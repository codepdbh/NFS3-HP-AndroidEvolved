#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

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

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5127d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005127d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005127d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005127d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005127d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005127d4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005127d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005127d9  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 005127de  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 005127e3  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 005127e8  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 005127ed  e858160200             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 005127f2  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 005127f7  668944240c             -mov word ptr [esp + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 005127fc  8d442402               -lea eax, [esp + 2]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00512800  e811dffcff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 00512805  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0051280a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0051280f  8d442406               -lea eax, [esp + 6]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00512813  e8fedefcff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 00512818  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051281d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051281f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00512822  6689442410             -mov word ptr [esp + 0x10], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00512827  b8be080000             -mov eax, 0x8be
    cpu.eax = 2238 /*0x8be*/;
    // 0051282c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051282e  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00512834  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00512837  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512838  6689442416             -mov word ptr [esp + 0x16], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(22) /* 0x16 */) = cpu.ax;
    // 0051283d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512843  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00512845  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512849  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051284a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051284c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0051284e  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00512852  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512854  e8d9150200             -call 0x533e32
    cpu.esp -= 4;
    sub_533e32(app, cpu);
    if (cpu.terminate) return;
    // 00512859  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 0051285f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512860  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00512862  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512868  83feff                 +cmp esi, -1
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
    // 0051286b  740d                   -je 0x51287a
    if (cpu.flags.zf)
    {
        goto L_0x0051287a;
    }
    // 0051286d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512872  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00512875  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512876  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512877  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512878  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512879  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051287a:
    // 0051287a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051287c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051287f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_512890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512890  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512891  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512892  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512893  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00512896  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00512899  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051289b  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0051289d  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 005128a2  e8a3150200             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 005128a7  663b460c               +cmp ax, word ptr [esi + 0xc]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005128ab  7409                   -je 0x5128b6
    if (cpu.flags.zf)
    {
        goto L_0x005128b6;
    }
L_0x005128ad:
    // 005128ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005128af  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005128b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005128b6:
    // 005128b6  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 005128bb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005128bd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005128bf  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005128c1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005128c3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005128ca  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005128cc  83f802                 +cmp eax, 2
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
    // 005128cf  75dc                   -jne 0x5128ad
    if (!cpu.flags.zf)
    {
        goto L_0x005128ad;
    }
    // 005128d1  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005128d3  c1ef06                 -shr edi, 6
    cpu.edi >>= 6 /*0x6*/ % 32;
    // 005128d6  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 005128d9  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 005128dd  8d7e32                 -lea edi, [esi + 0x32]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 005128e0  8d2c06                 -lea ebp, [esi + eax]
    cpu.ebp = x86::reg32(cpu.esi + cpu.eax * 1);
L_0x005128e3:
    // 005128e3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005128e7  4a                     -dec edx
    (cpu.edx)--;
    // 005128e8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005128ec  83faff                 +cmp edx, -1
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
    // 005128ef  750c                   -jne 0x5128fd
    if (!cpu.flags.zf)
    {
        goto L_0x005128fd;
    }
    // 005128f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005128f6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005128f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005128fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005128fd:
    // 005128fd  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00512902  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00512904  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00512906  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00512908  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051290a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00512911  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00512913  3dbe080000             +cmp eax, 0x8be
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2238 /*0x8be*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512918  740b                   -je 0x512925
    if (cpu.flags.zf)
    {
        goto L_0x00512925;
    }
    // 0051291a  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051291d  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00512920  83c740                 +add edi, 0x40
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00512923  ebbe                   -jmp 0x5128e3
    goto L_0x005128e3;
L_0x00512925:
    // 00512925  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00512928  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0051292a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051292c  e8ff30feff             -call 0x4f5a30
    cpu.esp -= 4;
    sub_4f5a30(app, cpu);
    if (cpu.terminate) return;
    // 00512931  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00512934  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00512937  83c740                 +add edi, 0x40
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051293a  eba7                   -jmp 0x5128e3
    goto L_0x005128e3;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_512940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512943  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00512945  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 0051294b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051294c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512952  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00512954  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512955  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00512957  6a42                   -push 0x42
    app->getMemory<x86::reg32>(cpu.esp-4) = 66 /*0x42*/;
    cpu.esp -= 4;
    // 00512959  68d2b0a000             -push 0xa0b0d2
    app->getMemory<x86::reg32>(cpu.esp-4) = 10531026 /*0xa0b0d2*/;
    cpu.esp -= 4;
    // 0051295e  8b0dbcb0a000           -mov ecx, dword ptr [0xa0b0bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */);
    // 00512964  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512965  e8c8140200             -call 0x533e32
    cpu.esp -= 4;
    sub_533e32(app, cpu);
    if (cpu.terminate) return;
    // 0051296a  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00512970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512971  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512977  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512978  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512979  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051297a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_512980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512982  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00512984  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00512989  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051298b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051298d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051298f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00512996  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00512998  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0051299d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051299f  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005129a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005129a4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005129a6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005129a8  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005129af  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005129b1  83fa01                 +cmp edx, 1
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
    // 005129b4  7516                   -jne 0x5129cc
    if (!cpu.flags.zf)
    {
        goto L_0x005129cc;
    }
    // 005129b6  3dbe080000             +cmp eax, 0x8be
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2238 /*0x8be*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005129bb  7407                   -je 0x5129c4
    if (cpu.flags.zf)
    {
        goto L_0x005129c4;
    }
    // 005129bd  3dffff0000             +cmp eax, 0xffff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005129c2  7508                   -jne 0x5129cc
    if (!cpu.flags.zf)
    {
        goto L_0x005129cc;
    }
L_0x005129c4:
    // 005129c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005129c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005129ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005129cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005129cc:
    // 005129cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005129ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005129cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005129d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_5129e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005129e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005129e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005129e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005129e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005129e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005129e5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005129e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005129ea  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 005129ef  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 005129f1  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 005129f3  e8b2140200             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 005129f8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005129fa  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005129fc  83f8ff                 +cmp eax, -1
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
    // 005129ff  7510                   -jne 0x512a11
    if (!cpu.flags.zf)
    {
        goto L_0x00512a11;
    }
    // 00512a01  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x00512a06:
    // 00512a06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512a08  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00512a0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512a0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512a0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512a0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512a0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512a10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00512a11:
    // 00512a11  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00512a13  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512a17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512a18  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00512a1a  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 00512a1f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00512a24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512a25  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00512a29  e828140200             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 00512a2e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00512a30  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512a34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512a35  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 00512a3a  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 00512a3f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512a40  e811140200             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 00512a45  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00512a47  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512a4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512a4c  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 00512a51  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 00512a56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512a57  e8fa130200             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 00512a5c  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 00512a61  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00512a63  e8a4dcfcff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 00512a68  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 00512a6d  66c7060600             -mov word ptr [esi], 6
    app->getMemory<x86::reg16>(cpu.esi) = 6 /*0x6*/;
    // 00512a72  e8d3130200             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 00512a77  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00512a79  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512a7a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512a7b  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 00512a7f  e8c0130200             -call 0x533e44
    cpu.esp -= 4;
    sub_533e44(app, cpu);
    if (cpu.terminate) return;
    // 00512a84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512a86  7524                   -jne 0x512aac
    if (!cpu.flags.zf)
    {
        goto L_0x00512aac;
    }
    // 00512a88  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512a8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512a8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512a8e  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00512a93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512a94  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00512a98  e8a1130200             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 00512a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512a9f  750b                   -jne 0x512aac
    if (!cpu.flags.zf)
    {
        goto L_0x00512aac;
    }
    // 00512aa1  837c24040e             +cmp dword ptr [esp + 4], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512aa6  0f845affffff           -je 0x512a06
    if (cpu.flags.zf)
    {
        goto L_0x00512a06;
    }
L_0x00512aac:
    // 00512aac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512aad  e8f2130200             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 00512ab2  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00512ab7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512ab9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00512abc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512abd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512abe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512abf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512ac0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512ac1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_512ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512ad2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512ad3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512ad4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512ad5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512ad6  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 00512adc  e8affcfdff             -call 0x4f2790
    cpu.esp -= 4;
    sub_4f2790(app, cpu);
    if (cpu.terminate) return;
    // 00512ae1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 00512ae6  6852040000             -push 0x452
    app->getMemory<x86::reg32>(cpu.esp-4) = 1106 /*0x452*/;
    cpu.esp -= 4;
    // 00512aeb  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00512aee  6689942418030000       -mov word ptr [esp + 0x318], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.dx;
    // 00512af6  e84f130200             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 00512afb  8d942414030000         -lea edx, [esp + 0x314]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00512b02  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00512b03  e8f82dfeff             -call 0x4f5900
    cpu.esp -= 4;
    sub_4f5900(app, cpu);
    if (cpu.terminate) return;
    // 00512b08  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00512b0d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00512b0f  8915b8b0a000           -mov dword ptr [0xa0b0b8], edx
    app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */) = cpu.edx;
    // 00512b15  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00512b17:
    // 00512b17  bee8030000             -mov esi, 0x3e8
    cpu.esi = 1000 /*0x3e8*/;
    // 00512b1c  a1bcb0a000             -mov eax, dword ptr [0xa0b0bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */);
    // 00512b21  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00512b23  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 00512b2a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00512b2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512b2f  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00512b31  89842424030000         -mov dword ptr [esp + 0x324], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.eax;
    // 00512b38  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00512b3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512b3c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00512b3f  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00512b41  69c2e8030000           -imul eax, edx, 0x3e8
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1000 /*0x3e8*/)));
    // 00512b47  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 00512b4e  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 00512b55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512b56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512b57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512b58  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00512b5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512b60  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00512b65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512b66  898c2414020000         -mov dword ptr [esp + 0x214], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.ecx;
    // 00512b6d  e8ae120200             -call 0x533e20
    cpu.esp -= 4;
    sub_533e20(app, cpu);
    if (cpu.terminate) return;
    // 00512b72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00512b74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512b76  0f84c9000000           -je 0x512c45
    if (cpu.flags.zf)
    {
        goto L_0x00512c45;
    }
    // 00512b7c  83f8ff                 +cmp eax, -1
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
    // 00512b7f  0f84c0000000           -je 0x512c45
    if (cpu.flags.zf)
    {
        goto L_0x00512c45;
    }
    // 00512b85  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00512b8a  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00512b8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512b90  89b42430030000         -mov dword ptr [esp + 0x330], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(816) /* 0x330 */) = cpu.esi;
    // 00512b97  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512b9d  8d84242c030000         -lea eax, [esp + 0x32c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(812) /* 0x32c */);
    // 00512ba4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512ba5  8d842408030000         -lea eax, [esp + 0x308]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 00512bac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512bad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512bae  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00512bb3  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00512bb7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512bb8  8b15bcb0a000           -mov edx, dword ptr [0xa0b0bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */);
    // 00512bbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512bbf  e898120200             -call 0x533e5c
    cpu.esp -= 4;
    sub_533e5c(app, cpu);
    if (cpu.terminate) return;
    // 00512bc4  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00512bca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512bcb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00512bcd  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512bd3  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512bd6  7519                   -jne 0x512bf1
    if (!cpu.flags.zf)
    {
        goto L_0x00512bf1;
    }
    // 00512bd8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00512bda  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00512bdc  e89ffdffff             -call 0x512980
    cpu.esp -= 4;
    sub_512980(app, cpu);
    if (cpu.terminate) return;
    // 00512be1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512be3  740c                   -je 0x512bf1
    if (cpu.flags.zf)
    {
        goto L_0x00512bf1;
    }
    // 00512be5  8d842404030000         -lea eax, [esp + 0x304]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00512bec  e84ffdffff             -call 0x512940
    cpu.esp -= 4;
    sub_512940(app, cpu);
    if (cpu.terminate) return;
L_0x00512bf1:
    // 00512bf1  3b2db8b0a000           +cmp ebp, dword ptr [0xa0b0b8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512bf7  7425                   -je 0x512c1e
    if (cpu.flags.zf)
    {
        goto L_0x00512c1e;
    }
    // 00512bf9  e892fbfdff             -call 0x4f2790
    cpu.esp -= 4;
    sub_4f2790(app, cpu);
    if (cpu.terminate) return;
    // 00512bfe  39c3                   +cmp ebx, eax
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
    // 00512c00  731c                   -jae 0x512c1e
    if (!cpu.flags.cf)
    {
        goto L_0x00512c1e;
    }
    // 00512c02  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00512c09  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00512c0e  e82dfdffff             -call 0x512940
    cpu.esp -= 4;
    sub_512940(app, cpu);
    if (cpu.terminate) return;
    // 00512c13  e878fbfdff             -call 0x4f2790
    cpu.esp -= 4;
    sub_4f2790(app, cpu);
    if (cpu.terminate) return;
    // 00512c18  8d9860ea0000           -lea ebx, [eax + 0xea60]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(60000) /* 0xea60 */);
L_0x00512c1e:
    // 00512c1e  3b2db8b0a000           +cmp ebp, dword ptr [0xa0b0b8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512c24  0f85edfeffff           -jne 0x512b17
    if (!cpu.flags.zf)
    {
        goto L_0x00512b17;
    }
L_0x00512c2a:
    // 00512c2a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00512c2c  7526                   -jne 0x512c54
    if (!cpu.flags.zf)
    {
        goto L_0x00512c54;
    }
L_0x00512c2e:
    // 00512c2e  c705b4b0a00001000000   -mov dword ptr [0xa0b0b4], 1
    app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */) = 1 /*0x1*/;
    // 00512c38  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 00512c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00512c45:
    // 00512c45  83faff                 +cmp edx, -1
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
    // 00512c48  75a7                   -jne 0x512bf1
    if (!cpu.flags.zf)
    {
        goto L_0x00512bf1;
    }
    // 00512c4a  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00512c4c  891db8b0a000           -mov dword ptr [0xa0b0b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */) = cpu.ebx;
    // 00512c52  ebd6                   -jmp 0x512c2a
    goto L_0x00512c2a;
L_0x00512c54:
    // 00512c54  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00512c59  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00512c5b  c1e810                 +shr eax, 0x10
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
    // 00512c5e  66a312b1a000           -mov word ptr [0xa0b112], ax
    app->getMemory<x86::reg16>(x86::reg32(10531090) /* 0xa0b112 */) = cpu.ax;
    // 00512c64  8d842414030000         -lea eax, [esp + 0x314]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00512c6b  e8d0fcffff             -call 0x512940
    cpu.esp -= 4;
    sub_512940(app, cpu);
    if (cpu.terminate) return;
    // 00512c70  ebbc                   -jmp 0x512c2e
    goto L_0x00512c2e;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_512c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512c80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512c81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512c82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512c83  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00512c85  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00512c87  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00512c89  833db8b0a00000         +cmp dword ptr [0xa0b0b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512c90  7409                   -je 0x512c9b
    if (cpu.flags.zf)
    {
        goto L_0x00512c9b;
    }
L_0x00512c92:
    // 00512c92  a1b8b0a000             -mov eax, dword ptr [0xa0b0b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */);
    // 00512c97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512c9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00512c9b:
    // 00512c9b  b8c4b0a000             -mov eax, 0xa0b0c4
    cpu.eax = 10531012 /*0xa0b0c4*/;
    // 00512ca0  e83bfdffff             -call 0x5129e0
    cpu.esp -= 4;
    sub_5129e0(app, cpu);
    if (cpu.terminate) return;
    // 00512ca5  a3bcb0a000             -mov dword ptr [0xa0b0bc], eax
    app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */) = cpu.eax;
    // 00512caa  83f8ff                 +cmp eax, -1
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
    // 00512cad  74e3                   -je 0x512c92
    if (cpu.flags.zf)
    {
        goto L_0x00512c92;
    }
    // 00512caf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00512cb4  890dc0b0a000           -mov dword ptr [0xa0b0c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531008) /* 0xa0b0c0 */) = cpu.ecx;
    // 00512cba  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00512cbc  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00512cbf  66a3d2b0a000           -mov word ptr [0xa0b0d2], ax
    app->getMemory<x86::reg16>(x86::reg32(10531026) /* 0xa0b0d2 */) = cpu.ax;
    // 00512cc5  b8be080000             -mov eax, 0x8be
    cpu.eax = 2238 /*0x8be*/;
    // 00512cca  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00512ccc  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00512ccf  66a3d4b0a000           -mov word ptr [0xa0b0d4], ax
    app->getMemory<x86::reg16>(x86::reg32(10531028) /* 0xa0b0d4 */) = cpu.ax;
    // 00512cd5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512cda  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 00512cdf  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00512ce1  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00512ce4  bf06b1a000             -mov edi, 0xa0b106
    cpu.edi = 10531078 /*0xa0b106*/;
    // 00512ce9  66a312b1a000           -mov word ptr [0xa0b112], ax
    app->getMemory<x86::reg16>(x86::reg32(10531090) /* 0xa0b112 */) = cpu.ax;
    // 00512cef  b8d6b0a000             -mov eax, 0xa0b0d6
    cpu.eax = 10531030 /*0xa0b0d6*/;
    // 00512cf4  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00512cf9  e832e1fcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00512cfe  68a0b0a000             -push 0xa0b0a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10530976 /*0xa0b0a0*/;
    cpu.esp -= 4;
    // 00512d03  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00512d08  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00512d09  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00512d0a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00512d0b  b8d02a5100             -mov eax, 0x512ad0
    cpu.eax = 5319376 /*0x512ad0*/;
    // 00512d10  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00512d12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00512d14  8935b4b0a000           -mov dword ptr [0xa0b0b4], esi
    app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */) = cpu.esi;
    // 00512d1a  e881cafcff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 00512d1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512d21  7422                   -je 0x512d45
    if (cpu.flags.zf)
    {
        goto L_0x00512d45;
    }
    // 00512d23  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00512d28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00512d2a:
    // 00512d2a  8b3db8b0a000           -mov edi, dword ptr [0xa0b0b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */);
    // 00512d30  39fa                   +cmp edx, edi
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
    // 00512d32  7511                   -jne 0x512d45
    if (!cpu.flags.zf)
    {
        goto L_0x00512d45;
    }
    // 00512d34  3b3db4b0a000           +cmp edi, dword ptr [0xa0b0b4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512d3a  7509                   -jne 0x512d45
    if (!cpu.flags.zf)
    {
        goto L_0x00512d45;
    }
    // 00512d3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00512d3e  e89dcbfcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 00512d43  ebe5                   -jmp 0x512d2a
    goto L_0x00512d2a;
L_0x00512d45:
    // 00512d45  833db4b0a00000         +cmp dword ptr [0xa0b0b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512d4c  0f8440ffffff           -je 0x512c92
    if (cpu.flags.zf)
    {
        goto L_0x00512c92;
    }
    // 00512d52  8b15bcb0a000           -mov edx, dword ptr [0xa0b0bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */);
    // 00512d58  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512d59  e846110200             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 00512d5e  a1b8b0a000             -mov eax, dword ptr [0xa0b0b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */);
    // 00512d63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_512d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512d70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512d71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512d72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512d73  833db8b0a00000         +cmp dword ptr [0xa0b0b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512d7a  750d                   -jne 0x512d89
    if (!cpu.flags.zf)
    {
        goto L_0x00512d89;
    }
    // 00512d7c  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00512d80:
    // 00512d80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512d85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512d88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00512d89:
    // 00512d89  8b1dbcb0a000           -mov ebx, dword ptr [0xa0b0bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531004) /* 0xa0b0bc */);
    // 00512d8f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512d91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512d92  890db8b0a000           -mov dword ptr [0xa0b0b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531000) /* 0xa0b0b8 */) = cpu.ecx;
    // 00512d98  e807110200             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 00512d9d  833db4b0a00000         +cmp dword ptr [0xa0b0b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512da4  75da                   -jne 0x512d80
    if (!cpu.flags.zf)
    {
        goto L_0x00512d80;
    }
L_0x00512da6:
    // 00512da6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512dab  e830cbfcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 00512db0  833db4b0a00000         +cmp dword ptr [0xa0b0b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10530996) /* 0xa0b0b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512db7  74ed                   -je 0x512da6
    if (cpu.flags.zf)
    {
        goto L_0x00512da6;
    }
    // 00512db9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512dbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512dbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512dc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512dc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_512dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512dd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ebc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ebe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ecc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ece  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512edc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ede  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f61  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f63  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00512f66  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f67  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f69  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00512f6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f6d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f6f  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00512f72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f75  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00512f78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f7b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00512f7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f7f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f81  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00512f84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f85  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f87  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 00512f8a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f8b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f8d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00512f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f91  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f93  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00512f97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f98  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f9a  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00512f9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f9f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00512fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512fa2  682c025500             -push 0x55022c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571116 /*0x55022c*/;
    cpu.esp -= 4;
    // 00512fa7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512fa8  e8e3c6fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00512fad  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00512fb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512fb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_512f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00512f60;
    // 00512dd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512de8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512df8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512dfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512e9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ea8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ebc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ebe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ec8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ecc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ece  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ed8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512edc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ede  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ee8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512eee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512ef8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512efe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00512f5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00512f60:
    // 00512f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f61  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f63  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 00512f66  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f67  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f69  8a480e                 -mov cl, byte ptr [eax + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00512f6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f6d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f6f  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00512f72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f75  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00512f78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f7b  8a480b                 -mov cl, byte ptr [eax + 0xb]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00512f7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f7f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f81  8a480a                 -mov cl, byte ptr [eax + 0xa]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00512f84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f85  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f87  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 00512f8a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f8b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f8d  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00512f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f91  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f93  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00512f97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f98  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512f9a  668b4804               -mov cx, word ptr [eax + 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00512f9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512f9f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00512fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512fa2  682c025500             -push 0x55022c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571116 /*0x55022c*/;
    cpu.esp -= 4;
    // 00512fa7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512fa8  e8e3c6fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00512fad  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00512fb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512fb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_512fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512fc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512fc1  8b15a0c17900           -mov edx, dword ptr [0x79c1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 00512fc7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00512fc9  a3e0895600             -mov dword ptr [0x5689e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5671392) /* 0x5689e0 */) = cpu.eax;
    // 00512fce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_512fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512fd0  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 00512fd5  2b05e0895600           -sub eax, dword ptr [0x5689e0]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5671392) /* 0x5689e0 */)));
    // 00512fdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512fdd  7c11                   -jl 0x512ff0
    if (cpu.flags.sf != cpu.flags.of)
    {
        return sub_512ff0(app, cpu);
    }
    // 00512fdf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512fe4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_512ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512ff0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00512ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_513000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00513000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00513002  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00513004  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00513006  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513008  7416                   -je 0x513020
    if (cpu.flags.zf)
    {
        goto L_0x00513020;
    }
L_0x0051300a:
    // 0051300a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051300c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051300e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00513010  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00513012  42                     -inc edx
    (cpu.edx)++;
    // 00513013  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513015  75f3                   -jne 0x51300a
    if (!cpu.flags.zf)
    {
        goto L_0x0051300a;
    }
    // 00513017  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051301d  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x00513020:
    // 00513020  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00513022  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513024  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_513030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00513030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513031  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00513032  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00513038  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051303a  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 00513041  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00513043  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00513046  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00513048  750a                   -jne 0x513054
    if (!cpu.flags.zf)
    {
        goto L_0x00513054;
    }
    // 0051304a  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 0051304e  0f8528010000           -jne 0x51317c
    if (!cpu.flags.zf)
    {
        goto L_0x0051317c;
    }
L_0x00513054:
    // 00513054  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00513055  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00513056  c78424b4000000636564ea -mov dword ptr [esp + 0xb4], 0xea646563
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = 3932448099 /*0xea646563*/;
    // 00513061  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513063  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00513067  8a4174                 -mov al, byte ptr [ecx + 0x74]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(116) /* 0x74 */);
    // 0051306a  88442450               -mov byte ptr [esp + 0x50], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.al;
    // 0051306e  8a4175                 -mov al, byte ptr [ecx + 0x75]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(117) /* 0x75 */);
    // 00513071  88442451               -mov byte ptr [esp + 0x51], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(81) /* 0x51 */) = cpu.al;
    // 00513075  8a4176                 -mov al, byte ptr [ecx + 0x76]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(118) /* 0x76 */);
    // 00513078  88442452               -mov byte ptr [esp + 0x52], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(82) /* 0x52 */) = cpu.al;
    // 0051307c  8a4177                 -mov al, byte ptr [ecx + 0x77]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(119) /* 0x77 */);
    // 0051307f  88442453               -mov byte ptr [esp + 0x53], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(83) /* 0x53 */) = cpu.al;
    // 00513083  8b4176                 -mov eax, dword ptr [ecx + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(118) /* 0x76 */);
    // 00513086  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00513089  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051308b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051308e  6689442454             -mov word ptr [esp + 0x54], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.ax;
    // 00513093  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 00513096  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00513099  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051309b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051309e  6689442456             -mov word ptr [esp + 0x56], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(86) /* 0x56 */) = cpu.ax;
    // 005130a3  8b417c                 -mov eax, dword ptr [ecx + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 005130a6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005130a8  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 005130ac  8b8180000000           -mov eax, dword ptr [ecx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 005130b2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005130b4  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 005130b8  8b8184000000           -mov eax, dword ptr [ecx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 005130be  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005130c0  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 005130c4  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 005130c7  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005130cb  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005130cd  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 005130d1  8d5154                 -lea edx, [ecx + 0x54]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 005130d4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005130d7  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 005130dc  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 005130e0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005130e1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005130e2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005130e3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005130e4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005130e5  e846ddfcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 005130ea  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005130ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x005130ee:
    // 005130ee  40                     -inc eax
    (cpu.eax)++;
    // 005130ef  8a9a94000000           -mov bl, byte ptr [edx + 0x94]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(148) /* 0x94 */);
    // 005130f5  42                     -inc edx
    (cpu.edx)++;
    // 005130f6  885c0427               -mov byte ptr [esp + eax + 0x27], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(39) /* 0x27 */ + cpu.eax * 1) = cpu.bl;
    // 005130fa  83f808                 +cmp eax, 8
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
    // 005130fd  7cef                   -jl 0x5130ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005130ee;
    }
    // 005130ff  8b858c000000           -mov eax, dword ptr [ebp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 00513105  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513107  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0051310b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051310d  668b8590000000         -mov ax, word ptr [ebp + 0x90]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00513114  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513116  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00513119  6689442424             -mov word ptr [esp + 0x24], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ax;
    // 0051311e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00513120  668b8592000000         -mov ax, word ptr [ebp + 0x92]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(146) /* 0x92 */);
    // 00513127  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513129  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051312c  8b35e06d5600           -mov esi, dword ptr [0x566de0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 00513132  6689442426             -mov word ptr [esp + 0x26], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(38) /* 0x26 */) = cpu.ax;
    // 00513137  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051313a  7c1e                   -jl 0x51315a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051315a;
    }
    // 0051313c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051313e  b9ac000000             -mov ecx, 0xac
    cpu.ecx = 172 /*0xac*/;
    // 00513143  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00513147  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513149  8d9424bc000000         -lea edx, [esp + 0xbc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513150  b864025500             -mov eax, 0x550264
    cpu.eax = 5571172 /*0x550264*/;
    // 00513155  e826f0ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051315a:
    // 0051315a  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0051315f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00513163  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0051316a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051316d  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513174  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00513177  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051317a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051317b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051317c:
    // 0051317c  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00513182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513183  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513184  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_513190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00513190  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00513191  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00513192  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00513193  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00513196  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00513198  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0051319c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0051319f  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 005131a3  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005131aa  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005131ad  a1dc895600             -mov eax, dword ptr [0x5689dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671388) /* 0x5689dc */);
    // 005131b2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005131b7  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005131b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005131bb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 005131bd  a3dc895600             -mov dword ptr [0x5689dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5671388) /* 0x5689dc */) = cpu.eax;
    // 005131c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005131c4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005131c6  8b15e06d5600           -mov edx, dword ptr [0x566de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 005131cc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 005131ce  83fa03                 +cmp edx, 3
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
    // 005131d1  7d4e                   -jge 0x513221
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00513221;
    }
L_0x005131d3:
    // 005131d3  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 005131d6  83784800               +cmp dword ptr [eax + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005131da  740b                   -je 0x5131e7
    if (cpu.flags.zf)
    {
        goto L_0x005131e7;
    }
    // 005131dc  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005131de  8d571c                 -lea edx, [edi + 0x1c]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 005131e1  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 005131e4  ff5548                 -call dword ptr [ebp + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005131e7:
    // 005131e7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005131eb  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005131ee  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005131f2  e8c9fdffff             -call 0x512fc0
    cpu.esp -= 4;
    sub_512fc0(app, cpu);
    if (cpu.terminate) return;
    // 005131f7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005131fb  83780400               +cmp dword ptr [eax + 4], 0
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
    // 005131ff  7510                   -jne 0x513211
    if (!cpu.flags.zf)
    {
        goto L_0x00513211;
    }
    // 00513201  8d471c                 -lea eax, [edi + 0x1c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00513204  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00513208:
    // 00513208  e8c3fdffff             -call 0x512fd0
    cpu.esp -= 4;
    sub_512fd0(app, cpu);
    if (cpu.terminate) return;
    // 0051320d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051320f  742c                   -je 0x51323d
    if (cpu.flags.zf)
    {
        goto L_0x0051323d;
    }
L_0x00513211:
    // 00513211  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00513218  83c410                 +add esp, 0x10
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
    // 0051321b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051321c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051321d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051321e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00513221:
    // 00513221  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513223  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00513227  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051322b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051322d  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00513231  b870025500             -mov eax, 0x550270
    cpu.eax = 5571184 /*0x550270*/;
    // 00513236  e845efffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051323b  eb96                   -jmp 0x5131d3
    goto L_0x005131d3;
L_0x0051323d:
    // 0051323d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00513241  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00513245  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00513248  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0051324b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051324c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00513250  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00513253  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00513256  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513258  7406                   -je 0x513260
    if (cpu.flags.zf)
    {
        goto L_0x00513260;
    }
    // 0051325a  8b35dc6d5600           -mov esi, dword ptr [0x566ddc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664220) /* 0x566ddc */);
L_0x00513260:
    // 00513260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00513262  e8c9c6fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00513267  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513269  7521                   -jne 0x51328c
    if (!cpu.flags.zf)
    {
        goto L_0x0051328c;
    }
    // 0051326b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051326d  e86ec6fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x00513272:
    // 00513272  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00513276  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0051327a  748c                   -je 0x513208
    if (cpu.flags.zf)
    {
        goto L_0x00513208;
    }
    // 0051327c  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00513283  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00513286  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513287  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513288  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513289  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0051328c:
    // 0051328c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051328e  e88d44fdff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 00513293  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513295  0f8c76ffffff           -jl 0x513211
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00513211;
    }
    // 0051329b  ebd5                   -jmp 0x513272
    goto L_0x00513272;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5132a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005132a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005132a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005132a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005132a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005132a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005132a5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005132a8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005132aa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 005132ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005132ae  8db088000000           -lea esi, [eax + 0x88]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(136) /* 0x88 */);
L_0x005132b4:
    // 005132b4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 005132b7  8b8784000000           -mov eax, dword ptr [edi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 005132bd  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 005132c0  48                     -dec eax
    (cpu.eax)--;
    // 005132c1  39c8                   +cmp eax, ecx
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
    // 005132c3  7645                   -jbe 0x51330a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051330a;
    }
    // 005132c5  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 005132c8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005132cd  8b5f50                 -mov ebx, dword ptr [edi + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 005132d0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005132d2  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 005132d4  7509                   -jne 0x5132df
    if (!cpu.flags.zf)
    {
        goto L_0x005132df;
    }
L_0x005132d6:
    // 005132d6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 005132d9  42                     -inc edx
    (cpu.edx)++;
    // 005132da  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005132dd  ebd5                   -jmp 0x5132b4
    goto L_0x005132b4;
L_0x005132df:
    // 005132df  6b0c2464               -imul ecx, dword ptr [esp], 0x64
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 005132e3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005132e5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005132e7  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 005132ea  e8511dfeff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 005132ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005132f1  74e3                   -je 0x5132d6
    if (cpu.flags.zf)
    {
        goto L_0x005132d6;
    }
    // 005132f3  a1d46d5600             -mov eax, dword ptr [0x566dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 005132f8  898439e4000000         -mov dword ptr [ecx + edi + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */ + cpu.edi * 1) = cpu.eax;
    // 005132ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00513301  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00513304  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513305  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513306  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513307  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513308  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513309  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051330a:
    // 0051330a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051330c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051330f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513310  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513311  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513312  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513313  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513314  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_513320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00513320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00513321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513322  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00513323  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00513325  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00513327  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00513329:
    // 00513329  8b9384000000           -mov edx, dword ptr [ebx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(132) /* 0x84 */);
    // 0051332f  4a                     -dec edx
    (cpu.edx)--;
    // 00513330  39d0                   +cmp eax, edx
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
    // 00513332  7356                   -jae 0x51338a
    if (!cpu.flags.cf)
    {
        goto L_0x0051338a;
    }
    // 00513334  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00513339  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0051333b  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0051333d  8b4b50                 -mov ecx, dword ptr [ebx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 00513340  85ca                   +test edx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.ecx));
    // 00513342  7403                   -je 0x513347
    if (cpu.flags.zf)
    {
        goto L_0x00513347;
    }
    // 00513344  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00513345  ebe2                   -jmp 0x513329
    goto L_0x00513329;
L_0x00513347:
    // 00513347  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00513348  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0051334a  09d7                   -or edi, edx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0051334c  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00513353  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00513355  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00513358  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051335a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0051335d  897b50                 -mov dword ptr [ebx + 0x50], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 00513360  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00513362  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00513367  8dbb88000000           -lea edi, [ebx + 0x88]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(136) /* 0x88 */);
    // 0051336d  8b15d46d5600           -mov edx, dword ptr [0x566dd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 00513373  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513375  8993e4000000           -mov dword ptr [ebx + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0051337b  8983e8000000           -mov dword ptr [ebx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00513381  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00513383  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513384  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00513386  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513388  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051338a:
    // 0051338a  687c025500             -push 0x55027c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571196 /*0x55027c*/;
    cpu.esp -= 4;
    // 0051338f  e85cd5fcff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 00513394  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00513396  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00513399  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051339b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051339c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051339d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051339e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5133a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005133a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005133a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005133a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005133a3  81ecd0000000           -sub esp, 0xd0
    (cpu.esp) -= x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 005133a9  8bbc24e0000000         -mov edi, dword ptr [esp + 0xe0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 005133b0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005133b2  899424cc000000         -mov dword ptr [esp + 0xcc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */) = cpu.edx;
    // 005133b9  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 005133c0  898c24b8000000         -mov dword ptr [esp + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 005133c7  8b6810                 -mov ebp, dword ptr [eax + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 005133ca  81fb216f6eea           +cmp ebx, 0xea6e6f21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933105953 /*0xea6e6f21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005133d0  7331                   -jae 0x513403
    if (!cpu.flags.cf)
    {
        goto L_0x00513403;
    }
    // 005133d2  81fb657962ea           +cmp ebx, 0xea627965
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932322149 /*0xea627965*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005133d8  0f835e020000           -jae 0x51363c
    if (!cpu.flags.cf)
    {
        goto L_0x0051363c;
    }
    // 005133de  81fb646461ea           +cmp ebx, 0xea616464
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932251236 /*0xea616464*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005133e4  0f83a9030000           -jae 0x513793
    if (!cpu.flags.cf)
    {
        goto L_0x00513793;
    }
L_0x005133ea:
    // 005133ea  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005133f1  0f8dbd0c0000           -jge 0x5140b4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005140b4;
    }
L_0x005133f7:
    // 005133f7  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005133fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005133fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005133ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513400  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513403:
    // 00513403  772c                   -ja 0x513431
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00513431;
    }
    // 00513405  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051340c  7ce9                   -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 0051340e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00513410  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513411  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513416  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00513418  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513419  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051341b  b880035500             -mov eax, 0x550380
    cpu.eax = 5571456 /*0x550380*/;
    // 00513420  e85bedffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513425  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 0051342b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051342c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051342d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051342e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513431:
    // 00513431  81fb796c70ea           +cmp ebx, 0xea706c79
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513437  0f83a0000000           -jae 0x5134dd
    if (!cpu.flags.cf)
    {
        goto L_0x005134dd;
    }
    // 0051343d  81fb6e706fea           +cmp ebx, 0xea6f706e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933171822 /*0xea6f706e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513443  0f8353010000           -jae 0x51359c
    if (!cpu.flags.cf)
    {
        goto L_0x0051359c;
    }
    // 00513449  81fb616c6fea           +cmp ebx, 0xea6f6c61
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933170785 /*0xea6f6c61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051344f  7599                   -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
    // 00513451  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513454  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00513456  0f85900b0000           -jne 0x513fec
    if (!cpu.flags.zf)
    {
        goto L_0x00513fec;
    }
    // 0051345c  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513463  7492                   -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513465  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051346c  7489                   -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 0051346e  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00513471  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513473  e8c81bfeff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00513478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051347a  0f8477ffffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513480  bf616c6fea             -mov edi, 0xea6f6c61
    cpu.edi = 3933170785 /*0xea6f6c61*/;
    // 00513485  a1d46d5600             -mov eax, dword ptr [0x566dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 0051348a  89bc24b0000000         -mov dword ptr [esp + 0xb0], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edi;
    // 00513491  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513492  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00513498  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0051349b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051349e  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 005134a5  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005134a8  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005134ab  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005134b2  0f8c3fffffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 005134b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005134ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005134bb  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 005134c2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005134c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005134c5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005134c7  b898035500             -mov eax, 0x550398
    cpu.eax = 5571480 /*0x550398*/;
    // 005134cc  e8afecffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 005134d1  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005134d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005134d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005134d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005134da  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005134dd:
    // 005134dd  0f86c9030000           -jbe 0x5138ac
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005138ac;
    }
    // 005134e3  81fb707372ea           +cmp ebx, 0xea727370
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933369200 /*0xea727370*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005134e9  7358                   -jae 0x513543
    if (!cpu.flags.cf)
    {
        goto L_0x00513543;
    }
    // 005134eb  81fb716572ea           +cmp ebx, 0xea726571
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933365617 /*0xea726571*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005134f1  0f85f3feffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
    // 005134f7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005134f9  0f84f8feffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005134ff  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00513503  0f84eefeffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513509  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0051350e  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513515  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 0051351c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051351e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513520  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513522  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513529  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051352b  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051352e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00513530  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00513532  e8f9faffff             -call 0x513030
    cpu.esp -= 4;
    sub_513030(app, cpu);
    if (cpu.terminate) return;
    // 00513537  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051353d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051353e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051353f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513540  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513543:
    // 00513543  0f8678090000           -jbe 0x513ec1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00513ec1;
    }
    // 00513549  81fb767273ea           +cmp ebx, 0xea737276
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933434486 /*0xea737276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051354f  0f8595feffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
    // 00513555  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00513557  0f849afeffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 0051355d  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513560  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00513562  0f848ffeffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513568  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0051356d  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00513570  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00513572  e8197efdff             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 00513577  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513579  0f8578feffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 0051357f  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00513586  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513589  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051358b  e8a0faffff             -call 0x513030
    cpu.esp -= 4;
    sub_513030(app, cpu);
    if (cpu.terminate) return;
    // 00513590  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00513596  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513597  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513598  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513599  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0051359c:
    // 0051359c  7762                   -ja 0x513600
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00513600;
    }
    // 0051359e  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005135a5  7c17                   -jl 0x5135be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005135be;
    }
    // 005135a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005135a9  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 005135ae  b878035500             -mov eax, 0x550378
    cpu.eax = 5571448 /*0x550378*/;
    // 005135b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005135b5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005135b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005135b9  e8c2ebffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x005135be:
    // 005135be  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005135c2  0f842ffeffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005135c8  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 005135cf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005135d1  ff5510                 -call dword ptr [ebp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005135d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005135d6  0f851bfeffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005135dc  bb216f6eea             -mov ebx, 0xea6e6f21
    cpu.ebx = 3933105953 /*0xea6e6f21*/;
    // 005135e1  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 005135e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005135e9  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005135ec  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005135ee  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005135f1  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005135f4  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 005135fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005135fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005135fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005135fd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513600:
    // 00513600  81fb74756fea           +cmp ebx, 0xea6f7574
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933173108 /*0xea6f7574*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513606  0f85defdffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
L_0x0051360c:
    // 0051360c  833de06d560002         +cmp dword ptr [0x566de0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513613  0f8d230a0000           -jge 0x51403c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051403c;
    }
L_0x00513619:
    // 00513619  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051361c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051361e  0f853b0a0000           -jne 0x51405f
    if (!cpu.flags.zf)
    {
        goto L_0x0051405f;
    }
    // 00513624  898da4000000           -mov dword ptr [ebp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0051362a  898da0000000           -mov dword ptr [ebp + 0xa0], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.ecx;
    // 00513630  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00513636  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513637  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513638  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513639  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0051363c:
    // 0051363c  76ce                   -jbe 0x51360c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051360c;
    }
    // 0051363e  81fb636564ea           +cmp ebx, 0xea646563
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513644  734d                   -jae 0x513693
    if (!cpu.flags.cf)
    {
        goto L_0x00513693;
    }
    // 00513646  81fb746164ea           +cmp ebx, 0xea646174
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932447092 /*0xea646174*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051364c  0f8598fdffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
    // 00513652  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513655  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00513657  0f85cc090000           -jne 0x514029
    if (!cpu.flags.zf)
    {
        goto L_0x00514029;
    }
    // 0051365d  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00513660  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513662  e8d919feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00513667  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513669  0f8488fdffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 0051366f  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513676  0f847bfdffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 0051367c  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 00513681  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00513687  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051368d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051368e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051368f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513690  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513693:
    // 00513693  0f8624030000           -jbe 0x5139bd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005139bd;
    }
    // 00513699  81fb746567ea           +cmp ebx, 0xea676574
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932644724 /*0xea676574*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051369f  0f8545fdffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
    // 005136a5  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 005136a9  0f8448fdffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005136af  bf796c70ea             -mov edi, 0xea706c79
    cpu.edi = 3933236345 /*0xea706c79*/;
    // 005136b4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005136b6  89bc24b0000000         -mov dword ptr [esp + 0xb0], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edi;
    // 005136bd  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005136c1  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005136c4  b878000000             -mov eax, 0x78
    cpu.eax = 120 /*0x78*/;
    // 005136c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005136ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005136cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005136cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005136cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005136ce  898424c8000000         -mov dword ptr [esp + 0xc8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.eax;
    // 005136d5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 005136d7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005136da  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 005136dd  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005136e1  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005136e8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 005136ed  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005136f0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005136f2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005136f4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005136f6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005136fd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005136ff  83f8ff                 +cmp eax, -1
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
    // 00513702  0f8439050000           -je 0x513c41
    if (cpu.flags.zf)
    {
        goto L_0x00513c41;
    }
    // 00513708  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051370d  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0051370f  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513712  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00513714  855350                 -test dword ptr [ebx + 0x50], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) & cpu.edx));
    // 00513717  0f8435050000           -je 0x513c52
    if (cpu.flags.zf)
    {
        goto L_0x00513c52;
    }
    // 0051371d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051371f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00513722  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00513724  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00513727  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00513729  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051372b  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00513730  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00513734  8db48688000000         -lea esi, [esi + eax*4 + 0x88]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(136) /* 0x88 */ + cpu.eax * 4);
L_0x0051373b:
    // 0051373b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0051373d:
    // 0051373d  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513744  7c20                   -jl 0x513766
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00513766;
    }
    // 00513746  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513748  8b8c24cc000000         -mov ecx, dword ptr [esp + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 0051374f  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00513753  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513755  8d9424b8000000         -lea edx, [esp + 0xb8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0051375c  b8dc025500             -mov eax, 0x5502dc
    cpu.eax = 5571292 /*0x5502dc*/;
    // 00513761  e81aeaffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00513766:
    // 00513766  8b8424c8000000         -mov eax, dword ptr [esp + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0051376d  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0051376f  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513776  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00513779  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051377a  8b9424d0000000         -mov edx, dword ptr [esp + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513781  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00513784  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00513787  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051378d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051378e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051378f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513790  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513793:
    // 00513793  0f8707010000           -ja 0x5138a0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005138a0;
    }
    // 00513799  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051379c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051379e  0f8453fcffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005137a4  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005137a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005137a9  0f8548fcffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 005137af  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 005137b6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005137b9  bb707372ea             -mov ebx, 0xea727370
    cpu.ebx = 3933369200 /*0xea727370*/;
    // 005137be  e8ddfaffff             -call 0x5132a0
    cpu.esp -= 4;
    sub_5132a0(app, cpu);
    if (cpu.terminate) return;
    // 005137c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005137c5  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005137cc  899c24b0000000         -mov dword ptr [esp + 0xb0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.ebx;
    // 005137d3  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 005137d8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005137da  89b424bc000000         -mov dword ptr [esp + 0xbc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.esi;
    // 005137e1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005137e4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005137e6  0f84fb040000           -je 0x513ce7
    if (cpu.flags.zf)
    {
        goto L_0x00513ce7;
    }
    // 005137ec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005137f1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005137f3  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005137f7  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005137fa  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 005137ff  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00513801  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00513806  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00513808  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051380b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051380d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051380f  8b3de06d5600           -mov edi, dword ptr [0x566de0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 00513815  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00513819  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051381c  7c21                   -jl 0x51383f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051383f;
    }
    // 0051381e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00513820  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513821  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513826  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0051382d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051382e  8d9424b8000000         -lea edx, [esp + 0xb8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513835  b83c035500             -mov eax, 0x55033c
    cpu.eax = 5571388 /*0x55033c*/;
L_0x0051383a:
    // 0051383a  e841e9ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051383f:
    // 0051383f  8b8424bc000000         -mov eax, dword ptr [esp + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513846  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00513848  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0051384f  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00513852  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513853  8b9424d0000000         -mov edx, dword ptr [esp + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0051385a  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051385d  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00513860  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513862  0f858ffbffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513868  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051386f  0f8c82fbffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00513875  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513876  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0051387b  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513882  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513883  8d9424b8000000         -lea edx, [esp + 0xb8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0051388a  b848035500             -mov eax, 0x550348
    cpu.eax = 5571400 /*0x550348*/;
    // 0051388f  e8ece8ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513894  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 0051389a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051389b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051389c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051389d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005138a0:
    // 005138a0  81fb646162ea           +cmp ebx, 0xea626164
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932316004 /*0xea626164*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005138a6  0f853efbffff           -jne 0x5133ea
    if (!cpu.flags.zf)
    {
        goto L_0x005133ea;
    }
L_0x005138ac:
    // 005138ac  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005138af  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 005138b6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005138b8  e88317feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 005138bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005138bf  0f84ed030000           -je 0x513cb2
    if (cpu.flags.zf)
    {
        goto L_0x00513cb2;
    }
    // 005138c5  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005138cc  740b                   -je 0x5138d9
    if (cpu.flags.zf)
    {
        goto L_0x005138d9;
    }
    // 005138ce  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 005138d3  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x005138d9:
    // 005138d9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 005138de  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005138e5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005138e7  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005138e9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005138eb  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005138f2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005138f4  837e1800               +cmp dword ptr [esi + 0x18], 0
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
    // 005138f8  0f847d030000           -je 0x513c7b
    if (cpu.flags.zf)
    {
        goto L_0x00513c7b;
    }
    // 005138fe  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513900  0f8575030000           -jne 0x513c7b
    if (!cpu.flags.zf)
    {
        goto L_0x00513c7b;
    }
    // 00513906  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051390d  7c1e                   -jl 0x51392d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051392d;
    }
    // 0051390f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513911  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513918  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0051391f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513921  b8e8025500             -mov eax, 0x5502e8
    cpu.eax = 5571304 /*0x5502e8*/;
    // 00513926  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513928  e853e8ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051392d:
    // 0051392d  81bc24ac000000796c70ea +cmp dword ptr [esp + 0xac], 0xea706c79
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513938  756a                   -jne 0x5139a4
    if (!cpu.flags.zf)
    {
        goto L_0x005139a4;
    }
    // 0051393a  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513941  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513946  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00513949  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051394b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051394d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051394f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513956  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513958  83f8ff                 +cmp eax, -1
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
    // 0051395b  0f8513030000           -jne 0x513c74
    if (!cpu.flags.zf)
    {
        goto L_0x00513c74;
    }
    // 00513961  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00513966:
    // 00513966  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0051396d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513972  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00513975  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513977  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513979  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051397b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513982  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513984  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00513987  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0051398e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00513990  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00513993  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00513996  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00513998  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051399a  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051399d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051399f  7503                   -jne 0x5139a4
    if (!cpu.flags.zf)
    {
        goto L_0x005139a4;
    }
    // 005139a1  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x005139a4:
    // 005139a4  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005139aa  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 005139b1  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 005139b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005139b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005139b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005139ba  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005139bd:
    // 005139bd  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 005139c2  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005139c9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005139cb  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005139cd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005139cf  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005139d6  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005139d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005139da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005139dc  0f8551020000           -jne 0x513c33
    if (!cpu.flags.zf)
    {
        goto L_0x00513c33;
    }
    // 005139e2  833e00                 +cmp dword ptr [esi], 0
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
    // 005139e5  0f8548020000           -jne 0x513c33
    if (!cpu.flags.zf)
    {
        goto L_0x00513c33;
    }
    // 005139eb  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 005139ef  0f843e020000           -je 0x513c33
    if (cpu.flags.zf)
    {
        goto L_0x00513c33;
    }
    // 005139f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x005139fa:
    // 005139fa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005139fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005139fe  753c                   -jne 0x513a3c
    if (!cpu.flags.zf)
    {
        goto L_0x00513a3c;
    }
    // 00513a00  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00513a04  0f8530020000           -jne 0x513c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00513c3a;
    }
    // 00513a0a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00513a0c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00513a0e  0f8426020000           -je 0x513c3a
    if (cpu.flags.zf)
    {
        goto L_0x00513c3a;
    }
    // 00513a14  39ca                   +cmp edx, ecx
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
    // 00513a16  0f851e020000           -jne 0x513c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00513c3a;
    }
    // 00513a1c  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00513a1f  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00513a26  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513a28  e81316feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00513a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513a2f  0f8405020000           -je 0x513c3a
    if (cpu.flags.zf)
    {
        goto L_0x00513c3a;
    }
    // 00513a35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00513a3a:
    // 00513a3a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00513a3c:
    // 00513a3c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00513a3e  0f84b3f9ffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513a44  83bda000000000         +cmp dword ptr [ebp + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513a4b  7411                   -je 0x513a5e
    if (cpu.flags.zf)
    {
        goto L_0x00513a5e;
    }
    // 00513a4d  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00513a51  750b                   -jne 0x513a5e
    if (!cpu.flags.zf)
    {
        goto L_0x00513a5e;
    }
    // 00513a53  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 00513a58  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
L_0x00513a5e:
    // 00513a5e  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513a65  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00513a6a  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00513a6d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513a6f  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513a71  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513a73  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513a7a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513a7c  88463c                 -mov byte ptr [esi + 0x3c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 00513a7f  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513a86  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00513a8b  83c049                 -add eax, 0x49
    (cpu.eax) += x86::reg32(x86::sreg32(73 /*0x49*/));
    // 00513a8e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513a90  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513a92  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513a94  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513a9b  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513a9d  88463d                 -mov byte ptr [esi + 0x3d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 00513aa0  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513aa7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00513aac  83c04a                 -add eax, 0x4a
    (cpu.eax) += x86::reg32(x86::sreg32(74 /*0x4a*/));
    // 00513aaf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513ab1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513ab3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513ab5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513abc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513abe  88463e                 -mov byte ptr [esi + 0x3e], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */) = cpu.al;
    // 00513ac1  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513ac8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00513acd  83c04b                 -add eax, 0x4b
    (cpu.eax) += x86::reg32(x86::sreg32(75 /*0x4b*/));
    // 00513ad0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513ad2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513ad4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513ad6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513add  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513adf  88463f                 -mov byte ptr [esi + 0x3f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = cpu.al;
    // 00513ae2  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513ae9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00513aee  83c04c                 -add eax, 0x4c
    (cpu.eax) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00513af1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513af3  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513af5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513af7  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513afe  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513b00  66894640               -mov word ptr [esi + 0x40], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 00513b04  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513b0b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00513b10  83c04e                 -add eax, 0x4e
    (cpu.eax) += x86::reg32(x86::sreg32(78 /*0x4e*/));
    // 00513b13  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513b15  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513b17  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513b19  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513b20  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513b22  66894642               -mov word ptr [esi + 0x42], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00513b26  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513b2d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513b32  83c050                 -add eax, 0x50
    (cpu.eax) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00513b35  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513b3c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513b3e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513b40  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513b42  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513b49  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513b4b  894644                 -mov dword ptr [esi + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00513b4e  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513b55  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513b5a  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00513b5d  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00513b62  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513b64  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513b66  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513b68  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513b6f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513b71  894648                 -mov dword ptr [esi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00513b74  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513b7b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513b80  83c058                 -add eax, 0x58
    (cpu.eax) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00513b83  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00513b86  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513b88  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513b8a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513b8c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513b93  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513b95  89464c                 -mov dword ptr [esi + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00513b98  8d461c                 -lea eax, [esi + 0x1c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00513b9b  e890d2fcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00513ba0  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513ba7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513bac  83c06c                 -add eax, 0x6c
    (cpu.eax) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00513baf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513bb1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513bb3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513bb5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513bbc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513bbe  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00513bc5  8b0de06d5600           -mov ecx, dword ptr [0x566de0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 00513bcb  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00513bce  83f903                 +cmp ecx, 3
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
    // 00513bd1  7c1e                   -jl 0x513bf1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00513bf1;
    }
    // 00513bd3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513bd5  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513bdc  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513be3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513be5  b8d0025500             -mov eax, 0x5502d0
    cpu.eax = 5571280 /*0x5502d0*/;
    // 00513bea  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513bec  e88fe5ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00513bf1:
    // 00513bf1  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00513bf5  0f84fcf7ffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513bfb  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513c02  8b406c                 -mov eax, dword ptr [eax + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 00513c05  8b8c24cc000000         -mov ecx, dword ptr [esp + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00513c0c  e8eff3ffff             -call 0x513000
    cpu.esp -= 4;
    sub_513000(app, cpu);
    if (cpu.terminate) return;
    // 00513c11  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00513c14  8d561c                 -lea edx, [esi + 0x1c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00513c17  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513c19  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00513c1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513c1e  0f85d3f7ffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513c24  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00513c27  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513c2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513c2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513c2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513c30  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513c33:
    // 00513c33  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00513c35  e9c0fdffff             -jmp 0x5139fa
    goto L_0x005139fa;
L_0x00513c3a:
    // 00513c3a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00513c3c  e9f9fdffff             -jmp 0x513a3a
    goto L_0x00513a3a;
L_0x00513c41:
    // 00513c41  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00513c46  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00513c4a  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00513c4d  e9e9faffff             -jmp 0x51373b
    goto L_0x0051373b;
L_0x00513c52:
    // 00513c52  8bb424c8000000         -mov esi, dword ptr [esp + 0xc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00513c59  bb646162ea             -mov ebx, 0xea626164
    cpu.ebx = 3932316004 /*0xea626164*/;
    // 00513c5e  83ee5c                 +sub esi, 0x5c
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00513c61  899c24b0000000         -mov dword ptr [esp + 0xb0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.ebx;
    // 00513c68  89b424c8000000         -mov dword ptr [esp + 0xc8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.esi;
    // 00513c6f  e9c9faffff             -jmp 0x51373d
    goto L_0x0051373d;
L_0x00513c74:
    // 00513c74  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00513c76  e9ebfcffff             -jmp 0x513966
    goto L_0x00513966;
L_0x00513c7b:
    // 00513c7b  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513c82  0f8c6ff7ffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00513c88  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513c8a  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513c91  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513c98  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513c9a  b8f4025500             -mov eax, 0x5502f4
    cpu.eax = 5571316 /*0x5502f4*/;
    // 00513c9f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513ca1  e8dae4ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513ca6  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513cac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513cad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513cae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513caf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513cb2:
    // 00513cb2  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513cb9  0f8c38f7ffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00513cbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513cc0  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513cc7  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513cce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513ccf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513cd1  b800035500             -mov eax, 0x550300
    cpu.eax = 5571328 /*0x550300*/;
    // 00513cd6  e8a5e4ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513cdb  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513ce1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513ce2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513ce3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513ce4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513ce7:
    // 00513ce7  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513cea  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513ced  8b9284000000           -mov edx, dword ptr [edx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00513cf3  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00513cf6  4a                     -dec edx
    (cpu.edx)--;
    // 00513cf7  e804f3ffff             -call 0x513000
    cpu.esp -= 4;
    sub_513000(app, cpu);
    if (cpu.terminate) return;
    // 00513cfc  39d0                   +cmp eax, edx
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
    // 00513cfe  0f8386010000           -jae 0x513e8a
    if (!cpu.flags.cf)
    {
        goto L_0x00513e8a;
    }
    // 00513d04  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513d07  80783c00               +cmp byte ptr [eax + 0x3c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00513d0b  0f85cb000000           -jne 0x513ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00513ddc;
    }
L_0x00513d11:
    // 00513d11  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513d18  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00513d1b  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00513d22  8bbc24b8000000         -mov edi, dword ptr [esp + 0xb8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513d29  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00513d30  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513d33  8bb424cc000000         -mov esi, dword ptr [esp + 0xcc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00513d3a  e8e1f5ffff             -call 0x513320
    cpu.esp -= 4;
    sub_513320(app, cpu);
    if (cpu.terminate) return;
    // 00513d3f  8d7f28                 -lea edi, [edi + 0x28]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00513d42  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00513d49  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513d4a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513d4b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513d4c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513d4d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513d4e  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 00513d55  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513d58  83784c00               +cmp dword ptr [eax + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513d5c  7420                   -je 0x513d7e
    if (cpu.flags.zf)
    {
        goto L_0x00513d7e;
    }
    // 00513d5e  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00513d65  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00513d6c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00513d6e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00513d70  43                     -inc ebx
    (cpu.ebx)++;
    // 00513d71  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513d73  ff564c                 -call dword ptr [esi + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00513d76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513d78  0f84b6000000           -je 0x513e34
    if (cpu.flags.zf)
    {
        goto L_0x00513e34;
    }
L_0x00513d7e:
    // 00513d7e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00513d83  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513d85  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00513d89  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00513d90  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00513d95  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513d97  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00513d9b  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513da2  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00513da6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00513da9  e84267fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00513dae  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513db5  0f8c84faffff           -jl 0x51383f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051383f;
    }
    // 00513dbb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513dbd  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513dc2  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513dc9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513dcb  8d9424b8000000         -lea edx, [esp + 0xb8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513dd2  b80c035500             -mov eax, 0x55030c
    cpu.eax = 5571340 /*0x55030c*/;
    // 00513dd7  e95efaffff             -jmp 0x51383a
    goto L_0x0051383a;
L_0x00513ddc:
    // 00513ddc  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00513de1  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513de8  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00513deb  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00513dee  e89d75fdff             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 00513df3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513df5  0f8416ffffff           -je 0x513d11
    if (cpu.flags.zf)
    {
        goto L_0x00513d11;
    }
    // 00513dfb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00513e00  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513e02  8b15e06d5600           -mov edx, dword ptr [0x566de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 00513e08  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00513e0c  83fa03                 +cmp edx, 3
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
    // 00513e0f  0f8c2afaffff           -jl 0x51383f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051383f;
    }
    // 00513e15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513e16  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513e1d  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00513e24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513e25  b824035500             -mov eax, 0x550324
    cpu.eax = 5571364 /*0x550324*/;
    // 00513e2a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513e2f  e906faffff             -jmp 0x51383a
    goto L_0x0051383a;
L_0x00513e34:
    // 00513e34  8a8c24c4000000         -mov cl, byte ptr [esp + 0xc4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00513e3b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00513e40  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00513e43  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00513e45  8b5850                 -mov ebx, dword ptr [eax + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00513e48  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00513e4a  21d3                   -and ebx, edx
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00513e4c  895850                 -mov dword ptr [eax + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00513e4f  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 00513e54  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513e56  8b35e06d5600           -mov esi, dword ptr [0x566de0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 00513e5c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00513e60  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513e63  0f8cd6f9ffff           -jl 0x51383f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051383f;
    }
    // 00513e69  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513e6b  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513e70  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513e77  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513e79  8d9424b8000000         -lea edx, [esp + 0xb8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513e80  b818035500             -mov eax, 0x550318
    cpu.eax = 5571352 /*0x550318*/;
    // 00513e85  e9b0f9ffff             -jmp 0x51383a
    goto L_0x0051383a;
L_0x00513e8a:
    // 00513e8a  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00513e8f  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513e91  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00513e95  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513e9c  0f8c9df9ffff           -jl 0x51383f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051383f;
    }
    // 00513ea2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513ea3  8b9c24d0000000         -mov ebx, dword ptr [esp + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00513eaa  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00513eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00513eb2  b830035500             -mov eax, 0x550330
    cpu.eax = 5571376 /*0x550330*/;
    // 00513eb7  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00513ebc  e979f9ffff             -jmp 0x51383a
    goto L_0x0051383a;
L_0x00513ec1:
    // 00513ec1  8d5d1c                 -lea ebx, [ebp + 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00513ec4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00513ec6  e87511feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00513ecb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513ecd  7535                   -jne 0x513f04
    if (!cpu.flags.zf)
    {
        goto L_0x00513f04;
    }
    // 00513ecf  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513ed6  0f8c1bf5ffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00513edc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513edd  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513ee4  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513eeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00513eec  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513eee  b86c035500             -mov eax, 0x55036c
    cpu.eax = 5571436 /*0x55036c*/;
    // 00513ef3  e888e2ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513ef8  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513efe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513eff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513f00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513f01  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513f04:
    // 00513f04  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513f09  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513f10  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513f12  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513f14  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513f16  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513f1d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513f1f  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513f21  0f858e000000           -jne 0x513fb5
    if (!cpu.flags.zf)
    {
        goto L_0x00513fb5;
    }
    // 00513f27  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513f2e  7c1e                   -jl 0x513f4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00513f4e;
    }
    // 00513f30  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513f32  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513f39  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513f40  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513f42  b854035500             -mov eax, 0x550354
    cpu.eax = 5571412 /*0x550354*/;
    // 00513f47  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513f49  e832e2ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00513f4e:
    // 00513f4e  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513f55  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00513f5a  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00513f5d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00513f5f  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00513f61  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00513f63  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00513f6a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00513f6c  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00513f6f  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00513f72  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00513f78  83ff01                 +cmp edi, 1
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
    // 00513f7b  0f8576f4ffff           -jne 0x5133f7
    if (!cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513f81  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00513f88  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00513f8b  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00513f8e  a1d46d5600             -mov eax, dword ptr [0x566dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 00513f93  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513f94  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513f95  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513f96  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513f97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00513f98  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00513f9e  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 00513fa3  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00513fa9  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513faf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fb2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513fb5:
    // 00513fb5  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00513fbc  0f8c35f4ffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00513fc2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513fc4  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00513fcb  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00513fd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00513fd4  b860035500             -mov eax, 0x550360
    cpu.eax = 5571424 /*0x550360*/;
    // 00513fd9  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00513fdb  e8a0e1ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00513fe0  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00513fe6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fe7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fe8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00513fe9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00513fec:
    // 00513fec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00513fee  e8adf2ffff             -call 0x5132a0
    cpu.esp -= 4;
    sub_5132a0(app, cpu);
    if (cpu.terminate) return;
    // 00513ff3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00513ff5  0f84fcf3ffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00513ffb  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514002  0f8ceff3ffff           -jl 0x5133f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005133f7;
    }
    // 00514008  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051400a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051400b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051400d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051400e  8d5060                 -lea edx, [eax + 0x60]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00514011  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00514013  b888035500             -mov eax, 0x550388
    cpu.eax = 5571464 /*0x550388*/;
    // 00514018  e863e1ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051401d  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 00514023  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514024  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514025  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514026  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00514029:
    // 00514029  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051402b  e870f2ffff             -call 0x5132a0
    cpu.esp -= 4;
    sub_5132a0(app, cpu);
    if (cpu.terminate) return;
    // 00514030  81c4d0000000           +add esp, 0xd0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514036  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514037  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514038  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514039  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0051403c:
    // 0051403c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051403e  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00514045  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0051404c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051404e  b8a8035500             -mov eax, 0x5503a8
    cpu.eax = 5571496 /*0x5503a8*/;
    // 00514053  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00514055  e826e1ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051405a  e9baf5ffff             -jmp 0x513619
    goto L_0x00513619;
L_0x0051405f:
    // 0051405f  8b9424cc000000         -mov edx, dword ptr [esp + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00514066  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00514068  e833f2ffff             -call 0x5132a0
    cpu.esp -= 4;
    sub_5132a0(app, cpu);
    if (cpu.terminate) return;
    // 0051406d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051406f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514071  0f8480f3ffff           -je 0x5133f7
    if (cpu.flags.zf)
    {
        goto L_0x005133f7;
    }
    // 00514077  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051407a  8d9788000000           -lea edx, [edi + 0x88]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(136) /* 0x88 */);
    // 00514080  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00514082  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00514084  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00514089  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051408c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051408e  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00514090  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514095  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00514097  8b5f50                 -mov ebx, dword ptr [edi + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    // 0051409a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0051409c  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0051409e  895f50                 -mov dword ptr [edi + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 005140a1  c7465c00000000         -mov dword ptr [esi + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 005140a8  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 005140ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140b1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005140b4:
    // 005140b4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005140b6  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 005140bd  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 005140c4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005140c6  b8b0035500             -mov eax, 0x5503b0
    cpu.eax = 5571504 /*0x5503b0*/;
    // 005140cb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 005140cd  e8aee0ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 005140d2  81c4d0000000           -add esp, 0xd0
    (cpu.esp) += x86::reg32(x86::sreg32(208 /*0xd0*/));
    // 005140d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005140db  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5140e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005140e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005140e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005140e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005140e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005140e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005140e5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005140e8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005140eb  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005140ed  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005140ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005140f1  0f854f010000           -jne 0x514246
    if (!cpu.flags.zf)
    {
        goto L_0x00514246;
    }
    // 005140f7  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005140fe  751f                   -jne 0x51411f
    if (!cpu.flags.zf)
    {
        goto L_0x0051411f;
    }
    // 00514100  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00514104  7419                   -je 0x51411f
    if (cpu.flags.zf)
    {
        goto L_0x0051411f;
    }
    // 00514106  8ba8a4000000           -mov ebp, dword ptr [eax + 0xa4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0051410c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051410e  740f                   -je 0x51411f
    if (cpu.flags.zf)
    {
        goto L_0x0051411f;
    }
    // 00514110  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 00514114  7509                   -jne 0x51411f
    if (!cpu.flags.zf)
    {
        goto L_0x0051411f;
    }
    // 00514116  8d4dff                 -lea ecx, [ebp - 1]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00514119  8988a4000000           -mov dword ptr [eax + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
L_0x0051411f:
    // 0051411f  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00514122  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00514124  0f841c010000           -je 0x514246
    if (cpu.flags.zf)
    {
        goto L_0x00514246;
    }
    // 0051412a  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051412d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0051412f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00514131  0f850f010000           -jne 0x514246
    if (!cpu.flags.zf)
    {
        goto L_0x00514246;
    }
    // 00514137  837b5000               +cmp dword ptr [ebx + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051413b  0f8405010000           -je 0x514246
    if (cpu.flags.zf)
    {
        goto L_0x00514246;
    }
    // 00514141  c7442404616c6fea       -mov dword ptr [esp + 4], 0xea6f6c61
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 3933170785 /*0xea6f6c61*/;
    // 00514149  8b9fa0000000           -mov ebx, dword ptr [edi + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(160) /* 0xa0 */);
    // 0051414f  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00514153  83fb02                 +cmp ebx, 2
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
    // 00514156  7c40                   -jl 0x514198
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00514198;
    }
    // 00514158  8d6bff                 -lea ebp, [ebx - 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0051415b  89afa0000000           -mov dword ptr [edi + 0xa0], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(160) /* 0xa0 */) = cpu.ebp;
L_0x00514161:
    // 00514161  8d8688000000           -lea eax, [esi + 0x88]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00514167  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514169  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051416d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
L_0x00514170:
    // 00514170  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00514176  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00514179  48                     -dec eax
    (cpu.eax)--;
    // 0051417a  39d8                   +cmp eax, ebx
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
    // 0051417c  0f86c4000000           -jbe 0x514246
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00514246;
    }
    // 00514182  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00514185  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051418a  8b6e50                 -mov ebp, dword ptr [esi + 0x50]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0051418d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0051418f  85e8                   +test eax, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebp));
    // 00514191  7537                   -jne 0x5141ca
    if (!cpu.flags.zf)
    {
        goto L_0x005141ca;
    }
L_0x00514193:
    // 00514193  ff0424                 +inc dword ptr [esp]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00514196  ebd8                   -jmp 0x514170
    goto L_0x00514170;
L_0x00514198:
    // 00514198  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 0051419d  8987a0000000           -mov dword ptr [edi + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 005141a3  833de06d560003         +cmp dword ptr [0x566de0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005141aa  7c14                   -jl 0x5141c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005141c0;
    }
    // 005141ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005141ad  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005141b1  b8bc035500             -mov eax, 0x5503bc
    cpu.eax = 5571516 /*0x5503bc*/;
    // 005141b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005141b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005141b9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 005141bb  e8c0dfffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x005141c0:
    // 005141c0  c744240c01000000       -mov dword ptr [esp + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 005141c8  eb97                   -jmp 0x514161
    goto L_0x00514161;
L_0x005141ca:
    // 005141ca  6bc364                 -imul eax, ebx, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 005141cd  8b9406e4000000         -mov edx, dword ptr [esi + eax + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */ + cpu.eax * 1);
    // 005141d4  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 005141d7  89ac06e4000000         -mov dword ptr [esi + eax + 0xe4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(228) /* 0xe4 */ + cpu.eax * 1) = cpu.ebp;
    // 005141de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005141e0  7536                   -jne 0x514218
    if (!cpu.flags.zf)
    {
        goto L_0x00514218;
    }
    // 005141e2  833de06d560002         +cmp dword ptr [0x566de0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005141e9  7c16                   -jl 0x514201
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00514201;
    }
    // 005141eb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005141ed  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005141f1  b8cc035500             -mov eax, 0x5503cc
    cpu.eax = 5571532 /*0x5503cc*/;
    // 005141f6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005141f8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005141fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005141fc  e87fdfffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00514201:
    // 00514201  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00514204  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514209  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0051420b  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0051420d  214650                 +and dword ptr [esi + 0x50], eax
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */) &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00514210  ff0424                 +inc dword ptr [esp]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00514213  e958ffffff             -jmp 0x514170
    goto L_0x00514170;
L_0x00514218:
    // 00514218  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051421d  0f8470ffffff           -je 0x514193
    if (cpu.flags.zf)
    {
        goto L_0x00514193;
    }
    // 00514223  6b142464               -imul edx, dword ptr [esp], 0x64
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 00514227  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00514229  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051422d  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00514230  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514232  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00514236  01c2                   +add edx, eax
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
    // 00514238  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0051423b  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051423e  ff0424                 +inc dword ptr [esp]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00514241  e92affffff             -jmp 0x514170
    goto L_0x00514170;
L_0x00514246:
    // 00514246  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051424b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051424e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051424f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514252  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514253  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_514260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514261  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00514262  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00514267  bae0405100             -mov edx, 0x5140e0
    cpu.edx = 5325024 /*0x5140e0*/;
    // 0051426c  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 00514271  e86aa6ffff             -call 0x50e8e0
    cpu.esp -= 4;
    sub_50e8e0(app, cpu);
    if (cpu.terminate) return;
    // 00514276  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514278  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_514280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514282  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514283  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00514285  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00514287  8b15e4895600           -mov edx, dword ptr [0x5689e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671396) /* 0x5689e4 */);
    // 0051428d  42                     -inc edx
    (cpu.edx)++;
    // 0051428e  8915e4895600           -mov dword ptr [0x5689e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5671396) /* 0x5689e4 */) = cpu.edx;
    // 00514294  83fa01                 +cmp edx, 1
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
    // 00514297  7514                   -jne 0x5142ad
    if (!cpu.flags.zf)
    {
        goto L_0x005142ad;
    }
    // 00514299  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051429c  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051429f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005142a1  7420                   -je 0x5142c3
    if (cpu.flags.zf)
    {
        goto L_0x005142c3;
    }
    // 005142a3  b860425100             -mov eax, 0x514260
    cpu.eax = 5325408 /*0x514260*/;
    // 005142a8  e883e6fdff             -call 0x4f2930
    cpu.esp -= 4;
    sub_4f2930(app, cpu);
    if (cpu.terminate) return;
L_0x005142ad:
    // 005142ad  bbf0534f00             -mov ebx, 0x4f53f0
    cpu.ebx = 5198832 /*0x4f53f0*/;
    // 005142b2  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 005142b5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005142b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005142b9  ff551c                 -call dword ptr [ebp + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005142bc  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005142bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005142c1  7506                   -jne 0x5142c9
    if (!cpu.flags.zf)
    {
        goto L_0x005142c9;
    }
L_0x005142c3:
    // 005142c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005142c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005142c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005142c6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005142c9:
    // 005142c9  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 005142cc  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 005142cf  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 005142d4  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005142d7  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 005142dd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005142df  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 005142e9  e80262fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 005142ee  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 005142f3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005142f7  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 005142fa  e831cbfcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 005142ff  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00514304  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00514308  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0051430b  e820cbfcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00514310  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 00514315  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514316  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514317  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514318  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_514320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00514323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514324  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514325  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00514327  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051432a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051432f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00514331  7465                   -je 0x514398
    if (cpu.flags.zf)
    {
        goto L_0x00514398;
    }
    // 00514333  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 00514337  7509                   -jne 0x514342
    if (!cpu.flags.zf)
    {
        goto L_0x00514342;
    }
    // 00514339  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514340  7409                   -je 0x51434b
    if (cpu.flags.zf)
    {
        goto L_0x0051434b;
    }
L_0x00514342:
    // 00514342  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00514344  e8470cfeff             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
    // 00514349  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0051434b:
    // 0051434b  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00514351  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 0051435b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051435d  741b                   -je 0x51437a
    if (cpu.flags.zf)
    {
        goto L_0x0051437a;
    }
L_0x0051435f:
    // 0051435f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514361  e8cab5fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00514366  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514368  7436                   -je 0x5143a0
    if (cpu.flags.zf)
    {
        goto L_0x005143a0;
    }
    // 0051436a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051436c  e8bf32fdff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x00514371:
    // 00514371  83baa800000000         +cmp dword ptr [edx + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514378  75e5                   -jne 0x51435f
    if (!cpu.flags.zf)
    {
        goto L_0x0051435f;
    }
L_0x0051437a:
    // 0051437a  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051437d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051437f  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00514386  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514389  8b1de4895600           -mov ebx, dword ptr [0x5689e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671396) /* 0x5689e4 */);
    // 0051438f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00514390  891de4895600           -mov dword ptr [0x5689e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5671396) /* 0x5689e4 */) = cpu.ebx;
    // 00514396  740f                   -je 0x5143a7
    if (cpu.flags.zf)
    {
        goto L_0x005143a7;
    }
L_0x00514398:
    // 00514398  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051439a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051439b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051439c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051439d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051439e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051439f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005143a0:
    // 005143a0  e83bb5fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 005143a5  ebca                   -jmp 0x514371
    goto L_0x00514371;
L_0x005143a7:
    // 005143a7  b860425100             -mov eax, 0x514260
    cpu.eax = 5325408 /*0x514260*/;
    // 005143ac  e8ffe5fdff             -call 0x4f29b0
    cpu.esp -= 4;
    sub_4f29b0(app, cpu);
    if (cpu.terminate) return;
    // 005143b1  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005143b4  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005143b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005143b9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005143bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005143bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005143bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005143be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005143bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005143c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_5143d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005143d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005143d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005143d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005143d3  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 005143d9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005143db  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 005143e2  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 005143e9  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 005143ee  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 005143f0  bed02d5100             -mov esi, 0x512dd0
    cpu.esi = 5320144 /*0x512dd0*/;
    // 005143f5  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 005143f9  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005143fe  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514400  e85bebffff             -call 0x512f60
    cpu.esp -= 4;
    sub_512f60(app, cpu);
    if (cpu.terminate) return;
    // 00514405  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0051440c  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00514410  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00514412  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00514416  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0051441d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00514420  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00514424  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00514426  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00514429  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051442b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00514430  e88bebffff             -call 0x512fc0
    cpu.esp -= 4;
    sub_512fc0(app, cpu);
    if (cpu.terminate) return;
    // 00514435  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00514437:
    // 00514437  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051443a  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0051443e  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00514441  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514444  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00514446:
    // 00514446  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00514448  e8e3b4fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051444d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051444f  751c                   -jne 0x51446d
    if (!cpu.flags.zf)
    {
        goto L_0x0051446d;
    }
    // 00514451  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00514453  e888b4fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x00514458:
    // 00514458  e873ebffff             -call 0x512fd0
    cpu.esp -= 4;
    sub_512fd0(app, cpu);
    if (cpu.terminate) return;
    // 0051445d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051445f  7517                   -jne 0x514478
    if (!cpu.flags.zf)
    {
        goto L_0x00514478;
    }
    // 00514461  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514465  7411                   -je 0x514478
    if (cpu.flags.zf)
    {
        goto L_0x00514478;
    }
    // 00514467  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00514469  74cc                   -je 0x514437
    if (cpu.flags.zf)
    {
        goto L_0x00514437;
    }
    // 0051446b  ebd9                   -jmp 0x514446
    goto L_0x00514446;
L_0x0051446d:
    // 0051446d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051446f  e8ac32fdff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 00514474  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514476  7de0                   -jge 0x514458
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00514458;
    }
L_0x00514478:
    // 00514478  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051447a  7513                   -jne 0x51448f
    if (!cpu.flags.zf)
    {
        goto L_0x0051448f;
    }
    // 0051447c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051447e  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00514485  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0051448b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051448c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051448d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051448e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051448f:
    // 0051448f  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00514492  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00514495  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514498  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051449a  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 005144a1  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 005144a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005144a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005144a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005144aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_5144b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005144b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005144b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005144b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005144b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005144b4  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 005144ba  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005144bc  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 005144c3  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 005144ca  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 005144cf  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 005144d6  be202e5100             -mov esi, 0x512e20
    cpu.esi = 5320224 /*0x512e20*/;
    // 005144db  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005144dd  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005144e4  0f857e000000           -jne 0x514568
    if (!cpu.flags.zf)
    {
        goto L_0x00514568;
    }
L_0x005144ea:
    // 005144ea  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 005144ef  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005144f3  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 005144f6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005144f8  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005144fc  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00514503  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514504  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514505  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514506  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514507  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514508  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0051450f  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514512  8b8c24fc000000         -mov ecx, dword ptr [esp + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00514519  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051451a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051451b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051451c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051451d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051451e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00514520  7476                   -je 0x514598
    if (cpu.flags.zf)
    {
        goto L_0x00514598;
    }
    // 00514522  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00514527  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051452b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051452d  e8fec8fcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
L_0x00514532:
    // 00514532  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514537  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00514539  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051453a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051453e  bb646461ea             -mov ebx, 0xea616464
    cpu.ebx = 3932251236 /*0xea616464*/;
    // 00514543  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 00514548  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0051454f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514551  e83aecffff             -call 0x513190
    cpu.esp -= 4;
    sub_513190(app, cpu);
    if (cpu.terminate) return;
    // 00514556  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
L_0x0051455d:
    // 0051455d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00514563  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514564  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514565  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514566  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514567  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514568:
    // 00514568  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0051456f  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00514572  e8c90afeff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00514577  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514579  7407                   -je 0x514582
    if (cpu.flags.zf)
    {
        goto L_0x00514582;
    }
    // 0051457b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514580  ebdb                   -jmp 0x51455d
    goto L_0x0051455d;
L_0x00514582:
    // 00514582  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514584  e8070afeff             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
    // 00514589  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 00514593  e952ffffff             -jmp 0x5144ea
    goto L_0x005144ea;
L_0x00514598:
    // 00514598  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051459b  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0051459f  eb91                   -jmp 0x514532
    goto L_0x00514532;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_5145b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005145b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005145b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005145b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005145b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005145b4  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 005145ba  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 005145bc  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 005145c1  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 005145c8  be702e5100             -mov esi, 0x512e70
    cpu.esi = 5320304 /*0x512e70*/;
    // 005145cd  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005145cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005145d1  7554                   -jne 0x514627
    if (!cpu.flags.zf)
    {
        goto L_0x00514627;
    }
    // 005145d3  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005145da  744b                   -je 0x514627
    if (cpu.flags.zf)
    {
        goto L_0x00514627;
    }
L_0x005145dc:
    // 005145dc  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 005145e2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005145e4  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 005145e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005145e7  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 005145ec  8db424cc000000         -lea esi, [esp + 0xcc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 005145f3  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 005145f8  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 005145ff  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00514601  e88aebffff             -call 0x513190
    cpu.esp -= 4;
    sub_513190(app, cpu);
    if (cpu.terminate) return;
    // 00514606  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0051460b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051460d  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514615  7429                   -je 0x514640
    if (cpu.flags.zf)
    {
        goto L_0x00514640;
    }
    // 00514617  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051461c  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 00514622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514625  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514626  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514627:
    // 00514627  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00514629  7415                   -je 0x514640
    if (cpu.flags.zf)
    {
        goto L_0x00514640;
    }
    // 0051462b  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514632  750c                   -jne 0x514640
    if (!cpu.flags.zf)
    {
        goto L_0x00514640;
    }
    // 00514634  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00514636  8d781c                 -lea edi, [eax + 0x1c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00514639  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051463a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051463b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051463c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051463d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051463e  eb9c                   -jmp 0x5145dc
    goto L_0x005145dc;
L_0x00514640:
    // 00514640  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514642  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 00514648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051464a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051464b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051464c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_514650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514651  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514652  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514653  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00514656  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00514658  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051465a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0051465e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00514661  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00514663  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00514666  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051466a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051466c  0f846f010000           -je 0x5147e1
    if (cpu.flags.zf)
    {
        goto L_0x005147e1;
    }
L_0x00514672:
    // 00514672  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514679  7411                   -je 0x51468c
    if (cpu.flags.zf)
    {
        goto L_0x0051468c;
    }
    // 0051467b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051467d  e80e09feff             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
    // 00514682  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x0051468c:
    // 0051468c  837e3002               +cmp dword ptr [esi + 0x30], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514690  732d                   -jae 0x5146bf
    if (!cpu.flags.cf)
    {
        goto L_0x005146bf;
    }
    // 00514692  b8dc035500             -mov eax, 0x5503dc
    cpu.eax = 5571548 /*0x5503dc*/;
    // 00514697  baec035500             -mov edx, 0x5503ec
    cpu.edx = 5571564 /*0x5503ec*/;
    // 0051469c  b9c5020000             -mov ecx, 0x2c5
    cpu.ecx = 709 /*0x2c5*/;
    // 005146a1  68f8035500             -push 0x5503f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571576 /*0x5503f8*/;
    cpu.esp -= 4;
    // 005146a6  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005146ab  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005146b1  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 005146b7  e854c9eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005146bc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005146bf:
    // 005146bf  837e3020               +cmp dword ptr [esi + 0x30], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005146c3  762f                   -jbe 0x5146f4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005146f4;
    }
    // 005146c5  bfdc035500             -mov edi, 0x5503dc
    cpu.edi = 5571548 /*0x5503dc*/;
    // 005146ca  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 005146cc  b8ec035500             -mov eax, 0x5503ec
    cpu.eax = 5571564 /*0x5503ec*/;
    // 005146d1  bac7020000             -mov edx, 0x2c7
    cpu.edx = 711 /*0x2c7*/;
    // 005146d6  682c045500             -push 0x55042c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571628 /*0x55042c*/;
    cpu.esp -= 4;
    // 005146db  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 005146e1  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 005146e6  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 005146ec  e81fc9eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005146f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x005146f4:
    // 005146f4  8b5630                 -mov edx, dword ptr [esi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 005146f7  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005146fa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00514701  b9dc035500             -mov ecx, 0x5503dc
    cpu.ecx = 5571548 /*0x5503dc*/;
    // 00514706  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00514708  bbec035500             -mov ebx, 0x5503ec
    cpu.ebx = 5571564 /*0x5503ec*/;
    // 0051470d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00514710  bfcb020000             -mov edi, 0x2cb
    cpu.edi = 715 /*0x2cb*/;
    // 00514715  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00514717  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0051471d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00514720  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00514726  8d90ec000000           -lea edx, [eax + 0xec]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(236) /* 0xec */);
    // 0051472c  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00514732  b858045500             -mov eax, 0x550458
    cpu.eax = 5571672 /*0x550458*/;
    // 00514737  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0051473d  e8decefcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00514742  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00514745  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514747  0f8489000000           -je 0x5147d6
    if (cpu.flags.zf)
    {
        goto L_0x005147d6;
    }
    // 0051474d  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00514750  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514753  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00514758  8d7f54                 -lea edi, [edi + 0x54]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 0051475b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051475d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514760  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00514767  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051476a  c7405000000000         -mov dword ptr [eax + 0x50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 00514771  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514774  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00514777  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0051477a  a1d46d5600             -mov eax, dword ptr [0x566dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 0051477f  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514782  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00514788  a1d86d5600             -mov eax, dword ptr [0x566dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664216) /* 0x566dd8 */);
    // 0051478d  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00514790  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00514796  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051479a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051479b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051479c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051479d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051479e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051479f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005147a1  754a                   -jne 0x5147ed
    if (!cpu.flags.zf)
    {
        goto L_0x005147ed;
    }
    // 005147a3  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005147a6  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
L_0x005147aa:
    // 005147aa  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005147ad  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 005147b3  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005147b6  e8a5e7ffff             -call 0x512f60
    cpu.esp -= 4;
    sub_512f60(app, cpu);
    if (cpu.terminate) return;
    // 005147bb  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005147be  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005147c1  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005147c4  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005147c7  ff5328                 -call dword ptr [ebx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005147ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005147cc  7431                   -je 0x5147ff
    if (cpu.flags.zf)
    {
        goto L_0x005147ff;
    }
    // 005147ce  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x005147d6:
    // 005147d6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005147da  83c40c                 +add esp, 0xc
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
    // 005147dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005147de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005147df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005147e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005147e1:
    // 005147e1  c7463020000000         -mov dword ptr [esi + 0x30], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 32 /*0x20*/;
    // 005147e8  e985feffff             -jmp 0x514672
    goto L_0x00514672;
L_0x005147ed:
    // 005147ed  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005147f0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 005147f5  83c03c                 +add eax, 0x3c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005147f8  e833c6fcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 005147fd  ebab                   -jmp 0x5147aa
    goto L_0x005147aa;
L_0x005147ff:
    // 005147ff  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514802  e889d0fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00514807  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0051480e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00514812  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00514815  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514816  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514817  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514818  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_514820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514821  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00514824  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00514826  7504                   -jne 0x51482c
    if (!cpu.flags.zf)
    {
        goto L_0x0051482c;
    }
    // 00514828  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051482a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051482b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051482c:
    // 0051482c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051482d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051482e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00514830  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00514835  8d7e54                 -lea edi, [esi + 0x54]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00514838  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051483a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051483f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514841  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514842  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514843  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514844  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_514850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514852  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00514854  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00514856  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00514859  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051485b  7442                   -je 0x51489f
    if (cpu.flags.zf)
    {
        goto L_0x0051489f;
    }
    // 0051485d  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514861  741b                   -je 0x51487e
    if (cpu.flags.zf)
    {
        goto L_0x0051487e;
    }
L_0x00514863:
    // 00514863  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00514865  740f                   -je 0x514876
    if (cpu.flags.zf)
    {
        goto L_0x00514876;
    }
    // 00514867  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0051486a  e821d0fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051486f  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00514876:
    // 00514876  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051487b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051487c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051487d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051487e:
    // 0051487e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051487f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00514882  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514885  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00514888  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051488b  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0051488e  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00514892  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00514895  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0051489c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051489d  ebc4                   -jmp 0x514863
    goto L_0x00514863;
L_0x0051489f:
    // 0051489f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005148a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5148b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005148b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005148b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005148b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005148b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005148b4  8b3dd46d5600           -mov edi, dword ptr [0x566dd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 005148ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005148bc  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005148bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005148c1  7409                   -je 0x5148cc
    if (cpu.flags.zf)
    {
        goto L_0x005148cc;
    }
    // 005148c3  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005148c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005148c8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005148ca  7513                   -jne 0x5148df
    if (!cpu.flags.zf)
    {
        goto L_0x005148df;
    }
L_0x005148cc:
    // 005148cc  8b3dd46d5600           -mov edi, dword ptr [0x566dd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 005148d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005148d4  893dd46d5600           -mov dword ptr [0x566dd4], edi
    app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */) = cpu.edi;
    // 005148da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005148de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005148df:
    // 005148df  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005148e6  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005148e9  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 005148ef  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005148f2  e869e6ffff             -call 0x512f60
    cpu.esp -= 4;
    sub_512f60(app, cpu);
    if (cpu.terminate) return;
    // 005148f7  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 005148fa  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005148fd  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00514900  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00514903  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514906  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514908  7441                   -je 0x51494b
    if (cpu.flags.zf)
    {
        goto L_0x0051494b;
    }
    // 0051490a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051490b  8b3dd46d5600           -mov edi, dword ptr [0x566dd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 00514911  c786a000000001000000   -mov dword ptr [esi + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 0051491b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051491d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051491f:
    // 0051491f  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00514922  8b9984000000           -mov ebx, dword ptr [ecx + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00514928  4b                     -dec ebx
    (cpu.ebx)--;
    // 00514929  39da                   +cmp edx, ebx
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
    // 0051492b  730d                   -jae 0x51493a
    if (!cpu.flags.cf)
    {
        goto L_0x0051493a;
    }
    // 0051492d  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514930  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00514931  89bc0180000000         -mov dword ptr [ecx + eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 1) = cpu.edi;
    // 00514938  ebe5                   -jmp 0x51491f
    goto L_0x0051491f;
L_0x0051493a:
    // 0051493a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051493f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514940  893dd46d5600           -mov dword ptr [0x566dd4], edi
    app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */) = cpu.edi;
    // 00514946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514948  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514949  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051494a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051494b:
    // 0051494b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0051494e  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00514955  8b3dd46d5600           -mov edi, dword ptr [0x566dd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */);
    // 0051495b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051495d  893dd46d5600           -mov dword ptr [0x566dd4], edi
    app->getMemory<x86::reg32>(x86::reg32(5664212) /* 0x566dd4 */) = cpu.edi;
    // 00514963  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514964  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514965  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514967  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_514970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514971  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00514977  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00514979  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514980  0f8420010000           -je 0x514aa6
    if (cpu.flags.zf)
    {
        goto L_0x00514aa6;
    }
    // 00514986  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514987  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514988  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00514989  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051498a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051498b  a1dc895600             -mov eax, dword ptr [0x5689dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671388) /* 0x5689dc */);
    // 00514990  b9657962ea             -mov ecx, 0xea627965
    cpu.ecx = 3932322149 /*0xea627965*/;
    // 00514995  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00514999  898c24c0000000         -mov dword ptr [esp + 0xc0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.ecx;
    // 005149a0  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005149a4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005149a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005149a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005149a9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005149aa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005149ab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005149ac  40                     -inc eax
    (cpu.eax)++;
    // 005149ad  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005149b0  a3dc895600             -mov dword ptr [0x5689dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5671388) /* 0x5689dc */) = cpu.eax;
    // 005149b5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005149b7  0f84f6000000           -je 0x514ab3
    if (cpu.flags.zf)
    {
        goto L_0x00514ab3;
    }
    // 005149bd  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005149c0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005149c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005149c4  0f85b4000000           -jne 0x514a7e
    if (!cpu.flags.zf)
    {
        goto L_0x00514a7e;
    }
    // 005149ca  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005149cd  8d530c                 -lea edx, [ebx + 0xc]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 005149d0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005149d3  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005149d6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005149d9  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 005149dd  833de06d560002         +cmp dword ptr [0x566de0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005149e4  7d53                   -jge 0x514a39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00514a39;
    }
L_0x005149e6:
    // 005149e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005149e8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005149ea  899424c4000000         -mov dword ptr [esp + 0xc4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.edx;
L_0x005149f1:
    // 005149f1  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005149f4  83785000               +cmp dword ptr [eax + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005149f8  0f8480000000           -je 0x514a7e
    if (cpu.flags.zf)
    {
        goto L_0x00514a7e;
    }
    // 005149fe  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00514a04  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514a0b  4a                     -dec edx
    (cpu.edx)--;
    // 00514a0c  39da                   +cmp edx, ebx
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
    // 00514a0e  766e                   -jbe 0x514a7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00514a7e;
    }
    // 00514a10  8a8c24c4000000         -mov cl, byte ptr [esp + 0xc4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514a17  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00514a1c  8b7850                 -mov edi, dword ptr [eax + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00514a1f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00514a21  85fa                   +test edx, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edi));
    // 00514a23  752d                   -jne 0x514a52
    if (!cpu.flags.zf)
    {
        goto L_0x00514a52;
    }
L_0x00514a25:
    // 00514a25  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514a2c  43                     -inc ebx
    (cpu.ebx)++;
    // 00514a2d  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514a30  899c24c4000000         -mov dword ptr [esp + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00514a37  ebb8                   -jmp 0x5149f1
    goto L_0x005149f1;
L_0x00514a39:
    // 00514a39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514a3a  8d9424c4000000         -lea edx, [esp + 0xc4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514a41  b860045500             -mov eax, 0x550460
    cpu.eax = 5571680 /*0x550460*/;
    // 00514a46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514a47  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514a49  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00514a4b  e830d7ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 00514a50  eb94                   -jmp 0x5149e6
    goto L_0x005149e6;
L_0x00514a52:
    // 00514a52  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00514a54  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00514a56  21d1                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00514a58  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00514a5b  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00514a5d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514a60  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00514a64  0588000000             +add eax, 0x88
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514a69  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00514a6c  8d1430                 -lea edx, [eax + esi]
    cpu.edx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00514a6f  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514a76  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00514a79  ff5754                 -call dword ptr [edi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514a7c  eba7                   -jmp 0x514a25
    goto L_0x00514a25;
L_0x00514a7e:
    // 00514a7e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514a81  e80acefcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00514a86  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00514a8d:
    // 00514a8d  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 00514a97  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 00514aa1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514aa3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514aa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514aa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00514aa6:
    // 00514aa6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514aab  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00514ab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514ab2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514ab3:
    // 00514ab3  833de06d560002         +cmp dword ptr [0x566de0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514aba  7c15                   -jl 0x514ad1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00514ad1;
    }
    // 00514abc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514abd  8d9424c4000000         -lea edx, [esp + 0xc4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514ac4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514ac5  b86c045500             -mov eax, 0x55046c
    cpu.eax = 5571692 /*0x55046c*/;
    // 00514aca  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00514acc  e8afd6ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00514ad1:
    // 00514ad1  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00514ad3  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00514ad7  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00514ade  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00514ae1  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514ae4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00514ae7  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514aea  eba1                   -jmp 0x514a8d
    goto L_0x00514a8d;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_514af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514af0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514af1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514af2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514af3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514af4  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00514afa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00514afc  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 00514b03  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514b05  898c2404010000         -mov dword ptr [esp + 0x104], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.ecx;
    // 00514b0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00514b0e  0f85a2000000           -jne 0x514bb6
    if (!cpu.flags.zf)
    {
        goto L_0x00514bb6;
    }
    // 00514b14  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514b1b  0f8495000000           -je 0x514bb6
    if (cpu.flags.zf)
    {
        goto L_0x00514bb6;
    }
    // 00514b21  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x00514b24:
    // 00514b24  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00514b28  0f84d8000000           -je 0x514c06
    if (cpu.flags.zf)
    {
        goto L_0x00514c06;
    }
    // 00514b2e  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514b31  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00514b33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00514b35  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514b37  e80405feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00514b3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514b3e  0f84c2000000           -je 0x514c06
    if (cpu.flags.zf)
    {
        goto L_0x00514c06;
    }
    // 00514b44  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00514b49  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00514b4c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00514b4e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514b50  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514b57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514b59  0f843e020000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514b5f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00514b64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514b66  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00514b68  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00514b6f  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
L_0x00514b76:
    // 00514b76  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00514b79  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00514b7f  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00514b86  4a                     -dec edx
    (cpu.edx)--;
    // 00514b87  39fa                   +cmp edx, edi
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
    // 00514b89  0f860e020000           -jbe 0x514d9d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514b8f  8a8c2408010000         -mov cl, byte ptr [esp + 0x108]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00514b96  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00514b9b  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00514b9d  855050                 -test dword ptr [eax + 0x50], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) & cpu.edx));
    // 00514ba0  753d                   -jne 0x514bdf
    if (!cpu.flags.zf)
    {
        goto L_0x00514bdf;
    }
L_0x00514ba2:
    // 00514ba2  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00514ba9  47                     -inc edi
    (cpu.edi)++;
    // 00514baa  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00514bad  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 00514bb4  ebc0                   -jmp 0x514b76
    goto L_0x00514b76;
L_0x00514bb6:
    // 00514bb6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00514bb8  7418                   -je 0x514bd2
    if (cpu.flags.zf)
    {
        goto L_0x00514bd2;
    }
    // 00514bba  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514bc1  750f                   -jne 0x514bd2
    if (!cpu.flags.zf)
    {
        goto L_0x00514bd2;
    }
    // 00514bc3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00514bc5  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514bc8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514bc9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514bca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514bcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514bcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514bcd  e952ffffff             -jmp 0x514b24
    goto L_0x00514b24;
L_0x00514bd2:
    // 00514bd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514bd4  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00514bda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514bdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514bdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514bdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514bde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514bdf:
    // 00514bdf  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00514be4  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00514be7  8d1430                 -lea edx, [eax + esi]
    cpu.edx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00514bea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514bec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514bee  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514bf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514bf7  0f84a0010000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514bfd  ff842404010000         +inc dword ptr [esp + 0x104]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00514c04  eb9c                   -jmp 0x514ba2
    goto L_0x00514ba2;
L_0x00514c06:
    // 00514c06  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00514c0b  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00514c12  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 00514c17  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514c1c  bec02e5100             -mov esi, 0x512ec0
    cpu.esi = 5320384 /*0x512ec0*/;
    // 00514c21  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00514c23  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00514c2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00514c2b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514c2d  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 00514c32  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00514c36  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514c38  e853e5ffff             -call 0x513190
    cpu.esp -= 4;
    sub_513190(app, cpu);
    if (cpu.terminate) return;
    // 00514c3d  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514c45  0f8452010000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514c4b  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00514c52  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00514c57  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 00514c5e  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00514c65  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00514c69  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00514c70  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00514c75  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 00514c7c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00514c7e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00514c82  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514c87  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00514c89  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00514c8b  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 00514c90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00514c91  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00514c98  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00514c9b  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00514c9d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514c9f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514ca0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514ca1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514ca2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514ca3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514ca4  e8e7e4ffff             -call 0x513190
    cpu.esp -= 4;
    sub_513190(app, cpu);
    if (cpu.terminate) return;
    // 00514ca9  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514cb1  0f84f8000000           -je 0x514daf
    if (cpu.flags.zf)
    {
        goto L_0x00514daf;
    }
    // 00514cb7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00514cbc:
    // 00514cbc  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00514cc3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00514cc5  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00514ccc  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
    // 00514cd3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00514cd5  0f84c2000000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
L_0x00514cdb:
    // 00514cdb  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00514ce2  83fb1f                 +cmp ebx, 0x1f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514ce5  0f8db2000000           -jge 0x514d9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00514d9d;
    }
    // 00514ceb  83bc24c400000000       +cmp dword ptr [esp + 0xc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514cf3  0f84a4000000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514cf9  83bc240401000000       +cmp dword ptr [esp + 0x104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514d01  0f8496000000           -je 0x514d9d
    if (cpu.flags.zf)
    {
        goto L_0x00514d9d;
    }
    // 00514d07  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00514d0e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514d13  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00514d1a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00514d1c  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00514d1e  745f                   -je 0x514d7f
    if (cpu.flags.zf)
    {
        goto L_0x00514d7f;
    }
    // 00514d20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00514d22  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00514d24  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00514d28  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514d2d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00514d2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00514d30  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00514d34  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00514d3b  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00514d3d  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 00514d42  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00514d44  e847e4ffff             -call 0x513190
    cpu.esp -= 4;
    sub_513190(app, cpu);
    if (cpu.terminate) return;
    // 00514d49  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514d51  7463                   -je 0x514db6
    if (cpu.flags.zf)
    {
        goto L_0x00514db6;
    }
    // 00514d53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00514d58:
    // 00514d58  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00514d5f  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00514d66  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00514d6b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00514d6d  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00514d74  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00514d76  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00514d78  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
L_0x00514d7f:
    // 00514d7f  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00514d86  42                     -inc edx
    (cpu.edx)++;
    // 00514d87  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00514d8e  8994240c010000         -mov dword ptr [esp + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 00514d95  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00514d97  0f853effffff           -jne 0x514cdb
    if (!cpu.flags.zf)
    {
        goto L_0x00514cdb;
    }
L_0x00514d9d:
    // 00514d9d  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00514da4  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00514daa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514daf:
    // 00514daf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00514db1  e906ffffff             -jmp 0x514cbc
    goto L_0x00514cbc;
L_0x00514db6:
    // 00514db6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00514db8  eb9e                   -jmp 0x514d58
    goto L_0x00514d58;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_514dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514dc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514dc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514dc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514dc5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514dc8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00514dca  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00514dcc  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00514dcf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00514dd1  0f84a5000000           -je 0x514e7c
    if (cpu.flags.zf)
    {
        goto L_0x00514e7c;
    }
    // 00514dd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00514dd9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00514ddb  e8c0e4ffff             -call 0x5132a0
    cpu.esp -= 4;
    sub_5132a0(app, cpu);
    if (cpu.terminate) return;
    // 00514de0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00514de2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514de4  751b                   -jne 0x514e01
    if (!cpu.flags.zf)
    {
        goto L_0x00514e01;
    }
    // 00514de6  8d5e30                 -lea ebx, [esi + 0x30]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00514de9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00514deb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00514ded  e84e02feff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 00514df2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00514df4  754e                   -jne 0x514e44
    if (!cpu.flags.zf)
    {
        goto L_0x00514e44;
    }
L_0x00514df6:
    // 00514df6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514df8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514dfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514dff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514e01:
    // 00514e01  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00514e04  81c288000000           -add edx, 0x88
    (cpu.edx) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00514e0a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00514e0c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00514e0e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00514e13  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00514e16  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00514e18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00514e1a  bb74756fea             -mov ebx, 0xea6f7574
    cpu.ebx = 3933173108 /*0xea6f7574*/;
    // 00514e1f  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00514e22  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00514e26  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00514e28  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00514e2a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00514e2d  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00514e30  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00514e33  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00514e38  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00514e3a  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00514e3d  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00514e3f  215050                 +and dword ptr [eax + 0x50], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00514e42  ebb2                   -jmp 0x514df6
    goto L_0x00514df6;
L_0x00514e44:
    // 00514e44  bfdc035500             -mov edi, 0x5503dc
    cpu.edi = 5571548 /*0x5503dc*/;
    // 00514e49  bd78045500             -mov ebp, 0x550478
    cpu.ebp = 5571704 /*0x550478*/;
    // 00514e4e  b89b030000             -mov eax, 0x39b
    cpu.eax = 923 /*0x39b*/;
    // 00514e53  6888045500             -push 0x550488
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571720 /*0x550488*/;
    cpu.esp -= 4;
    // 00514e58  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00514e5e  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00514e64  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00514e69  e8a2c1eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00514e6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514e71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514e73  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514e76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514e7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514e7c:
    // 00514e7c  b9dc035500             -mov ecx, 0x5503dc
    cpu.ecx = 5571548 /*0x5503dc*/;
    // 00514e81  bb78045500             -mov ebx, 0x550478
    cpu.ebx = 5571704 /*0x550478*/;
    // 00514e86  be9f030000             -mov esi, 0x39f
    cpu.esi = 927 /*0x39f*/;
    // 00514e8b  68b8045500             -push 0x5504b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571768 /*0x5504b8*/;
    cpu.esp -= 4;
    // 00514e90  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00514e96  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00514e9c  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00514ea2  e869c1eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00514ea7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514eaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00514eac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514eaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514eb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514eb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514eb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514eb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514eb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_514ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514ec0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514ec1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514ec2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514ec3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00514ec6  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514ecc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00514ece  83f9ff                 +cmp ecx, -1
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
    // 00514ed1  0f8588000000           -jne 0x514f5f
    if (!cpu.flags.zf)
    {
        goto L_0x00514f5f;
    }
    // 00514ed7  bd10ac5600             -mov ebp, 0x56ac10
    cpu.ebp = 5680144 /*0x56ac10*/;
L_0x00514edc:
    // 00514edc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00514ede  745b                   -je 0x514f3b
    if (cpu.flags.zf)
    {
        goto L_0x00514f3b;
    }
    // 00514ee0  66837e2a00             +cmp word ptr [esi + 0x2a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00514ee5  7515                   -jne 0x514efc
    if (!cpu.flags.zf)
    {
        goto L_0x00514efc;
    }
    // 00514ee7  c704241e000000         -mov dword ptr [esp], 0x1e
    app->getMemory<x86::reg32>(cpu.esp) = 30 /*0x1e*/;
    // 00514eee  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00514ef0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00514ef2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00514ef5  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00514ef8  6689462a               -mov word ptr [esi + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = cpu.ax;
L_0x00514efc:
    // 00514efc  66837e2c00             +cmp word ptr [esi + 0x2c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00514f01  7516                   -jne 0x514f19
    if (!cpu.flags.zf)
    {
        goto L_0x00514f19;
    }
    // 00514f03  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00514f08  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00514f0a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00514f0d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00514f10  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00514f12  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00514f15  6689462c               -mov word ptr [esi + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ax;
L_0x00514f19:
    // 00514f19  66837e2e00             +cmp word ptr [esi + 0x2e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00514f1e  7515                   -jne 0x514f35
    if (!cpu.flags.zf)
    {
        goto L_0x00514f35;
    }
    // 00514f20  c704240f000000         -mov dword ptr [esp], 0xf
    app->getMemory<x86::reg32>(cpu.esp) = 15 /*0xf*/;
    // 00514f27  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00514f29  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00514f2b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00514f2e  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00514f31  6689462e               -mov word ptr [esi + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = cpu.ax;
L_0x00514f35:
    // 00514f35  66c746280000           -mov word ptr [esi + 0x28], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00514f3b:
    // 00514f3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00514f3c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00514f3e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00514f40  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00514f42  bb046e5600             -mov ebx, 0x566e04
    cpu.ebx = 5664260 /*0x566e04*/;
    // 00514f47  893dd8435600           -mov dword ptr [0x5643d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */) = cpu.edi;
    // 00514f4d  e8de01feff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 00514f52  8b3dd8435600           -mov edi, dword ptr [0x5643d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 00514f58  83c404                 +add esp, 4
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
    // 00514f5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514f5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514f5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00514f5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00514f5f:
    // 00514f5f  bd28ac5600             -mov ebp, 0x56ac28
    cpu.ebp = 5680168 /*0x56ac28*/;
    // 00514f64  e973ffffff             -jmp 0x514edc
    goto L_0x00514edc;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_514f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00514f70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00514f71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00514f72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00514f73  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00514f76  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00514f78  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00514f7c  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00514f80  894c2458               -mov dword ptr [esp + 0x58], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.ecx;
    // 00514f84  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00514f89  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00514f8b  be102f5100             -mov esi, 0x512f10
    cpu.esi = 5320464 /*0x512f10*/;
    // 00514f90  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00514f92  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00514f96  83781800               +cmp dword ptr [eax + 0x18], 0
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
    // 00514f9a  0f8492000000           -je 0x515032
    if (cpu.flags.zf)
    {
        goto L_0x00515032;
    }
L_0x00514fa0:
    // 00514fa0  833de06d560005         +cmp dword ptr [0x566de0], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514fa7  7c1a                   -jl 0x514fc3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00514fc3;
    }
    // 00514fa9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00514fab  8b4c2470               -mov ecx, dword ptr [esp + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00514faf  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00514fb3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00514fb5  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00514fb9  b8f8045500             -mov eax, 0x5504f8
    cpu.eax = 5571832 /*0x5504f8*/;
    // 00514fbe  e8bdd1ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x00514fc3:
    // 00514fc3  8b5c246c               -mov ebx, dword ptr [esp + 0x6c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00514fc7  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00514fcb  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00514fcf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00514fd0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00514fd3  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00514fd7  e8c4e3ffff             -call 0x5133a0
    cpu.esp -= 4;
    sub_5133a0(app, cpu);
    if (cpu.terminate) return;
    // 00514fdc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00514fde  3b4518                 +cmp eax, dword ptr [ebp + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514fe1  7507                   -jne 0x514fea
    if (!cpu.flags.zf)
    {
        goto L_0x00514fea;
    }
    // 00514fe3  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00514fea:
    // 00514fea  83bda800000000         +cmp dword ptr [ebp + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00514ff1  7512                   -jne 0x515005
    if (!cpu.flags.zf)
    {
        goto L_0x00515005;
    }
    // 00514ff3  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 00514ff8  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00514ffb  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00514ffe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00515000  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515002  ff565c                 -call dword ptr [esi + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00515005:
    // 00515005  817c2450216f6eea       +cmp dword ptr [esp + 0x50], 0xea6e6f21
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933105953 /*0xea6e6f21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051500d  742d                   -je 0x51503c
    if (cpu.flags.zf)
    {
        goto L_0x0051503c;
    }
    // 0051500f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00515014:
    // 00515014  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00515018  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051501a  817c2450746164ea       +cmp dword ptr [esp + 0x50], 0xea646174
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932447092 /*0xea646174*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515022  751c                   -jne 0x515040
    if (!cpu.flags.zf)
    {
        goto L_0x00515040;
    }
    // 00515024  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00515029  83c45c                 +add esp, 0x5c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051502c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051502d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051502e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051502f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00515032:
    // 00515032  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00515034  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00515037  e964ffffff             -jmp 0x514fa0
    goto L_0x00514fa0;
L_0x0051503c:
    // 0051503c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051503e  ebd4                   -jmp 0x515014
    goto L_0x00515014;
L_0x00515040:
    // 00515040  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00515042  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00515045  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515046  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515047  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515048  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515051  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515052  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515053  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515054  8b15348a5600           -mov edx, dword ptr [0x568a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671476) /* 0x568a34 */);
    // 0051505a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051505c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051505e  740c                   -je 0x51506c
    if (cpu.flags.zf)
    {
        goto L_0x0051506c;
    }
    // 00515060  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00515065  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515068  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515069  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051506a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051506b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051506c:
    // 0051506c  6804055500             -push 0x550504
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571844 /*0x550504*/;
    cpu.esp -= 4;
    // 00515071  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515078  a3348a5600             -mov dword ptr [0x568a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5671476) /* 0x568a34 */) = cpu.eax;
    // 0051507d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051507f  7513                   -jne 0x515094
    if (!cpu.flags.zf)
    {
        goto L_0x00515094;
    }
    // 00515081  891d308a5600           -mov dword ptr [0x568a30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5671472) /* 0x568a30 */) = cpu.ebx;
    // 00515087  891d2c8a5600           -mov dword ptr [0x568a2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */) = cpu.ebx;
    // 0051508d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051508f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515090  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515091  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515092  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515093  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00515094:
    // 00515094  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515095  6814055500             -push 0x550514
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571860 /*0x550514*/;
    cpu.esp -= 4;
    // 0051509a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051509b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005150a2  6828055500             -push 0x550528
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571880 /*0x550528*/;
    cpu.esp -= 4;
    // 005150a7  8b3d348a5600           -mov edi, dword ptr [0x568a34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5671476) /* 0x568a34 */);
    // 005150ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005150ae  a32c8a5600             -mov dword ptr [0x568a2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */) = cpu.eax;
    // 005150b3  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005150ba  8b2d2c8a5600           -mov ebp, dword ptr [0x568a2c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */);
    // 005150c0  a3308a5600             -mov dword ptr [0x568a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5671472) /* 0x568a30 */) = cpu.eax;
    // 005150c5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005150c7  7411                   -je 0x5150da
    if (cpu.flags.zf)
    {
        goto L_0x005150da;
    }
    // 005150c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005150cb  740d                   -je 0x5150da
    if (cpu.flags.zf)
    {
        goto L_0x005150da;
    }
    // 005150cd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005150d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150d3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005150d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005150da:
    // 005150da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005150dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150dd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005150df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005150e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5150f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005150f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005150f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005150f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005150f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005150f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005150f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005150f6  81ec30010000           -sub esp, 0x130
    (cpu.esp) -= x86::reg32(x86::sreg32(304 /*0x130*/));
    // 005150fc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005150fe  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00515101  e84affffff             -call 0x515050
    cpu.esp -= 4;
    sub_515050(app, cpu);
    if (cpu.terminate) return;
    // 00515106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515108  0f8421010000           -je 0x51522f
    if (cpu.flags.zf)
    {
        goto L_0x0051522f;
    }
    // 0051510e  b99c010000             -mov ecx, 0x19c
    cpu.ecx = 412 /*0x19c*/;
    // 00515113  bb40055500             -mov ebx, 0x550540
    cpu.ebx = 5571904 /*0x550540*/;
    // 00515118  be50055500             -mov esi, 0x550550
    cpu.esi = 5571920 /*0x550550*/;
    // 0051511d  bd72000000             -mov ebp, 0x72
    cpu.ebp = 114 /*0x72*/;
    // 00515122  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515124  b868055500             -mov eax, 0x550568
    cpu.eax = 5571944 /*0x550568*/;
    // 00515129  8994242c010000         -mov dword ptr [esp + 0x12c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.edx;
    // 00515130  898c2428010000         -mov dword ptr [esp + 0x128], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.ecx;
    // 00515137  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0051513d  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00515143  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00515149  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051514b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00515151  e8cac4fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00515156  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515158  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051515a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0051515c  833d2c8a560000         +cmp dword ptr [0x568a2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515163  0f8481000000           -je 0x5151ea
    if (cpu.flags.zf)
    {
        goto L_0x005151ea;
    }
    // 00515169  8d84242c010000         -lea eax, [esp + 0x12c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 00515170  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00515171  8d84242c010000         -lea eax, [esp + 0x12c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 00515178  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00515179  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051517a  ff152c8a5600           -call dword ptr [0x568a2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515180  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515182  7466                   -je 0x5151ea
    if (cpu.flags.zf)
    {
        goto L_0x005151ea;
    }
    // 00515184  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515186  ba40055500             -mov edx, 0x550540
    cpu.edx = 5571904 /*0x550540*/;
    // 0051518b  e800c7fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00515190  bb79000000             -mov ebx, 0x79
    cpu.ebx = 121 /*0x79*/;
    // 00515195  b868055500             -mov eax, 0x550568
    cpu.eax = 5571944 /*0x550568*/;
    // 0051519a  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005151a0  8b942428010000         -mov edx, dword ptr [esp + 0x128]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 005151a7  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005151ad  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 005151b3  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 005151b9  e862c4fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 005151be  8d9c242c010000         -lea ebx, [esp + 0x12c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 005151c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005151c6  8d9c242c010000         -lea ebx, [esp + 0x12c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 005151cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005151ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005151cf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005151d1  c7009c010000           -mov dword ptr [eax], 0x19c
    app->getMemory<x86::reg32>(cpu.eax) = 412 /*0x19c*/;
    // 005151d7  ff152c8a5600           -call dword ptr [0x568a2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5671468) /* 0x568a2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005151dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005151df  7409                   -je 0x5151ea
    if (cpu.flags.zf)
    {
        goto L_0x005151ea;
    }
    // 005151e1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005151e3  89b4242c010000         -mov dword ptr [esp + 0x12c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.esi;
L_0x005151ea:
    // 005151ea  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 005151f1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005151f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005151f5  7631                   -jbe 0x515228
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00515228;
    }
    // 005151f7  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x005151f9:
    // 005151f9  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 005151fe  8b15308a5600           -mov edx, dword ptr [0x568a30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671472) /* 0x568a30 */);
    // 00515204  898c2400010000         -mov dword ptr [esp + 0x100], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.ecx;
    // 0051520b  898c2428010000         -mov dword ptr [esp + 0x128], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.ecx;
    // 00515212  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00515214  7539                   -jne 0x51524f
    if (!cpu.flags.zf)
    {
        goto L_0x0051524f;
    }
L_0x00515216:
    // 00515216  8b94242c010000         -mov edx, dword ptr [esp + 0x12c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 0051521d  46                     -inc esi
    (cpu.esi)++;
    // 0051521e  81c39c010000           -add ebx, 0x19c
    (cpu.ebx) += x86::reg32(x86::sreg32(412 /*0x19c*/));
    // 00515224  39d6                   +cmp esi, edx
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
    // 00515226  72d1                   -jb 0x5151f9
    if (cpu.flags.cf)
    {
        goto L_0x005151f9;
    }
L_0x00515228:
    // 00515228  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051522a  e861c6fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0051522f:
    // 0051522f  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00515234  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515238  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00515239  e8a0eb0100             -call 0x533dde
    cpu.esp -= 4;
    sub_533dde(app, cpu);
    if (cpu.terminate) return;
    // 0051523e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515240  7464                   -je 0x5152a6
    if (cpu.flags.zf)
    {
        goto L_0x005152a6;
    }
L_0x00515242:
    // 00515242  81c430010000           -add esp, 0x130
    (cpu.esp) += x86::reg32(x86::sreg32(304 /*0x130*/));
    // 00515248  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515249  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051524a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051524b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051524c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051524d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051524e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051524f:
    // 0051524f  8d842428010000         -lea eax, [esp + 0x128]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00515256  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00515257  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0051525e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051525f  6821800000             -push 0x8021
    app->getMemory<x86::reg32>(cpu.esp-4) = 32801 /*0x8021*/;
    cpu.esp -= 4;
    // 00515264  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00515267  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515268  ff15308a5600           -call dword ptr [0x568a30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5671472) /* 0x568a30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051526e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515270  75a4                   -jne 0x515216
    if (!cpu.flags.zf)
    {
        goto L_0x00515216;
    }
    // 00515272  83bc240401000000       +cmp dword ptr [esp + 0x104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051527a  759a                   -jne 0x515216
    if (!cpu.flags.zf)
    {
        goto L_0x00515216;
    }
    // 0051527c  8db42408010000         -lea esi, [esp + 0x108]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00515283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00515284:
    // 00515284  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00515286  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00515288  3c00                   +cmp al, 0
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
    // 0051528a  7410                   -je 0x51529c
    if (cpu.flags.zf)
    {
        goto L_0x0051529c;
    }
    // 0051528c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051528f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00515292  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00515295  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00515298  3c00                   +cmp al, 0
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
    // 0051529a  75e8                   -jne 0x515284
    if (!cpu.flags.zf)
    {
        goto L_0x00515284;
    }
L_0x0051529c:
    // 0051529c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051529d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051529f  e8ecc5fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 005152a4  eb9c                   -jmp 0x515242
    goto L_0x00515242;
L_0x005152a6:
    // 005152a6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005152a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005152a9  e848eb0100             -call 0x533df6
    cpu.esp -= 4;
    sub_533df6(app, cpu);
    if (cpu.terminate) return;
    // 005152ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005152b0  7490                   -je 0x515242
    if (cpu.flags.zf)
    {
        goto L_0x00515242;
    }
    // 005152b2  6683780802             +cmp word ptr [eax + 8], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005152b7  7589                   -jne 0x515242
    if (!cpu.flags.zf)
    {
        goto L_0x00515242;
    }
    // 005152b9  6683780a04             +cmp word ptr [eax + 0xa], 4
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005152be  7582                   -jne 0x515242
    if (!cpu.flags.zf)
    {
        goto L_0x00515242;
    }
    // 005152c0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005152c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005152c5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005152c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005152c8  e823eb0100             -call 0x533df0
    cpu.esp -= 4;
    sub_533df0(app, cpu);
    if (cpu.terminate) return;
    // 005152cd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005152cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x005152d0:
    // 005152d0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 005152d2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 005152d4  3c00                   +cmp al, 0
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
    // 005152d6  7410                   -je 0x5152e8
    if (cpu.flags.zf)
    {
        goto L_0x005152e8;
    }
    // 005152d8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 005152db  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005152de  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 005152e1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005152e4  3c00                   +cmp al, 0
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
    // 005152e6  75e8                   -jne 0x5152d0
    if (!cpu.flags.zf)
    {
        goto L_0x005152d0;
    }
L_0x005152e8:
    // 005152e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152e9  81c430010000           -add esp, 0x130
    (cpu.esp) += x86::reg32(x86::sreg32(304 /*0x130*/));
    // 005152ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005152f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515302  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515303  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515304  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00515306  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515308  0f849a000000           -je 0x5153a8
    if (cpu.flags.zf)
    {
        goto L_0x005153a8;
    }
    // 0051530e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00515311  39c1                   +cmp ecx, eax
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
    // 00515313  0f828f000000           -jb 0x5153a8
    if (cpu.flags.cf)
    {
        goto L_0x005153a8;
    }
    // 00515319  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051531b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0051531e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00515321  83f910                 +cmp ecx, 0x10
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
    // 00515324  7305                   -jae 0x51532b
    if (!cpu.flags.cf)
    {
        goto L_0x0051532b;
    }
    // 00515326  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x0051532b:
    // 0051532b  39c1                   +cmp ecx, eax
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
    // 0051532d  0f8775000000           -ja 0x5153a8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005153a8;
    }
    // 00515333  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00515336  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00515339  39d9                   +cmp ecx, ebx
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
    // 0051533b  7705                   -ja 0x515342
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00515342;
    }
    // 0051533d  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00515340  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00515342:
    // 00515342  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00515345:
    // 00515345  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00515347  39d1                   +cmp ecx, edx
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
    // 00515349  7612                   -jbe 0x51535d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051535d;
    }
    // 0051534b  39da                   +cmp edx, ebx
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
    // 0051534d  7602                   -jbe 0x515351
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00515351;
    }
    // 0051534f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00515351:
    // 00515351  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00515354  39f0                   +cmp eax, esi
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
    // 00515356  75ed                   -jne 0x515345
    if (!cpu.flags.zf)
    {
        goto L_0x00515345;
    }
    // 00515358  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0051535b  eb4b                   -jmp 0x5153a8
    goto L_0x005153a8;
L_0x0051535d:
    // 0051535d  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00515360  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00515363  43                     -inc ebx
    (cpu.ebx)++;
    // 00515364  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00515366  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00515369  83fa10                 +cmp edx, 0x10
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
    // 0051536c  721e                   -jb 0x51538c
    if (cpu.flags.cf)
    {
        goto L_0x0051538c;
    }
    // 0051536e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00515371  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00515374  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00515376  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00515378  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051537b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0051537e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00515381  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00515384  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00515387  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0051538a  eb12                   -jmp 0x51539e
    goto L_0x0051539e;
L_0x0051538c:
    // 0051538c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 0051538f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00515392  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00515395  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00515398  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0051539b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0051539e:
    // 0051539e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 005153a0  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005153a3  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005153a6  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x005153a8:
    // 005153a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005153aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005153ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005153ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005153ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005153ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5153b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005153b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005153b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005153b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005153b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005153b4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005153b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005153b8  0f841d010000           -je 0x5154db
    if (cpu.flags.zf)
    {
        goto L_0x005154db;
    }
    // 005153be  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 005153c1  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 005153c4  0f8411010000           -je 0x5154db
    if (cpu.flags.zf)
    {
        goto L_0x005154db;
    }
    // 005153ca  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005153cc  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 005153cf  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 005153d2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005153d4  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 005153d7  7522                   -jne 0x5153fb
    if (!cpu.flags.zf)
    {
        goto L_0x005153fb;
    }
    // 005153d9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 005153db  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005153dd  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 005153df  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
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
    // 005153e2  7503                   -jne 0x5153e7
    if (!cpu.flags.zf)
    {
        goto L_0x005153e7;
    }
    // 005153e4  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x005153e7:
    // 005153e7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005153ea  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 005153ed  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005153f0  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005153f3  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005153f6  e994000000             -jmp 0x51548f
    goto L_0x0051548f;
L_0x005153fb:
    // 005153fb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 005153fd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00515400  39c3                   +cmp ebx, eax
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
    // 00515402  7316                   -jae 0x51541a
    if (!cpu.flags.cf)
    {
        goto L_0x0051541a;
    }
    // 00515404  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00515407  0f8782000000           -ja 0x51548f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051548f;
    }
    // 0051540d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00515410  39c3                   +cmp ebx, eax
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
    // 00515412  0f8277000000           -jb 0x51548f
    if (cpu.flags.cf)
    {
        goto L_0x0051548f;
    }
    // 00515418  eb19                   -jmp 0x515433
    goto L_0x00515433;
L_0x0051541a:
    // 0051541a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051541d  39c3                   +cmp ebx, eax
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
    // 0051541f  0f826a000000           -jb 0x51548f
    if (cpu.flags.cf)
    {
        goto L_0x0051548f;
    }
    // 00515425  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00515428  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051542b  39d3                   +cmp ebx, edx
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
    // 0051542d  0f875c000000           -ja 0x51548f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051548f;
    }
L_0x00515433:
    // 00515433  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00515436  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00515439  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051543b  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0051543e  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515440  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00515442  39f8                   +cmp eax, edi
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
    // 00515444  7328                   -jae 0x51546e
    if (!cpu.flags.cf)
    {
        goto L_0x0051546e;
    }
    // 00515446  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00515449  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0051544b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051544d  39f8                   +cmp eax, edi
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
    // 0051544f  7705                   -ja 0x515456
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00515456;
    }
    // 00515451  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00515456:
    // 00515456  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00515458  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0051545a:
    // 0051545a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0051545c  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0051545f  742e                   -je 0x51548f
    if (cpu.flags.zf)
    {
        goto L_0x0051548f;
    }
    // 00515461  83faff                 +cmp edx, -1
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
    // 00515464  7408                   -je 0x51546e
    if (cpu.flags.zf)
    {
        goto L_0x0051546e;
    }
    // 00515466  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00515469  01d0                   +add eax, edx
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
    // 0051546b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051546c  75ec                   -jne 0x51545a
    if (!cpu.flags.zf)
    {
        goto L_0x0051545a;
    }
L_0x0051546e:
    // 0051546e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00515471  39c3                   +cmp ebx, eax
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
    // 00515473  7303                   -jae 0x515478
    if (!cpu.flags.cf)
    {
        goto L_0x00515478;
    }
    // 00515475  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00515478:
    // 00515478  39c3                   +cmp ebx, eax
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
    // 0051547a  7213                   -jb 0x51548f
    if (cpu.flags.cf)
    {
        goto L_0x0051548f;
    }
    // 0051547c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051547f  39c3                   +cmp ebx, eax
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
    // 00515481  720c                   -jb 0x51548f
    if (cpu.flags.cf)
    {
        goto L_0x0051548f;
    }
    // 00515483  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00515486  39c3                   +cmp ebx, eax
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
    // 00515488  7205                   -jb 0x51548f
    if (cpu.flags.cf)
    {
        goto L_0x0051548f;
    }
    // 0051548a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051548d  ebe9                   -jmp 0x515478
    goto L_0x00515478;
L_0x0051548f:
    // 0051548f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00515492  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00515494  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00515496  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00515498  39df                   +cmp edi, ebx
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
    // 0051549a  7512                   -jne 0x5154ae
    if (!cpu.flags.zf)
    {
        goto L_0x005154ae;
    }
    // 0051549c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0051549e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005154a0  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005154a2  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
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
    // 005154a5  7503                   -jne 0x5154aa
    if (!cpu.flags.zf)
    {
        goto L_0x005154aa;
    }
    // 005154a7  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x005154aa:
    // 005154aa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005154ac  eb0f                   -jmp 0x5154bd
    goto L_0x005154bd;
L_0x005154ae:
    // 005154ae  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 005154b1  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005154b4  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005154b7  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 005154ba  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x005154bd:
    // 005154bd  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005154c0  4a                     -dec edx
    (cpu.edx)--;
    // 005154c1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005154c4  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005154c7  39fb                   +cmp ebx, edi
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
    // 005154c9  7308                   -jae 0x5154d3
    if (!cpu.flags.cf)
    {
        goto L_0x005154d3;
    }
    // 005154cb  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
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
    // 005154ce  7603                   -jbe 0x5154d3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005154d3;
    }
    // 005154d0  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x005154d3:
    // 005154d3  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
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
    // 005154d6  7603                   -jbe 0x5154db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005154db;
    }
    // 005154d8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x005154db:
    // 005154db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005154dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005154dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005154de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005154df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5154e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005154e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005154e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005154e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005154e4  a14c6f5600             -mov eax, dword ptr [0x566f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 005154e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005154eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005154ed  740d                   -je 0x5154fc
    if (cpu.flags.zf)
    {
        goto L_0x005154fc;
    }
L_0x005154ef:
    // 005154ef  39c2                   +cmp edx, eax
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
    // 005154f1  7209                   -jb 0x5154fc
    if (cpu.flags.cf)
    {
        goto L_0x005154fc;
    }
    // 005154f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005154f5  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 005154f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005154fa  75f3                   -jne 0x5154ef
    if (!cpu.flags.zf)
    {
        goto L_0x005154ef;
    }
L_0x005154fc:
    // 005154fc  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 005154ff  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00515502  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00515504  7405                   -je 0x51550b
    if (cpu.flags.zf)
    {
        goto L_0x0051550b;
    }
    // 00515506  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00515509  eb06                   -jmp 0x515511
    goto L_0x00515511;
L_0x0051550b:
    // 0051550b  89154c6f5600           -mov dword ptr [0x566f4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */) = cpu.edx;
L_0x00515511:
    // 00515511  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515513  7403                   -je 0x515518
    if (cpu.flags.zf)
    {
        goto L_0x00515518;
    }
    // 00515515  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00515518:
    // 00515518  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0051551b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0051551e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00515525  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 0051552c  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00515533  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 0051553a  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0051553d  8b42d4                 -mov eax, dword ptr [edx - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */);
    // 00515540  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00515543  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00515546  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00515549  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051554b  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00515552  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00515554  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515555  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_515558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515558  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515559  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051555a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051555b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051555c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051555d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515560  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00515563  833d68af560000         +cmp dword ptr [0x56af68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681000) /* 0x56af68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051556a  7507                   -jne 0x515573
    if (!cpu.flags.zf)
    {
        goto L_0x00515573;
    }
    // 0051556c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051556e  e998000000             -jmp 0x51560b
    goto L_0x0051560b;
L_0x00515573:
    // 00515573  833df8775600fe         +cmp dword ptr [0x5677f8], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666808) /* 0x5677f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051557a  750b                   -jne 0x515587
    if (!cpu.flags.zf)
    {
        goto L_0x00515587;
    }
    // 0051557c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051557e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515581  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515582  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515583  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515586  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00515587:
    // 00515587  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00515589  e89a000000             -call 0x515628
    cpu.esp -= 4;
    sub_515628(app, cpu);
    if (cpu.terminate) return;
    // 0051558e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515590  0f8475000000           -je 0x51560b
    if (cpu.flags.zf)
    {
        goto L_0x0051560b;
    }
    // 00515596  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00515598  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0051559d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005155a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005155a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005155a4  2eff1524465300         -call dword ptr cs:[0x534624]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457444) /* 0x534624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005155ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005155ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005155af  745a                   -je 0x51560b
    if (cpu.flags.zf)
    {
        goto L_0x0051560b;
    }
    // 005155b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005155b4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 005155b7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005155ba  39f0                   +cmp eax, esi
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
    // 005155bc  760b                   -jbe 0x5155c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005155c9;
    }
    // 005155be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005155c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005155c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005155c9:
    // 005155c9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005155cc  83f838                 +cmp eax, 0x38
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
    // 005155cf  730b                   -jae 0x5155dc
    if (!cpu.flags.cf)
    {
        goto L_0x005155dc;
    }
    // 005155d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005155d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005155d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005155db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005155dc:
    // 005155dc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005155de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005155e0  e8fbfeffff             -call 0x5154e0
    cpu.esp -= 4;
    sub_5154e0(app, cpu);
    if (cpu.terminate) return;
    // 005155e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005155e7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005155e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005155ec  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005155ee  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 005155f0  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 005155f3  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 005155fa  47                     -inc edi
    (cpu.edi)++;
    // 005155fb  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005155fe  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00515601  e8ea23feff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00515606  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051560b:
    // 0051560b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051560e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051560f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515610  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515611  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515612  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515613  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_515614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515614  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515615  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00515617  e8a4eb0000             -call 0x5241c0
    cpu.esp -= 4;
    sub_5241c0(app, cpu);
    if (cpu.terminate) return;
    // 0051561c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051561e  e835ffffff             -call 0x515558
    cpu.esp -= 4;
    sub_515558(app, cpu);
    if (cpu.terminate) return;
    // 00515623  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515624  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_515628(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515628  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515629  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051562a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051562c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051562e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00515631  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00515633  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515635  743d                   -je 0x515674
    if (cpu.flags.zf)
    {
        goto L_0x00515674;
    }
    // 00515637  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00515639  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0051563c  3b02                   +cmp eax, dword ptr [edx]
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
    // 0051563e  7305                   -jae 0x515645
    if (!cpu.flags.cf)
    {
        goto L_0x00515645;
    }
    // 00515640  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00515642  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00515645:
    // 00515645  8b0d6caf5600           -mov ecx, dword ptr [0x56af6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5681004) /* 0x56af6c */);
    // 0051564b  39c8                   +cmp eax, ecx
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
    // 0051564d  7304                   -jae 0x515653
    if (!cpu.flags.cf)
    {
        goto L_0x00515653;
    }
    // 0051564f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515651  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00515653:
    // 00515653  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00515655  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0051565a  3b02                   +cmp eax, dword ptr [edx]
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
    // 0051565c  7305                   -jae 0x515663
    if (!cpu.flags.cf)
    {
        goto L_0x00515663;
    }
    // 0051565e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00515660  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515661  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515662  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00515663:
    // 00515663  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00515665  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00515668  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051566a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051566c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0051566f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00515674:
    // 00515674  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515675  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515676  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515680  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00515682  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515690  66833801               +cmp word ptr [eax], 1
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
    // 00515694  751c                   -jne 0x5156b2
    if (!cpu.flags.zf)
    {
        goto L_0x005156b2;
    }
    // 00515696  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0051569a  7416                   -je 0x5156b2
    if (cpu.flags.zf)
    {
        goto L_0x005156b2;
    }
    // 0051569c  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 005156a0  663d1000               +cmp ax, 0x10
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
    // 005156a4  7206                   -jb 0x5156ac
    if (cpu.flags.cf)
    {
        goto L_0x005156ac;
    }
    // 005156a6  663d1200               +cmp ax, 0x12
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
    // 005156aa  7606                   -jbe 0x5156b2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005156b2;
    }
L_0x005156ac:
    // 005156ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005156b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005156b2:
    // 005156b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005156b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5156b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005156b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005156b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005156ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005156bc  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005156c2  833d388a5600ff         +cmp dword ptr [0x568a38], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671480) /* 0x568a38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005156c9  7523                   -jne 0x5156ee
    if (!cpu.flags.zf)
    {
        goto L_0x005156ee;
    }
    // 005156cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005156cd  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 005156d2  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005156d4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005156d6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005156d8  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 005156dd  686c055500             -push 0x55056c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571948 /*0x55056c*/;
    cpu.esp -= 4;
    // 005156e2  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005156e9  a3388a5600             -mov dword ptr [0x568a38], eax
    app->getMemory<x86::reg32>(x86::reg32(5671480) /* 0x568a38 */) = cpu.eax;
L_0x005156ee:
    // 005156ee  833d3c8a5600ff         +cmp dword ptr [0x568a3c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671484) /* 0x568a3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005156f5  7523                   -jne 0x51571a
    if (!cpu.flags.zf)
    {
        goto L_0x0051571a;
    }
    // 005156f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005156f9  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 005156fe  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00515700  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00515702  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00515704  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00515709  6874055500             -push 0x550574
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571956 /*0x550574*/;
    cpu.esp -= 4;
    // 0051570e  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515715  a33c8a5600             -mov dword ptr [0x568a3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5671484) /* 0x568a3c */) = cpu.eax;
L_0x0051571a:
    // 0051571a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051571c  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515722  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515723  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_515728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515728  e88bffffff             -call 0x5156b8
    cpu.esp -= 4;
    sub_5156b8(app, cpu);
    if (cpu.terminate) return;
    // 0051572d  a1388a5600             -mov eax, dword ptr [0x568a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671480) /* 0x568a38 */);
    // 00515732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_515734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515734  e87fffffff             -call 0x5156b8
    cpu.esp -= 4;
    sub_5156b8(app, cpu);
    if (cpu.terminate) return;
    // 00515739  a13c8a5600             -mov eax, dword ptr [0x568a3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671484) /* 0x568a3c */);
    // 0051573e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_515740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515741  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515743  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515744  8a25996f5600           -mov ah, byte ptr [0x566f99]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5664665) /* 0x566f99 */);
    // 0051574a  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0051574d  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0051574f  8825996f5600           -mov byte ptr [0x566f99], ah
    app->getMemory<x86::reg8>(x86::reg32(5664665) /* 0x566f99 */) = cpu.ah;
    // 00515755  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00515758  8815996f5600           -mov byte ptr [0x566f99], dl
    app->getMemory<x86::reg8>(x86::reg32(5664665) /* 0x566f99 */) = cpu.dl;
    // 0051575e  8b15646f5600           -mov edx, dword ptr [0x566f64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664612) /* 0x566f64 */);
    // 00515764  bb586f5600             -mov ebx, 0x566f58
    cpu.ebx = 5664600 /*0x566f58*/;
    // 00515769  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051576b  7466                   -je 0x5157d3
    if (cpu.flags.zf)
    {
        goto L_0x005157d3;
    }
L_0x0051576d:
    // 0051576d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00515772  e88921feff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00515777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515779  7521                   -jne 0x51579c
    if (!cpu.flags.zf)
    {
        goto L_0x0051579c;
    }
    // 0051577b  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00515780  e87b21feff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00515785  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00515787  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515789  7513                   -jne 0x51579e
    if (!cpu.flags.zf)
    {
        goto L_0x0051579e;
    }
    // 0051578b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00515790  b87c055500             -mov eax, 0x55057c
    cpu.eax = 5571964 /*0x55057c*/;
    // 00515795  e872c5ffff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0051579a  eb02                   -jmp 0x51579e
    goto L_0x0051579e;
L_0x0051579c:
    // 0051579c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0051579e:
    // 0051579e  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 005157a3  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 005157a6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 005157a8  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 005157ab  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005157b2  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005157b5  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 005157b9  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005157bc  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 005157c3  890da0389f00           -mov dword ptr [0x9f38a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */) = cpu.ecx;
    // 005157c9  8b4b26                 -mov ecx, dword ptr [ebx + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(38) /* 0x26 */);
    // 005157cc  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 005157cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005157d1  759a                   -jne 0x51576d
    if (!cpu.flags.zf)
    {
        goto L_0x0051576d;
    }
L_0x005157d3:
    // 005157d3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005157d5  8935a4389f00           -mov dword ptr [0x9f38a4], esi
    app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */) = cpu.esi;
    // 005157db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005157dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005157dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005157de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005157df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5157e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005157e0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005157e2  e80d000000             -call 0x5157f4
    cpu.esp -= 4;
    sub_5157f4(app, cpu);
    if (cpu.terminate) return;
    // 005157e7  e9643bffff             -jmp 0x509350
    return sub_509350(app, cpu);
}

/* align: skip  */
void Application::sub_5157ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005157ec  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 005157f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005157f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005157f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005157f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005157f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005157f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005157fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005157fd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005157ff  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515802  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00515804  be586f5600             -mov esi, 0x566f58
    cpu.esi = 5664600 /*0x566f58*/;
    // 00515809  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051580b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051580d  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 00515812  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00515814  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515816  742f                   -je 0x515847
    if (cpu.flags.zf)
    {
        goto L_0x00515847;
    }
L_0x00515818:
    // 00515818  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0051581a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051581d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00515822  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00515826  7513                   -jne 0x51583b
    if (!cpu.flags.zf)
    {
        goto L_0x0051583b;
    }
    // 00515828  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0051582c  750d                   -jne 0x51583b
    if (!cpu.flags.zf)
    {
        goto L_0x0051583b;
    }
    // 0051582e  39f0                   +cmp eax, esi
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
    // 00515830  720f                   -jb 0x515841
    if (cpu.flags.cf)
    {
        goto L_0x00515841;
    }
    // 00515832  3da66f5600             +cmp eax, 0x566fa6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5664678 /*0x566fa6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515837  7302                   -jae 0x51583b
    if (!cpu.flags.cf)
    {
        goto L_0x0051583b;
    }
    // 00515839  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0051583b:
    // 0051583b  e80489fdff             -call 0x4ee144
    cpu.esp -= 4;
    sub_4ee144(app, cpu);
    if (cpu.terminate) return;
    // 00515840  43                     -inc ebx
    (cpu.ebx)++;
L_0x00515841:
    // 00515841  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515843  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00515845  75d1                   -jne 0x515818
    if (!cpu.flags.zf)
    {
        goto L_0x00515818;
    }
L_0x00515847:
    // 00515847  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515849  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5157f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005157f4;
    // 005157ec  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 005157f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x005157f4:
    // 005157f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005157f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005157f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005157f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005157f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005157fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005157fd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005157ff  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515802  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00515804  be586f5600             -mov esi, 0x566f58
    cpu.esi = 5664600 /*0x566f58*/;
    // 00515809  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051580b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051580d  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 00515812  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00515814  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515816  742f                   -je 0x515847
    if (cpu.flags.zf)
    {
        goto L_0x00515847;
    }
L_0x00515818:
    // 00515818  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0051581a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051581d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00515822  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00515826  7513                   -jne 0x51583b
    if (!cpu.flags.zf)
    {
        goto L_0x0051583b;
    }
    // 00515828  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0051582c  750d                   -jne 0x51583b
    if (!cpu.flags.zf)
    {
        goto L_0x0051583b;
    }
    // 0051582e  39f0                   +cmp eax, esi
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
    // 00515830  720f                   -jb 0x515841
    if (cpu.flags.cf)
    {
        goto L_0x00515841;
    }
    // 00515832  3da66f5600             +cmp eax, 0x566fa6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5664678 /*0x566fa6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515837  7302                   -jae 0x51583b
    if (!cpu.flags.cf)
    {
        goto L_0x0051583b;
    }
    // 00515839  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0051583b:
    // 0051583b  e80489fdff             -call 0x4ee144
    cpu.esp -= 4;
    sub_4ee144(app, cpu);
    if (cpu.terminate) return;
    // 00515840  43                     -inc ebx
    (cpu.ebx)++;
L_0x00515841:
    // 00515841  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515843  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00515845  75d1                   -jne 0x515818
    if (!cpu.flags.zf)
    {
        goto L_0x00515818;
    }
L_0x00515847:
    // 00515847  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515849  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051584d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_515850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515850  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00515855  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00515858  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515859  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051585a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051585b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051585d  ff1578775600           -call dword ptr [0x567778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515863  8b15a0389f00           -mov edx, dword ptr [0x9f38a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 00515869  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051586b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051586d  741a                   -je 0x515889
    if (cpu.flags.zf)
    {
        goto L_0x00515889;
    }
L_0x0051586f:
    // 0051586f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00515872  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00515875  740c                   -je 0x515883
    if (cpu.flags.zf)
    {
        goto L_0x00515883;
    }
    // 00515877  43                     -inc ebx
    (cpu.ebx)++;
    // 00515878  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0051587c  7405                   -je 0x515883
    if (cpu.flags.zf)
    {
        goto L_0x00515883;
    }
    // 0051587e  e8ddcefeff             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
L_0x00515883:
    // 00515883  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00515885  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00515887  75e6                   -jne 0x51586f
    if (!cpu.flags.zf)
    {
        goto L_0x0051586f;
    }
L_0x00515889:
    // 00515889  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051588f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515891  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515892  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_515858(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00515858;
    // 00515850  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00515855  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00515858:
    // 00515858  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515859  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051585a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051585b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051585d  ff1578775600           -call dword ptr [0x567778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515863  8b15a0389f00           -mov edx, dword ptr [0x9f38a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 00515869  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051586b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051586d  741a                   -je 0x515889
    if (cpu.flags.zf)
    {
        goto L_0x00515889;
    }
L_0x0051586f:
    // 0051586f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00515872  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00515875  740c                   -je 0x515883
    if (cpu.flags.zf)
    {
        goto L_0x00515883;
    }
    // 00515877  43                     -inc ebx
    (cpu.ebx)++;
    // 00515878  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0051587c  7405                   -je 0x515883
    if (cpu.flags.zf)
    {
        goto L_0x00515883;
    }
    // 0051587e  e8ddcefeff             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
L_0x00515883:
    // 00515883  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00515885  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00515887  75e6                   -jne 0x51586f
    if (!cpu.flags.zf)
    {
        goto L_0x0051586f;
    }
L_0x00515889:
    // 00515889  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051588f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515891  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515892  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5158a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005158a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005158a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005158a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005158a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005158a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005158a6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005158a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005158ae  e8699bfeff             -call 0x4ff41c
    cpu.esp -= 4;
    sub_4ff41c(app, cpu);
    if (cpu.terminate) return;
    // 005158b3  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 005158b8  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005158bb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 005158bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005158bf  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005158c1  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 005158c3  8b1d70af5600           -mov ebx, dword ptr [0x56af70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 005158c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005158cb  e870adfcff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 005158d0  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 005158d5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005158d7  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 005158dd  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 005158e0  e8539afeff             -call 0x4ff338
    cpu.esp -= 4;
    sub_4ff338(app, cpu);
    if (cpu.terminate) return;
    // 005158e5  e8a6e90000             -call 0x524290
    cpu.esp -= 4;
    sub_524290(app, cpu);
    if (cpu.terminate) return;
    // 005158ea  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005158ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005158ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005158ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005158ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005158f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515905  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515906  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00515909  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0051590b  a1fc775600             -mov eax, dword ptr [0x5677fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666812) /* 0x5677fc */);
    // 00515910  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515912  e8cd000000             -call 0x5159e4
    cpu.esp -= 4;
    sub_5159e4(app, cpu);
    if (cpu.terminate) return;
    // 00515917  40                     -inc eax
    (cpu.eax)++;
    // 00515918  8b15fc775600           -mov edx, dword ptr [0x5677fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666812) /* 0x5677fc */);
    // 0051591e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00515922  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00515925  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515927  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051592a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051592d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0051592f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00515931  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515935  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515938  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051593c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051593f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00515941  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00515944  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00515946  e8b51ffeff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051594b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051594d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051594f  7455                   -je 0x5159a6
    if (cpu.flags.zf)
    {
        goto L_0x005159a6;
    }
    // 00515951  8b35fc775600           -mov esi, dword ptr [0x5677fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666812) /* 0x5677fc */);
    // 00515957  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00515959  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0051595b  a3c0389f00             -mov dword ptr [0x9f38c0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */) = cpu.eax;
    // 00515960  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00515961  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00515963  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00515965  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515966  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515968  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0051596b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051596d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0051596f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00515972  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00515974  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515975  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00515976  8b15c0389f00           -mov edx, dword ptr [0x9f38c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */);
    // 0051597c  a100785600             -mov eax, dword ptr [0x567800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666816) /* 0x567800 */);
    // 00515981  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00515983  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00515985  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515988  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051598a  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051598e  e851000000             -call 0x5159e4
    cpu.esp -= 4;
    sub_5159e4(app, cpu);
    if (cpu.terminate) return;
    // 00515993  a1c0389f00             -mov eax, dword ptr [0x9f38c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */);
    // 00515998  01f0                   +add eax, esi
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
    // 0051599a  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005159a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005159a4  eb05                   -jmp 0x5159ab
    goto L_0x005159ab;
L_0x005159a6:
    // 005159a6  a3c0389f00             -mov dword ptr [0x9f38c0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */) = cpu.eax;
L_0x005159ab:
    // 005159ab  a3bc389f00             -mov dword ptr [0x9f38bc], eax
    app->getMemory<x86::reg32>(x86::reg32(10434748) /* 0x9f38bc */) = cpu.eax;
    // 005159b0  a1bc389f00             -mov eax, dword ptr [0x9f38bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434748) /* 0x9f38bc */);
    // 005159b5  a31082a100             -mov dword ptr [0xa18210], eax
    app->getMemory<x86::reg32>(x86::reg32(10584592) /* 0xa18210 */) = cpu.eax;
    // 005159ba  a1c0389f00             -mov eax, dword ptr [0x9f38c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */);
    // 005159bf  a31482a100             -mov dword ptr [0xa18214], eax
    app->getMemory<x86::reg32>(x86::reg32(10584596) /* 0xa18214 */) = cpu.eax;
    // 005159c4  a11082a100             -mov eax, dword ptr [0xa18210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584592) /* 0xa18210 */);
    // 005159c9  a3c4389f00             -mov dword ptr [0x9f38c4], eax
    app->getMemory<x86::reg32>(x86::reg32(10434756) /* 0x9f38c4 */) = cpu.eax;
    // 005159ce  a11482a100             -mov eax, dword ptr [0xa18214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584596) /* 0xa18214 */);
    // 005159d3  a3c8389f00             -mov dword ptr [0x9f38c8], eax
    app->getMemory<x86::reg32>(x86::reg32(10434760) /* 0x9f38c8 */) = cpu.eax;
    // 005159d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005159db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005159e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5159e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005159e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005159e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005159e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005159e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005159e8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005159eb  8b0d1882a100           -mov ecx, dword ptr [0xa18218]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10584600) /* 0xa18218 */);
    // 005159f1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005159f3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005159f6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x005159f8:
    // 005159f8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 005159fa  80fa20                 +cmp dl, 0x20
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
    // 005159fd  7405                   -je 0x515a04
    if (cpu.flags.zf)
    {
        goto L_0x00515a04;
    }
    // 005159ff  80fa09                 +cmp dl, 9
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
    // 00515a02  7503                   -jne 0x515a07
    if (!cpu.flags.zf)
    {
        goto L_0x00515a07;
    }
L_0x00515a04:
    // 00515a04  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515a05  ebf1                   -jmp 0x5159f8
    goto L_0x005159f8;
L_0x00515a07:
    // 00515a07  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00515a09  0f84be000000           -je 0x515acd
    if (cpu.flags.zf)
    {
        goto L_0x00515acd;
    }
    // 00515a0f  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515a11  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00515a13  80ff22                 +cmp bh, 0x22
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a16  7503                   -jne 0x515a1b
    if (!cpu.flags.zf)
    {
        goto L_0x00515a1b;
    }
    // 00515a18  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00515a1a  40                     -inc eax
    (cpu.eax)++;
L_0x00515a1b:
    // 00515a1b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00515a1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00515a21:
    // 00515a21  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a24  751c                   -jne 0x515a42
    if (!cpu.flags.zf)
    {
        goto L_0x00515a42;
    }
    // 00515a26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00515a28  750f                   -jne 0x515a39
    if (!cpu.flags.zf)
    {
        goto L_0x00515a39;
    }
    // 00515a2a  40                     -inc eax
    (cpu.eax)++;
    // 00515a2b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00515a2d  7504                   -jne 0x515a33
    if (!cpu.flags.zf)
    {
        goto L_0x00515a33;
    }
    // 00515a2f  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 00515a31  ebee                   -jmp 0x515a21
    goto L_0x00515a21;
L_0x00515a33:
    // 00515a33  740d                   -je 0x515a42
    if (cpu.flags.zf)
    {
        goto L_0x00515a42;
    }
    // 00515a35  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00515a37  ebe8                   -jmp 0x515a21
    goto L_0x00515a21;
L_0x00515a39:
    // 00515a39  80fa01                 +cmp dl, 1
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
    // 00515a3c  0f845f000000           -je 0x515aa1
    if (cpu.flags.zf)
    {
        goto L_0x00515aa1;
    }
L_0x00515a42:
    // 00515a42  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515a44  80fe20                 +cmp dh, 0x20
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
    // 00515a47  7405                   -je 0x515a4e
    if (cpu.flags.zf)
    {
        goto L_0x00515a4e;
    }
    // 00515a49  80fe09                 +cmp dh, 9
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a4c  7508                   -jne 0x515a56
    if (!cpu.flags.zf)
    {
        goto L_0x00515a56;
    }
L_0x00515a4e:
    // 00515a4e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00515a50  0f844b000000           -je 0x515aa1
    if (cpu.flags.zf)
    {
        goto L_0x00515aa1;
    }
L_0x00515a56:
    // 00515a56  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515a58  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00515a5a  7445                   -je 0x515aa1
    if (cpu.flags.zf)
    {
        goto L_0x00515aa1;
    }
    // 00515a5c  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a5f  7530                   -jne 0x515a91
    if (!cpu.flags.zf)
    {
        goto L_0x00515a91;
    }
    // 00515a61  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00515a63  7511                   -jne 0x515a76
    if (!cpu.flags.zf)
    {
        goto L_0x00515a76;
    }
    // 00515a65  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a69  7526                   -jne 0x515a91
    if (!cpu.flags.zf)
    {
        goto L_0x00515a91;
    }
    // 00515a6b  8a70ff                 -mov dh, byte ptr [eax - 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00515a6e  40                     -inc eax
    (cpu.eax)++;
    // 00515a6f  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a72  74ad                   -je 0x515a21
    if (cpu.flags.zf)
    {
        goto L_0x00515a21;
    }
    // 00515a74  eb1b                   -jmp 0x515a91
    goto L_0x00515a91;
L_0x00515a76:
    // 00515a76  80fa01                 +cmp dl, 1
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
    // 00515a79  750f                   -jne 0x515a8a
    if (!cpu.flags.zf)
    {
        goto L_0x00515a8a;
    }
    // 00515a7b  8a7001                 -mov dh, byte ptr [eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00515a7e  80fe22                 +cmp dh, 0x22
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a81  740d                   -je 0x515a90
    if (cpu.flags.zf)
    {
        goto L_0x00515a90;
    }
    // 00515a83  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a86  7509                   -jne 0x515a91
    if (!cpu.flags.zf)
    {
        goto L_0x00515a91;
    }
    // 00515a88  eb06                   -jmp 0x515a90
    goto L_0x00515a90;
L_0x00515a8a:
    // 00515a8a  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515a8e  7501                   -jne 0x515a91
    if (!cpu.flags.zf)
    {
        goto L_0x00515a91;
    }
L_0x00515a90:
    // 00515a90  40                     -inc eax
    (cpu.eax)++;
L_0x00515a91:
    // 00515a91  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00515a93  7409                   -je 0x515a9e
    if (cpu.flags.zf)
    {
        goto L_0x00515a9e;
    }
    // 00515a95  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515a96  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515a98  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515a99  8873ff                 -mov byte ptr [ebx - 1], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dh;
    // 00515a9c  eb83                   -jmp 0x515a21
    goto L_0x00515a21;
L_0x00515a9e:
    // 00515a9e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515a9f  eb80                   -jmp 0x515a21
    goto L_0x00515a21;
L_0x00515aa1:
    // 00515aa1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00515aa3  741b                   -je 0x515ac0
    if (cpu.flags.zf)
    {
        goto L_0x00515ac0;
    }
    // 00515aa5  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515aa9  892cbe                 -mov dword ptr [esi + edi*4], ebp
    app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 4) = cpu.ebp;
    // 00515aac  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515aae  47                     -inc edi
    (cpu.edi)++;
    // 00515aaf  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00515ab1  7504                   -jne 0x515ab7
    if (!cpu.flags.zf)
    {
        goto L_0x00515ab7;
    }
    // 00515ab3  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00515ab5  eb16                   -jmp 0x515acd
    goto L_0x00515acd;
L_0x00515ab7:
    // 00515ab7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515ab8  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00515abb  e938ffffff             -jmp 0x5159f8
    goto L_0x005159f8;
L_0x00515ac0:
    // 00515ac0  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515ac2  47                     -inc edi
    (cpu.edi)++;
    // 00515ac3  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00515ac5  7406                   -je 0x515acd
    if (cpu.flags.zf)
    {
        goto L_0x00515acd;
    }
    // 00515ac7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515ac8  e92bffffff             -jmp 0x5159f8
    goto L_0x005159f8;
L_0x00515acd:
    // 00515acd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00515ad0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00515ad2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00515ad4  890d1882a100           -mov dword ptr [0xa18218], ecx
    app->getMemory<x86::reg32>(x86::reg32(10584600) /* 0xa18218 */) = cpu.ecx;
    // 00515ada  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00515add  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515adf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ae0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ae1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515af0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515af1  8a15a08b5600           -mov dl, byte ptr [0x568ba0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515af7  a1a08b5600             -mov eax, dword ptr [0x568ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515afc  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00515aff  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00515b02  8815a08b5600           -mov byte ptr [0x568ba0], dl
    app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */) = cpu.dl;
    // 00515b08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515b09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_515b0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515b0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515b0d  8a15a08b5600           -mov dl, byte ptr [0x568ba0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515b13  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00515b16  a1a08b5600             -mov eax, dword ptr [0x568ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515b1b  8815a08b5600           -mov byte ptr [0x568ba0], dl
    app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */) = cpu.dl;
    // 00515b21  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00515b23  80e6fd                 -and dh, 0xfd
    cpu.dh &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00515b26  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00515b29  8835a08b5600           -mov byte ptr [0x568ba0], dh
    app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */) = cpu.dh;
    // 00515b2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515b30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_515b34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515b34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515b35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515b36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515b37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515b38  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 00515b3e  8a25a08b5600           -mov ah, byte ptr [0x568ba0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515b44  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00515b47  7409                   -je 0x515b52
    if (cpu.flags.zf)
    {
        goto L_0x00515b52;
    }
    // 00515b49  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00515b4c  0f85cd000000           -jne 0x515c1f
    if (!cpu.flags.zf)
    {
        goto L_0x00515c1f;
    }
L_0x00515b52:
    // 00515b52  8a35a08b5600           -mov dh, byte ptr [0x568ba0]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */);
    // 00515b58  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00515b5a  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00515b5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00515b5e  8835a08b5600           -mov byte ptr [0x568ba0], dh
    app->getMemory<x86::reg8>(x86::reg32(5671840) /* 0x568ba0 */) = cpu.dh;
    // 00515b64  2eff156c455300         -call dword ptr cs:[0x53456c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457260) /* 0x53456c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00515b6b  83f801                 +cmp eax, 1
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
    // 00515b6e  0f82ab000000           -jb 0x515c1f
    if (cpu.flags.cf)
    {
        goto L_0x00515c1f;
    }
    // 00515b74  7635                   -jbe 0x515bab
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00515bab;
    }
    // 00515b76  83f802                 +cmp eax, 2
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
    // 00515b79  0f85a0000000           -jne 0x515c1f
    if (!cpu.flags.zf)
    {
        goto L_0x00515c1f;
    }
    // 00515b7f  c705988b560001000000   -mov dword ptr [0x568b98], 1
    app->getMemory<x86::reg32>(x86::reg32(5671832) /* 0x568b98 */) = 1 /*0x1*/;
    // 00515b89  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00515b90  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00515b92  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00515b95  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515b97  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515b9a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515b9c  a39c8b5600             -mov dword ptr [0x568b9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */) = cpu.eax;
    // 00515ba1  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00515ba3  891d9c8b5600           -mov dword ptr [0x568b9c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */) = cpu.ebx;
    // 00515ba9  eb08                   -jmp 0x515bb3
    goto L_0x00515bb3;
L_0x00515bab:
    // 00515bab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00515bad  890d988b5600           -mov dword ptr [0x568b98], ecx
    app->getMemory<x86::reg32>(x86::reg32(5671832) /* 0x568b98 */) = cpu.ecx;
L_0x00515bb3:
    // 00515bb3  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00515bb7  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00515bba  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00515bbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00515bbe  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00515bc1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515bc3  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00515bc8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515bcb  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515bcf  a3948b5600             -mov dword ptr [0x568b94], eax
    app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */) = cpu.eax;
    // 00515bd4  b8888a5600             -mov eax, 0x568a88
    cpu.eax = 5671560 /*0x568a88*/;
    // 00515bd9  e812e70000             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00515bde  83f8ff                 +cmp eax, -1
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
    // 00515be1  750a                   -jne 0x515bed
    if (!cpu.flags.zf)
    {
        goto L_0x00515bed;
    }
    // 00515be3  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 00515be5  883d888a5600           -mov byte ptr [0x568a88], bh
    app->getMemory<x86::reg8>(x86::reg32(5671560) /* 0x568a88 */) = cpu.bh;
    // 00515beb  eb08                   -jmp 0x515bf5
    goto L_0x00515bf5;
L_0x00515bed:
    // 00515bed  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00515bef  881d088b5600           -mov byte ptr [0x568b08], bl
    app->getMemory<x86::reg8>(x86::reg32(5671688) /* 0x568b08 */) = cpu.bl;
L_0x00515bf5:
    // 00515bf5  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00515bfa  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00515bfe  b8098b5600             -mov eax, 0x568b09
    cpu.eax = 5671689 /*0x568b09*/;
    // 00515c03  e8e8e60000             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00515c08  83f8ff                 +cmp eax, -1
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
    // 00515c0b  750a                   -jne 0x515c17
    if (!cpu.flags.zf)
    {
        goto L_0x00515c17;
    }
    // 00515c0d  30ed                   +xor ch, ch
    cpu.clear_co();
    cpu.set_szp((cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch))));
    // 00515c0f  882d098b5600           -mov byte ptr [0x568b09], ch
    app->getMemory<x86::reg8>(x86::reg32(5671689) /* 0x568b09 */) = cpu.ch;
    // 00515c15  eb08                   -jmp 0x515c1f
    goto L_0x00515c1f;
L_0x00515c17:
    // 00515c17  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00515c19  880d898b5600           -mov byte ptr [0x568b89], cl
    app->getMemory<x86::reg8>(x86::reg32(5671817) /* 0x568b89 */) = cpu.cl;
L_0x00515c1f:
    // 00515c1f  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 00515c25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_515c2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515c2c  b8ac055500             -mov eax, 0x5505ac
    cpu.eax = 5572012 /*0x5505ac*/;
    // 00515c31  e89a8effff             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 00515c36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00515c38  0f84f6feffff           -je 0x515b34
    if (cpu.flags.zf)
    {
        return sub_515b34(app, cpu);
    }
    // 00515c3e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00515c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00515c43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515c44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515c45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515c46  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515c49  8b359c8b5600           -mov esi, dword ptr [0x568b9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 00515c4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515c51  bb948b5600             -mov ebx, 0x568b94
    cpu.ebx = 5671828 /*0x568b94*/;
    // 00515c56  8915988b5600           -mov dword ptr [0x568b98], edx
    app->getMemory<x86::reg32>(x86::reg32(5671832) /* 0x568b98 */) = cpu.edx;
    // 00515c5c  ba888a5600             -mov edx, 0x568a88
    cpu.edx = 5671560 /*0x568a88*/;
    // 00515c61  e856000000             -call 0x515cbc
    cpu.esp -= 4;
    sub_515cbc(app, cpu);
    if (cpu.terminate) return;
    // 00515c66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00515c68  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 00515c6a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00515c6c  0f8550020000           -jne 0x515ec2
    if (!cpu.flags.zf)
    {
        return sub_515ec2(app, cpu);
    }
    // 00515c72  8b359c8b5600           -mov esi, dword ptr [0x568b9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 00515c78  8825098b5600           -mov byte ptr [0x568b09], ah
    app->getMemory<x86::reg8>(x86::reg32(5671689) /* 0x568b09 */) = cpu.ah;
    // 00515c7e  89359c8b5600           -mov dword ptr [0x568b9c], esi
    app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */) = cpu.esi;
    // 00515c84  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515c87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c8a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515c8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_515c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515c91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515c92  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00515c94  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515c96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515c98  80fb30                 +cmp bl, 0x30
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
    // 00515c9b  7219                   -jb 0x515cb6
    if (cpu.flags.cf)
    {
        goto L_0x00515cb6;
    }
L_0x00515c9d:
    // 00515c9d  803839                 +cmp byte ptr [eax], 0x39
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515ca0  7714                   -ja 0x515cb6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00515cb6;
    }
    // 00515ca2  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00515ca5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00515ca7  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515ca9  40                     -inc eax
    (cpu.eax)++;
    // 00515caa  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00515cac  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515cae  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00515cb1  80ff30                 +cmp bh, 0x30
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515cb4  73e7                   -jae 0x515c9d
    if (!cpu.flags.cf)
    {
        goto L_0x00515c9d;
    }
L_0x00515cb6:
    // 00515cb6  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00515cb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515cb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515cba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_515cbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515cbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515cbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515cbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515cbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515cc0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00515cc3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00515cc5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00515cc8  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00515ccc  80383a                 +cmp byte ptr [eax], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515ccf  7501                   -jne 0x515cd2
    if (!cpu.flags.zf)
    {
        goto L_0x00515cd2;
    }
    // 00515cd1  45                     -inc ebp
    (cpu.ebp)++;
L_0x00515cd2:
    // 00515cd2  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x00515cd4:
    // 00515cd4  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00515cd7  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00515cd9  741c                   -je 0x515cf7
    if (cpu.flags.zf)
    {
        goto L_0x00515cf7;
    }
    // 00515cdb  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515cde  7417                   -je 0x515cf7
    if (cpu.flags.zf)
    {
        goto L_0x00515cf7;
    }
    // 00515ce0  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515ce3  7412                   -je 0x515cf7
    if (cpu.flags.zf)
    {
        goto L_0x00515cf7;
    }
    // 00515ce5  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515ce8  740d                   -je 0x515cf7
    if (cpu.flags.zf)
    {
        goto L_0x00515cf7;
    }
    // 00515cea  80fa30                 +cmp dl, 0x30
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
    // 00515ced  7205                   -jb 0x515cf4
    if (cpu.flags.cf)
    {
        goto L_0x00515cf4;
    }
    // 00515cef  80fa39                 +cmp dl, 0x39
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
    // 00515cf2  7603                   -jbe 0x515cf7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00515cf7;
    }
L_0x00515cf4:
    // 00515cf4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00515cf5  ebdd                   -jmp 0x515cd4
    goto L_0x00515cd4;
L_0x00515cf7:
    // 00515cf7  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00515cf9  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00515cfb  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515d01  7e05                   -jle 0x515d08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00515d08;
    }
    // 00515d03  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
L_0x00515d08:
    // 00515d08  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00515d0b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00515d0d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00515d0e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00515d10  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00515d12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515d13  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515d15  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00515d18  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00515d1a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00515d1c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00515d1f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00515d21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515d22  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00515d23  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00515d25  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00515d28  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00515d2a  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00515d2d  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515d30  7507                   -jne 0x515d39
    if (!cpu.flags.zf)
    {
        goto L_0x00515d39;
    }
    // 00515d32  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00515d37  eb05                   -jmp 0x515d3e
    goto L_0x00515d3e;
L_0x00515d39:
    // 00515d39  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515d3c  7502                   -jne 0x515d40
    if (!cpu.flags.zf)
    {
        goto L_0x00515d40;
    }
L_0x00515d3e:
    // 00515d3e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00515d40:
    // 00515d40  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 00515d43  3c30                   +cmp al, 0x30
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
    // 00515d45  0f827d000000           -jb 0x515dc8
    if (cpu.flags.cf)
    {
        goto L_0x00515dc8;
    }
    // 00515d4b  3c39                   +cmp al, 0x39
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
    // 00515d4d  0f8775000000           -ja 0x515dc8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00515dc8;
    }
    // 00515d53  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515d57  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00515d59  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00515d5b  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00515d5f  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00515d63  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00515d67  e824ffffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515d6c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515d6e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00515d70  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515d73  751f                   -jne 0x515d94
    if (!cpu.flags.zf)
    {
        goto L_0x00515d94;
    }
    // 00515d75  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00515d79  40                     -inc eax
    (cpu.eax)++;
    // 00515d7a  e811ffffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515d7f  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515d81  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00515d83  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515d86  750c                   -jne 0x515d94
    if (!cpu.flags.zf)
    {
        goto L_0x00515d94;
    }
    // 00515d88  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515d8c  40                     -inc eax
    (cpu.eax)++;
    // 00515d8d  e8fefeffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515d92  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00515d94:
    // 00515d94  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515d98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515d9a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00515d9d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00515d9f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00515da3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515da6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00515da8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00515daa  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00515dad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515daf  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515db3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00515db6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00515db8  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00515dbc  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00515dbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00515dc0  7406                   -je 0x515dc8
    if (cpu.flags.zf)
    {
        goto L_0x00515dc8;
    }
    // 00515dc2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00515dc4  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00515dc6  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
L_0x00515dc8:
    // 00515dc8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00515dca  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00515dcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515dce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515dd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515dd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_515dd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515dd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00515dd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00515dd6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515dd7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00515dda  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515ddc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00515dde  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 00515de0  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00515de5  80fc4a                 +cmp ah, 0x4a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515de8  7507                   -jne 0x515df1
    if (!cpu.flags.zf)
    {
        goto L_0x00515df1;
    }
    // 00515dea  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00515def  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00515df1:
    // 00515df1  803b4d                 +cmp byte ptr [ebx], 0x4d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(77 /*0x4d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515df4  7503                   -jne 0x515df9
    if (!cpu.flags.zf)
    {
        goto L_0x00515df9;
    }
    // 00515df6  43                     -inc ebx
    (cpu.ebx)++;
    // 00515df7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00515df9:
    // 00515df9  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515dfd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515dff  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00515e02  e889feffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515e07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00515e09  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515e0b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00515e0d  7409                   -je 0x515e18
    if (cpu.flags.zf)
    {
        goto L_0x00515e18;
    }
    // 00515e0f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e13  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00515e16  eb45                   -jmp 0x515e5d
    goto L_0x00515e5d;
L_0x00515e18:
    // 00515e18  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e1c  48                     -dec eax
    (cpu.eax)--;
    // 00515e1d  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00515e20  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515e23  7531                   -jne 0x515e56
    if (!cpu.flags.zf)
    {
        goto L_0x00515e56;
    }
    // 00515e25  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00515e28  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e2c  e85ffeffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515e31  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00515e33  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515e35  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e39  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00515e3c  803e2e                 +cmp byte ptr [esi], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515e3f  7515                   -jne 0x515e56
    if (!cpu.flags.zf)
    {
        goto L_0x00515e56;
    }
    // 00515e41  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e45  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00515e48  e843feffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515e4d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515e4f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00515e53  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00515e56:
    // 00515e56  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00515e5d:
    // 00515e5d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00515e62  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00515e64  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00515e68  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00515e6b  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00515e6f  803b2f                 +cmp byte ptr [ebx], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515e72  7532                   -jne 0x515ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00515ea6;
    }
    // 00515e74  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00515e78  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00515e7b  e810feffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515e80  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00515e82  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515e84  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515e87  751d                   -jne 0x515ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00515ea6;
    }
    // 00515e89  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515e8d  40                     -inc eax
    (cpu.eax)++;
    // 00515e8e  e8fdfdffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515e93  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515e95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00515e97  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515e9a  750a                   -jne 0x515ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00515ea6;
    }
    // 00515e9c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00515e9e  40                     -inc eax
    (cpu.eax)++;
    // 00515e9f  e8ecfdffff             -call 0x515c90
    cpu.esp -= 4;
    sub_515c90(app, cpu);
    if (cpu.terminate) return;
    // 00515ea4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00515ea6:
    // 00515ea6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00515ea9  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00515eab  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00515eaf  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00515eb2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00515eb6  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00515eb9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515ebb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00515ebe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ebf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ec0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515ec1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_515ec2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515ec2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00515ec7  ba098b5600             -mov edx, 0x568b09
    cpu.edx = 5671689 /*0x568b09*/;
    // 00515ecc  a1948b5600             -mov eax, dword ptr [0x568b94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 00515ed1  891d988b5600           -mov dword ptr [0x568b98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5671832) /* 0x568b98 */) = cpu.ebx;
    // 00515ed7  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 00515edc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00515ede  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00515ee1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00515ee3  e8d4fdffff             -call 0x515cbc
    cpu.esp -= 4;
    sub_515cbc(app, cpu);
    if (cpu.terminate) return;
    // 00515ee8  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00515eeb  8b35948b5600           -mov esi, dword ptr [0x568b94]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 00515ef1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00515ef3  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00515ef5  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00515ef7  89359c8b5600           -mov dword ptr [0x568b9c], esi
    app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */) = cpu.esi;
    // 00515efd  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515f00  750d                   -jne 0x515f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00515f0f;
    }
    // 00515f02  ba408a5600             -mov edx, 0x568a40
    cpu.edx = 5671488 /*0x568a40*/;
    // 00515f07  40                     -inc eax
    (cpu.eax)++;
    // 00515f08  e8c7feffff             -call 0x515dd4
    cpu.esp -= 4;
    sub_515dd4(app, cpu);
    if (cpu.terminate) return;
    // 00515f0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00515f0f:
    // 00515f0f  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00515f11  8b359c8b5600           -mov esi, dword ptr [0x568b9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 00515f17  80ff2c                 +cmp bh, 0x2c
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00515f1a  7567                   -jne 0x515f83
    if (!cpu.flags.zf)
    {
        goto L_0x00515f83;
    }
    // 00515f1c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00515f1f  ba648a5600             -mov edx, 0x568a64
    cpu.edx = 5671524 /*0x568a64*/;
    // 00515f24  e8abfeffff             -call 0x515dd4
    cpu.esp -= 4;
    sub_515dd4(app, cpu);
    if (cpu.terminate) return;
    // 00515f29  8b359c8b5600           -mov esi, dword ptr [0x568b9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */);
    // 00515f2f  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 00515f34  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00515f36  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515f38  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00515f3b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00515f3d  8b3d6c8a5600           -mov edi, dword ptr [0x568a6c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5671532) /* 0x568a6c */);
    // 00515f43  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 00515f48  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00515f4a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00515f4c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515f4e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00515f51  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00515f53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00515f55  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00515f58  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00515f5a  8b2d688a5600           -mov ebp, dword ptr [0x568a68]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5671528) /* 0x568a68 */);
    // 00515f60  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515f62  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00515f64  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515f66  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00515f69  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00515f6b  a1648a5600             -mov eax, dword ptr [0x568a64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671524) /* 0x568a64 */);
    // 00515f70  893d6c8a5600           -mov dword ptr [0x568a6c], edi
    app->getMemory<x86::reg32>(x86::reg32(5671532) /* 0x568a6c */) = cpu.edi;
    // 00515f76  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00515f78  892d688a5600           -mov dword ptr [0x568a68], ebp
    app->getMemory<x86::reg32>(x86::reg32(5671528) /* 0x568a68 */) = cpu.ebp;
    // 00515f7e  a3648a5600             -mov dword ptr [0x568a64], eax
    app->getMemory<x86::reg32>(x86::reg32(5671524) /* 0x568a64 */) = cpu.eax;
L_0x00515f83:
    // 00515f83  89359c8b5600           -mov dword ptr [0x568b9c], esi
    app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */) = cpu.esi;
    // 00515f89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00515f8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00515f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_515fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00515fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00515fa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00515fa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00515fa3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00515fa5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00515fa7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515fa9  81fac0a80000           +cmp edx, 0xa8c0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43200 /*0xa8c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00515faf  731c                   -jae 0x515fcd
    if (!cpu.flags.cf)
    {
        goto L_0x00515fcd;
    }
    // 00515fb1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00515fb3  7e18                   -jle 0x515fcd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00515fcd;
    }
    // 00515fb5  8db280510100           -lea esi, [edx + 0x15180]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(86400) /* 0x15180 */);
    // 00515fbb  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00515fbd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515fbf  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 00515fc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515fc6  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515fc8  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00515fca  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00515fcb  eb0f                   -jmp 0x515fdc
    goto L_0x00515fdc;
L_0x00515fcd:
    // 00515fcd  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 00515fd2  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00515fd4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515fd6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515fd8  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515fda  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00515fdc:
    // 00515fdc  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 00515fe1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00515fe3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515fe5  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515fe7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00515fe9  be100e0000             -mov esi, 0xe10
    cpu.esi = 3600 /*0xe10*/;
    // 00515fee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515ff0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515ff2  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515ff4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00515ff6  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00515ff9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00515ffb  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00515ffd  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00515fff  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 00516004  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00516006  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00516008  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0051600a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051600c  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051600f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00516011  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00516013  bb6e010000             -mov ebx, 0x16e
    cpu.ebx = 366 /*0x16e*/;
    // 00516018  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051601a  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0051601c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051601e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00516020  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00516022  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00516025  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00516027  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0051602a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051602c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051602e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00516031  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00516033  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00516035  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00516037  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00516039  7608                   -jbe 0x516043
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00516043;
    }
    // 0051603b  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051603e  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 00516041  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00516043:
    // 00516043  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 00516049  e8a2000000             -call 0x5160f0
    cpu.esp -= 4;
    sub_5160f0(app, cpu);
    if (cpu.terminate) return;
    // 0051604e  056d010000             -add eax, 0x16d
    (cpu.eax) += x86::reg32(x86::sreg32(365 /*0x16d*/));
    // 00516053  39c3                   +cmp ebx, eax
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
    // 00516055  7207                   -jb 0x51605e
    if (cpu.flags.cf)
    {
        goto L_0x0051605e;
    }
L_0x00516057:
    // 00516057  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00516059  42                     -inc edx
    (cpu.edx)++;
    // 0051605a  39c3                   +cmp ebx, eax
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
    // 0051605c  73f9                   -jae 0x516057
    if (!cpu.flags.cf)
    {
        goto L_0x00516057;
    }
L_0x0051605e:
    // 0051605e  be48215500             -mov esi, 0x552148
    cpu.esi = 5579080 /*0x552148*/;
    // 00516063  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00516066  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 0051606c  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0051606f  e87c000000             -call 0x5160f0
    cpu.esp -= 4;
    sub_5160f0(app, cpu);
    if (cpu.terminate) return;
    // 00516074  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00516076  7405                   -je 0x51607d
    if (cpu.flags.zf)
    {
        goto L_0x0051607d;
    }
    // 00516078  be62215500             -mov esi, 0x552162
    cpu.esi = 5579106 /*0x552162*/;
L_0x0051607d:
    // 0051607d  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 00516082  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00516084  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00516086  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00516088  8b1446                 -mov edx, dword ptr [esi + eax*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 0051608b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0051608e  39d3                   +cmp ebx, edx
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
    // 00516090  7201                   -jb 0x516093
    if (cpu.flags.cf)
    {
        goto L_0x00516093;
    }
    // 00516092  40                     -inc eax
    (cpu.eax)++;
L_0x00516093:
    // 00516093  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00516096  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 0051609a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051609c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051609e  43                     -inc ebx
    (cpu.ebx)++;
    // 0051609f  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 005160a2  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005160a5  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 005160aa  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005160ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005160ae  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005160b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005160b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005160b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005160b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
