#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_a57551(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57551  e917feffff             -jmp 0xa5736d
    return sub_a5736d(app, cpu);
}

/* align: skip  */
void sub_a57556(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57556  e930ffffff             -jmp 0xa5748b
    return sub_a5748b(app, cpu);
}

/* align: skip  */
void sub_a5755b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5755b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5755c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5755d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5755e  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 00a57564  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a57566  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a57568  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a5756a  893d18e9a500           -mov dword ptr [0xa5e918], edi
    app->getMemory<x86::reg32>(x86::reg32(10873112) /* 0xa5e918 */) = cpu.edi;
    // 00a57570  e8c3060000             -call 0xa57c38
    cpu.esp -= 4;
    sub_a57c38(app, cpu);
    if (cpu.terminate) return;
    // 00a57575  a31ce9a500             -mov dword ptr [0xa5e91c], eax
    app->getMemory<x86::reg32>(x86::reg32(10873116) /* 0xa5e91c */) = cpu.eax;
    // 00a5757a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5757c  7511                   -jne 0xa5758f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5758f;
    }
    // 00a5757e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a57580  0f85f6010000           -jne 0xa5777c
    if (!cpu.flags.zf)
    {
        goto L_0x00a5777c;
    }
    // 00a57586  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a57588  2eff153cb9a500         -call dword ptr cs:[0xa5b93c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860860) /* 0xa5b93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a5758f:
    // 00a5758f  e823ffffff             -call 0xa574b7
    cpu.esp -= 4;
    sub_a574b7(app, cpu);
    if (cpu.terminate) return;
    // 00a57594  2eff155cb9a500         -call dword ptr cs:[0xa5b95c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860892) /* 0xa5b95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5759b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5759d  a319dba500             -mov dword ptr [0xa5db19], eax
    app->getMemory<x86::reg32>(x86::reg32(10869529) /* 0xa5db19 */) = cpu.eax;
    // 00a575a2  891588f0a500           -mov dword ptr [0xa5f088], edx
    app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */) = cpu.edx;
    // 00a575a8  2eff1580b9a500         -call dword ptr cs:[0xa5b980]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860928) /* 0xa5b980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a575af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a575b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a575b3  a21fdba500             -mov byte ptr [0xa5db1f], al
    app->getMemory<x86::reg8>(x86::reg32(10869535) /* 0xa5db1f */) = cpu.al;
    // 00a575b8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a575bb  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a575c0  66a321dba500           -mov word ptr [0xa5db21], ax
    app->getMemory<x86::reg16>(x86::reg32(10869537) /* 0xa5db21 */) = cpu.ax;
    // 00a575c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a575c8  66a121dba500           -mov ax, word ptr [0xa5db21]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10869537) /* 0xa5db21 */);
    // 00a575ce  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a575d4  a323dba500             -mov dword ptr [0xa5db23], eax
    app->getMemory<x86::reg32>(x86::reg32(10869539) /* 0xa5db23 */) = cpu.eax;
    // 00a575d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a575db  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00a575de  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a575e0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a575e6  a327dba500             -mov dword ptr [0xa5db27], eax
    app->getMemory<x86::reg32>(x86::reg32(10869543) /* 0xa5db27 */) = cpu.eax;
    // 00a575eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a575ed  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a575ef  881520dba500           -mov byte ptr [0xa5db20], dl
    app->getMemory<x86::reg8>(x86::reg32(10869536) /* 0xa5db20 */) = cpu.dl;
    // 00a575f5  a32bdba500             -mov dword ptr [0xa5db2b], eax
    app->getMemory<x86::reg32>(x86::reg32(10869547) /* 0xa5db2b */) = cpu.eax;
    // 00a575fa  a127dba500             -mov eax, dword ptr [0xa5db27]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10869543) /* 0xa5db27 */);
    // 00a575ff  8b152bdba500           -mov edx, dword ptr [0xa5db2b]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869547) /* 0xa5db2b */);
    // 00a57605  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00a57608  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5760a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a5760f  a32fdba500             -mov dword ptr [0xa5db2f], eax
    app->getMemory<x86::reg32>(x86::reg32(10869551) /* 0xa5db2f */) = cpu.eax;
    // 00a57614  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 00a5761b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5761c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a5761e  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a57623  2eff1568b9a500         -call dword ptr cs:[0xa5b968]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860904) /* 0xa5b968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5762a  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 00a57631  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a57633  e8e6080000             -call 0xa57f1e
    cpu.esp -= 4;
    sub_a57f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a57638  a3e0daa500             -mov dword ptr [0xa5dae0], eax
    app->getMemory<x86::reg32>(x86::reg32(10869472) /* 0xa5dae0 */) = cpu.eax;
    // 00a5763d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5763f  e81f090000             -call 0xa57f63
    cpu.esp -= 4;
    sub_a57f63(app, cpu);
    if (cpu.terminate) return;
    // 00a57644  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a57646  e8a8090000             -call 0xa57ff3
    cpu.esp -= 4;
    sub_a57ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a5764b  a3ecdaa500             -mov dword ptr [0xa5daec], eax
    app->getMemory<x86::reg32>(x86::reg32(10869484) /* 0xa5daec */) = cpu.eax;
    // 00a57650  2eff154cb9a500         -call dword ptr cs:[0xa5b94c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860876) /* 0xa5b94c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57657  e8c2080000             -call 0xa57f1e
    cpu.esp -= 4;
    sub_a57f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a5765c  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5765e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57660  80fb22                 +cmp bl, 0x22
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
    // 00a57663  7514                   -jne 0xa57679
    if (!cpu.flags.zf)
    {
        goto L_0x00a57679;
    }
L_0x00a57665:
    // 00a57665  40                     -inc eax
    (cpu.eax)++;
    // 00a57666  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a57668  80fd22                 +cmp ch, 0x22
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a5766b  7404                   -je 0xa57671
    if (cpu.flags.zf)
    {
        goto L_0x00a57671;
    }
    // 00a5766d  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00a5766f  75f4                   -jne 0xa57665
    if (!cpu.flags.zf)
    {
        goto L_0x00a57665;
    }
L_0x00a57671:
    // 00a57671  803800                 +cmp byte ptr [eax], 0
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
    // 00a57674  741e                   -je 0xa57694
    if (cpu.flags.zf)
    {
        goto L_0x00a57694;
    }
L_0x00a57676:
    // 00a57676  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a57677  eb1b                   -jmp 0xa57694
    goto L_0x00a57694;
L_0x00a57679:
    // 00a57679  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a5767b  fec2                   -inc dl
    (cpu.dl)++;
    // 00a5767d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a57683  f68218dda50002         +test byte ptr [edx + 0xa5dd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870040) /* 0xa5dd18 */) & 2 /*0x2*/));
    // 00a5768a  7508                   -jne 0xa57694
    if (!cpu.flags.zf)
    {
        goto L_0x00a57694;
    }
    // 00a5768c  803800                 +cmp byte ptr [eax], 0
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
    // 00a5768f  7403                   -je 0xa57694
    if (cpu.flags.zf)
    {
        goto L_0x00a57694;
    }
    // 00a57691  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a57692  ebe5                   -jmp 0xa57679
    goto L_0x00a57679;
L_0x00a57694:
    // 00a57694  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a57696  fec2                   -inc dl
    (cpu.dl)++;
    // 00a57698  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5769e  f68218dda50002         +test byte ptr [edx + 0xa5dd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870040) /* 0xa5dd18 */) & 2 /*0x2*/));
    // 00a576a5  75cf                   -jne 0xa57676
    if (!cpu.flags.zf)
    {
        goto L_0x00a57676;
    }
    // 00a576a7  a3dcdaa500             -mov dword ptr [0xa5dadc], eax
    app->getMemory<x86::reg32>(x86::reg32(10869468) /* 0xa5dadc */) = cpu.eax;
    // 00a576ac  2eff1550b9a500         -call dword ptr cs:[0xa5b950]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860880) /* 0xa5b950 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a576b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a576b5  0f845f000000           -je 0xa5771a
    if (cpu.flags.zf)
    {
        goto L_0x00a5771a;
    }
    // 00a576bb  e833090000             -call 0xa57ff3
    cpu.esp -= 4;
    sub_a57ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a576c0  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a576c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a576c5  6683fb22               +cmp bx, 0x22
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
    // 00a576c9  751c                   -jne 0xa576e7
    if (!cpu.flags.zf)
    {
        goto L_0x00a576e7;
    }
L_0x00a576cb:
    // 00a576cb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a576ce  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a576d1  6683fa22               +cmp dx, 0x22
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a576d5  7405                   -je 0xa576dc
    if (cpu.flags.zf)
    {
        goto L_0x00a576dc;
    }
    // 00a576d7  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a576da  75ef                   -jne 0xa576cb
    if (!cpu.flags.zf)
    {
        goto L_0x00a576cb;
    }
L_0x00a576dc:
    // 00a576dc  66833800               +cmp word ptr [eax], 0
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
    // 00a576e0  7423                   -je 0xa57705
    if (cpu.flags.zf)
    {
        goto L_0x00a57705;
    }
L_0x00a576e2:
    // 00a576e2  83c002                 +add eax, 2
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
    // 00a576e5  eb1e                   -jmp 0xa57705
    goto L_0x00a57705;
L_0x00a576e7:
    // 00a576e7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a576e9  fec2                   -inc dl
    (cpu.dl)++;
    // 00a576eb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a576f1  f68218dda50002         +test byte ptr [edx + 0xa5dd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870040) /* 0xa5dd18 */) & 2 /*0x2*/));
    // 00a576f8  750b                   -jne 0xa57705
    if (!cpu.flags.zf)
    {
        goto L_0x00a57705;
    }
    // 00a576fa  66833800               +cmp word ptr [eax], 0
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
    // 00a576fe  7405                   -je 0xa57705
    if (cpu.flags.zf)
    {
        goto L_0x00a57705;
    }
    // 00a57700  83c002                 +add eax, 2
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
    // 00a57703  ebe2                   -jmp 0xa576e7
    goto L_0x00a576e7;
L_0x00a57705:
    // 00a57705  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a57707  fec2                   -inc dl
    (cpu.dl)++;
    // 00a57709  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a5770f  f68218dda50002         +test byte ptr [edx + 0xa5dd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870040) /* 0xa5dd18 */) & 2 /*0x2*/));
    // 00a57716  740c                   -je 0xa57724
    if (cpu.flags.zf)
    {
        goto L_0x00a57724;
    }
    // 00a57718  ebc8                   -jmp 0xa576e2
    goto L_0x00a576e2;
L_0x00a5771a:
    // 00a5771a  b848cba500             -mov eax, 0xa5cb48
    cpu.eax = 10865480 /*0xa5cb48*/;
    // 00a5771f  e8cf080000             -call 0xa57ff3
    cpu.esp -= 4;
    sub_a57ff3(app, cpu);
    if (cpu.terminate) return;
L_0x00a57724:
    // 00a57724  a3e8daa500             -mov dword ptr [0xa5dae8], eax
    app->getMemory<x86::reg32>(x86::reg32(10869480) /* 0xa5dae8 */) = cpu.eax;
    // 00a57729  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a5772b  744a                   -je 0xa57777
    if (cpu.flags.zf)
    {
        goto L_0x00a57777;
    }
    // 00a5772d  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a57732  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 00a57739  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5773a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5773b  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a57740  2eff1568b9a500         -call dword ptr cs:[0xa5b968]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860904) /* 0xa5b968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57747  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 00a5774e  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00a57755  e8c4070000             -call 0xa57f1e
    cpu.esp -= 4;
    sub_a57f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a5775a  a3e4daa500             -mov dword ptr [0xa5dae4], eax
    app->getMemory<x86::reg32>(x86::reg32(10869476) /* 0xa5dae4 */) = cpu.eax;
    // 00a5775f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a57761  e8fd070000             -call 0xa57f63
    cpu.esp -= 4;
    sub_a57f63(app, cpu);
    if (cpu.terminate) return;
    // 00a57766  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00a5776d  e881080000             -call 0xa57ff3
    cpu.esp -= 4;
    sub_a57ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a57772  a3f0daa500             -mov dword ptr [0xa5daf0], eax
    app->getMemory<x86::reg32>(x86::reg32(10869488) /* 0xa5daf0 */) = cpu.eax;
L_0x00a57777:
    // 00a57777  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a5777c:
    // 00a5777c  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 00a57782  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57783  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57785  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57786(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57786  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57787  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57788  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57789  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5778a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a5778c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a5778e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a57790  2eff1570b9a500         -call dword ptr cs:[0xa5b970]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860912) /* 0xa5b970 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57797  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57799  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a5779b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5779d  e8b9fdffff             -call 0xa5755b
    cpu.esp -= 4;
    sub_a5755b(app, cpu);
    if (cpu.terminate) return;
    // 00a577a2  bafcdaa500             -mov edx, 0xa5dafc
    cpu.edx = 10869500 /*0xa5dafc*/;
    // 00a577a7  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a577ad  e868080000             -call 0xa5801a
    cpu.esp -= 4;
    sub_a5801a(app, cpu);
    if (cpu.terminate) return;
    // 00a577b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a577b4  e8e80c0000             -call 0xa584a1
    cpu.esp -= 4;
    sub_a584a1(app, cpu);
    if (cpu.terminate) return;
    // 00a577b9  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00a577be  e85a0d0000             -call 0xa5851d
    cpu.esp -= 4;
    sub_a5851d(app, cpu);
    if (cpu.terminate) return;
    // 00a577c3  ff15a4dca500           -call dword ptr [0xa5dca4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869924) /* 0xa5dca4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a577c9  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a577ce  e84a0d0000             -call 0xa5851d
    cpu.esp -= 4;
    sub_a5851d(app, cpu);
    if (cpu.terminate) return;
    // 00a577d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a577d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a577d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a577d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a577d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a577d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a577d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a577da  833d18e9a50000         +cmp dword ptr [0xa5e918], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10873112) /* 0xa5e918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a577e1  7418                   -je 0xa577fb
    if (cpu.flags.zf)
    {
        goto L_0x00a577fb;
    }
    // 00a577e3  833dacdca50000         +cmp dword ptr [0xa5dcac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869932) /* 0xa5dcac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a577ea  7426                   -je 0xa57812
    if (cpu.flags.zf)
    {
        goto L_0x00a57812;
    }
    // 00a577ec  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a577f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a577f3  ff15acdca500           -call dword ptr [0xa5dcac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869932) /* 0xa5dcac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a577f9  eb17                   -jmp 0xa57812
    goto L_0x00a57812;
L_0x00a577fb:
    // 00a577fb  e8ed0c0000             -call 0xa584ed
    cpu.esp -= 4;
    sub_a584ed(app, cpu);
    if (cpu.terminate) return;
    // 00a57800  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a57805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a57807  e85d0d0000             -call 0xa58569
    cpu.esp -= 4;
    sub_a58569(app, cpu);
    if (cpu.terminate) return;
    // 00a5780c  ff15a0dca500           -call dword ptr [0xa5dca0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869920) /* 0xa5dca0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57812:
    // 00a57812  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57813  2eff153cb9a500         -call dword ptr cs:[0xa5b93c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860860) /* 0xa5b93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5781a  803db0dca50000         +cmp byte ptr [0xa5dcb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10869936) /* 0xa5dcb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a57821  741a                   -je 0xa5783d
    if (cpu.flags.zf)
    {
        goto L_0x00a5783d;
    }
    // 00a57823  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a57829  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5782a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5782b  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a5782c  eb06                   -jmp 0xa57834
    goto L_0x00a57834;
    // 00a5782e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5782f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57830  49                     -dec ecx
    (cpu.ecx)--;
    // 00a57831  44                     -inc esp
    (cpu.esp)++;
    // 00a57832  45                     -inc ebp
    (cpu.ebp)++;
    // 00a57833  4f                     -dec edi
    (cpu.edi)--;
L_0x00a57834:
    // 00a57834  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57839  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5783c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5783d:
    // 00a5783d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5783f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5781a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a5781a;
    // 00a577d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a577da  833d18e9a50000         +cmp dword ptr [0xa5e918], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10873112) /* 0xa5e918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a577e1  7418                   -je 0xa577fb
    if (cpu.flags.zf)
    {
        goto L_0x00a577fb;
    }
    // 00a577e3  833dacdca50000         +cmp dword ptr [0xa5dcac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869932) /* 0xa5dcac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a577ea  7426                   -je 0xa57812
    if (cpu.flags.zf)
    {
        goto L_0x00a57812;
    }
    // 00a577ec  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a577f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a577f3  ff15acdca500           -call dword ptr [0xa5dcac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869932) /* 0xa5dcac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a577f9  eb17                   -jmp 0xa57812
    goto L_0x00a57812;
L_0x00a577fb:
    // 00a577fb  e8ed0c0000             -call 0xa584ed
    cpu.esp -= 4;
    sub_a584ed(app, cpu);
    if (cpu.terminate) return;
    // 00a57800  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a57805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a57807  e85d0d0000             -call 0xa58569
    cpu.esp -= 4;
    sub_a58569(app, cpu);
    if (cpu.terminate) return;
    // 00a5780c  ff15a0dca500           -call dword ptr [0xa5dca0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869920) /* 0xa5dca0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57812:
    // 00a57812  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57813  2eff153cb9a500         -call dword ptr cs:[0xa5b93c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860860) /* 0xa5b93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a5781a:
    // 00a5781a  803db0dca50000         +cmp byte ptr [0xa5dcb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10869936) /* 0xa5dcb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a57821  741a                   -je 0xa5783d
    if (cpu.flags.zf)
    {
        goto L_0x00a5783d;
    }
    // 00a57823  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a57829  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a5782a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5782b  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a5782c  eb06                   -jmp 0xa57834
    goto L_0x00a57834;
    // 00a5782e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5782f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57830  49                     -dec ecx
    (cpu.ecx)--;
    // 00a57831  44                     -inc esp
    (cpu.esp)++;
    // 00a57832  45                     -inc ebp
    (cpu.ebp)++;
    // 00a57833  4f                     -dec edi
    (cpu.edi)--;
L_0x00a57834:
    // 00a57834  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57839  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5783c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5783d:
    // 00a5783d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5783f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57841  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a57845  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a57848  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a5784d  751c                   -jne 0xa5786b
    if (!cpu.flags.zf)
    {
        goto L_0x00a5786b;
    }
    // 00a5784f  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a57856  750c                   -jne 0xa57864
    if (!cpu.flags.zf)
    {
        goto L_0x00a57864;
    }
    // 00a57858  833800                 +cmp dword ptr [eax], 0
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
    // 00a5785b  7507                   -jne 0xa57864
    if (!cpu.flags.zf)
    {
        goto L_0x00a57864;
    }
    // 00a5785d  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a57862  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57864:
    // 00a57864  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a57869  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5786a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5786b:
    // 00a5786b  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 00a57871  7516                   -jne 0xa57889
    if (!cpu.flags.zf)
    {
        goto L_0x00a57889;
    }
    // 00a57873  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a57877  7509                   -jne 0xa57882
    if (!cpu.flags.zf)
    {
        goto L_0x00a57882;
    }
    // 00a57879  833800                 +cmp dword ptr [eax], 0
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
    // 00a5787c  7504                   -jne 0xa57882
    if (!cpu.flags.zf)
    {
        goto L_0x00a57882;
    }
    // 00a5787e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a57880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57881  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57882:
    // 00a57882  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a57887  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57889:
    // 00a57889  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a5788e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5788f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57890(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57890  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57892  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57893  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57894  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57895  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57896  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57898  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5789a  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5789c  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5789e  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a578a0:
    // 00a578a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a578a2  3c00                   +cmp al, 0
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
    // 00a578a4  742f                   -je 0xa578d5
    if (cpu.flags.zf)
    {
        goto L_0x00a578d5;
    }
    // 00a578a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a578a8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a578aa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a578ac  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578ae  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578b0  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a578b2  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578b4  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578b6  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a578b8  01c5                   +add ebp, eax
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
    // 00a578ba  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578bc  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00a578be  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578c0  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578c2  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a578c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a578c6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a578c8  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00a578ca  01c5                   +add ebp, eax
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
    // 00a578cc  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578cf  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a578d2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a578d3  ebcb                   -jmp 0xa578a0
    goto L_0x00a578a0;
L_0x00a578d5:
    // 00a578d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a578d7  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 00a578dc  e811000000             -call 0xa578f2
    cpu.esp -= 4;
    sub_a578f2(app, cpu);
    if (cpu.terminate) return;
    // 00a578e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578e2  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a578e5  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a578e8  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 00a578ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a578f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a578f2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a578f2  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a578f4  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a578f6  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a578f8  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00a578fa  7436                   -je 0xa57932
    if (cpu.flags.zf)
    {
        goto L_0x00a57932;
    }
    // 00a578fc  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a578fe  7509                   -jne 0xa57909
    if (!cpu.flags.zf)
    {
        goto L_0x00a57909;
    }
    // 00a57900  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57902  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a57904  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a57906  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a57909:
    // 00a57909  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a5790b  7509                   -jne 0xa57916
    if (!cpu.flags.zf)
    {
        goto L_0x00a57916;
    }
    // 00a5790d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a5790f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a57911  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a57913  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a57916:
    // 00a57916  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a57918  7809                   -js 0xa57923
    if (cpu.flags.sf)
    {
        goto L_0x00a57923;
    }
    // 00a5791a  4f                     -dec edi
    (cpu.edi)--;
    // 00a5791b  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a5791d  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a5791f  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a57921  ebf3                   -jmp 0xa57916
    goto L_0x00a57916;
L_0x00a57923:
    // 00a57923  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a57925  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a57928  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a5792b  7303                   -jae 0xa57930
    if (!cpu.flags.cf)
    {
        goto L_0x00a57930;
    }
    // 00a5792d  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 00a5792f  47                     -inc edi
    (cpu.edi)++;
L_0x00a57930:
    // 00a57930  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00a57932:
    // 00a57932  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57933(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a57933:
    // 00a57933  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57934  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57936  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5793c  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a5793f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57940  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a57941  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a57946  ebeb                   -jmp 0xa57933
    goto L_0x00a57933;
}

/* align: skip  */
void sub_a57948(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57948  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a5794d  ebe4                   -jmp 0xa57933
    return sub_a57933(app, cpu);
}

/* align: skip  */
void sub_a5794f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5794f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a57954  e8daffffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a57959  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5795e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5795f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5795f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57960  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57962  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57968  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a5796b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5796c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5796d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5796d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5796e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5796f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57970  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57972  3b05b4dca500           +cmp eax, dword ptr [0xa5dcb4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10869940) /* 0xa5dcb4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a57978  7206                   -jb 0xa57980
    if (cpu.flags.cf)
    {
        goto L_0x00a57980;
    }
    // 00a5797a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5797c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5797d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5797e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5797f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57980:
    // 00a57980  83f803                 +cmp eax, 3
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
    // 00a57983  7d31                   -jge 0xa579b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a579b6;
    }
    // 00a57985  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57987  a108dda500             -mov eax, dword ptr [0xa5dd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870024) /* 0xa5dd08 */);
    // 00a5798c  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00a5798f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a57991  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a57994  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a57997  751d                   -jne 0xa579b6
    if (!cpu.flags.zf)
    {
        goto L_0x00a579b6;
    }
    // 00a57999  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a5799b  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a5799e  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00a579a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a579a3  e8120c0000             -call 0xa585ba
    cpu.esp -= 4;
    sub_a585ba(app, cpu);
    if (cpu.terminate) return;
    // 00a579a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a579aa  740a                   -je 0xa579b6
    if (cpu.flags.zf)
    {
        goto L_0x00a579b6;
    }
    // 00a579ac  a108dda500             -mov eax, dword ptr [0xa5dd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870024) /* 0xa5dd08 */);
    // 00a579b1  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a579b6:
    // 00a579b6  a108dda500             -mov eax, dword ptr [0xa5dd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870024) /* 0xa5dd08 */);
    // 00a579bb  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a579be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a579bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a579c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a579c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a579c2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a579c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a579c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a579c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a579c8  740e                   -je 0xa579d8
    if (cpu.flags.zf)
    {
        goto L_0x00a579d8;
    }
    // 00a579ca  8b1d08dda500           -mov ebx, dword ptr [0xa5dd08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10870024) /* 0xa5dd08 */);
    // 00a579d0  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a579d3  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a579d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a579d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a579d8:
    // 00a579d8  8b1d08dda500           -mov ebx, dword ptr [0xa5dd08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10870024) /* 0xa5dd08 */);
    // 00a579de  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a579e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a579e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a579e3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a579e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a579e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a579e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a579e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a579e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a579e8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a579ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a579ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a579ee  7509                   -jne 0xa579f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a579f9;
    }
    // 00a579f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a579f2  e8190c0000             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a579f7  eb5e                   -jmp 0xa57a57
    goto L_0x00a57a57;
L_0x00a579f9:
    // 00a579f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a579fb  7509                   -jne 0xa57a06
    if (!cpu.flags.zf)
    {
        goto L_0x00a57a06;
    }
    // 00a579fd  e8fb0c0000             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a57a02  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a57a04  eb51                   -jmp 0xa57a57
    goto L_0x00a57a57;
L_0x00a57a06:
    // 00a57a06  e8f60d0000             -call 0xa58801
    cpu.esp -= 4;
    sub_a58801(app, cpu);
    if (cpu.terminate) return;
    // 00a57a0b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57a0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57a0f  e8f80d0000             -call 0xa5880c
    cpu.esp -= 4;
    sub_a5880c(app, cpu);
    if (cpu.terminate) return;
    // 00a57a14  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a57a16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57a18  753b                   -jne 0xa57a55
    if (!cpu.flags.zf)
    {
        goto L_0x00a57a55;
    }
    // 00a57a1a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a57a1c  e8ef0b0000             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a57a21  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a57a23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57a25  7425                   -je 0xa57a4c
    if (cpu.flags.zf)
    {
        goto L_0x00a57a4c;
    }
    // 00a57a27  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a57a29  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a57a2b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a57a2d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a57a2e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a57a30  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a57a32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57a33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a57a35  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a57a38  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a57a3a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a57a3c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a57a3f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a57a41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a42  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a57a43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57a45  e8b30c0000             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a57a4a  eb09                   -jmp 0xa57a55
    goto L_0x00a57a55;
L_0x00a57a4c:
    // 00a57a4c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a57a4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57a50  e8b70d0000             -call 0xa5880c
    cpu.esp -= 4;
    sub_a5880c(app, cpu);
    if (cpu.terminate) return;
L_0x00a57a55:
    // 00a57a55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a57a57:
    // 00a57a57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57a5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57a5d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57a5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57a5e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57a5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57a5f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57a60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57a61  8b1580eaa500           -mov edx, dword ptr [0xa5ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10873472) /* 0xa5ea80 */);
    // 00a57a67  83fa40                 +cmp edx, 0x40
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
    // 00a57a6a  7d1c                   -jge 0xa57a88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a57a88;
    }
    // 00a57a6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57a6e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a57a71  bb84eaa500             -mov ebx, 0xa5ea84
    cpu.ebx = 10873476 /*0xa5ea84*/;
    // 00a57a76  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a57a78  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a57a7b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a57a7e  890d80eaa500           -mov dword ptr [0xa5ea80], ecx
    app->getMemory<x86::reg32>(x86::reg32(10873472) /* 0xa5ea80 */) = cpu.ecx;
    // 00a57a84  01c3                   +add ebx, eax
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
    // 00a57a86  eb24                   -jmp 0xa57aac
    goto L_0x00a57aac;
L_0x00a57a88:
    // 00a57a88  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00a57a8d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57a92  e8590f0000             -call 0xa589f0
    cpu.esp -= 4;
    sub_a589f0(app, cpu);
    if (cpu.terminate) return;
    // 00a57a97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57a99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57a9b  750f                   -jne 0xa57aac
    if (!cpu.flags.zf)
    {
        goto L_0x00a57aac;
    }
    // 00a57a9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a57aa2  b84ccba500             -mov eax, 0xa5cb4c
    cpu.eax = 10865484 /*0xa5cb4c*/;
    // 00a57aa7  e87aeaffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
L_0x00a57aac:
    // 00a57aac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57aae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57aaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ab0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ab1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57ab2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57ab2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57ab3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57ab4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57ab5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57ab7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a57abb  740a                   -je 0xa57ac7
    if (cpu.flags.zf)
    {
        goto L_0x00a57ac7;
    }
    // 00a57abd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a57abf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57ac0  2eff1534b9a500         -call dword ptr cs:[0xa5b934]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860852) /* 0xa5b934 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57ac7:
    // 00a57ac7  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a57ace  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a57ad5  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a57adc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57add  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ade  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57adf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57ae0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57ae0  b820e9a500             -mov eax, 0xa5e920
    cpu.eax = 10873120 /*0xa5e920*/;
    // 00a57ae5  e97d000000             -jmp 0xa57b67
    return sub_a57b67(app, cpu);
}

/* align: skip  */
void sub_a57aea(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57aea  b820e9a500             -mov eax, 0xa5e920
    cpu.eax = 10873120 /*0xa5e920*/;
    // 00a57aef  e9d9000000             -jmp 0xa57bcd
    return sub_a57bcd(app, cpu);
}

/* align: skip  */
void sub_a57af4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57af4  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a57af7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a57afa  0540e9a500             +add eax, 0xa5e940
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10873152 /*0xa5e940*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a57aff  eb66                   -jmp 0xa57b67
    return sub_a57b67(app, cpu);
}

/* align: skip  */
void sub_a57b01(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b01  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a57b04  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a57b07  0540e9a500             +add eax, 0xa5e940
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10873152 /*0xa5e940*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a57b0c  e9bc000000             -jmp 0xa57bcd
    return sub_a57bcd(app, cpu);
}

/* align: skip  */
void sub_a57b11(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b11  e957f8ffff             -jmp 0xa5736d
    return sub_a5736d(app, cpu);
}

/* align: skip  */
void sub_a57b16(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57b17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57b19  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a57b1c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a57b1f  0540e9a500             -add eax, 0xa5e940
    (cpu.eax) += x86::reg32(x86::sreg32(10873152 /*0xa5e940*/));
    // 00a57b24  e889ffffff             -call 0xa57ab2
    cpu.esp -= 4;
    sub_a57ab2(app, cpu);
    if (cpu.terminate) return;
    // 00a57b29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57b2b  e85bf9ffff             -call 0xa5748b
    cpu.esp -= 4;
    sub_a5748b(app, cpu);
    if (cpu.terminate) return;
    // 00a57b30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57b31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57b32(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b32  b840eaa500             -mov eax, 0xa5ea40
    cpu.eax = 10873408 /*0xa5ea40*/;
    // 00a57b37  eb2e                   -jmp 0xa57b67
    return sub_a57b67(app, cpu);
}

/* align: skip  */
void sub_a57b39(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b39  b840eaa500             -mov eax, 0xa5ea40
    cpu.eax = 10873408 /*0xa5ea40*/;
    // 00a57b3e  e98a000000             -jmp 0xa57bcd
    return sub_a57bcd(app, cpu);
}

/* align: skip  */
void sub_a57b43(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b43  b830e9a500             -mov eax, 0xa5e930
    cpu.eax = 10873136 /*0xa5e930*/;
    // 00a57b48  eb1d                   -jmp 0xa57b67
    return sub_a57b67(app, cpu);
}

/* align: skip  */
void sub_a57b4a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b4a  b830e9a500             -mov eax, 0xa5e930
    cpu.eax = 10873136 /*0xa5e930*/;
    // 00a57b4f  e979000000             -jmp 0xa57bcd
    return sub_a57bcd(app, cpu);
}

/* align: skip  */
void sub_a57b54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b54  b860eaa500             -mov eax, 0xa5ea60
    cpu.eax = 10873440 /*0xa5ea60*/;
    // 00a57b59  eb0c                   -jmp 0xa57b67
    return sub_a57b67(app, cpu);
}

/* align: skip  */
void sub_a57b5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b5b  b860eaa500             -mov eax, 0xa5ea60
    cpu.eax = 10873440 /*0xa5ea60*/;
    // 00a57b60  eb6b                   -jmp 0xa57bcd
    return sub_a57bcd(app, cpu);
}

/* align: skip  */
void sub_a57b62(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57b62  b870eaa500             -mov eax, 0xa5ea70
    cpu.eax = 10873456 /*0xa5ea70*/;
    // 00a57b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57b68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57b69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57b6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57b6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57b6d  2eff1554b9a500         -call dword ptr cs:[0xa5b954]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860884) /* 0xa5b954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57b74  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a57b77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57b79  39d0                   +cmp eax, edx
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
    // 00a57b7b  7443                   -je 0xa57bc0
    if (cpu.flags.zf)
    {
        goto L_0x00a57bc0;
    }
    // 00a57b7d  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a57b81  7530                   -jne 0xa57bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a57bb3;
    }
    // 00a57b83  b850eaa500             -mov eax, 0xa5ea50
    cpu.eax = 10873424 /*0xa5ea50*/;
    // 00a57b88  e8daffffff             -call 0xa57b67
    cpu.esp -= 4;
    sub_a57b67(app, cpu);
    if (cpu.terminate) return;
    // 00a57b8d  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a57b91  7516                   -jne 0xa57ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a57ba9;
    }
    // 00a57b93  e8c6feffff             -call 0xa57a5e
    cpu.esp -= 4;
    sub_a57a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a57b98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57b99  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a57b9b  2eff1584b9a500         -call dword ptr cs:[0xa5b984]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860932) /* 0xa5b984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ba2  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x00a57ba9:
    // 00a57ba9  b850eaa500             -mov eax, 0xa5ea50
    cpu.eax = 10873424 /*0xa5ea50*/;
    // 00a57bae  e81a000000             -call 0xa57bcd
    cpu.esp -= 4;
    sub_a57bcd(app, cpu);
    if (cpu.terminate) return;
L_0x00a57bb3:
    // 00a57bb3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a57bb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57bb6  2eff1538b9a500         -call dword ptr cs:[0xa5b938]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860856) /* 0xa5b938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57bbd  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a57bc0:
    // 00a57bc0  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a57bc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57b67(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a57b67;
    // 00a57b62  b870eaa500             -mov eax, 0xa5ea70
    cpu.eax = 10873456 /*0xa5ea70*/;
L_entry_0x00a57b67:
    // 00a57b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57b68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57b69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57b6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57b6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57b6d  2eff1554b9a500         -call dword ptr cs:[0xa5b954]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860884) /* 0xa5b954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57b74  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a57b77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57b79  39d0                   +cmp eax, edx
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
    // 00a57b7b  7443                   -je 0xa57bc0
    if (cpu.flags.zf)
    {
        goto L_0x00a57bc0;
    }
    // 00a57b7d  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a57b81  7530                   -jne 0xa57bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a57bb3;
    }
    // 00a57b83  b850eaa500             -mov eax, 0xa5ea50
    cpu.eax = 10873424 /*0xa5ea50*/;
    // 00a57b88  e8daffffff             -call 0xa57b67
    cpu.esp -= 4;
    sub_a57b67(app, cpu);
    if (cpu.terminate) return;
    // 00a57b8d  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a57b91  7516                   -jne 0xa57ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a57ba9;
    }
    // 00a57b93  e8c6feffff             -call 0xa57a5e
    cpu.esp -= 4;
    sub_a57a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a57b98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57b99  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a57b9b  2eff1584b9a500         -call dword ptr cs:[0xa5b984]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860932) /* 0xa5b984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ba2  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x00a57ba9:
    // 00a57ba9  b850eaa500             -mov eax, 0xa5ea50
    cpu.eax = 10873424 /*0xa5ea50*/;
    // 00a57bae  e81a000000             -call 0xa57bcd
    cpu.esp -= 4;
    sub_a57bcd(app, cpu);
    if (cpu.terminate) return;
L_0x00a57bb3:
    // 00a57bb3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a57bb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57bb6  2eff1538b9a500         -call dword ptr cs:[0xa5b938]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860856) /* 0xa5b938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57bbd  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a57bc0:
    // 00a57bc0  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a57bc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57bc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57bc8  b870eaa500             -mov eax, 0xa5ea70
    cpu.eax = 10873456 /*0xa5ea70*/;
    // 00a57bcd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57bce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57bcf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57bd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57bd1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a57bd4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a57bd6  7617                   -jbe 0xa57bef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a57bef;
    }
    // 00a57bd8  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a57bdb  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a57bde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a57be0  750d                   -jne 0xa57bef
    if (!cpu.flags.zf)
    {
        goto L_0x00a57bef;
    }
    // 00a57be2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a57be4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57be5  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a57be8  2eff1588b9a500         -call dword ptr cs:[0xa5b988]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860936) /* 0xa5b988 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57bef:
    // 00a57bef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57bcd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a57bcd;
    // 00a57bc8  b870eaa500             -mov eax, 0xa5ea70
    cpu.eax = 10873456 /*0xa5ea70*/;
L_entry_0x00a57bcd:
    // 00a57bcd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57bce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57bcf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57bd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57bd1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a57bd4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a57bd6  7617                   -jbe 0xa57bef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a57bef;
    }
    // 00a57bd8  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a57bdb  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a57bde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a57be0  750d                   -jne 0xa57bef
    if (!cpu.flags.zf)
    {
        goto L_0x00a57bef;
    }
    // 00a57be2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a57be4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57be5  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a57be8  2eff1588b9a500         -call dword ptr cs:[0xa5b988]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860936) /* 0xa5b988 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57bef:
    // 00a57bef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57bf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57bf4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57bf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57bf6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57bf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57bf8  2eff1564b9a500         -call dword ptr cs:[0xa5b964]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860900) /* 0xa5b964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57bff  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57c05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57c06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57c08  2eff15b8b9a500         -call dword ptr cs:[0xa5b9b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860984) /* 0xa5b9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57c0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57c11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57c13  7507                   -jne 0xa57c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a57c1c;
    }
    // 00a57c15  e8ee0d0000             -call 0xa58a08
    cpu.esp -= 4;
    sub_a58a08(app, cpu);
    if (cpu.terminate) return;
    // 00a57c1a  eb0b                   -jmp 0xa57c27
    goto L_0x00a57c27;
L_0x00a57c1c:
    // 00a57c1c  80785300               +cmp byte ptr [eax + 0x53], 0
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
    // 00a57c20  7407                   -je 0xa57c29
    if (cpu.flags.zf)
    {
        goto L_0x00a57c29;
    }
    // 00a57c22  e81a0e0000             -call 0xa58a41
    cpu.esp -= 4;
    sub_a58a41(app, cpu);
    if (cpu.terminate) return;
L_0x00a57c27:
    // 00a57c27  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a57c29:
    // 00a57c29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57c2a  2eff15a4b9a500         -call dword ptr cs:[0xa5b9a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860964) /* 0xa5b9a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57c31  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57c33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57c38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57c38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57c39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57c3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57c3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57c3e  7526                   -jne 0xa57c66
    if (!cpu.flags.zf)
    {
        goto L_0x00a57c66;
    }
    // 00a57c40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57c45  8b1544dea500           -mov edx, dword ptr [0xa5de44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a57c4b  e8a00d0000             -call 0xa589f0
    cpu.esp -= 4;
    sub_a589f0(app, cpu);
    if (cpu.terminate) return;
    // 00a57c50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57c52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57c54  7410                   -je 0xa57c66
    if (cpu.flags.zf)
    {
        goto L_0x00a57c66;
    }
    // 00a57c56  8b1d44dea500           -mov ebx, dword ptr [0xa5de44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a57c5c  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a57c60  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00a57c66:
    // 00a57c66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57c68  e8c70f0000             -call 0xa58c34
    cpu.esp -= 4;
    sub_a58c34(app, cpu);
    if (cpu.terminate) return;
    // 00a57c6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57c6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57c71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57c72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57c72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57c73  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57c74  2eff15b0b9a500         -call dword ptr cs:[0xa5b9b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860976) /* 0xa5b9b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57c7b  668b1521dba500         -mov dx, word ptr [0xa5db21]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10869537) /* 0xa5db21 */);
    // 00a57c82  a360dca500             -mov dword ptr [0xa5dc60], eax
    app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */) = cpu.eax;
    // 00a57c87  6681fa0080             +cmp dx, 0x8000
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
    // 00a57c8c  7227                   -jb 0xa57cb5
    if (cpu.flags.cf)
    {
        goto L_0x00a57cb5;
    }
    // 00a57c8e  803d1fdba50004         +cmp byte ptr [0xa5db1f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10869535) /* 0xa5db1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a57c95  731e                   -jae 0xa57cb5
    if (!cpu.flags.cf)
    {
        goto L_0x00a57cb5;
    }
L_0x00a57c97:
    // 00a57c97  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57c9d  83faff                 +cmp edx, -1
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
    // 00a57ca0  7413                   -je 0xa57cb5
    if (cpu.flags.zf)
    {
        goto L_0x00a57cb5;
    }
    // 00a57ca2  83fa02                 +cmp edx, 2
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
    // 00a57ca5  770e                   -ja 0xa57cb5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a57cb5;
    }
    // 00a57ca7  2eff15b0b9a500         -call dword ptr cs:[0xa5b9b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860976) /* 0xa5b9b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57cae  a360dca500             -mov dword ptr [0xa5dc60], eax
    app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */) = cpu.eax;
    // 00a57cb3  ebe2                   -jmp 0xa57c97
    goto L_0x00a57c97;
L_0x00a57cb5:
    // 00a57cb5  833d60dca500ff         +cmp dword ptr [0xa5dc60], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a57cbc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a57cbf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a57cc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57cc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57cc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57cc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57cc7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57cc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57cc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57cca  833d60dca500ff         +cmp dword ptr [0xa5dc60], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a57cd1  7506                   -jne 0xa57cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00a57cd9;
    }
L_0x00a57cd3:
    // 00a57cd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a57cd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57cd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57cd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57cd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57cd9:
    // 00a57cd9  e85affffff             -call 0xa57c38
    cpu.esp -= 4;
    sub_a57c38(app, cpu);
    if (cpu.terminate) return;
    // 00a57cde  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57ce0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57ce2  742e                   -je 0xa57d12
    if (cpu.flags.zf)
    {
        goto L_0x00a57d12;
    }
    // 00a57ce4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a57ce6  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a57cec  e8240e0000             -call 0xa58b15
    cpu.esp -= 4;
    sub_a58b15(app, cpu);
    if (cpu.terminate) return;
    // 00a57cf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57cf3  7509                   -jne 0xa57cfe
    if (!cpu.flags.zf)
    {
        goto L_0x00a57cfe;
    }
    // 00a57cf5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57cf7  e8010a0000             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a57cfc  ebd5                   -jmp 0xa57cd3
    goto L_0x00a57cd3;
L_0x00a57cfe:
    // 00a57cfe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57cff  8b1d60dca500           -mov ebx, dword ptr [0xa5dc60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d05  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57d06  2eff15bcb9a500         -call dword ptr cs:[0xa5b9bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860988) /* 0xa5b9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a57d12:
    // 00a57d12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57d16(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57d16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57d17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57d18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57d1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57d1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57d1d  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d23  83faff                 +cmp edx, -1
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
    // 00a57d26  743d                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d29  2eff15b8b9a500         -call dword ptr cs:[0xa5b9b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860984) /* 0xa5b9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57d32  7431                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d34  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a57d3a  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a57d40  e8310e0000             -call 0xa58b76
    cpu.esp -= 4;
    sub_a58b76(app, cpu);
    if (cpu.terminate) return;
    // 00a57d45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a57d47  8b3d60dca500           -mov edi, dword ptr [0xa5dc60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57d4e  2eff15bcb9a500         -call dword ptr cs:[0xa5b9bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860988) /* 0xa5b9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a57d57  740c                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d59  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a57d5b  7408                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57d5e  2eff1524b9a500         -call dword ptr cs:[0xa5b924]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860836) /* 0xa5b924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57d65:
    // 00a57d65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57d65(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a57d65;
    // 00a57d16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57d17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57d18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57d1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57d1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57d1d  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d23  83faff                 +cmp edx, -1
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
    // 00a57d26  743d                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d29  2eff15b8b9a500         -call dword ptr cs:[0xa5b9b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860984) /* 0xa5b9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57d32  7431                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d34  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a57d3a  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a57d40  e8310e0000             -call 0xa58b76
    cpu.esp -= 4;
    sub_a58b76(app, cpu);
    if (cpu.terminate) return;
    // 00a57d45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a57d47  8b3d60dca500           -mov edi, dword ptr [0xa5dc60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57d4e  2eff15bcb9a500         -call dword ptr cs:[0xa5b9bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860988) /* 0xa5b9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a57d57  740c                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d59  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a57d5b  7408                   -je 0xa57d65
    if (cpu.flags.zf)
    {
        goto L_0x00a57d65;
    }
    // 00a57d5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57d5e  2eff1524b9a500         -call dword ptr cs:[0xa5b924]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860836) /* 0xa5b924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a57d65:
L_entry_0x00a57d65:
    // 00a57d65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57d6b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57d6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57d70  e8a1ffffff             -call 0xa57d16
    cpu.esp -= 4;
    sub_a57d16(app, cpu);
    if (cpu.terminate) return;
    // 00a57d75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57d76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d77  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d7d  83faff                 +cmp edx, -1
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
    // 00a57d80  7412                   -je 0xa57d94
    if (cpu.flags.zf)
    {
        goto L_0x00a57d94;
    }
    // 00a57d82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d83  2eff15b4b9a500         -call dword ptr cs:[0xa5b9b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860980) /* 0xa5b9b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d8a  c70560dca500ffffffff   -mov dword ptr [0xa5dc60], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */) = 4294967295 /*0xffffffff*/;
L_0x00a57d94:
    // 00a57d94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57d75(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a57d75;
    // 00a57d6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a57d70  e8a1ffffff             -call 0xa57d16
    cpu.esp -= 4;
    sub_a57d16(app, cpu);
    if (cpu.terminate) return;
L_entry_0x00a57d75:
    // 00a57d75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57d76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d77  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57d7d  83faff                 +cmp edx, -1
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
    // 00a57d80  7412                   -je 0xa57d94
    if (cpu.flags.zf)
    {
        goto L_0x00a57d94;
    }
    // 00a57d82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d83  2eff15b4b9a500         -call dword ptr cs:[0xa5b9b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860980) /* 0xa5b9b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57d8a  c70560dca500ffffffff   -mov dword ptr [0xa5dc60], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */) = 4294967295 /*0xffffffff*/;
L_0x00a57d94:
    // 00a57d94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57d97(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57d97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57d98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57d99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57d9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57d9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57d9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57d9d  baf47aa500             -mov edx, 0xa57af4
    cpu.edx = 10844916 /*0xa57af4*/;
    // 00a57da2  bb017ba500             -mov ebx, 0xa57b01
    cpu.ebx = 10844929 /*0xa57b01*/;
    // 00a57da7  b9117ba500             -mov ecx, 0xa57b11
    cpu.ecx = 10844945 /*0xa57b11*/;
    // 00a57dac  be167ba500             -mov esi, 0xa57b16
    cpu.esi = 10844950 /*0xa57b16*/;
    // 00a57db1  bfe07aa500             -mov edi, 0xa57ae0
    cpu.edi = 10844896 /*0xa57ae0*/;
    // 00a57db6  bdea7aa500             -mov ebp, 0xa57aea
    cpu.ebp = 10844906 /*0xa57aea*/;
    // 00a57dbb  b8547ba500             -mov eax, 0xa57b54
    cpu.eax = 10845012 /*0xa57b54*/;
    // 00a57dc0  891568dca500           -mov dword ptr [0xa5dc68], edx
    app->getMemory<x86::reg32>(x86::reg32(10869864) /* 0xa5dc68 */) = cpu.edx;
    // 00a57dc6  891d6cdca500           -mov dword ptr [0xa5dc6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10869868) /* 0xa5dc6c */) = cpu.ebx;
    // 00a57dcc  890d70dca500           -mov dword ptr [0xa5dc70], ecx
    app->getMemory<x86::reg32>(x86::reg32(10869872) /* 0xa5dc70 */) = cpu.ecx;
    // 00a57dd2  893574dca500           -mov dword ptr [0xa5dc74], esi
    app->getMemory<x86::reg32>(x86::reg32(10869876) /* 0xa5dc74 */) = cpu.esi;
    // 00a57dd8  893d78dca500           -mov dword ptr [0xa5dc78], edi
    app->getMemory<x86::reg32>(x86::reg32(10869880) /* 0xa5dc78 */) = cpu.edi;
    // 00a57dde  892d7cdca500           -mov dword ptr [0xa5dc7c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10869884) /* 0xa5dc7c */) = cpu.ebp;
    // 00a57de4  a390dca500             -mov dword ptr [0xa5dc90], eax
    app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */) = cpu.eax;
    // 00a57de9  ba5b7ba500             -mov edx, 0xa57b5b
    cpu.edx = 10845019 /*0xa57b5b*/;
    // 00a57dee  bb677ba500             -mov ebx, 0xa57b67
    cpu.ebx = 10845031 /*0xa57b67*/;
    // 00a57df3  b9cd7ba500             -mov ecx, 0xa57bcd
    cpu.ecx = 10845133 /*0xa57bcd*/;
    // 00a57df8  beb27aa500             -mov esi, 0xa57ab2
    cpu.esi = 10844850 /*0xa57ab2*/;
    // 00a57dfd  bf327ba500             -mov edi, 0xa57b32
    cpu.edi = 10844978 /*0xa57b32*/;
    // 00a57e02  bd437ba500             -mov ebp, 0xa57b43
    cpu.ebp = 10844995 /*0xa57b43*/;
    // 00a57e07  b8397ba500             -mov eax, 0xa57b39
    cpu.eax = 10844985 /*0xa57b39*/;
    // 00a57e0c  891594dca500           -mov dword ptr [0xa5dc94], edx
    app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */) = cpu.edx;
    // 00a57e12  891d0cdda500           -mov dword ptr [0xa5dd0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10870028) /* 0xa5dd0c */) = cpu.ebx;
    // 00a57e18  890d10dda500           -mov dword ptr [0xa5dd10], ecx
    app->getMemory<x86::reg32>(x86::reg32(10870032) /* 0xa5dd10 */) = cpu.ecx;
    // 00a57e1e  893514dda500           -mov dword ptr [0xa5dd14], esi
    app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */) = cpu.esi;
    // 00a57e24  893d80dca500           -mov dword ptr [0xa5dc80], edi
    app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */) = cpu.edi;
    // 00a57e2a  892d84dca500           -mov dword ptr [0xa5dc84], ebp
    app->getMemory<x86::reg32>(x86::reg32(10869892) /* 0xa5dc84 */) = cpu.ebp;
    // 00a57e30  a388dca500             -mov dword ptr [0xa5dc88], eax
    app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */) = cpu.eax;
    // 00a57e35  ba4a7ba500             -mov edx, 0xa57b4a
    cpu.edx = 10845002 /*0xa57b4a*/;
    // 00a57e3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a57e3f  bec87ba500             -mov esi, 0xa57bc8
    cpu.esi = 10845128 /*0xa57bc8*/;
    // 00a57e44  89158cdca500           -mov dword ptr [0xa5dc8c], edx
    app->getMemory<x86::reg32>(x86::reg32(10869900) /* 0xa5dc8c */) = cpu.edx;
    // 00a57e4a  e80ffcffff             -call 0xa57a5e
    cpu.esp -= 4;
    sub_a57a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a57e4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57e50  bf6b7da500             -mov edi, 0xa57d6b
    cpu.edi = 10845547 /*0xa57d6b*/;
    // 00a57e55  a350eaa500             -mov dword ptr [0xa5ea50], eax
    app->getMemory<x86::reg32>(x86::reg32(10873424) /* 0xa5ea50 */) = cpu.eax;
    // 00a57e5a  2eff1584b9a500         -call dword ptr cs:[0xa5b984]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860932) /* 0xa5b984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57e61  b9627ba500             -mov ecx, 0xa57b62
    cpu.ecx = 10845026 /*0xa57b62*/;
    // 00a57e66  8b151ce9a500           -mov edx, dword ptr [0xa5e91c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10873116) /* 0xa5e91c */);
    // 00a57e6c  891d54eaa500           -mov dword ptr [0xa5ea54], ebx
    app->getMemory<x86::reg32>(x86::reg32(10873428) /* 0xa5ea54 */) = cpu.ebx;
    // 00a57e72  89359cdca500           -mov dword ptr [0xa5dc9c], esi
    app->getMemory<x86::reg32>(x86::reg32(10869916) /* 0xa5dc9c */) = cpu.esi;
    // 00a57e78  893da0dca500           -mov dword ptr [0xa5dca0], edi
    app->getMemory<x86::reg32>(x86::reg32(10869920) /* 0xa5dca0 */) = cpu.edi;
    // 00a57e7e  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00a57e84  890d98dca500           -mov dword ptr [0xa5dc98], ecx
    app->getMemory<x86::reg32>(x86::reg32(10869912) /* 0xa5dc98 */) = cpu.ecx;
    // 00a57e8a  e8860c0000             -call 0xa58b15
    cpu.esp -= 4;
    sub_a58b15(app, cpu);
    if (cpu.terminate) return;
    // 00a57e8f  8b2d1ce9a500           -mov ebp, dword ptr [0xa5e91c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10873116) /* 0xa5e91c */);
    // 00a57e95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57e96  a160dca500             -mov eax, dword ptr [0xa5dc60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a57e9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57e9c  2eff15bcb9a500         -call dword ptr cs:[0xa5b9bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860988) /* 0xa5b9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ea3  c70564dca500f47ba500   -mov dword ptr [0xa5dc64], 0xa57bf4
    app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */) = 10845172 /*0xa57bf4*/;
    // 00a57ead  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57eae  e9b2feffff             -jmp 0xa57d65
    return sub_a57d65(app, cpu);
}

/* align: skip  */
void sub_a57eb3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57eb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57eb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57eb5  b820e9a500             -mov eax, 0xa5e920
    cpu.eax = 10873120 /*0xa5e920*/;
    // 00a57eba  ba40e9a500             -mov edx, 0xa5e940
    cpu.edx = 10873152 /*0xa5e940*/;
    // 00a57ebf  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ec5  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00a57ecb:
    // 00a57ecb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57ecd  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a57ed0  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ed6  39da                   +cmp edx, ebx
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
    // 00a57ed8  75f1                   -jne 0xa57ecb
    if (!cpu.flags.zf)
    {
        goto L_0x00a57ecb;
    }
    // 00a57eda  b870eaa500             -mov eax, 0xa5ea70
    cpu.eax = 10873456 /*0xa5ea70*/;
    // 00a57edf  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ee5  e8720d0000             -call 0xa58c5c
    cpu.esp -= 4;
    sub_a58c5c(app, cpu);
    if (cpu.terminate) return;
    // 00a57eea  b840eaa500             -mov eax, 0xa5ea40
    cpu.eax = 10873408 /*0xa5ea40*/;
    // 00a57eef  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57ef5  b830e9a500             -mov eax, 0xa5e930
    cpu.eax = 10873136 /*0xa5e930*/;
    // 00a57efa  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57f00  b860eaa500             -mov eax, 0xa5ea60
    cpu.eax = 10873440 /*0xa5ea60*/;
    // 00a57f05  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57f0b  b850eaa500             -mov eax, 0xa5ea50
    cpu.eax = 10873424 /*0xa5ea50*/;
    // 00a57f10  ff1514dda500           -call dword ptr [0xa5dd14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870036) /* 0xa5dd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57f16  e85afeffff             -call 0xa57d75
    cpu.esp -= 4;
    sub_a57d75(app, cpu);
    if (cpu.terminate) return;
    // 00a57f1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57f1e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57f1e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57f1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57f20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57f21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57f22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a57f24  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a57f26  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a57f27  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a57f29  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a57f2b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a57f2d  49                     -dec ecx
    (cpu.ecx)--;
    // 00a57f2e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a57f30  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a57f32  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a57f34  49                     -dec ecx
    (cpu.ecx)--;
    // 00a57f35  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a57f36  41                     -inc ecx
    (cpu.ecx)++;
    // 00a57f37  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a57f39  e8d2060000             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a57f3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57f40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57f42  7418                   -je 0xa57f5c
    if (cpu.flags.zf)
    {
        goto L_0x00a57f5c;
    }
    // 00a57f44  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a57f46  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a57f47  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a57f49  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a57f4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57f4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a57f4e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a57f51  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a57f53  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a57f55  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a57f58  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a57f5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f5b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a57f5c:
    // 00a57f5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a57f5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57f63(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57f63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57f64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57f65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57f66  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57f67  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a57f69  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a57f6b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a57f6d  2eff1580b9a500         -call dword ptr cs:[0xa5b980]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860928) /* 0xa5b980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57f74  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a57f77  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a57f7c  663d0080               +cmp ax, 0x8000
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
    // 00a57f80  730f                   -jae 0xa57f91
    if (!cpu.flags.cf)
    {
        goto L_0x00a57f91;
    }
    // 00a57f82  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57f83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57f84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57f85  2eff156cb9a500         -call dword ptr cs:[0xa5b96c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860908) /* 0xa5b96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57f8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57f90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57f91:
    // 00a57f91  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00a57f96  e875060000             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a57f9b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a57f9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57f9f  744d                   -je 0xa57fee
    if (cpu.flags.zf)
    {
        goto L_0x00a57fee;
    }
    // 00a57fa1  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00a57fa6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a57fa7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a57fa8  2eff1568b9a500         -call dword ptr cs:[0xa5b968]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860904) /* 0xa5b968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a57fb1  750e                   -jne 0xa57fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00a57fc1;
    }
    // 00a57fb3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57fb5  e843070000             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a57fba:
    // 00a57fba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a57fbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57fbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57fbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57fbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57fc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a57fc1:
    // 00a57fc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a57fc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a57fc3  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a57fc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57fc6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a57fc8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a57fca  2eff1590b9a500         -call dword ptr cs:[0xa5b990]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860944) /* 0xa5b990 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a57fd1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a57fd3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a57fd5  e823070000             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a57fda  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a57fdc  74dc                   -je 0xa57fba
    if (cpu.flags.zf)
    {
        goto L_0x00a57fba;
    }
    // 00a57fde  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a57fe0  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 00a57fe7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a57fe9  e8350d0000             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
L_0x00a57fee:
    // 00a57fee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57fef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ff0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ff1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a57ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a57ff3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a57ff3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a57ff4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a57ff5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a57ff6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a57ff8  e8260d0000             -call 0xa58d23
    cpu.esp -= 4;
    sub_a58d23(app, cpu);
    if (cpu.terminate) return;
    // 00a57ffd  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a58000  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a58002  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58004  e807060000             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a58009  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a5800b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5800d  7405                   -je 0xa58014
    if (cpu.flags.zf)
    {
        goto L_0x00a58014;
    }
    // 00a5800f  e8220d0000             -call 0xa58d36
    cpu.esp -= 4;
    sub_a58d36(app, cpu);
    if (cpu.terminate) return;
L_0x00a58014:
    // 00a58014  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58016  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58017  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58018  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5801a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5801a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5801b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5801c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5801d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a58020  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58022  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a58024  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00a58026  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a5802a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5802b  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a5802f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a58030  2eff15ccb9a500         -call dword ptr cs:[0xa5b9cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10861004) /* 0xa5b9cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58037  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a5803a  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a5803e  668b0d21dba500         -mov cx, word ptr [0xa5db21]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(10869537) /* 0xa5db21 */);
    // 00a58045  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58049  6681f90080             +cmp cx, 0x8000
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
    // 00a5804e  7307                   -jae 0xa58057
    if (!cpu.flags.cf)
    {
        goto L_0x00a58057;
    }
    // 00a58050  0500300000             +add eax, 0x3000
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
    // 00a58055  eb17                   -jmp 0xa5806e
    goto L_0x00a5806e;
L_0x00a58057:
    // 00a58057  7210                   -jb 0xa58069
    if (cpu.flags.cf)
    {
        goto L_0x00a58069;
    }
    // 00a58059  803d1fdba50004         +cmp byte ptr [0xa5db1f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10869535) /* 0xa5db1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a58060  7307                   -jae 0xa58069
    if (!cpu.flags.cf)
    {
        goto L_0x00a58069;
    }
    // 00a58062  0500200100             +add eax, 0x12000
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
    // 00a58067  eb05                   -jmp 0xa5806e
    goto L_0x00a5806e;
L_0x00a58069:
    // 00a58069  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00a5806e:
    // 00a5806e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a58070  7402                   -je 0xa58074
    if (cpu.flags.zf)
    {
        goto L_0x00a58074;
    }
    // 00a58072  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a58074:
    // 00a58074  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a58076  7402                   -je 0xa5807a
    if (cpu.flags.zf)
    {
        goto L_0x00a5807a;
    }
    // 00a58078  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00a5807a:
    // 00a5807a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a5807d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5807e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5807f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58081(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58081  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58082  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58083  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58084  6870cba500             -push 0xa5cb70
    app->getMemory<x86::reg32>(cpu.esp-4) = 10865520 /*0xa5cb70*/;
    cpu.esp -= 4;
    // 00a58089  2eff158cb9a500         -call dword ptr cs:[0xa5b98c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860940) /* 0xa5b98c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58090  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a58092  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58094  7417                   -je 0xa580ad
    if (cpu.flags.zf)
    {
        goto L_0x00a580ad;
    }
    // 00a58096  687bcba500             -push 0xa5cb7b
    app->getMemory<x86::reg32>(cpu.esp-4) = 10865531 /*0xa5cb7b*/;
    cpu.esp -= 4;
    // 00a5809b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5809c  2eff1578b9a500         -call dword ptr cs:[0xa5b978]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860920) /* 0xa5b978 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a580a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a580a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a580a7  7404                   -je 0xa580ad
    if (cpu.flags.zf)
    {
        goto L_0x00a580ad;
    }
    // 00a580a9  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a580ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a580ad:
    // 00a580ad  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a580af  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a580b2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a580b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a580b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a580b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a580ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a580bb(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a580bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a580bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a580bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a580be  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a580c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a580c2:
    // 00a580c2  803800                 +cmp byte ptr [eax], 0
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
    // 00a580c5  7403                   -je 0xa580ca
    if (cpu.flags.zf)
    {
        goto L_0x00a580ca;
    }
    // 00a580c7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a580c8  ebf8                   -jmp 0xa580c2
    goto L_0x00a580c2;
L_0x00a580ca:
    // 00a580ca  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00a580cd:
    // 00a580cd  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a580cf  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a580d1  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a580d3  7412                   -je 0xa580e7
    if (cpu.flags.zf)
    {
        goto L_0x00a580e7;
    }
    // 00a580d5  80f930                 +cmp cl, 0x30
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
    // 00a580d8  7508                   -jne 0xa580e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a580e2;
    }
    // 00a580da  807a0178               +cmp byte ptr [edx + 1], 0x78
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
    // 00a580de  7502                   -jne 0xa580e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a580e2;
    }
    // 00a580e0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00a580e2:
    // 00a580e2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a580e3  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a580e4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a580e5  ebe6                   -jmp 0xa580cd
    goto L_0x00a580cd;
L_0x00a580e7:
    // 00a580e7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a580e9  7419                   -je 0xa58104
    if (cpu.flags.zf)
    {
        goto L_0x00a58104;
    }
    // 00a580eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a580ed:
    // 00a580ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a580ef  7413                   -je 0xa58104
    if (cpu.flags.zf)
    {
        goto L_0x00a58104;
    }
    // 00a580f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a580f3  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a580f6  8a9224dea500           -mov dl, byte ptr [edx + 0xa5de24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10870308) /* 0xa5de24 */);
    // 00a580fc  c1e804                 +shr eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a580ff  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00a58101  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a58102  ebe9                   -jmp 0xa580ed
    goto L_0x00a580ed;
L_0x00a58104:
    // 00a58104  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58105  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58106  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58107  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58108(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58108  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58109  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a5810a  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a58110  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00a58117  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a58119  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a5811c  e860ffffff             -call 0xa58081
    cpu.esp -= 4;
    sub_a58081(app, cpu);
    if (cpu.terminate) return;
    // 00a58121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58123  750a                   -jne 0xa5812f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5812f;
    }
    // 00a58125  e8ce0c0000             -call 0xa58df8
    cpu.esp -= 4;
    sub_a58df8(app, cpu);
    if (cpu.terminate) return;
    // 00a5812a  83f8ff                 +cmp eax, -1
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
    // 00a5812d  7507                   -jne 0xa58136
    if (!cpu.flags.zf)
    {
        goto L_0x00a58136;
    }
L_0x00a5812f:
    // 00a5812f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a58131  e97e010000             -jmp 0xa582b4
    goto L_0x00a582b4;
L_0x00a58136:
    // 00a58136  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a58138  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00a5813b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a5813d  3d900000c0             +cmp eax, 0xc0000090
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
    // 00a58142  724d                   -jb 0xa58191
    if (cpu.flags.cf)
    {
        goto L_0x00a58191;
    }
    // 00a58144  0f86b5000000           -jbe 0xa581ff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a581ff;
    }
    // 00a5814a  3d930000c0             +cmp eax, 0xc0000093
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
    // 00a5814f  7233                   -jb 0xa58184
    if (cpu.flags.cf)
    {
        goto L_0x00a58184;
    }
    // 00a58151  0f86a1000000           -jbe 0xa581f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a581f8;
    }
    // 00a58157  3d960000c0             +cmp eax, 0xc0000096
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
    // 00a5815c  7216                   -jb 0xa58174
    if (cpu.flags.cf)
    {
        goto L_0x00a58174;
    }
    // 00a5815e  0f86d8000000           -jbe 0xa5823c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a5823c;
    }
    // 00a58164  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 00a58169  0f84e5000000           -je 0xa58254
    if (cpu.flags.zf)
    {
        goto L_0x00a58254;
    }
    // 00a5816f  e9ea000000             -jmp 0xa5825e
    goto L_0x00a5825e;
L_0x00a58174:
    // 00a58174  3d940000c0             +cmp eax, 0xc0000094
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
    // 00a58179  0f84cb000000           -je 0xa5824a
    if (cpu.flags.zf)
    {
        goto L_0x00a5824a;
    }
    // 00a5817f  e9da000000             -jmp 0xa5825e
    goto L_0x00a5825e;
L_0x00a58184:
    // 00a58184  3d910000c0             +cmp eax, 0xc0000091
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
    // 00a58189  0f8662000000           -jbe 0xa581f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a581f1;
    }
    // 00a5818f  eb2f                   -jmp 0xa581c0
    goto L_0x00a581c0;
L_0x00a58191:
    // 00a58191  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 00a58196  720b                   -jb 0xa581a3
    if (cpu.flags.cf)
    {
        goto L_0x00a581a3;
    }
    // 00a58198  7642                   -jbe 0xa581dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a581dc;
    }
    // 00a5819a  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 00a5819f  7642                   -jbe 0xa581e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a581e3;
    }
    // 00a581a1  eb47                   -jmp 0xa581ea
    goto L_0x00a581ea;
L_0x00a581a3:
    // 00a581a3  3d050000c0             +cmp eax, 0xc0000005
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
    // 00a581a8  0f82b0000000           -jb 0xa5825e
    if (cpu.flags.cf)
    {
        goto L_0x00a5825e;
    }
    // 00a581ae  7656                   -jbe 0xa58206
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58206;
    }
    // 00a581b0  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 00a581b5  0f8488000000           -je 0xa58243
    if (cpu.flags.zf)
    {
        goto L_0x00a58243;
    }
    // 00a581bb  e99e000000             -jmp 0xa5825e
    goto L_0x00a5825e;
L_0x00a581c0:
    // 00a581c0  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a581c4  740f                   -je 0xa581d5
    if (cpu.flags.zf)
    {
        goto L_0x00a581d5;
    }
    // 00a581c6  ba8bcba500             -mov edx, 0xa5cb8b
    cpu.edx = 10865547 /*0xa5cb8b*/;
L_0x00a581cb:
    // 00a581cb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a581cd  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a581d0  e9a1000000             -jmp 0xa58276
    goto L_0x00a58276;
L_0x00a581d5:
    // 00a581d5  badccba500             -mov edx, 0xa5cbdc
    cpu.edx = 10865628 /*0xa5cbdc*/;
    // 00a581da  ebef                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581dc:
    // 00a581dc  ba2ecca500             -mov edx, 0xa5cc2e
    cpu.edx = 10865710 /*0xa5cc2e*/;
    // 00a581e1  ebe8                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581e3:
    // 00a581e3  ba81cca500             -mov edx, 0xa5cc81
    cpu.edx = 10865793 /*0xa5cc81*/;
    // 00a581e8  ebe1                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581ea:
    // 00a581ea  bad4cca500             -mov edx, 0xa5ccd4
    cpu.edx = 10865876 /*0xa5ccd4*/;
    // 00a581ef  ebda                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581f1:
    // 00a581f1  ba25cda500             -mov edx, 0xa5cd25
    cpu.edx = 10865957 /*0xa5cd25*/;
    // 00a581f6  ebd3                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581f8:
    // 00a581f8  ba71cda500             -mov edx, 0xa5cd71
    cpu.edx = 10866033 /*0xa5cd71*/;
    // 00a581fd  ebcc                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a581ff:
    // 00a581ff  babecda500             -mov edx, 0xa5cdbe
    cpu.edx = 10866110 /*0xa5cdbe*/;
    // 00a58204  ebc5                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a58206:
    // 00a58206  ba13cea500             -mov edx, 0xa5ce13
    cpu.edx = 10866195 /*0xa5ce13*/;
    // 00a5820b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5820d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a58210  e8a6feffff             -call 0xa580bb
    cpu.esp -= 4;
    sub_a580bb(app, cpu);
    if (cpu.terminate) return;
    // 00a58215  ba44cea500             -mov edx, 0xa5ce44
    cpu.edx = 10866244 /*0xa5ce44*/;
    // 00a5821a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a5821c  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a5821f  e897feffff             -call 0xa580bb
    cpu.esp -= 4;
    sub_a580bb(app, cpu);
    if (cpu.terminate) return;
    // 00a58224  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 00a58228  750b                   -jne 0xa58235
    if (!cpu.flags.zf)
    {
        goto L_0x00a58235;
    }
    // 00a5822a  ba6ccea500             -mov edx, 0xa5ce6c
    cpu.edx = 10866284 /*0xa5ce6c*/;
L_0x00a5822f:
    // 00a5822f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a58231  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a58233  eb41                   -jmp 0xa58276
    goto L_0x00a58276;
L_0x00a58235:
    // 00a58235  ba73cea500             -mov edx, 0xa5ce73
    cpu.edx = 10866291 /*0xa5ce73*/;
    // 00a5823a  ebf3                   -jmp 0xa5822f
    goto L_0x00a5822f;
L_0x00a5823c:
    // 00a5823c  ba7dcea500             -mov edx, 0xa5ce7d
    cpu.edx = 10866301 /*0xa5ce7d*/;
    // 00a58241  eb88                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a58243:
    // 00a58243  babbcea500             -mov edx, 0xa5cebb
    cpu.edx = 10866363 /*0xa5cebb*/;
    // 00a58248  eb81                   -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a5824a:
    // 00a5824a  baf7cea500             -mov edx, 0xa5cef7
    cpu.edx = 10866423 /*0xa5cef7*/;
    // 00a5824f  e977ffffff             -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a58254:
    // 00a58254  ba39cfa500             -mov edx, 0xa5cf39
    cpu.edx = 10866489 /*0xa5cf39*/;
    // 00a58259  e96dffffff             -jmp 0xa581cb
    goto L_0x00a581cb;
L_0x00a5825e:
    // 00a5825e  ba72cfa500             -mov edx, 0xa5cf72
    cpu.edx = 10866546 /*0xa5cf72*/;
    // 00a58263  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a58265  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58267  e84ffeffff             -call 0xa580bb
    cpu.esp -= 4;
    sub_a580bb(app, cpu);
    if (cpu.terminate) return;
    // 00a5826c  baa3cfa500             -mov edx, 0xa5cfa3
    cpu.edx = 10866595 /*0xa5cfa3*/;
    // 00a58271  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a58273  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00a58276:
    // 00a58276  e840feffff             -call 0xa580bb
    cpu.esp -= 4;
    sub_a580bb(app, cpu);
    if (cpu.terminate) return;
    // 00a5827b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a5827d  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a58284  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a58285  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a58289  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5828a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a5828c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a5828e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58290  49                     -dec ecx
    (cpu.ecx)--;
    // 00a58291  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a58293  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a58295  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a58297  49                     -dec ecx
    (cpu.ecx)--;
    // 00a58298  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a58299  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5829a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5829e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5829f  a154dca500             -mov eax, dword ptr [0xa5dc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10869844) /* 0xa5dc54 */);
    // 00a582a4  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a582a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a582a8  2eff15d8b9a500         -call dword ptr cs:[0xa5b9d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10861016) /* 0xa5b9d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a582af  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a582b4:
    // 00a582b4  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a582ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a582bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a582bc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
/* data blob: 8bc02783a5003183a5003b83a5005983a5004583a5000d83a5004f83a500 */
void sub_a582dd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a582dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a582de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a582df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a582e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a582e3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a582e7  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a582eb  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00a582ef  0f85a0010000           -jne 0xa58495
    if (!cpu.flags.zf)
    {
        goto L_0x00a58495;
    }
    // 00a582f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a582f7  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00a582fc  83f806                 +cmp eax, 6
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
    // 00a582ff  0f8723010000           -ja 0xa58428
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58428;
    }
    // 00a58305  2eff2485c182a500       -jmp dword ptr cs:[eax*4 + 0xa582c1]
    cpu.ip = app->getMemory<x86::reg32>(10846913 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a5830d:
    // 00a5830d  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a58311  740a                   -je 0xa5831d
    if (cpu.flags.zf)
    {
        goto L_0x00a5831d;
    }
    // 00a58313  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00a58318  e9ce000000             -jmp 0xa583eb
    goto L_0x00a583eb;
L_0x00a5831d:
    // 00a5831d  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00a58322  e9c4000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a58327:
    // 00a58327  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00a5832c  e9ba000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a58331:
L_0x00a58331:
    // 00a58331  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00a58336  e9b0000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a5833b:
    // 00a5833b  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00a58340  e9a6000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a58345:
    // 00a58345  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00a5834a  e99c000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a5834f:
    // 00a5834f  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00a58354  e992000000             -jmp 0xa583eb
    goto L_0x00a583eb;
  case 0x00a58359:
    // 00a58359  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a5835c  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a5835f  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00a58364  6681fad9fa             +cmp dx, 0xfad9
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
    // 00a58369  750a                   -jne 0xa58375
    if (!cpu.flags.zf)
    {
        goto L_0x00a58375;
    }
    // 00a5836b  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00a58370  e976000000             -jmp 0xa583eb
    goto L_0x00a583eb;
L_0x00a58375:
    // 00a58375  6681fad9f1             +cmp dx, 0xf1d9
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
    // 00a5837a  750a                   -jne 0xa58386
    if (!cpu.flags.zf)
    {
        goto L_0x00a58386;
    }
    // 00a5837c  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00a58381  e965000000             -jmp 0xa583eb
    goto L_0x00a583eb;
L_0x00a58386:
    // 00a58386  7507                   -jne 0xa5838f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5838f;
    }
    // 00a58388  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00a5838d  eb5c                   -jmp 0xa583eb
    goto L_0x00a583eb;
L_0x00a5838f:
    // 00a5838f  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a58391  80fedb                 +cmp dh, 0xdb
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
    // 00a58394  7405                   -je 0xa5839b
    if (cpu.flags.zf)
    {
        goto L_0x00a5839b;
    }
    // 00a58396  80fedf                 +cmp dh, 0xdf
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
    // 00a58399  7510                   -jne 0xa583ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a583ab;
    }
L_0x00a5839b:
    // 00a5839b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5839e  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a583a1  80fa10                 +cmp dl, 0x10
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
    // 00a583a4  7505                   -jne 0xa583ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a583ab;
    }
    // 00a583a6  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00a583ab:
    // 00a583ab  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a583ae  7536                   -jne 0xa583e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a583e6;
    }
    // 00a583b0  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a583b3  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a583b5  3c30                   +cmp al, 0x30
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
    // 00a583b7  752d                   -jne 0xa583e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a583e6;
    }
    // 00a583b9  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a583bc  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a583c1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a583c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a583c6  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00a583ca  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00a583cd  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00a583d0  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a583d6  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a583d8  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00a583da  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00a583dd  83fa01                 +cmp edx, 1
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
    // 00a583e0  0f844bffffff           -je 0xa58331
    if (cpu.flags.zf)
    {
        goto L_0x00a58331;
    }
L_0x00a583e6:
    // 00a583e6  83fbff                 +cmp ebx, -1
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
    // 00a583e9  743d                   -je 0xa58428
    if (cpu.flags.zf)
    {
        goto L_0x00a58428;
    }
L_0x00a583eb:
    // 00a583eb  c60594f0a50001         -mov byte ptr [0xa5f094], 1
    app->getMemory<x86::reg8>(x86::reg32(10875028) /* 0xa5f094 */) = 1 /*0x1*/;
    // 00a583f2  e80c0a0000             -call 0xa58e03
    cpu.esp -= 4;
    sub_a58e03(app, cpu);
    if (cpu.terminate) return;
    // 00a583f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a583f9  e8d20b0000             -call 0xa58fd0
    cpu.esp -= 4;
    sub_a58fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a583fe  83f8ff                 +cmp eax, -1
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
    // 00a58401  0f846f000000           -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a58407  803d94f0a50000         +cmp byte ptr [0xa5f094], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10875028) /* 0xa5f094 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a5840e  0f8462000000           -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a58414  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a58418  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a5841a  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a5841d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5841f  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00a58423  e972000000             -jmp 0xa5849a
    goto L_0x00a5849a;
L_0x00a58428:
    // 00a58428  833d20dea50000         +cmp dword ptr [0xa5de20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10870304) /* 0xa5de20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5842f  7445                   -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a58431  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a58436:
    // 00a58436  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58438  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a5843a  ff151cdea500           -call dword ptr [0xa5de1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870300) /* 0xa5de1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58440  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58442  742c                   -je 0xa58470
    if (cpu.flags.zf)
    {
        goto L_0x00a58470;
    }
    // 00a58444  83f801                 +cmp eax, 1
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
    // 00a58447  742d                   -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a58449  83f802                 +cmp eax, 2
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
    // 00a5844c  7428                   -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a5844e  83f803                 +cmp eax, 3
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
    // 00a58451  7423                   -je 0xa58476
    if (cpu.flags.zf)
    {
        goto L_0x00a58476;
    }
    // 00a58453  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00a58455  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58457  881594f0a500           -mov byte ptr [0xa5f094], dl
    app->getMemory<x86::reg8>(x86::reg32(10875028) /* 0xa5f094 */) = cpu.dl;
    // 00a5845d  ff1520dea500           -call dword ptr [0xa5de20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870304) /* 0xa5de20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58463  803d94f0a50000         +cmp byte ptr [0xa5f094], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10875028) /* 0xa5f094 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a5846a  7404                   -je 0xa58470
    if (cpu.flags.zf)
    {
        goto L_0x00a58470;
    }
    // 00a5846c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5846e  eb2a                   -jmp 0xa5849a
    goto L_0x00a5849a;
L_0x00a58470:
    // 00a58470  43                     -inc ebx
    (cpu.ebx)++;
    // 00a58471  83fb0c                 +cmp ebx, 0xc
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
    // 00a58474  7ec0                   -jle 0xa58436
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a58436;
    }
L_0x00a58476:
    // 00a58476  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a58478  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a58479  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a5847d  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a58481  2eff15c0b9a500         -call dword ptr cs:[0xa5b9c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860992) /* 0xa5b9c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58488  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5848a  7409                   -je 0xa58495
    if (cpu.flags.zf)
    {
        goto L_0x00a58495;
    }
    // 00a5848c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a5848e  2eff153cb9a500         -call dword ptr cs:[0xa5b93c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860860) /* 0xa5b93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a58495:
    // 00a58495  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a5849a:
    // 00a5849a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a5849d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5849e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5849f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a584a0  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip  */
void sub_a584a1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a584a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a584a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a584a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a584a5  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584ab  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00a584ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a584b0  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00a584b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a584b5  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584bb  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a584be  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a584c0  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584c6  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a584c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a584cb  c74004dd82a500         -mov dword ptr [eax + 4], 0xa582dd
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10846941 /*0xa582dd*/;
    // 00a584d2  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584d8  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a584db  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00a584de  680881a500             -push 0xa58108
    app->getMemory<x86::reg32>(cpu.esp-4) = 10846472 /*0xa58108*/;
    cpu.esp -= 4;
    // 00a584e3  2eff15acb9a500         -call dword ptr cs:[0xa5b9ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860972) /* 0xa5b9ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a584eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a584ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a584ed(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a584ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a584ee  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a584f4  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a584f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a584f9  7407                   -je 0xa58502
    if (cpu.flags.zf)
    {
        goto L_0x00a58502;
    }
    // 00a584fb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a584fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a584ff  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00a58502:
    // 00a58502  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58508  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00a5850f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58511(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58511  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a58512  833800                 +cmp dword ptr [eax], 0
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
    // 00a58515  7404                   -je 0xa5851b
    if (cpu.flags.zf)
    {
        goto L_0x00a5851b;
    }
    // 00a58517  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a58518  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a58519  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a5851b:
    // 00a5851b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a5851c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5851d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5851d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5851e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5851f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58520  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58521  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a58522  be04e1a500             -mov esi, 0xa5e104
    cpu.esi = 10871044 /*0xa5e104*/;
    // 00a58527  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00a58529:
    // 00a58529  b8e0e0a500             -mov eax, 0xa5e0e0
    cpu.eax = 10871008 /*0xa5e0e0*/;
    // 00a5852e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a58530  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
L_0x00a58532:
    // 00a58532  3d04e1a500             +cmp eax, 0xa5e104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10871044 /*0xa5e104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58537  7315                   -jae 0xa5854e
    if (!cpu.flags.cf)
    {
        goto L_0x00a5854e;
    }
    // 00a58539  803802                 +cmp byte ptr [eax], 2
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
    // 00a5853c  740b                   -je 0xa58549
    if (cpu.flags.zf)
    {
        goto L_0x00a58549;
    }
    // 00a5853e  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a58541  38ea                   +cmp dl, ch
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
    // 00a58543  7204                   -jb 0xa58549
    if (cpu.flags.cf)
    {
        goto L_0x00a58549;
    }
    // 00a58545  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58547  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a58549:
    // 00a58549  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a5854c  ebe4                   -jmp 0xa58532
    goto L_0x00a58532;
L_0x00a5854e:
    // 00a5854e  81fb04e1a500           +cmp ebx, 0xa5e104
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10871044 /*0xa5e104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58554  740d                   -je 0xa58563
    if (cpu.flags.zf)
    {
        goto L_0x00a58563;
    }
    // 00a58556  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a58559  e8b3ffffff             -call 0xa58511
    cpu.esp -= 4;
    sub_a58511(app, cpu);
    if (cpu.terminate) return;
    // 00a5855e  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a58561  ebc6                   -jmp 0xa58529
    goto L_0x00a58529;
L_0x00a58563:
    // 00a58563  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a58564  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58565  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58566  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58567  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58569(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58569  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5856a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5856b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5856c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a5856d  be10e1a500             -mov esi, 0xa5e110
    cpu.esi = 10871056 /*0xa5e110*/;
    // 00a58572  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a58574  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00a58576:
    // 00a58576  b804e1a500             -mov eax, 0xa5e104
    cpu.eax = 10871044 /*0xa5e104*/;
    // 00a5857b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a5857d  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x00a5857f:
    // 00a5857f  3d10e1a500             +cmp eax, 0xa5e110
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10871056 /*0xa5e110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58584  7315                   -jae 0xa5859b
    if (!cpu.flags.cf)
    {
        goto L_0x00a5859b;
    }
    // 00a58586  803802                 +cmp byte ptr [eax], 2
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
    // 00a58589  740b                   -je 0xa58596
    if (cpu.flags.zf)
    {
        goto L_0x00a58596;
    }
    // 00a5858b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a5858e  38ea                   +cmp dl, ch
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
    // 00a58590  7704                   -ja 0xa58596
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58596;
    }
    // 00a58592  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58594  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a58596:
    // 00a58596  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a58599  ebe4                   -jmp 0xa5857f
    goto L_0x00a5857f;
L_0x00a5859b:
    // 00a5859b  81fb10e1a500           +cmp ebx, 0xa5e110
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10871056 /*0xa5e110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a585a1  7412                   -je 0xa585b5
    if (cpu.flags.zf)
    {
        goto L_0x00a585b5;
    }
    // 00a585a3  3a7301                 +cmp dh, byte ptr [ebx + 1]
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
    // 00a585a6  7208                   -jb 0xa585b0
    if (cpu.flags.cf)
    {
        goto L_0x00a585b0;
    }
    // 00a585a8  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a585ab  e861ffffff             -call 0xa58511
    cpu.esp -= 4;
    sub_a58511(app, cpu);
    if (cpu.terminate) return;
L_0x00a585b0:
    // 00a585b0  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a585b3  ebc1                   -jmp 0xa58576
    goto L_0x00a58576;
L_0x00a585b5:
    // 00a585b5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a585b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a585ba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a585ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a585bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a585bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a585bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a585bf  ff1568dca500           -call dword ptr [0xa5dc68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869864) /* 0xa5dc68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a585c5  833dbcdea50000         +cmp dword ptr [0xa5debc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10870460) /* 0xa5debc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a585cc  741d                   -je 0xa585eb
    if (cpu.flags.zf)
    {
        goto L_0x00a585eb;
    }
    // 00a585ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a585d0  ff15bcdea500           -call dword ptr [0xa5debc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10870460) /* 0xa5debc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a585d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a585d8  7411                   -je 0xa585eb
    if (cpu.flags.zf)
    {
        goto L_0x00a585eb;
    }
L_0x00a585da:
    // 00a585da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a585dc  ff156cdca500           -call dword ptr [0xa5dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869868) /* 0xa5dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a585e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a585e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a585ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a585eb:
    // 00a585eb  a154dca500             -mov eax, dword ptr [0xa5dc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10869844) /* 0xa5dc54 */);
    // 00a585f0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a585f2  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a585f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a585f6  2eff1560b9a500         -call dword ptr cs:[0xa5b960]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860896) /* 0xa5b960 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a585fd  83f802                 +cmp eax, 2
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
    // 00a58600  74d8                   -je 0xa585da
    if (cpu.flags.zf)
    {
        goto L_0x00a585da;
    }
    // 00a58602  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58604  ff156cdca500           -call dword ptr [0xa5dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869868) /* 0xa5dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5860a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5860c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5860d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5860e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5860f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58610(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58613  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58614  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58615  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a58616  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a58618  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a5861a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a5861b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5861e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a58620  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58622  7405                   -je 0xa58629
    if (cpu.flags.zf)
    {
        goto L_0x00a58629;
    }
    // 00a58624  83f8d4                 +cmp eax, -0x2c
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
    // 00a58627  7607                   -jbe 0xa58630
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58630;
    }
L_0x00a58629:
    // 00a58629  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a5862b  e9be000000             -jmp 0xa586ee
    goto L_0x00a586ee;
L_0x00a58630:
    // 00a58630  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a58633  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00a58636  83fd10                 +cmp ebp, 0x10
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
    // 00a58639  7305                   -jae 0xa58640
    if (!cpu.flags.cf)
    {
        goto L_0x00a58640;
    }
    // 00a5863b  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00a58640:
    // 00a58640  ff1580dca500           -call dword ptr [0xa5dc80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58646  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a58648  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a5864a  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a5864d:
    // 00a5864d  3b2d40dea500           +cmp ebp, dword ptr [0xa5de40]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58653  760c                   -jbe 0xa58661
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58661;
    }
    // 00a58655  8b0d3cdea500           -mov ecx, dword ptr [0xa5de3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */);
    // 00a5865b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a5865d  7510                   -jne 0xa5866f
    if (!cpu.flags.zf)
    {
        goto L_0x00a5866f;
    }
    // 00a5865f  eb02                   -jmp 0xa58663
    goto L_0x00a58663;
L_0x00a58661:
    // 00a58661  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a58663:
    // 00a58663  890d40dea500           -mov dword ptr [0xa5de40], ecx
    app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */) = cpu.ecx;
    // 00a58669  8b0d38dea500           -mov ecx, dword ptr [0xa5de38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
L_0x00a5866f:
    // 00a5866f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58671  743c                   -je 0xa586af
    if (cpu.flags.zf)
    {
        goto L_0x00a586af;
    }
    // 00a58673  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a58676  890d3cdea500           -mov dword ptr [0xa5de3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */) = cpu.ecx;
    // 00a5867c  39fe                   +cmp esi, edi
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
    // 00a5867e  721c                   -jb 0xa5869c
    if (cpu.flags.cf)
    {
        goto L_0x00a5869c;
    }
    // 00a58680  b838dea500             -mov eax, 0xa5de38
    cpu.eax = 10870328 /*0xa5de38*/;
    // 00a58685  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a58687  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a5868d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a5868f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a58691  e8ea0a0000             -call 0xa59180
    cpu.esp -= 4;
    sub_a59180(app, cpu);
    if (cpu.terminate) return;
    // 00a58696  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58698  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5869a  7542                   -jne 0xa586de
    if (!cpu.flags.zf)
    {
        goto L_0x00a586de;
    }
L_0x00a5869c:
    // 00a5869c  3b3540dea500           +cmp esi, dword ptr [0xa5de40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a586a2  7606                   -jbe 0xa586aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a586aa;
    }
    // 00a586a4  893540dea500           -mov dword ptr [0xa5de40], esi
    app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */) = cpu.esi;
L_0x00a586aa:
    // 00a586aa  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a586ad  ebc0                   -jmp 0xa5866f
    goto L_0x00a5866f;
L_0x00a586af:
    // 00a586af  803c2400               +cmp byte ptr [esp], 0
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
    // 00a586b3  750b                   -jne 0xa586c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a586c0;
    }
    // 00a586b5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a586b7  e8aa0d0000             -call 0xa59466
    cpu.esp -= 4;
    sub_a59466(app, cpu);
    if (cpu.terminate) return;
    // 00a586bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a586be  7515                   -jne 0xa586d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a586d5;
    }
L_0x00a586c0:
    // 00a586c0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a586c2  e8fa0d0000             -call 0xa594c1
    cpu.esp -= 4;
    sub_a594c1(app, cpu);
    if (cpu.terminate) return;
    // 00a586c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a586c9  7413                   -je 0xa586de
    if (cpu.flags.zf)
    {
        goto L_0x00a586de;
    }
    // 00a586cb  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00a586cd  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00a586d0  e978ffffff             -jmp 0xa5864d
    goto L_0x00a5864d;
L_0x00a586d5:
    // 00a586d5  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00a586d9  e96fffffff             -jmp 0xa5864d
    goto L_0x00a5864d;
L_0x00a586de:
    // 00a586de  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00a586e0  882da0f0a500           -mov byte ptr [0xa5f0a0], ch
    app->getMemory<x86::reg8>(x86::reg32(10875040) /* 0xa5f0a0 */) = cpu.ch;
    // 00a586e6  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a586ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a586ee:
    // 00a586ee  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a586f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586f2  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a586f4  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a586f6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a586f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a586fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a586fd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a586fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a586fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a586ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58700  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58701  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a58703  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58705  0f84f1000000           -je 0xa587fc
    if (cpu.flags.zf)
    {
        goto L_0x00a587fc;
    }
    // 00a5870b  ff1580dca500           -call dword ptr [0xa5dc80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58711  8b0d98f0a500           -mov ecx, dword ptr [0xa5f098]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10875032) /* 0xa5f098 */);
    // 00a58717  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58719  7440                   -je 0xa5875b
    if (cpu.flags.zf)
    {
        goto L_0x00a5875b;
    }
    // 00a5871b  39f1                   +cmp ecx, esi
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
    // 00a5871d  770c                   -ja 0xa5872b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5872b;
    }
    // 00a5871f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58721  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58723  39f0                   +cmp eax, esi
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
    // 00a58725  0f878b000000           -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a5872b:
    // 00a5872b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a5872d  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a58730  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58732  7410                   -je 0xa58744
    if (cpu.flags.zf)
    {
        goto L_0x00a58744;
    }
    // 00a58734  39f1                   +cmp ecx, esi
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
    // 00a58736  770c                   -ja 0xa58744
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58744;
    }
    // 00a58738  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a5873a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5873c  39f2                   +cmp edx, esi
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
    // 00a5873e  0f8772000000           -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a58744:
    // 00a58744  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a58747  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58749  7410                   -je 0xa5875b
    if (cpu.flags.zf)
    {
        goto L_0x00a5875b;
    }
    // 00a5874b  39f1                   +cmp ecx, esi
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
    // 00a5874d  770c                   -ja 0xa5875b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a5875b;
    }
    // 00a5874f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58751  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58753  39f0                   +cmp eax, esi
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
    // 00a58755  0f875b000000           -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a5875b:
    // 00a5875b  8b0d3cdea500           -mov ecx, dword ptr [0xa5de3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */);
    // 00a58761  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58763  7434                   -je 0xa58799
    if (cpu.flags.zf)
    {
        goto L_0x00a58799;
    }
    // 00a58765  39f1                   +cmp ecx, esi
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
    // 00a58767  7708                   -ja 0xa58771
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58771;
    }
    // 00a58769  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a5876b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a5876d  39f0                   +cmp eax, esi
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
    // 00a5876f  7745                   -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a58771:
    // 00a58771  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58773  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a58776  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58778  740c                   -je 0xa58786
    if (cpu.flags.zf)
    {
        goto L_0x00a58786;
    }
    // 00a5877a  39f1                   +cmp ecx, esi
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
    // 00a5877c  7708                   -ja 0xa58786
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58786;
    }
    // 00a5877e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58780  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58782  39f2                   +cmp edx, esi
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
    // 00a58784  7730                   -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a58786:
    // 00a58786  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a58789  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a5878b  740c                   -je 0xa58799
    if (cpu.flags.zf)
    {
        goto L_0x00a58799;
    }
    // 00a5878d  39f1                   +cmp ecx, esi
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
    // 00a5878f  7708                   -ja 0xa58799
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a58799;
    }
    // 00a58791  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58793  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58795  39f0                   +cmp eax, esi
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
    // 00a58797  771d                   -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a58799:
    // 00a58799  8b0d38dea500           -mov ecx, dword ptr [0xa5de38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a5879f  eb0f                   -jmp 0xa587b0
    goto L_0x00a587b0;
L_0x00a587a1:
    // 00a587a1  39f1                   +cmp ecx, esi
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
    // 00a587a3  7708                   -ja 0xa587ad
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587ad;
    }
    // 00a587a5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a587a7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a587a9  39f0                   +cmp eax, esi
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
    // 00a587ab  7709                   -ja 0xa587b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a587b6;
    }
L_0x00a587ad:
    // 00a587ad  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00a587b0:
    // 00a587b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a587b2  75ed                   -jne 0xa587a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a587a1;
    }
    // 00a587b4  eb40                   -jmp 0xa587f6
    goto L_0x00a587f6;
L_0x00a587b6:
    // 00a587b6  b838dea500             -mov eax, 0xa5de38
    cpu.eax = 10870328 /*0xa5de38*/;
    // 00a587bb  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a587bd  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a587c3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a587c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a587c7  e8640a0000             -call 0xa59230
    cpu.esp -= 4;
    sub_a59230(app, cpu);
    if (cpu.terminate) return;
    // 00a587cc  8b153cdea500           -mov edx, dword ptr [0xa5de3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870332) /* 0xa5de3c */);
    // 00a587d2  890d98f0a500           -mov dword ptr [0xa5f098], ecx
    app->getMemory<x86::reg32>(x86::reg32(10875032) /* 0xa5f098 */) = cpu.ecx;
    // 00a587d8  39d1                   +cmp ecx, edx
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
    // 00a587da  7312                   -jae 0xa587ee
    if (!cpu.flags.cf)
    {
        goto L_0x00a587ee;
    }
    // 00a587dc  8b1d40dea500           -mov ebx, dword ptr [0xa5de40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */);
    // 00a587e2  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a587e5  39d8                   +cmp eax, ebx
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
    // 00a587e7  7605                   -jbe 0xa587ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a587ee;
    }
    // 00a587e9  a340dea500             -mov dword ptr [0xa5de40], eax
    app->getMemory<x86::reg32>(x86::reg32(10870336) /* 0xa5de40 */) = cpu.eax;
L_0x00a587ee:
    // 00a587ee  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a587f0  8825a0f0a500           -mov byte ptr [0xa5f0a0], ah
    app->getMemory<x86::reg8>(x86::reg32(10875040) /* 0xa5f0a0 */) = cpu.ah;
L_0x00a587f6:
    // 00a587f6  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a587fc:
    // 00a587fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a587fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a587fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a587ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58801(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58801  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a58804  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a58806  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a58808  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a5880b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a5880c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a5880c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a5880d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a5880e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a5880f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a58812  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a58814  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a58816  ff1580dca500           -call dword ptr [0xa5dc80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869888) /* 0xa5dc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5881c  b838dea500             -mov eax, 0xa5de38
    cpu.eax = 10870328 /*0xa5de38*/;
    // 00a58821  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a58823  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58825  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a58827  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 00a5882a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a5882c  e815000000             -call 0xa58846
    cpu.esp -= 4;
    sub_a58846(app, cpu);
    if (cpu.terminate) return;
    // 00a58831  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58833  0f85a8010000           -jne 0xa589e1
    if (!cpu.flags.zf)
    {
        return sub_a589e1(app, cpu);
    }
    // 00a58839  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a5883f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a58841  e9a3010000             -jmp 0xa589e9
    return sub_a589e9(app, cpu);
}

/* align: skip  */
void sub_a58846(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58846  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58847  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58848  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a58849  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a5884c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a5884d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a5884f  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 00a58852  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a58854  39d8                   +cmp eax, ebx
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
    // 00a58856  7307                   -jae 0xa5885f
    if (!cpu.flags.cf)
    {
        goto L_0x00a5885f;
    }
    // 00a58858  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a5885d  eb0a                   -jmp 0xa58869
    goto L_0x00a58869;
L_0x00a5885f:
    // 00a5885f  83f810                 +cmp eax, 0x10
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
    // 00a58862  7305                   -jae 0xa58869
    if (!cpu.flags.cf)
    {
        goto L_0x00a58869;
    }
    // 00a58864  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00a58869:
    // 00a58869  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00a5886c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a58870  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a58872  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a58875  39d0                   +cmp eax, edx
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
    // 00a58877  0f86fc000000           -jbe 0xa58979
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58979;
    }
    // 00a5887d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58881  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a58883  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00a58885:
    // 00a58885  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a58887  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a58889  83fdff                 +cmp ebp, -1
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
    // 00a5888c  750a                   -jne 0xa58898
    if (!cpu.flags.zf)
    {
        goto L_0x00a58898;
    }
    // 00a5888e  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00a58893  e940010000             -jmp 0xa589d8
    goto L_0x00a589d8;
L_0x00a58898:
    // 00a58898  f7c501000000           +test ebp, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & 1 /*0x1*/));
    // 00a5889e  0f85ce000000           -jne 0xa58972
    if (!cpu.flags.zf)
    {
        goto L_0x00a58972;
    }
    // 00a588a4  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a588a7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a588ab  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a588ae  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a588b0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a588b4  b838dea500             -mov eax, 0xa5de38
    cpu.eax = 10870328 /*0xa5de38*/;
    // 00a588b9  663b1424               +cmp dx, word ptr [esp]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a588bd  751d                   -jne 0xa588dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a588dc;
    }
    // 00a588bf  8b3538dea500           -mov esi, dword ptr [0xa5de38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a588c5  eb0f                   -jmp 0xa588d6
    goto L_0x00a588d6;
L_0x00a588c7:
    // 00a588c7  39fe                   +cmp esi, edi
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
    // 00a588c9  7708                   -ja 0xa588d3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a588d3;
    }
    // 00a588cb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a588cd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a588cf  39f8                   +cmp eax, edi
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
    // 00a588d1  7709                   -ja 0xa588dc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a588dc;
    }
L_0x00a588d3:
    // 00a588d3  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x00a588d6:
    // 00a588d6  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a588da  75eb                   -jne 0xa588c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a588c7;
    }
L_0x00a588dc:
    // 00a588dc  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a588df  39d3                   +cmp ebx, edx
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
    // 00a588e1  7506                   -jne 0xa588e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a588e9;
    }
    // 00a588e3  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a588e6  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a588e9:
    // 00a588e9  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a588eb  720b                   -jb 0xa588f8
    if (cpu.flags.cf)
    {
        goto L_0x00a588f8;
    }
    // 00a588ed  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a588ef  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a588f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a588f3  83f810                 +cmp eax, 0x10
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
    // 00a588f6  7334                   -jae 0xa5892c
    if (!cpu.flags.cf)
    {
        goto L_0x00a5892c;
    }
L_0x00a588f8:
    // 00a588f8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a588fc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a58900  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a58903  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58905  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a58909  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a5890c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58910  0128                   -add dword ptr [eax], ebp
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a58912  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a58915  48                     -dec eax
    (cpu.eax)--;
    // 00a58916  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a58918  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a5891b  8815a1f0a500           -mov byte ptr [0xa5f0a1], dl
    app->getMemory<x86::reg8>(x86::reg32(10875041) /* 0xa5f0a1 */) = cpu.dl;
    // 00a58921  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58923  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58925  7240                   -jb 0xa58967
    if (cpu.flags.cf)
    {
        goto L_0x00a58967;
    }
    // 00a58927  e9aa000000             -jmp 0xa589d6
    goto L_0x00a589d6;
L_0x00a5892c:
    // 00a5892c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a5892e  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a58930  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a58934  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a58937  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a5893b  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a5893e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a58942  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a58945  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a58949  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a5894c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58950  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a58952  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a58954  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a58956  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a58958  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00a5895a  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00a5895c  8825a1f0a500           -mov byte ptr [0xa5f0a1], ah
    app->getMemory<x86::reg8>(x86::reg32(10875041) /* 0xa5f0a1 */) = cpu.ah;
    // 00a58962  e971000000             -jmp 0xa589d8
    goto L_0x00a589d8;
L_0x00a58967:
    // 00a58967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58969  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a5896b  01eb                   +add ebx, ebp
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
    // 00a5896d  e913ffffff             -jmp 0xa58885
    goto L_0x00a58885;
L_0x00a58972:
    // 00a58972  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a58977  eb5f                   -jmp 0xa589d8
    goto L_0x00a589d8;
L_0x00a58979:
    // 00a58979  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a5897b  83fa10                 +cmp edx, 0x10
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
    // 00a5897e  7256                   -jb 0xa589d6
    if (cpu.flags.cf)
    {
        goto L_0x00a589d6;
    }
    // 00a58980  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58982  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58986  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a58989  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a5898c  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00a5898e  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a58991  b838dea500             -mov eax, 0xa5de38
    cpu.eax = 10870328 /*0xa5de38*/;
    // 00a58996  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a5899a  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a5899c  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a5899e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a589a1  6639da                 +cmp dx, bx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a589a4  751d                   -jne 0xa589c3
    if (!cpu.flags.zf)
    {
        goto L_0x00a589c3;
    }
    // 00a589a6  8b3538dea500           -mov esi, dword ptr [0xa5de38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10870328) /* 0xa5de38 */);
    // 00a589ac  eb0f                   -jmp 0xa589bd
    goto L_0x00a589bd;
L_0x00a589ae:
    // 00a589ae  39fe                   +cmp esi, edi
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
    // 00a589b0  7708                   -ja 0xa589ba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a589ba;
    }
    // 00a589b2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a589b4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a589b6  39f8                   +cmp eax, edi
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
    // 00a589b8  7709                   -ja 0xa589c3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a589c3;
    }
L_0x00a589ba:
    // 00a589ba  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x00a589bd:
    // 00a589bd  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a589c1  75eb                   -jne 0xa589ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a589ae;
    }
L_0x00a589c3:
    // 00a589c3  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a589c6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a589ca  47                     -inc edi
    (cpu.edi)++;
    // 00a589cb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a589ce  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a589d1  e827fdffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a589d6:
    // 00a589d6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a589d8:
    // 00a589d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a589da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a589dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a589e1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a589e1  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a589e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a589e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a589ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a589e9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a589e9;
    // 00a589e1  ff1588dca500           -call dword ptr [0xa5dc88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869896) /* 0xa5dc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a589e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x00a589e9:
    // 00a589e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a589ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a589ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a589f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a589f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a589f1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a589f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a589f6  e815fcffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a589fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a589fd  7407                   -je 0xa58a06
    if (cpu.flags.zf)
    {
        goto L_0x00a58a06;
    }
    // 00a589ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a58a01  e843c8ffff             -call 0xa55249
    cpu.esp -= 4;
    sub_a55249(app, cpu);
    if (cpu.terminate) return;
L_0x00a58a06:
    // 00a58a06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58a07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58a08(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58a08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58a09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58a0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58a0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58a0d  e8b5f2ffff             -call 0xa57cc7
    cpu.esp -= 4;
    sub_a57cc7(app, cpu);
    if (cpu.terminate) return;
    // 00a58a12  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a58a14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58a16  7410                   -je 0xa58a28
    if (cpu.flags.zf)
    {
        goto L_0x00a58a28;
    }
    // 00a58a18  8b1560dca500           -mov edx, dword ptr [0xa5dc60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a58a1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58a1f  2eff15b8b9a500         -call dword ptr cs:[0xa5b9b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860984) /* 0xa5b9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58a26  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a58a28:
    // 00a58a28  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a58a2a  750f                   -jne 0xa58a3b
    if (!cpu.flags.zf)
    {
        goto L_0x00a58a3b;
    }
    // 00a58a2c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a58a31  b8cccfa500             -mov eax, 0xa5cfcc
    cpu.eax = 10866636 /*0xa5cfcc*/;
    // 00a58a36  e8ebdaffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
L_0x00a58a3b:
    // 00a58a3b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58a3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58a3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58a3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58a41(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58a41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58a42  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58a43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58a44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58a45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58a46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a58a47  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58a4d  2eff1554b9a500         -call dword ptr cs:[0xa5b954]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860884) /* 0xa5b954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58a54  8b1d9cf0a500           -mov ebx, dword ptr [0xa5f09c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
    // 00a58a5a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a58a5c  eb07                   -jmp 0xa58a65
    goto L_0x00a58a65;
L_0x00a58a5e:
    // 00a58a5e  3b6b04                 +cmp ebp, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58a61  7406                   -je 0xa58a69
    if (cpu.flags.zf)
    {
        goto L_0x00a58a69;
    }
    // 00a58a63  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
L_0x00a58a65:
    // 00a58a65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a58a67  75f5                   -jne 0xa58a5e
    if (!cpu.flags.zf)
    {
        goto L_0x00a58a5e;
    }
L_0x00a58a69:
    // 00a58a69  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 00a58a6d  7425                   -je 0xa58a94
    if (cpu.flags.zf)
    {
        goto L_0x00a58a94;
    }
    // 00a58a6f  8b1544dea500           -mov edx, dword ptr [0xa5de44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a58a75  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a58a78  e866efffff             -call 0xa579e3
    cpu.esp -= 4;
    sub_a579e3(app, cpu);
    if (cpu.terminate) return;
    // 00a58a7d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a58a7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58a81  755e                   -jne 0xa58ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00a58ae1;
    }
    // 00a58a83  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a58a88  b8f1cfa500             -mov eax, 0xa5cff1
    cpu.eax = 10866673 /*0xa5cff1*/;
    // 00a58a8d  e894daffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
    // 00a58a92  eb4d                   -jmp 0xa58ae1
    goto L_0x00a58ae1;
L_0x00a58a94:
    // 00a58a94  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58a99  8b1544dea500           -mov edx, dword ptr [0xa5de44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a58a9f  e84cffffff             -call 0xa589f0
    cpu.esp -= 4;
    sub_a589f0(app, cpu);
    if (cpu.terminate) return;
    // 00a58aa4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a58aa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58aa8  750f                   -jne 0xa58ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00a58ab9;
    }
    // 00a58aaa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a58aaf  b819d0a500             -mov eax, 0xa5d019
    cpu.eax = 10866713 /*0xa5d019*/;
    // 00a58ab4  e86ddaffff             -call 0xa56526
    cpu.esp -= 4;
    sub_a56526(app, cpu);
    if (cpu.terminate) return;
L_0x00a58ab9:
    // 00a58ab9  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a58abc  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a58abe  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00a58ac4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a58ac5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a58ac7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a58ac9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58aca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58acc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a58acf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a58ad1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a58ad3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a58ad6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a58ad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58ad9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a58ada  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a58ae1:
    // 00a58ae1  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a58ae4  a144dea500             -mov eax, dword ptr [0xa5de44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a58ae9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a58aea  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a58aee  8b3560dca500           -mov esi, dword ptr [0xa5dc60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10869856) /* 0xa5dc60 */);
    // 00a58af4  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00a58af8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58af9  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a58aff  2eff15bcb9a500         -call dword ptr cs:[0xa5b9bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860988) /* 0xa5b9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b06  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b0c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a58b0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58b15(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58b15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58b16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58b17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58b18  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a58b1a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a58b1c  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b22  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a58b27  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00a58b2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58b2e  e8bdfeffff             -call 0xa589f0
    cpu.esp -= 4;
    sub_a589f0(app, cpu);
    if (cpu.terminate) return;
    // 00a58b33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58b35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58b37  742f                   -je 0xa58b68
    if (cpu.flags.zf)
    {
        goto L_0x00a58b68;
    }
    // 00a58b39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58b3b  e895090000             -call 0xa594d5
    cpu.esp -= 4;
    sub_a594d5(app, cpu);
    if (cpu.terminate) return;
    // 00a58b40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58b42  7409                   -je 0xa58b4d
    if (cpu.flags.zf)
    {
        goto L_0x00a58b4d;
    }
    // 00a58b44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58b46  e8b2fbffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a58b4b  eb1b                   -jmp 0xa58b68
    goto L_0x00a58b68;
L_0x00a58b4d:
    // 00a58b4d  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a58b50  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a58b53  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00a58b56  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a58b59  a19cf0a500             -mov eax, dword ptr [0xa5f09c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
    // 00a58b5e  89159cf0a500           -mov dword ptr [0xa5f09c], edx
    app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */) = cpu.edx;
    // 00a58b64  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a58b66  eb02                   -jmp 0xa58b6a
    goto L_0x00a58b6a;
L_0x00a58b68:
    // 00a58b68  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a58b6a:
    // 00a58b6a  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58b72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58b75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58b76(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58b76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58b77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58b78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58b79  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58b7b  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b81  bb9cf0a500             -mov ebx, 0xa5f09c
    cpu.ebx = 10875036 /*0xa5f09c*/;
    // 00a58b86  8b159cf0a500           -mov edx, dword ptr [0xa5f09c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
    // 00a58b8c  eb24                   -jmp 0xa58bb2
    goto L_0x00a58bb2;
L_0x00a58b8e:
    // 00a58b8e  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58b91  751b                   -jne 0xa58bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a58bae;
    }
    // 00a58b93  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00a58b97  7408                   -je 0xa58ba1
    if (cpu.flags.zf)
    {
        goto L_0x00a58ba1;
    }
    // 00a58b99  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a58b9c  e85cfbffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a58ba1:
    // 00a58ba1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a58ba3  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a58ba5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58ba7  e851fbffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a58bac  eb08                   -jmp 0xa58bb6
    goto L_0x00a58bb6;
L_0x00a58bae:
    // 00a58bae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a58bb0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x00a58bb2:
    // 00a58bb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a58bb4  75d8                   -jne 0xa58b8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a58b8e;
    }
L_0x00a58bb6:
    // 00a58bb6  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58bbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58bbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a58bbc;
    // 00a58b76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58b77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58b78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58b79  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58b7b  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58b81  bb9cf0a500             -mov ebx, 0xa5f09c
    cpu.ebx = 10875036 /*0xa5f09c*/;
    // 00a58b86  8b159cf0a500           -mov edx, dword ptr [0xa5f09c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
    // 00a58b8c  eb24                   -jmp 0xa58bb2
    goto L_0x00a58bb2;
L_0x00a58b8e:
    // 00a58b8e  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58b91  751b                   -jne 0xa58bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a58bae;
    }
    // 00a58b93  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00a58b97  7408                   -je 0xa58ba1
    if (cpu.flags.zf)
    {
        goto L_0x00a58ba1;
    }
    // 00a58b99  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a58b9c  e85cfbffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a58ba1:
    // 00a58ba1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a58ba3  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a58ba5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58ba7  e851fbffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a58bac  eb08                   -jmp 0xa58bb6
    goto L_0x00a58bb6;
L_0x00a58bae:
    // 00a58bae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a58bb0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x00a58bb2:
    // 00a58bb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a58bb4  75d8                   -jne 0xa58b8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a58b8e;
    }
L_0x00a58bb6:
    // 00a58bb6  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a58bbc:
    // 00a58bbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58bbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58bc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58bc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58bc1  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58bc7  a19cf0a500             -mov eax, dword ptr [0xa5f09c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
L_0x00a58bcc:
    // 00a58bcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58bce  740b                   -je 0xa58bdb
    if (cpu.flags.zf)
    {
        goto L_0x00a58bdb;
    }
    // 00a58bd0  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a58bd3  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00a58bd7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a58bd9  ebf1                   -jmp 0xa58bcc
    goto L_0x00a58bcc;
L_0x00a58bdb:
    // 00a58bdb  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58be1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58be2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58be3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58be3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58be4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58be5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58be6  8b159cf0a500           -mov edx, dword ptr [0xa5f09c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875036) /* 0xa5f09c */);
L_0x00a58bec:
    // 00a58bec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a58bee  74cc                   -je 0xa58bbc
    if (cpu.flags.zf)
    {
        return sub_a58bbc(app, cpu);
    }
    // 00a58bf0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a58bf3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a58bf5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a58bf7  7408                   -je 0xa58c01
    if (cpu.flags.zf)
    {
        goto L_0x00a58c01;
    }
    // 00a58bf9  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a58bfc  e8fcfaffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a58c01:
    // 00a58c01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58c03  e8f5faffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
    // 00a58c08  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a58c0a  ebe0                   -jmp 0xa58bec
    goto L_0x00a58bec;
}

/* align: skip  */
void sub_a58c0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58c0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58c0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58c0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58c10  ff1590dca500           -call dword ptr [0xa5dc90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869904) /* 0xa5dc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58c16  8b1544dea500           -mov edx, dword ptr [0xa5de44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */);
    // 00a58c1c  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a58c1f  a344dea500             -mov dword ptr [0xa5de44], eax
    app->getMemory<x86::reg32>(x86::reg32(10870340) /* 0xa5de44 */) = cpu.eax;
    // 00a58c24  e897ffffff             -call 0xa58bc0
    cpu.esp -= 4;
    sub_a58bc0(app, cpu);
    if (cpu.terminate) return;
    // 00a58c29  ff1594dca500           -call dword ptr [0xa5dc94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869908) /* 0xa5dc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58c2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58c31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58c32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58c34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58c34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58c35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58c36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58c37  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58c39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58c3b  741b                   -je 0xa58c58
    if (cpu.flags.zf)
    {
        goto L_0x00a58c58;
    }
    // 00a58c3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a58c3f  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00a58c46  e8cff3ffff             -call 0xa5801a
    cpu.esp -= 4;
    sub_a5801a(app, cpu);
    if (cpu.terminate) return;
    // 00a58c4b  2eff1554b9a500         -call dword ptr cs:[0xa5b954]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860884) /* 0xa5b954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58c52  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00a58c58:
    // 00a58c58  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58c59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58c5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58c5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58c5c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58c5c  e982ffffff             -jmp 0xa58be3
    return sub_a58be3(app, cpu);
}

/* align: skip  */
void sub_a58c61(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58c61  e9aaf9ffff             -jmp 0xa58610
    return sub_a58610(app, cpu);
}

/* align: skip  */
void sub_a58c66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58c66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58c67  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58c68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58c69  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58c6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58c6b  833d88f0a50000         +cmp dword ptr [0xa5f088], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58c72  0f85a5000000           -jne 0xa58d1d
    if (!cpu.flags.zf)
    {
        goto L_0x00a58d1d;
    }
    // 00a58c78  8b3d19dba500           -mov edi, dword ptr [0xa5db19]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10869529) /* 0xa5db19 */);
    // 00a58c7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58c80  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a58c82  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a58c84:
    // 00a58c84  3a10                   +cmp dl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a58c86  7412                   -je 0xa58c9a
    if (cpu.flags.zf)
    {
        goto L_0x00a58c9a;
    }
L_0x00a58c88:
    // 00a58c88  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a58c8a  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a58c8d  38f2                   +cmp dl, dh
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
    // 00a58c8f  7404                   -je 0xa58c95
    if (cpu.flags.zf)
    {
        goto L_0x00a58c95;
    }
    // 00a58c91  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58c93  ebf3                   -jmp 0xa58c88
    goto L_0x00a58c88;
L_0x00a58c95:
    // 00a58c95  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a58c96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58c98  ebea                   -jmp 0xa58c84
    goto L_0x00a58c84;
L_0x00a58c9a:
    // 00a58c9a  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a58c9c  7505                   -jne 0xa58ca3
    if (!cpu.flags.zf)
    {
        goto L_0x00a58ca3;
    }
    // 00a58c9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a58ca3:
    // 00a58ca3  e868f9ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a58ca8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58caa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58cac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58cae  7468                   -je 0xa58d18
    if (cpu.flags.zf)
    {
        goto L_0x00a58d18;
    }
    // 00a58cb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58cb2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a58cb5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a58cb8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58cba  e851f9ffff             -call 0xa58610
    cpu.esp -= 4;
    sub_a58610(app, cpu);
    if (cpu.terminate) return;
    // 00a58cbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58cc1  744e                   -je 0xa58d11
    if (cpu.flags.zf)
    {
        goto L_0x00a58d11;
    }
    // 00a58cc3  a388f0a500             -mov dword ptr [0xa5f088], eax
    app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */) = cpu.eax;
    // 00a58cc8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a58cca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58ccc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a58cce:
    // 00a58cce  803800                 +cmp byte ptr [eax], 0
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
    // 00a58cd1  7419                   -je 0xa58cec
    if (cpu.flags.zf)
    {
        goto L_0x00a58cec;
    }
    // 00a58cd3  8b1588f0a500           -mov edx, dword ptr [0xa5f088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a58cd9  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00a58cdc:
    // 00a58cdc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a58cde  40                     -inc eax
    (cpu.eax)++;
    // 00a58cdf  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00a58ce1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a58ce2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a58ce4  75f6                   -jne 0xa58cdc
    if (!cpu.flags.zf)
    {
        goto L_0x00a58cdc;
    }
    // 00a58ce6  83c104                 +add ecx, 4
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
    // 00a58ce9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a58cea  ebe2                   -jmp 0xa58cce
    goto L_0x00a58cce;
L_0x00a58cec:
    // 00a58cec  8b1588f0a500           -mov edx, dword ptr [0xa5f088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10875016) /* 0xa5f088 */);
    // 00a58cf2  c7041100000000         -mov dword ptr [ecx + edx], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 00a58cf9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a58cfc  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a58cfe  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a58d00  891584f0a500           -mov dword ptr [0xa5f084], edx
    app->getMemory<x86::reg32>(x86::reg32(10875012) /* 0xa5f084 */) = cpu.edx;
    // 00a58d06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58d08  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a58d0a  e83ac5ffff             -call 0xa55249
    cpu.esp -= 4;
    sub_a55249(app, cpu);
    if (cpu.terminate) return;
    // 00a58d0f  eb07                   -jmp 0xa58d18
    goto L_0x00a58d18;
L_0x00a58d11:
    // 00a58d11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58d13  e8e5f9ffff             -call 0xa586fd
    cpu.esp -= 4;
    sub_a586fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a58d18:
    // 00a58d18  e8fe070000             -call 0xa5951b
    cpu.esp -= 4;
    sub_a5951b(app, cpu);
    if (cpu.terminate) return;
L_0x00a58d1d:
    // 00a58d1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d1f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58d23(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58d23  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58d24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a58d26:
    // 00a58d26  66833800               +cmp word ptr [eax], 0
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
    // 00a58d2a  7404                   -je 0xa58d30
    if (cpu.flags.zf)
    {
        goto L_0x00a58d30;
    }
    // 00a58d2c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a58d2d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a58d2e  ebf6                   -jmp 0xa58d26
    goto L_0x00a58d26;
L_0x00a58d30:
    // 00a58d30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a58d32  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a58d34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58d36(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58d36  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58d37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a58d38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58d39  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a58d3b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a58d3d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a58d3f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a58d40  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a58d42  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a58d44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a58d45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a58d47  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a58d4a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a58d4c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a58d4e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a58d51  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a58d53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d54  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a58d55  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a58d57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58d5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58d5b  66833801               +cmp word ptr [eax], 1
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
    // 00a58d5f  751c                   -jne 0xa58d7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a58d7d;
    }
    // 00a58d61  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a58d65  7416                   -je 0xa58d7d
    if (cpu.flags.zf)
    {
        goto L_0x00a58d7d;
    }
    // 00a58d67  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00a58d6b  663d1000               +cmp ax, 0x10
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
    // 00a58d6f  7206                   -jb 0xa58d77
    if (cpu.flags.cf)
    {
        goto L_0x00a58d77;
    }
    // 00a58d71  663d1200               +cmp ax, 0x12
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
    // 00a58d75  7606                   -jbe 0xa58d7d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58d7d;
    }
L_0x00a58d77:
    // 00a58d77  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58d7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58d7d:
    // 00a58d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58d7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58d80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58d80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58d81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58d82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58d84  ff1568dca500           -call dword ptr [0xa5dc68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869864) /* 0xa5dc68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58d8a  833d48dea500ff         +cmp dword ptr [0xa5de48], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10870344) /* 0xa5de48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58d91  7523                   -jne 0xa58db6
    if (!cpu.flags.zf)
    {
        goto L_0x00a58db6;
    }
    // 00a58d93  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a58d95  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a58d9a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a58d9c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a58d9e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a58da0  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00a58da5  6844d0a500             -push 0xa5d044
    app->getMemory<x86::reg32>(cpu.esp-4) = 10866756 /*0xa5d044*/;
    cpu.esp -= 4;
    // 00a58daa  2eff152cb9a500         -call dword ptr cs:[0xa5b92c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860844) /* 0xa5b92c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58db1  a348dea500             -mov dword ptr [0xa5de48], eax
    app->getMemory<x86::reg32>(x86::reg32(10870344) /* 0xa5de48 */) = cpu.eax;
L_0x00a58db6:
    // 00a58db6  833d4cdea500ff         +cmp dword ptr [0xa5de4c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10870348) /* 0xa5de4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a58dbd  7523                   -jne 0xa58de2
    if (!cpu.flags.zf)
    {
        goto L_0x00a58de2;
    }
    // 00a58dbf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a58dc1  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a58dc6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a58dc8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a58dca  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a58dcc  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00a58dd1  684bd0a500             -push 0xa5d04b
    app->getMemory<x86::reg32>(cpu.esp-4) = 10866763 /*0xa5d04b*/;
    cpu.esp -= 4;
    // 00a58dd6  2eff152cb9a500         -call dword ptr cs:[0xa5b92c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860844) /* 0xa5b92c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58ddd  a34cdea500             -mov dword ptr [0xa5de4c], eax
    app->getMemory<x86::reg32>(x86::reg32(10870348) /* 0xa5de4c */) = cpu.eax;
L_0x00a58de2:
    // 00a58de2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58de4  ff156cdca500           -call dword ptr [0xa5dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869868) /* 0xa5dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58dea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58deb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58ded(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58ded  e88effffff             -call 0xa58d80
    cpu.esp -= 4;
    sub_a58d80(app, cpu);
    if (cpu.terminate) return;
    // 00a58df2  a148dea500             -mov eax, dword ptr [0xa5de48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870344) /* 0xa5de48 */);
    // 00a58df7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58df8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58df8  e883ffffff             -call 0xa58d80
    cpu.esp -= 4;
    sub_a58d80(app, cpu);
    if (cpu.terminate) return;
    // 00a58dfd  a14cdea500             -mov eax, dword ptr [0xa5de4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870348) /* 0xa5de4c */);
    // 00a58e02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e03(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e03  dbe2                   -fnclex 
    /*nothing*/;
    // 00a58e05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e06(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e06  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58e07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58e08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58e0a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a58e0c  83f807                 +cmp eax, 7
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
    // 00a58e0f  7405                   -je 0xa58e16
    if (cpu.flags.zf)
    {
        goto L_0x00a58e16;
    }
    // 00a58e11  83f804                 +cmp eax, 4
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
    // 00a58e14  7513                   -jne 0xa58e29
    if (!cpu.flags.zf)
    {
        goto L_0x00a58e29;
    }
L_0x00a58e16:
    // 00a58e16  8b14dd50dea500         -mov edx, dword ptr [ebx*8 + 0xa5de50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10870352) /* 0xa5de50 */ + cpu.ebx * 8);
    // 00a58e1d  890cdd50dea500         -mov dword ptr [ebx*8 + 0xa5de50], ecx
    app->getMemory<x86::reg32>(x86::reg32(10870352) /* 0xa5de50 */ + cpu.ebx * 8) = cpu.ecx;
    // 00a58e24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58e26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58e29:
    // 00a58e29  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58e2f  8b54d858               -mov edx, dword ptr [eax + ebx*8 + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8);
    // 00a58e33  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58e39  894cd858               -mov dword ptr [eax + ebx*8 + 0x58], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8) = cpu.ecx;
    // 00a58e3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58e3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e42(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58e43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58e45  83f807                 +cmp eax, 7
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
    // 00a58e48  7405                   -je 0xa58e4f
    if (cpu.flags.zf)
    {
        goto L_0x00a58e4f;
    }
    // 00a58e4a  83f804                 +cmp eax, 4
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
    // 00a58e4d  7509                   -jne 0xa58e58
    if (!cpu.flags.zf)
    {
        goto L_0x00a58e58;
    }
L_0x00a58e4f:
    // 00a58e4f  8b04d550dea500         -mov eax, dword ptr [edx*8 + 0xa5de50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870352) /* 0xa5de50 */ + cpu.edx * 8);
    // 00a58e56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58e58:
    // 00a58e58  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58e5e  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00a58e62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58e65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58e67  83f807                 +cmp eax, 7
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
    // 00a58e6a  7405                   -je 0xa58e71
    if (cpu.flags.zf)
    {
        goto L_0x00a58e71;
    }
    // 00a58e6c  83f804                 +cmp eax, 4
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
    // 00a58e6f  7509                   -jne 0xa58e7a
    if (!cpu.flags.zf)
    {
        goto L_0x00a58e7a;
    }
L_0x00a58e71:
    // 00a58e71  8b04d554dea500         -mov eax, dword ptr [edx*8 + 0xa5de54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10870356) /* 0xa5de54 */ + cpu.edx * 8);
    // 00a58e78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58e7a:
    // 00a58e7a  ff1564dca500           -call dword ptr [0xa5dc64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10869860) /* 0xa5dc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58e80  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00a58e84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e86(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58e87  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58e89  e8d6ffffff             -call 0xa58e64
    cpu.esp -= 4;
    sub_a58e64(app, cpu);
    if (cpu.terminate) return;
    // 00a58e8e  39c2                   +cmp edx, eax
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
    // 00a58e90  7509                   -jne 0xa58e9b
    if (!cpu.flags.zf)
    {
        goto L_0x00a58e9b;
    }
    // 00a58e92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a58e94  e8a9ffffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58e99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58e9b:
    // 00a58e9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58e9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58e9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58e9f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58e9f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a58ea3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58ea5  760a                   -jbe 0xa58eb1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a58eb1;
    }
    // 00a58ea7  83f801                 +cmp eax, 1
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
    // 00a58eaa  7424                   -je 0xa58ed0
    if (cpu.flags.zf)
    {
        goto L_0x00a58ed0;
    }
    // 00a58eac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58eae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a58eb1:
    // 00a58eb1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a58eb6  e887ffffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58ebb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58ebd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58ebf  7503                   -jne 0xa58ec4
    if (!cpu.flags.zf)
    {
        goto L_0x00a58ec4;
    }
    // 00a58ec1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a58ec4:
    // 00a58ec4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x00a58ec9:
    // 00a58ec9  e8d5000000             -call 0xa58fa3
    cpu.esp -= 4;
    sub_a58fa3(app, cpu);
    if (cpu.terminate) return;
    // 00a58ece  eb1f                   -jmp 0xa58eef
    goto L_0x00a58eef;
L_0x00a58ed0:
    // 00a58ed0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a58ed5  e868ffffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58eda  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58edc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58ede  7503                   -jne 0xa58ee3
    if (!cpu.flags.zf)
    {
        goto L_0x00a58ee3;
    }
    // 00a58ee0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a58ee3:
    // 00a58ee3  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a58ee8  ebdf                   -jmp 0xa58ec9
    goto L_0x00a58ec9;
L_0x00a58eea:
    // 00a58eea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58eec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a58eef:
    // 00a58eef  83fa02                 +cmp edx, 2
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
    // 00a58ef2  74f6                   -je 0xa58eea
    if (cpu.flags.zf)
    {
        goto L_0x00a58eea;
    }
    // 00a58ef4  83fa03                 +cmp edx, 3
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
    // 00a58ef7  74f1                   -je 0xa58eea
    if (cpu.flags.zf)
    {
        goto L_0x00a58eea;
    }
    // 00a58ef9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58efe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a58f01(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58f01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58f02  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a58f07  e836ffffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58f0c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a58f0e  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a58f13  e82affffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58f18  83fa02                 +cmp edx, 2
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
    // 00a58f1b  7405                   -je 0xa58f22
    if (cpu.flags.zf)
    {
        goto L_0x00a58f22;
    }
    // 00a58f1d  83fa03                 +cmp edx, 3
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
    // 00a58f20  750a                   -jne 0xa58f2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a58f2c;
    }
L_0x00a58f22:
    // 00a58f22  83f802                 +cmp eax, 2
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
    // 00a58f25  740c                   -je 0xa58f33
    if (cpu.flags.zf)
    {
        goto L_0x00a58f33;
    }
    // 00a58f27  83f803                 +cmp eax, 3
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
    // 00a58f2a  7407                   -je 0xa58f33
    if (cpu.flags.zf)
    {
        goto L_0x00a58f33;
    }
L_0x00a58f2c:
    // 00a58f2c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58f31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a58f33:
    // 00a58f33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58f35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58f37(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58f37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58f38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58f39  803db8dea50000         +cmp byte ptr [0xa5deb8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a58f40  7519                   -jne 0xa58f5b
    if (!cpu.flags.zf)
    {
        goto L_0x00a58f5b;
    }
    // 00a58f42  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a58f44  689f8ea500             -push 0xa58e9f
    app->getMemory<x86::reg32>(cpu.esp-4) = 10849951 /*0xa58e9f*/;
    cpu.esp -= 4;
    // 00a58f49  2eff1594b9a500         -call dword ptr cs:[0xa5b994]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860948) /* 0xa5b994 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58f50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58f52  7407                   -je 0xa58f5b
    if (cpu.flags.zf)
    {
        goto L_0x00a58f5b;
    }
    // 00a58f54  c605b8dea50001         -mov byte ptr [0xa5deb8], 1
    app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */) = 1 /*0x1*/;
L_0x00a58f5b:
    // 00a58f5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58f5d  a0b8dea500             -mov al, byte ptr [0xa5deb8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */);
    // 00a58f62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58f65(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58f65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58f66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58f67  803db8dea50000         +cmp byte ptr [0xa5deb8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a58f6e  741a                   -je 0xa58f8a
    if (cpu.flags.zf)
    {
        goto L_0x00a58f8a;
    }
    // 00a58f70  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a58f72  689f8ea500             -push 0xa58e9f
    app->getMemory<x86::reg32>(cpu.esp-4) = 10849951 /*0xa58e9f*/;
    cpu.esp -= 4;
    // 00a58f77  2eff1594b9a500         -call dword ptr cs:[0xa5b994]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10860948) /* 0xa5b994 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a58f7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58f80  7408                   -je 0xa58f8a
    if (cpu.flags.zf)
    {
        goto L_0x00a58f8a;
    }
    // 00a58f82  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a58f84  8815b8dea500           -mov byte ptr [0xa5deb8], dl
    app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */) = cpu.dl;
L_0x00a58f8a:
    // 00a58f8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a58f8c  a0b8dea500             -mov al, byte ptr [0xa5deb8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10870456) /* 0xa5deb8 */);
    // 00a58f91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a58f93  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a58f96  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a58f9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58f9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58f9e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58fa3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58fa4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58fa5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58fa8  e895feffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58faf  83fb02                 +cmp ebx, 2
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
    // 00a58fb2  0f82db000000           -jb 0xa59093
    if (cpu.flags.cf)
    {
        return sub_a59093(app, cpu);
    }
    // 00a58fb8  0f86df000000           -jbe 0xa5909d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a5909d(app, cpu);
    }
    // 00a58fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a58fc1  0f86ec000000           -jbe 0xa590b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a590b3(app, cpu);
    }
    // 00a58fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a58fcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58fc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a58fc7;
    // 00a58f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a58fa3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58fa4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58fa5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58fa8  e895feffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58faf  83fb02                 +cmp ebx, 2
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
    // 00a58fb2  0f82db000000           -jb 0xa59093
    if (cpu.flags.cf)
    {
        return sub_a59093(app, cpu);
    }
    // 00a58fb8  0f86df000000           -jbe 0xa5909d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a5909d(app, cpu);
    }
    // 00a58fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a58fc1  0f86ec000000           -jbe 0xa590b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a590b3(app, cpu);
    }
L_entry_0x00a58fc7:
    // 00a58fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a58fcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58fa3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a58fa3;
    // 00a58f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_entry_0x00a58fa3:
    // 00a58fa3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58fa4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58fa5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58fa8  e895feffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58faf  83fb02                 +cmp ebx, 2
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
    // 00a58fb2  0f82db000000           -jb 0xa59093
    if (cpu.flags.cf)
    {
        return sub_a59093(app, cpu);
    }
    // 00a58fb8  0f86df000000           -jbe 0xa5909d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a5909d(app, cpu);
    }
    // 00a58fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a58fc1  0f86ec000000           -jbe 0xa590b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a590b3(app, cpu);
    }
    // 00a58fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a58fcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a58fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a58fd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a58fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a58fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a58fd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a58fd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a58fd5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a58fda  e863feffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a58fdf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a58fe1  83f801                 +cmp eax, 1
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
    // 00a58fe4  7425                   -je 0xa5900b
    if (cpu.flags.zf)
    {
        goto L_0x00a5900b;
    }
    // 00a58fe6  83f802                 +cmp eax, 2
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
    // 00a58fe9  7420                   -je 0xa5900b
    if (cpu.flags.zf)
    {
        goto L_0x00a5900b;
    }
    // 00a58feb  83f803                 +cmp eax, 3
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
    // 00a58fee  741b                   -je 0xa5900b
    if (cpu.flags.zf)
    {
        goto L_0x00a5900b;
    }
    // 00a58ff0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a58ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a58ff7  e80afeffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a58ffc  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a59001  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a59003  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a59005  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59007  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59008  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59009  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a5900a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a5900b:
    // 00a5900b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a59010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59011  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59012  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59014(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59014  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a59015  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a59016  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a59017  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a59019  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a5901b  83f801                 +cmp eax, 1
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
    // 00a5901e  7c05                   -jl 0xa59025
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a59025;
    }
    // 00a59020  83f80c                 +cmp eax, 0xc
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
    // 00a59023  7e13                   -jle 0xa59038
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a59038;
    }
L_0x00a59025:
    // 00a59025  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a5902a  e804e9ffff             -call 0xa57933
    cpu.esp -= 4;
    sub_a57933(app, cpu);
    if (cpu.terminate) return;
    // 00a5902f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a59034  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59035  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59036  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59037  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a59038:
    // 00a59038  c7050cdfa5009e8fa500   -mov dword ptr [0xa5df0c], 0xa58f9e
    app->getMemory<x86::reg32>(x86::reg32(10870540) /* 0xa5df0c */) = 10850206 /*0xa58f9e*/;
    // 00a59042  83f902                 +cmp ecx, 2
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
    // 00a59045  741f                   -je 0xa59066
    if (cpu.flags.zf)
    {
        goto L_0x00a59066;
    }
    // 00a59047  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a5904a  741a                   -je 0xa59066
    if (cpu.flags.zf)
    {
        goto L_0x00a59066;
    }
    // 00a5904c  e813feffff             -call 0xa58e64
    cpu.esp -= 4;
    sub_a58e64(app, cpu);
    if (cpu.terminate) return;
    // 00a59051  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a59053  7411                   -je 0xa59066
    if (cpu.flags.zf)
    {
        goto L_0x00a59066;
    }
    // 00a59055  83fb02                 +cmp ebx, 2
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
    // 00a59058  750c                   -jne 0xa59066
    if (!cpu.flags.zf)
    {
        goto L_0x00a59066;
    }
    // 00a5905a  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00a5905f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a59061  e8ed050000             -call 0xa59653
    cpu.esp -= 4;
    sub_a59653(app, cpu);
    if (cpu.terminate) return;
L_0x00a59066:
    // 00a59066  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59068  e8d5fdffff             -call 0xa58e42
    cpu.esp -= 4;
    sub_a58e42(app, cpu);
    if (cpu.terminate) return;
    // 00a5906d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a5906f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a59071  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a59073  e88efdffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a59078  e884feffff             -call 0xa58f01
    cpu.esp -= 4;
    sub_a58f01(app, cpu);
    if (cpu.terminate) return;
    // 00a5907d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a5907f  7407                   -je 0xa59088
    if (cpu.flags.zf)
    {
        goto L_0x00a59088;
    }
    // 00a59081  e8b1feffff             -call 0xa58f37
    cpu.esp -= 4;
    sub_a58f37(app, cpu);
    if (cpu.terminate) return;
    // 00a59086  eb05                   -jmp 0xa5908d
    goto L_0x00a5908d;
L_0x00a59088:
    // 00a59088  e8d8feffff             -call 0xa58f65
    cpu.esp -= 4;
    sub_a58f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a5908d:
    // 00a5908d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a5908f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59090  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59091  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a59092  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a59093(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a59093  83fb01                 +cmp ebx, 1
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
    // 00a59096  7411                   -je 0xa590a9
    if (cpu.flags.zf)
    {
        goto L_0x00a590a9;
    }
    // 00a59098  e92affffff             -jmp 0xa58fc7
    return sub_a58fc7(app, cpu);
    // 00a5909d  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a590a2  e829ffffff             -call 0xa58fd0
    cpu.esp -= 4;
    sub_a58fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a590a7  eb37                   -jmp 0xa590e0
    goto L_0x00a590e0;
L_0x00a590a9:
    // 00a590a9  83f802                 +cmp eax, 2
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
    // 00a590ac  7505                   -jne 0xa590b3
    if (!cpu.flags.zf)
    {
        goto L_0x00a590b3;
    }
    // 00a590ae  e88e050000             -call 0xa59641
    cpu.esp -= 4;
    sub_a59641(app, cpu);
    if (cpu.terminate) return;
L_0x00a590b3:
    // 00a590b3  83f901                 +cmp ecx, 1
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
    // 00a590b6  741a                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590b8  83f902                 +cmp ecx, 2
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
    // 00a590bb  7415                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590bd  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a590c0  7410                   -je 0xa590d2
    if (cpu.flags.zf)
    {
        goto L_0x00a590d2;
    }
    // 00a590c2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a590c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590c9  e838fdffff             -call 0xa58e06
    cpu.esp -= 4;
    sub_a58e06(app, cpu);
    if (cpu.terminate) return;
    // 00a590ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a590d0  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a590d2:
    // 00a590d2  e82afeffff             -call 0xa58f01
    cpu.esp -= 4;
    sub_a58f01(app, cpu);
    if (cpu.terminate) return;
    // 00a590d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a590d9  7505                   -jne 0xa590e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a590e0;
    }
    // 00a590db  e885feffff             -call 0xa58f65
    cpu.esp -= 4;
    sub_a58f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a590e0:
    // 00a590e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a590e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a590e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
