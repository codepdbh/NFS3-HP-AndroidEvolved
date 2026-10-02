#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4fd4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004fd4e0:
    // 004fd4e0  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fd4e3  66a1ac4f9f00           -mov ax, word ptr [0x9f4fac]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10440620) /* 0x9f4fac */);
    // 004fd4e9  668942fe               -mov word ptr [edx - 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004fd4ed  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd4ee  75f0                   -jne 0x4fd4e0
    if (!cpu.flags.zf)
    {
        goto L_0x004fd4e0;
    }
    // 004fd4f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4fd500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004fd500:
    // 004fd500  66a1ac4f9f00           -mov ax, word ptr [0x9f4fac]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10440620) /* 0x9f4fac */);
    // 004fd506  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004fd509  a1ac4f9f00             -mov eax, dword ptr [0x9f4fac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440620) /* 0x9f4fac */);
    // 004fd50e  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004fd511  c1e810                 +shr eax, 0x10
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
    // 004fd514  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004fd517  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd518  75e6                   -jne 0x4fd500
    if (!cpu.flags.zf)
    {
        goto L_0x004fd500;
    }
    // 004fd51a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4fd520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd520  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fd522  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fd524  8b1dac4f9f00           -mov ebx, dword ptr [0x9f4fac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10440620) /* 0x9f4fac */);
    // 004fd52a  c1e202                 +shl edx, 2
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
    // 004fd52d  e9ef31feff             -jmp 0x4e0721
    return sub_4e0721(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fd540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd541  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd542  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fd543  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004fd546  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fd548  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fd54a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004fd54e  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004fd554  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fd557  0f8381000000           -jae 0x4fd5de
    if (!cpu.flags.cf)
    {
        goto L_0x004fd5de;
    }
    // 004fd55d  80fa04                 +cmp dl, 4
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
    // 004fd560  750a                   -jne 0x4fd56c
    if (!cpu.flags.zf)
    {
        goto L_0x004fd56c;
    }
    // 004fd562  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004fd565  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fd567  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x004fd56a:
    // 004fd56a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x004fd56c:
    // 004fd56c  a3ac4f9f00             -mov dword ptr [0x9f4fac], eax
    app->getMemory<x86::reg32>(x86::reg32(10440620) /* 0x9f4fac */) = cpu.eax;
    // 004fd571  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fd573  8a2510505600           -mov ah, byte ptr [0x565010]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004fd579  8915cc765600           -mov dword ptr [0x5676cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5666508) /* 0x5676cc */) = cpu.edx;
    // 004fd57f  80fc10                 +cmp ah, 0x10
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
    // 004fd582  7513                   -jne 0x4fd597
    if (!cpu.flags.zf)
    {
        goto L_0x004fd597;
    }
    // 004fd584  833db076560000         +cmp dword ptr [0x5676b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666480) /* 0x5676b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fd58b  740a                   -je 0x4fd597
    if (cpu.flags.zf)
    {
        goto L_0x004fd597;
    }
    // 004fd58d  c705cc765600e0d44f00   -mov dword ptr [0x5676cc], 0x4fd4e0
    app->getMemory<x86::reg32>(x86::reg32(5666508) /* 0x5676cc */) = 5231840 /*0x4fd4e0*/;
L_0x004fd597:
    // 004fd597  66895c2404             -mov word ptr [esp + 4], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 004fd59c  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 004fd5a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fd5a3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004fd5a5  b9b4765600             -mov ecx, 0x5676b4
    cpu.ecx = 5666484 /*0x5676b4*/;
    // 004fd5aa  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 004fd5ad  a011505600             -mov al, byte ptr [0x565011]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */);
    // 004fd5b2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004fd5b5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004fd5ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fd5bc  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004fd5be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fd5c0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004fd5c2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fd5c5  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004fd5cb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fd5cd  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004fd5d0  e8dbda0000             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 004fd5d5  83c414                 +add esp, 0x14
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
    // 004fd5d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd5d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd5da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd5db  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004fd5de:
    // 004fd5de  7716                   -ja 0x4fd5f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fd5f6;
    }
    // 004fd5e0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004fd5e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fd5e7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004fd5ea  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004fd5ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fd5ee  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fd5f1  e974ffffff             -jmp 0x4fd56a
    goto L_0x004fd56a;
L_0x004fd5f6:
    // 004fd5f6  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004fd5f9  0f826dffffff           -jb 0x4fd56c
    if (cpu.flags.cf)
    {
        goto L_0x004fd56c;
    }
    // 004fd5ff  770f                   -ja 0x4fd610
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fd610;
    }
L_0x004fd601:
    // 004fd601  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004fd606  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fd608  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fd60b  e95affffff             -jmp 0x4fd56a
    goto L_0x004fd56a;
L_0x004fd610:
    // 004fd610  80fa10                 +cmp dl, 0x10
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
    // 004fd613  74ec                   -je 0x4fd601
    if (cpu.flags.zf)
    {
        goto L_0x004fd601;
    }
    // 004fd615  e952ffffff             -jmp 0x4fd56c
    goto L_0x004fd56c;
}

/* align: skip 0x00 0x00 */
void Application::sub_4fd61c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd61c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fd61d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd61e  891dd8765600           -mov dword ptr [0x5676d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ebx;
    // 004fd624  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fd626  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd627  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004fd628:
    // 004fd628  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fd62a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd62c  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004fd62e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fd630  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 004fd633  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004fd638  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004fd63b  8b2c9d18629f00         -mov ebp, dword ptr [ebx*4 + 0x9f6218]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10445336) /* 0x9f6218 */ + cpu.ebx * 4);
    // 004fd642  8b3cbd185e9f00         -mov edi, dword ptr [edi*4 + 0x9f5e18]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.edi * 4);
    // 004fd649  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd64c  8b048518609f00         -mov eax, dword ptr [eax*4 + 0x9f6018]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10444824) /* 0x9f6018 */ + cpu.eax * 4);
    // 004fd653  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd655  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fd657  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd659  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fd65b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fd65d  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004fd660  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004fd666  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 004fd669  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd66f  8b048550599f00         -mov eax, dword ptr [eax*4 + 0x9f5950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.eax * 4);
    // 004fd676  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 004fd679  8b0c8d38559f00         -mov ecx, dword ptr [ecx*4 + 0x9f5538]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.ecx * 4);
    // 004fd680  8b3cbdb04f9f00         -mov edi, dword ptr [edi*4 + 0x9f4fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.edi * 4);
    // 004fd687  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd689  8b1c9d185e9f00         -mov ebx, dword ptr [ebx*4 + 0x9f5e18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.ebx * 4);
    // 004fd690  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd692  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd694  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fd696  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fd698  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004fd69a  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004fd6a0  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004fd6a3  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd6a9  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 004fd6ac  8b0dd8765600           -mov ecx, dword ptr [0x5676d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */);
    // 004fd6b2  8b048550599f00         -mov eax, dword ptr [eax*4 + 0x9f5950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.eax * 4);
    // 004fd6b9  8b3cbdb04f9f00         -mov edi, dword ptr [edi*4 + 0x9f4fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.edi * 4);
    // 004fd6c0  8b1c9d38559f00         -mov ebx, dword ptr [ebx*4 + 0x9f5538]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.ebx * 4);
    // 004fd6c7  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd6c9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd6cb  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004fd6d1  250000ffff             -and eax, 0xffff0000
    cpu.eax &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004fd6d6  09e8                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004fd6d8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd6d9  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd6df  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fd6e1  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004fd6e4  0f853effffff           -jne 0x4fd628
    if (!cpu.flags.zf)
    {
        goto L_0x004fd628;
    }
    // 004fd6ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd6eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd6ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd6ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd6ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fd6ef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd6ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fd6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd6f1  891dd8765600           -mov dword ptr [0x5676d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ebx;
    // 004fd6f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fd6f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd6fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004fd6fb:
    // 004fd6fb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fd6fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd6ff  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004fd701  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fd703  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 004fd706  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004fd70b  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004fd70e  8b2c9d18629f00         -mov ebp, dword ptr [ebx*4 + 0x9f6218]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10445336) /* 0x9f6218 */ + cpu.ebx * 4);
    // 004fd715  8b3cbd185e9f00         -mov edi, dword ptr [edi*4 + 0x9f5e18]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.edi * 4);
    // 004fd71c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd71f  8b048518609f00         -mov eax, dword ptr [eax*4 + 0x9f6018]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10444824) /* 0x9f6018 */ + cpu.eax * 4);
    // 004fd726  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd728  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fd72a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd72c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fd72e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fd730  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004fd733  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004fd739  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 004fd73c  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd742  8b048550599f00         -mov eax, dword ptr [eax*4 + 0x9f5950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.eax * 4);
    // 004fd749  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 004fd74c  8b0c8d38559f00         -mov ecx, dword ptr [ecx*4 + 0x9f5538]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.ecx * 4);
    // 004fd753  8b3cbdb04f9f00         -mov edi, dword ptr [edi*4 + 0x9f4fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.edi * 4);
    // 004fd75a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd75c  8b1c9d185e9f00         -mov ebx, dword ptr [ebx*4 + 0x9f5e18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.ebx * 4);
    // 004fd763  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd765  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd767  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fd769  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fd76b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004fd76d  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 004fd773  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 004fd776  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd77c  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 004fd77f  8b0dd8765600           -mov ecx, dword ptr [0x5676d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */);
    // 004fd785  8b048550599f00         -mov eax, dword ptr [eax*4 + 0x9f5950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.eax * 4);
    // 004fd78c  8b3cbdb04f9f00         -mov edi, dword ptr [edi*4 + 0x9f4fb0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.edi * 4);
    // 004fd793  8b1c9d38559f00         -mov ebx, dword ptr [ebx*4 + 0x9f5538]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.ebx * 4);
    // 004fd79a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fd79c  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004fd79e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd79f  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd7a5  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004fd7a8  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004fd7ab  0f854affffff           -jne 0x4fd6fb
    if (!cpu.flags.zf)
    {
        goto L_0x004fd6fb;
    }
    // 004fd7b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd7b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd7b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd7b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fd7b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd7b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd7b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd7b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fd7ba  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fd7bc  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd7c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004fd7c3:
    // 004fd7c3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fd7c5  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004fd7c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fd7c9  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd7cc  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004fd7ce  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd7d1  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004fd7d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fd7d8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fd7da  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fd7dc  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004fd7df  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004fd7e1  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 004fd7e4  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004fd7ea  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004fd7ed  8b149518629f00         -mov edx, dword ptr [edx*4 + 0x9f6218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445336) /* 0x9f6218 */ + cpu.edx * 4);
    // 004fd7f4  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004fd7fa  8b0c8d18609f00         -mov ecx, dword ptr [ecx*4 + 0x9f6018]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10444824) /* 0x9f6018 */ + cpu.ecx * 4);
    // 004fd801  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd803  8b0485185e9f00         -mov eax, dword ptr [eax*4 + 0x9f5e18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.eax * 4);
    // 004fd80a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fd80c  8b2cad185e9f00         -mov ebp, dword ptr [ebp*4 + 0x9f5e18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10444312) /* 0x9f5e18 */ + cpu.ebp * 4);
    // 004fd813  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fd815  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fd817  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 004fd81a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fd81c  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 004fd81f  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd824  8b149550599f00         -mov edx, dword ptr [edx*4 + 0x9f5950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.edx * 4);
    // 004fd82b  81e1ff010000           -and ecx, 0x1ff
    cpu.ecx &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd831  8b0485b04f9f00         -mov eax, dword ptr [eax*4 + 0x9f4fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.eax * 4);
    // 004fd838  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fd83b  8b0c8d38559f00         -mov ecx, dword ptr [ecx*4 + 0x9f5538]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.ecx * 4);
    // 004fd842  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fd844  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd846  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004fd848  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 004fd84b  8943f8                 -mov dword ptr [ebx - 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004fd84e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fd850  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd856  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004fd859  8b149550599f00         -mov edx, dword ptr [edx*4 + 0x9f5950]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10443088) /* 0x9f5950 */ + cpu.edx * 4);
    // 004fd860  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fd865  8b2cadb04f9f00         -mov ebp, dword ptr [ebp*4 + 0x9f4fb0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10440624) /* 0x9f4fb0 */ + cpu.ebp * 4);
    // 004fd86c  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd86e  8b0dd8765600           -mov ecx, dword ptr [0x5676d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */);
    // 004fd874  8b048538559f00         -mov eax, dword ptr [eax*4 + 0x9f5538]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10442040) /* 0x9f5538 */ + cpu.eax * 4);
    // 004fd87b  01d0                   +add eax, edx
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
    // 004fd87d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd87e  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd884  90                     -nop 
    ;
    // 004fd885  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004fd888  0f8535ffffff           -jne 0x4fd7c3
    if (!cpu.flags.zf)
    {
        goto L_0x004fd7c3;
    }
    // 004fd88e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd88f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd890  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd891  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fd892(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd892  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fd893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd894  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd895  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004fd896:
    // 004fd896  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004fd898  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004fd89b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004fd89d  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004fd89f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004fd8a2  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 004fd8a8  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004fd8ab  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 004fd8b1  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004fd8b7  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd8b9  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd8bb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd8be  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fd8c0  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fd8c3  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 004fd8c5  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 004fd8cb  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004fd8cd  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 004fd8d3  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004fd8d6  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd8d8  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004fd8de  897afc                 -mov dword ptr [edx - 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004fd8e1  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004fd8e3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd8e4  8972f8                 -mov dword ptr [edx - 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 004fd8e7  75ad                   -jne 0x4fd896
    if (!cpu.flags.zf)
    {
        goto L_0x004fd896;
    }
    // 004fd8e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd8ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd8eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd8ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd8ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fd8ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd8ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd8ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd8f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fd8f1  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd8f7  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004fd8f9  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004fd8fb  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fd8fd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd900  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 004fd902  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd905  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004fd90b  893ddc765600           -mov dword ptr [0x5676dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5666524) /* 0x5676dc */) = cpu.edi;
L_0x004fd911:
    // 004fd911  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004fd913  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004fd915  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fd917  8b35dc765600           -mov esi, dword ptr [0x5676dc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666524) /* 0x5676dc */);
    // 004fd91d  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 004fd91f  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fd922  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004fd928  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004fd92a  893ddc765600           -mov dword ptr [0x5676dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5666524) /* 0x5676dc */) = cpu.edi;
    // 004fd930  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004fd932  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004fd935  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 004fd93b  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004fd93e  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 004fd944  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004fd94a  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd94c  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fd94e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd951  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fd953  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fd956  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 004fd958  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 004fd95e  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004fd960  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 004fd966  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 004fd969  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd96b  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 004fd971  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004fd974  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004fd976  8b0dd8765600           -mov ecx, dword ptr [0x5676d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */);
    // 004fd97c  8973f8                 -mov dword ptr [ebx - 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 004fd97f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fd980  890dd8765600           -mov dword ptr [0x5676d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666520) /* 0x5676d8 */) = cpu.ecx;
    // 004fd986  7589                   -jne 0x4fd911
    if (!cpu.flags.zf)
    {
        goto L_0x004fd911;
    }
    // 004fd988  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd989  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd98a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fd98b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fd98c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fd98c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fd98d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fd98e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fd98f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fd990  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fd992  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fd994  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004fd996  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fd998  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd99a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd99c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004fd99e:
    // 004fd99e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004fd9a0  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004fd9a3  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004fd9a6  8a5603                 -mov dl, byte ptr [esi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004fd9a9  8a80e0765600           -mov al, byte ptr [eax + 0x5676e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9af  8a9be0765600           -mov bl, byte ptr [ebx + 0x5676e0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9b5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004fd9b8  8a89e0765600           -mov cl, byte ptr [ecx + 0x5676e0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9be  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004fd9c1  8a92e0765600           -mov dl, byte ptr [edx + 0x5676e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9c7  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fd9c9  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004fd9cb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004fd9ce  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fd9d1  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd9d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fd9d5  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004fd9d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fd9d9  8a4efc                 -mov cl, byte ptr [esi - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004fd9dc  8a56fd                 -mov dl, byte ptr [esi - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */);
    // 004fd9df  8a46fe                 -mov al, byte ptr [esi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 004fd9e2  8a5eff                 -mov bl, byte ptr [esi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004fd9e5  8a89e0765600           -mov cl, byte ptr [ecx + 0x5676e0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9eb  8a92e0765600           -mov dl, byte ptr [edx + 0x5676e0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9f1  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004fd9f4  8a80e0765600           -mov al, byte ptr [eax + 0x5676e0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fd9fa  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004fd9fd  8a9be0765600           -mov bl, byte ptr [ebx + 0x5676e0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5666528) /* 0x5676e0 */);
    // 004fda03  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004fda05  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fda07  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004fda0a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fda0d  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004fda0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fda11  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004fda14  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fda16  83ed02                 +sub ebp, 2
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
    // 004fda19  7f83                   -jg 0x4fd99e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fd99e;
    }
    // 004fda1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fda20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fda20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fda21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fda22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fda23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fda24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fda25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fda26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004fda28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004fda2b  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004fda2e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004fda32  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 004fda37  bb71000000             -mov ebx, 0x71
    cpu.ebx = 113 /*0x71*/;
    // 004fda3c  bf00180200             -mov edi, 0x21800
    cpu.edi = 137216 /*0x21800*/;
    // 004fda41  be0000802c             -mov esi, 0x2c800000
    cpu.esi = 746586112 /*0x2c800000*/;
    // 004fda46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004fda48:
    // 004fda48  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004fda4c  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004fda4f  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004fda53  dc05b8e05400           -fadd qword ptr [0x54e0b8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5562552) /* 0x54e0b8 */));
    // 004fda59  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fda5b  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 004fda5e  dc0d98e05400           -fmul qword ptr [0x54e098]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5562520) /* 0x54e098 */));
    // 004fda64  8982185e9f00           -mov dword ptr [edx + 0x9f5e18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10444312) /* 0x9f5e18 */) = cpu.eax;
    // 004fda6a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fda6d  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004fda70  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda71  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004fda74  dc0da0e05400           -fmul qword ptr [0x54e0a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5562528) /* 0x54e0a0 */));
    // 004fda7a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004fda7e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fda81  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004fda84  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fda85  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004fda88  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fda8c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fda90  dc0da8e05400           -fmul qword ptr [0x54e0a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5562536) /* 0x54e0a8 */));
    // 004fda96  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fda9b  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 004fda9e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004fdaa2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fdaa6  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fdaab  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fdaaf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fdab3  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004fdab7  898218609f00           -mov dword ptr [edx + 0x9f6018], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10444824) /* 0x9f6018 */) = cpu.eax;
    // 004fdabd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdac0  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004fdac3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdac4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004fdac7  dc0db0e05400           -fmul qword ptr [0x54e0b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5562544) /* 0x54e0b0 */));
    // 004fdacd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fdad1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdad4  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004fdad7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdad8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004fdadc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fdae0  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fdae5  c1e017                 -shl eax, 0x17
    cpu.eax <<= 23 /*0x17*/ % 32;
    // 004fdae8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fdaec  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fdaf0  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdaf3  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004fdaf8  81c700080000           -add edi, 0x800
    (cpu.edi) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 004fdafe  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 004fdb01  81c600008000           -add esi, 0x800000
    (cpu.esi) += x86::reg32(x86::sreg32(8388608 /*0x800000*/));
    // 004fdb07  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004fdb0b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fdb0f  41                     -inc ecx
    (cpu.ecx)++;
    // 004fdb10  03442410               -add eax, dword ptr [esp + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004fdb14  43                     -inc ebx
    (cpu.ebx)++;
    // 004fdb15  898214629f00           -mov dword ptr [edx + 0x9f6214], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10445332) /* 0x9f6214 */) = cpu.eax;
    // 004fdb1b  83f940                 +cmp ecx, 0x40
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
    // 004fdb1e  0f8c24ffffff           -jl 0x4fda48
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fda48;
    }
    // 004fdb24  b99cfdffff             -mov ecx, 0xfffffd9c
    cpu.ecx = 4294966684 /*0xfffffd9c*/;
    // 004fdb29  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
    // 004fdb2e  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fdb32  ba67ffffff             -mov edx, 0xffffff67
    cpu.edx = 4294967143 /*0xffffff67*/;
L_0x004fdb37:
    // 004fdb37  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004fdb3a  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 004fdb3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fdb41  0f8c03010000           -jl 0x4fdc4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdc4a;
    }
    // 004fdb47  3dff000000             +cmp eax, 0xff
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
    // 004fdb4c  7e05                   -jle 0x4fdb53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdb53;
    }
    // 004fdb4e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004fdb53:
    // 004fdb53  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fdb55  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdb58  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004fdb5b  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004fdb5e  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdb61  7e02                   -jle 0x4fdb65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdb65;
    }
    // 004fdb63  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004fdb65:
    // 004fdb65  83ff0f                 +cmp edi, 0xf
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdb68  0f85e3000000           -jne 0x4fdc51
    if (!cpu.flags.zf)
    {
        goto L_0x004fdc51;
    }
    // 004fdb6e  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004fdb71  c1e31a                 -shl ebx, 0x1a
    cpu.ebx <<= 26 /*0x1a*/ % 32;
L_0x004fdb74:
    // 004fdb74  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fdb76  8981b45b9f00           -mov dword ptr [ecx + 0x9f5bb4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10443700) /* 0x9f5bb4 */) = cpu.eax;
    // 004fdb7c  42                     -inc edx
    (cpu.edx)++;
    // 004fdb7d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdb80  81fa99000000           +cmp edx, 0x99
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153 /*0x99*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdb86  7caf                   -jl 0x4fdb37
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdb37;
    }
    // 004fdb88  b9f4fdffff             -mov ecx, 0xfffffdf4
    cpu.ecx = 4294966772 /*0xfffffdf4*/;
    // 004fdb8d  ba7dffffff             -mov edx, 0xffffff7d
    cpu.edx = 4294967165 /*0xffffff7d*/;
    // 004fdb92  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 004fdb97  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
L_0x004fdb9c:
    // 004fdb9c  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004fdb9f  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 004fdba4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fdba6  0f8cb0000000           -jl 0x4fdc5c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdc5c;
    }
    // 004fdbac  3dff000000             +cmp eax, 0xff
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
    // 004fdbb1  7e02                   -jle 0x4fdbb5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdbb5;
    }
    // 004fdbb3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004fdbb5:
    // 004fdbb5  837c240c0f             +cmp dword ptr [esp + 0xc], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdbba  0f85a3000000           -jne 0x4fdc63
    if (!cpu.flags.zf)
    {
        goto L_0x004fdc63;
    }
    // 004fdbc0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fdbc2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdbc5  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004fdbc8  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004fdbcb  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdbce  7e05                   -jle 0x4fdbd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdbd5;
    }
    // 004fdbd0  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
L_0x004fdbd5:
    // 004fdbd5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004fdbd8  c1e315                 -shl ebx, 0x15
    cpu.ebx <<= 21 /*0x15*/ % 32;
    // 004fdbdb  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdbde  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fdbe0  42                     -inc edx
    (cpu.edx)++;
    // 004fdbe1  898140579f00           -mov dword ptr [ecx + 0x9f5740], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10442560) /* 0x9f5740 */) = cpu.eax;
    // 004fdbe7  81fa83000000           +cmp edx, 0x83
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdbed  7cad                   -jl 0x4fdb9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdb9c;
    }
    // 004fdbef  b93cfdffff             -mov ecx, 0xfffffd3c
    cpu.ecx = 4294966588 /*0xfffffd3c*/;
    // 004fdbf4  bf1f000000             -mov edi, 0x1f
    cpu.edi = 31 /*0x1f*/;
    // 004fdbf9  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 004fdbfe  ba4fffffff             -mov edx, 0xffffff4f
    cpu.edx = 4294967119 /*0xffffff4f*/;
L_0x004fdc03:
    // 004fdc03  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004fdc06  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 004fdc0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fdc0d  7c6f                   -jl 0x4fdc7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdc7e;
    }
    // 004fdc0f  3dff000000             +cmp eax, 0xff
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
    // 004fdc14  7e02                   -jle 0x4fdc18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdc18;
    }
    // 004fdc16  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004fdc18:
    // 004fdc18  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fdc1a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdc1d  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004fdc20  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004fdc23  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdc26  7e02                   -jle 0x4fdc2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdc2a;
    }
    // 004fdc28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004fdc2a:
    // 004fdc2a  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004fdc2d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fdc30  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fdc32  42                     -inc edx
    (cpu.edx)++;
    // 004fdc33  898170529f00           -mov dword ptr [ecx + 0x9f5270], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10441328) /* 0x9f5270 */) = cpu.eax;
    // 004fdc39  81fab1000000           +cmp edx, 0xb1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(177 /*0xb1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdc3f  7cc2                   -jl 0x4fdc03
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdc03;
    }
    // 004fdc41  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004fdc43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdc49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fdc4a:
    // 004fdc4a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fdc4c  e902ffffff             -jmp 0x4fdb53
    goto L_0x004fdb53;
L_0x004fdc51:
    // 004fdc51  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 004fdc54  c1e31b                 +shl ebx, 0x1b
    {
        x86::reg8 tmp = 27 /*0x1b*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004fdc57  e918ffffff             -jmp 0x4fdb74
    goto L_0x004fdb74;
L_0x004fdc5c:
    // 004fdc5c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fdc5e  e952ffffff             -jmp 0x4fdbb5
    goto L_0x004fdbb5;
L_0x004fdc63:
    // 004fdc63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fdc65  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fdc68  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004fdc6b  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 004fdc6e  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdc71  0f8e5effffff           -jle 0x4fdbd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdbd5;
    }
    // 004fdc77  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fdc79  e957ffffff             -jmp 0x4fdbd5
    goto L_0x004fdbd5;
L_0x004fdc7e:
    // 004fdc7e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fdc80  eb96                   -jmp 0x4fdc18
    goto L_0x004fdc18;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4fdc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fdc90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fdc91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fdc92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fdc93  81ec480a0000           -sub esp, 0xa48
    (cpu.esp) -= x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fdc99  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fdc9b  899424100a0000         -mov dword ptr [esp + 0xa10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.edx;
    // 004fdca2  899c240c0a0000         -mov dword ptr [esp + 0xa0c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebx;
    // 004fdca9  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004fdcab  8b94245c0a0000         -mov edx, dword ptr [esp + 0xa5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 004fdcb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fdcb4  0f85f4010000           -jne 0x4fdeae
    if (!cpu.flags.zf)
    {
        goto L_0x004fdeae;
    }
    // 004fdcba  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004fdcbf:
    // 004fdcbf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fdcc1  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004fdcc7  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdcca  7409                   -je 0x4fdcd5
    if (cpu.flags.zf)
    {
        goto L_0x004fdcd5;
    }
    // 004fdccc  83fa10                 +cmp edx, 0x10
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
    // 004fdccf  0f8503020000           -jne 0x4fded8
    if (!cpu.flags.zf)
    {
        goto L_0x004fded8;
    }
L_0x004fdcd5:
    // 004fdcd5  3b1518649f00           +cmp edx, dword ptr [0x9f6418]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10445848) /* 0x9f6418 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdcdb  740d                   -je 0x4fdcea
    if (cpu.flags.zf)
    {
        goto L_0x004fdcea;
    }
    // 004fdcdd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fdcdf  e83cfdffff             -call 0x4fda20
    cpu.esp -= 4;
    sub_4fda20(app, cpu);
    if (cpu.terminate) return;
    // 004fdce4  891518649f00           -mov dword ptr [0x9f6418], edx
    app->getMemory<x86::reg32>(x86::reg32(10445848) /* 0x9f6418 */) = cpu.edx;
L_0x004fdcea:
    // 004fdcea  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fdcec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fdcee  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fdcf4  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fdcf7  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fdcfd  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fdd00  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fdd06  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004fdd09  6683e6fe               -and si, 0xfffe
    cpu.si &= x86::reg16(x86::sreg16(65534 /*0xfffe*/));
    // 004fdd0d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004fdd0f  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004fdd11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fdd13  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004fdd16  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004fdd19  8b8424580a0000         -mov eax, dword ptr [esp + 0xa58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2648) /* 0xa58 */);
    // 004fdd20  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004fdd23  899424080a0000         -mov dword ptr [esp + 0xa08], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edx;
    // 004fdd2a  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdd31  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fdd33  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
    // 004fdd3a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fdd3c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fdd3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fdd41  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fdd43  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004fdd45  8b1500505600           -mov edx, dword ptr [0x565000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004fdd4b  898424040a0000         -mov dword ptr [esp + 0xa04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */) = cpu.eax;
    // 004fdd52  39d6                   +cmp esi, edx
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
    // 004fdd54  7d22                   -jge 0x4fdd78
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdd78;
    }
    // 004fdd56  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 004fdd59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fdd5b  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004fdd5e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fdd60  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fdd62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fdd64  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fdd67  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fdd69  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fdd6c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fdd6f  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fdd71  0184240c0a0000         -add dword ptr [esp + 0xa0c], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004fdd78:
    // 004fdd78  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004fdd7f  8b3d08505600           -mov edi, dword ptr [0x565008]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 004fdd85  39f8                   +cmp eax, edi
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
    // 004fdd87  7e07                   -jle 0x4fdd90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fdd90;
    }
    // 004fdd89  89bc24080a0000         -mov dword ptr [esp + 0xa08], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edi;
L_0x004fdd90:
    // 004fdd90  8b8424100a0000         -mov eax, dword ptr [esp + 0xa10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdd97  8b2d04505600           -mov ebp, dword ptr [0x565004]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 004fdd9d  39e8                   +cmp eax, ebp
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
    // 004fdd9f  7d47                   -jge 0x4fdde8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdde8;
    }
    // 004fdda1  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdda8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fddaa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fddac  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004fddaf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fddb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fddb3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fddb6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fddb8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fddba  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004fddbd  0faf8424040a0000       -imul eax, dword ptr [esp + 0xa04]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */))));
    // 004fddc5  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fddcc  8bac240c0a0000         -mov ebp, dword ptr [esp + 0xa0c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fddd3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fddd6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fddd8  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fddda  899c24100a0000         -mov dword ptr [esp + 0xa10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.ebx;
    // 004fdde1  89ac240c0a0000         -mov dword ptr [esp + 0xa0c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebp;
L_0x004fdde8:
    // 004fdde8  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fddef  8b150c505600           -mov edx, dword ptr [0x56500c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 004fddf5  39d0                   +cmp eax, edx
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
    // 004fddf7  7e07                   -jle 0x4fde00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fde00;
    }
    // 004fddf9  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
L_0x004fde00:
    // 004fde00  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004fde07  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fde09  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fde0b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004fde0d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fde10  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fde12  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fde14  83f802                 +cmp eax, 2
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
    // 004fde17  0f8c83000000           -jl 0x4fdea0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdea0;
    }
    // 004fde1d  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 004fde24  8b8c245c0a0000         -mov ecx, dword ptr [esp + 0xa5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 004fde2b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fde2e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fde30  0f85b3000000           -jne 0x4fdee9
    if (!cpu.flags.zf)
    {
        goto L_0x004fdee9;
    }
    // 004fde36  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fde3d  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fde44  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fde4b  39dd                   +cmp ebp, ebx
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
    // 004fde4d  7d51                   -jge 0x4fdea0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdea0;
    }
    // 004fde4f  898424200a0000         -mov dword ptr [esp + 0xa20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */) = cpu.eax;
L_0x004fde56:
    // 004fde56  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004fde58  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fde5a  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fde60  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fde63  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fde69  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fde6c  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fde72  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fde74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fde76  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fde78  45                     -inc ebp
    (cpu.ebp)++;
    // 004fde79  e89ef7ffff             -call 0x4fd61c
    cpu.esp -= 4;
    sub_4fd61c(app, cpu);
    if (cpu.terminate) return;
    // 004fde7e  8b8424200a0000         -mov eax, dword ptr [esp + 0xa20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */);
    // 004fde85  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fde8c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fde8e  39d5                   +cmp ebp, edx
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
    // 004fde90  7cc4                   -jl 0x4fde56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fde56;
    }
    // 004fde92  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004fde98  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004fde9e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004fdea0:
    // 004fdea0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fdea2  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fdea8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdea9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdeaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdeab  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fdeae:
    // 004fdeae  83fa01                 +cmp edx, 1
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
    // 004fdeb1  750a                   -jne 0x4fdebd
    if (!cpu.flags.zf)
    {
        goto L_0x004fdebd;
    }
L_0x004fdeb3:
    // 004fdeb3  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004fdeb8  e902feffff             -jmp 0x4fdcbf
    goto L_0x004fdcbf;
L_0x004fdebd:
    // 004fdebd  83fa02                 +cmp edx, 2
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
    // 004fdec0  74f1                   -je 0x4fdeb3
    if (cpu.flags.zf)
    {
        goto L_0x004fdeb3;
    }
    // 004fdec2  83fa03                 +cmp edx, 3
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
    // 004fdec5  74ec                   -je 0x4fdeb3
    if (cpu.flags.zf)
    {
        goto L_0x004fdeb3;
    }
    // 004fdec7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004fdecc  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fded2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fded3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fded4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fded5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fded8:
    // 004fded8  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004fdedd  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fdee3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdee4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdee5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fdee6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fdee9:
    // 004fdee9  83f903                 +cmp ecx, 3
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
    // 004fdeec  0f857c010000           -jne 0x4fe06e
    if (!cpu.flags.zf)
    {
        goto L_0x004fe06e;
    }
    // 004fdef2  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdef9  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fdf00  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fdf07  39dd                   +cmp ebp, ebx
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
    // 004fdf09  0f8d71000000           -jge 0x4fdf80
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdf80;
    }
    // 004fdf0f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fdf11  4a                     -dec edx
    (cpu.edx)--;
    // 004fdf12  899424180a0000         -mov dword ptr [esp + 0xa18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */) = cpu.edx;
    // 004fdf19  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004fdf1c  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fdf1f  898424140a0000         -mov dword ptr [esp + 0xa14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */) = cpu.eax;
    // 004fdf26  899424280a0000         -mov dword ptr [esp + 0xa28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */) = cpu.edx;
L_0x004fdf2d:
    // 004fdf2d  8b9c24180a0000         -mov ebx, dword ptr [esp + 0xa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */);
    // 004fdf34  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004fdf36  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fdf38  e855f9ffff             -call 0x4fd892
    cpu.esp -= 4;
    sub_4fd892(app, cpu);
    if (cpu.terminate) return;
    // 004fdf3d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004fdf3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fdf41  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fdf47  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fdf4a  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fdf50  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fdf53  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fdf59  8b9c24280a0000         -mov ebx, dword ptr [esp + 0xa28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */);
    // 004fdf60  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fdf62  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fdf64  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fdf67  e8b0f6ffff             -call 0x4fd61c
    cpu.esp -= 4;
    sub_4fd61c(app, cpu);
    if (cpu.terminate) return;
    // 004fdf6c  8b8424140a0000         -mov eax, dword ptr [esp + 0xa14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */);
    // 004fdf73  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fdf7a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fdf7c  39d5                   +cmp ebp, edx
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
    // 004fdf7e  7cad                   -jl 0x4fdf2d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdf2d;
    }
L_0x004fdf80:
    // 004fdf80  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fdf87  8b8c24100a0000         -mov ecx, dword ptr [esp + 0xa10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdf8e  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004fdf95  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fdf97  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fdf99  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fdf9c  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fdfa1  0f8fae000000           -jg 0x4fe055
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe055;
    }
L_0x004fdfa7:
    // 004fdfa7  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fdfae  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004fdfb1  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fdfb8  899424340a0000         -mov dword ptr [esp + 0xa34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */) = cpu.edx;
    // 004fdfbf  8b9424040a0000         -mov edx, dword ptr [esp + 0xa04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 004fdfc6  45                     -inc ebp
    (cpu.ebp)++;
    // 004fdfc7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004fdfca  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004fdfcc  899424240a0000         -mov dword ptr [esp + 0xa24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.edx;
    // 004fdfd3  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fdfda  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fdfdd  4a                     -dec edx
    (cpu.edx)--;
    // 004fdfde  89bc24300a0000         -mov dword ptr [esp + 0xa30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */) = cpu.edi;
    // 004fdfe5  899424380a0000         -mov dword ptr [esp + 0xa38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */) = cpu.edx;
    // 004fdfec  39d5                   +cmp ebp, edx
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
    // 004fdfee  0f8dacfeffff           -jge 0x4fdea0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdea0;
    }
L_0x004fdff4:
    // 004fdff4  8bbc24240a0000         -mov edi, dword ptr [esp + 0xa24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 004fdffb  8b8c24340a0000         -mov ecx, dword ptr [esp + 0xa34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 004fe002  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fe004  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fe006  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004fe008  e8e1f8ffff             -call 0x4fd8ee
    cpu.esp -= 4;
    sub_4fd8ee(app, cpu);
    if (cpu.terminate) return;
    // 004fe00d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004fe00f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fe011  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fe017  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fe01a  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fe020  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fe023  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fe029  8b9c24300a0000         -mov ebx, dword ptr [esp + 0xa30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */);
    // 004fe030  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fe032  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe034  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe037  e8e0f5ffff             -call 0x4fd61c
    cpu.esp -= 4;
    sub_4fd61c(app, cpu);
    if (cpu.terminate) return;
    // 004fe03c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fe03e  3bac24380a0000         +cmp ebp, dword ptr [esp + 0xa38]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fe045  7cad                   -jl 0x4fdff4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fdff4;
    }
    // 004fe047  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fe049  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fe04f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe050  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe051  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe052  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fe055:
    // 004fe055  e886b0ffff             -call 0x4f90e0
    cpu.esp -= 4;
    sub_4f90e0(app, cpu);
    if (cpu.terminate) return;
    // 004fe05a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fe05c  0f8545ffffff           -jne 0x4fdfa7
    if (!cpu.flags.zf)
    {
        goto L_0x004fdfa7;
    }
    // 004fe062  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fe068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe069  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe06a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe06b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fe06e:
    // 004fe06e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fe075  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fe07c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fe083  39dd                   +cmp ebp, ebx
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
    // 004fe085  7d49                   -jge 0x4fe0d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fe0d0;
    }
    // 004fe087  8984241c0a0000         -mov dword ptr [esp + 0xa1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */) = cpu.eax;
L_0x004fe08e:
    // 004fe08e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004fe090  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fe092  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fe098  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fe09b  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fe0a1  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fe0a4  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fe0aa  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004fe0ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fe0ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fe0b0  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe0b3  e837f6ffff             -call 0x4fd6ef
    cpu.esp -= 4;
    sub_4fd6ef(app, cpu);
    if (cpu.terminate) return;
    // 004fe0b8  8b84241c0a0000         -mov eax, dword ptr [esp + 0xa1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */);
    // 004fe0bf  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fe0c6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004fe0c8  39d5                   +cmp ebp, edx
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
    // 004fe0ca  7cc2                   -jl 0x4fe08e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fe08e;
    }
    // 004fe0cc  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004fe0d0:
    // 004fe0d0  83bc245c0a000002       +cmp dword ptr [esp + 0xa5c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fe0d8  0f85c2fdffff           -jne 0x4fdea0
    if (!cpu.flags.zf)
    {
        goto L_0x004fdea0;
    }
    // 004fe0de  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fe0e5  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fe0ec  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 004fe0f3  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fe0f5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fe0f7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004fe0fa  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fe0ff  0f8fab000000           -jg 0x4fe1b0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe1b0;
    }
L_0x004fe105:
    // 004fe105  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 004fe10c  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 004fe113  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 004fe11a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004fe11d  8984242c0a0000         -mov dword ptr [esp + 0xa2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */) = cpu.eax;
    // 004fe124  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 004fe12b  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 004fe132  48                     -dec eax
    (cpu.eax)--;
    // 004fe133  45                     -inc ebp
    (cpu.ebp)++;
    // 004fe134  8984243c0a0000         -mov dword ptr [esp + 0xa3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */) = cpu.eax;
    // 004fe13b  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fe13d  0f8d5dfdffff           -jge 0x4fdea0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fdea0;
    }
L_0x004fe143:
    // 004fe143  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004fe145  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fe147  8b8c242c0a0000         -mov ecx, dword ptr [esp + 0xa2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */);
    // 004fe14e  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 004fe154  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004fe157  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 004fe15d  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004fe160  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 004fe166  8b9424400a0000         -mov edx, dword ptr [esp + 0xa40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 004fe16d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fe16f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe172  8b8424400a0000         -mov eax, dword ptr [esp + 0xa40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 004fe179  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe17b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004fe17d  899424000a0000         -mov dword ptr [esp + 0xa00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */) = cpu.edx;
    // 004fe184  e82df6ffff             -call 0x4fd7b6
    cpu.esp -= 4;
    sub_4fd7b6(app, cpu);
    if (cpu.terminate) return;
    // 004fe189  8b8424000a0000         -mov eax, dword ptr [esp + 0xa00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */);
    // 004fe190  8b9c243c0a0000         -mov ebx, dword ptr [esp + 0xa3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */);
    // 004fe197  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 004fe19e  39dd                   +cmp ebp, ebx
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
    // 004fe1a0  7ca1                   -jl 0x4fe143
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fe143;
    }
    // 004fe1a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fe1a4  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fe1aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1ad  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004fe1b0:
    // 004fe1b0  e82bafffff             -call 0x4f90e0
    cpu.esp -= 4;
    sub_4f90e0(app, cpu);
    if (cpu.terminate) return;
    // 004fe1b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fe1b7  0f8548ffffff           -jne 0x4fe105
    if (!cpu.flags.zf)
    {
        goto L_0x004fe105;
    }
    // 004fe1bd  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 004fe1c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe1c6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4fe1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe1d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe1d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe1d2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe1d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe1d4  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe1d7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fe1d9  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004fe1db  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004fe1dd  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004fe1e2  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 004fe1e6  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004fe1e8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fe1eb  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 004fe1f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fe1f2  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004fe1f7  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004fe1fb  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004fe1fd  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 004fe201  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004fe203  0f8461030000           -je 0x4fe56a
    if (cpu.flags.zf)
    {
        goto L_0x004fe56a;
    }
L_0x004fe209:
    // 004fe209  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe20d  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe211  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe213  45                     -inc ebp
    (cpu.ebp)++;
    // 004fe214  80fd25                 +cmp ch, 0x25
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
    // 004fe217  7411                   -je 0x4fe22a
    if (cpu.flags.zf)
    {
        goto L_0x004fe22a;
    }
    // 004fe219  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004fe21b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe21d  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 004fe21f  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 004fe223  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe225  e918030000             -jmp 0x4fe542
    goto L_0x004fe542;
L_0x004fe22a:
    // 004fe22a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fe22c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe22e  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004fe232  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004fe236  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fe238  e83b030000             -call 0x4fe578
    cpu.esp -= 4;
    sub_4fe578(app, cpu);
    if (cpu.terminate) return;
    // 004fe23d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fe23f  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004fe243  45                     -inc ebp
    (cpu.ebp)++;
    // 004fe244  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004fe246  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 004fe249  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 004fe24d  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004fe251  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004fe253  0f8411030000           -je 0x4fe56a
    if (cpu.flags.zf)
    {
        goto L_0x004fe56a;
    }
    // 004fe259  3c6e                   +cmp al, 0x6e
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
    // 004fe25b  0f8570010000           -jne 0x4fe3d1
    if (!cpu.flags.zf)
    {
        goto L_0x004fe3d1;
    }
    // 004fe261  8a5c241e               -mov bl, byte ptr [esp + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004fe265  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004fe268  744f                   -je 0x4fe2b9
    if (cpu.flags.zf)
    {
        goto L_0x004fe2b9;
    }
    // 004fe26a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004fe26d  741f                   -je 0x4fe28e
    if (cpu.flags.zf)
    {
        goto L_0x004fe28e;
    }
    // 004fe26f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe271  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fe274  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004fe276  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
    // 004fe279  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe27d  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 004fe280  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe284  803800                 +cmp byte ptr [eax], 0
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
    // 004fe287  7580                   -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe289  e9dc020000             -jmp 0x4fe56a
    goto L_0x004fe56a;
L_0x004fe28e:
    // 004fe28e  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004fe291  0f84e8000000           -je 0x4fe37f
    if (cpu.flags.zf)
    {
        goto L_0x004fe37f;
    }
    // 004fe297  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe299  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe29c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004fe29e  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004fe2a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe2a5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fe2a7  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe2ab  803800                 +cmp byte ptr [eax], 0
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
    // 004fe2ae  0f8555ffffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe2b4  e9b1020000             -jmp 0x4fe56a
    goto L_0x004fe56a;
L_0x004fe2b9:
    // 004fe2b9  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004fe2bc  0f8489000000           -je 0x4fe34b
    if (cpu.flags.zf)
    {
        goto L_0x004fe34b;
    }
    // 004fe2c2  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004fe2c5  742b                   -je 0x4fe2f2
    if (cpu.flags.zf)
    {
        goto L_0x004fe2f2;
    }
    // 004fe2c7  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe2c9  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fe2cc  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004fe2ce  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004fe2d1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe2d5  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 004fe2d9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe2dd  803800                 +cmp byte ptr [eax], 0
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
    // 004fe2e0  0f8523ffffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe2e6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe2ea  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe2ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe2ee  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe2ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe2f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe2f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe2f2:
    // 004fe2f2  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004fe2f5  742a                   -je 0x4fe321
    if (cpu.flags.zf)
    {
        goto L_0x004fe321;
    }
    // 004fe2f7  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe2f9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe2fc  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004fe2fe  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004fe301  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe305  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004fe308  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe30c  803800                 +cmp byte ptr [eax], 0
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
    // 004fe30f  0f85f4feffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe315  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe319  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe31c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe31d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe31f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe320  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe321:
    // 004fe321  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe323  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe326  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004fe328  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004fe32b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe32f  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004fe332  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe336  803800                 +cmp byte ptr [eax], 0
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
    // 004fe339  0f85cafeffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe33f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe343  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe346  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe347  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe348  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe349  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe34a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe34b:
    // 004fe34b  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004fe34e  742a                   -je 0x4fe37a
    if (cpu.flags.zf)
    {
        goto L_0x004fe37a;
    }
    // 004fe350  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe352  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fe355  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004fe357  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 004fe35a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe35e  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 004fe361  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe365  803800                 +cmp byte ptr [eax], 0
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
    // 004fe368  0f859bfeffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe36e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe372  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe375  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe376  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe377  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe378  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe379  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe37a:
    // 004fe37a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004fe37d  7429                   -je 0x4fe3a8
    if (cpu.flags.zf)
    {
        goto L_0x004fe3a8;
    }
L_0x004fe37f:
    // 004fe37f  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe381  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe384  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 004fe386  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004fe389  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe38d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fe38f  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe393  803800                 +cmp byte ptr [eax], 0
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
    // 004fe396  0f856dfeffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe39c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe3a0  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe3a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3a4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe3a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe3a8:
    // 004fe3a8  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe3aa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe3ad  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004fe3af  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004fe3b2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe3b6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fe3b8  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe3bc  803800                 +cmp byte ptr [eax], 0
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
    // 004fe3bf  0f8544feffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe3c5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe3c9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe3cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3cd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe3ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe3d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe3d1:
    // 004fe3d1  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004fe3d5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fe3d7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe3d9  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004fe3dd  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004fe3e1  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004fe3e5  e8ea050000             -call 0x4fe9d4
    cpu.esp -= 4;
    sub_4fe9d4(app, cpu);
    if (cpu.terminate) return;
    // 004fe3ea  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004fe3ec  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004fe3f0  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004fe3f2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004fe3f4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fe3f8  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004fe3fc  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004fe400  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe402  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004fe406  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fe408  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004fe40c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004fe40e  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004fe412  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe414  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004fe418  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fe41a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004fe41c  8a54241e               -mov dl, byte ptr [esp + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004fe420  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004fe424  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004fe427  751d                   -jne 0x4fe446
    if (!cpu.flags.zf)
    {
        goto L_0x004fe446;
    }
    // 004fe429  807c241620             +cmp byte ptr [esp + 0x16], 0x20
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
    // 004fe42e  7516                   -jne 0x4fe446
    if (!cpu.flags.zf)
    {
        goto L_0x004fe446;
    }
L_0x004fe430:
    // 004fe430  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004fe435  7e0f                   -jle 0x4fe446
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe446;
    }
    // 004fe437  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004fe43c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe43e  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe440  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe444  ebea                   -jmp 0x4fe430
    goto L_0x004fe430;
L_0x004fe446:
    // 004fe446  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fe44a  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004fe44e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fe450  7e16                   -jle 0x4fe468
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe468;
    }
L_0x004fe452:
    // 004fe452  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe454  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe456  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004fe458  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe45a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004fe45e  4a                     -dec edx
    (cpu.edx)--;
    // 004fe45f  43                     -inc ebx
    (cpu.ebx)++;
    // 004fe460  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004fe464  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe466  7fea                   -jg 0x4fe452
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe452;
    }
L_0x004fe468:
    // 004fe468  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 004fe46d  7e0f                   -jle 0x4fe47e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe47e;
    }
    // 004fe46f  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004fe474  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe476  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe478  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe47c  ebea                   -jmp 0x4fe468
    goto L_0x004fe468;
L_0x004fe47e:
    // 004fe47e  8a5c2415               -mov bl, byte ptr [esp + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 004fe482  80fb73                 +cmp bl, 0x73
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
    // 004fe485  7533                   -jne 0x4fe4ba
    if (!cpu.flags.zf)
    {
        goto L_0x004fe4ba;
    }
    // 004fe487  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004fe48c  740f                   -je 0x4fe49d
    if (cpu.flags.zf)
    {
        goto L_0x004fe49d;
    }
    // 004fe48e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fe490  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004fe492  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fe494  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fe496  e8d5040000             -call 0x4fe970
    cpu.esp -= 4;
    sub_4fe970(app, cpu);
    if (cpu.terminate) return;
    // 004fe49b  eb4e                   -jmp 0x4fe4eb
    goto L_0x004fe4eb;
L_0x004fe49d:
    // 004fe49d  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 004fe4a2  7e47                   -jle 0x4fe4eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe4eb;
    }
    // 004fe4a4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004fe4a6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe4a8  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 004fe4ac  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe4ae  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004fe4b2  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe4b3  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe4b4  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004fe4b8  ebe3                   -jmp 0x4fe49d
    goto L_0x004fe49d;
L_0x004fe4ba:
    // 004fe4ba  80fb53                 +cmp bl, 0x53
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
    // 004fe4bd  750f                   -jne 0x4fe4ce
    if (!cpu.flags.zf)
    {
        goto L_0x004fe4ce;
    }
    // 004fe4bf  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004fe4c1  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004fe4c3  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fe4c5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004fe4c7  e8a4040000             -call 0x4fe970
    cpu.esp -= 4;
    sub_4fe970(app, cpu);
    if (cpu.terminate) return;
    // 004fe4cc  eb1d                   -jmp 0x4fe4eb
    goto L_0x004fe4eb;
L_0x004fe4ce:
    // 004fe4ce  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 004fe4d3  7e16                   -jle 0x4fe4eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe4eb;
    }
    // 004fe4d5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004fe4d7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe4d9  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 004fe4dd  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe4df  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004fe4e3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe4e4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe4e5  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004fe4e9  ebe3                   -jmp 0x4fe4ce
    goto L_0x004fe4ce;
L_0x004fe4eb:
    // 004fe4eb  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 004fe4f0  7e0f                   -jle 0x4fe501
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe501;
    }
    // 004fe4f2  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004fe4f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe4f9  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe4fb  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe4ff  ebea                   -jmp 0x4fe4eb
    goto L_0x004fe4eb;
L_0x004fe501:
    // 004fe501  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 004fe506  7e16                   -jle 0x4fe51e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe51e;
    }
    // 004fe508  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004fe50a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe50c  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 004fe510  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe512  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004fe516  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe517  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe518  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004fe51c  ebe3                   -jmp 0x4fe501
    goto L_0x004fe501;
L_0x004fe51e:
    // 004fe51e  837c243400             +cmp dword ptr [esp + 0x34], 0
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
    // 004fe523  7e0f                   -jle 0x4fe534
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe534;
    }
    // 004fe525  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004fe52a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe52c  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe52e  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe532  ebea                   -jmp 0x4fe51e
    goto L_0x004fe51e;
L_0x004fe534:
    // 004fe534  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004fe539  7407                   -je 0x4fe542
    if (cpu.flags.zf)
    {
        goto L_0x004fe542;
    }
L_0x004fe53b:
    // 004fe53b  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004fe540  7f19                   -jg 0x4fe55b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe55b;
    }
L_0x004fe542:
    // 004fe542  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004fe546  803800                 +cmp byte ptr [eax], 0
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
    // 004fe549  0f85bafcffff           -jne 0x4fe209
    if (!cpu.flags.zf)
    {
        goto L_0x004fe209;
    }
    // 004fe54f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe553  83c470                 +add esp, 0x70
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
    // 004fe556  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe557  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe558  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe559  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe55a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe55b:
    // 004fe55b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004fe560  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe562  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe564  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe568  ebd1                   -jmp 0x4fe53b
    goto L_0x004fe53b;
L_0x004fe56a:
    // 004fe56a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004fe56e  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004fe571  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe572  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe573  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe575  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fe578(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe578  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe579  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe57a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe57b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fe57d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004fe57f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 004fe583  e844010000             -call 0x4fe6cc
    cpu.esp -= 4;
    sub_4fe6cc(app, cpu);
    if (cpu.terminate) return;
    // 004fe588  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004fe58f  80382a                 +cmp byte ptr [eax], 0x2a
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
    // 004fe592  7524                   -jne 0x4fe5b8
    if (!cpu.flags.zf)
    {
        goto L_0x004fe5b8;
    }
    // 004fe594  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe596  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe599  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004fe59b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004fe59e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004fe5a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe5a3  7d10                   -jge 0x4fe5b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fe5b5;
    }
    // 004fe5a5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004fe5a7  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004fe5aa  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004fe5ac  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004fe5af  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004fe5b2  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x004fe5b5:
    // 004fe5b5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe5b6  eb1f                   -jmp 0x4fe5d7
    goto L_0x004fe5d7;
L_0x004fe5b8:
    // 004fe5b8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe5ba  80fa30                 +cmp dl, 0x30
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
    // 004fe5bd  7218                   -jb 0x4fe5d7
    if (cpu.flags.cf)
    {
        goto L_0x004fe5d7;
    }
    // 004fe5bf  80fa39                 +cmp dl, 0x39
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
    // 004fe5c2  7713                   -ja 0x4fe5d7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fe5d7;
    }
    // 004fe5c4  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004fe5c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe5ca  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe5cc  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004fe5cf  01d1                   +add ecx, edx
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
    // 004fe5d1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe5d2  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004fe5d5  ebe1                   -jmp 0x4fe5b8
    goto L_0x004fe5b8;
L_0x004fe5d7:
    // 004fe5d7  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004fe5de  80382e                 +cmp byte ptr [eax], 0x2e
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
    // 004fe5e1  7554                   -jne 0x4fe637
    if (!cpu.flags.zf)
    {
        goto L_0x004fe637;
    }
    // 004fe5e3  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004fe5ea  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004fe5ed  40                     -inc eax
    (cpu.eax)++;
    // 004fe5ee  80fd2a                 +cmp ch, 0x2a
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
    // 004fe5f1  751b                   -jne 0x4fe60e
    if (!cpu.flags.zf)
    {
        goto L_0x004fe60e;
    }
    // 004fe5f3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004fe5f5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe5f8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004fe5fa  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004fe5fd  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004fe600  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe602  7d07                   -jge 0x4fe60b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fe60b;
    }
    // 004fe604  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x004fe60b:
    // 004fe60b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe60c  eb1f                   -jmp 0x4fe62d
    goto L_0x004fe62d;
L_0x004fe60e:
    // 004fe60e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe610  80fa30                 +cmp dl, 0x30
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
    // 004fe613  7218                   -jb 0x4fe62d
    if (cpu.flags.cf)
    {
        goto L_0x004fe62d;
    }
    // 004fe615  80fa39                 +cmp dl, 0x39
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
    // 004fe618  7713                   -ja 0x4fe62d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004fe62d;
    }
    // 004fe61a  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004fe61e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe620  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe622  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004fe625  01d1                   +add ecx, edx
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
    // 004fe627  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe628  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004fe62b  ebe1                   -jmp 0x4fe60e
    goto L_0x004fe60e;
L_0x004fe62d:
    // 004fe62d  837b08ff               +cmp dword ptr [ebx + 8], -1
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
    // 004fe631  7404                   -je 0x4fe637
    if (cpu.flags.zf)
    {
        goto L_0x004fe637;
    }
    // 004fe633  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x004fe637:
    // 004fe637  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe639  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004fe63c  80fa4e                 +cmp dl, 0x4e
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
    // 004fe63f  721f                   -jb 0x4fe660
    if (cpu.flags.cf)
    {
        goto L_0x004fe660;
    }
    // 004fe641  0f867b000000           -jbe 0x4fe6c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fe6c2;
    }
    // 004fe647  80fa6c                 +cmp dl, 0x6c
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
    // 004fe64a  720b                   -jb 0x4fe657
    if (cpu.flags.cf)
    {
        goto L_0x004fe657;
    }
    // 004fe64c  762b                   -jbe 0x4fe679
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fe679;
    }
    // 004fe64e  80fa77                 +cmp dl, 0x77
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
    // 004fe651  7426                   -je 0x4fe679
    if (cpu.flags.zf)
    {
        goto L_0x004fe679;
    }
    // 004fe653  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe654  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe655  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe656  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe657:
    // 004fe657  80fa68                 +cmp dl, 0x68
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
    // 004fe65a  742b                   -je 0x4fe687
    if (cpu.flags.zf)
    {
        goto L_0x004fe687;
    }
    // 004fe65c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe65d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe65e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe65f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe660:
    // 004fe660  80fa49                 +cmp dl, 0x49
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
    // 004fe663  720b                   -jb 0x4fe670
    if (cpu.flags.cf)
    {
        goto L_0x004fe670;
    }
    // 004fe665  7626                   -jbe 0x4fe68d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fe68d;
    }
    // 004fe667  80fa4c                 +cmp dl, 0x4c
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
    // 004fe66a  743d                   -je 0x4fe6a9
    if (cpu.flags.zf)
    {
        goto L_0x004fe6a9;
    }
    // 004fe66c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe66d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe66e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe66f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe670:
    // 004fe670  80fa46                 +cmp dl, 0x46
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
    // 004fe673  7443                   -je 0x4fe6b8
    if (cpu.flags.zf)
    {
        goto L_0x004fe6b8;
    }
    // 004fe675  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe676  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe677  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe678  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe679:
    // 004fe679  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004fe67c  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004fe67f  40                     -inc eax
    (cpu.eax)++;
    // 004fe680  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004fe683  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe684  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe686  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe687:
    // 004fe687  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004fe68b  eb39                   -jmp 0x4fe6c6
    goto L_0x004fe6c6;
L_0x004fe68d:
    // 004fe68d  80780136               +cmp byte ptr [eax + 1], 0x36
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
    // 004fe691  7535                   -jne 0x4fe6c8
    if (!cpu.flags.zf)
    {
        goto L_0x004fe6c8;
    }
    // 004fe693  80780234               +cmp byte ptr [eax + 2], 0x34
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
    // 004fe697  752f                   -jne 0x4fe6c8
    if (!cpu.flags.zf)
    {
        goto L_0x004fe6c8;
    }
    // 004fe699  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004fe69c  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004fe69f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004fe6a2  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 004fe6a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe6a9:
    // 004fe6a9  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004fe6ac  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004fe6af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fe6b1  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 004fe6b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe6b8:
    // 004fe6b8  804b1e80               -or byte ptr [ebx + 0x1e], 0x80
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004fe6bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fe6be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe6c2:
    // 004fe6c2  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004fe6c6:
    // 004fe6c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004fe6c8:
    // 004fe6c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe6cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fe6cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe6cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fe6cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe6ce  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004fe6d4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe6d6  80fb2d                 +cmp bl, 0x2d
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
    // 004fe6d9  7506                   -jne 0x4fe6e1
    if (!cpu.flags.zf)
    {
        goto L_0x004fe6e1;
    }
    // 004fe6db  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004fe6df  eb42                   -jmp 0x4fe723
    goto L_0x004fe723;
L_0x004fe6e1:
    // 004fe6e1  80fb23                 +cmp bl, 0x23
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
    // 004fe6e4  7506                   -jne 0x4fe6ec
    if (!cpu.flags.zf)
    {
        goto L_0x004fe6ec;
    }
    // 004fe6e6  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004fe6ea  eb37                   -jmp 0x4fe723
    goto L_0x004fe723;
L_0x004fe6ec:
    // 004fe6ec  80fb2b                 +cmp bl, 0x2b
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
    // 004fe6ef  7513                   -jne 0x4fe704
    if (!cpu.flags.zf)
    {
        goto L_0x004fe704;
    }
    // 004fe6f1  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004fe6f4  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004fe6f7  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 004fe6f9  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 004fe6fc  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 004fe6ff  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 004fe702  eb1f                   -jmp 0x4fe723
    goto L_0x004fe723;
L_0x004fe704:
    // 004fe704  80fb20                 +cmp bl, 0x20
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
    // 004fe707  7512                   -jne 0x4fe71b
    if (!cpu.flags.zf)
    {
        goto L_0x004fe71b;
    }
    // 004fe709  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004fe70c  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004fe70f  7512                   -jne 0x4fe723
    if (!cpu.flags.zf)
    {
        goto L_0x004fe723;
    }
    // 004fe711  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 004fe713  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004fe716  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004fe719  eb08                   -jmp 0x4fe723
    goto L_0x004fe723;
L_0x004fe71b:
    // 004fe71b  80fb30                 +cmp bl, 0x30
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
    // 004fe71e  7511                   -jne 0x4fe731
    if (!cpu.flags.zf)
    {
        goto L_0x004fe731;
    }
    // 004fe720  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x004fe723:
    // 004fe723  40                     -inc eax
    (cpu.eax)++;
    // 004fe724  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004fe726  80fb2d                 +cmp bl, 0x2d
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
    // 004fe729  75b6                   -jne 0x4fe6e1
    if (!cpu.flags.zf)
    {
        goto L_0x004fe6e1;
    }
    // 004fe72b  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004fe72f  ebf2                   -jmp 0x4fe723
    goto L_0x004fe723;
L_0x004fe731:
    // 004fe731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe732  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fe734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe734  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe735  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe737  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe738  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004fe73a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004fe73c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fe73e  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004fe740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004fe742:
    // 004fe742  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004fe744  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 004fe747  42                     -inc edx
    (cpu.edx)++;
    // 004fe748  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004fe74a  7407                   -je 0x4fe753
    if (cpu.flags.zf)
    {
        goto L_0x004fe753;
    }
    // 004fe74c  39f8                   +cmp eax, edi
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
    // 004fe74e  7403                   -je 0x4fe753
    if (cpu.flags.zf)
    {
        goto L_0x004fe753;
    }
    // 004fe750  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe751  ebef                   -jmp 0x4fe742
    goto L_0x004fe742;
L_0x004fe753:
    // 004fe753  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe754  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe755  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe756  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe757  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fe758(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe758  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe759  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe75a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe75b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe75e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fe760  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004fe762  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004fe764  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe766  83feff                 +cmp esi, -1
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
    // 004fe769  7521                   -jne 0x4fe78c
    if (!cpu.flags.zf)
    {
        goto L_0x004fe78c;
    }
L_0x004fe76b:
    // 004fe76b  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004fe76f  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004fe772  7440                   -je 0x4fe7b4
    if (cpu.flags.zf)
    {
        goto L_0x004fe7b4;
    }
    // 004fe774  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe776  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe778  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 004fe77b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe77e  e8ddf80100             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 004fe783  83f8ff                 +cmp eax, -1
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
    // 004fe786  74e3                   -je 0x4fe76b
    if (cpu.flags.zf)
    {
        goto L_0x004fe76b;
    }
    // 004fe788  01c1                   +add ecx, eax
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
    // 004fe78a  ebdf                   -jmp 0x4fe76b
    goto L_0x004fe76b;
L_0x004fe78c:
    // 004fe78c  6626833b00             +cmp word ptr es:[ebx], 0
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
    // 004fe791  741d                   -je 0x4fe7b0
    if (cpu.flags.zf)
    {
        goto L_0x004fe7b0;
    }
    // 004fe793  39f1                   +cmp ecx, esi
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
    // 004fe795  7f19                   -jg 0x4fe7b0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe7b0;
    }
    // 004fe797  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe799  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe79b  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004fe79f  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe7a2  e8b9f80100             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 004fe7a7  83f8ff                 +cmp eax, -1
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
    // 004fe7aa  74e0                   -je 0x4fe78c
    if (cpu.flags.zf)
    {
        goto L_0x004fe78c;
    }
    // 004fe7ac  01c1                   +add ecx, eax
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
    // 004fe7ae  ebdc                   -jmp 0x4fe78c
    goto L_0x004fe78c;
L_0x004fe7b0:
    // 004fe7b0  39f1                   +cmp ecx, esi
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
    // 004fe7b2  7f04                   -jg 0x4fe7b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe7b8;
    }
L_0x004fe7b4:
    // 004fe7b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fe7b6  eb02                   -jmp 0x4fe7ba
    goto L_0x004fe7ba;
L_0x004fe7b8:
    // 004fe7b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004fe7ba:
    // 004fe7ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe7bd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe7be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe7bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe7c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fe7c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe7c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe7c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe7c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe7c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe7c8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe7cb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004fe7cd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004fe7d0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004fe7d5  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004fe7d7  e810f90100             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004fe7dc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe7dd  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004fe7df  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004fe7e1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe7e3  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe7e4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fe7e6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004fe7e8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004fe7ea  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe7eb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe7ec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004fe7ef  48                     -dec eax
    (cpu.eax)--;
    // 004fe7f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fe7f2  7415                   -je 0x4fe809
    if (cpu.flags.zf)
    {
        goto L_0x004fe809;
    }
    // 004fe7f4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004fe7f6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004fe7f9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x004fe7fc:
    // 004fe7fc  4b                     -dec ebx
    (cpu.ebx)--;
    // 004fe7fd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004fe800  4a                     -dec edx
    (cpu.edx)--;
    // 004fe801  48                     -dec eax
    (cpu.eax)--;
    // 004fe802  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004fe805  39f2                   +cmp edx, esi
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
    // 004fe807  75f3                   -jne 0x4fe7fc
    if (!cpu.flags.zf)
    {
        goto L_0x004fe7fc;
    }
L_0x004fe809:
    // 004fe809  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x004fe80c:
    // 004fe80c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fe80e  7c07                   -jl 0x4fe817
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fe817;
    }
    // 004fe810  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe811  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 004fe814  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe815  ebf5                   -jmp 0x4fe80c
    goto L_0x004fe80c;
L_0x004fe817:
    // 004fe817  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004fe81a  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 004fe81e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe821  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe822  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe823  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe824  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe825  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fe81e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004fe81e;
    // 004fe7c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe7c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe7c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe7c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe7c8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe7cb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004fe7cd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004fe7d0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004fe7d5  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004fe7d7  e810f90100             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004fe7dc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe7dd  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004fe7df  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004fe7e1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe7e3  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe7e4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fe7e6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004fe7e8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004fe7ea  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe7eb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe7ec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004fe7ef  48                     -dec eax
    (cpu.eax)--;
    // 004fe7f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004fe7f2  7415                   -je 0x4fe809
    if (cpu.flags.zf)
    {
        goto L_0x004fe809;
    }
    // 004fe7f4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004fe7f6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004fe7f9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x004fe7fc:
    // 004fe7fc  4b                     -dec ebx
    (cpu.ebx)--;
    // 004fe7fd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004fe800  4a                     -dec edx
    (cpu.edx)--;
    // 004fe801  48                     -dec eax
    (cpu.eax)--;
    // 004fe802  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004fe805  39f2                   +cmp edx, esi
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
    // 004fe807  75f3                   -jne 0x4fe7fc
    if (!cpu.flags.zf)
    {
        goto L_0x004fe7fc;
    }
L_0x004fe809:
    // 004fe809  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x004fe80c:
    // 004fe80c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fe80e  7c07                   -jl 0x4fe817
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fe817;
    }
    // 004fe810  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe811  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 004fe814  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe815  ebf5                   -jmp 0x4fe80c
    goto L_0x004fe80c;
L_0x004fe817:
    // 004fe817  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004fe81a  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
L_entry_0x004fe81e:
    // 004fe81e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe821  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe822  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe823  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe824  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe825  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4fe828(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe828  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe829  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe82a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe82b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe82c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe82f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fe831  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004fe833  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fe836  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe838  7d0b                   -jge 0x4fe845
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fe845;
    }
    // 004fe83a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004fe83c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004fe83f  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 004fe842  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004fe845:
    // 004fe845  837e08ff               +cmp dword ptr [esi + 8], -1
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
    // 004fe849  7507                   -jne 0x4fe852
    if (!cpu.flags.zf)
    {
        goto L_0x004fe852;
    }
    // 004fe84b  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x004fe852:
    // 004fe852  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004fe857  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fe859  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004fe85b  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004fe860  e887f80100             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 004fe865  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004fe867  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fe869  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004fe86b  7408                   -je 0x4fe875
    if (cpu.flags.zf)
    {
        goto L_0x004fe875;
    }
L_0x004fe86d:
    // 004fe86d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004fe870  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe871  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004fe873  75f8                   -jne 0x4fe86d
    if (!cpu.flags.zf)
    {
        goto L_0x004fe86d;
    }
L_0x004fe875:
    // 004fe875  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004fe879  7432                   -je 0x4fe8ad
    if (cpu.flags.zf)
    {
        goto L_0x004fe8ad;
    }
    // 004fe87b  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 004fe87e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fe880  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004fe883  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe884  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fe886  7e22                   -jle 0x4fe8aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe8aa;
    }
L_0x004fe888:
    // 004fe888  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe88a  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004fe88f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004fe892  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004fe895  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004fe898  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004fe89c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004fe89f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004fe8a1  40                     -inc eax
    (cpu.eax)++;
    // 004fe8a2  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004fe8a5  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8a6  39e8                   +cmp eax, ebp
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
    // 004fe8a8  7cde                   -jl 0x4fe888
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fe888;
    }
L_0x004fe8aa:
    // 004fe8aa  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004fe8ad:
    // 004fe8ad  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 004fe8b2  0f8466ffffff           -je 0x4fe81e
    if (cpu.flags.zf)
    {
        return sub_4fe81e(app, cpu);
    }
L_0x004fe8b8:
    // 004fe8b8  39d9                   +cmp ecx, ebx
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
    // 004fe8ba  7541                   -jne 0x4fe8fd
    if (!cpu.flags.zf)
    {
        goto L_0x004fe8fd;
    }
    // 004fe8bc  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004fe8bf  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
    // 004fe8c2  803930                 +cmp byte ptr [ecx], 0x30
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
    // 004fe8c5  7508                   -jne 0x4fe8cf
    if (!cpu.flags.zf)
    {
        goto L_0x004fe8cf;
    }
L_0x004fe8c7:
    // 004fe8c7  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004fe8ca  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8cb  3c30                   +cmp al, 0x30
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
    // 004fe8cd  74f8                   -je 0x4fe8c7
    if (cpu.flags.zf)
    {
        goto L_0x004fe8c7;
    }
L_0x004fe8cf:
    // 004fe8cf  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004fe8d1  80fc2e                 +cmp ah, 0x2e
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
    // 004fe8d4  7518                   -jne 0x4fe8ee
    if (!cpu.flags.zf)
    {
        goto L_0x004fe8ee;
    }
    // 004fe8d6  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004fe8d9  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8da  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 004fe8dc  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004fe8df  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8e0  80fa30                 +cmp dl, 0x30
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
    // 004fe8e3  7509                   -jne 0x4fe8ee
    if (!cpu.flags.zf)
    {
        goto L_0x004fe8ee;
    }
L_0x004fe8e5:
    // 004fe8e5  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004fe8e8  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8e9  80fe30                 +cmp dh, 0x30
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
    // 004fe8ec  74f7                   -je 0x4fe8e5
    if (cpu.flags.zf)
    {
        goto L_0x004fe8e5;
    }
L_0x004fe8ee:
    // 004fe8ee  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004fe8f1  41                     -inc ecx
    (cpu.ecx)++;
    // 004fe8f2  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 004fe8f5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe8f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe8f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe8fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe8fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe8fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe8fd:
    // 004fe8fd  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004fe900  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe901  80fa2e                 +cmp dl, 0x2e
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
    // 004fe904  7501                   -jne 0x4fe907
    if (!cpu.flags.zf)
    {
        goto L_0x004fe907;
    }
    // 004fe906  49                     -dec ecx
    (cpu.ecx)--;
L_0x004fe907:
    // 004fe907  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004fe909  80fe39                 +cmp dh, 0x39
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
    // 004fe90c  740e                   -je 0x4fe91c
    if (cpu.flags.zf)
    {
        goto L_0x004fe91c;
    }
    // 004fe90e  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004fe910  fec3                   -inc bl
    (cpu.bl)++;
    // 004fe912  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 004fe914  83c404                 +add esp, 4
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
    // 004fe917  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe918  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe919  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe91a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe91b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fe91c:
    // 004fe91c  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004fe91f  eb97                   -jmp 0x4fe8b8
    goto L_0x004fe8b8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fe924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe924  ff1564ac5600           -call dword ptr [0x56ac64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680228) /* 0x56ac64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe92a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fe92c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe92c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fe92d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fe92e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fe92f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe930  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe931  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe932  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004fe936  7530                   -jne 0x4fe968
    if (!cpu.flags.zf)
    {
        goto L_0x004fe968;
    }
    // 004fe938  80781630               +cmp byte ptr [eax + 0x16], 0x30
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
    // 004fe93c  752a                   -jne 0x4fe968
    if (!cpu.flags.zf)
    {
        goto L_0x004fe968;
    }
    // 004fe93e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004fe941  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004fe944  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004fe947  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fe949  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004fe94c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004fe94e  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004fe951  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004fe953  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004fe956  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004fe958  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004fe95b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004fe95d  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004fe95f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe961  7e05                   -jle 0x4fe968
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe968;
    }
    // 004fe963  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004fe965  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x004fe968:
    // 004fe968  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe969  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe96a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe96b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe96c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe96d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe96e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4fe970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe972  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe973  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe974  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe977  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004fe979  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fe97b  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004fe97e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004fe980  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fe982  7e45                   -jle 0x4fe9c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fe9c9;
    }
L_0x004fe984:
    // 004fe984  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fe986  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004fe988  66268b17               -mov dx, word ptr es:[edi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.edi);
    // 004fe98c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004fe98f  e8ccf60100             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 004fe994  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fe996  83f8ff                 +cmp eax, -1
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
    // 004fe999  740d                   -je 0x4fe9a8
    if (cpu.flags.zf)
    {
        goto L_0x004fe9a8;
    }
    // 004fe99b  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
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
    // 004fe99e  7f22                   -jg 0x4fe9c2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe9c2;
    }
    // 004fe9a0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004fe9a2:
    // 004fe9a2  49                     -dec ecx
    (cpu.ecx)--;
    // 004fe9a3  83f9ff                 +cmp ecx, -1
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
    // 004fe9a6  7508                   -jne 0x4fe9b0
    if (!cpu.flags.zf)
    {
        goto L_0x004fe9b0;
    }
L_0x004fe9a8:
    // 004fe9a8  837b2800               +cmp dword ptr [ebx + 0x28], 0
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
    // 004fe9ac  7fd6                   -jg 0x4fe984
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004fe984;
    }
    // 004fe9ae  eb19                   -jmp 0x4fe9c9
    goto L_0x004fe9c9;
L_0x004fe9b0:
    // 004fe9b0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004fe9b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004fe9b4  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004fe9b6  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fe9b8  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004fe9bb  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004fe9bc  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fe9bd  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004fe9c0  ebe0                   -jmp 0x4fe9a2
    goto L_0x004fe9a2;
L_0x004fe9c2:
    // 004fe9c2  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x004fe9c9:
    // 004fe9c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fe9cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe9cd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fe9ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe9cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fe9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fe9d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fe9d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fe9d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fe9d6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004fe9d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004fe9d8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fe9db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004fe9dd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004fe9df  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004fe9e1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004fe9e3  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004fe9ea  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004fe9f1  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004fe9f8  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004fe9ff  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004fea06  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004fea08  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004fea0b  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004fea12  3c69                   +cmp al, 0x69
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
    // 004fea14  721e                   -jb 0x4fea34
    if (cpu.flags.cf)
    {
        goto L_0x004fea34;
    }
    // 004fea16  0f8692000000           -jbe 0x4feaae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004feaae;
    }
    // 004fea1c  3c75                   +cmp al, 0x75
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
    // 004fea1e  720b                   -jb 0x4fea2b
    if (cpu.flags.cf)
    {
        goto L_0x004fea2b;
    }
    // 004fea20  7625                   -jbe 0x4fea47
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fea47;
    }
    // 004fea22  3c78                   +cmp al, 0x78
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
    // 004fea24  7421                   -je 0x4fea47
    if (cpu.flags.zf)
    {
        goto L_0x004fea47;
    }
    // 004fea26  e960010000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004fea2b:
    // 004fea2b  3c6f                   +cmp al, 0x6f
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
    // 004fea2d  7418                   -je 0x4fea47
    if (cpu.flags.zf)
    {
        goto L_0x004fea47;
    }
    // 004fea2f  e957010000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004fea34:
    // 004fea34  3c58                   +cmp al, 0x58
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
    // 004fea36  0f824f010000           -jb 0x4feb8b
    if (cpu.flags.cf)
    {
        goto L_0x004feb8b;
    }
    // 004fea3c  7609                   -jbe 0x4fea47
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fea47;
    }
    // 004fea3e  3c64                   +cmp al, 0x64
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
    // 004fea40  746c                   -je 0x4feaae
    if (cpu.flags.zf)
    {
        goto L_0x004feaae;
    }
    // 004fea42  e944010000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004fea47:
    // 004fea47  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004fea4b  7420                   -je 0x4fea6d
    if (cpu.flags.zf)
    {
        goto L_0x004fea6d;
    }
    // 004fea4d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004fea4f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fea52  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004fea54  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004fea57  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004fea5a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004fea5c  83c504                 +add ebp, 4
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
    // 004fea5f  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004fea61  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004fea64  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004fea68  e91e010000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004fea6d:
    // 004fea6d  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004fea71  7413                   -je 0x4fea86
    if (cpu.flags.zf)
    {
        goto L_0x004fea86;
    }
    // 004fea73  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004fea75  83c004                 +add eax, 4
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
    // 004fea78  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fea7a  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004fea7d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fea81  e905010000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004fea86:
    // 004fea86  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004fea88  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fea8b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004fea8d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004fea90  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fea94  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004fea98  0f84ed000000           -je 0x4feb8b
    if (cpu.flags.zf)
    {
        goto L_0x004feb8b;
    }
    // 004fea9e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004feaa0  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004feaa5  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004feaa9  e9dd000000             -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004feaae:
    // 004feaae  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004feab2  741d                   -je 0x4fead1
    if (cpu.flags.zf)
    {
        goto L_0x004fead1;
    }
    // 004feab4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004feab6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004feab9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004feabb  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004feabe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004feac1  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004feac3  83c304                 +add ebx, 4
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
    // 004feac6  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004feac8  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004feacb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004feacf  eb33                   -jmp 0x4feb04
    goto L_0x004feb04;
L_0x004fead1:
    // 004fead1  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004fead5  740c                   -je 0x4feae3
    if (cpu.flags.zf)
    {
        goto L_0x004feae3;
    }
    // 004fead7  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004fead9  83c504                 +add ebp, 4
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
    // 004feadc  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004feade  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004feae1  eb1d                   -jmp 0x4feb00
    goto L_0x004feb00;
L_0x004feae3:
    // 004feae3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004feae5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004feae8  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004feaea  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004feaed  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004feaf0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004feaf4  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004feaf7  740b                   -je 0x4feb04
    if (cpu.flags.zf)
    {
        goto L_0x004feb04;
    }
    // 004feaf9  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004feafd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x004feb00:
    // 004feb00  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004feb04:
    // 004feb04  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004feb07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004feb09  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004feb0c  7409                   -je 0x4feb17
    if (cpu.flags.zf)
    {
        goto L_0x004feb17;
    }
    // 004feb0e  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004feb13  7409                   -je 0x4feb1e
    if (cpu.flags.zf)
    {
        goto L_0x004feb1e;
    }
    // 004feb15  eb0b                   -jmp 0x4feb22
    goto L_0x004feb22;
L_0x004feb17:
    // 004feb17  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004feb1c  7c04                   -jl 0x4feb22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004feb22;
    }
L_0x004feb1e:
    // 004feb1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004feb20  7442                   -je 0x4feb64
    if (cpu.flags.zf)
    {
        goto L_0x004feb64;
    }
L_0x004feb22:
    // 004feb22  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004feb25  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004feb28  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004feb2b  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004feb2f  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004feb33  7429                   -je 0x4feb5e
    if (cpu.flags.zf)
    {
        goto L_0x004feb5e;
    }
    // 004feb35  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004feb38  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004feb3c  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004feb3e  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 004feb40  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004feb43  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004feb46  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004feb4a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004feb4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004feb4f  7505                   -jne 0x4feb56
    if (!cpu.flags.zf)
    {
        goto L_0x004feb56;
    }
    // 004feb51  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004feb54  eb02                   -jmp 0x4feb58
    goto L_0x004feb58;
L_0x004feb56:
    // 004feb56  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004feb58:
    // 004feb58  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004feb5c  eb2d                   -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004feb5e:
    // 004feb5e  f75c2408               +neg dword ptr [esp + 8]
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
    // 004feb62  eb27                   -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004feb64:
    // 004feb64  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004feb67  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004feb69  740f                   -je 0x4feb7a
    if (cpu.flags.zf)
    {
        goto L_0x004feb7a;
    }
    // 004feb6b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004feb6e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004feb71  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004feb74  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004feb78  eb11                   -jmp 0x4feb8b
    goto L_0x004feb8b;
L_0x004feb7a:
    // 004feb7a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004feb7c  740d                   -je 0x4feb8b
    if (cpu.flags.zf)
    {
        goto L_0x004feb8b;
    }
    // 004feb7e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004feb81  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004feb84  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004feb87  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004feb8b:
    // 004feb8b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004feb8e  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004feb93  3c64                   +cmp al, 0x64
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
    // 004feb95  7261                   -jb 0x4febf8
    if (cpu.flags.cf)
    {
        goto L_0x004febf8;
    }
    // 004feb97  0f860b020000           -jbe 0x4feda8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004feda8;
    }
    // 004feb9d  3c6f                   +cmp al, 0x6f
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
    // 004feb9f  7238                   -jb 0x4febd9
    if (cpu.flags.cf)
    {
        goto L_0x004febd9;
    }
    // 004feba1  0f86e1010000           -jbe 0x4fed88
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fed88;
    }
    // 004feba7  3c73                   +cmp al, 0x73
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
    // 004feba9  7221                   -jb 0x4febcc
    if (cpu.flags.cf)
    {
        goto L_0x004febcc;
    }
    // 004febab  0f86f0000000           -jbe 0x4feca1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004feca1;
    }
    // 004febb1  3c75                   +cmp al, 0x75
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
    // 004febb3  0f8204040000           -jb 0x4fefbd
    if (cpu.flags.cf)
    {
        goto L_0x004fefbd;
    }
    // 004febb9  0f86e9010000           -jbe 0x4feda8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004feda8;
    }
    // 004febbf  3c78                   +cmp al, 0x78
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
    // 004febc1  0f847c010000           -je 0x4fed43
    if (cpu.flags.zf)
    {
        goto L_0x004fed43;
    }
    // 004febc7  e9f1030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004febcc:
    // 004febcc  3c70                   +cmp al, 0x70
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
    // 004febce  0f8489020000           -je 0x4fee5d
    if (cpu.flags.zf)
    {
        goto L_0x004fee5d;
    }
    // 004febd4  e9e4030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004febd9:
    // 004febd9  3c66                   +cmp al, 0x66
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
    // 004febdb  0f829d000000           -jb 0x4fec7e
    if (cpu.flags.cf)
    {
        goto L_0x004fec7e;
    }
    // 004febe1  7666                   -jbe 0x4fec49
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fec49;
    }
    // 004febe3  3c67                   +cmp al, 0x67
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
    // 004febe5  0f8693000000           -jbe 0x4fec7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fec7e;
    }
    // 004febeb  3c69                   +cmp al, 0x69
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
    // 004febed  0f84b5010000           -je 0x4feda8
    if (cpu.flags.zf)
    {
        goto L_0x004feda8;
    }
    // 004febf3  e9c5030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004febf8:
    // 004febf8  3c47                   +cmp al, 0x47
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
    // 004febfa  7238                   -jb 0x4fec34
    if (cpu.flags.cf)
    {
        goto L_0x004fec34;
    }
    // 004febfc  0f867c000000           -jbe 0x4fec7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fec7e;
    }
    // 004fec02  3c53                   +cmp al, 0x53
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
    // 004fec04  7221                   -jb 0x4fec27
    if (cpu.flags.cf)
    {
        goto L_0x004fec27;
    }
    // 004fec06  0f8695000000           -jbe 0x4feca1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004feca1;
    }
    // 004fec0c  3c58                   +cmp al, 0x58
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
    // 004fec0e  0f82a9030000           -jb 0x4fefbd
    if (cpu.flags.cf)
    {
        goto L_0x004fefbd;
    }
    // 004fec14  0f8629010000           -jbe 0x4fed43
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fed43;
    }
    // 004fec1a  3c63                   +cmp al, 0x63
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
    // 004fec1c  0f84ce020000           -je 0x4feef0
    if (cpu.flags.zf)
    {
        goto L_0x004feef0;
    }
    // 004fec22  e996030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004fec27:
    // 004fec27  3c50                   +cmp al, 0x50
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
    // 004fec29  0f842e020000           -je 0x4fee5d
    if (cpu.flags.zf)
    {
        goto L_0x004fee5d;
    }
    // 004fec2f  e989030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004fec34:
    // 004fec34  3c45                   +cmp al, 0x45
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
    // 004fec36  7204                   -jb 0x4fec3c
    if (cpu.flags.cf)
    {
        goto L_0x004fec3c;
    }
    // 004fec38  7644                   -jbe 0x4fec7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004fec7e;
    }
    // 004fec3a  eb0d                   -jmp 0x4fec49
    goto L_0x004fec49;
L_0x004fec3c:
    // 004fec3c  3c43                   +cmp al, 0x43
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
    // 004fec3e  0f8438030000           -je 0x4fef7c
    if (cpu.flags.zf)
    {
        goto L_0x004fef7c;
    }
    // 004fec44  e974030000             -jmp 0x4fefbd
    goto L_0x004fefbd;
L_0x004fec49:
    // 004fec49  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004fec4d  742f                   -je 0x4fec7e
    if (cpu.flags.zf)
    {
        goto L_0x004fec7e;
    }
    // 004fec4f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004fec51  83c304                 +add ebx, 4
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
    // 004fec54  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004fec56  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004fec59  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004fec5d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fec5f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fec61  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fec63  e8c0fbffff             -call 0x4fe828
    cpu.esp -= 4;
    sub_4fe828(app, cpu);
    if (cpu.terminate) return;
    // 004fec68  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004fec6d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004fec6f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fec71  e8befaffff             -call 0x4fe734
    cpu.esp -= 4;
    sub_4fe734(app, cpu);
    if (cpu.terminate) return;
    // 004fec76  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004fec79  e952030000             -jmp 0x4fefd0
    goto L_0x004fefd0;
L_0x004fec7e:
    // 004fec7e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004fec80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fec82  e89dfcffff             -call 0x4fe924
    cpu.esp -= 4;
    sub_4fe924(app, cpu);
    if (cpu.terminate) return;
    // 004fec87  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fec89  e89efcffff             -call 0x4fe92c
    cpu.esp -= 4;
    sub_4fe92c(app, cpu);
    if (cpu.terminate) return;
    // 004fec8e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004fec90  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004fec93  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004fec95  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fec97  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fec99  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fec9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fec9d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fec9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fec9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feca0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004feca1:
    // 004feca1  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004feca4  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004feca7  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004feca9  741d                   -je 0x4fecc8
    if (cpu.flags.zf)
    {
        goto L_0x004fecc8;
    }
    // 004fecab  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004fecad  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004fecb0  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004fecb2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004fecb5  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004fecb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fecbb  7505                   -jne 0x4fecc2
    if (!cpu.flags.zf)
    {
        goto L_0x004fecc2;
    }
    // 004fecbd  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004fecc0  742e                   -je 0x4fecf0
    if (cpu.flags.zf)
    {
        goto L_0x004fecf0;
    }
L_0x004fecc2:
    // 004fecc2  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004fecc4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fecc6  eb28                   -jmp 0x4fecf0
    goto L_0x004fecf0;
L_0x004fecc8:
    // 004fecc8  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004fecca  7410                   -je 0x4fecdc
    if (cpu.flags.zf)
    {
        goto L_0x004fecdc;
    }
    // 004feccc  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004fecce  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fecd1  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004fecd3  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004fecd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fecd8  7416                   -je 0x4fecf0
    if (cpu.flags.zf)
    {
        goto L_0x004fecf0;
    }
    // 004fecda  eb0e                   -jmp 0x4fecea
    goto L_0x004fecea;
L_0x004fecdc:
    // 004fecdc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004fecde  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fece1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004fece3  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004fece6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004fece8  7406                   -je 0x4fecf0
    if (cpu.flags.zf)
    {
        goto L_0x004fecf0;
    }
L_0x004fecea:
    // 004fecea  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004fecec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fecee  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x004fecf0:
    // 004fecf0  80791553               +cmp byte ptr [ecx + 0x15], 0x53
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
    // 004fecf4  7508                   -jne 0x4fecfe
    if (!cpu.flags.zf)
    {
        goto L_0x004fecfe;
    }
    // 004fecf6  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004fecfa  7408                   -je 0x4fed04
    if (cpu.flags.zf)
    {
        goto L_0x004fed04;
    }
    // 004fecfc  eb14                   -jmp 0x4fed12
    goto L_0x004fed12;
L_0x004fecfe:
    // 004fecfe  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004fed02  740e                   -je 0x4fed12
    if (cpu.flags.zf)
    {
        goto L_0x004fed12;
    }
L_0x004fed04:
    // 004fed04  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fed06  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fed08  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004fed0b  e848faffff             -call 0x4fe758
    cpu.esp -= 4;
    sub_4fe758(app, cpu);
    if (cpu.terminate) return;
    // 004fed10  eb0c                   -jmp 0x4fed1e
    goto L_0x004fed1e;
L_0x004fed12:
    // 004fed12  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fed14  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fed16  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004fed19  e816faffff             -call 0x4fe734
    cpu.esp -= 4;
    sub_4fe734(app, cpu);
    if (cpu.terminate) return;
L_0x004fed1e:
    // 004fed1e  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004fed21  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004fed24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fed26  0f8ca4020000           -jl 0x4fefd0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004fefd0;
    }
    // 004fed2c  39d0                   +cmp eax, edx
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
    // 004fed2e  0f8e9c020000           -jle 0x4fefd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004fefd0;
    }
    // 004fed34  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004fed37  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fed39  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fed3b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fed3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fed3f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fed40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fed41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fed42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fed43:
    // 004fed43  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004fed47  743a                   -je 0x4fed83
    if (cpu.flags.zf)
    {
        goto L_0x004fed83;
    }
    // 004fed49  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004fed4d  740f                   -je 0x4fed5e
    if (cpu.flags.zf)
    {
        goto L_0x004fed5e;
    }
    // 004fed4f  833c2400               +cmp dword ptr [esp], 0
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
    // 004fed53  7510                   -jne 0x4fed65
    if (!cpu.flags.zf)
    {
        goto L_0x004fed65;
    }
    // 004fed55  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004fed5a  7427                   -je 0x4fed83
    if (cpu.flags.zf)
    {
        goto L_0x004fed83;
    }
    // 004fed5c  eb07                   -jmp 0x4fed65
    goto L_0x004fed65;
L_0x004fed5e:
    // 004fed5e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004fed63  741e                   -je 0x4fed83
    if (cpu.flags.zf)
    {
        goto L_0x004fed83;
    }
L_0x004fed65:
    // 004fed65  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fed68  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004fed6b  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004fed6e  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 004fed72  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fed75  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004fed78  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004fed7b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004fed7e  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004fed81  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x004fed83:
    // 004fed83  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004fed88:
    // 004fed88  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
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
    // 004fed8c  751a                   -jne 0x4feda8
    if (!cpu.flags.zf)
    {
        goto L_0x004feda8;
    }
    // 004fed8e  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004fed91  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004fed96  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004fed99  740d                   -je 0x4feda8
    if (cpu.flags.zf)
    {
        goto L_0x004feda8;
    }
    // 004fed9b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fed9e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004feda1  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004feda4  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x004feda8:
    // 004feda8  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004fedaa  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fedad  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004fedaf  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fedb1  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004fedb4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004fedb6  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004fedb9  7436                   -je 0x4fedf1
    if (cpu.flags.zf)
    {
        goto L_0x004fedf1;
    }
    // 004fedbb  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 004fedbf  7515                   -jne 0x4fedd6
    if (!cpu.flags.zf)
    {
        goto L_0x004fedd6;
    }
    // 004fedc1  833c2400               +cmp dword ptr [esp], 0
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
    // 004fedc5  750f                   -jne 0x4fedd6
    if (!cpu.flags.zf)
    {
        goto L_0x004fedd6;
    }
    // 004fedc7  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004fedcc  7508                   -jne 0x4fedd6
    if (!cpu.flags.zf)
    {
        goto L_0x004fedd6;
    }
    // 004fedce  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 004fedd2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fedd4  eb59                   -jmp 0x4fee2f
    goto L_0x004fee2f;
L_0x004fedd6:
    // 004fedd6  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fedd9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004feddb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004feddd  e84ef30100             -call 0x51e130
    cpu.esp -= 4;
    sub_51e130(app, cpu);
    if (cpu.terminate) return;
    // 004fede2  80791558               +cmp byte ptr [ecx + 0x15], 0x58
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
    // 004fede6  7539                   -jne 0x4fee21
    if (!cpu.flags.zf)
    {
        goto L_0x004fee21;
    }
    // 004fede8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fedea  e8ed010000             -call 0x4fefdc
    cpu.esp -= 4;
    sub_4fefdc(app, cpu);
    if (cpu.terminate) return;
    // 004fedef  eb30                   -jmp 0x4fee21
    goto L_0x004fee21;
L_0x004fedf1:
    // 004fedf1  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 004fedf5  750f                   -jne 0x4fee06
    if (!cpu.flags.zf)
    {
        goto L_0x004fee06;
    }
    // 004fedf7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004fedfc  7508                   -jne 0x4fee06
    if (!cpu.flags.zf)
    {
        goto L_0x004fee06;
    }
    // 004fedfe  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 004fee02  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004fee04  eb29                   -jmp 0x4fee2f
    goto L_0x004fee2f;
L_0x004fee06:
    // 004fee06  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004fee09  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fee0d  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004fee0f  e80cf40100             -call 0x51e220
    cpu.esp -= 4;
    sub_51e220(app, cpu);
    if (cpu.terminate) return;
    // 004fee14  80791558               +cmp byte ptr [ecx + 0x15], 0x58
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
    // 004fee18  7507                   -jne 0x4fee21
    if (!cpu.flags.zf)
    {
        goto L_0x004fee21;
    }
    // 004fee1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fee1c  e8bb010000             -call 0x4fefdc
    cpu.esp -= 4;
    sub_4fefdc(app, cpu);
    if (cpu.terminate) return;
L_0x004fee21:
    // 004fee21  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004fee26  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fee28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fee2a  e805f9ffff             -call 0x4fe734
    cpu.esp -= 4;
    sub_4fe734(app, cpu);
    if (cpu.terminate) return;
L_0x004fee2f:
    // 004fee2f  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004fee32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fee34  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004fee37  39c2                   +cmp edx, eax
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
    // 004fee39  7d05                   -jge 0x4fee40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004fee40;
    }
    // 004fee3b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004fee3d  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004fee40:
    // 004fee40  837908ff               +cmp dword ptr [ecx + 8], -1
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
    // 004fee44  0f8586010000           -jne 0x4fefd0
    if (!cpu.flags.zf)
    {
        goto L_0x004fefd0;
    }
    // 004fee4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fee4c  e8dbfaffff             -call 0x4fe92c
    cpu.esp -= 4;
    sub_4fe92c(app, cpu);
    if (cpu.terminate) return;
    // 004fee51  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fee53  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fee55  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fee58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fee59  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fee5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fee5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fee5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fee5d:
    // 004fee5d  83790400               +cmp dword ptr [ecx + 4], 0
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
    // 004fee61  7516                   -jne 0x4fee79
    if (!cpu.flags.zf)
    {
        goto L_0x004fee79;
    }
    // 004fee63  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 004fee67  7409                   -je 0x4fee72
    if (cpu.flags.zf)
    {
        goto L_0x004fee72;
    }
    // 004fee69  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 004fee70  eb07                   -jmp 0x4fee79
    goto L_0x004fee79;
L_0x004fee72:
    // 004fee72  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x004fee79:
    // 004fee79  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004fee7d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004fee7f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fee82  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fee84  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004fee87  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004fee8a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004fee8d  7429                   -je 0x4feeb8
    if (cpu.flags.zf)
    {
        goto L_0x004feeb8;
    }
    // 004fee8f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fee92  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fee94  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004fee99  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004fee9c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004fee9e  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004feea3  e81cf9ffff             -call 0x4fe7c4
    cpu.esp -= 4;
    sub_4fe7c4(app, cpu);
    if (cpu.terminate) return;
    // 004feea8  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004feead  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004feeb0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004feeb2  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 004feeb6  eb09                   -jmp 0x4feec1
    goto L_0x004feec1;
L_0x004feeb8:
    // 004feeb8  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004feebd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004feebf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004feec1:
    // 004feec1  e8fef8ffff             -call 0x4fe7c4
    cpu.esp -= 4;
    sub_4fe7c4(app, cpu);
    if (cpu.terminate) return;
    // 004feec6  80791550               +cmp byte ptr [ecx + 0x15], 0x50
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
    // 004feeca  7507                   -jne 0x4feed3
    if (!cpu.flags.zf)
    {
        goto L_0x004feed3;
    }
    // 004feecc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004feece  e809010000             -call 0x4fefdc
    cpu.esp -= 4;
    sub_4fefdc(app, cpu);
    if (cpu.terminate) return;
L_0x004feed3:
    // 004feed3  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004feed8  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004feeda  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004feedc  e853f8ffff             -call 0x4fe734
    cpu.esp -= 4;
    sub_4fe734(app, cpu);
    if (cpu.terminate) return;
    // 004feee1  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004feee4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004feee6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004feee8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004feeeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feeec  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004feeed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feeee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feeef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004feef0:
    // 004feef0  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004feef3  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004feefa  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004feefd  7465                   -je 0x4fef64
    if (cpu.flags.zf)
    {
        goto L_0x004fef64;
    }
    // 004feeff  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004fef01  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fef04  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004fef06  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004fef0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004fef0c  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 004fef0f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fef13  e848f10100             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 004fef18  83f8ff                 +cmp eax, -1
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
    // 004fef1b  0f84af000000           -je 0x4fefd0
    if (cpu.flags.zf)
    {
        goto L_0x004fefd0;
    }
    // 004fef21  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fef25  8b2d00b2a000           -mov ebp, dword ptr [0xa0b200]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
    // 004fef2b  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004fef2d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004fef2f  0f849b000000           -je 0x4fefd0
    if (cpu.flags.zf)
    {
        goto L_0x004fefd0;
    }
    // 004fef35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fef37  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004fef3b  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 004fef41  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004fef43  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004fef48  0f8482000000           -je 0x4fefd0
    if (cpu.flags.zf)
    {
        goto L_0x004fefd0;
    }
    // 004fef4e  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 004fef52  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004fef55  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 004fef58  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fef5a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fef5c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fef5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef60  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fef61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fef64:
    // 004fef64  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004fef66  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fef69  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004fef6b  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004fef6e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004fef70  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fef72  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fef74  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fef77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef78  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fef79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fef7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fef7c:
    // 004fef7c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004fef7e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004fef81  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004fef83  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004fef87  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004fef8d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004fef8f  e8ccf00100             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 004fef94  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fef96  83f8ff                 +cmp eax, -1
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
    // 004fef99  740f                   -je 0x4fefaa
    if (cpu.flags.zf)
    {
        goto L_0x004fefaa;
    }
    // 004fef9b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004fef9e  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fefa0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fefa2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fefa5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefa6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fefa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fefaa:
    // 004fefaa  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004fefb1  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fefb3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fefb5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fefb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefb9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fefba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004fefbd:
    // 004fefbd  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004fefc4  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004fefc7  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004fefc9  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004fefd0:
    // 004fefd0  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004fefd2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004fefd4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004fefd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefd8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004fefd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fefdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4fefdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fefdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fefdd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004fefde  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fefe0  803800                 +cmp byte ptr [eax], 0
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
    // 004fefe3  7413                   -je 0x4feff8
    if (cpu.flags.zf)
    {
        goto L_0x004feff8;
    }
L_0x004fefe5:
    // 004fefe5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fefe7  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004fefe9  e8f2fdfeff             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 004fefee  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004feff0  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004feff3  42                     -inc edx
    (cpu.edx)++;
    // 004feff4  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004feff6  75ed                   -jne 0x4fefe5
    if (!cpu.flags.zf)
    {
        goto L_0x004fefe5;
    }
L_0x004feff8:
    // 004feff8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feff9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004feffa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4feffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004feffc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004feffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ff000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff001  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff003  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff005  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ff007  e8a4a70000             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 004ff00c  ff4310                 -inc dword ptr [ebx + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 004ff00f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff010  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff014  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff015  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff016  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff017  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff018  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ff01a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ff01d  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff023  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ff026  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ff029  83f901                 +cmp ecx, 1
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
    // 004ff02c  741b                   -je 0x4ff049
    if (cpu.flags.zf)
    {
        goto L_0x004ff049;
    }
    // 004ff02e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ff030  7410                   -je 0x4ff042
    if (cpu.flags.zf)
    {
        goto L_0x004ff042;
    }
    // 004ff032  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ff035  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff03b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff03d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff03e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff03f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff040  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff041  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff042:
    // 004ff042  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004ff049:
    // 004ff049  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ff04c  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 004ff04f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ff052  88660c                 -mov byte ptr [esi + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 004ff055  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ff058  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ff05b  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004ff05e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ff060  7507                   -jne 0x4ff069
    if (!cpu.flags.zf)
    {
        goto L_0x004ff069;
    }
    // 004ff062  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ff064  e857390000             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004ff069:
    // 004ff069  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004ff06c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ff06e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004ff071  7414                   -je 0x4ff087
    if (cpu.flags.zf)
    {
        goto L_0x004ff087;
    }
    // 004ff073  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004ff075  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004ff078  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 004ff07a  886e0d                 -mov byte ptr [esi + 0xd], ch
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 004ff07d  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004ff07f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004ff084  88460d                 -mov byte ptr [esi + 0xd], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x004ff087:
    // 004ff087  b900f04f00             -mov ecx, 0x4ff000
    cpu.ecx = 5238784 /*0x4ff000*/;
    // 004ff08c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ff08e  e83df1ffff             -call 0x4fe1d0
    cpu.esp -= 4;
    sub_4fe1d0(app, cpu);
    if (cpu.terminate) return;
    // 004ff093  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ff095  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ff097  7418                   -je 0x4ff0b1
    if (cpu.flags.zf)
    {
        goto L_0x004ff0b1;
    }
    // 004ff099  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004ff09c  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004ff09f  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 004ff0a1  88660d                 -mov byte ptr [esi + 0xd], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004ff0a4  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004ff0a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ff0a9  885e0d                 -mov byte ptr [esi + 0xd], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004ff0ac  e8af360000             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
L_0x004ff0b1:
    // 004ff0b1  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004ff0b5  7405                   -je 0x4ff0bc
    if (cpu.flags.zf)
    {
        goto L_0x004ff0bc;
    }
    // 004ff0b7  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004ff0bc:
    // 004ff0bc  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ff0bf  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ff0c1  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ff0c4  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ff0c7  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff0cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff0cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff0d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff0d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff0d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff0e0  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff0e6  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 004ff0eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff0ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff0ec  a12c649f00             -mov eax, dword ptr [0x9f642c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10445868) /* 0x9f642c */);
    // 004ff0f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff0f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff0f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff0f4;
    // 004ff0ec  a12c649f00             -mov eax, dword ptr [0x9f642c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10445868) /* 0x9f642c */);
    // 004ff0f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x004ff0f4:
    // 004ff0f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff0f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff0f8  e907f20100             -jmp 0x51e304
    return sub_51e304(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff100  e957f30100             -jmp 0x51e45c
    return sub_51e45c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff108(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff108  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff109  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff10a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff10b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ff10d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ff10f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff111  893520649f00           -mov dword ptr [0x9f6420], esi
    app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */) = cpu.esi;
    // 004ff117  e8d0f60100             -call 0x51e7ec
    cpu.esp -= 4;
    sub_51e7ec(app, cpu);
    if (cpu.terminate) return;
    // 004ff11c  a32c649f00             -mov dword ptr [0x9f642c], eax
    app->getMemory<x86::reg32>(x86::reg32(10445868) /* 0x9f642c */) = cpu.eax;
    // 004ff121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff123  7511                   -jne 0x4ff136
    if (!cpu.flags.zf)
    {
        goto L_0x004ff136;
    }
    // 004ff125  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ff127  0f8505020000           -jne 0x4ff332
    if (!cpu.flags.zf)
    {
        goto L_0x004ff332;
    }
    // 004ff12d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ff12f  2eff15c0445300         -call dword ptr cs:[0x5344c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457088) /* 0x5344c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ff136:
    // 004ff136  e855f30100             -call 0x51e490
    cpu.esp -= 4;
    sub_51e490(app, cpu);
    if (cpu.terminate) return;
    // 004ff13b  2eff151c455300         -call dword ptr cs:[0x53451c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457180) /* 0x53451c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff142  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ff144  a339785600             -mov dword ptr [0x567839], eax
    app->getMemory<x86::reg32>(x86::reg32(5666873) /* 0x567839 */) = cpu.eax;
    // 004ff149  891554b1a000           -mov dword ptr [0xa0b154], edx
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edx;
    // 004ff14f  2eff1574455300         -call dword ptr cs:[0x534574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457268) /* 0x534574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff156  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ff158  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff15a  a23f785600             -mov byte ptr [0x56783f], al
    app->getMemory<x86::reg8>(x86::reg32(5666879) /* 0x56783f */) = cpu.al;
    // 004ff15f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ff162  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ff167  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004ff16c  66a341785600           -mov word ptr [0x567841], ax
    app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */) = cpu.ax;
    // 004ff172  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff174  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ff17a  66a141785600           -mov ax, word ptr [0x567841]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */);
    // 004ff180  6830649f00             -push 0x9f6430
    app->getMemory<x86::reg32>(cpu.esp-4) = 10445872 /*0x9f6430*/;
    cpu.esp -= 4;
    // 004ff185  a343785600             -mov dword ptr [0x567843], eax
    app->getMemory<x86::reg32>(x86::reg32(5666883) /* 0x567843 */) = cpu.eax;
    // 004ff18a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff18c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004ff18f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004ff191  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ff197  a347785600             -mov dword ptr [0x567847], eax
    app->getMemory<x86::reg32>(x86::reg32(5666887) /* 0x567847 */) = cpu.eax;
    // 004ff19c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff19e  881540785600           -mov byte ptr [0x567840], dl
    app->getMemory<x86::reg8>(x86::reg32(5666880) /* 0x567840 */) = cpu.dl;
    // 004ff1a4  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004ff1a6  8b1547785600           -mov edx, dword ptr [0x567847]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666887) /* 0x567847 */);
    // 004ff1ac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ff1ae  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004ff1b1  bb30649f00             -mov ebx, 0x9f6430
    cpu.ebx = 10445872 /*0x9f6430*/;
    // 004ff1b6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff1b8  a34b785600             -mov dword ptr [0x56784b], eax
    app->getMemory<x86::reg32>(x86::reg32(5666891) /* 0x56784b */) = cpu.eax;
    // 004ff1bd  89154f785600           -mov dword ptr [0x56784f], edx
    app->getMemory<x86::reg32>(x86::reg32(5666895) /* 0x56784f */) = cpu.edx;
    // 004ff1c3  2eff1544455300         -call dword ptr cs:[0x534544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457220) /* 0x534544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff1ca  ba34659f00             -mov edx, 0x9f6534
    cpu.edx = 10446132 /*0x9f6534*/;
    // 004ff1cf  891d00785600           -mov dword ptr [0x567800], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666816) /* 0x567800 */) = cpu.ebx;
    // 004ff1d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff1d7  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004ff1dc  b934659f00             -mov ecx, 0x9f6534
    cpu.ecx = 10446132 /*0x9f6534*/;
    // 004ff1e1  e81af90100             -call 0x51eb00
    cpu.esp -= 4;
    sub_51eb00(app, cpu);
    if (cpu.terminate) return;
    // 004ff1e6  890d0c785600           -mov dword ptr [0x56780c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666828) /* 0x56780c */) = cpu.ecx;
    // 004ff1ec  2eff15f4445300         -call dword ptr cs:[0x5344f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457140) /* 0x5344f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff1f3  e8a8f90100             -call 0x51eba0
    cpu.esp -= 4;
    sub_51eba0(app, cpu);
    if (cpu.terminate) return;
    // 004ff1f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ff1fa  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ff1fc  a324649f00             -mov dword ptr [0x9f6424], eax
    app->getMemory<x86::reg32>(x86::reg32(10445860) /* 0x9f6424 */) = cpu.eax;
    // 004ff201  80fb22                 +cmp bl, 0x22
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
    // 004ff204  751e                   -jne 0x4ff224
    if (!cpu.flags.zf)
    {
        goto L_0x004ff224;
    }
    // 004ff206  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ff209  40                     -inc eax
    (cpu.eax)++;
    // 004ff20a  38df                   +cmp bh, bl
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
    // 004ff20c  740e                   -je 0x4ff21c
    if (cpu.flags.zf)
    {
        goto L_0x004ff21c;
    }
L_0x004ff20e:
    // 004ff20e  803800                 +cmp byte ptr [eax], 0
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
    // 004ff211  7409                   -je 0x4ff21c
    if (cpu.flags.zf)
    {
        goto L_0x004ff21c;
    }
    // 004ff213  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ff216  40                     -inc eax
    (cpu.eax)++;
    // 004ff217  80fa22                 +cmp dl, 0x22
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
    // 004ff21a  75f2                   -jne 0x4ff20e
    if (!cpu.flags.zf)
    {
        goto L_0x004ff20e;
    }
L_0x004ff21c:
    // 004ff21c  803800                 +cmp byte ptr [eax], 0
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
    // 004ff21f  741e                   -je 0x4ff23f
    if (cpu.flags.zf)
    {
        goto L_0x004ff23f;
    }
    // 004ff221  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff222  eb1b                   -jmp 0x4ff23f
    goto L_0x004ff23f;
L_0x004ff224:
    // 004ff224  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ff226  fec2                   -inc dl
    (cpu.dl)++;
    // 004ff228  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ff22e  f682f04e560002         +test byte ptr [edx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 004ff235  7508                   -jne 0x4ff23f
    if (!cpu.flags.zf)
    {
        goto L_0x004ff23f;
    }
    // 004ff237  803800                 +cmp byte ptr [eax], 0
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
    // 004ff23a  7403                   -je 0x4ff23f
    if (cpu.flags.zf)
    {
        goto L_0x004ff23f;
    }
    // 004ff23c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff23d  ebe5                   -jmp 0x4ff224
    goto L_0x004ff224;
L_0x004ff23f:
    // 004ff23f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ff241  fec2                   -inc dl
    (cpu.dl)++;
    // 004ff243  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ff249  f682f04e560002         +test byte ptr [edx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 004ff250  7403                   -je 0x4ff255
    if (cpu.flags.zf)
    {
        goto L_0x004ff255;
    }
    // 004ff252  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff253  ebea                   -jmp 0x4ff23f
    goto L_0x004ff23f;
L_0x004ff255:
    // 004ff255  a3fc775600             -mov dword ptr [0x5677fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5666812) /* 0x5677fc */) = cpu.eax;
    // 004ff25a  2eff15f8445300         -call dword ptr cs:[0x5344f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457144) /* 0x5344f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff261  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff263  0f847d000000           -je 0x4ff2e6
    if (cpu.flags.zf)
    {
        goto L_0x004ff2e6;
    }
    // 004ff269  e882f90100             -call 0x51ebf0
    cpu.esp -= 4;
    sub_51ebf0(app, cpu);
    if (cpu.terminate) return;
    // 004ff26e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ff270  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004ff273  a328649f00             -mov dword ptr [0x9f6428], eax
    app->getMemory<x86::reg32>(x86::reg32(10445864) /* 0x9f6428 */) = cpu.eax;
    // 004ff278  6683fb22               +cmp bx, 0x22
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
    // 004ff27c  752a                   -jne 0x4ff2a8
    if (!cpu.flags.zf)
    {
        goto L_0x004ff2a8;
    }
    // 004ff27e  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ff282  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ff285  6639d9                 +cmp cx, bx
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
    // 004ff288  7413                   -je 0x4ff29d
    if (cpu.flags.zf)
    {
        goto L_0x004ff29d;
    }
L_0x004ff28a:
    // 004ff28a  66833800               +cmp word ptr [eax], 0
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
    // 004ff28e  740d                   -je 0x4ff29d
    if (cpu.flags.zf)
    {
        goto L_0x004ff29d;
    }
    // 004ff290  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ff294  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ff297  6683fb22               +cmp bx, 0x22
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
    // 004ff29b  75ed                   -jne 0x4ff28a
    if (!cpu.flags.zf)
    {
        goto L_0x004ff28a;
    }
L_0x004ff29d:
    // 004ff29d  66833800               +cmp word ptr [eax], 0
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
    // 004ff2a1  7427                   -je 0x4ff2ca
    if (cpu.flags.zf)
    {
        goto L_0x004ff2ca;
    }
    // 004ff2a3  83c002                 +add eax, 2
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
    // 004ff2a6  eb22                   -jmp 0x4ff2ca
    goto L_0x004ff2ca;
L_0x004ff2a8:
    // 004ff2a8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x004ff2ad:
    // 004ff2ad  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ff2af  fec2                   -inc dl
    (cpu.dl)++;
    // 004ff2b1  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004ff2b7  849af04e5600           -test byte ptr [edx + 0x564ef0], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & cpu.bl));
    // 004ff2bd  750b                   -jne 0x4ff2ca
    if (!cpu.flags.zf)
    {
        goto L_0x004ff2ca;
    }
    // 004ff2bf  66833800               +cmp word ptr [eax], 0
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
    // 004ff2c3  7405                   -je 0x4ff2ca
    if (cpu.flags.zf)
    {
        goto L_0x004ff2ca;
    }
    // 004ff2c5  83c002                 +add eax, 2
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
    // 004ff2c8  ebe3                   -jmp 0x4ff2ad
    goto L_0x004ff2ad;
L_0x004ff2ca:
    // 004ff2ca  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x004ff2cf:
    // 004ff2cf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004ff2d1  fec2                   -inc dl
    (cpu.dl)++;
    // 004ff2d3  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004ff2d9  849af04e5600           -test byte ptr [edx + 0x564ef0], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & cpu.bl));
    // 004ff2df  740a                   -je 0x4ff2eb
    if (cpu.flags.zf)
    {
        goto L_0x004ff2eb;
    }
    // 004ff2e1  83c002                 +add eax, 2
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
    // 004ff2e4  ebe9                   -jmp 0x4ff2cf
    goto L_0x004ff2cf;
L_0x004ff2e6:
    // 004ff2e6  b8c0e05400             -mov eax, 0x54e0c0
    cpu.eax = 5562560 /*0x54e0c0*/;
L_0x004ff2eb:
    // 004ff2eb  a308785600             -mov dword ptr [0x567808], eax
    app->getMemory<x86::reg32>(x86::reg32(5666824) /* 0x567808 */) = cpu.eax;
    // 004ff2f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ff2f2  7439                   -je 0x4ff32d
    if (cpu.flags.zf)
    {
        goto L_0x004ff32d;
    }
    // 004ff2f4  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004ff2f9  683c679f00             -push 0x9f673c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10446652 /*0x9f673c*/;
    cpu.esp -= 4;
    // 004ff2fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff2ff  be3c679f00             -mov esi, 0x9f673c
    cpu.esi = 10446652 /*0x9f673c*/;
    // 004ff304  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 004ff309  2eff1544455300         -call dword ptr cs:[0x534544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457220) /* 0x534544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff310  ba40689f00             -mov edx, 0x9f6840
    cpu.edx = 10446912 /*0x9f6840*/;
    // 004ff315  893504785600           -mov dword ptr [0x567804], esi
    app->getMemory<x86::reg32>(x86::reg32(5666820) /* 0x567804 */) = cpu.esi;
    // 004ff31b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ff31d  bf40689f00             -mov edi, 0x9f6840
    cpu.edi = 10446912 /*0x9f6840*/;
    // 004ff322  e8d9f70100             -call 0x51eb00
    cpu.esp -= 4;
    sub_51eb00(app, cpu);
    if (cpu.terminate) return;
    // 004ff327  893d10785600           -mov dword ptr [0x567810], edi
    app->getMemory<x86::reg32>(x86::reg32(5666832) /* 0x567810 */) = cpu.edi;
L_0x004ff32d:
    // 004ff32d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ff332:
    // 004ff332  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff333  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff334  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff335  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ff338(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff338  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff339  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff33a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff33b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff33c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ff33e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ff340  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ff342  2eff154c455300         -call dword ptr cs:[0x53454c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457228) /* 0x53454c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff349  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff34b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ff34d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff34f  e8b4fdffff             -call 0x4ff108
    cpu.esp -= 4;
    sub_4ff108(app, cpu);
    if (cpu.terminate) return;
    // 004ff354  ba1c785600             -mov edx, 0x56781c
    cpu.edx = 5666844 /*0x56781c*/;
    // 004ff359  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff35f  e8bcf80100             -call 0x51ec20
    cpu.esp -= 4;
    sub_51ec20(app, cpu);
    if (cpu.terminate) return;
    // 004ff364  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ff366  e865fd0100             -call 0x51f0d0
    cpu.esp -= 4;
    sub_51f0d0(app, cpu);
    if (cpu.terminate) return;
    // 004ff36b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004ff370  e8a7000000             -call 0x4ff41c
    cpu.esp -= 4;
    sub_4ff41c(app, cpu);
    if (cpu.terminate) return;
    // 004ff375  ff15a4775600           -call dword ptr [0x5677a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666724) /* 0x5677a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff37b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004ff380  e897000000             -call 0x4ff41c
    cpu.esp -= 4;
    sub_4ff41c(app, cpu);
    if (cpu.terminate) return;
    // 004ff385  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff386  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff388  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ff38c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff38c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff38e  833d20649f0000         +cmp dword ptr [0x9f6420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff395  7418                   -je 0x4ff3af
    if (cpu.flags.zf)
    {
        goto L_0x004ff3af;
    }
    // 004ff397  833dac77560000         +cmp dword ptr [0x5677ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666732) /* 0x5677ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff39e  7426                   -je 0x4ff3c6
    if (cpu.flags.zf)
    {
        goto L_0x004ff3c6;
    }
    // 004ff3a0  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004ff3a5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ff3a7  ff15ac775600           -call dword ptr [0x5677ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666732) /* 0x5677ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff3ad  eb17                   -jmp 0x4ff3c6
    goto L_0x004ff3c6;
L_0x004ff3af:
    // 004ff3af  e868fd0100             -call 0x51f11c
    cpu.esp -= 4;
    sub_51f11c(app, cpu);
    if (cpu.terminate) return;
    // 004ff3b4  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004ff3b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff3bb  e8ac000000             -call 0x4ff46c
    cpu.esp -= 4;
    sub_4ff46c(app, cpu);
    if (cpu.terminate) return;
    // 004ff3c0  ff15a0775600           -call dword ptr [0x5677a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666720) /* 0x5677a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ff3c6:
    // 004ff3c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff3c7  2eff15c0445300         -call dword ptr cs:[0x5344c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457088) /* 0x5344c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff3ce  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004ff3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff3d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff3d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff3d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff3d4  8b1524649f00           -mov edx, dword ptr [0x9f6424]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445860) /* 0x9f6424 */);
    // 004ff3da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff3dc  740f                   -je 0x4ff3ed
    if (cpu.flags.zf)
    {
        goto L_0x004ff3ed;
    }
    // 004ff3de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff3e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ff3e2  e80986ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004ff3e7  891d24649f00           -mov dword ptr [0x9f6424], ebx
    app->getMemory<x86::reg32>(x86::reg32(10445860) /* 0x9f6424 */) = cpu.ebx;
L_0x004ff3ed:
    // 004ff3ed  8b0d28649f00           -mov ecx, dword ptr [0x9f6428]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10445864) /* 0x9f6428 */);
    // 004ff3f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ff3f5  740f                   -je 0x4ff406
    if (cpu.flags.zf)
    {
        goto L_0x004ff406;
    }
    // 004ff3f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ff3f9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ff3fb  e8f085ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004ff400  893528649f00           -mov dword ptr [0x9f6428], esi
    app->getMemory<x86::reg32>(x86::reg32(10445864) /* 0x9f6428 */) = cpu.esi;
L_0x004ff406:
    // 004ff406  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff407  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff408  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff409  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff40a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff3d0;
    // 004ff38c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff38e  833d20649f0000         +cmp dword ptr [0x9f6420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff395  7418                   -je 0x4ff3af
    if (cpu.flags.zf)
    {
        goto L_0x004ff3af;
    }
    // 004ff397  833dac77560000         +cmp dword ptr [0x5677ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666732) /* 0x5677ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff39e  7426                   -je 0x4ff3c6
    if (cpu.flags.zf)
    {
        goto L_0x004ff3c6;
    }
    // 004ff3a0  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004ff3a5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ff3a7  ff15ac775600           -call dword ptr [0x5677ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666732) /* 0x5677ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff3ad  eb17                   -jmp 0x4ff3c6
    goto L_0x004ff3c6;
L_0x004ff3af:
    // 004ff3af  e868fd0100             -call 0x51f11c
    cpu.esp -= 4;
    sub_51f11c(app, cpu);
    if (cpu.terminate) return;
    // 004ff3b4  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004ff3b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff3bb  e8ac000000             -call 0x4ff46c
    cpu.esp -= 4;
    sub_4ff46c(app, cpu);
    if (cpu.terminate) return;
    // 004ff3c0  ff15a0775600           -call dword ptr [0x5677a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666720) /* 0x5677a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ff3c6:
    // 004ff3c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff3c7  2eff15c0445300         -call dword ptr cs:[0x5344c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457088) /* 0x5344c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff3ce  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004ff3d0:
    // 004ff3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff3d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff3d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff3d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff3d4  8b1524649f00           -mov edx, dword ptr [0x9f6424]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445860) /* 0x9f6424 */);
    // 004ff3da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff3dc  740f                   -je 0x4ff3ed
    if (cpu.flags.zf)
    {
        goto L_0x004ff3ed;
    }
    // 004ff3de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff3e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ff3e2  e80986ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004ff3e7  891d24649f00           -mov dword ptr [0x9f6424], ebx
    app->getMemory<x86::reg32>(x86::reg32(10445860) /* 0x9f6424 */) = cpu.ebx;
L_0x004ff3ed:
    // 004ff3ed  8b0d28649f00           -mov ecx, dword ptr [0x9f6428]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10445864) /* 0x9f6428 */);
    // 004ff3f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ff3f5  740f                   -je 0x4ff406
    if (cpu.flags.zf)
    {
        goto L_0x004ff406;
    }
    // 004ff3f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ff3f9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ff3fb  e8f085ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004ff400  893528649f00           -mov dword ptr [0x9f6428], esi
    app->getMemory<x86::reg32>(x86::reg32(10445864) /* 0x9f6428 */) = cpu.esi;
L_0x004ff406:
    // 004ff406  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff407  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff408  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff409  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff40a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff410  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ff411  833800                 +cmp dword ptr [eax], 0
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
    // 004ff414  7404                   -je 0x4ff41a
    if (cpu.flags.zf)
    {
        goto L_0x004ff41a;
    }
    // 004ff416  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004ff417  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ff418  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ff41a:
    // 004ff41a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ff41b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff41c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff41c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff41d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff41e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff41f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff420  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ff421  be1ab85600             -mov esi, 0x56b81a
    cpu.esi = 5683226 /*0x56b81a*/;
    // 004ff426  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x004ff428:
    // 004ff428  b8deb75600             -mov eax, 0x56b7de
    cpu.eax = 5683166 /*0x56b7de*/;
    // 004ff42d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ff42f  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004ff431  39c6                   +cmp esi, eax
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
    // 004ff433  761a                   -jbe 0x4ff44f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ff44f;
    }
L_0x004ff435:
    // 004ff435  803802                 +cmp byte ptr [eax], 2
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
    // 004ff438  740b                   -je 0x4ff445
    if (cpu.flags.zf)
    {
        goto L_0x004ff445;
    }
    // 004ff43a  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ff43d  38ea                   +cmp dl, ch
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
    // 004ff43f  7204                   -jb 0x4ff445
    if (cpu.flags.cf)
    {
        goto L_0x004ff445;
    }
    // 004ff441  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff443  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004ff445:
    // 004ff445  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004ff448  3d1ab85600             +cmp eax, 0x56b81a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5683226 /*0x56b81a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff44d  72e6                   -jb 0x4ff435
    if (cpu.flags.cf)
    {
        goto L_0x004ff435;
    }
L_0x004ff44f:
    // 004ff44f  81fb1ab85600           +cmp ebx, 0x56b81a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5683226 /*0x56b81a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff455  740d                   -je 0x4ff464
    if (cpu.flags.zf)
    {
        goto L_0x004ff464;
    }
    // 004ff457  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004ff45a  e8b1ffffff             -call 0x4ff410
    cpu.esp -= 4;
    sub_4ff410(app, cpu);
    if (cpu.terminate) return;
    // 004ff45f  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004ff462  ebc4                   -jmp 0x4ff428
    goto L_0x004ff428;
L_0x004ff464:
    // 004ff464  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ff465  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff466  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff468  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff469  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ff46c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff46c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff46d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff46e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff46f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ff470  be44b85600             -mov esi, 0x56b844
    cpu.esi = 5683268 /*0x56b844*/;
    // 004ff475  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004ff477  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x004ff479:
    // 004ff479  b81ab85600             -mov eax, 0x56b81a
    cpu.eax = 5683226 /*0x56b81a*/;
    // 004ff47e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ff480  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004ff482  39c6                   +cmp esi, eax
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
    // 004ff484  761a                   -jbe 0x4ff4a0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ff4a0;
    }
L_0x004ff486:
    // 004ff486  803802                 +cmp byte ptr [eax], 2
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
    // 004ff489  740b                   -je 0x4ff496
    if (cpu.flags.zf)
    {
        goto L_0x004ff496;
    }
    // 004ff48b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004ff48e  38ea                   +cmp dl, ch
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
    // 004ff490  7704                   -ja 0x4ff496
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ff496;
    }
    // 004ff492  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff494  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004ff496:
    // 004ff496  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004ff499  3d44b85600             +cmp eax, 0x56b844
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5683268 /*0x56b844*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff49e  72e6                   -jb 0x4ff486
    if (cpu.flags.cf)
    {
        goto L_0x004ff486;
    }
L_0x004ff4a0:
    // 004ff4a0  81fb44b85600           +cmp ebx, 0x56b844
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5683268 /*0x56b844*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff4a6  7412                   -je 0x4ff4ba
    if (cpu.flags.zf)
    {
        goto L_0x004ff4ba;
    }
    // 004ff4a8  3a7301                 +cmp dh, byte ptr [ebx + 1]
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
    // 004ff4ab  7208                   -jb 0x4ff4b5
    if (cpu.flags.cf)
    {
        goto L_0x004ff4b5;
    }
    // 004ff4ad  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004ff4b0  e85bffffff             -call 0x4ff410
    cpu.esp -= 4;
    sub_4ff410(app, cpu);
    if (cpu.terminate) return;
L_0x004ff4b5:
    // 004ff4b5  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004ff4b8  ebbf                   -jmp 0x4ff479
    goto L_0x004ff479;
L_0x004ff4ba:
    // 004ff4ba  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ff4bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff4bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff4bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff4be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ff4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff4c0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004ff4c2  742c                   -je 0x4ff4f0
    if (cpu.flags.zf)
    {
        goto L_0x004ff4f0;
    }
    // 004ff4c4  3810                   -cmp byte ptr [eax], dl
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
L_0x004ff4c6:
    // 004ff4c6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004ff4c8  7409                   -je 0x4ff4d3
    if (cpu.flags.zf)
    {
        goto L_0x004ff4d3;
    }
    // 004ff4ca  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004ff4cc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff4cd  c1ca08                 +ror edx, 8
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
    // 004ff4d0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff4d1  75f3                   -jne 0x4ff4c6
    if (!cpu.flags.zf)
    {
        goto L_0x004ff4c6;
    }
L_0x004ff4d3:
    // 004ff4d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff4d4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004ff4d7  e81b000000             -call 0x4ff4f7
    cpu.esp -= 4;
    sub_4ff4f7(app, cpu);
    if (cpu.terminate) return;
    // 004ff4dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff4dd  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004ff4e0  740e                   -je 0x4ff4f0
    if (cpu.flags.zf)
    {
        goto L_0x004ff4f0;
    }
    // 004ff4e2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004ff4e4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff4e5  7409                   -je 0x4ff4f0
    if (cpu.flags.zf)
    {
        goto L_0x004ff4f0;
    }
    // 004ff4e7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 004ff4ea  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff4eb  7403                   -je 0x4ff4f0
    if (cpu.flags.zf)
    {
        goto L_0x004ff4f0;
    }
    // 004ff4ed  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x004ff4f0:
    // 004ff4f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ff4f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff4f2  90                     -nop 
    ;
    // 004ff4f3  90                     -nop 
    ;
    // 004ff4f4  90                     -nop 
    ;
    // 004ff4f5  90                     -nop 
    ;
    // 004ff4f6  90                     -nop 
    ;
    // 004ff4f7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004ff4f9  7467                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
L_0x004ff4fb:
    // 004ff4fb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004ff4fd  7408                   -je 0x4ff507
    if (cpu.flags.zf)
    {
        goto L_0x004ff507;
    }
    // 004ff4ff  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff501  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff504  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff505  75f4                   -jne 0x4ff4fb
    if (!cpu.flags.zf)
    {
        goto L_0x004ff4fb;
    }
L_0x004ff507:
    // 004ff507  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff508  c1e902                 +shr ecx, 2
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
    // 004ff50b  743a                   -je 0x4ff547
    if (cpu.flags.zf)
    {
        goto L_0x004ff547;
    }
    // 004ff50d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff50e  7429                   -je 0x4ff539
    if (cpu.flags.zf)
    {
        goto L_0x004ff539;
    }
L_0x004ff510:
    // 004ff510  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff512  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ff515  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff516  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ff519  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ff51c  7418                   -je 0x4ff536
    if (cpu.flags.zf)
    {
        goto L_0x004ff536;
    }
    // 004ff51e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 004ff521  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ff524  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ff527  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff528  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ff52b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ff52e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ff531  75dd                   -jne 0x4ff510
    if (!cpu.flags.zf)
    {
        goto L_0x004ff510;
    }
    // 004ff533  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004ff536:
    // 004ff536  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004ff539:
    // 004ff539  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff53b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ff53e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ff541  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ff544  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004ff547:
    // 004ff547  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff548  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004ff54b  7415                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff54d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff54f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff552  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff553  740d                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff555  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff557  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff55a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff55b  7405                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff55d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff55f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004ff562:
    // 004ff562  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff4f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff4f7;
    // 004ff4f2  90                     -nop 
    ;
    // 004ff4f3  90                     -nop 
    ;
    // 004ff4f4  90                     -nop 
    ;
    // 004ff4f5  90                     -nop 
    ;
    // 004ff4f6  90                     -nop 
    ;
L_entry_0x004ff4f7:
    // 004ff4f7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004ff4f9  7467                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
L_0x004ff4fb:
    // 004ff4fb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004ff4fd  7408                   -je 0x4ff507
    if (cpu.flags.zf)
    {
        goto L_0x004ff507;
    }
    // 004ff4ff  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff501  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff504  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff505  75f4                   -jne 0x4ff4fb
    if (!cpu.flags.zf)
    {
        goto L_0x004ff4fb;
    }
L_0x004ff507:
    // 004ff507  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff508  c1e902                 +shr ecx, 2
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
    // 004ff50b  743a                   -je 0x4ff547
    if (cpu.flags.zf)
    {
        goto L_0x004ff547;
    }
    // 004ff50d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff50e  7429                   -je 0x4ff539
    if (cpu.flags.zf)
    {
        goto L_0x004ff539;
    }
L_0x004ff510:
    // 004ff510  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff512  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ff515  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff516  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ff519  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ff51c  7418                   -je 0x4ff536
    if (cpu.flags.zf)
    {
        goto L_0x004ff536;
    }
    // 004ff51e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 004ff521  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ff524  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ff527  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff528  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ff52b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ff52e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ff531  75dd                   -jne 0x4ff510
    if (!cpu.flags.zf)
    {
        goto L_0x004ff510;
    }
    // 004ff533  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004ff536:
    // 004ff536  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004ff539:
    // 004ff539  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff53b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ff53e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ff541  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ff544  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004ff547:
    // 004ff547  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff548  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004ff54b  7415                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff54d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff54f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff552  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff553  740d                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff555  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff557  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ff55a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ff55b  7405                   -je 0x4ff562
    if (cpu.flags.zf)
    {
        goto L_0x004ff562;
    }
    // 004ff55d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ff55f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004ff562:
    // 004ff562  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff572  ba40f15100             -mov edx, 0x51f140
    cpu.edx = 5370176 /*0x51f140*/;
    // 004ff577  bb54f25100             -mov ebx, 0x51f254
    cpu.ebx = 5370452 /*0x51f254*/;
    // 004ff57c  891564ac5600           -mov dword ptr [0x56ac64], edx
    app->getMemory<x86::reg32>(x86::reg32(5680228) /* 0x56ac64 */) = cpu.edx;
    // 004ff582  891d68ac5600           -mov dword ptr [0x56ac68], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680232) /* 0x56ac68 */) = cpu.ebx;
    // 004ff588  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff589  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff590  9b                     -wait 
    /*nothing*/;
    // 004ff591  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 004ff593  9b                     -wait 
    /*nothing*/;
    // 004ff594  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff598(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff598  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 004ff59a  9b                     -wait 
    /*nothing*/;
    // 004ff59b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff59c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff59c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff59d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff59e  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ff5a5  7416                   -je 0x4ff5bd
    if (cpu.flags.zf)
    {
        goto L_0x004ff5bd;
    }
    // 004ff5a7  ba90f54f00             -mov edx, 0x4ff590
    cpu.edx = 5240208 /*0x4ff590*/;
    // 004ff5ac  bb98f54f00             -mov ebx, 0x4ff598
    cpu.ebx = 5240216 /*0x4ff598*/;
    // 004ff5b1  8915f0ac5600           -mov dword ptr [0x56acf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5680368) /* 0x56acf0 */) = cpu.edx;
    // 004ff5b7  891df4ac5600           -mov dword ptr [0x56acf4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680372) /* 0x56acf4 */) = cpu.ebx;
L_0x004ff5bd:
    // 004ff5bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff5bf  66a1f8ac5600           -mov ax, word ptr [0x56acf8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5680376) /* 0x56acf8 */);
    // 004ff5c5  e8a8fc0100             -call 0x51f272
    cpu.esp -= 4;
    sub_51f272(app, cpu);
    if (cpu.terminate) return;
    // 004ff5ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff5cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff5cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ff5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff5d0  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ff5d7  75c3                   -jne 0x4ff59c
    if (!cpu.flags.zf)
    {
        return sub_4ff59c(app, cpu);
    }
    // 004ff5d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ff5dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff5dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff5dd  8a25c0445600           -mov ah, byte ptr [0x5644c0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5653696) /* 0x5644c0 */);
    // 004ff5e3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004ff5e5  7537                   -jne 0x4ff61e
    if (!cpu.flags.zf)
    {
        goto L_0x004ff61e;
    }
    // 004ff5e7  8825c1445600           -mov byte ptr [0x5644c1], ah
    app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */) = cpu.ah;
    // 004ff5ed  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004ff5ef  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff5f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ff5f2  dbe3                   -fninit 
    cpu.fpu.init();
    // 004ff5f4  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004ff5f7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff5f8  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 004ff5fa  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004ff5fc  3c03                   +cmp al, 3
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
    // 004ff5fe  7509                   -jne 0x4ff609
    if (!cpu.flags.zf)
    {
        goto L_0x004ff609;
    }
    // 004ff600  e897ffffff             -call 0x4ff59c
    cpu.esp -= 4;
    sub_4ff59c(app, cpu);
    if (cpu.terminate) return;
    // 004ff605  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 004ff607  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x004ff609:
    // 004ff609  803d3478560000         +cmp byte ptr [0x567834], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5666868) /* 0x567834 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ff610  750c                   -jne 0x4ff61e
    if (!cpu.flags.zf)
    {
        goto L_0x004ff61e;
    }
    // 004ff612  8835c0445600           -mov byte ptr [0x5644c0], dh
    app->getMemory<x86::reg8>(x86::reg32(5653696) /* 0x5644c0 */) = cpu.dh;
    // 004ff618  8815c1445600           -mov byte ptr [0x5644c1], dl
    app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */) = cpu.dl;
L_0x004ff61e:
    // 004ff61e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff61f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ff624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff624  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ff625  83ec76                 -sub esp, 0x76
    (cpu.esp) -= x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004ff628  db7c246c               -fstp xword ptr [esp + 0x6c]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(108) /* 0x6c */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ff62c  dd3424                 -fnsave dword ptr [esp]
    NFS2_ASSERT(false);
    // 004ff62f  db6c241c               -fld xword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004ff633  db6c246c               -fld xword ptr [esp + 0x6c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(108) /* 0x6c */)));
    // 004ff637  e8e4fc0100             -call 0x51f320
    cpu.esp -= 4;
    sub_51f320(app, cpu);
    if (cpu.terminate) return;
    // 004ff63c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ff63e  db7c241c               -fstp xword ptr [esp + 0x1c]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ff642  6625ff00               -and ax, 0xff
    cpu.ax &= x86::reg16(x86::sreg16(255 /*0xff*/));
    // 004ff646  660b442404             -or ax, word ptr [esp + 4]
    cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004ff64b  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004ff650  dd2424                 -frstor dword ptr [esp]
    NFS2_ASSERT(false);
    // 004ff653  83c476                 -add esp, 0x76
    (cpu.esp) += x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004ff656  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff660  a3506a9f00             -mov dword ptr [0x9f6a50], eax
    app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */) = cpu.eax;
    // 004ff665  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ff670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff674  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff675  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff677  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff679  e8b202feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004ff67e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff680  754e                   -jne 0x4ff6d0
    if (!cpu.flags.zf)
    {
        goto L_0x004ff6d0;
    }
    // 004ff682  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004ff687:
    // 004ff687  833d6478560000         +cmp dword ptr [0x567864], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff68e  750a                   -jne 0x4ff69a
    if (!cpu.flags.zf)
    {
        goto L_0x004ff69a;
    }
    // 004ff690  e86b04feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004ff695  a364785600             -mov dword ptr [0x567864], eax
    app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */) = cpu.eax;
L_0x004ff69a:
    // 004ff69a  833d506a9f0000         +cmp dword ptr [0x9f6a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff6a1  743f                   -je 0x4ff6e2
    if (cpu.flags.zf)
    {
        goto L_0x004ff6e2;
    }
    // 004ff6a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ff6a5  740f                   -je 0x4ff6b6
    if (cpu.flags.zf)
    {
        goto L_0x004ff6b6;
    }
    // 004ff6a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff6a8  8b3d80445600           -mov edi, dword ptr [0x564480]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ff6ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff6af  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff6b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ff6b6:
    // 004ff6b6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ff6b8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ff6ba  892d5c785600           -mov dword ptr [0x56785c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5666908) /* 0x56785c */) = cpu.ebp;
    // 004ff6c0  ff15506a9f00           -call dword ptr [0x9f6a50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff6c6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ff6c8  750a                   -jne 0x4ff6d4
    if (!cpu.flags.zf)
    {
        goto L_0x004ff6d4;
    }
L_0x004ff6ca:
    // 004ff6ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff6d0:
    // 004ff6d0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004ff6d2  ebb3                   -jmp 0x4ff687
    goto L_0x004ff687;
L_0x004ff6d4:
    // 004ff6d4  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004ff6d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ff6da  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ff6e0  ebe8                   -jmp 0x4ff6ca
    goto L_0x004ff6ca;
L_0x004ff6e2:
    // 004ff6e2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ff6e7  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff6ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff6ef  891d5c785600           -mov dword ptr [0x56785c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666908) /* 0x56785c */) = cpu.ebx;
    // 004ff6f5  e82604feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004ff6fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff6ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff700  e86b99ffff             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004ff705  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff707  752f                   -jne 0x4ff738
    if (!cpu.flags.zf)
    {
        goto L_0x004ff738;
    }
L_0x004ff709:
    // 004ff709  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ff70b:
    // 004ff70b  3b1564785600           +cmp edx, dword ptr [0x567864]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff711  0f84f8000000           -je 0x4ff80f
    if (cpu.flags.zf)
    {
        return sub_4ff80f(app, cpu);
    }
    // 004ff717  8b2d5c785600           -mov ebp, dword ptr [0x56785c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5666908) /* 0x56785c */);
    // 004ff71d  39ea                   +cmp edx, ebp
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
    // 004ff71f  0f85ea000000           -jne 0x4ff80f
    if (!cpu.flags.zf)
    {
        return sub_4ff80f(app, cpu);
    }
    // 004ff725  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ff72a  e8b101feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004ff72f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ff731  e8fa7efeff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004ff736  ebd3                   -jmp 0x4ff70b
    goto L_0x004ff70b;
L_0x004ff738:
    // 004ff738  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff739  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff73a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff73b  b9c4e05400             -mov ecx, 0x54e0c4
    cpu.ecx = 5562564 /*0x54e0c4*/;
    // 004ff740  bbd4e05400             -mov ebx, 0x54e0d4
    cpu.ebx = 5562580 /*0x54e0d4*/;
    // 004ff745  be5e000000             -mov esi, 0x5e
    cpu.esi = 94 /*0x5e*/;
    // 004ff74a  68e4e05400             -push 0x54e0e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562596 /*0x54e0e4*/;
    cpu.esp -= 4;
    // 004ff74f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ff755  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ff75b  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004ff761  e8aa18f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ff766  83c404                 +add esp, 4
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
    // 004ff769  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff76a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff76b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff76c  eb9b                   -jmp 0x4ff709
    goto L_0x004ff709;
}

/* align: skip  */
void Application::sub_4ff76e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff76e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ff770  e8fb03feff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004ff775  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff776  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff777  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ff780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff781  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff787  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff789  7502                   -jne 0x4ff78d
    if (!cpu.flags.zf)
    {
        goto L_0x004ff78d;
    }
    // 004ff78b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff78c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff78d:
    // 004ff78d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff78e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ff793  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff795  890d5c785600           -mov dword ptr [0x56785c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666908) /* 0x56785c */) = cpu.ecx;
    // 004ff79b  e88003feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004ff7a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff7a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff7a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4ff7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff7b0  a15c785600             -mov eax, dword ptr [0x56785c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666908) /* 0x56785c */);
    // 004ff7b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ff7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff7c0  833d506a9f0000         +cmp dword ptr [0x9f6a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff7c7  7417                   -je 0x4ff7e0
    if (cpu.flags.zf)
    {
        goto L_0x004ff7e0;
    }
    // 004ff7c9  833dd843560000         +cmp dword ptr [0x5643d8], 0
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
    // 004ff7d0  750f                   -jne 0x4ff7e1
    if (!cpu.flags.zf)
    {
        goto L_0x004ff7e1;
    }
    // 004ff7d2  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7d8  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ff7e0:
    // 004ff7e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff7e1:
    // 004ff7e1  e88afeffff             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004ff7e6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7ec  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff7f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff7f4  e83701feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004ff7f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff7fb  0f85fffeffff           -jne 0x4ff700
    if (!cpu.flags.zf)
    {
        return sub_4ff700(app, cpu);
    }
    // 004ff801  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff807  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff809  0f855fffffff           -jne 0x4ff76e
    if (!cpu.flags.zf)
    {
        return sub_4ff76e(app, cpu);
    }
    // 004ff80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff810  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff7f0;
    // 004ff7c0  833d506a9f0000         +cmp dword ptr [0x9f6a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff7c7  7417                   -je 0x4ff7e0
    if (cpu.flags.zf)
    {
        goto L_0x004ff7e0;
    }
    // 004ff7c9  833dd843560000         +cmp dword ptr [0x5643d8], 0
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
    // 004ff7d0  750f                   -jne 0x4ff7e1
    if (!cpu.flags.zf)
    {
        goto L_0x004ff7e1;
    }
    // 004ff7d2  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7d8  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ff7e0:
    // 004ff7e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff7e1:
    // 004ff7e1  e88afeffff             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004ff7e6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7ec  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_entry_0x004ff7f0:
    // 004ff7f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff7f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff7f4  e83701feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004ff7f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff7fb  0f85fffeffff           -jne 0x4ff700
    if (!cpu.flags.zf)
    {
        return sub_4ff700(app, cpu);
    }
    // 004ff801  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff807  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff809  0f855fffffff           -jne 0x4ff76e
    if (!cpu.flags.zf)
    {
        return sub_4ff76e(app, cpu);
    }
    // 004ff80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff810  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff7e0;
    // 004ff7c0  833d506a9f0000         +cmp dword ptr [0x9f6a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff7c7  7417                   -je 0x4ff7e0
    if (cpu.flags.zf)
    {
        goto L_0x004ff7e0;
    }
    // 004ff7c9  833dd843560000         +cmp dword ptr [0x5643d8], 0
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
    // 004ff7d0  750f                   -jne 0x4ff7e1
    if (!cpu.flags.zf)
    {
        goto L_0x004ff7e1;
    }
    // 004ff7d2  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7d8  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ff7e0:
L_entry_0x004ff7e0:
    // 004ff7e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff7e1:
    // 004ff7e1  e88afeffff             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004ff7e6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7ec  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff7f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff7f4  e83701feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004ff7f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff7fb  0f85fffeffff           -jne 0x4ff700
    if (!cpu.flags.zf)
    {
        return sub_4ff700(app, cpu);
    }
    // 004ff801  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff807  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff809  0f855fffffff           -jne 0x4ff76e
    if (!cpu.flags.zf)
    {
        return sub_4ff76e(app, cpu);
    }
    // 004ff80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff810  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ff80f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ff80f;
    // 004ff7c0  833d506a9f0000         +cmp dword ptr [0x9f6a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447440) /* 0x9f6a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff7c7  7417                   -je 0x4ff7e0
    if (cpu.flags.zf)
    {
        goto L_0x004ff7e0;
    }
    // 004ff7c9  833dd843560000         +cmp dword ptr [0x5643d8], 0
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
    // 004ff7d0  750f                   -jne 0x4ff7e1
    if (!cpu.flags.zf)
    {
        goto L_0x004ff7e1;
    }
    // 004ff7d2  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7d8  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ff7e0:
    // 004ff7e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff7e1:
    // 004ff7e1  e88afeffff             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004ff7e6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004ff7ec  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004ff7f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ff7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff7f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff7f4  e83701feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004ff7f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff7fb  0f85fffeffff           -jne 0x4ff700
    if (!cpu.flags.zf)
    {
        return sub_4ff700(app, cpu);
    }
    // 004ff801  8b1564785600           -mov edx, dword ptr [0x567864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666916) /* 0x567864 */);
    // 004ff807  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff809  0f855fffffff           -jne 0x4ff76e
    if (!cpu.flags.zf)
    {
        return sub_4ff76e(app, cpu);
    }
L_entry_0x004ff80f:
    // 004ff80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff810  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4ff820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff820  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004ff825  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ff830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff830  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ff840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ff841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ff842  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ff844  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ff846  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff848  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ff84a  7e12                   -jle 0x4ff85e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ff85e;
    }
L_0x004ff84c:
    // 004ff84c  8b90516a9f00           -mov edx, dword ptr [eax + 0x9f6a51]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ff852  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004ff855  39da                   +cmp edx, ebx
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
    // 004ff857  740a                   -je 0x4ff863
    if (cpu.flags.zf)
    {
        goto L_0x004ff863;
    }
    // 004ff859  40                     -inc eax
    (cpu.eax)++;
    // 004ff85a  39c8                   +cmp eax, ecx
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
    // 004ff85c  7cee                   -jl 0x4ff84c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff84c;
    }
L_0x004ff85e:
    // 004ff85e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ff863:
    // 004ff863  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ff868  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff869  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ff86a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ff86c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ff86c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ff86d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ff86e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ff86f  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004ff872  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ff876  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ff87a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ff87e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ff881  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 004ff886  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ff88a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ff88c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ff88e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ff892  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ff894  7e12                   -jle 0x4ff8a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ff8a8;
    }
    // 004ff896  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 004ff898  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x004ff89c:
    // 004ff89c  40                     -inc eax
    (cpu.eax)++;
    // 004ff89d  8890536a9f00           -mov byte ptr [eax + 0x9f6a53], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10447443) /* 0x9f6a53 */) = cpu.dl;
    // 004ff8a3  39d8                   +cmp eax, ebx
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
    // 004ff8a5  7cf5                   -jl 0x4ff89c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff89c;
    }
    // 004ff8a7  90                     -nop 
    ;
L_0x004ff8a8:
    // 004ff8a8  8b356c785600           -mov esi, dword ptr [0x56786c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666924) /* 0x56786c */);
    // 004ff8ae  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ff8b1  89356c785600           -mov dword ptr [0x56786c], esi
    app->getMemory<x86::reg32>(x86::reg32(5666924) /* 0x56786c */) = cpu.esi;
    // 004ff8b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ff8b9  7c42                   -jl 0x4ff8fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff8fd;
    }
L_0x004ff8bb:
    // 004ff8bb  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ff8bf  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ff8c3  39d7                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff8c5  0f8d80000000           -jge 0x4ff94b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ff94b;
    }
L_0x004ff8cb:
    // 004ff8cb  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004ff8d0  be3c9ba000             -mov esi, 0xa09b3c
    cpu.esi = 10525500 /*0xa09b3c*/;
    // 004ff8d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ff8d7  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
L_0x004ff8db:
    // 004ff8db  0fbe05f69aa000         -movsx eax, byte ptr [0xa09af6]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(10525430) /* 0xa09af6 */)));
    // 004ff8e2  39c3                   +cmp ebx, eax
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
    // 004ff8e4  7d42                   -jge 0x4ff928
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ff928;
    }
    // 004ff8e6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ff8eb  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004ff8ed  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ff8f1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004ff8f3  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004ff8f5  750f                   -jne 0x4ff906
    if (!cpu.flags.zf)
    {
        goto L_0x004ff906;
    }
L_0x004ff8f7:
    // 004ff8f7  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ff8fa  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff8fb  ebde                   -jmp 0x4ff8db
    goto L_0x004ff8db;
L_0x004ff8fd:
    // 004ff8fd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ff8ff  a36c785600             -mov dword ptr [0x56786c], eax
    app->getMemory<x86::reg32>(x86::reg32(5666924) /* 0x56786c */) = cpu.eax;
    // 004ff904  ebb5                   -jmp 0x4ff8bb
    goto L_0x004ff8bb;
L_0x004ff906:
    // 004ff906  807e0c00               +cmp byte ptr [esi + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ff90a  75eb                   -jne 0x4ff8f7
    if (!cpu.flags.zf)
    {
        goto L_0x004ff8f7;
    }
    // 004ff90c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ff90e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ff910  e82bffffff             -call 0x4ff840
    cpu.esp -= 4;
    sub_4ff840(app, cpu);
    if (cpu.terminate) return;
    // 004ff915  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff917  75de                   -jne 0x4ff8f7
    if (!cpu.flags.zf)
    {
        goto L_0x004ff8f7;
    }
    // 004ff919  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ff91c  39cd                   +cmp ebp, ecx
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
    // 004ff91e  76d7                   -jbe 0x4ff8f7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ff8f7;
    }
    // 004ff920  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ff922  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004ff926  ebcf                   -jmp 0x4ff8f7
    goto L_0x004ff8f7;
L_0x004ff928:
    // 004ff928  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004ff92d  7c0b                   -jl 0x4ff93a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff93a;
    }
    // 004ff92f  47                     -inc edi
    (cpu.edi)++;
    // 004ff930  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ff934  8887536a9f00           -mov byte ptr [edi + 0x9f6a53], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10447443) /* 0x9f6a53 */) = cpu.al;
L_0x004ff93a:
    // 004ff93a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ff93e  41                     -inc ecx
    (cpu.ecx)++;
    // 004ff93f  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ff943  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004ff947  39d9                   +cmp ecx, ebx
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
    // 004ff949  7c80                   -jl 0x4ff8cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff8cb;
    }
L_0x004ff94b:
    // 004ff94b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ff94f  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004ff953  39f7                   +cmp edi, esi
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
    // 004ff955  0f8d97000000           -jge 0x4ff9f2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ff9f2;
    }
L_0x004ff95b:
    // 004ff95b  bd66000000             -mov ebp, 0x66
    cpu.ebp = 102 /*0x66*/;
    // 004ff960  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ff965  be3c9ba000             -mov esi, 0xa09b3c
    cpu.esi = 10525500 /*0xa09b3c*/;
    // 004ff96a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ff96c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004ff970  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004ff974:
    // 004ff974  0fbe05f69aa000         -movsx eax, byte ptr [0xa09af6]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(10525430) /* 0xa09af6 */)));
    // 004ff97b  39c3                   +cmp ebx, eax
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
    // 004ff97d  7d51                   -jge 0x4ff9d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ff9d0;
    }
    // 004ff97f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ff984  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004ff986  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ff98a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004ff98c  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004ff98e  7506                   -jne 0x4ff996
    if (!cpu.flags.zf)
    {
        goto L_0x004ff996;
    }
L_0x004ff990:
    // 004ff990  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ff993  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ff994  ebde                   -jmp 0x4ff974
    goto L_0x004ff974;
L_0x004ff996:
    // 004ff996  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ff998  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ff99a  e8a1feffff             -call 0x4ff840
    cpu.esp -= 4;
    sub_4ff840(app, cpu);
    if (cpu.terminate) return;
    // 004ff99f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ff9a1  75ed                   -jne 0x4ff990
    if (!cpu.flags.zf)
    {
        goto L_0x004ff990;
    }
    // 004ff9a3  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004ff9a6  39e8                   +cmp eax, ebp
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
    // 004ff9a8  7d0f                   -jge 0x4ff9b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ff9b9;
    }
    // 004ff9aa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ff9ac  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ff9af  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004ff9b3  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ff9b7  ebd7                   -jmp 0x4ff990
    goto L_0x004ff990;
L_0x004ff9b9:
    // 004ff9b9  75d5                   -jne 0x4ff990
    if (!cpu.flags.zf)
    {
        goto L_0x004ff990;
    }
    // 004ff9bb  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ff9bf  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ff9c2  39c8                   +cmp eax, ecx
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
    // 004ff9c4  73ca                   -jae 0x4ff990
    if (!cpu.flags.cf)
    {
        goto L_0x004ff990;
    }
    // 004ff9c6  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ff9ca  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004ff9ce  ebc0                   -jmp 0x4ff990
    goto L_0x004ff990;
L_0x004ff9d0:
    // 004ff9d0  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004ff9d5  0f8cb8000000           -jl 0x4ffa93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffa93;
    }
    // 004ff9db  47                     -inc edi
    (cpu.edi)++;
    // 004ff9dc  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ff9e0  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ff9e4  8887536a9f00           -mov byte ptr [edi + 0x9f6a53], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10447443) /* 0x9f6a53 */) = cpu.al;
    // 004ff9ea  39df                   +cmp edi, ebx
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
    // 004ff9ec  0f8ca1000000           -jl 0x4ffa93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffa93;
    }
L_0x004ff9f2:
    // 004ff9f2  3b7c2414               +cmp edi, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ff9f6  0f858c000000           -jne 0x4ffa88
    if (!cpu.flags.zf)
    {
        goto L_0x004ffa88;
    }
    // 004ff9fc  8b1d516a9f00           -mov ebx, dword ptr [0x9f6a51]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffa02  a16c785600             -mov eax, dword ptr [0x56786c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666924) /* 0x56786c */);
    // 004ffa07  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004ffa0a  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffa0c  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ffa0f  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ffa11  a1516a9f00             -mov eax, dword ptr [0x9f6a51]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffa16  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ffa19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffa1b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ffa1f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ffa21  0f8eb3000000           -jle 0x4ffada
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ffada;
    }
L_0x004ffa27:
    // 004ffa27  8bab516a9f00           -mov ebp, dword ptr [ebx + 0x9f6a51]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffa2d  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 004ffa30  6bed60                 -imul ebp, ebp, 0x60
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004ffa33  81c53c9ba000           -add ebp, 0xa09b3c
    (cpu.ebp) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004ffa39  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ffa3c  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ffa3f  80f901                 +cmp cl, 1
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffa42  0f8576000000           -jne 0x4ffabe
    if (!cpu.flags.zf)
    {
        goto L_0x004ffabe;
    }
    // 004ffa48  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ffa4a  7c61                   -jl 0x4ffaad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffaad;
    }
L_0x004ffa4c:
    // 004ffa4c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ffa4e  e81d9cfeff             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 004ffa53  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ffa55  e87695feff             -call 0x4e8fd0
    cpu.esp -= 4;
    sub_4e8fd0(app, cpu);
    if (cpu.terminate) return;
    // 004ffa5a  83f801                 +cmp eax, 1
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
    // 004ffa5d  745f                   -je 0x4ffabe
    if (cpu.flags.zf)
    {
        goto L_0x004ffabe;
    }
    // 004ffa5f  4b                     -dec ebx
    (cpu.ebx)--;
    // 004ffa60  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ffa62  7c1c                   -jl 0x4ffa80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffa80;
    }
    // 004ffa64  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ffa66:
    // 004ffa66  8b83516a9f00           -mov eax, dword ptr [ebx + 0x9f6a51]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffa6c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ffa6f  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004ffa72  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004ffa77  4b                     -dec ebx
    (cpu.ebx)--;
    // 004ffa78  88500c                 -mov byte ptr [eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004ffa7b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ffa7d  7de7                   -jge 0x4ffa66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ffa66;
    }
    // 004ffa7f  90                     -nop 
    ;
L_0x004ffa80:
    // 004ffa80  c7442404f7ffffff       -mov dword ptr [esp + 4], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 4294967287 /*0xfffffff7*/;
L_0x004ffa88:
    // 004ffa88  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ffa8c  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004ffa8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffa90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffa91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffa92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffa93:
    // 004ffa93  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ffa97  43                     -inc ebx
    (cpu.ebx)++;
    // 004ffa98  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ffa9c  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004ffaa0  39f3                   +cmp ebx, esi
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
    // 004ffaa2  0f8cb3feffff           -jl 0x4ff95b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ff95b;
    }
    // 004ffaa8  e945ffffff             -jmp 0x4ff9f2
    goto L_0x004ff9f2;
L_0x004ffaad:
    // 004ffaad  8b4541                 -mov eax, dword ptr [ebp + 0x41]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(65) /* 0x41 */);
    // 004ffab0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ffab3  6bc060                 +imul eax, eax, 0x60
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004ffab6  8bb03c9ba000           -mov esi, dword ptr [eax + 0xa09b3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525500) /* 0xa09b3c */);
    // 004ffabc  eb8e                   -jmp 0x4ffa4c
    goto L_0x004ffa4c;
L_0x004ffabe:
    // 004ffabe  c6450c01               -mov byte ptr [ebp + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004ffac2  a1fc9aa000             -mov eax, dword ptr [0xa09afc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004ffac7  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ffaca  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004fface  43                     -inc ebx
    (cpu.ebx)++;
    // 004ffacf  88450e                 -mov byte ptr [ebp + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004ffad2  39fb                   +cmp ebx, edi
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
    // 004ffad4  0f8c4dffffff           -jl 0x4ffa27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffa27;
    }
L_0x004ffada:
    // 004ffada  8b1d516a9f00           -mov ebx, dword ptr [0x9f6a51]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffae0  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004ffae3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ffaea  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffaec  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ffaef  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffaf2  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ffaf4  89983c9ba000           -mov dword ptr [eax + 0xa09b3c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525500) /* 0xa09b3c */) = cpu.ebx;
    // 004ffafa  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004ffaff  39f7                   +cmp edi, esi
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
    // 004ffb01  7e85                   -jle 0x4ffa88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ffa88;
    }
    // 004ffb03  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
L_0x004ffb08:
    // 004ffb08  8b1d516a9f00           -mov ebx, dword ptr [0x9f6a51]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffb0e  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004ffb11  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ffb18  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffb1a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffb1d  8a9e546a9f00           -mov bl, byte ptr [esi + 0x9f6a54]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10447444) /* 0x9f6a54 */);
    // 004ffb23  889c063f9ba000         -mov byte ptr [esi + eax + 0xa09b3f], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10525503) /* 0xa09b3f */ + cpu.eax * 1) = cpu.bl;
    // 004ffb2a  8b9e516a9f00           -mov ebx, dword ptr [esi + 0x9f6a51]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10447441) /* 0x9f6a51 */);
    // 004ffb30  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004ffb33  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ffb3a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffb3c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffb3f  89a83c9ba000           -mov dword ptr [eax + 0xa09b3c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525500) /* 0xa09b3c */) = cpu.ebp;
    // 004ffb45  8a1d546a9f00           -mov bl, byte ptr [0x9f6a54]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(10447444) /* 0x9f6a54 */);
    // 004ffb4b  8898809ba000           -mov byte ptr [eax + 0xa09b80], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525568) /* 0xa09b80 */) = cpu.bl;
    // 004ffb51  46                     -inc esi
    (cpu.esi)++;
    // 004ffb52  39fe                   +cmp esi, edi
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
    // 004ffb54  7cb2                   -jl 0x4ffb08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffb08;
    }
    // 004ffb56  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ffb5a  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004ffb5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffb5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffb5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffb60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ffb64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ffb64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ffb65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ffb66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ffb67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ffb68  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ffb69  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ffb6a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ffb6c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ffb6f  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ffb71  ba3c9ba000             -mov edx, 0xa09b3c
    cpu.edx = 10525500 /*0xa09b3c*/;
    // 004ffb76  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffb79  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ffb7b  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004ffb80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ffb82  8a623b                 -mov ah, byte ptr [edx + 0x3b]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */);
    // 004ffb85  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 004ffb89  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004ffb8b  0f84c1000000           -je 0x4ffc52
    if (cpu.flags.zf)
    {
        goto L_0x004ffc52;
    }
    // 004ffb91  b83c9ba000             -mov eax, 0xa09b3c
    cpu.eax = 10525500 /*0xa09b3c*/;
    // 004ffb96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ffb98:
    // 004ffb98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ffb9a  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004ffb9d  39fb                   +cmp ebx, edi
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
    // 004ffb9f  7515                   -jne 0x4ffbb6
    if (!cpu.flags.zf)
    {
        goto L_0x004ffbb6;
    }
    // 004ffba1  833800                 +cmp dword ptr [eax], 0
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
    // 004ffba4  7c10                   -jl 0x4ffbb6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffbb6;
    }
    // 004ffba6  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffbaa  740a                   -je 0x4ffbb6
    if (cpu.flags.zf)
    {
        goto L_0x004ffbb6;
    }
    // 004ffbac  8a583a                 -mov bl, byte ptr [eax + 0x3a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 004ffbaf  41                     -inc ecx
    (cpu.ecx)++;
    // 004ffbb0  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004ffbb2  7402                   -je 0x4ffbb6
    if (cpu.flags.zf)
    {
        goto L_0x004ffbb6;
    }
    // 004ffbb4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004ffbb6:
    // 004ffbb6  42                     -inc edx
    (cpu.edx)++;
    // 004ffbb7  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004ffbba  83fa10                 +cmp edx, 0x10
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
    // 004ffbbd  7cd9                   -jl 0x4ffb98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffb98;
    }
    // 004ffbbf  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004ffbc6  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ffbc8  ba3c9ba000             -mov edx, 0xa09b3c
    cpu.edx = 10525500 /*0xa09b3c*/;
    // 004ffbcd  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffbd0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ffbd2  83f901                 +cmp ecx, 1
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
    // 004ffbd5  7445                   -je 0x4ffc1c
    if (cpu.flags.zf)
    {
        goto L_0x004ffc1c;
    }
    // 004ffbd7  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ffbde  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ffbe0  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffbe3  80b8489ba00002         +cmp byte ptr [eax + 0xa09b48], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525512) /* 0xa09b48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffbea  7509                   -jne 0x4ffbf5
    if (!cpu.flags.zf)
    {
        goto L_0x004ffbf5;
    }
    // 004ffbec  39f5                   +cmp ebp, esi
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
    // 004ffbee  7405                   -je 0x4ffbf5
    if (cpu.flags.zf)
    {
        goto L_0x004ffbf5;
    }
    // 004ffbf0  83f902                 +cmp ecx, 2
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
    // 004ffbf3  7435                   -je 0x4ffc2a
    if (cpu.flags.zf)
    {
        goto L_0x004ffc2a;
    }
L_0x004ffbf5:
    // 004ffbf5  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ffbfc  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ffbfe  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffc01  80b8489ba00001         +cmp byte ptr [eax + 0xa09b48], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525512) /* 0xa09b48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffc08  7512                   -jne 0x4ffc1c
    if (!cpu.flags.zf)
    {
        goto L_0x004ffc1c;
    }
    // 004ffc0a  39f5                   +cmp ebp, esi
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
    // 004ffc0c  750e                   -jne 0x4ffc1c
    if (!cpu.flags.zf)
    {
        goto L_0x004ffc1c;
    }
    // 004ffc0e  c680489ba00002         -mov byte ptr [eax + 0xa09b48], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525512) /* 0xa09b48 */) = 2 /*0x2*/;
L_0x004ffc15:
    // 004ffc15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffc1c:
    // 004ffc1c  c6420c00               -mov byte ptr [edx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ffc20  a1fc9aa000             -mov eax, dword ptr [0xa09afc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004ffc25  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ffc28  ebeb                   -jmp 0x4ffc15
    goto L_0x004ffc15;
L_0x004ffc2a:
    // 004ffc2a  c6420c00               -mov byte ptr [edx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ffc2e  8b0dfc9aa000           -mov ecx, dword ptr [0xa09afc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004ffc34  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ffc37  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004ffc39  8890489ba000           -mov byte ptr [eax + 0xa09b48], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10525512) /* 0xa09b48 */) = cpu.dl;
    // 004ffc3f  8b15fc9aa000           -mov edx, dword ptr [0xa09afc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004ffc45  8990509ba000           -mov dword ptr [eax + 0xa09b50], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525520) /* 0xa09b50 */) = cpu.edx;
    // 004ffc4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffc52:
    // 004ffc52  807a0c00               +cmp byte ptr [edx + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffc56  752f                   -jne 0x4ffc87
    if (!cpu.flags.zf)
    {
        goto L_0x004ffc87;
    }
    // 004ffc58  b928e15400             -mov ecx, 0x54e128
    cpu.ecx = 5562664 /*0x54e128*/;
    // 004ffc5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ffc5e  bb38e15400             -mov ebx, 0x54e138
    cpu.ebx = 5562680 /*0x54e138*/;
    // 004ffc63  be2a010000             -mov esi, 0x12a
    cpu.esi = 298 /*0x12a*/;
    // 004ffc68  6848e15400             -push 0x54e148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562696 /*0x54e148*/;
    cpu.esp -= 4;
    // 004ffc6d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ffc73  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ffc79  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004ffc7f  e88c13f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ffc84  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004ffc87:
    // 004ffc87  c6420c00               -mov byte ptr [edx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ffc8b  a1fc9aa000             -mov eax, dword ptr [0xa09afc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */);
    // 004ffc90  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ffc93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffc99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ffc9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ffc9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ffc9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ffc9e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ffca0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ffca2  7c2b                   -jl 0x4ffccf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ffccf;
    }
    // 004ffca4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ffca6  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ffca9  83fa10                 +cmp edx, 0x10
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
    // 004ffcac  7d21                   -jge 0x4ffccf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ffccf;
    }
    // 004ffcae  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004ffcb5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ffcb7  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004ffcba  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 004ffcbf  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ffcc3  7512                   -jne 0x4ffcd7
    if (!cpu.flags.zf)
    {
        goto L_0x004ffcd7;
    }
L_0x004ffcc5:
    // 004ffcc5  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 004ffcca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ffccc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffccd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffcce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffccf:
    // 004ffccf  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004ffcd4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffcd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffcd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffcd7:
    // 004ffcd7  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ffcd9  75ea                   -jne 0x4ffcc5
    if (!cpu.flags.zf)
    {
        goto L_0x004ffcc5;
    }
    // 004ffcdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ffcdd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffcde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffcdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ffce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ffce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ffce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ffce2  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ffce5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ffce7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ffce9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ffceb  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ffcf0  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 004ffcf5  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004ffcf8  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ffcfa  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ffcfe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ffd00  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ffd04  e857affeff             -call 0x4eac60
    cpu.esp -= 4;
    sub_4eac60(app, cpu);
    if (cpu.terminate) return;
    // 004ffd09  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004ffd0b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ffd0f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ffd11  e80af80100             -call 0x51f520
    cpu.esp -= 4;
    sub_51f520(app, cpu);
    if (cpu.terminate) return;
    // 004ffd16  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ffd1a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ffd1e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ffd22  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ffd26  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004ffd2a  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004ffd2e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ffd30  dd0574e15400           -fld qword ptr [0x54e174]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5562740) /* 0x54e174 */)));
    // 004ffd36  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ffd38  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004ffd3a  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ffd3c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ffd40  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ffd44  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004ffd48  dc0d7ce15400           -fmul qword ptr [0x54e17c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5562748) /* 0x54e17c */));
    // 004ffd4e  d95904                 -fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ffd51  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ffd55  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ffd59  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ffd5c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ffd60  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 004ffd64  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004ffd68  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ffd6a  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004ffd6c  d95908                 -fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ffd6f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ffd72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffd73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffd74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ffd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ffd80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ffd84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ffd84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ffd85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ffd86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ffd87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ffd88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ffd89  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ffd8a  a0b4435600             -mov al, byte ptr [0x5643b4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5653428) /* 0x5643b4 */);
    // 004ffd8f  8b15b4435600           -mov edx, dword ptr [0x5643b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */);
    // 004ffd95  a25b6a9f00             -mov byte ptr [0x9f6a5b], al
    app->getMemory<x86::reg8>(x86::reg32(10447451) /* 0x9f6a5b */) = cpu.al;
    // 004ffd9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ffd9c  0f84bf000000           -je 0x4ffe61
    if (cpu.flags.zf)
    {
        goto L_0x004ffe61;
    }
    // 004ffda2  bd80f55100             -mov ebp, 0x51f580
    cpu.ebp = 5371264 /*0x51f580*/;
    // 004ffda7  b880f65100             -mov eax, 0x51f680
    cpu.eax = 5371520 /*0x51f680*/;
    // 004ffdac  ba50f75100             -mov edx, 0x51f750
    cpu.edx = 5371728 /*0x51f750*/;
    // 004ffdb1  b950f85100             -mov ecx, 0x51f850
    cpu.ecx = 5371984 /*0x51f850*/;
    // 004ffdb6  bb38fc5100             -mov ebx, 0x51fc38
    cpu.ebx = 5372984 /*0x51fc38*/;
    // 004ffdbb  be2c005200             -mov esi, 0x52002c
    cpu.esi = 5373996 /*0x52002c*/;
    // 004ffdc0  bfa0035200             -mov edi, 0x5203a0
    cpu.edi = 5374880 /*0x5203a0*/;
    // 004ffdc5  892ddc6a9f00           -mov dword ptr [0x9f6adc], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447580) /* 0x9f6adc */) = cpu.ebp;
    // 004ffdcb  a3e06a9f00             -mov dword ptr [0x9f6ae0], eax
    app->getMemory<x86::reg32>(x86::reg32(10447584) /* 0x9f6ae0 */) = cpu.eax;
    // 004ffdd0  8915e46a9f00           -mov dword ptr [0x9f6ae4], edx
    app->getMemory<x86::reg32>(x86::reg32(10447588) /* 0x9f6ae4 */) = cpu.edx;
    // 004ffdd6  890de86a9f00           -mov dword ptr [0x9f6ae8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447592) /* 0x9f6ae8 */) = cpu.ecx;
    // 004ffddc  891dfc6a9f00           -mov dword ptr [0x9f6afc], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447612) /* 0x9f6afc */) = cpu.ebx;
    // 004ffde2  8935006b9f00           -mov dword ptr [0x9f6b00], esi
    app->getMemory<x86::reg32>(x86::reg32(10447616) /* 0x9f6b00 */) = cpu.esi;
    // 004ffde8  893d046b9f00           -mov dword ptr [0x9f6b04], edi
    app->getMemory<x86::reg32>(x86::reg32(10447620) /* 0x9f6b04 */) = cpu.edi;
    // 004ffdee  891dec6a9f00           -mov dword ptr [0x9f6aec], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447596) /* 0x9f6aec */) = cpu.ebx;
    // 004ffdf4  8935f06a9f00           -mov dword ptr [0x9f6af0], esi
    app->getMemory<x86::reg32>(x86::reg32(10447600) /* 0x9f6af0 */) = cpu.esi;
    // 004ffdfa  893df46a9f00           -mov dword ptr [0x9f6af4], edi
    app->getMemory<x86::reg32>(x86::reg32(10447604) /* 0x9f6af4 */) = cpu.edi;
    // 004ffe00  bde4075200             -mov ebp, 0x5207e4
    cpu.ebp = 5375972 /*0x5207e4*/;
    // 004ffe05  be30085200             -mov esi, 0x520830
    cpu.esi = 5376048 /*0x520830*/;
    // 004ffe0a  bf70085200             -mov edi, 0x520870
    cpu.edi = 5376112 /*0x520870*/;
    // 004ffe0f  b820095200             -mov eax, 0x520920
    cpu.eax = 5376288 /*0x520920*/;
    // 004ffe14  baa0095200             -mov edx, 0x5209a0
    cpu.edx = 5376416 /*0x5209a0*/;
    // 004ffe19  b9000a5200             -mov ecx, 0x520a00
    cpu.ecx = 5376512 /*0x520a00*/;
    // 004ffe1e  892d086b9f00           -mov dword ptr [0x9f6b08], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447624) /* 0x9f6b08 */) = cpu.ebp;
    // 004ffe24  892df86a9f00           -mov dword ptr [0x9f6af8], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447608) /* 0x9f6af8 */) = cpu.ebp;
    // 004ffe2a  89350c6b9f00           -mov dword ptr [0x9f6b0c], esi
    app->getMemory<x86::reg32>(x86::reg32(10447628) /* 0x9f6b0c */) = cpu.esi;
    // 004ffe30  893d106b9f00           -mov dword ptr [0x9f6b10], edi
    app->getMemory<x86::reg32>(x86::reg32(10447632) /* 0x9f6b10 */) = cpu.edi;
    // 004ffe36  a3186b9f00             -mov dword ptr [0x9f6b18], eax
    app->getMemory<x86::reg32>(x86::reg32(10447640) /* 0x9f6b18 */) = cpu.eax;
    // 004ffe3b  89155c6a9f00           -mov dword ptr [0x9f6a5c], edx
    app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */) = cpu.edx;
    // 004ffe41  890d246b9f00           -mov dword ptr [0x9f6b24], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */) = cpu.ecx;
    // 004ffe47  bd100a5200             -mov ebp, 0x520a10
    cpu.ebp = 5376528 /*0x520a10*/;
    // 004ffe4c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004ffe4e  892d146b9f00           -mov dword ptr [0x9f6b14], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447636) /* 0x9f6b14 */) = cpu.ebp;
    // 004ffe54  88155a6a9f00           -mov byte ptr [0x9f6a5a], dl
    app->getMemory<x86::reg8>(x86::reg32(10447450) /* 0x9f6a5a */) = cpu.dl;
    // 004ffe5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffe60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffe61:
    // 004ffe61  b9400a5200             -mov ecx, 0x520a40
    cpu.ecx = 5376576 /*0x520a40*/;
    // 004ffe66  bb000e5200             -mov ebx, 0x520e00
    cpu.ebx = 5377536 /*0x520e00*/;
    // 004ffe6b  bdc0115200             -mov ebp, 0x5211c0
    cpu.ebp = 5378496 /*0x5211c0*/;
    // 004ffe70  b810135200             -mov eax, 0x521310
    cpu.eax = 5378832 /*0x521310*/;
    // 004ffe75  be00185200             -mov esi, 0x521800
    cpu.esi = 5380096 /*0x521800*/;
    // 004ffe7a  ba40185200             -mov edx, 0x521840
    cpu.edx = 5380160 /*0x521840*/;
    // 004ffe7f  bf80fd4f00             -mov edi, 0x4ffd80
    cpu.edi = 5242240 /*0x4ffd80*/;
    // 004ffe84  890ddc6a9f00           -mov dword ptr [0x9f6adc], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447580) /* 0x9f6adc */) = cpu.ecx;
    // 004ffe8a  891de06a9f00           -mov dword ptr [0x9f6ae0], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447584) /* 0x9f6ae0 */) = cpu.ebx;
    // 004ffe90  890de46a9f00           -mov dword ptr [0x9f6ae4], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447588) /* 0x9f6ae4 */) = cpu.ecx;
    // 004ffe96  891de86a9f00           -mov dword ptr [0x9f6ae8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447592) /* 0x9f6ae8 */) = cpu.ebx;
    // 004ffe9c  892dec6a9f00           -mov dword ptr [0x9f6aec], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447596) /* 0x9f6aec */) = cpu.ebp;
    // 004ffea2  a3f06a9f00             -mov dword ptr [0x9f6af0], eax
    app->getMemory<x86::reg32>(x86::reg32(10447600) /* 0x9f6af0 */) = cpu.eax;
    // 004ffea7  892df46a9f00           -mov dword ptr [0x9f6af4], ebp
    app->getMemory<x86::reg32>(x86::reg32(10447604) /* 0x9f6af4 */) = cpu.ebp;
    // 004ffead  a3f86a9f00             -mov dword ptr [0x9f6af8], eax
    app->getMemory<x86::reg32>(x86::reg32(10447608) /* 0x9f6af8 */) = cpu.eax;
    // 004ffeb2  8935006b9f00           -mov dword ptr [0x9f6b00], esi
    app->getMemory<x86::reg32>(x86::reg32(10447616) /* 0x9f6b00 */) = cpu.esi;
    // 004ffeb8  8935086b9f00           -mov dword ptr [0x9f6b08], esi
    app->getMemory<x86::reg32>(x86::reg32(10447624) /* 0x9f6b08 */) = cpu.esi;
    // 004ffebe  8915106b9f00           -mov dword ptr [0x9f6b10], edx
    app->getMemory<x86::reg32>(x86::reg32(10447632) /* 0x9f6b10 */) = cpu.edx;
    // 004ffec4  893d246b9f00           -mov dword ptr [0x9f6b24], edi
    app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */) = cpu.edi;
    // 004ffeca  bbc41b5200             -mov ebx, 0x521bc4
    cpu.ebx = 5381060 /*0x521bc4*/;
    // 004ffecf  b8101c5200             -mov eax, 0x521c10
    cpu.eax = 5381136 /*0x521c10*/;
    // 004ffed4  b910095000             -mov ecx, 0x500910
    cpu.ecx = 5245200 /*0x500910*/;
    // 004ffed9  be901c5200             -mov esi, 0x521c90
    cpu.esi = 5381264 /*0x521c90*/;
    // 004ffede  891dfc6a9f00           -mov dword ptr [0x9f6afc], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447612) /* 0x9f6afc */) = cpu.ebx;
    // 004ffee4  891d046b9f00           -mov dword ptr [0x9f6b04], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447620) /* 0x9f6b04 */) = cpu.ebx;
    // 004ffeea  a30c6b9f00             -mov dword ptr [0x9f6b0c], eax
    app->getMemory<x86::reg32>(x86::reg32(10447628) /* 0x9f6b0c */) = cpu.eax;
    // 004ffeef  890d146b9f00           -mov dword ptr [0x9f6b14], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447636) /* 0x9f6b14 */) = cpu.ecx;
    // 004ffef5  89355c6a9f00           -mov dword ptr [0x9f6a5c], esi
    app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */) = cpu.esi;
    // 004ffefb  bb001d5200             -mov ebx, 0x521d00
    cpu.ebx = 5381376 /*0x521d00*/;
    // 004fff00  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 004fff02  891d186b9f00           -mov dword ptr [0x9f6b18], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447640) /* 0x9f6b18 */) = cpu.ebx;
    // 004fff08  88255a6a9f00           -mov byte ptr [0x9f6a5a], ah
    app->getMemory<x86::reg8>(x86::reg32(10447450) /* 0x9f6a5a */) = cpu.ah;
    // 004fff0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fff14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4fff18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004fff18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004fff19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fff1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004fff1c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004fff1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004fff1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004fff20  e85b1e0200             -call 0x521d80
    cpu.esp -= 4;
    sub_521d80(app, cpu);
    if (cpu.terminate) return;
    // 004fff25  e8361f0200             -call 0x521e60
    cpu.esp -= 4;
    sub_521e60(app, cpu);
    if (cpu.terminate) return;
    // 004fff2a  e891200200             -call 0x521fc0
    cpu.esp -= 4;
    sub_521fc0(app, cpu);
    if (cpu.terminate) return;
    // 004fff2f  e86c210200             -call 0x5220a0
    cpu.esp -= 4;
    sub_5220a0(app, cpu);
    if (cpu.terminate) return;
    // 004fff34  ba286b9f00             -mov edx, 0x9f6b28
    cpu.edx = 10447656 /*0x9f6b28*/;
    // 004fff39  be30739f00             -mov esi, 0x9f7330
    cpu.esi = 10449712 /*0x9f7330*/;
    // 004fff3e  bf98b49f00             -mov edi, 0x9fb498
    cpu.edi = 10466456 /*0x9fb498*/;
    // 004fff43  8915a8bc9f00           -mov dword ptr [0x9fbca8], edx
    app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */) = cpu.edx;
    // 004fff49  8935acbc9f00           -mov dword ptr [0x9fbcac], esi
    app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */) = cpu.esi;
    // 004fff4f  893db0bc9f00           -mov dword ptr [0x9fbcb0], edi
    app->getMemory<x86::reg32>(x86::reg32(10468528) /* 0x9fbcb0 */) = cpu.edi;
    // 004fff55  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
L_0x004fff5a:
    // 004fff5a  a1a8bc9f00             -mov eax, dword ptr [0x9fbca8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 004fff5f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fff61  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fff64  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fff66  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fff68  751d                   -jne 0x4fff87
    if (!cpu.flags.zf)
    {
        goto L_0x004fff87;
    }
    // 004fff6a  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
L_0x004fff6f:
    // 004fff6f  a1acbc9f00             -mov eax, dword ptr [0x9fbcac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
    // 004fff74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fff76  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fff79  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fff7b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fff7d  7410                   -je 0x4fff8f
    if (cpu.flags.zf)
    {
        goto L_0x004fff8f;
    }
    // 004fff7f  ff05acbc9f00           +inc dword ptr [0x9fbcac]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fff85  ebe8                   -jmp 0x4fff6f
    goto L_0x004fff6f;
L_0x004fff87:
    // 004fff87  ff05a8bc9f00           +inc dword ptr [0x9fbca8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fff8d  ebcb                   -jmp 0x4fff5a
    goto L_0x004fff5a;
L_0x004fff8f:
    // 004fff8f  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
L_0x004fff94:
    // 004fff94  a1b0bc9f00             -mov eax, dword ptr [0x9fbcb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468528) /* 0x9fbcb0 */);
    // 004fff99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004fff9b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004fff9e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004fffa0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004fffa2  7408                   -je 0x4fffac
    if (cpu.flags.zf)
    {
        goto L_0x004fffac;
    }
    // 004fffa4  ff05b0bc9f00           +inc dword ptr [0x9fbcb0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(10468528) /* 0x9fbcb0 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004fffaa  ebe8                   -jmp 0x4fff94
    goto L_0x004fff94;
L_0x004fffac:
    // 004fffac  e8d3fdffff             -call 0x4ffd84
    cpu.esp -= 4;
    sub_4ffd84(app, cpu);
    if (cpu.terminate) return;
    // 004fffb1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004fffb3  891d1c6b9f00           -mov dword ptr [0x9f6b1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447644) /* 0x9f6b1c */) = cpu.ebx;
    // 004fffb9  e84a000000             -call 0x500008
    cpu.esp -= 4;
    sub_500008(app, cpu);
    if (cpu.terminate) return;
    // 004fffbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004fffc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004fffc1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004fffc2:
    // 004fffc2  05e40d0000             -add eax, 0xde4
    (cpu.eax) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004fffc7  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004fffc9  8890d0ae9f00           -mov byte ptr [eax + 0x9faed0], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10464976) /* 0x9faed0 */) = cpu.dl;
    // 004fffcf  3d40de0000             +cmp eax, 0xde40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56896 /*0xde40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004fffd4  75ec                   -jne 0x4fffc2
    if (!cpu.flags.zf)
    {
        goto L_0x004fffc2;
    }
    // 004fffd6  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004fffdb  8b0da8bc9f00           -mov ecx, dword ptr [0x9fbca8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 004fffe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004fffe2  ff155c6a9f00           -call dword ptr [0x9f6a5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004fffe8  8b1d606a9f00           -mov ebx, dword ptr [0x9f6a60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10447456) /* 0x9f6a60 */);
    // 004fffee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ffff1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ffff3  7505                   -jne 0x4ffffa
    if (!cpu.flags.zf)
    {
        goto L_0x004ffffa;
    }
    // 004ffff5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ffff7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffff8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ffff9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ffffa:
    // 004ffffa  ff15606a9f00           -call dword ptr [0x9f6a60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447456) /* 0x9f6a60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500000  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500002  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500003  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500004  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_500008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500008  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500009  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050000a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050000b  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050000d  7528                   -jne 0x500037
    if (!cpu.flags.zf)
    {
        goto L_0x00500037;
    }
    // 0050000f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00500011  753e                   -jne 0x500051
    if (!cpu.flags.zf)
    {
        goto L_0x00500051;
    }
    // 00500013  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00500015  7552                   -jne 0x500069
    if (!cpu.flags.zf)
    {
        goto L_0x00500069;
    }
    // 00500017  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00500019  7466                   -je 0x500081
    if (cpu.flags.zf)
    {
        goto L_0x00500081;
    }
    // 0050001b  a10c6b9f00             -mov eax, dword ptr [0x9f6b0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447628) /* 0x9f6b0c */);
    // 00500020  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00500025  a3206b9f00             -mov dword ptr [0x9f6b20], eax
    app->getMemory<x86::reg32>(x86::reg32(10447648) /* 0x9f6b20 */) = cpu.eax;
    // 0050002a  668915586a9f00         -mov word ptr [0x9f6a58], dx
    app->getMemory<x86::reg16>(x86::reg32(10447448) /* 0x9f6a58 */) = cpu.dx;
L_0x00500031:
    // 00500031  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00500033  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500034  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500035  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500036  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500037:
    // 00500037  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500038  a1186b9f00             -mov eax, dword ptr [0x9f6b18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447640) /* 0x9f6b18 */);
    // 0050003d  be00040000             -mov esi, 0x400
    cpu.esi = 1024 /*0x400*/;
    // 00500042  a3206b9f00             -mov dword ptr [0x9f6b20], eax
    app->getMemory<x86::reg32>(x86::reg32(10447648) /* 0x9f6b20 */) = cpu.eax;
    // 00500047  668935586a9f00         -mov word ptr [0x9f6a58], si
    app->getMemory<x86::reg16>(x86::reg32(10447448) /* 0x9f6a58 */) = cpu.si;
    // 0050004e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050004f  ebe0                   -jmp 0x500031
    goto L_0x00500031;
L_0x00500051:
    // 00500051  a1106b9f00             -mov eax, dword ptr [0x9f6b10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447632) /* 0x9f6b10 */);
    // 00500056  b900020000             -mov ecx, 0x200
    cpu.ecx = 512 /*0x200*/;
    // 0050005b  a3206b9f00             -mov dword ptr [0x9f6b20], eax
    app->getMemory<x86::reg32>(x86::reg32(10447648) /* 0x9f6b20 */) = cpu.eax;
    // 00500060  66890d586a9f00         -mov word ptr [0x9f6a58], cx
    app->getMemory<x86::reg16>(x86::reg32(10447448) /* 0x9f6a58 */) = cpu.cx;
    // 00500067  ebc8                   -jmp 0x500031
    goto L_0x00500031;
L_0x00500069:
    // 00500069  a1146b9f00             -mov eax, dword ptr [0x9f6b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447636) /* 0x9f6b14 */);
    // 0050006e  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00500073  a3206b9f00             -mov dword ptr [0x9f6b20], eax
    app->getMemory<x86::reg32>(x86::reg32(10447648) /* 0x9f6b20 */) = cpu.eax;
    // 00500078  66891d586a9f00         -mov word ptr [0x9f6a58], bx
    app->getMemory<x86::reg16>(x86::reg32(10447448) /* 0x9f6a58 */) = cpu.bx;
    // 0050007f  ebb0                   -jmp 0x500031
    goto L_0x00500031;
L_0x00500081:
    // 00500081  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 00500086  b994e15400             -mov ecx, 0x54e194
    cpu.ecx = 5562772 /*0x54e194*/;
    // 0050008b  bbbc000000             -mov ebx, 0xbc
    cpu.ebx = 188 /*0xbc*/;
    // 00500090  68a4e15400             -push 0x54e1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562788 /*0x54e1a4*/;
    cpu.esp -= 4;
    // 00500095  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050009b  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 005000a1  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005000a7  e8640ff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005000ac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005000af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005000b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005000b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005000b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005000b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5000b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005000b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005000b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005000ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005000bb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005000be  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005000c1  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 005000c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005000ca  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 005000cd  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005000cf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005000d1  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 005000d4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005000d6  81c6b4bc9f00           -add esi, 0x9fbcb4
    (cpu.esi) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 005000dc  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 005000df  0f856c010000           -jne 0x500251
    if (!cpu.flags.zf)
    {
        goto L_0x00500251;
    }
    // 005000e5  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 005000e8  0f849b010000           -je 0x500289
    if (cpu.flags.zf)
    {
        goto L_0x00500289;
    }
    // 005000ee  bf0c000000             -mov edi, 0xc
    cpu.edi = 12 /*0xc*/;
    // 005000f3  a1e86a9f00             -mov eax, dword ptr [0x9f6ae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447592) /* 0x9f6ae8 */);
    // 005000f8  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 005000fc  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00500100  83fd19                 +cmp ebp, 0x19
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500103  0f8f75010000           -jg 0x50027e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050027e;
    }
    // 00500109  8b2df86a9f00           -mov ebp, dword ptr [0x9f6af8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447608) /* 0x9f6af8 */);
L_0x0050010f:
    // 0050010f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00500111  0f8503020000           -jne 0x50031a
    if (!cpu.flags.zf)
    {
        goto L_0x0050031a;
    }
L_0x00500117:
    // 00500117  83f901                 +cmp ecx, 1
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
    // 0050011a  0f85c7020000           -jne 0x5003e7
    if (!cpu.flags.zf)
    {
        goto L_0x005003e7;
    }
    // 00500120  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 00500125  7e02                   -jle 0x500129
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500129;
    }
L_0x00500127:
    // 00500127  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00500129:
    // 00500129  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00500130  83b86c6a9f0000         +cmp dword ptr [eax + 0x9f6a6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10447468) /* 0x9f6a6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500137  0f84f2020000           -je 0x50042f
    if (cpu.flags.zf)
    {
        goto L_0x0050042f;
    }
    // 0050013d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050013f  8d86ac0d0000           -lea eax, [esi + 0xdac]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3500) /* 0xdac */);
    // 00500145  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500146  8d86a80d0000           -lea eax, [esi + 0xda8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    // 0050014c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050014d  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00500151  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00500155  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500156  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050015a  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050015e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050015f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00500163  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00500166  ff976c6a9f00           -call dword ptr [edi + 0x9f6a6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10447468) /* 0x9f6a6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0050016c:
    // 0050016c  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00500171  0f84eb020000           -je 0x500462
    if (cpu.flags.zf)
    {
        goto L_0x00500462;
    }
    // 00500177  8d86bc0d0000           -lea eax, [esi + 0xdbc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    // 0050017d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050017e  8d86c00d0000           -lea eax, [esi + 0xdc0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    // 00500184  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500185  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 0050018b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050018c  ff542410               -call dword ptr [esp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500190  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00500193  8d86dc0d0000           -lea eax, [esi + 0xddc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3548) /* 0xddc */);
    // 00500199  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050019a  8d86e00d0000           -lea eax, [esi + 0xde0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    // 005001a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001a1  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 005001a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001a8  ff542410               -call dword ptr [esp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005001ac  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x005001af:
    // 005001af  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005001b1  0f84dd020000           -je 0x500494
    if (cpu.flags.zf)
    {
        goto L_0x00500494;
    }
    // 005001b7  8d86b80d0000           -lea eax, [esi + 0xdb8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    // 005001bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001be  8d86b40d0000           -lea eax, [esi + 0xdb4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    // 005001c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001c5  8d86b00d0000           -lea eax, [esi + 0xdb0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    // 005001cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001cc  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 005001d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001d3  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005001d5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x005001d8:
    // 005001d8  817c243000000800       +cmp dword ptr [esp + 0x30], 0x80000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005001e0  7608                   -jbe 0x5001ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005001ea;
    }
    // 005001e2  c744243000000800       -mov dword ptr [esp + 0x30], 0x80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 524288 /*0x80000*/;
L_0x005001ea:
    // 005001ea  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 005001ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001ef  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 005001f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005001f6  ff96b00d0000           -call dword ptr [esi + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005001fc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005001ff  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00500203  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00500206  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050020a  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0050020d  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00500211  884604                 -mov byte ptr [esi + 4], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 00500214  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00500218  884605                 -mov byte ptr [esi + 5], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 0050021b  8a442438               -mov al, byte ptr [esp + 0x38]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050021f  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00500222  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500224  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00500228  e827040000             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 0050022d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050022e  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00500232  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500233  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 00500239  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050023a  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500240  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00500243  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 00500246  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500248  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050024b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050024c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050024d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050024e  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x00500251:
    // 00500251  a1e46a9f00             -mov eax, dword ptr [0x9f6ae4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447588) /* 0x9f6ae4 */);
    // 00500256  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050025a  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050025e  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 00500263  83f819                 +cmp eax, 0x19
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500266  7f0b                   -jg 0x500273
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00500273;
    }
    // 00500268  8b2df46a9f00           -mov ebp, dword ptr [0x9f6af4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447604) /* 0x9f6af4 */);
    // 0050026e  e99cfeffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x00500273:
    // 00500273  8b2d046b9f00           -mov ebp, dword ptr [0x9f6b04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447620) /* 0x9f6b04 */);
    // 00500279  e991feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x0050027e:
    // 0050027e  8b2d086b9f00           -mov ebp, dword ptr [0x9f6b08]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447624) /* 0x9f6b08 */);
    // 00500284  e986feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x00500289:
    // 00500289  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0050028c  742a                   -je 0x5002b8
    if (cpu.flags.zf)
    {
        goto L_0x005002b8;
    }
    // 0050028e  a1dc6a9f00             -mov eax, dword ptr [0x9f6adc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447580) /* 0x9f6adc */);
    // 00500293  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00500297  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050029b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050029d  83f819                 +cmp eax, 0x19
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005002a0  7f0b                   -jg 0x5002ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005002ad;
    }
    // 005002a2  8b2dec6a9f00           -mov ebp, dword ptr [0x9f6aec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447596) /* 0x9f6aec */);
    // 005002a8  e962feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x005002ad:
    // 005002ad  8b2dfc6a9f00           -mov ebp, dword ptr [0x9f6afc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447612) /* 0x9f6afc */);
    // 005002b3  e957feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x005002b8:
    // 005002b8  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 005002bb  742d                   -je 0x5002ea
    if (cpu.flags.zf)
    {
        goto L_0x005002ea;
    }
    // 005002bd  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 005002c2  a1e06a9f00             -mov eax, dword ptr [0x9f6ae0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10447584) /* 0x9f6ae0 */);
    // 005002c7  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 005002cb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005002cf  83fd19                 +cmp ebp, 0x19
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005002d2  7f0b                   -jg 0x5002df
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005002df;
    }
    // 005002d4  8b2df06a9f00           -mov ebp, dword ptr [0x9f6af0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447600) /* 0x9f6af0 */);
    // 005002da  e930feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x005002df:
    // 005002df  8b2d006b9f00           -mov ebp, dword ptr [0x9f6b00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10447616) /* 0x9f6b00 */);
    // 005002e5  e925feffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x005002ea:
    // 005002ea  c7059021550084e15400   -mov dword ptr [0x552190], 0x54e184
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5562756 /*0x54e184*/;
    // 005002f4  c70594215500cce15400   -mov dword ptr [0x552194], 0x54e1cc
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5562828 /*0x54e1cc*/;
    // 005002fe  b805010000             -mov eax, 0x105
    cpu.eax = 261 /*0x105*/;
    // 00500303  68dce15400             -push 0x54e1dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562844 /*0x54e1dc*/;
    cpu.esp -= 4;
    // 00500308  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050030d  e8fe0cf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500312  83c404                 +add esp, 4
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
    // 00500315  e9f5fdffff             -jmp 0x50010f
    goto L_0x0050010f;
L_0x0050031a:
    // 0050031a  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050031d  7550                   -jne 0x50036f
    if (!cpu.flags.zf)
    {
        goto L_0x0050036f;
    }
    // 0050031f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00500322  740a                   -je 0x50032e
    if (cpu.flags.zf)
    {
        goto L_0x0050032e;
    }
    // 00500324  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 00500329  e9e9fdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x0050032e:
    // 0050032e  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00500331  740a                   -je 0x50033d
    if (cpu.flags.zf)
    {
        goto L_0x0050033d;
    }
    // 00500333  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 00500338  e9dafdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x0050033d:
    // 0050033d  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 00500342  bbcce15400             -mov ebx, 0x54e1cc
    cpu.ebx = 5562828 /*0x54e1cc*/;
    // 00500347  b81d010000             -mov eax, 0x11d
    cpu.eax = 285 /*0x11d*/;
    // 0050034c  6808e25400             -push 0x54e208
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562888 /*0x54e208*/;
    cpu.esp -= 4;
    // 00500351  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00500357  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050035d  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00500362  e8a90cf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500367  83c404                 +add esp, 4
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
    // 0050036a  e9a8fdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x0050036f:
    // 0050036f  83fb09                 +cmp ebx, 9
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
    // 00500372  7541                   -jne 0x5003b5
    if (!cpu.flags.zf)
    {
        goto L_0x005003b5;
    }
    // 00500374  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00500377  740a                   -je 0x500383
    if (cpu.flags.zf)
    {
        goto L_0x00500383;
    }
    // 00500379  bf18000000             -mov edi, 0x18
    cpu.edi = 24 /*0x18*/;
    // 0050037e  e994fdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x00500383:
    // 00500383  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 00500388  bbcce15400             -mov ebx, 0x54e1cc
    cpu.ebx = 5562828 /*0x54e1cc*/;
    // 0050038d  b82b010000             -mov eax, 0x12b
    cpu.eax = 299 /*0x12b*/;
    // 00500392  6808e25400             -push 0x54e208
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562888 /*0x54e208*/;
    cpu.esp -= 4;
    // 00500397  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050039d  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005003a3  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 005003a8  e8630cf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005003ad  83c404                 +add esp, 4
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
    // 005003b0  e962fdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x005003b5:
    // 005003b5  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 005003ba  bbcce15400             -mov ebx, 0x54e1cc
    cpu.ebx = 5562828 /*0x54e1cc*/;
    // 005003bf  b842010000             -mov eax, 0x142
    cpu.eax = 322 /*0x142*/;
    // 005003c4  682ce25400             -push 0x54e22c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562924 /*0x54e22c*/;
    cpu.esp -= 4;
    // 005003c9  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005003cf  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005003d5  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 005003da  e8310cf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005003df  83c404                 +add esp, 4
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
    // 005003e2  e930fdffff             -jmp 0x500117
    goto L_0x00500117;
L_0x005003e7:
    // 005003e7  83f902                 +cmp ecx, 2
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
    // 005003ea  0f8437fdffff           -je 0x500127
    if (cpu.flags.zf)
    {
        goto L_0x00500127;
    }
    // 005003f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005003f2  7508                   -jne 0x5003fc
    if (!cpu.flags.zf)
    {
        goto L_0x005003fc;
    }
    // 005003f4  83c703                 +add edi, 3
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005003f7  e92dfdffff             -jmp 0x500129
    goto L_0x00500129;
L_0x005003fc:
    // 005003fc  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 00500401  b9cce15400             -mov ecx, 0x54e1cc
    cpu.ecx = 5562828 /*0x54e1cc*/;
    // 00500406  bb5a010000             -mov ebx, 0x15a
    cpu.ebx = 346 /*0x15a*/;
    // 0050040b  685ce25400             -push 0x54e25c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5562972 /*0x54e25c*/;
    cpu.esp -= 4;
    // 00500410  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00500416  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 0050041c  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00500422  e8e90bf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500427  83c404                 +add esp, 4
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
    // 0050042a  e9fafcffff             -jmp 0x500129
    goto L_0x00500129;
L_0x0050042f:
    // 0050042f  b984e15400             -mov ecx, 0x54e184
    cpu.ecx = 5562756 /*0x54e184*/;
    // 00500434  bbcce15400             -mov ebx, 0x54e1cc
    cpu.ebx = 5562828 /*0x54e1cc*/;
    // 00500439  bf78010000             -mov edi, 0x178
    cpu.edi = 376 /*0x178*/;
    // 0050043e  6884e25400             -push 0x54e284
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563012 /*0x54e284*/;
    cpu.esp -= 4;
    // 00500443  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00500449  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050044f  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00500455  e8b60bf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050045a  83c404                 +add esp, 4
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
    // 0050045d  e90afdffff             -jmp 0x50016c
    goto L_0x0050016c;
L_0x00500462:
    // 00500462  bb84e15400             -mov ebx, 0x54e184
    cpu.ebx = 5562756 /*0x54e184*/;
    // 00500467  bfcce15400             -mov edi, 0x54e1cc
    cpu.edi = 5562828 /*0x54e1cc*/;
    // 0050046c  b88a010000             -mov eax, 0x18a
    cpu.eax = 394 /*0x18a*/;
    // 00500471  68a8e25400             -push 0x54e2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563048 /*0x54e2a8*/;
    cpu.esp -= 4;
    // 00500476  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050047c  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00500482  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00500487  e8840bf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050048c  83c404                 +add esp, 4
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
    // 0050048f  e91bfdffff             -jmp 0x5001af
    goto L_0x005001af;
L_0x00500494:
    // 00500494  ba84e15400             -mov edx, 0x54e184
    cpu.edx = 5562756 /*0x54e184*/;
    // 00500499  b9cce15400             -mov ecx, 0x54e1cc
    cpu.ecx = 5562828 /*0x54e1cc*/;
    // 0050049e  bb97010000             -mov ebx, 0x197
    cpu.ebx = 407 /*0x197*/;
    // 005004a3  68d4e25400             -push 0x54e2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563092 /*0x54e2d4*/;
    cpu.esp -= 4;
    // 005004a8  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005004ae  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 005004b4  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005004ba  e8510bf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005004bf  83c404                 +add esp, 4
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
    // 005004c2  e911fdffff             -jmp 0x5001d8
    goto L_0x005001d8;
}

/* align: skip 0x90 */
void Application::sub_5004c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005004c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005004c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005004ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005004cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005004cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005004cd  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005004d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005004d2  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 005004d4  05900d0000             -add eax, 0xd90
    (cpu.eax) += x86::reg32(x86::sreg32(3472 /*0xd90*/));
    // 005004d9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005004dd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005004df  05640d0000             -add eax, 0xd64
    (cpu.eax) += x86::reg32(x86::sreg32(3428 /*0xd64*/));
    // 005004e4  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005004e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005004ea  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005004ed  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005004ef  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x005004f3:
    // 005004f3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 005004f6  3a4604                 +cmp al, byte ptr [esi + 4]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005004f9  0f84c8000000           -je 0x5005c7
    if (cpu.flags.zf)
    {
        goto L_0x005005c7;
    }
L_0x005004ff:
    // 005004ff  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00500501  0f84cc000000           -je 0x5005d3
    if (cpu.flags.zf)
    {
        goto L_0x005005d3;
    }
    // 00500507  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050050a  8a7604                 -mov dh, byte ptr [esi + 4]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050050d  4d                     -dec ebp
    (cpu.ebp)--;
    // 0050050e  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00500510  0f85c8000000           -jne 0x5005de
    if (!cpu.flags.zf)
    {
        goto L_0x005005de;
    }
L_0x00500516:
    // 00500516  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00500519  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050051c  7406                   -je 0x500524
    if (cpu.flags.zf)
    {
        goto L_0x00500524;
    }
    // 0050051e  8a4607                 -mov al, byte ptr [esi + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 00500521  004602                 -add byte ptr [esi + 2], al
    (app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)) += x86::reg8(x86::sreg8(cpu.al));
L_0x00500524:
    // 00500524  0fbe4602               -movsx eax, byte ptr [esi + 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)));
    // 00500528  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500529  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 0050052d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050052e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00500532  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500533  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500539  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050053c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050053e  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00500542  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500543  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500549  8b1dacbc9f00           -mov ebx, dword ptr [0x9fbcac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
    // 0050054f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00500552  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500554  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00500558  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050055b  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500561  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00500563  7e6e                   -jle 0x5005d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005005d3;
    }
    // 00500565  a1b0bc9f00             -mov eax, dword ptr [0x9fbcb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468528) /* 0x9fbcb0 */);
    // 0050056a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050056d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050056f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500570  a1acbc9f00             -mov eax, dword ptr [0x9fbcac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
    // 00500575  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00500578  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500579  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050057b  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050057f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500580  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500586  8b0d576a9f00           -mov ecx, dword ptr [0x9f6a57]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10447447) /* 0x9f6a57 */);
    // 0050058c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050058e  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00500591  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00500593  8b0da8bc9f00           -mov ecx, dword ptr [0x9fbca8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 00500599  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050059c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050059f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005005a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005005a2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005005a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005005a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005005a9  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005005ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005005ae  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005005b4  8b0d646a9f00           -mov ecx, dword ptr [0x9f6a64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10447460) /* 0x9f6a64 */);
    // 005005ba  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005005bd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005005bf  7528                   -jne 0x5005e9
    if (!cpu.flags.zf)
    {
        goto L_0x005005e9;
    }
    // 005005c1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005005c2  e92cffffff             -jmp 0x5004f3
    goto L_0x005004f3;
L_0x005005c7:
    // 005005c7  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 005005ca  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005005cd  0f852cffffff           -jne 0x5004ff
    if (!cpu.flags.zf)
    {
        goto L_0x005004ff;
    }
L_0x005005d3:
    // 005005d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005005d5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005005d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005005d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005005da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005005db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005005dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005005dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005005de:
    // 005005de  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 005005e1  004601                 +add byte ptr [esi + 1], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005005e4  e92dffffff             -jmp 0x500516
    goto L_0x00500516;
L_0x005005e9:
    // 005005e9  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 005005ec  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005005f1  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 005005f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005005f5  ff15646a9f00           -call dword ptr [0x9f6a64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447460) /* 0x9f6a64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005005fb  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005005fc  e9f2feffff             -jmp 0x5004f3
    goto L_0x005004f3;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_500604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500604  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500605  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500606  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500607  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500608  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00500609  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050060b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050060e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500610  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00500613  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00500615  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500617  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0050061a  bfb4bc9f00             -mov edi, 0x9fbcb4
    cpu.edi = 10468532 /*0x9fbcb4*/;
    // 0050061f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00500621  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00500623  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00500625  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00500627  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500629  e876000000             -call 0x5006a4
    cpu.esp -= 4;
    sub_5006a4(app, cpu);
    if (cpu.terminate) return;
    // 0050062e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00500633  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00500635  e88efeffff             -call 0x5004c8
    cpu.esp -= 4;
    sub_5004c8(app, cpu);
    if (cpu.terminate) return;
    // 0050063a  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500640  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500642  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 00500645  ff151c6b9f00           -call dword ptr [0x9f6b1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447644) /* 0x9f6b1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050064b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050064d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050064e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050064f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500650  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500651  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_500654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500654  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500655  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00500658  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0050065a  7505                   -jne 0x500661
    if (!cpu.flags.zf)
    {
        goto L_0x00500661;
    }
    // 0050065c  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0050065f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500660  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500661:
    // 00500661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500662  8b5001                 -mov edx, dword ptr [eax + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00500665  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00500668  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0050066b  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0050066e  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00500670  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00500672  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00500675  8b4805                 -mov ecx, dword ptr [eax + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00500678  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050067a  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0050067d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00500680  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00500683  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 00500686  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00500689  8b5005                 -mov edx, dword ptr [eax + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0050068c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0050068f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500690  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500691  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 00500697  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500698  ff90dc0d0000           -call dword ptr [eax + 0xddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3548) /* 0xddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050069e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005006a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005006a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005006a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5006a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005006a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005006a5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005006a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005006aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005006ac  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005006af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005006b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005006b3  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 005006b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005006b8  05b4bc9f00             -add eax, 0x9fbcb4
    (cpu.eax) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 005006bd  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 005006c0  0fbe5001               -movsx edx, byte ptr [eax + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */)));
    // 005006c4  885805                 -mov byte ptr [eax + 5], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 005006c7  39ca                   +cmp edx, ecx
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
    // 005006c9  7c19                   -jl 0x5006e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005006e4;
    }
    // 005006cb  c64006ff               -mov byte ptr [eax + 6], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 255 /*0xff*/;
L_0x005006cf:
    // 005006cf  0fbe5002               -movsx edx, byte ptr [eax + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */)));
    // 005006d3  39da                   +cmp edx, ebx
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
    // 005006d5  7d13                   -jge 0x5006ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005006ea;
    }
    // 005006d7  c6400701               -mov byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 1 /*0x1*/;
    // 005006db  e874ffffff             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 005006e0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005006e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005006e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005006e4:
    // 005006e4  c6400601               -mov byte ptr [eax + 6], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 005006e8  ebe5                   -jmp 0x5006cf
    goto L_0x005006cf;
L_0x005006ea:
    // 005006ea  c64007ff               -mov byte ptr [eax + 7], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 255 /*0xff*/;
    // 005006ee  e861ffffff             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 005006f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005006f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005006f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5006f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005006f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005006f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005006fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005006fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005006fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005006fd  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00500700  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00500704  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00500708  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050070a  bfb4bc9f00             -mov edi, 0x9fbcb4
    cpu.edi = 10468532 /*0x9fbcb4*/;
    // 0050070f  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00500713:
    // 00500713  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00500715  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00500717  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00500719  7558                   -jne 0x500773
    if (!cpu.flags.zf)
    {
        goto L_0x00500773;
    }
L_0x0050071b:
    // 0050071b  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050071f  46                     -inc esi
    (cpu.esi)++;
    // 00500720  81c7e40d0000           -add edi, 0xde4
    (cpu.edi) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 00500726  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0050072a  83fe10                 +cmp esi, 0x10
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
    // 0050072d  7ce4                   -jl 0x500713
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500713;
    }
L_0x0050072f:
    // 0050072f  833d686a9f0000         +cmp dword ptr [0x9f6a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10447464) /* 0x9f6a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500736  0f8512010000           -jne 0x50084e
    if (!cpu.flags.zf)
    {
        goto L_0x0050084e;
    }
L_0x0050073c:
    // 0050073c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00500740  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500741  8b0da8bc9f00           -mov ecx, dword ptr [0x9fbca8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 00500747  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500748  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050074c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050074d  ff15206b9f00           -call dword ptr [0x9f6b20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447648) /* 0x9f6b20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500753  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00500756  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00500759  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050075a  8b35a8bc9f00           -mov esi, dword ptr [0x9fbca8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 00500760  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500761  ff155c6a9f00           -call dword ptr [0x9f6a5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447452) /* 0x9f6a5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500767  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050076a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050076d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050076e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050076f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500770  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500771  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500772  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500773:
    // 00500773  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00500777  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00500779  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050077d  e846fdffff             -call 0x5004c8
    cpu.esp -= 4;
    sub_5004c8(app, cpu);
    if (cpu.terminate) return;
    // 00500782  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00500786  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500788  74a5                   -je 0x50072f
    if (cpu.flags.zf)
    {
        goto L_0x0050072f;
    }
    // 0050078a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050078b  8d87640d0000           -lea eax, [edi + 0xd64]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(3428) /* 0xd64 */);
    // 00500791  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500792  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500798  8b1dacbc9f00           -mov ebx, dword ptr [0x9fbcac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
    // 0050079e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005007a1  8d4f0c                 -lea ecx, [edi + 0xc]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 005007a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005007a6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005007a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005007ab  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005007b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005007b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005007b5  0f8c85000000           -jl 0x500840
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500840;
    }
L_0x005007bb:
    // 005007bb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005007bd  0f8e58ffffff           -jle 0x50071b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050071b;
    }
    // 005007c3  a1b0bc9f00             -mov eax, dword ptr [0x9fbcb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468528) /* 0x9fbcb0 */);
    // 005007c8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005007cb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005007cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005007ce  a1acbc9f00             -mov eax, dword ptr [0x9fbcac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468524) /* 0x9fbcac */);
    // 005007d3  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005007d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005007d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005007d8  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 005007de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005007df  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005007e5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005007e8  8b0d576a9f00           -mov ecx, dword ptr [0x9f6a57]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10447447) /* 0x9f6a57 */);
    // 005007ee  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005007f2  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 005007f5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005007f7  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 005007fe  a1a8bc9f00             -mov eax, dword ptr [0x9fbca8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 00500803  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00500805  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500806  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050080a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050080b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050080c  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 00500812  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00500813  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500819  8b1d646a9f00           -mov ebx, dword ptr [0x9f6a64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10447460) /* 0x9f6a64 */);
    // 0050081f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00500822  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00500824  0f84f1feffff           -je 0x50071b
    if (cpu.flags.zf)
    {
        goto L_0x0050071b;
    }
    // 0050082a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050082e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00500831  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00500833  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500835  ff15646a9f00           -call dword ptr [0x9f6a64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447460) /* 0x9f6a64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050083b  e9dbfeffff             -jmp 0x50071b
    goto L_0x0050071b;
L_0x00500840:
    // 00500840  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00500844  e8bbfdffff             -call 0x500604
    cpu.esp -= 4;
    sub_500604(app, cpu);
    if (cpu.terminate) return;
    // 00500849  e96dffffff             -jmp 0x5007bb
    goto L_0x005007bb;
L_0x0050084e:
    // 0050084e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00500852  8b15a8bc9f00           -mov edx, dword ptr [0x9fbca8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10468520) /* 0x9fbca8 */);
    // 00500858  ff15686a9f00           -call dword ptr [0x9f6a68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447464) /* 0x9f6a68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050085e  e9d9feffff             -jmp 0x50073c
    goto L_0x0050073c;
}

/* align: skip 0x90 */
void Application::sub_500864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500864  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500865  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500866  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00500868  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050086a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050086c  7e2a                   -jle 0x500898
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500898;
    }
L_0x0050086e:
    // 0050086e  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500874  7e25                   -jle 0x50089b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050089b;
    }
    // 00500876  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
L_0x0050087b:
    // 0050087b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050087d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050087f  e874feffff             -call 0x5006f8
    cpu.esp -= 4;
    sub_5006f8(app, cpu);
    if (cpu.terminate) return;
    // 00500884  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500886  66a1586a9f00           -mov ax, word ptr [0x9f6a58]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10447448) /* 0x9f6a58 */);
    // 0050088c  81e900010000           -sub ecx, 0x100
    (cpu.ecx) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00500892  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00500894  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00500896  7fd6                   -jg 0x50086e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050086e;
    }
L_0x00500898:
    // 00500898  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500899  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050089a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050089b:
    // 0050089b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050089d  ebdc                   -jmp 0x50087b
    goto L_0x0050087b;
}

/* align: skip 0x00 */
void Application::sub_5008a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005008a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005008a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005008a3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 005008a4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005008a7  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005008aa  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005008ad  83f907                 +cmp ecx, 7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005008b0  7e42                   -jle 0x5008f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005008f4;
    }
    // 005008b2  83e907                 -sub ecx, 7
    (cpu.ecx) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x005008b5:
    // 005008b5  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 005008b7  df4702                 -fild word ptr [edi + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */))));
    // 005008ba  df4704                 -fild word ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 005008bd  df4706                 -fild word ptr [edi + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */))));
    // 005008c0  df4708                 -fild word ptr [edi + 8]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 005008c3  df470a                 -fild word ptr [edi + 0xa]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */))));
    // 005008c6  df470c                 -fild word ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 005008c9  df470e                 -fild word ptr [edi + 0xe]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */))));
    // 005008cc  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 005008ce  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008d1  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008d4  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008d7  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008da  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008dd  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008e0  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008e3  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008e6  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005008e9  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005008ec  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005008ef  7fc4                   -jg 0x5008b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005008b5;
    }
    // 005008f1  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x005008f4:
    // 005008f4  83f900                 +cmp ecx, 0
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
    // 005008f7  7e10                   -jle 0x500909
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500909;
    }
    // 005008f9  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 005008fb  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005008fe  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00500901  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00500904  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500907  7feb                   -jg 0x5008f4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005008f4;
    }
L_0x00500909:
    // 00500909  61                     -popal 
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
    // 0050090a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050090b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_500910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500911  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00500914  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00500918  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050091c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0050091f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00500923  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00500925  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00500927  39d9                   +cmp ecx, ebx
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
    // 00500929  7348                   -jae 0x500973
    if (!cpu.flags.cf)
    {
        goto L_0x00500973;
    }
L_0x0050092b:
    // 0050092b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0050092e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 00500930  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00500932  dc0d04e35400           -fmul qword ptr [0x54e304]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5563140) /* 0x54e304 */));
    // 00500938  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 0050093a  dc050ce35400           -fadd qword ptr [0x54e30c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5563148) /* 0x54e30c */));
    // 00500940  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500942  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500944  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00500946  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0050094c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050094f  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500955  7628                   -jbe 0x50097f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050097f;
    }
    // 00500957  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050095d  7320                   -jae 0x50097f
    if (!cpu.flags.cf)
    {
        goto L_0x0050097f;
    }
    // 0050095f  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500965  7311                   -jae 0x500978
    if (!cpu.flags.cf)
    {
        goto L_0x00500978;
    }
    // 00500967  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x0050096c:
    // 0050096c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050096f  39d8                   +cmp eax, ebx
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
    // 00500971  72b8                   -jb 0x50092b
    if (cpu.flags.cf)
    {
        goto L_0x0050092b;
    }
L_0x00500973:
    // 00500973  83c408                 +add esp, 8
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
    // 00500976  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500977  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500978:
    // 00500978  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 0050097d  ebed                   -jmp 0x50096c
    goto L_0x0050096c;
L_0x0050097f:
    // 0050097f  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00500982  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00500985  39d8                   +cmp eax, ebx
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
    // 00500987  72a2                   -jb 0x50092b
    if (cpu.flags.cf)
    {
        goto L_0x0050092b;
    }
    // 00500989  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050098c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050098d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_500990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500990  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00500991  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00500993  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00500994  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00500997  8b7e14                 -mov edi, dword ptr [esi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050099a  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050099d  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005009a0  891570785600           -mov dword ptr [0x567870], edx
    app->getMemory<x86::reg32>(x86::reg32(5666928) /* 0x567870 */) = cpu.edx;
    // 005009a6  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 005009a9  891574785600           -mov dword ptr [0x567874], edx
    app->getMemory<x86::reg32>(x86::reg32(5666932) /* 0x567874 */) = cpu.edx;
    // 005009af  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005009b2  891578785600           -mov dword ptr [0x567878], edx
    app->getMemory<x86::reg32>(x86::reg32(5666936) /* 0x567878 */) = cpu.edx;
    // 005009b8  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005009bb  89157c785600           -mov dword ptr [0x56787c], edx
    app->getMemory<x86::reg32>(x86::reg32(5666940) /* 0x56787c */) = cpu.edx;
L_0x005009c1:
    // 005009c1  833e00                 +cmp dword ptr [esi], 0
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
    // 005009c4  0f8e17010000           -jle 0x500ae1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500ae1;
    }
    // 005009ca  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005009cd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005009cf  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005009d1  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 005009d3  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 005009d5  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 005009d8  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 005009db  d9049d60ad5600         -fld dword ptr [ebx*4 + 0x56ad60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680480) /* 0x56ad60 */ + cpu.ebx * 4)));
    // 005009e2  d9049d50ad5600         -fld dword ptr [ebx*4 + 0x56ad50]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680464) /* 0x56ad50 */ + cpu.ebx * 4)));
    // 005009e9  d9048560ad5600         -fld dword ptr [eax*4 + 0x56ad60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680480) /* 0x56ad60 */ + cpu.eax * 4)));
    // 005009f0  d9048550ad5600         -fld dword ptr [eax*4 + 0x56ad50]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680464) /* 0x56ad50 */ + cpu.eax * 4)));
    // 005009f7  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 005009fa  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 005009fd  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00500a00  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00500a03  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00500a06  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 00500a09  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00500a0c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00500a0e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00500a13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500a14  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00500a16:
    // 00500a16  d90570785600           -fld dword ptr [0x567870]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666928) /* 0x567870 */)));
    // 00500a1c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00500a1e  d90578785600           -fld dword ptr [0x567878]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666936) /* 0x567878 */)));
    // 00500a24  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00500a26  d90574785600           -fld dword ptr [0x567874]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666932) /* 0x567874 */)));
    // 00500a2c  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00500a2e  d9057c785600           -fld dword ptr [0x56787c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666940) /* 0x56787c */)));
    // 00500a34  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 00500a36  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500a38  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500a3a  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 00500a3c  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00500a3e  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 00500a41  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00500a44  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500a46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500a48  d88490a0baa000         -fadd dword ptr [eax + edx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.edx * 4));
    // 00500a4f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500a51  d8849ea0baa000         -fadd dword ptr [esi + ebx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.ebx * 4));
    // 00500a58  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500a5a  d95500                 -fst dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    // 00500a5d  d91d74785600           -fstp dword ptr [0x567874]
    app->getMemory<float>(x86::reg32(5666932) /* 0x567874 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500a63  d95504                 -fst dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 00500a66  d91d7c785600           -fstp dword ptr [0x56787c]
    app->getMemory<float>(x86::reg32(5666940) /* 0x56787c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500a6c  d90574785600           -fld dword ptr [0x567874]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666932) /* 0x567874 */)));
    // 00500a72  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00500a74  d9057c785600           -fld dword ptr [0x56787c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666940) /* 0x56787c */)));
    // 00500a7a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00500a7c  d90570785600           -fld dword ptr [0x567870]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666928) /* 0x567870 */)));
    // 00500a82  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00500a84  d90578785600           -fld dword ptr [0x567878]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666936) /* 0x567878 */)));
    // 00500a8a  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 00500a8c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500a8e  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500a90  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00500a93  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00500a96  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 00500a99  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00500a9c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500a9e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500aa0  d88490a0baa000         -fadd dword ptr [eax + edx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.edx * 4));
    // 00500aa7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500aa9  d8849ea0baa000         -fadd dword ptr [esi + ebx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.ebx * 4));
    // 00500ab0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500ab2  d95508                 -fst dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 00500ab5  d91d70785600           -fstp dword ptr [0x567870]
    app->getMemory<float>(x86::reg32(5666928) /* 0x567870 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500abb  d9550c                 -fst dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 00500abe  d91d78785600           -fstp dword ptr [0x567878]
    app->getMemory<float>(x86::reg32(5666936) /* 0x567878 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500ac4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00500ac7  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00500aca  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500acd  0f8f43ffffff           -jg 0x500a16
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00500a16;
    }
    // 00500ad3  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500ad5  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500ad7  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500ad9  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500adb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500adc  e9e0feffff             -jmp 0x5009c1
    goto L_0x005009c1;
L_0x00500ae1:
    // 00500ae1  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00500ae4  8b1570785600           -mov edx, dword ptr [0x567870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666928) /* 0x567870 */);
    // 00500aea  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00500aed  8b1574785600           -mov edx, dword ptr [0x567874]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666932) /* 0x567874 */);
    // 00500af3  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00500af6  8b1578785600           -mov edx, dword ptr [0x567878]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666936) /* 0x567878 */);
    // 00500afc  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00500aff  8b157c785600           -mov edx, dword ptr [0x56787c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666940) /* 0x56787c */);
    // 00500b05  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00500b08  61                     -popal 
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
    // 00500b09  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500b0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_500b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500b10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00500b11  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00500b13  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00500b14  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00500b17  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00500b1a  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00500b1d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500b1f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00500b21  83f903                 +cmp ecx, 3
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
    // 00500b24  7e44                   -jle 0x500b6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500b6a;
    }
    // 00500b26  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00500b29:
    // 00500b29  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00500b2b  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00500b2e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00500b31  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00500b34  8b1c85a0c2a000         -mov ebx, dword ptr [eax*4 + 0xa0c2a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.eax * 4);
    // 00500b3b  8b3495a0c2a000         -mov esi, dword ptr [edx*4 + 0xa0c2a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.edx * 4);
    // 00500b42  8a47fe                 -mov al, byte ptr [edi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 00500b45  8a57ff                 -mov dl, byte ptr [edi - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00500b48  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00500b4b  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00500b4e  8b1c85a0c2a000         -mov ebx, dword ptr [eax*4 + 0xa0c2a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.eax * 4);
    // 00500b55  8b3495a0c2a000         -mov esi, dword ptr [edx*4 + 0xa0c2a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.edx * 4);
    // 00500b5c  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00500b5f  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00500b62  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500b65  7fc2                   -jg 0x500b29
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00500b29;
    }
    // 00500b67  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00500b6a:
    // 00500b6a  83f900                 +cmp ecx, 0
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
    // 00500b6d  7e17                   -jle 0x500b86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500b86;
    }
    // 00500b6f  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00500b71  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00500b74  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00500b77  8b1c85a0c2a000         -mov ebx, dword ptr [eax*4 + 0xa0c2a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10535584) /* 0xa0c2a0 */ + cpu.eax * 4);
    // 00500b7e  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00500b81  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500b84  7fe4                   -jg 0x500b6a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00500b6a;
    }
L_0x00500b86:
    // 00500b86  61                     -popal 
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
    // 00500b87  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500b88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_500b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500b90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00500b91  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00500b93  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00500b94  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00500b97  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00500b9a  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00500b9d  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00500ba0  891580785600           -mov dword ptr [0x567880], edx
    app->getMemory<x86::reg32>(x86::reg32(5666944) /* 0x567880 */) = cpu.edx;
    // 00500ba6  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00500ba9  891584785600           -mov dword ptr [0x567884], edx
    app->getMemory<x86::reg32>(x86::reg32(5666948) /* 0x567884 */) = cpu.edx;
L_0x00500baf:
    // 00500baf  833e00                 +cmp dword ptr [esi], 0
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
    // 00500bb2  0f8ea7000000           -jle 0x500c5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00500c5f;
    }
    // 00500bb8  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00500bbb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500bbd  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00500bbf  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00500bc2  d9048560ad5600         -fld dword ptr [eax*4 + 0x56ad60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680480) /* 0x56ad60 */ + cpu.eax * 4)));
    // 00500bc9  d9048550ad5600         -fld dword ptr [eax*4 + 0x56ad50]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5680464) /* 0x56ad50 */ + cpu.eax * 4)));
    // 00500bd0  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00500bd2  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00500bd5  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00500bd8  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00500bdb  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00500bdd  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 00500be2  d90584785600           -fld dword ptr [0x567884]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666948) /* 0x567884 */)));
    // 00500be8  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00500bea  d90580785600           -fld dword ptr [0x567880]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666944) /* 0x567880 */)));
    // 00500bf0  d90580785600           -fld dword ptr [0x567880]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666944) /* 0x567880 */)));
    // 00500bf6  d90584785600           -fld dword ptr [0x567884]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5666948) /* 0x567884 */)));
    // 00500bfc  83c70e                 -add edi, 0xe
    (cpu.edi) += x86::reg32(x86::sreg32(14 /*0xe*/));
    // 00500bff  83c370                 -add ebx, 0x70
    (cpu.ebx) += x86::reg32(x86::sreg32(112 /*0x70*/));
L_0x00500c02:
    // 00500c02  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500c04  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00500c06  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 00500c09  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 00500c0c  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500c0e  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00500c10  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500c12  d88490a0baa000         -fadd dword ptr [eax + edx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.edx * 4));
    // 00500c19  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00500c1b  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 00500c1e  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00500c20  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00500c22  d914cb                 -fst dword ptr [ebx + ecx*8]
    app->getMemory<float>(cpu.ebx + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 00500c25  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00500c27  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500c29  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 00500c2b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500c2d  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00500c2f  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 00500c32  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00500c34  d88490a0baa000         +fadd dword ptr [eax + edx*4 + 0xa0baa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(10533536) /* 0xa0baa0 */ + cpu.edx * 4));
    // 00500c3b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00500c3d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00500c3f  d954cb04               +fst dword ptr [ebx + ecx*8 + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 00500c43  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00500c45  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00500c46  7cba                   -jl 0x500c02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500c02;
    }
    // 00500c48  d91d84785600           +fstp dword ptr [0x567884]
    app->getMemory<float>(x86::reg32(5666948) /* 0x567884 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500c4e  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500c50  d91d80785600           +fstp dword ptr [0x567880]
    app->getMemory<float>(x86::reg32(5666944) /* 0x567880 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500c56  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00500c58  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00500c5a  e950ffffff             -jmp 0x500baf
    goto L_0x00500baf;
L_0x00500c5f:
    // 00500c5f  8b1580785600           -mov edx, dword ptr [0x567880]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666944) /* 0x567880 */);
    // 00500c65  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00500c68  8b1584785600           -mov edx, dword ptr [0x567884]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666948) /* 0x567884 */);
    // 00500c6e  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00500c71  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00500c74  61                     -popal 
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
    // 00500c75  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500c76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_500c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500c83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500c84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00500c85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00500c86  fe05f79aa000           -inc byte ptr [0xa09af7]
    (app->getMemory<x86::reg8>(x86::reg32(10525431) /* 0xa09af7 */))++;
    // 00500c8c  ff05fc9aa000           -inc dword ptr [0xa09afc]
    (app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */))++;
    // 00500c92  e8e518feff             -call 0x4e257c
    cpu.esp -= 4;
    sub_4e257c(app, cpu);
    if (cpu.terminate) return;
    // 00500c97  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00500c99  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00500c9b:
    // 00500c9b  0fbe05f99aa000         -movsx eax, byte ptr [0xa09af9]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(10525433) /* 0xa09af9 */)));
    // 00500ca2  39c3                   +cmp ebx, eax
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
    // 00500ca4  0f8ce9000000           -jl 0x500d93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500d93;
    }
    // 00500caa  bb3c9ba000             -mov ebx, 0xa09b3c
    cpu.ebx = 10525500 /*0xa09b3c*/;
    // 00500caf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00500cb1:
    // 00500cb1  8a530c                 -mov dl, byte ptr [ebx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00500cb4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00500cb6  80fa01                 +cmp dl, 1
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
    // 00500cb9  0f85ba000000           -jne 0x500d79
    if (!cpu.flags.zf)
    {
        goto L_0x00500d79;
    }
    // 00500cbf  833b00                 +cmp dword ptr [ebx], 0
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
    // 00500cc2  0f8cb1000000           -jl 0x500d79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500d79;
    }
    // 00500cc8  837b5c00               +cmp dword ptr [ebx + 0x5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500ccc  7427                   -je 0x500cf5
    if (cpu.flags.zf)
    {
        goto L_0x00500cf5;
    }
    // 00500cce  8a733f                 -mov dh, byte ptr [ebx + 0x3f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(63) /* 0x3f */);
    // 00500cd1  00d6                   -add dh, dl
    (cpu.dh) += x86::reg8(x86::sreg8(cpu.dl));
    // 00500cd3  8a633d                 -mov ah, byte ptr [ebx + 0x3d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(61) /* 0x3d */);
    // 00500cd6  88733f                 -mov byte ptr [ebx + 0x3f], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(63) /* 0x3f */) = cpu.dh;
    // 00500cd9  38e6                   +cmp dh, ah
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00500cdb  7204                   -jb 0x500ce1
    if (cpu.flags.cf)
    {
        goto L_0x00500ce1;
    }
    // 00500cdd  c6433f00               -mov byte ptr [ebx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
L_0x00500ce1:
    // 00500ce1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500ce3  e8c81f0000             -call 0x502cb0
    cpu.esp -= 4;
    sub_502cb0(app, cpu);
    if (cpu.terminate) return;
    // 00500ce8  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00500ceb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500ced  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00500cf0  e83b200000             -call 0x502d30
    cpu.esp -= 4;
    sub_502d30(app, cpu);
    if (cpu.terminate) return;
L_0x00500cf5:
    // 00500cf5  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00500cf8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00500cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00500cfc  7418                   -je 0x500d16
    if (cpu.flags.zf)
    {
        goto L_0x00500d16;
    }
    // 00500cfe  8a513e                 -mov dl, byte ptr [ecx + 0x3e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00500d01  fec2                   -inc dl
    (cpu.dl)++;
    // 00500d03  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
    // 00500d06  8a713c                 -mov dh, byte ptr [ecx + 0x3c]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 00500d09  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00500d0e  38f2                   +cmp dl, dh
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
    // 00500d10  7204                   -jb 0x500d16
    if (cpu.flags.cf)
    {
        goto L_0x00500d16;
    }
    // 00500d12  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
L_0x00500d16:
    // 00500d16  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00500d19  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500d1b  742f                   -je 0x500d4c
    if (cpu.flags.zf)
    {
        goto L_0x00500d4c;
    }
    // 00500d1d  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00500d20  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00500d25  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00500d27  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00500d2a  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00500d2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00500d2f  0f8c6f000000           -jl 0x500da4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500da4;
    }
    // 00500d35  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00500d38  39d5                   +cmp ebp, edx
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
    // 00500d3a  7c0a                   -jl 0x500d46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500d46;
    }
    // 00500d3c  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00500d43  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00500d46:
    // 00500d46  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00500d4a  7c26                   -jl 0x500d72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500d72;
    }
L_0x00500d4c:
    // 00500d4c  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00500d4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500d51  7408                   -je 0x500d5b
    if (cpu.flags.zf)
    {
        goto L_0x00500d5b;
    }
    // 00500d53  015128                 -add dword ptr [ecx + 0x28], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00500d56  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00500d5b:
    // 00500d5b  83792c00               +cmp dword ptr [ecx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500d5f  0f8587000000           -jne 0x500dec
    if (!cpu.flags.zf)
    {
        goto L_0x00500dec;
    }
    // 00500d65  8a4135                 -mov al, byte ptr [ecx + 0x35]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 00500d68  fec0                   -inc al
    (cpu.al)++;
    // 00500d6a  884135                 -mov byte ptr [ecx + 0x35], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = cpu.al;
    // 00500d6d  3a4134                 +cmp al, byte ptr [ecx + 0x34]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00500d70  7c47                   -jl 0x500db9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500db9;
    }
L_0x00500d72:
    // 00500d72  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00500d74  e8f788feff             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
L_0x00500d79:
    // 00500d79  46                     -inc esi
    (cpu.esi)++;
    // 00500d7a  83c360                 -add ebx, 0x60
    (cpu.ebx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00500d7d  83fe10                 +cmp esi, 0x10
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
    // 00500d80  0f8c2bffffff           -jl 0x500cb1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500cb1;
    }
    // 00500d86  fe0df79aa000           -dec byte ptr [0xa09af7]
    (app->getMemory<x86::reg8>(x86::reg32(10525431) /* 0xa09af7 */))--;
    // 00500d8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500d92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500d93:
    // 00500d93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500d95  ff900c9ba000           -call dword ptr [eax + 0xa09b0c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525452) /* 0xa09b0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500d9b  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00500d9e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00500d9f  e9f7feffff             -jmp 0x500c9b
    goto L_0x00500c9b;
L_0x00500da4:
    // 00500da4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00500da6  8b691c                 -mov ebp, dword ptr [ecx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00500da9  39e8                   +cmp eax, ebp
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
    // 00500dab  7f99                   -jg 0x500d46
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00500d46;
    }
    // 00500dad  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00500db4  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00500db7  eb8d                   -jmp 0x500d46
    goto L_0x00500d46;
L_0x00500db9:
    // 00500db9  8b4132                 -mov eax, dword ptr [ecx + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(50) /* 0x32 */);
    // 00500dbc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00500dbf  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00500dc6  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00500dc9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00500dcb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00500dcd  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00500dd0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500dd2  7c41                   -jl 0x500e15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500e15;
    }
L_0x00500dd4:
    // 00500dd4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00500dd7  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00500dda  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00500ddd  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00500ddf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00500de1  8b692c                 -mov ebp, dword ptr [ecx + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00500de4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00500de7  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00500de9  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00500dec:
    // 00500dec  ff492c                 -dec dword ptr [ecx + 0x2c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */))--;
    // 00500def  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00500df1  7486                   -je 0x500d79
    if (cpu.flags.zf)
    {
        goto L_0x00500d79;
    }
    // 00500df3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500df5  e8a6060000             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 00500dfa  833900                 +cmp dword ptr [ecx], 0
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
    // 00500dfd  0f8c76ffffff           -jl 0x500d79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00500d79;
    }
    // 00500e03  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00500e06  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00500e08  c1fa18                 +sar edx, 0x18
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
    // 00500e0b  e830070000             -call 0x501540
    cpu.esp -= 4;
    sub_501540(app, cpu);
    if (cpu.terminate) return;
    // 00500e10  e964ffffff             -jmp 0x500d79
    goto L_0x00500d79;
L_0x00500e15:
    // 00500e15  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 00500e1c  ebb6                   -jmp 0x500dd4
    goto L_0x00500dd4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_500e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500e20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500e21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500e22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500e23  e84882ffff             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 00500e28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00500e2a  7439                   -je 0x500e65
    if (cpu.flags.zf)
    {
        goto L_0x00500e65;
    }
    // 00500e2c  803df79aa00000         +cmp byte ptr [0xa09af7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525431) /* 0xa09af7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00500e33  7530                   -jne 0x500e65
    if (!cpu.flags.zf)
    {
        goto L_0x00500e65;
    }
    // 00500e35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500e36  ba14e35400             -mov edx, 0x54e314
    cpu.edx = 5563156 /*0x54e314*/;
    // 00500e3b  b924e35400             -mov ecx, 0x54e324
    cpu.ecx = 5563172 /*0x54e324*/;
    // 00500e40  bb14010000             -mov ebx, 0x114
    cpu.ebx = 276 /*0x114*/;
    // 00500e45  6834e35400             -push 0x54e334
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563188 /*0x54e334*/;
    cpu.esp -= 4;
    // 00500e4a  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00500e50  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00500e56  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00500e5c  e8af01f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500e61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00500e64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00500e65:
    // 00500e65  8b35049ba000           -mov esi, dword ptr [0xa09b04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 00500e6b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500e6c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500e72  fe05f89aa000           -inc byte ptr [0xa09af8]
    (app->getMemory<x86::reg8>(x86::reg32(10525432) /* 0xa09af8 */))++;
    // 00500e78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500e79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500e7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500e7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_500e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500e7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500e7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500e7e  fe0df89aa000           -dec byte ptr [0xa09af8]
    (app->getMemory<x86::reg8>(x86::reg32(10525432) /* 0xa09af8 */))--;
    // 00500e84  8b15049ba000           -mov edx, dword ptr [0xa09b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 00500e8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500e8b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500e91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500e92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500e93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_500e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500e94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500e95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500e97  803df99aa00006         +cmp byte ptr [0xa09af9], 6
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525433) /* 0xa09af9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00500e9e  7d17                   -jge 0x500eb7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00500eb7;
    }
L_0x00500ea0:
    // 00500ea0  a1f69aa000             -mov eax, dword ptr [0xa09af6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525430) /* 0xa09af6 */);
    // 00500ea5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00500ea8  8914850c9ba000         -mov dword ptr [eax*4 + 0xa09b0c], edx
    app->getMemory<x86::reg32>(x86::reg32(10525452) /* 0xa09b0c */ + cpu.eax * 4) = cpu.edx;
    // 00500eaf  fe05f99aa000           -inc byte ptr [0xa09af9]
    (app->getMemory<x86::reg8>(x86::reg32(10525433) /* 0xa09af9 */))++;
    // 00500eb5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500eb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500eb7:
    // 00500eb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00500eb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500eb9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500eba  b914e35400             -mov ecx, 0x54e314
    cpu.ecx = 5563156 /*0x54e314*/;
    // 00500ebf  bb8ce35400             -mov ebx, 0x54e38c
    cpu.ebx = 5563276 /*0x54e38c*/;
    // 00500ec4  be49010000             -mov esi, 0x149
    cpu.esi = 329 /*0x149*/;
    // 00500ec9  68a8e35400             -push 0x54e3a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563304 /*0x54e3a8*/;
    cpu.esp -= 4;
    // 00500ece  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00500ed4  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00500eda  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00500ee0  e82b01f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500ee5  83c404                 +add esp, 4
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
    // 00500ee8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500ee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500eea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500eeb  ebb3                   -jmp 0x500ea0
    goto L_0x00500ea0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_500ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00500ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500ef3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00500ef5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00500ef7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00500ef9:
    // 00500ef9  8b0df69aa000           -mov ecx, dword ptr [0xa09af6]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10525430) /* 0xa09af6 */);
    // 00500eff  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00500f02  39c8                   +cmp eax, ecx
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
    // 00500f04  7d3a                   -jge 0x500f40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00500f40;
    }
    // 00500f06  3b9a0c9ba000           +cmp ebx, dword ptr [edx + 0xa09b0c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10525452) /* 0xa09b0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00500f0c  752c                   -jne 0x500f3a
    if (!cpu.flags.zf)
    {
        goto L_0x00500f3a;
    }
    // 00500f0e  fe0df99aa000           -dec byte ptr [0xa09af9]
    (app->getMemory<x86::reg8>(x86::reg32(10525433) /* 0xa09af9 */))--;
    // 00500f14  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
L_0x00500f1b:
    // 00500f1b  8b0df69aa000           -mov ecx, dword ptr [0xa09af6]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10525430) /* 0xa09af6 */);
    // 00500f21  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00500f24  39c8                   +cmp eax, ecx
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
    // 00500f26  7d46                   -jge 0x500f6e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00500f6e;
    }
    // 00500f28  83c204                 +add edx, 4
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
    // 00500f2b  8b8a0c9ba000           -mov ecx, dword ptr [edx + 0xa09b0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10525452) /* 0xa09b0c */);
    // 00500f31  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00500f32  898a089ba000           -mov dword ptr [edx + 0xa09b08], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10525448) /* 0xa09b08 */) = cpu.ecx;
    // 00500f38  ebe1                   -jmp 0x500f1b
    goto L_0x00500f1b;
L_0x00500f3a:
    // 00500f3a  83c204                 +add edx, 4
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
    // 00500f3d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00500f3e  ebb9                   -jmp 0x500ef9
    goto L_0x00500ef9;
L_0x00500f40:
    // 00500f40  ba14e35400             -mov edx, 0x54e314
    cpu.edx = 5563156 /*0x54e314*/;
    // 00500f45  b9d8e35400             -mov ecx, 0x54e3d8
    cpu.ecx = 5563352 /*0x54e3d8*/;
    // 00500f4a  bb65010000             -mov ebx, 0x165
    cpu.ebx = 357 /*0x165*/;
    // 00500f4f  68f4e35400             -push 0x54e3f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563380 /*0x54e3f4*/;
    cpu.esp -= 4;
    // 00500f54  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00500f5a  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00500f60  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00500f66  e8a500f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00500f6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00500f6e:
    // 00500f6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500f70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_500f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500f80  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500f82  7504                   -jne 0x500f88
    if (!cpu.flags.zf)
    {
        goto L_0x00500f88;
    }
    // 00500f84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00500f86:
    // 00500f86  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00500f87  90                     -nop 
    ;
L_0x00500f88:
    // 00500f88  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500f8a  74fa                   -je 0x500f86
    if (cpu.flags.zf)
    {
        goto L_0x00500f86;
    }
    // 00500f8c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500f8d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500f8f  e834190000             -call 0x5028c8
    cpu.esp -= 4;
    sub_5028c8(app, cpu);
    if (cpu.terminate) return;
    // 00500f94  83fa7b                 +cmp edx, 0x7b
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
    // 00500f97  7507                   -jne 0x500fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00500fa0;
    }
    // 00500f99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00500f9e  eb45                   -jmp 0x500fe5
    goto L_0x00500fe5;
L_0x00500fa0:
    // 00500fa0  81face000000           +cmp edx, 0xce
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
    // 00500fa6  7511                   -jne 0x500fb9
    if (!cpu.flags.zf)
    {
        goto L_0x00500fb9;
    }
    // 00500fa8  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00500fad  e8ce180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fb2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500fb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500fb9:
    // 00500fb9  81fab7000000           +cmp edx, 0xb7
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
    // 00500fbf  7511                   -jne 0x500fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00500fd2;
    }
    // 00500fc1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00500fc6  e8b5180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fcb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500fd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500fd2:
    // 00500fd2  83fa13                 +cmp edx, 0x13
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
    // 00500fd5  7605                   -jbe 0x500fdc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00500fdc;
    }
    // 00500fd7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00500fdc:
    // 00500fdc  8b8285785600           -mov eax, dword ptr [edx + 0x567885]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5666949) /* 0x567885 */);
    // 00500fe2  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00500fe5:
    // 00500fe5  e896180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500ff0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_500f8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00500f8c;
    // 00500f80  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500f82  7504                   -jne 0x500f88
    if (!cpu.flags.zf)
    {
        goto L_0x00500f88;
    }
    // 00500f84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00500f86:
    // 00500f86  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00500f87  90                     -nop 
    ;
L_0x00500f88:
    // 00500f88  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00500f8a  74fa                   -je 0x500f86
    if (cpu.flags.zf)
    {
        goto L_0x00500f86;
    }
L_entry_0x00500f8c:
    // 00500f8c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500f8d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00500f8f  e834190000             -call 0x5028c8
    cpu.esp -= 4;
    sub_5028c8(app, cpu);
    if (cpu.terminate) return;
    // 00500f94  83fa7b                 +cmp edx, 0x7b
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
    // 00500f97  7507                   -jne 0x500fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00500fa0;
    }
    // 00500f99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00500f9e  eb45                   -jmp 0x500fe5
    goto L_0x00500fe5;
L_0x00500fa0:
    // 00500fa0  81face000000           +cmp edx, 0xce
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
    // 00500fa6  7511                   -jne 0x500fb9
    if (!cpu.flags.zf)
    {
        goto L_0x00500fb9;
    }
    // 00500fa8  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00500fad  e8ce180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fb2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500fb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500fb9:
    // 00500fb9  81fab7000000           +cmp edx, 0xb7
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
    // 00500fbf  7511                   -jne 0x500fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00500fd2;
    }
    // 00500fc1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00500fc6  e8b5180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fcb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500fd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00500fd2:
    // 00500fd2  83fa13                 +cmp edx, 0x13
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
    // 00500fd5  7605                   -jbe 0x500fdc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00500fdc;
    }
    // 00500fd7  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00500fdc:
    // 00500fdc  8b8285785600           -mov eax, dword ptr [edx + 0x567885]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5666949) /* 0x567885 */);
    // 00500fe2  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00500fe5:
    // 00500fe5  e896180000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00500fea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00500fef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00500ff0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_500ff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00500ff4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00500ff5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00500ff6  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00500ffd  e88affffff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 00501002  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501003  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501004  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_501010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501011  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501012  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00501014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501016  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0050101b  e810e9fdff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00501020  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501022  7409                   -je 0x50102d
    if (cpu.flags.zf)
    {
        goto L_0x0050102d;
    }
    // 00501024  833d6443560000         +cmp dword ptr [0x564364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050102b  7505                   -jne 0x501032
    if (!cpu.flags.zf)
    {
        goto L_0x00501032;
    }
L_0x0050102d:
    // 0050102d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050102f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501030  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501031  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501032:
    // 00501032  e83980ffff             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 00501037  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501039  74f2                   -je 0x50102d
    if (cpu.flags.zf)
    {
        goto L_0x0050102d;
    }
    // 0050103b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050103c  682ce45400             -push 0x54e42c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563436 /*0x54e42c*/;
    cpu.esp -= 4;
    // 00501041  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00501043  e8c8ffefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501048  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050104b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050104d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050104e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050104f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_501050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501051  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501052  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501053  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 00501059  8b842414040000         -mov eax, dword ptr [esp + 0x414]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 00501060  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501062  7415                   -je 0x501079
    if (cpu.flags.zf)
    {
        goto L_0x00501079;
    }
    // 00501064  8b942418040000         -mov edx, dword ptr [esp + 0x418]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0050106b  3b10                   +cmp edx, dword ptr [eax]
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
    // 0050106d  7e0a                   -jle 0x501079
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501079;
    }
L_0x0050106f:
    // 0050106f  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 00501075  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501076  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501077  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501078  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501079:
    // 00501079  8d842420040000         -lea eax, [esp + 0x420]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1056) /* 0x420 */);
    // 00501080  8d9c2400040000         -lea ebx, [esp + 0x400]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00501087  8b94241c040000         -mov edx, dword ptr [esp + 0x41c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0050108e  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 00501095  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00501097  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00501099  e8d6e5fdff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0050109e  a19c785600             -mov eax, dword ptr [0x56789c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666972) /* 0x56789c */);
    // 005010a3  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 005010aa  83f802                 +cmp eax, 2
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
    // 005010ad  7319                   -jae 0x5010c8
    if (!cpu.flags.cf)
    {
        goto L_0x005010c8;
    }
    // 005010af  83f801                 +cmp eax, 1
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
    // 005010b2  75bb                   -jne 0x50106f
    if (!cpu.flags.zf)
    {
        goto L_0x0050106f;
    }
    // 005010b4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005010b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005010b7  2eff159c455300         -call dword ptr cs:[0x53459c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457308) /* 0x53459c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005010be  81c404040000           +add esp, 0x404
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1028 /*0x404*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005010c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005010c8:
    // 005010c8  761a                   -jbe 0x5010e4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005010e4;
    }
    // 005010ca  83f803                 +cmp eax, 3
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
    // 005010cd  75a0                   -jne 0x50106f
    if (!cpu.flags.zf)
    {
        goto L_0x0050106f;
    }
    // 005010cf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005010d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005010d2  e819f8fdff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005010d7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005010da  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 005010e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005010e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005010e4:
    // 005010e4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005010e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005010e7  e8d4e5fdff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 005010ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005010ef  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 005010f4  e8776cffff             -call 0x4f7d70
    cpu.esp -= 4;
    sub_4f7d70(app, cpu);
    if (cpu.terminate) return;
    // 005010f9  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 005010ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501100  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501101  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501102  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_501110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501114  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501115  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00501118  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050111a  8b15a0785600           -mov edx, dword ptr [0x5678a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */);
    // 00501120  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00501122  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00501124  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00501126  7435                   -je 0x50115d
    if (cpu.flags.zf)
    {
        goto L_0x0050115d;
    }
L_0x00501128:
    // 00501128  8b0da0785600           -mov ecx, dword ptr [0x5678a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */);
    // 0050112e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00501130  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00501132  4a                     -dec edx
    (cpu.edx)--;
    // 00501133  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501135  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00501138  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050113a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050113d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0050113f  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 00501144  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00501146  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00501148  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501149  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050114b  2eff1524465300         -call dword ptr cs:[0x534624]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457444) /* 0x534624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00501152  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00501154  83c424                 +add esp, 0x24
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00501157  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501158  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501159  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050115a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050115b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050115c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050115d:
    // 0050115d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050115f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501160  2eff1560455300         -call dword ptr cs:[0x534560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457248) /* 0x534560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00501167  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050116b  a3a0785600             -mov dword ptr [0x5678a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */) = cpu.eax;
    // 00501170  ebb6                   -jmp 0x501128
    goto L_0x00501128;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_501180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501180  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501181  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501182  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00501187  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00501189  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050118a  2eff1528465300         -call dword ptr cs:[0x534628]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457448) /* 0x534628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00501191  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501192  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501193  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5011a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005011a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005011a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005011a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005011a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005011a4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005011a7  8b35a0785600           -mov esi, dword ptr [0x5678a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */);
    // 005011ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005011af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005011b1  0f847a000000           -je 0x501231
    if (cpu.flags.zf)
    {
        goto L_0x00501231;
    }
L_0x005011b7:
    // 005011b7  833da478560000         +cmp dword ptr [0x5678a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666980) /* 0x5678a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005011be  750a                   -jne 0x5011ca
    if (!cpu.flags.zf)
    {
        goto L_0x005011ca;
    }
    // 005011c0  e82b100200             -call 0x5221f0
    cpu.esp -= 4;
    sub_5221f0(app, cpu);
    if (cpu.terminate) return;
    // 005011c5  a3a4785600             -mov dword ptr [0x5678a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5666980) /* 0x5678a4 */) = cpu.eax;
L_0x005011ca:
    // 005011ca  8b1da4785600           -mov ebx, dword ptr [0x5678a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5666980) /* 0x5678a4 */);
    // 005011d0  8b35a0785600           -mov esi, dword ptr [0x5678a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */);
    // 005011d6  39da                   +cmp edx, ebx
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
    // 005011d8  7e02                   -jle 0x5011dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005011dc;
    }
    // 005011da  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x005011dc:
    // 005011dc  39f2                   +cmp edx, esi
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
    // 005011de  7c43                   -jl 0x501223
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501223;
    }
    // 005011e0  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 005011e3  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 005011e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005011e8  4b                     -dec ebx
    (cpu.ebx)--;
    // 005011e9  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 005011eb  21fb                   -and ebx, edi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.edi));
    // 005011ed  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005011ef  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005011f1  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005011f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005011f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005011f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005011fa  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005011fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005011fe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00501201  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501203  7e1e                   -jle 0x501223
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501223;
    }
L_0x00501205:
    // 00501205  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00501207  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501209  39cb                   +cmp ebx, ecx
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
    // 0050120b  720c                   -jb 0x501219
    if (cpu.flags.cf)
    {
        goto L_0x00501219;
    }
L_0x0050120d:
    // 0050120d  40                     -inc eax
    (cpu.eax)++;
    // 0050120e  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00501210  83f820                 +cmp eax, 0x20
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
    // 00501213  7d04                   -jge 0x501219
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00501219;
    }
    // 00501215  39ca                   +cmp edx, ecx
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
    // 00501217  73f4                   -jae 0x50120d
    if (!cpu.flags.cf)
    {
        goto L_0x0050120d;
    }
L_0x00501219:
    // 00501219  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050121c  47                     -inc edi
    (cpu.edi)++;
    // 0050121d  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050121f  39c7                   +cmp edi, eax
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
    // 00501221  7ce2                   -jl 0x501205
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501205;
    }
L_0x00501223:
    // 00501223  8935a0785600           -mov dword ptr [0x5678a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5666976) /* 0x5678a0 */) = cpu.esi;
    // 00501229  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050122c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050122d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050122e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050122f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501230  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501231:
    // 00501231  bb54e45400             -mov ebx, 0x54e454
    cpu.ebx = 5563476 /*0x54e454*/;
    // 00501236  bf64e45400             -mov edi, 0x54e464
    cpu.edi = 5563492 /*0x54e464*/;
    // 0050123b  bd32000000             -mov ebp, 0x32
    cpu.ebp = 50 /*0x32*/;
    // 00501240  6874e45400             -push 0x54e474
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563508 /*0x54e474*/;
    cpu.esp -= 4;
    // 00501245  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050124b  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00501251  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00501257  e8b4fdefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050125c  83c404                 +add esp, 4
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
    // 0050125f  e953ffffff             -jmp 0x5011b7
    goto L_0x005011b7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_501270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501270  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501271  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501272  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00501273  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00501276  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00501278  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050127a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050127d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0050127f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00501281  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00501283  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 00501288  e89323feff             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 0050128d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050128f  754b                   -jne 0x5012dc
    if (!cpu.flags.zf)
    {
        goto L_0x005012dc;
    }
    // 00501291  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 00501298  7511                   -jne 0x5012ab
    if (!cpu.flags.zf)
    {
        goto L_0x005012ab;
    }
L_0x0050129a:
    // 0050129a  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005012a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005012a2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005012a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005012a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005012a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005012a8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005012ab:
    // 005012ab  ba9ce45400             -mov edx, 0x54e49c
    cpu.edx = 5563548 /*0x54e49c*/;
    // 005012b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005012b1  b9ace45400             -mov ecx, 0x54e4ac
    cpu.ecx = 5563564 /*0x54e4ac*/;
    // 005012b6  bb52000000             -mov ebx, 0x52
    cpu.ebx = 82 /*0x52*/;
    // 005012bb  68bce45400             -push 0x54e4bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563580 /*0x54e4bc*/;
    cpu.esp -= 4;
    // 005012c0  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005012c6  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 005012cc  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005012d2  e839fdefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005012d7  83c408                 +add esp, 8
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
    // 005012da  ebbe                   -jmp 0x50129a
    goto L_0x0050129a;
L_0x005012dc:
    // 005012dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005012de  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005012e2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005012e4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 005012e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005012e8  e89326feff             -call 0x4e3980
    cpu.esp -= 4;
    sub_4e3980(app, cpu);
    if (cpu.terminate) return;
    // 005012ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005012ef  7550                   -jne 0x501341
    if (!cpu.flags.zf)
    {
        goto L_0x00501341;
    }
    // 005012f1  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 005012f8  742f                   -je 0x501329
    if (cpu.flags.zf)
    {
        goto L_0x00501329;
    }
    // 005012fa  b99ce45400             -mov ecx, 0x54e49c
    cpu.ecx = 5563548 /*0x54e49c*/;
    // 005012ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501300  bbace45400             -mov ebx, 0x54e4ac
    cpu.ebx = 5563564 /*0x54e4ac*/;
    // 00501305  bd58000000             -mov ebp, 0x58
    cpu.ebp = 88 /*0x58*/;
    // 0050130a  68e4e45400             -push 0x54e4e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563620 /*0x54e4e4*/;
    cpu.esp -= 4;
    // 0050130f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00501315  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050131b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00501321  e8eafcefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501326  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501329:
    // 00501329  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0050132b  e8b02cfeff             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 00501330  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00501336  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501338  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050133b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050133c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050133d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050133e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00501341:
    // 00501341  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00501344  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0050134a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050134f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00501352  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501353  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501354  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501355  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_501360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501363  ba9ce45400             -mov edx, 0x54e49c
    cpu.edx = 5563548 /*0x54e49c*/;
    // 00501368  b90ce55400             -mov ecx, 0x54e50c
    cpu.ecx = 5563660 /*0x54e50c*/;
    // 0050136d  bb66000000             -mov ebx, 0x66
    cpu.ebx = 102 /*0x66*/;
    // 00501372  681ce55400             -push 0x54e51c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563676 /*0x54e51c*/;
    cpu.esp -= 4;
    // 00501377  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050137d  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00501383  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00501389  e882fcefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050138e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00501391  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501393  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501394  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501395  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501396  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_5013a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005013a0  e93b2cfeff             -jmp 0x4e3fe0
    return sub_4e3fe0(app, cpu);
}

}
