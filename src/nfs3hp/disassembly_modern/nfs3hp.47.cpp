#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_5089d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005089d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005089d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005089d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005089d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005089d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005089d6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005089d8  8b15c87d5600           -mov edx, dword ptr [0x567dc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668296) /* 0x567dc8 */);
    // 005089de  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005089e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005089e2  7529                   -jne 0x508a0d
    if (!cpu.flags.zf)
    {
        goto L_0x00508a0d;
    }
    // 005089e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005089e6  7532                   -jne 0x508a1a
    if (!cpu.flags.zf)
    {
        goto L_0x00508a1a;
    }
    // 005089e8  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x005089ed:
    // 005089ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005089ef  7535                   -jne 0x508a26
    if (!cpu.flags.zf)
    {
        goto L_0x00508a26;
    }
    // 005089f1  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
L_0x005089f6:
    // 005089f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005089f8  7538                   -jne 0x508a32
    if (!cpu.flags.zf)
    {
        goto L_0x00508a32;
    }
L_0x005089fa:
    // 005089fa  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x005089ff:
    // 005089ff  bdd44e5600             -mov ebp, 0x564ed4
    cpu.ebp = 5656276 /*0x564ed4*/;
    // 00508a04  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00508a06  7436                   -je 0x508a3e
    if (cpu.flags.zf)
    {
        goto L_0x00508a3e;
    }
    // 00508a08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508a0d:
    // 00508a0d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00508a0f  ff15c87d5600           -call dword ptr [0x567dc8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668296) /* 0x567dc8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00508a15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508a1a:
    // 00508a1a  83f8ff                 +cmp eax, -1
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
    // 00508a1d  75ce                   -jne 0x5089ed
    if (!cpu.flags.zf)
    {
        goto L_0x005089ed;
    }
    // 00508a1f  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00508a24  ebc7                   -jmp 0x5089ed
    goto L_0x005089ed;
L_0x00508a26:
    // 00508a26  83feff                 +cmp esi, -1
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
    // 00508a29  75cb                   -jne 0x5089f6
    if (!cpu.flags.zf)
    {
        goto L_0x005089f6;
    }
    // 00508a2b  be00030000             -mov esi, 0x300
    cpu.esi = 768 /*0x300*/;
    // 00508a30  ebc4                   -jmp 0x5089f6
    goto L_0x005089f6;
L_0x00508a32:
    // 00508a32  83fbff                 +cmp ebx, -1
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
    // 00508a35  74c3                   -je 0x5089fa
    if (cpu.flags.zf)
    {
        goto L_0x005089fa;
    }
    // 00508a37  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508a3a  75c3                   -jne 0x5089ff
    if (!cpu.flags.zf)
    {
        goto L_0x005089ff;
    }
    // 00508a3c  ebbc                   -jmp 0x5089fa
    goto L_0x005089fa;
L_0x00508a3e:
    // 00508a3e  e82df7ffff             -call 0x508170
    cpu.esp -= 4;
    sub_508170(app, cpu);
    if (cpu.terminate) return;
    // 00508a43  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508a44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508a45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508a46  68c8f45400             -push 0x54f4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567688 /*0x54f4c8*/;
    cpu.esp -= 4;
    // 00508a4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00508a4d  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508a4f  890de4389f00           -mov dword ptr [0x9f38e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */) = cpu.ecx;
    // 00508a55  8935e8389f00           -mov dword ptr [0x9f38e8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */) = cpu.esi;
    // 00508a5b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508a5c  891dec389f00           -mov dword ptr [0x9f38ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(10434796) /* 0x9f38ec */) = cpu.ebx;
    // 00508a62  881d2c3d9f00           -mov byte ptr [0x9f3d2c], bl
    app->getMemory<x86::reg8>(x86::reg32(10435884) /* 0x9f3d2c */) = cpu.bl;
    // 00508a68  e8e385ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508a6d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00508a70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00508a72  e819f9ffff             -call 0x508390
    cpu.esp -= 4;
    sub_508390(app, cpu);
    if (cpu.terminate) return;
    // 00508a77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508a79  750b                   -jne 0x508a86
    if (!cpu.flags.zf)
    {
        goto L_0x00508a86;
    }
    // 00508a7b  893d64435600           -mov dword ptr [0x564364], edi
    app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */) = cpu.edi;
    // 00508a81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508a85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508a86:
    // 00508a86  8b3dec389f00           -mov edi, dword ptr [0x9f38ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434796) /* 0x9f38ec */);
    // 00508a8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508a8d  a1e8389f00             -mov eax, dword ptr [0x9f38e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */);
    // 00508a92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508a93  8b15e4389f00           -mov edx, dword ptr [0x9f38e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */);
    // 00508a99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508a9a  68ecf45400             -push 0x54f4ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567724 /*0x54f4ec*/;
    cpu.esp -= 4;
    // 00508a9f  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508aa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508aa2  e8a985ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508aa7  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00508aaa  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00508aaf  e87cf4ffff             -call 0x507f30
    cpu.esp -= 4;
    sub_507f30(app, cpu);
    if (cpu.terminate) return;
    // 00508ab4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508ab5  6818f55400             -push 0x54f518
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567768 /*0x54f518*/;
    cpu.esp -= 4;
    // 00508aba  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508abc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508abd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00508abf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00508ac1  e88a85ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508ac6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00508ac9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508acb  7412                   -je 0x508adf
    if (cpu.flags.zf)
    {
        goto L_0x00508adf;
    }
    // 00508acd  e81ef8ffff             -call 0x5082f0
    cpu.esp -= 4;
    sub_5082f0(app, cpu);
    if (cpu.terminate) return;
    // 00508ad2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00508ad4  0f8464ffffff           -je 0x508a3e
    if (cpu.flags.zf)
    {
        goto L_0x00508a3e;
    }
    // 00508ada  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508adb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508adc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508add  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ade  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508adf:
    // 00508adf  68c0f35400             -push 0x54f3c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567424 /*0x54f3c0*/;
    cpu.esp -= 4;
    // 00508ae4  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508ae6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508ae7  e86485ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508aec  8a2590435600           -mov ah, byte ptr [0x564390]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 00508af2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00508af5  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00508af8  7518                   -jne 0x508b12
    if (!cpu.flags.zf)
    {
        goto L_0x00508b12;
    }
    // 00508afa  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00508afc  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00508aff  881590435600           -mov byte ptr [0x564390], dl
    app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */) = cpu.dl;
    // 00508b05  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00508b07  0f8431ffffff           -je 0x508a3e
    if (cpu.flags.zf)
    {
        goto L_0x00508a3e;
    }
    // 00508b0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508b12:
    // 00508b12  891564435600           -mov dword ptr [0x564364], edx
    app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */) = cpu.edx;
    // 00508b18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_508b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508b22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508b23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508b24  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508b27  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00508b29  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508b2b  8b35d0389f00           -mov esi, dword ptr [0x9f38d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 00508b31  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00508b34  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00508b36  7419                   -je 0x508b51
    if (cpu.flags.zf)
    {
        goto L_0x00508b51;
    }
L_0x00508b38:
    // 00508b38  833d6443560000         +cmp dword ptr [0x564364], 0
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
    // 00508b3f  751c                   -jne 0x508b5d
    if (!cpu.flags.zf)
    {
        goto L_0x00508b5d;
    }
L_0x00508b41:
    // 00508b41  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00508b43  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00508b46  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00508b49  83c404                 +add esp, 4
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
    // 00508b4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508b51:
    // 00508b51  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00508b56  e815feffff             -call 0x508970
    cpu.esp -= 4;
    sub_508970(app, cpu);
    if (cpu.terminate) return;
    // 00508b5b  ebdb                   -jmp 0x508b38
    goto L_0x00508b38;
L_0x00508b5d:
    // 00508b5d  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00508b62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508b63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508b65  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00508b67  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00508b6b  e8e031feff             -call 0x4ebd50
    cpu.esp -= 4;
    sub_4ebd50(app, cpu);
    if (cpu.terminate) return;
    // 00508b70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508b72  74cd                   -je 0x508b41
    if (cpu.flags.zf)
    {
        goto L_0x00508b41;
    }
    // 00508b74  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00508b77  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508b7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508b7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_508b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508b80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508b81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508b82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508b83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00508b86  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00508b88  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00508b8a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00508b8c  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00508b90  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00508b94  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508b96  7506                   -jne 0x508b9e
    if (!cpu.flags.zf)
    {
        goto L_0x00508b9e;
    }
    // 00508b98  8b0d8c435600           -mov ecx, dword ptr [0x56438c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
L_0x00508b9e:
    // 00508b9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508ba0  7505                   -jne 0x508ba7
    if (!cpu.flags.zf)
    {
        goto L_0x00508ba7;
    }
    // 00508ba2  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x00508ba7:
    // 00508ba7  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00508baa  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00508bac  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00508bb1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00508bb4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00508bb6  e8517bfdff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 00508bbb  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 00508bc1  c6461eff               -mov byte ptr [esi + 0x1e], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = 255 /*0xff*/;
    // 00508bc5  896e04                 -mov dword ptr [esi + 4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00508bc8  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00508bcb  896e14                 -mov dword ptr [esi + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 00508bce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00508bd2  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00508bd5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508bd7  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00508bda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00508bdc  884e1c                 -mov byte ptr [esi + 0x1c], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cl;
    // 00508bdf  e8ec0c0000             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 00508be4  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 00508be7  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00508beb  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00508bef  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00508bf2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00508bf6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00508bf8  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00508bfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508bfd  e82e0e0000             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 00508c02  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00508c07  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00508c0a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00508c0c  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00508c0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508c11  e81a0e0000             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 00508c16  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00508c19  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00508c1c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508c1e  740d                   -je 0x508c2d
    if (cpu.flags.zf)
    {
        goto L_0x00508c2d;
    }
    // 00508c20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508c22  7409                   -je 0x508c2d
    if (cpu.flags.zf)
    {
        goto L_0x00508c2d;
    }
    // 00508c24  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00508c27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c2a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00508c2d:
    // 00508c2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508c2e  bb3cf55400             -mov ebx, 0x54f53c
    cpu.ebx = 5567804 /*0x54f53c*/;
    // 00508c33  be4cf55400             -mov esi, 0x54f54c
    cpu.esi = 5567820 /*0x54f54c*/;
    // 00508c38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508c39  b829000000             -mov eax, 0x29
    cpu.eax = 41 /*0x29*/;
    // 00508c3e  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00508c44  685cf55400             -push 0x54f55c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567836 /*0x54f55c*/;
    cpu.esp -= 4;
    // 00508c49  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00508c4f  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00508c54  e8b783efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00508c59  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00508c5c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00508c5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508c62  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_508c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508c70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508c71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508c72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508c73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508c76  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00508c78  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00508c7a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00508c7d  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00508c81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508c83  7c69                   -jl 0x508cee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00508cee;
    }
    // 00508c85  3d60090000             +cmp eax, 0x960
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2400 /*0x960*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508c8a  7f62                   -jg 0x508cee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00508cee;
    }
    // 00508c8c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508c8e  7c5e                   -jl 0x508cee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00508cee;
    }
    // 00508c90  81fa40060000           +cmp edx, 0x640
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1600 /*0x640*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508c96  7f56                   -jg 0x508cee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00508cee;
    }
    // 00508c98  83fbff                 +cmp ebx, -1
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
    // 00508c9b  0f8592000000           -jne 0x508d33
    if (!cpu.flags.zf)
    {
        goto L_0x00508d33;
    }
    // 00508ca1  bd2c505600             -mov ebp, 0x56502c
    cpu.ebp = 5656620 /*0x56502c*/;
L_0x00508ca6:
    // 00508ca6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00508ca8  0f85ca000000           -jne 0x508d78
    if (!cpu.flags.zf)
    {
        goto L_0x00508d78;
    }
    // 00508cae  bd3cf55400             -mov ebp, 0x54f53c
    cpu.ebp = 5567804 /*0x54f53c*/;
    // 00508cb3  b894f55400             -mov eax, 0x54f594
    cpu.eax = 5567892 /*0x54f594*/;
    // 00508cb8  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 00508cbd  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00508cc3  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00508cc8  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00508cce  e8ad88fdff             -call 0x4e1580
    cpu.esp -= 4;
    sub_4e1580(app, cpu);
    if (cpu.terminate) return;
    // 00508cd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508cd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508cd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508cd6  68fcf55400             -push 0x54f5fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567996 /*0x54f5fc*/;
    cpu.esp -= 4;
    // 00508cdb  e83083efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00508ce0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00508ce3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508ce5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508ce8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ce9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508cea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ceb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00508cee:
    // 00508cee  6840060000             -push 0x640
    app->getMemory<x86::reg32>(cpu.esp-4) = 1600 /*0x640*/;
    cpu.esp -= 4;
    // 00508cf3  6860090000             -push 0x960
    app->getMemory<x86::reg32>(cpu.esp-4) = 2400 /*0x960*/;
    cpu.esp -= 4;
    // 00508cf8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508cf9  b93cf55400             -mov ecx, 0x54f53c
    cpu.ecx = 5567804 /*0x54f53c*/;
    // 00508cfe  bb94f55400             -mov ebx, 0x54f594
    cpu.ebx = 5567892 /*0x54f594*/;
    // 00508d03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508d04  bd32000000             -mov ebp, 0x32
    cpu.ebp = 50 /*0x32*/;
    // 00508d09  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00508d0f  68a4f55400             -push 0x54f5a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567908 /*0x54f5a4*/;
    cpu.esp -= 4;
    // 00508d14  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00508d1a  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00508d20  e8eb82efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00508d25  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00508d28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508d2a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508d2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d30  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00508d33:
    // 00508d33  83fbfe                 +cmp ebx, -2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508d36  750a                   -jne 0x508d42
    if (!cpu.flags.zf)
    {
        goto L_0x00508d42;
    }
    // 00508d38  bd64505600             -mov ebp, 0x565064
    cpu.ebp = 5656676 /*0x565064*/;
    // 00508d3d  e964ffffff             -jmp 0x508ca6
    goto L_0x00508ca6;
L_0x00508d42:
    // 00508d42  ba3cf55400             -mov edx, 0x54f53c
    cpu.edx = 5567804 /*0x54f53c*/;
    // 00508d47  bd94f55400             -mov ebp, 0x54f594
    cpu.ebp = 5567892 /*0x54f594*/;
    // 00508d4c  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
    // 00508d51  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00508d57  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00508d5c  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00508d61  b8f4f55400             -mov eax, 0x54f5f4
    cpu.eax = 5567988 /*0x54f5f4*/;
    // 00508d66  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00508d6c  e8af88fdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00508d71  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00508d73  e92effffff             -jmp 0x508ca6
    goto L_0x00508ca6;
L_0x00508d78:
    // 00508d78  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00508d7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508d7d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00508d81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508d82  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00508d84  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00508d86  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508d87  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00508d89  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00508d8d  e8eefdffff             -call 0x508b80
    cpu.esp -= 4;
    sub_508b80(app, cpu);
    if (cpu.terminate) return;
    // 00508d92  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00508d94  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508d97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508d9a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_508da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508da4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00508da6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508da8  7505                   -jne 0x508daf
    if (!cpu.flags.zf)
    {
        goto L_0x00508daf;
    }
    // 00508daa  bef44f5600             -mov esi, 0x564ff4
    cpu.esi = 5656564 /*0x564ff4*/;
L_0x00508daf:
    // 00508daf  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00508db2  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00508db5  39ca                   +cmp edx, ecx
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
    // 00508db7  7459                   -je 0x508e12
    if (cpu.flags.zf)
    {
        goto L_0x00508e12;
    }
    // 00508db9  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00508dbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00508dbe  7407                   -je 0x508dc7
    if (cpu.flags.zf)
    {
        goto L_0x00508dc7;
    }
    // 00508dc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00508dc2  e8490d0000             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
L_0x00508dc7:
    // 00508dc7  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00508dca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508dcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508dce  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00508dd1  e85a0c0000             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 00508dd6  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00508dd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508ddb  7535                   -jne 0x508e12
    if (!cpu.flags.zf)
    {
        goto L_0x00508e12;
    }
    // 00508ddd  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00508de0  bd3cf55400             -mov ebp, 0x54f53c
    cpu.ebp = 5567804 /*0x54f53c*/;
    // 00508de5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508de6  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00508de9  b83cf65400             -mov eax, 0x54f63c
    cpu.eax = 5568060 /*0x54f63c*/;
    // 00508dee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508def  ba5e000000             -mov edx, 0x5e
    cpu.edx = 94 /*0x5e*/;
    // 00508df4  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00508dfa  6850f65400             -push 0x54f650
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568080 /*0x54f650*/;
    cpu.esp -= 4;
    // 00508dff  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00508e04  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00508e0a  e80182efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00508e0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00508e12:
    // 00508e12  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00508e15  3b7e0c                 +cmp edi, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508e18  7d03                   -jge 0x508e1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00508e1d;
    }
    // 00508e1a  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00508e1d:
    // 00508e1d  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00508e20  3b6e10                 +cmp ebp, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508e23  7d03                   -jge 0x508e28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00508e28;
    }
    // 00508e25  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x00508e28:
    // 00508e28  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00508e2b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00508e2e  39d0                   +cmp eax, edx
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
    // 00508e30  7e19                   -jle 0x508e4b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00508e4b;
    }
    // 00508e32  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00508e35:
    // 00508e35  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00508e38  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00508e3b  39d8                   +cmp eax, ebx
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
    // 00508e3d  7f18                   -jg 0x508e57
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00508e57;
    }
    // 00508e3f  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00508e42  39f8                   +cmp eax, edi
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
    // 00508e44  7c19                   -jl 0x508e5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00508e5f;
    }
    // 00508e46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508e4b:
    // 00508e4b  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00508e4e  39c8                   +cmp eax, ecx
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
    // 00508e50  7de3                   -jge 0x508e35
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00508e35;
    }
    // 00508e52  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00508e55  ebde                   -jmp 0x508e35
    goto L_0x00508e35;
L_0x00508e57:
    // 00508e57  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00508e5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508e5f:
    // 00508e5f  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00508e62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508e66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_508e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508e72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508e73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00508e75  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00508e78  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508e7a  7529                   -jne 0x508ea5
    if (!cpu.flags.zf)
    {
        goto L_0x00508ea5;
    }
L_0x00508e7c:
    // 00508e7c  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00508e7f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00508e81  740e                   -je 0x508e91
    if (cpu.flags.zf)
    {
        goto L_0x00508e91;
    }
    // 00508e83  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00508e85  e8860c0000             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00508e8a  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
L_0x00508e91:
    // 00508e91  81fa2c505600           +cmp edx, 0x56502c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5656620 /*0x56502c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508e97  7408                   -je 0x508ea1
    if (cpu.flags.zf)
    {
        goto L_0x00508ea1;
    }
    // 00508e99  81fa64505600           +cmp edx, 0x565064
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5656676 /*0x565064*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508e9f  7514                   -jne 0x508eb5
    if (!cpu.flags.zf)
    {
        goto L_0x00508eb5;
    }
L_0x00508ea1:
    // 00508ea1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ea2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ea3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ea4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508ea5:
    // 00508ea5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00508ea7  e8640c0000             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00508eac  c7422c00000000         -mov dword ptr [edx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00508eb3  ebc7                   -jmp 0x508e7c
    goto L_0x00508e7c;
L_0x00508eb5:
    // 00508eb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00508eb7  e8d489fdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00508ebc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ebd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ebe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ebf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_508ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508ec0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508ec1  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00508ec4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508ec6  7502                   -jne 0x508eca
    if (!cpu.flags.zf)
    {
        goto L_0x00508eca;
    }
    // 00508ec8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ec9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508eca:
    // 00508eca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00508ecc  e83f4afeff             -call 0x4ed910
    cpu.esp -= 4;
    sub_4ed910(app, cpu);
    if (cpu.terminate) return;
    // 00508ed1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_508ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508ee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508ee1  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00508ee4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508ee6  7502                   -jne 0x508eea
    if (!cpu.flags.zf)
    {
        goto L_0x00508eea;
    }
    // 00508ee8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ee9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508eea:
    // 00508eea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00508eec  e85f4afeff             -call 0x4ed950
    cpu.esp -= 4;
    sub_4ed950(app, cpu);
    if (cpu.terminate) return;
    // 00508ef1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ef2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_508f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508f00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508f01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508f02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508f03  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00508f06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00508f08  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00508f0a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00508f0c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00508f0e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00508f10  7433                   -je 0x508f45
    if (cpu.flags.zf)
    {
        goto L_0x00508f45;
    }
    // 00508f12  3b1d8c435600           +cmp ebx, dword ptr [0x56438c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508f18  742b                   -je 0x508f45
    if (cpu.flags.zf)
    {
        goto L_0x00508f45;
    }
    // 00508f1a  c705902155003cf55400   -mov dword ptr [0x552190], 0x54f53c
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5567804 /*0x54f53c*/;
    // 00508f24  c7059421550088f65400   -mov dword ptr [0x552194], 0x54f688
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5568136 /*0x54f688*/;
    // 00508f2e  b8d1000000             -mov eax, 0xd1
    cpu.eax = 209 /*0xd1*/;
    // 00508f33  689cf65400             -push 0x54f69c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568156 /*0x54f69c*/;
    cpu.esp -= 4;
    // 00508f38  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00508f3d  e8ce80efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00508f42  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00508f45:
    // 00508f45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00508f47  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00508f4b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508f4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508f4d  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00508f52  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00508f54  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00508f56  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00508f58  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00508f5a  e82145feff             -call 0x4ed480
    cpu.esp -= 4;
    sub_4ed480(app, cpu);
    if (cpu.terminate) return;
    // 00508f5f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00508f61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508f63  750b                   -jne 0x508f70
    if (!cpu.flags.zf)
    {
        goto L_0x00508f70;
    }
L_0x00508f65:
    // 00508f65  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00508f67  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00508f6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508f6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508f6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508f6d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00508f70:
    // 00508f70  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00508f72  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00508f76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508f77  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00508f7b  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00508f7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508f80  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00508f84  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00508f86  e89548feff             -call 0x4ed820
    cpu.esp -= 4;
    sub_4ed820(app, cpu);
    if (cpu.terminate) return;
    // 00508f8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508f8c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00508f90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508f91  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00508f95  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00508f99  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508f9a  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00508f9e  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00508fa2  e8c9fcffff             -call 0x508c70
    cpu.esp -= 4;
    sub_508c70(app, cpu);
    if (cpu.terminate) return;
    // 00508fa7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00508fa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508fab  75b8                   -jne 0x508f65
    if (!cpu.flags.zf)
    {
        goto L_0x00508f65;
    }
    // 00508fad  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00508fb2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00508fb4  e87747feff             -call 0x4ed730
    cpu.esp -= 4;
    sub_4ed730(app, cpu);
    if (cpu.terminate) return;
    // 00508fb9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00508fbb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00508fbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508fbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508fc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508fc1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_508fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508fd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508fd2  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00508fd6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508fd9  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00508fdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00508fdd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00508fdf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00508fe3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508fe4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00508fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508fe9  e806000000             -call 0x508ff4
    cpu.esp -= 4;
    sub_508ff4(app, cpu);
    if (cpu.terminate) return;
    // 00508fee  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00508ff1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ff2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508ff3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_508ff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508ff4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508ff5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508ff6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508ff7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00508ffa  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00508ffe  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00509000  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00509004  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00509008  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050900b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050900f  e808000000             -call 0x50901c
    cpu.esp -= 4;
    sub_50901c(app, cpu);
    if (cpu.terminate) return;
    // 00509014  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509017  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509018  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509019  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050901a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50901c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050901c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050901d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050901e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050901f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00509022  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509024  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00509028  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0050902a  e881520100             -call 0x51e2b0
    cpu.esp -= 4;
    sub_51e2b0(app, cpu);
    if (cpu.terminate) return;
    // 0050902f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509031  7414                   -je 0x509047
    if (cpu.flags.zf)
    {
        goto L_0x00509047;
    }
    // 00509033  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00509038  e84398ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0050903d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00509042  e9fe010000             -jmp 0x509245
    goto L_0x00509245;
L_0x00509047:
    // 00509047  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509049  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050904d  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00509050  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00509054  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509056  e875a40100             -call 0x5234d0
    cpu.esp -= 4;
    sub_5234d0(app, cpu);
    if (cpu.terminate) return;
    // 0050905b  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050905f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00509061  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509063  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00509065  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0050906a  e895a40100             -call 0x523504
    cpu.esp -= 4;
    sub_523504(app, cpu);
    if (cpu.terminate) return;
    // 0050906f  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00509074  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00509078  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050907c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050907f  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00509082  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00509085  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050908a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050908e  833db877560000         +cmp dword ptr [0x5677b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666744) /* 0x5677b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509095  7434                   -je 0x5090cb
    if (cpu.flags.zf)
    {
        goto L_0x005090cb;
    }
    // 00509097  baf0f65400             -mov edx, 0x54f6f0
    cpu.edx = 5568240 /*0x54f6f0*/;
    // 0050909c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050909e  e81d0efeff             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 005090a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005090a5  7524                   -jne 0x5090cb
    if (!cpu.flags.zf)
    {
        goto L_0x005090cb;
    }
    // 005090a7  e844540100             -call 0x51e4f0
    cpu.esp -= 4;
    sub_51e4f0(app, cpu);
    if (cpu.terminate) return;
    // 005090ac  ff1570775600           -call dword ptr [0x567770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666672) /* 0x567770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005090b2  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 005090b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005090b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005090b6  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 005090bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005090bd  ff15b8775600           -call dword ptr [0x5677b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666744) /* 0x5677b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005090c3  83c40c                 +add esp, 0xc
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
    // 005090c6  e92a010000             -jmp 0x5091f5
    goto L_0x005091f5;
L_0x005090cb:
    // 005090cb  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005090cf  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 005090d2  0f8472000000           -je 0x50914a
    if (cpu.flags.zf)
    {
        goto L_0x0050914a;
    }
    // 005090d8  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 005090da  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005090dd  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 005090df  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 005090e2  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005090e6  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 005090ec  a160ae5600             -mov eax, dword ptr [0x56ae60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680736) /* 0x56ae60 */);
    // 005090f1  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005090f5  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 005090f7  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 005090f9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 005090fd  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 00509102  740c                   -je 0x509110
    if (cpu.flags.zf)
    {
        goto L_0x00509110;
    }
    // 00509104  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 00509109  7505                   -jne 0x509110
    if (!cpu.flags.zf)
    {
        goto L_0x00509110;
    }
    // 0050910b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00509110:
    // 00509110  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 00509115  740d                   -je 0x509124
    if (cpu.flags.zf)
    {
        goto L_0x00509124;
    }
    // 00509117  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0050911c  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00509120  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509122  eb37                   -jmp 0x50915b
    goto L_0x0050915b;
L_0x00509124:
    // 00509124  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 00509129  740f                   -je 0x50913a
    if (cpu.flags.zf)
    {
        goto L_0x0050913a;
    }
    // 0050912b  c744241802000000       -mov dword ptr [esp + 0x18], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
    // 00509133  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00509138  eb21                   -jmp 0x50915b
    goto L_0x0050915b;
L_0x0050913a:
    // 0050913a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0050913f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00509144  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00509148  eb11                   -jmp 0x50915b
    goto L_0x0050915b;
L_0x0050914a:
    // 0050914a  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0050914d  7407                   -je 0x509156
    if (cpu.flags.zf)
    {
        goto L_0x00509156;
    }
    // 0050914f  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00509154  eb05                   -jmp 0x50915b
    goto L_0x0050915b;
L_0x00509156:
    // 00509156  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0050915b:
    // 0050915b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050915d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050915e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050915f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00509163  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00509164  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00509168  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509169  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050916d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050916e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050916f  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509176  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00509178  83f8ff                 +cmp eax, -1
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
    // 0050917b  7536                   -jne 0x5091b3
    if (!cpu.flags.zf)
    {
        goto L_0x005091b3;
    }
    // 0050917d  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 00509182  741e                   -je 0x5091a2
    if (cpu.flags.zf)
    {
        goto L_0x005091a2;
    }
    // 00509184  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00509186  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509187  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050918b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050918c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050918e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00509192  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00509193  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00509197  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509198  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509199  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005091a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005091a2:
    // 005091a2  83fbff                 +cmp ebx, -1
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
    // 005091a5  750c                   -jne 0x5091b3
    if (!cpu.flags.zf)
    {
        goto L_0x005091b3;
    }
    // 005091a7  e8487effff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 005091ac  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005091af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005091b3:
    // 005091b3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005091b5  ff1570775600           -call dword ptr [0x567770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666672) /* 0x567770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005091bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005091bd  8b3d94ad5600           -mov edi, dword ptr [0x56ad94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */);
    // 005091c3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005091c5  39f8                   +cmp eax, edi
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
    // 005091c7  721e                   -jb 0x5091e7
    if (cpu.flags.cf)
    {
        goto L_0x005091e7;
    }
    // 005091c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005091ca  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005091d1  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 005091d6  e8a596ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005091db  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005091e0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005091e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005091e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005091e7:
    // 005091e7  e874a30100             -call 0x523560
    cpu.esp -= 4;
    sub_523560(app, cpu);
    if (cpu.terminate) return;
    // 005091ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005091ee  7405                   -je 0x5091f5
    if (cpu.flags.zf)
    {
        goto L_0x005091f5;
    }
    // 005091f0  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x005091f5:
    // 005091f5  83fe02                 +cmp esi, 2
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
    // 005091f8  7505                   -jne 0x5091ff
    if (!cpu.flags.zf)
    {
        goto L_0x005091ff;
    }
    // 005091fa  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 005091fd  eb11                   -jmp 0x509210
    goto L_0x00509210;
L_0x005091ff:
    // 005091ff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509201  7505                   -jne 0x509208
    if (!cpu.flags.zf)
    {
        goto L_0x00509208;
    }
    // 00509203  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00509206  eb08                   -jmp 0x509210
    goto L_0x00509210;
L_0x00509208:
    // 00509208  83fe01                 +cmp esi, 1
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
    // 0050920b  7503                   -jne 0x509210
    if (!cpu.flags.zf)
    {
        goto L_0x00509210;
    }
    // 0050920d  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00509210:
    // 00509210  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 00509215  7403                   -je 0x50921a
    if (cpu.flags.zf)
    {
        goto L_0x0050921a;
    }
    // 00509217  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0050921a:
    // 0050921a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050921c  8a5c241d               -mov bl, byte ptr [esp + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 00509220  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00509222  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 00509225  7407                   -je 0x50922e
    if (cpu.flags.zf)
    {
        goto L_0x0050922e;
    }
    // 00509227  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0050922a  7410                   -je 0x50923c
    if (cpu.flags.zf)
    {
        goto L_0x0050923c;
    }
    // 0050922c  eb0c                   -jmp 0x50923a
    goto L_0x0050923a;
L_0x0050922e:
    // 0050922e  813d6471560000020000   +cmp dword ptr [0x567164], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665124) /* 0x567164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509238  7502                   -jne 0x50923c
    if (!cpu.flags.zf)
    {
        goto L_0x0050923c;
    }
L_0x0050923a:
    // 0050923a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0050923c:
    // 0050923c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050923e  e8f59b0100             -call 0x522e38
    cpu.esp -= 4;
    sub_522e38(app, cpu);
    if (cpu.terminate) return;
    // 00509243  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00509245:
    // 00509245  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00509248  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509249  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050924a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050924b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_509250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509252  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509253  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509254  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509255  ff1578775600           -call dword ptr [0x567778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050925b  8b35a4389f00           -mov esi, dword ptr [0x9f38a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */);
    // 00509261  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509263  7419                   -je 0x50927e
    if (cpu.flags.zf)
    {
        goto L_0x0050927e;
    }
    // 00509265  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00509268  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050926b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0050926d  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 00509273  a3a4389f00             -mov dword ptr [0x9f38a4], eax
    app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */) = cpu.eax;
    // 00509278  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 0050927c  eb4d                   -jmp 0x5092cb
    goto L_0x005092cb;
L_0x0050927e:
    // 0050927e  b9586f5600             -mov ecx, 0x566f58
    cpu.ecx = 5664600 /*0x566f58*/;
    // 00509283  81f960715600           +cmp ecx, 0x567160
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5665120 /*0x567160*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509289  7328                   -jae 0x5092b3
    if (!cpu.flags.cf)
    {
        goto L_0x005092b3;
    }
L_0x0050928b:
    // 0050928b  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 0050928f  7517                   -jne 0x5092a8
    if (!cpu.flags.zf)
    {
        goto L_0x005092a8;
    }
    // 00509291  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00509296  e865e6feff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0050929b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050929d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050929f  7458                   -je 0x5092f9
    if (cpu.flags.zf)
    {
        goto L_0x005092f9;
    }
    // 005092a1  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 005092a6  eb23                   -jmp 0x5092cb
    goto L_0x005092cb;
L_0x005092a8:
    // 005092a8  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 005092ab  81f960715600           +cmp ecx, 0x567160
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5665120 /*0x567160*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005092b1  72d8                   -jb 0x50928b
    if (cpu.flags.cf)
    {
        goto L_0x0050928b;
    }
L_0x005092b3:
    // 005092b3  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 005092b8  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 005092bd  e83ee6feff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005092c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005092c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005092c6  7431                   -je 0x5092f9
    if (cpu.flags.zf)
    {
        goto L_0x005092f9;
    }
    // 005092c8  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x005092cb:
    // 005092cb  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 005092d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005092d2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005092d4  e86773fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 005092d9  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 005092dc  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005092df  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 005092e4  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 005092e7  8935a0389f00           -mov dword ptr [0x9f38a0], esi
    app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */) = cpu.esi;
    // 005092ed  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 005092ef  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005092f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005092f7  eb12                   -jmp 0x50930b
    goto L_0x0050930b;
L_0x005092f9:
    // 005092f9  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 005092fe  e87d95ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00509303  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509309  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050930b:
    // 0050930b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050930c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050930d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050930e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050930f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_509314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509314  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509315  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509316  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509317  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00509319  baa0389f00             -mov edx, 0x9f38a0
    cpu.edx = 10434720 /*0x9f38a0*/;
L_0x0050931e:
    // 0050931e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00509320  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509322  7425                   -je 0x509349
    if (cpu.flags.zf)
    {
        goto L_0x00509349;
    }
    // 00509324  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00509327  39cb                   +cmp ebx, ecx
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
    // 00509329  7404                   -je 0x50932f
    if (cpu.flags.zf)
    {
        goto L_0x0050932f;
    }
    // 0050932b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050932d  ebef                   -jmp 0x50931e
    goto L_0x0050931e;
L_0x0050932f:
    // 0050932f  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00509332  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00509335  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 00509338  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050933a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0050933c  8b15a4389f00           -mov edx, dword ptr [0x9f38a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */);
    // 00509342  a3a4389f00             -mov dword ptr [0x9f38a4], eax
    app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */) = cpu.eax;
    // 00509347  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00509349:
    // 00509349  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050934a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050934b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050934c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_509350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509350  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509351  833da4389f0000         +cmp dword ptr [0x9f38a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509358  7416                   -je 0x509370
    if (cpu.flags.zf)
    {
        goto L_0x00509370;
    }
L_0x0050935a:
    // 0050935a  a1a4389f00             -mov eax, dword ptr [0x9f38a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */);
    // 0050935f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00509361  e88ae6feff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00509366  8915a4389f00           -mov dword ptr [0x9f38a4], edx
    app->getMemory<x86::reg32>(x86::reg32(10434724) /* 0x9f38a4 */) = cpu.edx;
    // 0050936c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050936e  75ea                   -jne 0x50935a
    if (!cpu.flags.zf)
    {
        goto L_0x0050935a;
    }
L_0x00509370:
    // 00509370  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509371  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_509380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509383  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509385  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00509389  7522                   -jne 0x5093ad
    if (!cpu.flags.zf)
    {
        goto L_0x005093ad;
    }
    // 0050938b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050938e  e8cda10100             -call 0x523560
    cpu.esp -= 4;
    sub_523560(app, cpu);
    if (cpu.terminate) return;
    // 00509393  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509395  7416                   -je 0x5093ad
    if (cpu.flags.zf)
    {
        goto L_0x005093ad;
    }
    // 00509397  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0050939a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0050939d  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 005093a0  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 005093a3  7508                   -jne 0x5093ad
    if (!cpu.flags.zf)
    {
        goto L_0x005093ad;
    }
    // 005093a5  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 005093a7  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 005093aa  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x005093ad:
    // 005093ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005093ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005093af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005093b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5093c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005093c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005093c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005093c2  2eff1508455300         -call dword ptr cs:[0x534508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457160) /* 0x534508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005093c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005093ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005093cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5093d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005093d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005093d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005093d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005093d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005093d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005093d5  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 005093db  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005093e1  bd14f75400             -mov ebp, 0x54f714
    cpu.ebp = 5568276 /*0x54f714*/;
    // 005093e6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005093e9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x005093eb:
    // 005093eb  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 005093f2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005093f4  e86f4dfeff             -call 0x4ee168
    cpu.esp -= 4;
    sub_4ee168(app, cpu);
    if (cpu.terminate) return;
    // 005093f9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 005093fe  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00509405  41                     -inc ecx
    (cpu.ecx)++;
    // 00509406  e8e571feff             -call 0x4f05f0
    cpu.esp -= 4;
    sub_4f05f0(app, cpu);
    if (cpu.terminate) return;
    // 0050940b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050940d  74dc                   -je 0x5093eb
    if (cpu.flags.zf)
    {
        goto L_0x005093eb;
    }
    // 0050940f  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00509416  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00509418  e8cb4bfeff             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0050941d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050941f  751b                   -jne 0x50943c
    if (!cpu.flags.zf)
    {
        goto L_0x0050943c;
    }
    // 00509421  e8aaa10100             -call 0x5235d0
    cpu.esp -= 4;
    sub_5235d0(app, cpu);
    if (cpu.terminate) return;
    // 00509426  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509429  740a                   -je 0x509435
    if (cpu.flags.zf)
    {
        goto L_0x00509435;
    }
    // 0050942b  e8a0a10100             -call 0x5235d0
    cpu.esp -= 4;
    sub_5235d0(app, cpu);
    if (cpu.terminate) return;
    // 00509430  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509433  75b6                   -jne 0x5093eb
    if (!cpu.flags.zf)
    {
        goto L_0x005093eb;
    }
L_0x00509435:
    // 00509435  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00509437  e998000000             -jmp 0x5094d4
    goto L_0x005094d4;
L_0x0050943c:
    // 0050943c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050943e  e8bd4cfeff             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 00509443  8a1d60715600           -mov bl, byte ptr [0x567160]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5665120) /* 0x567160 */);
L_0x00509449:
    // 00509449  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050944b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050944d  e8164dfeff             -call 0x4ee168
    cpu.esp -= 4;
    sub_4ee168(app, cpu);
    if (cpu.terminate) return;
    // 00509452  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00509454  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0050945b  e890a10100             -call 0x5235f0
    cpu.esp -= 4;
    sub_5235f0(app, cpu);
    if (cpu.terminate) return;
    // 00509460  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509462  7551                   -jne 0x5094b5
    if (!cpu.flags.zf)
    {
        goto L_0x005094b5;
    }
    // 00509464  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00509466  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00509468  e87b4bfeff             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0050946d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050946f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509471  742a                   -je 0x50949d
    if (cpu.flags.zf)
    {
        goto L_0x0050949d;
    }
    // 00509473  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00509476  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00509479  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 0050947c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0050947f  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 00509482  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509484  881d60715600           -mov byte ptr [0x567160], bl
    app->getMemory<x86::reg8>(x86::reg32(5665120) /* 0x567160 */) = cpu.bl;
    // 0050948a  e8f193ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0050948f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509491  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00509497  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509498  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509499  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050949a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050949b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050949c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050949d:
    // 0050949d  e82ea10100             -call 0x5235d0
    cpu.esp -= 4;
    sub_5235d0(app, cpu);
    if (cpu.terminate) return;
    // 005094a2  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005094a5  750e                   -jne 0x5094b5
    if (!cpu.flags.zf)
    {
        goto L_0x005094b5;
    }
    // 005094a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005094a9  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 005094af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005094b5:
    // 005094b5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 005094ba  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 005094c1  43                     -inc ebx
    (cpu.ebx)++;
    // 005094c2  e82971feff             -call 0x4f05f0
    cpu.esp -= 4;
    sub_4f05f0(app, cpu);
    if (cpu.terminate) return;
    // 005094c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005094c9  0f851cffffff           -jne 0x5093eb
    if (!cpu.flags.zf)
    {
        goto L_0x005093eb;
    }
    // 005094cf  e975ffffff             -jmp 0x509449
    goto L_0x00509449;
L_0x005094d4:
    // 005094d4  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 005094da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005094df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5094e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005094e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005094e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005094e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005094e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005094e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005094e5  803d7882560000         +cmp byte ptr [0x568278], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5669496) /* 0x568278 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005094ec  0f85ab000000           -jne 0x50959d
    if (!cpu.flags.zf)
    {
        goto L_0x0050959d;
    }
    // 005094f2  bb64825600             -mov ebx, 0x568264
    cpu.ebx = 5669476 /*0x568264*/;
    // 005094f7  eb39                   -jmp 0x509532
    goto L_0x00509532;
L_0x005094f9:
    // 005094f9  e8d2550000             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 005094fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509500  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509502  742b                   -je 0x50952f
    if (cpu.flags.zf)
    {
        goto L_0x0050952f;
    }
    // 00509504  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509506  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00509507  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00509509  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050950b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050950d  49                     -dec ecx
    (cpu.ecx)--;
    // 0050950e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00509510  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00509512  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00509514  49                     -dec ecx
    (cpu.ecx)--;
    // 00509515  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00509516  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050951c  7711                   -ja 0x50952f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050952f;
    }
    // 0050951e  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 00509523  b878825600             -mov eax, 0x568278
    cpu.eax = 5669496 /*0x568278*/;
    // 00509528  e8e3a00100             -call 0x523610
    cpu.esp -= 4;
    sub_523610(app, cpu);
    if (cpu.terminate) return;
    // 0050952d  eb0a                   -jmp 0x509539
    goto L_0x00509539;
L_0x0050952f:
    // 0050952f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00509532:
    // 00509532  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00509534  803800                 +cmp byte ptr [eax], 0
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
    // 00509537  75c0                   -jne 0x5094f9
    if (!cpu.flags.zf)
    {
        goto L_0x005094f9;
    }
L_0x00509539:
    // 00509539  803d7882560000         +cmp byte ptr [0x568278], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5669496) /* 0x568278 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00509540  752a                   -jne 0x50956c
    if (!cpu.flags.zf)
    {
        goto L_0x0050956c;
    }
    // 00509542  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00509544  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509546  bf78825600             -mov edi, 0x568278
    cpu.edi = 5669496 /*0x568278*/;
    // 0050954b  e8e071feff             -call 0x4f0730
    cpu.esp -= 4;
    sub_4f0730(app, cpu);
    if (cpu.terminate) return;
    // 00509550  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00509553:
    // 00509553  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00509555  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00509557  3c00                   +cmp al, 0
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
    // 00509559  7410                   -je 0x50956b
    if (cpu.flags.zf)
    {
        goto L_0x0050956b;
    }
    // 0050955b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050955e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509561  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00509564  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509567  3c00                   +cmp al, 0
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
    // 00509569  75e8                   -jne 0x509553
    if (!cpu.flags.zf)
    {
        goto L_0x00509553;
    }
L_0x0050956b:
    // 0050956b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050956c:
    // 0050956c  bf78825600             -mov edi, 0x568278
    cpu.edi = 5669496 /*0x568278*/;
    // 00509571  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00509572  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00509574  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00509576  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509578  49                     -dec ecx
    (cpu.ecx)--;
    // 00509579  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050957b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0050957d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0050957f  49                     -dec ecx
    (cpu.ecx)--;
    // 00509580  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00509581  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00509584  0578825600             -add eax, 0x568278
    (cpu.eax) += x86::reg32(x86::sreg32(5669496 /*0x568278*/));
    // 00509589  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050958b  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050958e  740d                   -je 0x50959d
    if (cpu.flags.zf)
    {
        goto L_0x0050959d;
    }
    // 00509590  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00509593  7408                   -je 0x50959d
    if (cpu.flags.zf)
    {
        goto L_0x0050959d;
    }
    // 00509595  40                     -inc eax
    (cpu.eax)++;
    // 00509596  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 00509599  40                     -inc eax
    (cpu.eax)++;
    // 0050959a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0050959d:
    // 0050959d  b878825600             -mov eax, 0x568278
    cpu.eax = 5669496 /*0x568278*/;
    // 005095a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005095a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005095a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005095a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005095a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005095a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5095b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005095b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005095b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005095b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005095b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005095b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005095b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005095b6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005095b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005095ba  7c08                   -jl 0x5095c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005095c4;
    }
    // 005095bc  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
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
    // 005095c2  7611                   -jbe 0x5095d5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005095d5;
    }
L_0x005095c4:
    // 005095c4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005095c9  e8b292ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005095ce  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005095d3  eb61                   -jmp 0x509636
    goto L_0x00509636;
L_0x005095d5:
    // 005095d5  8b15bcac5600           -mov edx, dword ptr [0x56acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 005095db  8b2dbc775600           -mov ebp, dword ptr [0x5677bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5666748) /* 0x5677bc */);
    // 005095e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005095e3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005095e5  8b3c9a                 -mov edi, dword ptr [edx + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 005095e8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005095ea  741e                   -je 0x50960a
    if (cpu.flags.zf)
    {
        goto L_0x0050960a;
    }
    // 005095ec  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005095f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005095f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005095f6  7412                   -je 0x50960a
    if (cpu.flags.zf)
    {
        goto L_0x0050960a;
    }
    // 005095f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005095fa  ff15b4775600           -call dword ptr [0x5677b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666740) /* 0x5677b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509600  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509602  ff15bc775600           -call dword ptr [0x5677bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666748) /* 0x5677bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509608  eb21                   -jmp 0x50962b
    goto L_0x0050962b;
L_0x0050960a:
    // 0050960a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050960c  751d                   -jne 0x50962b
    if (!cpu.flags.zf)
    {
        goto L_0x0050962b;
    }
    // 0050960e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050960f  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509616  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509618  7511                   -jne 0x50962b
    if (!cpu.flags.zf)
    {
        goto L_0x0050962b;
    }
    // 0050961a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050961f  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00509624  e85792ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00509629  eb09                   -jmp 0x509634
    goto L_0x00509634;
L_0x0050962b:
    // 0050962b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050962d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050962f  e804980100             -call 0x522e38
    cpu.esp -= 4;
    sub_522e38(app, cpu);
    if (cpu.terminate) return;
L_0x00509634:
    // 00509634  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00509636:
    // 00509636  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509637  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509638  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509639  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050963a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050963b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050963c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_509640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509642  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509643  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509644  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0050964a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050964c  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 0050964e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00509650:
    // 00509650  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00509652  3ac2                   +cmp al, dl
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
    // 00509654  7412                   -je 0x509668
    if (cpu.flags.zf)
    {
        goto L_0x00509668;
    }
    // 00509656  3c00                   +cmp al, 0
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
    // 00509658  740c                   -je 0x509666
    if (cpu.flags.zf)
    {
        goto L_0x00509666;
    }
    // 0050965a  46                     -inc esi
    (cpu.esi)++;
    // 0050965b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0050965d  3ac2                   +cmp al, dl
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
    // 0050965f  7407                   -je 0x509668
    if (cpu.flags.zf)
    {
        goto L_0x00509668;
    }
    // 00509661  46                     -inc esi
    (cpu.esi)++;
    // 00509662  3c00                   +cmp al, 0
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
    // 00509664  75ea                   -jne 0x509650
    if (!cpu.flags.zf)
    {
        goto L_0x00509650;
    }
L_0x00509666:
    // 00509666  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00509668:
    // 00509668  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050966a  7520                   -jne 0x50968c
    if (!cpu.flags.zf)
    {
        goto L_0x0050968c;
    }
    // 0050966c  b23f                   -mov dl, 0x3f
    cpu.dl = 63 /*0x3f*/;
    // 0050966e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00509670:
    // 00509670  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00509672  3ac2                   +cmp al, dl
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
    // 00509674  7412                   -je 0x509688
    if (cpu.flags.zf)
    {
        goto L_0x00509688;
    }
    // 00509676  3c00                   +cmp al, 0
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
    // 00509678  740c                   -je 0x509686
    if (cpu.flags.zf)
    {
        goto L_0x00509686;
    }
    // 0050967a  46                     -inc esi
    (cpu.esi)++;
    // 0050967b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0050967d  3ac2                   +cmp al, dl
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
    // 0050967f  7407                   -je 0x509688
    if (cpu.flags.zf)
    {
        goto L_0x00509688;
    }
    // 00509681  46                     -inc esi
    (cpu.esi)++;
    // 00509682  3c00                   +cmp al, 0
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
    // 00509684  75ea                   -jne 0x509670
    if (!cpu.flags.zf)
    {
        goto L_0x00509670;
    }
L_0x00509686:
    // 00509686  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00509688:
    // 00509688  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050968a  7407                   -je 0x509693
    if (cpu.flags.zf)
    {
        goto L_0x00509693;
    }
L_0x0050968c:
    // 0050968c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00509691  eb13                   -jmp 0x5096a6
    goto L_0x005096a6;
L_0x00509693:
    // 00509693  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00509695  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00509696  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509697  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050969e  83f8ff                 +cmp eax, -1
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
    // 005096a1  7403                   -je 0x5096a6
    if (cpu.flags.zf)
    {
        goto L_0x005096a6;
    }
    // 005096a3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x005096a6:
    // 005096a6  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 005096ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005096ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005096ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005096af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005096b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5096c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005096c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005096c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005096c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005096c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005096c4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005096c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005096c9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005096cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005096cd  7c08                   -jl 0x5096d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005096d7;
    }
    // 005096cf  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
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
    // 005096d5  7614                   -jbe 0x5096eb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005096eb;
    }
L_0x005096d7:
    // 005096d7  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005096dc  e89f91ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005096e1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005096e6  e9b8000000             -jmp 0x5097a3
    goto L_0x005097a3;
L_0x005096eb:
    // 005096eb  8b2dbcac5600           -mov ebp, dword ptr [0x56acbc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 005096f1  8b6cb500               -mov ebp, dword ptr [ebp + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 005096f5  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005096fb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005096fd  e8de960100             -call 0x522de0
    cpu.esp -= 4;
    sub_522de0(app, cpu);
    if (cpu.terminate) return;
    // 00509702  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00509704  7428                   -je 0x50972e
    if (cpu.flags.zf)
    {
        goto L_0x0050972e;
    }
    // 00509706  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00509708  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050970a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050970c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050970d  2eff15f0455300         -call dword ptr cs:[0x5345f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457392) /* 0x5345f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509714  83f8ff                 +cmp eax, -1
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
    // 00509717  7515                   -jne 0x50972e
    if (!cpu.flags.zf)
    {
        goto L_0x0050972e;
    }
    // 00509719  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050971b  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509721  e8ce78ffff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00509726  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509729  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050972a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050972b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050972c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050972d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050972e:
    // 0050972e  833ddc77560000         +cmp dword ptr [0x5677dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666780) /* 0x5677dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509735  7428                   -je 0x50975f
    if (cpu.flags.zf)
    {
        goto L_0x0050975f;
    }
    // 00509737  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509739  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050973f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509741  741c                   -je 0x50975f
    if (cpu.flags.zf)
    {
        goto L_0x0050975f;
    }
    // 00509743  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00509745  ff15dc775600           -call dword ptr [0x5677dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666780) /* 0x5677dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050974b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050974d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050974f  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509755  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509757  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050975a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050975b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050975c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050975d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050975e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050975f:
    // 0050975f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00509761  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00509765  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00509766  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509767  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509768  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509769  2eff1540465300         -call dword ptr cs:[0x534640]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457472) /* 0x534640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509770  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509772  7515                   -jne 0x509789
    if (!cpu.flags.zf)
    {
        goto L_0x00509789;
    }
    // 00509774  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509776  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050977c  e87378ffff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00509781  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509784  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509785  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509786  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509787  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509788  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509789:
    // 00509789  3b1c24                 +cmp ebx, dword ptr [esp]
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
    // 0050978c  740a                   -je 0x509798
    if (cpu.flags.zf)
    {
        goto L_0x00509798;
    }
    // 0050978e  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00509793  e8e890ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
L_0x00509798:
    // 00509798  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050979a  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005097a0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x005097a3:
    // 005097a3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005097a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005097a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005097a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005097a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005097aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5097b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005097b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005097b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005097b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005097b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005097b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005097b5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005097b7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005097ba  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005097c0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005097c3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005097c6  83f901                 +cmp ecx, 1
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
    // 005097c9  741e                   -je 0x5097e9
    if (cpu.flags.zf)
    {
        goto L_0x005097e9;
    }
    // 005097cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005097cd  7413                   -je 0x5097e2
    if (cpu.flags.zf)
    {
        goto L_0x005097e2;
    }
    // 005097cf  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005097d2  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005097d8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005097dd  e9dc000000             -jmp 0x5098be
    goto L_0x005098be;
L_0x005097e2:
    // 005097e2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x005097e9:
    // 005097e9  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 005097ed  7522                   -jne 0x509811
    if (!cpu.flags.zf)
    {
        goto L_0x00509811;
    }
    // 005097ef  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005097f4  e88790ffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005097f9  804a0c20               -or byte ptr [edx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 005097fd  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00509800  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509806  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050980b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050980c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050980d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050980e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050980f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509810  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509811:
    // 00509811  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00509814  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00509818  7507                   -jne 0x509821
    if (!cpu.flags.zf)
    {
        goto L_0x00509821;
    }
    // 0050981a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050981c  e89f91ffff             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x00509821:
    // 00509821  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00509826  83fb0a                 +cmp ebx, 0xa
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
    // 00509829  7547                   -jne 0x509872
    if (!cpu.flags.zf)
    {
        goto L_0x00509872;
    }
    // 0050982b  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050982e  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 00509833  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00509835  753b                   -jne 0x509872
    if (!cpu.flags.zf)
    {
        goto L_0x00509872;
    }
    // 00509837  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0050983b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0050983d  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00509840  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00509842  45                     -inc ebp
    (cpu.ebp)++;
    // 00509843  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00509846  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00509848  40                     -inc eax
    (cpu.eax)++;
    // 00509849  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0050984c  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050984f  39f0                   +cmp eax, esi
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
    // 00509851  751f                   -jne 0x509872
    if (!cpu.flags.zf)
    {
        goto L_0x00509872;
    }
    // 00509853  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509855  e8068fffff             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 0050985a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050985c  7414                   -je 0x509872
    if (cpu.flags.zf)
    {
        goto L_0x00509872;
    }
    // 0050985e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00509861  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00509867  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050986c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050986d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050986e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050986f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509870  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509871  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509872:
    // 00509872  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00509876  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00509878  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0050987a  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050987c  47                     -inc edi
    (cpu.edi)++;
    // 0050987d  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00509880  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00509882  45                     -inc ebp
    (cpu.ebp)++;
    // 00509883  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00509886  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00509889  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 0050988b  7505                   -jne 0x509892
    if (!cpu.flags.zf)
    {
        goto L_0x00509892;
    }
    // 0050988d  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
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
    // 00509890  751f                   -jne 0x5098b1
    if (!cpu.flags.zf)
    {
        goto L_0x005098b1;
    }
L_0x00509892:
    // 00509892  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509894  e8c78effff             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 00509899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050989b  7414                   -je 0x5098b1
    if (cpu.flags.zf)
    {
        goto L_0x005098b1;
    }
    // 0050989d  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005098a0  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005098a6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005098ab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005098b1:
    // 005098b1  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005098b4  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005098ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005098bc  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x005098be:
    // 005098be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5098d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005098d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005098d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005098d3  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005098d6  7313                   -jae 0x5098eb
    if (!cpu.flags.cf)
    {
        goto L_0x005098eb;
    }
    // 005098d8  83f804                 +cmp eax, 4
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
    // 005098db  7333                   -jae 0x509910
    if (!cpu.flags.cf)
    {
        goto L_0x00509910;
    }
    // 005098dd  83f801                 +cmp eax, 1
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
    // 005098e0  7505                   -jne 0x5098e7
    if (!cpu.flags.zf)
    {
        goto L_0x005098e7;
    }
    // 005098e2  ba79000000             -mov edx, 0x79
    cpu.edx = 121 /*0x79*/;
L_0x005098e7:
    // 005098e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005098e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005098eb:
    // 005098eb  763c                   -jbe 0x509929
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509929;
    }
    // 005098ed  83f818                 +cmp eax, 0x18
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
    // 005098f0  730e                   -jae 0x509900
    if (!cpu.flags.cf)
    {
        goto L_0x00509900;
    }
    // 005098f2  83f810                 +cmp eax, 0x10
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
    // 005098f5  75f0                   -jne 0x5098e7
    if (!cpu.flags.zf)
    {
        goto L_0x005098e7;
    }
    // 005098f7  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 005098fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005098fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005098ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509900:
    // 00509900  7630                   -jbe 0x509932
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509932;
    }
    // 00509902  83f820                 +cmp eax, 0x20
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
    // 00509905  75e0                   -jne 0x5098e7
    if (!cpu.flags.zf)
    {
        goto L_0x005098e7;
    }
    // 00509907  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 0050990c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050990e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050990f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509910:
    // 00509910  760e                   -jbe 0x509920
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509920;
    }
    // 00509912  83f808                 +cmp eax, 8
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
    // 00509915  75d0                   -jne 0x5098e7
    if (!cpu.flags.zf)
    {
        goto L_0x005098e7;
    }
    // 00509917  ba7b000000             -mov edx, 0x7b
    cpu.edx = 123 /*0x7b*/;
    // 0050991c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050991e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050991f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509920:
    // 00509920  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 00509925  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509927  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509928  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509929:
    // 00509929  ba7e000000             -mov edx, 0x7e
    cpu.edx = 126 /*0x7e*/;
    // 0050992e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509930  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509931  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509932:
    // 00509932  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00509937  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509939  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050993a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_509940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509943  8b157c835600           -mov edx, dword ptr [0x56837c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669756) /* 0x56837c */);
    // 00509949  81facc000000           +cmp edx, 0xcc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050994f  7c36                   -jl 0x509987
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509987;
    }
L_0x00509951:
    // 00509951  833d8083560000         +cmp dword ptr [0x568380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509958  7460                   -je 0x5099ba
    if (cpu.flags.zf)
    {
        goto L_0x005099ba;
    }
L_0x0050995a:
    // 0050995a  8b157c835600           -mov edx, dword ptr [0x56837c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669756) /* 0x56837c */);
    // 00509960  a180835600             -mov eax, dword ptr [0x568380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
    // 00509965  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00509968  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0050996b  8b157c835600           -mov edx, dword ptr [0x56837c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669756) /* 0x56837c */);
    // 00509971  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00509978  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050997b  891d10a8a000           -mov dword ptr [0xa0a810], ebx
    app->getMemory<x86::reg32>(x86::reg32(10528784) /* 0xa0a810 */) = cpu.ebx;
    // 00509981  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00509983  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509984  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509985  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509986  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509987:
    // 00509987  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509988  b918f75400             -mov ecx, 0x54f718
    cpu.ecx = 5568280 /*0x54f718*/;
    // 0050998d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050998e  bb24f75400             -mov ebx, 0x54f724
    cpu.ebx = 5568292 /*0x54f724*/;
    // 00509993  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 00509998  682cf75400             -push 0x54f72c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568300 /*0x54f72c*/;
    cpu.esp -= 4;
    // 0050999d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 005099a3  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005099a9  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 005099af  e85c76efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005099b4  83c408                 +add esp, 8
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
    // 005099b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005099b8  eb97                   -jmp 0x509951
    goto L_0x00509951;
L_0x005099ba:
    // 005099ba  b818f75400             -mov eax, 0x54f718
    cpu.eax = 5568280 /*0x54f718*/;
    // 005099bf  ba24f75400             -mov edx, 0x54f724
    cpu.edx = 5568292 /*0x54f724*/;
    // 005099c4  b915000000             -mov ecx, 0x15
    cpu.ecx = 21 /*0x15*/;
    // 005099c9  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 005099cf  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005099d4  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005099da  8b157c835600           -mov edx, dword ptr [0x56837c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669756) /* 0x56837c */);
    // 005099e0  b870f75400             -mov eax, 0x54f770
    cpu.eax = 5568368 /*0x54f770*/;
    // 005099e5  c1e202                 +shl edx, 2
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
    // 005099e8  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 005099ee  e82d7cfdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 005099f3  a380835600             -mov dword ptr [0x568380], eax
    app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */) = cpu.eax;
    // 005099f8  e95dffffff             -jmp 0x50995a
    goto L_0x0050995a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_509a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509a00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509a01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509a02  8b1580835600           -mov edx, dword ptr [0x568380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
    // 00509a08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00509a0a  750b                   -jne 0x509a17
    if (!cpu.flags.zf)
    {
        goto L_0x00509a17;
    }
    // 00509a0c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509a0e  890d80835600           -mov dword ptr [0x568380], ecx
    app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */) = cpu.ecx;
    // 00509a14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509a15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509a16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509a17:
    // 00509a17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509a19  e8727efdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00509a1e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509a20  890d80835600           -mov dword ptr [0x568380], ecx
    app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */) = cpu.ecx;
    // 00509a26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509a27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509a28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_509a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509a31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509a32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509a33  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00509a36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509a38  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00509a3b  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00509a3f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00509a41  a180835600             -mov eax, dword ptr [0x568380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
    // 00509a46  8b1510a8a000           -mov edx, dword ptr [0xa0a810]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528784) /* 0xa0a810 */);
    // 00509a4c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509a4e  39d0                   +cmp eax, edx
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
    // 00509a50  7335                   -jae 0x509a87
    if (!cpu.flags.cf)
    {
        goto L_0x00509a87;
    }
    // 00509a52  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00509a56  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00509a59  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 00509a5b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00509a5d:
    // 00509a5d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00509a5f  39f9                   +cmp ecx, edi
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
    // 00509a61  7c14                   -jl 0x509a77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509a77;
    }
    // 00509a63  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00509a67  0f8678000000           -jbe 0x509ae5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509ae5;
    }
    // 00509a6d  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509a70  7505                   -jne 0x509a77
    if (!cpu.flags.zf)
    {
        goto L_0x00509a77;
    }
    // 00509a72  3b500c                 +cmp edx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509a75  7462                   -je 0x509ad9
    if (cpu.flags.zf)
    {
        goto L_0x00509ad9;
    }
L_0x00509a77:
    // 00509a77  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00509a7a  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00509a7d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00509a7f  3b0510a8a000           +cmp eax, dword ptr [0xa0a810]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10528784) /* 0xa0a810 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509a85  72d6                   -jb 0x509a5d
    if (cpu.flags.cf)
    {
        goto L_0x00509a5d;
    }
L_0x00509a87:
    // 00509a87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509a89  0f8473000000           -je 0x509b02
    if (cpu.flags.zf)
    {
        goto L_0x00509b02;
    }
    // 00509a8f  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00509a92  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00509a94  39d0                   +cmp eax, edx
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
    // 00509a96  7d55                   -jge 0x509aed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00509aed;
    }
    // 00509a98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00509a9a:
    // 00509a9a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509a9d  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00509aa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509aa2  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00509aa8  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509aab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00509aad  7e21                   -jle 0x509ad0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509ad0;
    }
    // 00509aaf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00509ab1:
    // 00509ab1  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00509ab5  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00509ab7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509aba  40                     -inc eax
    (cpu.eax)++;
    // 00509abb  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00509abd  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00509ac0  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00509ac3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00509ac5  39f8                   +cmp eax, edi
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
    // 00509ac7  7ce8                   -jl 0x509ab1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509ab1;
    }
    // 00509ac9  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509acf  90                     -nop 
    ;
L_0x00509ad0:
    // 00509ad0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00509ad2:
    // 00509ad2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00509ad5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ad6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ad7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ad8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509ad9:
    // 00509ad9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00509adc  83c008                 +add eax, 8
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
    // 00509adf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00509ae0  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00509ae3  ebed                   -jmp 0x509ad2
    goto L_0x00509ad2;
L_0x00509ae5:
    // 00509ae5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509ae7  758e                   -jne 0x509a77
    if (!cpu.flags.zf)
    {
        goto L_0x00509a77;
    }
    // 00509ae9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00509aeb  eb8a                   -jmp 0x509a77
    goto L_0x00509a77;
L_0x00509aed:
    // 00509aed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509aef  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00509af1  c744bb0c00000000       -mov dword ptr [ebx + edi*4 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.edi * 4) = 0 /*0x0*/;
    // 00509af9  83ea02                 +sub edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00509afc  8954bb08               -mov dword ptr [ebx + edi*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edi * 4) = cpu.edx;
    // 00509b00  eb98                   -jmp 0x509a9a
    goto L_0x00509a9a;
L_0x00509b02:
    // 00509b02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509b04  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00509b07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_509b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509b13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509b14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509b15  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509b17  8d48f8                 -lea ecx, [eax - 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00509b1a  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00509b1d  4a                     -dec edx
    (cpu.edx)--;
    // 00509b1e  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00509b21  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00509b23  7606                   -jbe 0x509b2b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509b2b;
    }
L_0x00509b25:
    // 00509b25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509b2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509b2b:
    // 00509b2b  8b1580835600           -mov edx, dword ptr [0x568380]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
    // 00509b31  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509b33  39ca                   +cmp edx, ecx
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
    // 00509b35  7319                   -jae 0x509b50
    if (!cpu.flags.cf)
    {
        goto L_0x00509b50;
    }
L_0x00509b37:
    // 00509b37  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00509b39  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509b3c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00509b3f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00509b41  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509b43  39ca                   +cmp edx, ecx
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
    // 00509b45  72f0                   -jb 0x509b37
    if (cpu.flags.cf)
    {
        goto L_0x00509b37;
    }
    // 00509b47  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509b4d  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x00509b50:
    // 00509b50  7430                   -je 0x509b82
    if (cpu.flags.zf)
    {
        goto L_0x00509b82;
    }
    // 00509b52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509b53  be18f75400             -mov esi, 0x54f718
    cpu.esi = 5568280 /*0x54f718*/;
    // 00509b58  bf78f75400             -mov edi, 0x54f778
    cpu.edi = 5568376 /*0x54f778*/;
    // 00509b5d  bd71000000             -mov ebp, 0x71
    cpu.ebp = 113 /*0x71*/;
    // 00509b62  6884f75400             -push 0x54f784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568388 /*0x54f784*/;
    cpu.esp -= 4;
    // 00509b67  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00509b6d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00509b73  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00509b79  e89274efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00509b7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509b81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00509b82:
    // 00509b82  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00509b84  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509b87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00509b8a  8b0d10a8a000           -mov ecx, dword ptr [0xa0a810]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10528784) /* 0xa0a810 */);
    // 00509b90  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509b92  39c8                   +cmp eax, ecx
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
    // 00509b94  7306                   -jae 0x509b9c
    if (!cpu.flags.cf)
    {
        goto L_0x00509b9c;
    }
    // 00509b96  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00509b9a  761b                   -jbe 0x509bb7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00509bb7;
    }
L_0x00509b9c:
    // 00509b9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509b9e  7485                   -je 0x509b25
    if (cpu.flags.zf)
    {
        goto L_0x00509b25;
    }
    // 00509ba0  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00509ba4  0f877bffffff           -ja 0x509b25
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00509b25;
    }
    // 00509baa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00509bac  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509baf  0103                   -add dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509bb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bb2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509bb7:
    // 00509bb7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00509bb9  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00509bbb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509bbe  01c7                   +add edi, eax
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
    // 00509bc0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00509bc2  ebd8                   -jmp 0x509b9c
    goto L_0x00509b9c;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_509bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509bd2  89157c835600           -mov dword ptr [0x56837c], edx
    app->getMemory<x86::reg32>(x86::reg32(5669756) /* 0x56837c */) = cpu.edx;
    // 00509bd8  a380835600             -mov dword ptr [0x568380], eax
    app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */) = cpu.eax;
    // 00509bdd  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00509be4  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00509beb  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00509bee  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509bf1  891d10a8a000           -mov dword ptr [0xa0a810], ebx
    app->getMemory<x86::reg32>(x86::reg32(10528784) /* 0xa0a810 */) = cpu.ebx;
    // 00509bf7  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00509bf9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_509c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00509c01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00509c03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509c04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c06  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00509c08:
    // 00509c08  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00509c0a  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00509c0d  8b0485c0f59e00         -mov eax, dword ptr [eax*4 + 0x9ef5c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 00509c14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509c16  7410                   -je 0x509c28
    if (cpu.flags.zf)
    {
        goto L_0x00509c28;
    }
    // 00509c18  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00509c1b:
    // 00509c1b  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00509c1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00509c20  7513                   -jne 0x509c35
    if (!cpu.flags.zf)
    {
        goto L_0x00509c35;
    }
L_0x00509c22:
    // 00509c22  f64003c0               +test byte ptr [eax + 3], 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 192 /*0xc0*/));
    // 00509c26  741f                   -je 0x509c47
    if (cpu.flags.zf)
    {
        goto L_0x00509c47;
    }
L_0x00509c28:
    // 00509c28  46                     -inc esi
    (cpu.esi)++;
    // 00509c29  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509c2c  7eda                   -jle 0x509c08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509c08;
    }
    // 00509c2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509c30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509c35:
    // 00509c35  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00509c38  39d1                   +cmp ecx, edx
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
    // 00509c3a  72df                   -jb 0x509c1b
    if (cpu.flags.cf)
    {
        goto L_0x00509c1b;
    }
    // 00509c3c  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00509c3f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509c41  39d9                   +cmp ecx, ebx
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
    // 00509c43  73d6                   -jae 0x509c1b
    if (!cpu.flags.cf)
    {
        goto L_0x00509c1b;
    }
    // 00509c45  ebdb                   -jmp 0x509c22
    goto L_0x00509c22;
L_0x00509c47:
    // 00509c47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00509c49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509c4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_509c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c50  43                     -inc ebx
    (cpu.ebx)++;
    // 00509c51  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00509c53  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509c59  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00509c5f  90                     -nop 
    ;
    // 00509c60  e98b08feff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509c70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509c71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509c72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509c73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c75  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509c77  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00509c79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509c7b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509c7d  7e2d                   -jle 0x509cac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509cac;
    }
    // 00509c7f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00509c81:
    // 00509c81  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509c83  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509c85  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00509c87  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00509c89  7425                   -je 0x509cb0
    if (cpu.flags.zf)
    {
        goto L_0x00509cb0;
    }
    // 00509c8b  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00509c8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509c8f  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509c92  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00509c94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509c96  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00509c98  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x00509c9b:
    // 00509c9b  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509c9d  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00509c9f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509ca1  42                     -inc edx
    (cpu.edx)++;
    // 00509ca2  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509ca4  40                     -inc eax
    (cpu.eax)++;
    // 00509ca5  881c31                 -mov byte ptr [ecx + esi], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 00509ca8  39f8                   +cmp eax, edi
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
    // 00509caa  7cd5                   -jl 0x509c81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509c81;
    }
L_0x00509cac:
    // 00509cac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509caf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509cb0:
    // 00509cb0  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00509cb2  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00509cb5  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00509cb7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509cbd  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509cc0  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00509cc6  ebd3                   -jmp 0x509c9b
    goto L_0x00509c9b;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_509cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509cd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509cd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509cd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509cd3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509cd5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509cd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509cd9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509cdb  7e1e                   -jle 0x509cfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509cfb;
    }
L_0x00509cdd:
    // 00509cdd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509cdf  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00509ce1  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00509ce3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00509ce5  7418                   -je 0x509cff
    if (cpu.flags.zf)
    {
        goto L_0x00509cff;
    }
    // 00509ce7  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00509ce9  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509cef  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00509cf2  42                     -inc edx
    (cpu.edx)++;
    // 00509cf3  40                     -inc eax
    (cpu.eax)++;
    // 00509cf4  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00509cf7  39f0                   +cmp eax, esi
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
    // 00509cf9  7ce2                   -jl 0x509cdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509cdd;
    }
L_0x00509cfb:
    // 00509cfb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509cfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509cff:
    // 00509cff  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00509d01  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00509d04  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00509d0a  42                     -inc edx
    (cpu.edx)++;
    // 00509d0b  40                     -inc eax
    (cpu.eax)++;
    // 00509d0c  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00509d0f  39f0                   +cmp eax, esi
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
    // 00509d11  7cca                   -jl 0x509cdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509cdd;
    }
    // 00509d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_509d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509d21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509d22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509d23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509d24  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509d27  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509d29  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509d2b  8b1dc0505600           -mov ebx, dword ptr [0x5650c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 00509d31  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509d33  7563                   -jne 0x509d98
    if (!cpu.flags.zf)
    {
        goto L_0x00509d98;
    }
    // 00509d35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509d37  7e57                   -jle 0x509d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509d90;
    }
L_0x00509d39:
    // 00509d39  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00509d3c  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00509d41  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509d43  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00509d46  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509d49  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00509d4d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509d4f  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00509d52  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00509d55  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509d58  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00509d5c  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00509d60  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00509d64  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00509d67  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00509d6a  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00509d70  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00509d73  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00509d75  42                     -inc edx
    (cpu.edx)++;
    // 00509d76  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00509d78  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509d7b  e8e059feff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00509d80  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00509d84  43                     -inc ebx
    (cpu.ebx)++;
    // 00509d85  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00509d89  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00509d8c  39f3                   +cmp ebx, esi
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
    // 00509d8e  7ca9                   -jl 0x509d39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509d39;
    }
L_0x00509d90:
    // 00509d90  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509d93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509d97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509d98:
    // 00509d98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509d9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00509d9c  7ef2                   -jle 0x509d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509d90;
    }
L_0x00509d9e:
    // 00509d9e  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00509da1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00509da6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509da8  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00509dab  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509dae  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00509db1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00509db3  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00509db6  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509db9  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00509dbc  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00509dc0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00509dc3  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00509dc5  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00509dc8  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 00509dcb  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00509dcd  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00509dd1  8b3dc0505600           -mov edi, dword ptr [0x5650c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 00509dd7  42                     -inc edx
    (cpu.edx)++;
    // 00509dd8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509ddb  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 00509dde  43                     -inc ebx
    (cpu.ebx)++;
    // 00509ddf  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00509de2  39f3                   +cmp ebx, esi
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
    // 00509de4  7cb8                   -jl 0x509d9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509d9e;
    }
    // 00509de6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00509de9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509dea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509deb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509dec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_509df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509df1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509df2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509df3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509df4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509df6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00509df8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509dfa  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509dfc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509dfe  7e1b                   -jle 0x509e1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509e1b;
    }
L_0x00509e00:
    // 00509e00  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00509e02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509e04  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509e0a  7314                   -jae 0x509e20
    if (!cpu.flags.cf)
    {
        goto L_0x00509e20;
    }
L_0x00509e0c:
    // 00509e0c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509e0f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509e12  47                     -inc edi
    (cpu.edi)++;
    // 00509e13  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00509e17  39ef                   +cmp edi, ebp
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
    // 00509e19  7ce5                   -jl 0x509e00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509e00;
    }
L_0x00509e1b:
    // 00509e1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509e1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509e20:
    // 00509e20  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00509e22  7425                   -je 0x509e49
    if (cpu.flags.zf)
    {
        goto L_0x00509e49;
    }
    // 00509e24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e26  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509e2c  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00509e2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509e31  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509e34  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00509e3a  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00509e3d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509e40  01c3                   +add ebx, eax
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
    // 00509e42  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00509e49:
    // 00509e49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e4b  ebbf                   -jmp 0x509e0c
    goto L_0x00509e0c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_509e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509e52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509e53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509e54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509e56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509e58  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509e5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509e5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509e5e  7e40                   -jle 0x509ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509ea0;
    }
L_0x00509e60:
    // 00509e60  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00509e62  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00509e64  7425                   -je 0x509e8b
    if (cpu.flags.zf)
    {
        goto L_0x00509e8b;
    }
    // 00509e66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509e68  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509e6e  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00509e71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509e73  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509e76  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00509e7c  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00509e7f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509e82  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509e84  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00509e8b:
    // 00509e8b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509e8e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509e91  47                     -inc edi
    (cpu.edi)++;
    // 00509e92  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509e96  39ef                   +cmp edi, ebp
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
    // 00509e98  7cc6                   -jl 0x509e60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509e60;
    }
    // 00509e9a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509ea0:
    // 00509ea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ea4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509eb0  01db                   +add ebx, ebx
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
    // 00509eb2  e93906feff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_509ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509ec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509ec1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509ec2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00509ec4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509ec6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509ec8  7e16                   -jle 0x509ee0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509ee0;
    }
L_0x00509eca:
    // 00509eca  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509ecd  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00509ed0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509ed3  41                     -inc ecx
    (cpu.ecx)++;
    // 00509ed4  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509ed8  39f1                   +cmp ecx, esi
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
    // 00509eda  7cee                   -jl 0x509eca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509eca;
    }
    // 00509edc  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509ee0:
    // 00509ee0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ee1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509ee2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_509ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509ef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509ef2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509ef3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509ef4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00509ef6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00509ef8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509efa  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509efc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509efe  7e1b                   -jle 0x509f1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509f1b;
    }
L_0x00509f00:
    // 00509f00  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00509f02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00509f04  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00509f0a  7314                   -jae 0x509f20
    if (!cpu.flags.cf)
    {
        goto L_0x00509f20;
    }
L_0x00509f0c:
    // 00509f0c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509f0f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509f12  47                     -inc edi
    (cpu.edi)++;
    // 00509f13  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00509f17  39ef                   +cmp edi, ebp
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
    // 00509f19  7ce5                   -jl 0x509f00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509f00;
    }
L_0x00509f1b:
    // 00509f1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00509f20:
    // 00509f20  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f22  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509f28  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00509f2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509f2d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509f30  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00509f36  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00509f39  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509f3c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509f3e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509f40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f42  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00509f45  75c5                   -jne 0x509f0c
    if (!cpu.flags.zf)
    {
        goto L_0x00509f0c;
    }
    // 00509f47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00509f4c  ebbe                   -jmp 0x509f0c
    goto L_0x00509f0c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_509f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509f50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509f51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00509f52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509f53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00509f54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00509f56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00509f58  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00509f5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00509f5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509f5e  7e40                   -jle 0x509fa0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00509fa0;
    }
L_0x00509f60:
    // 00509f60  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00509f62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00509f64  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00509f6a  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00509f6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00509f6f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00509f72  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00509f78  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00509f7b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00509f7e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00509f80  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00509f82  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00509f85  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509f88  47                     -inc edi
    (cpu.edi)++;
    // 00509f89  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00509f8d  39ef                   +cmp edi, ebp
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
    // 00509f8f  7ccf                   -jl 0x509f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509f60;
    }
    // 00509f91  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00509f97  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00509f9d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00509fa0:
    // 00509fa0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00509fa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_509fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00509fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00509fb1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00509fb4  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00509fb8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00509fba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00509fbc  7e51                   -jle 0x50a00f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a00f;
    }
    // 00509fbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00509fbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00509fc0:
    // 00509fc0  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00509fc4  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00509fc8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509fca  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00509fcd  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00509fd0  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00509fd3  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 00509fd6  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00509fda  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 00509fdd  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00509fe0  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00509fe3  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00509fe5  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00509fe9  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00509fec  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00509fef  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00509ff3  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00509ff5  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00509ff9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00509ffc  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00509ffe  41                     -inc ecx
    (cpu.ecx)++;
    // 00509fff  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 0050a002  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a006  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a009  39f1                   +cmp ecx, esi
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
    // 0050a00b  7cb3                   -jl 0x509fc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00509fc0;
    }
    // 0050a00d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a00e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a00f:
    // 0050a00f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a012  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_50a020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a022  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a024  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a027  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a029  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a02c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0050a02f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a031  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a033  7e4f                   -jle 0x50a084
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a084;
    }
L_0x0050a035:
    // 0050a035  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a038  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a03e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a043  39e8                   +cmp eax, ebp
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
    // 0050a045  7445                   -je 0x50a08c
    if (cpu.flags.zf)
    {
        goto L_0x0050a08c;
    }
    // 0050a047  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a049  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a04b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050a04d  c1ff0c                 -sar edi, 0xc
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (12 /*0xc*/ % 32));
    // 0050a050  c1fe07                 -sar esi, 7
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (7 /*0x7*/ % 32));
    // 0050a053  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a056  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a059  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050a05d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a05f  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a062  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050a065  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0050a068  80ccf0                 -or ah, 0xf0
    cpu.ah |= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0050a06b  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a06d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a071  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a073  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
L_0x0050a076:
    // 0050a076  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0050a079  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a07c  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a07d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a080  39fb                   +cmp ebx, edi
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
    // 0050a082  7cb1                   -jl 0x50a035
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a035;
    }
L_0x0050a084:
    // 0050a084  83c408                 +add esp, 8
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
    // 0050a087  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a088  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a089  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a08a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a08b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a08c:
    // 0050a08c  66c7020000             -mov word ptr [edx], 0
    app->getMemory<x86::reg16>(cpu.edx) = 0 /*0x0*/;
    // 0050a091  ebe3                   -jmp 0x50a076
    goto L_0x0050a076;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50a0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a0a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a0a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a0a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a0a3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a0a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a0aa  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a0ad  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a0af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a0b1  7e3f                   -jle 0x50a0f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a0f2;
    }
    // 0050a0b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0050a0b4:
    // 0050a0b4  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0050a0b6  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0b9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a0bb  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a0c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a0c3  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050a0c9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050a0cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a0ce  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050a0d1  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050a0d7  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050a0da  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a0dd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050a0df  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050a0e1  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a0e3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050a0e4  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0050a0e6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a0ea  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0ed  39cd                   +cmp ebp, ecx
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
    // 0050a0ef  7cc3                   -jl 0x50a0b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a0b4;
    }
    // 0050a0f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a0f2:
    // 0050a0f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a0f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a0f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50a100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a102  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a103  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a104  8b2d90835600           -mov ebp, dword ptr [0x568390]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050a10a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a10c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a10e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a110  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a112  7e2c                   -jle 0x50a140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a140;
    }
L_0x0050a114:
    // 0050a114  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a116  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050a118  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0050a11f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0050a122  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a125  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050a128  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050a12b  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a12c  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0050a12f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a132  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0050a134  46                     -inc esi
    (cpu.esi)++;
    // 0050a135  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0050a138  39fe                   +cmp esi, edi
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
    // 0050a13a  7cd8                   -jl 0x50a114
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a114;
    }
    // 0050a13c  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0050a140:
    // 0050a140  892d90835600           -mov dword ptr [0x568390], ebp
    app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.ebp;
    // 0050a146  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a147  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a148  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a149  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a14a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50a150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a151  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a152  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a155  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a157  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a159  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a15b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050a15d  7e52                   -jle 0x50a1b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a1b1;
    }
    // 0050a15f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a160:
    // 0050a160  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a163  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a168  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a16a  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 0050a16d  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a170  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0050a173  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a176  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050a17a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a17c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a17f  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a182  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a185  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a188  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050a18c  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0050a18f  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a193  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050a197  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 0050a19a  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a19e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a1a1  8842fe                 -mov byte ptr [edx - 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 0050a1a4  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a1a8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a1a9  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0050a1ac  39fb                   +cmp ebx, edi
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
    // 0050a1ae  7cb0                   -jl 0x50a160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a160;
    }
    // 0050a1b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a1b1:
    // 0050a1b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a1b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a1c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a1c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a1c3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0050a1ca  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1cc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050a1ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a1d0  e81b03feff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0050a1d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a1d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a1e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a1e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a1e2  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a1e5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050a1e7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a1e9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a1eb  7e43                   -jle 0x50a230
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a230;
    }
L_0x0050a1ed:
    // 0050a1ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1ef  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a1f2  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a1f5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a1f7  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050a1fa  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a1fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a200  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050a202  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a206  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a209  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a20d  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0050a210  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a214  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a217  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 0050a21a  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0050a21d  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a21e  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0050a221  39f1                   +cmp ecx, esi
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
    // 0050a223  7cc8                   -jl 0x50a1ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a1ed;
    }
    // 0050a225  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0050a22b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0050a22e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_0x0050a230:
    // 0050a230  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a233  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a234  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a235  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50a240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a240  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a241  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a243  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a244  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a247  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a249  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a24c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0050a24f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a251  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a253  7e48                   -jle 0x50a29d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a29d;
    }
L_0x0050a255:
    // 0050a255  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a258  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a25e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a263  39e8                   +cmp eax, ebp
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
    // 0050a265  743e                   -je 0x50a2a5
    if (cpu.flags.zf)
    {
        goto L_0x0050a2a5;
    }
    // 0050a267  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a269  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a26b  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 0050a26e  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a271  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a274  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a277  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a27a  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 0050a27d  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 0050a280  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a286  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a289  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a28b  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a28d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x0050a28f:
    // 0050a28f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0050a292  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a295  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a296  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a299  39fb                   +cmp ebx, edi
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
    // 0050a29b  7cb8                   -jl 0x50a255
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a255;
    }
L_0x0050a29d:
    // 0050a29d  83c404                 +add esp, 4
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
    // 0050a2a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a2a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a2a5:
    // 0050a2a5  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050a2ab  ebe2                   -jmp 0x50a28f
    goto L_0x0050a28f;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50a2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a2b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a2b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a2b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a2b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a2b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a2b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a2b9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a2bd  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a2c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a2c3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050a2c5  7e50                   -jle 0x50a317
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a317;
    }
L_0x0050a2c7:
    // 0050a2c7  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0050a2ca  8b2d88835600           -mov ebp, dword ptr [0x568388]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5669768) /* 0x568388 */);
    // 0050a2d0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a2d5  39e8                   +cmp eax, ebp
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
    // 0050a2d7  7446                   -je 0x50a31f
    if (cpu.flags.zf)
    {
        goto L_0x0050a31f;
    }
    // 0050a2d9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050a2db  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a2dd  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a2e0  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 0050a2e3  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a2e6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050a2e9  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a2ec  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050a2ef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a2f1  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a2f4  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 0050a2f7  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 0050a2fa  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a2ff  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a301  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0050a304  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a306  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x0050a308:
    // 0050a308  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a30c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a30f  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a310  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a313  39fb                   +cmp ebx, edi
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
    // 0050a315  7cb0                   -jl 0x50a2c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a2c7;
    }
L_0x0050a317:
    // 0050a317  83c408                 +add esp, 8
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
    // 0050a31a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a31e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a31f:
    // 0050a31f  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050a325  ebe1                   -jmp 0x50a308
    goto L_0x0050a308;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a330  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a331  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a332  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a333  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a336  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a338  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a33a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a33d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a33f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050a343  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a345  7e6a                   -jle 0x50a3b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a3b1;
    }
    // 0050a347  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0050a348:
    // 0050a348  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0050a34b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a350  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a352  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 0050a355  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a358  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050a35a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a35c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0050a35f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0050a362  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a365  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050a369  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0050a36c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050a36f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a371  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a373  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a376  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0050a379  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0050a37c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a37f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050a382  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050a384  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050a387  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0050a38a  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a38c  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a38e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050a390  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050a393  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0050a396  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a398  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a39a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a39c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a3a0  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a3a3  40                     -inc eax
    (cpu.eax)++;
    // 0050a3a4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050a3a8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050a3ac  39d0                   +cmp eax, edx
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
    // 0050a3ae  7c98                   -jl 0x50a348
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a348;
    }
    // 0050a3b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a3b1:
    // 0050a3b1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a3b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50a3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a3c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a3c1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a3c4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a3c6  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a3ca  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a3ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a3d0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050a3d2  7e5e                   -jle 0x50a432
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a432;
    }
    // 0050a3d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a3d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a3d6:
    // 0050a3d6  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0050a3da  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0050a3dd  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a3e3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a3e5  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 0050a3e8  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3eb  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0050a3ef  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050a3f1  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0050a3f4  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3f7  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a3fa  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0050a3fe  8d3cd500000000         -lea edi, [edx*8]
    cpu.edi = x86::reg32(cpu.edx * 8);
    // 0050a405  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a407  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a40b  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0050a40e  c1e613                 -shl esi, 0x13
    cpu.esi <<= 19 /*0x13*/ % 32;
    // 0050a411  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a413  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a417  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a41a  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0050a41d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a420  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a422  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a423  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a425  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050a429  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a42c  39f3                   +cmp ebx, esi
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
    // 0050a42e  7ca6                   -jl 0x50a3d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a3d6;
    }
    // 0050a430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a431  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a432:
    // 0050a432  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a435  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50a440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a441  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a444  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a446  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050a44a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a44e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a450  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050a452  7e5c                   -jle 0x50a4b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a4b0;
    }
    // 0050a454  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a455  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a456:
    // 0050a456  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 0050a45a  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0050a45d  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050a463  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a465  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 0050a468  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a46b  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050a46f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a471  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0050a474  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050a477  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050a47a  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050a47e  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 0050a485  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a489  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 0050a48c  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 0050a48f  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a491  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050a495  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a498  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 0050a49b  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a49e  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a4a0  43                     -inc ebx
    (cpu.ebx)++;
    // 0050a4a1  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050a4a3  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050a4a7  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050a4aa  39f3                   +cmp ebx, esi
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
    // 0050a4ac  7ca8                   -jl 0x50a456
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a456;
    }
    // 0050a4ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a4af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a4b0:
    // 0050a4b0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a4b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a4b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50a4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a4c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a4c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a4c2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a4c5  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050a4c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a4ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050a4cc  7e36                   -jle 0x50a504
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050a504;
    }
    // 0050a4ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a4cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0050a4d0:
    // 0050a4d0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050a4d2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a4d5  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050a4d8  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 0050a4dc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050a4de  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 0050a4e1  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0050a4e4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a4e6  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050a4ec  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0050a4ef  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050a4f2  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050a4f4  41                     -inc ecx
    (cpu.ecx)++;
    // 0050a4f5  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050a4f7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a4fb  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0050a4fe  39f1                   +cmp ecx, esi
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
    // 0050a500  7cce                   -jl 0x50a4d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050a4d0;
    }
    // 0050a502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a503  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050a504:
    // 0050a504  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050a507  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a509  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_50a510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a510  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050a513  e9d8fffdff             -jmp 0x4ea4f0
    return sub_4ea4f0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50a520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a520  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
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
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a559(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a559;
    // 0050a520  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
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
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
L_entry_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a550;
    // 0050a520  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
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
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
L_entry_0x0050a550:
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50a543(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050a543;
    // 0050a520  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a523  7312                   -jae 0x50a537
    if (!cpu.flags.cf)
    {
        goto L_0x0050a537;
    }
    // 0050a525  83f804                 +cmp eax, 4
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
    // 0050a528  722c                   -jb 0x50a556
    if (cpu.flags.cf)
    {
        goto L_0x0050a556;
    }
    // 0050a52a  762a                   -jbe 0x50a556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a52c  83f808                 +cmp eax, 8
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
    // 0050a52f  7525                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a531  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a536  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a537:
    // 0050a537  7620                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a559;
    }
    // 0050a539  83f818                 +cmp eax, 0x18
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
    // 0050a53c  730b                   -jae 0x50a549
    if (!cpu.flags.cf)
    {
        goto L_0x0050a549;
    }
    // 0050a53e  83f810                 +cmp eax, 0x10
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
    // 0050a541  7513                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
L_entry_0x0050a543:
    // 0050a543  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0050a548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a549:
    // 0050a549  7614                   -jbe 0x50a55f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a55f;
    }
    // 0050a54b  83f820                 +cmp eax, 0x20
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
    // 0050a54e  7506                   -jne 0x50a556
    if (!cpu.flags.zf)
    {
        goto L_0x0050a556;
    }
    // 0050a550  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050a555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a556:
    // 0050a556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a559:
    // 0050a559  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050a55e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a55f:
    // 0050a55f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50a570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a570  83f878                 +cmp eax, 0x78
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
    // 0050a573  730f                   -jae 0x50a584
    if (!cpu.flags.cf)
    {
        goto L_0x0050a584;
    }
    // 0050a575  83f842                 +cmp eax, 0x42
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(66 /*0x42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a578  7335                   -jae 0x50a5af
    if (!cpu.flags.cf)
    {
        goto L_0x0050a5af;
    }
    // 0050a57a  83f840                 +cmp eax, 0x40
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
    // 0050a57d  7248                   -jb 0x50a5c7
    if (cpu.flags.cf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a57f  7716                   -ja 0x50a597
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050a597;
    }
L_0x0050a581:
    // 0050a581  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050a583  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a584:
    // 0050a584  76bd                   -jbe 0x50a543
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a543(app, cpu);
    }
    // 0050a586  83f87d                 +cmp eax, 0x7d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a589  7312                   -jae 0x50a59d
    if (!cpu.flags.cf)
    {
        goto L_0x0050a59d;
    }
    // 0050a58b  83f87a                 +cmp eax, 0x7a
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
    // 0050a58e  7237                   -jb 0x50a5c7
    if (cpu.flags.cf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a590  76ef                   -jbe 0x50a581
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a581;
    }
    // 0050a592  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a595  7530                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
L_0x0050a597:
    // 0050a597  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050a59c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a59d:
    // 0050a59d  76b1                   -jbe 0x50a550
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a550(app, cpu);
    }
    // 0050a59f  83f87e                 +cmp eax, 0x7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5a2  76b5                   -jbe 0x50a559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_50a559(app, cpu);
    }
    // 0050a5a4  83f87f                 +cmp eax, 0x7f
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
    // 0050a5a7  751e                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
L_0x0050a5a9:
    // 0050a5a9  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050a5ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5af:
    // 0050a5af  7610                   -jbe 0x50a5c1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a5c1;
    }
    // 0050a5b1  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5b4  76f3                   -jbe 0x50a5a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050a5a9;
    }
    // 0050a5b6  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5b9  750c                   -jne 0x50a5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0050a5c7;
    }
    // 0050a5bb  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0050a5c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5c1:
    // 0050a5c1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0050a5c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a5c7:
    // 0050a5c7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050a5cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50a5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a5d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a5d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a5d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a5d4  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a5da  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a5dc  e8df2bffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a5e1  bf14a8a000             -mov edi, 0xa0a814
    cpu.edi = 10528788 /*0xa0a814*/;
    // 0050a5e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a5e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a5ea  0f846f000000           -je 0x50a65f
    if (cpu.flags.zf)
    {
        goto L_0x0050a65f;
    }
    // 0050a5f0  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a5f2  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a5f8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a5fb  83fe2a                 +cmp esi, 0x2a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a5fe  0f8468000000           -je 0x50a66c
    if (cpu.flags.zf)
    {
        goto L_0x0050a66c;
    }
    // 0050a604  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a607  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 0050a611  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050a613  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a615  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a61b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0050a61e  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a621  744d                   -je 0x50a670
    if (cpu.flags.zf)
    {
        goto L_0x0050a670;
    }
    // 0050a623  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a626  7455                   -je 0x50a67d
    if (cpu.flags.zf)
    {
        goto L_0x0050a67d;
    }
    // 0050a628  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a62b  745b                   -je 0x50a688
    if (cpu.flags.zf)
    {
        goto L_0x0050a688;
    }
    // 0050a62d  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a630  745a                   -je 0x50a68c
    if (cpu.flags.zf)
    {
        goto L_0x0050a68c;
    }
    // 0050a632  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a635  7460                   -je 0x50a697
    if (cpu.flags.zf)
    {
        goto L_0x0050a697;
    }
    // 0050a637  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a63a  7466                   -je 0x50a6a2
    if (cpu.flags.zf)
    {
        goto L_0x0050a6a2;
    }
    // 0050a63c  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a63f  0f8575000000           -jne 0x50a6ba
    if (!cpu.flags.zf)
    {
        goto L_0x0050a6ba;
    }
    // 0050a645  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a64a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a64c  e8739cffff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
    // 0050a651  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a656  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a658:
    // 0050a658  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a65a  e8e1fbffff             -call 0x50a240
    cpu.esp -= 4;
    sub_50a240(app, cpu);
    if (cpu.terminate) return;
L_0x0050a65f:
    // 0050a65f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a661  81c400020000           +add esp, 0x200
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050a667  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a668  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a66a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a66b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a66c:
    // 0050a66c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a66e  ebef                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a670:
    // 0050a670  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a674  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a676  e8e5380100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a67b  ebe2                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a67d:
    // 0050a67d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a67f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a681  e82afcffff             -call 0x50a2b0
    cpu.esp -= 4;
    sub_50a2b0(app, cpu);
    if (cpu.terminate) return;
    // 0050a686  ebd7                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a688:
    // 0050a688  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a68a  ebcc                   -jmp 0x50a658
    goto L_0x0050a658;
L_0x0050a68c:
    // 0050a68c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a68e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a690  e8abfdffff             -call 0x50a440
    cpu.esp -= 4;
    sub_50a440(app, cpu);
    if (cpu.terminate) return;
    // 0050a695  ebc8                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a697:
    // 0050a697  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a699  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a69b  e820fdffff             -call 0x50a3c0
    cpu.esp -= 4;
    sub_50a3c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a6a0  ebbd                   -jmp 0x50a65f
    goto L_0x0050a65f;
L_0x0050a6a2:
    // 0050a6a2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a6a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a6a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a6a8  e8b3370100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a6ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a6af  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a6b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a6ba:
    // 0050a6ba  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a6bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a6c0  bbb8f75400             -mov ebx, 0x54f7b8
    cpu.ebx = 5568440 /*0x54f7b8*/;
    // 0050a6c5  be13030000             -mov esi, 0x313
    cpu.esi = 787 /*0x313*/;
    // 0050a6ca  68c4f75400             -push 0x54f7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568452 /*0x54f7c4*/;
    cpu.esp -= 4;
    // 0050a6cf  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a6d5  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a6db  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a6e1  e82a69efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a6e6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a6e9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a6eb  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0050a6f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a6f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50a700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a702  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a703  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a704  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a70a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050a70c  e8af2affff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a711  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a713  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a715  0f84f3000000           -je 0x50a80e
    if (cpu.flags.zf)
    {
        goto L_0x0050a80e;
    }
    // 0050a71b  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a71d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a723  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a726  83fb29                 +cmp ebx, 0x29
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a729  7452                   -je 0x50a77d
    if (cpu.flags.zf)
    {
        goto L_0x0050a77d;
    }
    // 0050a72b  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a72e  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 0050a737  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050a739  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a73b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a741  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0050a744  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a747  7438                   -je 0x50a781
    if (cpu.flags.zf)
    {
        goto L_0x0050a781;
    }
    // 0050a749  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a74c  744b                   -je 0x50a799
    if (cpu.flags.zf)
    {
        goto L_0x0050a799;
    }
    // 0050a74e  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a751  7451                   -je 0x50a7a4
    if (cpu.flags.zf)
    {
        goto L_0x0050a7a4;
    }
    // 0050a753  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a756  7457                   -je 0x50a7af
    if (cpu.flags.zf)
    {
        goto L_0x0050a7af;
    }
    // 0050a758  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a75b  7431                   -je 0x50a78e
    if (cpu.flags.zf)
    {
        goto L_0x0050a78e;
    }
    // 0050a75d  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a760  7458                   -je 0x50a7ba
    if (cpu.flags.zf)
    {
        goto L_0x0050a7ba;
    }
    // 0050a762  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a765  756b                   -jne 0x50a7d2
    if (!cpu.flags.zf)
    {
        goto L_0x0050a7d2;
    }
    // 0050a767  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a769  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a76b  e8549bffff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
L_0x0050a770:
    // 0050a770  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a772  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050a778  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a779  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a77c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a77d:
    // 0050a77d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a77f  ebef                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a781:
    // 0050a781  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a783  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a785  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a787  e8d4370100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a78c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a78e:
    // 0050a78e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a790  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a792  e859f7ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a797  ebd7                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a799:
    // 0050a799  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a79b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a79d  e81ef7ffff             -call 0x509ec0
    cpu.esp -= 4;
    sub_509ec0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7a2  ebcc                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7a4:
    // 0050a7a4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a7a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7a8  e813f7ffff             -call 0x509ec0
    cpu.esp -= 4;
    sub_509ec0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a7af:
    // 0050a7af  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7b1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a7b3  e87b99ffff             -call 0x504133
    cpu.esp -= 4;
    sub_504133(app, cpu);
    if (cpu.terminate) return;
    // 0050a7b8  ebb6                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7ba:
    // 0050a7ba  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a7bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a7be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a7c0  e89b360100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a7c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050a7c7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050a7c9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a7cb  e820f7ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a7d0  eb9e                   -jmp 0x50a770
    goto L_0x0050a770;
L_0x0050a7d2:
    // 0050a7d2  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a7d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a7d8  bbf0f75400             -mov ebx, 0x54f7f0
    cpu.ebx = 5568496 /*0x54f7f0*/;
    // 0050a7dd  be50030000             -mov esi, 0x350
    cpu.esi = 848 /*0x350*/;
    // 0050a7e2  6800f85400             -push 0x54f800
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568512 /*0x54f800*/;
    cpu.esp -= 4;
    // 0050a7e7  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a7ed  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a7f3  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a7f9  e81268efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a7fe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a801  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a803  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a809  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a80d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a80e:
    // 0050a80e  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a813  b814a8a000             -mov eax, 0xa0a814
    cpu.eax = 10528788 /*0xa0a814*/;
    // 0050a818  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050a81a  e8d1f6ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050a81f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050a821  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a823  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a829  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a82d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50a830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050a831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a832  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a833  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a834  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a83a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a83c  e87f29ffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a841  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a843  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050a845  0f84f3000000           -je 0x50a93e
    if (cpu.flags.zf)
    {
        goto L_0x0050a93e;
    }
    // 0050a84b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a84d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a853  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050a856  83f92c                 +cmp ecx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a859  0f8469000000           -je 0x50a8c8
    if (cpu.flags.zf)
    {
        goto L_0x0050a8c8;
    }
    // 0050a85f  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050a862  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 0050a86c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050a86e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0050a870  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a876  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050a879  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a87c  744e                   -je 0x50a8cc
    if (cpu.flags.zf)
    {
        goto L_0x0050a8cc;
    }
    // 0050a87e  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a881  7456                   -je 0x50a8d9
    if (cpu.flags.zf)
    {
        goto L_0x0050a8d9;
    }
    // 0050a883  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a886  7457                   -je 0x50a8df
    if (cpu.flags.zf)
    {
        goto L_0x0050a8df;
    }
    // 0050a888  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a88b  745d                   -je 0x50a8ea
    if (cpu.flags.zf)
    {
        goto L_0x0050a8ea;
    }
    // 0050a88d  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a890  7420                   -je 0x50a8b2
    if (cpu.flags.zf)
    {
        goto L_0x0050a8b2;
    }
    // 0050a892  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a895  745e                   -je 0x50a8f5
    if (cpu.flags.zf)
    {
        goto L_0x0050a8f5;
    }
    // 0050a897  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050a89a  7566                   -jne 0x50a902
    if (!cpu.flags.zf)
    {
        goto L_0x0050a902;
    }
    // 0050a89c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a89e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a8a0  e81f9affff             -call 0x5042c4
    cpu.esp -= 4;
    sub_5042c4(app, cpu);
    if (cpu.terminate) return;
    // 0050a8a5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8a7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0050a8ab:
    // 0050a8ab  e800faffff             -call 0x50a2b0
    cpu.esp -= 4;
    sub_50a2b0(app, cpu);
    if (cpu.terminate) return;
L_0x0050a8b0:
    // 0050a8b0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050a8b2:
    // 0050a8b2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a8b6  e8e5f7ffff             -call 0x50a0a0
    cpu.esp -= 4;
    sub_50a0a0(app, cpu);
    if (cpu.terminate) return;
L_0x0050a8bb:
    // 0050a8bb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a8bd  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050a8c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a8c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a8c8:
    // 0050a8c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a8ca  ebef                   -jmp 0x50a8bb
    goto L_0x0050a8bb;
L_0x0050a8cc:
    // 0050a8cc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a8ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a8d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a8d2  e889360100             -call 0x51df60
    cpu.esp -= 4;
    sub_51df60(app, cpu);
    if (cpu.terminate) return;
    // 0050a8d7  ebd7                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8d9:
    // 0050a8d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8db  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8dd  ebcc                   -jmp 0x50a8ab
    goto L_0x0050a8ab;
L_0x0050a8df:
    // 0050a8df  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8e3  e858f9ffff             -call 0x50a240
    cpu.esp -= 4;
    sub_50a240(app, cpu);
    if (cpu.terminate) return;
    // 0050a8e8  ebc6                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8ea:
    // 0050a8ea  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050a8ec  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050a8ee  e8cdfaffff             -call 0x50a3c0
    cpu.esp -= 4;
    sub_50a3c0(app, cpu);
    if (cpu.terminate) return;
    // 0050a8f3  ebbb                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a8f5:
    // 0050a8f5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050a8f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050a8f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050a8fb  e860350100             -call 0x51de60
    cpu.esp -= 4;
    sub_51de60(app, cpu);
    if (cpu.terminate) return;
    // 0050a900  ebae                   -jmp 0x50a8b0
    goto L_0x0050a8b0;
L_0x0050a902:
    // 0050a902  b9a8f75400             -mov ecx, 0x54f7a8
    cpu.ecx = 5568424 /*0x54f7a8*/;
    // 0050a907  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050a908  bb2cf85400             -mov ebx, 0x54f82c
    cpu.ebx = 5568556 /*0x54f82c*/;
    // 0050a90d  be97030000             -mov esi, 0x397
    cpu.esi = 919 /*0x397*/;
    // 0050a912  683cf85400             -push 0x54f83c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568572 /*0x54f83c*/;
    cpu.esp -= 4;
    // 0050a917  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050a91d  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050a923  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050a929  e8e266efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050a92e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050a931  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a933  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a93d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050a93e:
    // 0050a93e  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0050a943  b814a8a000             -mov eax, 0xa0a814
    cpu.eax = 10528788 /*0xa0a814*/;
    // 0050a948  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050a94a  e851f7ffff             -call 0x50a0a0
    cpu.esp -= 4;
    sub_50a0a0(app, cpu);
    if (cpu.terminate) return;
    // 0050a94f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0050a951  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050a953  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050a959  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050a960  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050a961  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050a962  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050a963  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050a964  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a967  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050a969  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050a96b  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050a96f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a971  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050a977  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a979  e8f2fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a97e  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050a985  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a987  e8e4fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a98c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050a98e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050a990  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050a992  8a8194855600           -mov al, byte ptr [ecx + 0x568594]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5670292) /* 0x568594 */);
    // 0050a998  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050a99c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050a99f  39c6                   +cmp esi, eax
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
    // 0050a9a1  7551                   -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050a9a3  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0050a9a8  7556                   -jne 0x50aa00
    if (!cpu.flags.zf)
    {
        goto L_0x0050aa00;
    }
    // 0050a9aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050a9ac  e8bffbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a9b1  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050a9b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050a9ba  e8b1fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050a9bf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050a9c1  8b048594845600         -mov eax, dword ptr [eax*4 + 0x568494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5670036) /* 0x568494 */ + cpu.eax * 4);
L_0x0050a9c8:
    // 0050a9c8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050a9cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050a9ce  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a9d0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050a9d3  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050a9d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050a9db  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050a9dd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050a9df  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050a9e2  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050a9e8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050a9ea  83f908                 +cmp ecx, 8
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
    // 0050a9ed  7f05                   -jg 0x50a9f4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050a9f4;
    }
    // 0050a9ef  83f808                 +cmp eax, 8
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
    // 0050a9f2  7f2c                   -jg 0x50aa20
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050aa20;
    }
L_0x0050a9f4:
    // 0050a9f4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050a9f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050a9fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050a9ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa00:
    // 0050aa00  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050aa02  e869fbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aa07  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0050aa0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050aa10  e85bfbffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aa15  01c8                   +add eax, ecx
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
    // 0050aa17  8b048594835600         -mov eax, dword ptr [eax*4 + 0x568394]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669780) /* 0x568394 */ + cpu.eax * 4);
    // 0050aa1e  eba8                   -jmp 0x50a9c8
    goto L_0x0050a9c8;
L_0x0050aa20:
    // 0050aa20  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050aa27  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050aa2c  e89ffbffff             -call 0x50a5d0
    cpu.esp -= 4;
    sub_50a5d0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa31  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050aa35  a390835600             -mov dword ptr [0x568390], eax
    app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.eax;
    // 0050aa3a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0050aa3c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050aa3e  7451                   -je 0x50aa91
    if (cpu.flags.zf)
    {
        goto L_0x0050aa91;
    }
    // 0050aa40  83fe6d                 +cmp esi, 0x6d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa43  7420                   -je 0x50aa65
    if (cpu.flags.zf)
    {
        goto L_0x0050aa65;
    }
    // 0050aa45  83ff0f                 +cmp edi, 0xf
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
    // 0050aa48  7431                   -je 0x50aa7b
    if (cpu.flags.zf)
    {
        goto L_0x0050aa7b;
    }
    // 0050aa4a  83ff10                 +cmp edi, 0x10
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
    // 0050aa4d  75a5                   -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050aa4f  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa54  e897f4ffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa59  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa65:
    // 0050aa65  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa6a  e841f5ffff             -call 0x509fb0
    cpu.esp -= 4;
    sub_509fb0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa6f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa73  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa7b:
    // 0050aa7b  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aa80  e86bf3ffff             -call 0x509df0
    cpu.esp -= 4;
    sub_509df0(app, cpu);
    if (cpu.terminate) return;
    // 0050aa85  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aa89  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aa8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aa90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aa91:
    // 0050aa91  83fe6d                 +cmp esi, 0x6d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050aa94  74cf                   -je 0x50aa65
    if (cpu.flags.zf)
    {
        goto L_0x0050aa65;
    }
    // 0050aa96  83ff0f                 +cmp edi, 0xf
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
    // 0050aa99  741f                   -je 0x50aaba
    if (cpu.flags.zf)
    {
        goto L_0x0050aaba;
    }
    // 0050aa9b  83ff10                 +cmp edi, 0x10
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
    // 0050aa9e  0f8550ffffff           -jne 0x50a9f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050a9f4;
    }
    // 0050aaa4  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aaa9  e8a2f4ffff             -call 0x509f50
    cpu.esp -= 4;
    sub_509f50(app, cpu);
    if (cpu.terminate) return;
    // 0050aaae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aab2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aab9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050aaba:
    // 0050aaba  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aabf  e88cf3ffff             -call 0x509e50
    cpu.esp -= 4;
    sub_509e50(app, cpu);
    if (cpu.terminate) return;
    // 0050aac4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050aac8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050aacb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aace  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050aacf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50aad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050aad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050aad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050aad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050aad3  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0050aad6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050aad8  89542444               -mov dword ptr [esp + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0050aadc  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050aae0  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0050aae4  e8d726ffff             -call 0x4fd1c0
    cpu.esp -= 4;
    sub_4fd1c0(app, cpu);
    if (cpu.terminate) return;
    // 0050aae9  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0050aaee  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0050aaf2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050aaf4  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 0050aaf8  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
L_0x0050aafc:
    // 0050aafc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050aafe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab03  e868faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ab0a  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab0e  e85dfaffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ab15  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050ab17  0f8c2d030000           -jl 0x50ae4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ae4a;
    }
L_0x0050ab1d:
    // 0050ab1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050ab1f  0f8c60030000           -jl 0x50ae85
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ae85;
    }
L_0x0050ab25:
    // 0050ab25  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 0050ab2a  0f848c030000           -je 0x50aebc
    if (cpu.flags.zf)
    {
        goto L_0x0050aebc;
    }
    // 0050ab30  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab32  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab37  e834faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab3c  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050ab43  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab47  e824faffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ab4e  8b048594835600         -mov eax, dword ptr [eax*4 + 0x568394]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669780) /* 0x568394 */ + cpu.eax * 4);
L_0x0050ab55:
    // 0050ab55  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0050ab59  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab60  e80bfaffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab65  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050ab6c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab70  e8fbf9ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050ab75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ab77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ab79  8a8294855600           -mov al, byte ptr [edx + 0x568594]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670292) /* 0x568594 */);
    // 0050ab7f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0050ab83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050ab85  753a                   -jne 0x50abc1
    if (!cpu.flags.zf)
    {
        goto L_0x0050abc1;
    }
    // 0050ab87  b8a8f75400             -mov eax, 0x54f7a8
    cpu.eax = 5568424 /*0x54f7a8*/;
    // 0050ab8c  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ab90  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0050ab95  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050ab97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ab98  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ab9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ab9e  ba68f85400             -mov edx, 0x54f868
    cpu.edx = 5568616 /*0x54f868*/;
    // 0050aba3  b909040000             -mov ecx, 0x409
    cpu.ecx = 1033 /*0x409*/;
    // 0050aba8  68fcf85400             -push 0x54f8fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568764 /*0x54f8fc*/;
    cpu.esp -= 4;
    // 0050abad  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0050abb3  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050abb9  e85264efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050abbe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0050abc1:
    // 0050abc1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050abc3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050abc5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050abc8  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050abce  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050abd0  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0050abd4  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050abd8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050abda  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050abdd  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050abe3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050abe5  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0050abe9  40                     -inc eax
    (cpu.eax)++;
    // 0050abea  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050abec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050abee  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0050abf1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0050abf4  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0050abf8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0050abfb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0050abfe  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0050ac02  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ac04  e8b78a0100             -call 0x5236c0
    cpu.esp -= 4;
    sub_5236c0(app, cpu);
    if (cpu.terminate) return;
    // 0050ac09  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0050ac0d  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ac11  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0050ac14  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050ac17  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0050ac19  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050ac1b  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0050ac1e  83f908                 +cmp ecx, 8
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
    // 0050ac21  7f71                   -jg 0x50ac94
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050ac94;
    }
    // 0050ac23  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ac26  7e6c                   -jle 0x50ac94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ac94;
    }
    // 0050ac28  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050ac2d  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050ac31  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0050ac33  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ac35  0f84ab020000           -je 0x50aee6
    if (cpu.flags.zf)
    {
        goto L_0x0050aee6;
    }
    // 0050ac3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ac3d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ac3f  7e1e                   -jle 0x50ac5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ac5f;
    }
    // 0050ac41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050ac43:
    // 0050ac43  0fb6b064ae5600         -movzx esi, byte ptr [eax + 0x56ae64]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680740) /* 0x56ae64 */));
    // 0050ac4a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ac4d  8b34b514a8a000         -mov esi, dword ptr [esi*4 + 0xa0a814]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.esi * 4);
    // 0050ac54  40                     -inc eax
    (cpu.eax)++;
    // 0050ac55  89b110aca000           -mov dword ptr [ecx + 0xa0ac10], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10529808) /* 0xa0ac10 */) = cpu.esi;
    // 0050ac5b  39d8                   +cmp eax, ebx
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
    // 0050ac5d  7ce4                   -jl 0x50ac43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ac43;
    }
L_0x0050ac5f:
    // 0050ac5f  c7059083560014aca000   -mov dword ptr [0x568390], 0xa0ac14
    app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = 10529812 /*0xa0ac14*/;
L_0x0050ac69:
    // 0050ac69  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 0050ac6e  0f84c4020000           -je 0x50af38
    if (cpu.flags.zf)
    {
        goto L_0x0050af38;
    }
    // 0050ac74  837c24446d             +cmp dword ptr [esp + 0x44], 0x6d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ac79  0f857f020000           -jne 0x50aefe
    if (!cpu.flags.zf)
    {
        goto L_0x0050aefe;
    }
L_0x0050ac7f:
    // 0050ac7f  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050ac84  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050ac89  e822f3ffff             -call 0x509fb0
    cpu.esp -= 4;
    sub_509fb0(app, cpu);
    if (cpu.terminate) return;
L_0x0050ac8e:
    // 0050ac8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ac90  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0050ac94:
    // 0050ac94  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050ac98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ac99  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ac9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ac9e  6870f95400             -push 0x54f970
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568880 /*0x54f970*/;
    cpu.esp -= 4;
    // 0050aca3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050aca7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050aca8  e8e349fdff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0050acad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050acb0  8b4c2454               -mov ecx, dword ptr [esp + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050acb4  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050acb7  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050acbc  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050acc1  b83e040000             -mov eax, 0x43e
    cpu.eax = 1086 /*0x43e*/;
    // 0050acc6  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050accc  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0050acd2  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050acd7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050acd9  8d5114                 -lea edx, [ecx + 0x14]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0050acdc  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050ace2  e83969fdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0050ace7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050ace9  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0050aced  b850485343             -mov eax, 0x43534850
    cpu.eax = 1129531472 /*0x43534850*/;
    // 0050acf2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050acf4  89443110               -mov dword ptr [ecx + esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.esi * 1) = cpu.eax;
    // 0050acf8  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050acfc  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0050acff  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ad04  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0050ad06  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad08  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ad0c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050ad0e  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0050ad10  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ad16  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0050ad1a  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad1e  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0050ad20  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 0050ad24  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050ad28  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0050ad2c  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0050ad30  668b560c               -mov dx, word ptr [esi + 0xc]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0050ad34  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0050ad38  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0050ad3e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050ad41  6689560c               -mov word ptr [esi + 0xc], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0050ad45  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0050ad4a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0050ad4d  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050ad50  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad52  895efc                 -mov dword ptr [esi - 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0050ad55  668b5efe               -mov bx, word ptr [esi - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0050ad59  8d4f10                 -lea ecx, [edi + 0x10]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050ad5c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0050ad62  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050ad65  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 0050ad69  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 0050ad6e  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ad71  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050ad73  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad75  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad79  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0050ad7c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ad7e  7e1d                   -jle 0x50ad9d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ad9d;
    }
L_0x0050ad80:
    // 0050ad80  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050ad84  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050ad86  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ad88  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050ad8c  47                     -inc edi
    (cpu.edi)++;
    // 0050ad8d  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050ad91  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ad95  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ad97  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ad99  39d7                   +cmp edi, edx
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
    // 0050ad9b  7ce3                   -jl 0x50ad80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ad80;
    }
L_0x0050ad9d:
    // 0050ad9d  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 0050ada2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ada6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ada8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0050adad  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050adb0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050adb2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050adb4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050adb6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0050adbd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0050adbf  3d50485343             +cmp eax, 0x43534850
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1129531472 /*0x43534850*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050adc4  7444                   -je 0x50ae0a
    if (cpu.flags.zf)
    {
        goto L_0x0050ae0a;
    }
    // 0050adc6  8b6c2440               -mov ebp, dword ptr [esp + 0x40]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050adca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050adcb  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050adcf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050add0  8b542458               -mov edx, dword ptr [esp + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050add4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050add5  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050add9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050adda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050addb  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050ade0  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050ade5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ade6  bf61040000             -mov edi, 0x461
    cpu.edi = 1121 /*0x461*/;
    // 0050adeb  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050adf1  6878f95400             -push 0x54f978
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568888 /*0x54f978*/;
    cpu.esp -= 4;
    // 0050adf6  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050adfc  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050ae02  e80962efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ae07  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0050ae0a:
    // 0050ae0a  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050ae0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ae10  7407                   -je 0x50ae19
    if (cpu.flags.zf)
    {
        goto L_0x0050ae19;
    }
    // 0050ae12  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ae14  e8776afdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0050ae19:
    // 0050ae19  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ae1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050ae1f  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050ae23  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050ae25  8b6c2444               -mov ebp, dword ptr [esp + 0x44]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050ae29  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ae2e  39e8                   +cmp eax, ebp
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
    // 0050ae30  740f                   -je 0x50ae41
    if (cpu.flags.zf)
    {
        goto L_0x0050ae41;
    }
    // 0050ae32  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ae36  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050ae37  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0050ae3b  0f85bbfcffff           -jne 0x50aafc
    if (!cpu.flags.zf)
    {
        goto L_0x0050aafc;
    }
L_0x0050ae41:
    // 0050ae41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ae43  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0050ae46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ae49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ae4a:
    // 0050ae4a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050ae4c  bba8f75400             -mov ebx, 0x54f7a8
    cpu.ebx = 5568424 /*0x54f7a8*/;
    // 0050ae51  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ae56  be68f85400             -mov esi, 0x54f868
    cpu.esi = 5568616 /*0x54f868*/;
    // 0050ae5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ae5c  bdfb030000             -mov ebp, 0x3fb
    cpu.ebp = 1019 /*0x3fb*/;
    // 0050ae61  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050ae67  687cf85400             -push 0x54f87c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568636 /*0x54f87c*/;
    cpu.esp -= 4;
    // 0050ae6c  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050ae72  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050ae78  e89361efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ae7d  83c408                 +add esp, 8
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
    // 0050ae80  e998fcffff             -jmp 0x50ab1d
    goto L_0x0050ab1d;
L_0x0050ae85:
    // 0050ae85  b8a8f75400             -mov eax, 0x54f7a8
    cpu.eax = 5568424 /*0x54f7a8*/;
    // 0050ae8a  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050ae8e  ba68f85400             -mov edx, 0x54f868
    cpu.edx = 5568616 /*0x54f868*/;
    // 0050ae93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ae94  b9fd030000             -mov ecx, 0x3fd
    cpu.ecx = 1021 /*0x3fd*/;
    // 0050ae99  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0050ae9e  68b4f85400             -push 0x54f8b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568692 /*0x54f8b4*/;
    cpu.esp -= 4;
    // 0050aea3  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0050aea9  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050aeaf  e85c61efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050aeb4  83c408                 +add esp, 8
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
    // 0050aeb7  e969fcffff             -jmp 0x50ab25
    goto L_0x0050ab25;
L_0x0050aebc:
    // 0050aebc  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050aebe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050aec3  e8a8f6ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aec8  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0050aecf  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050aed3  e898f6ffff             -call 0x50a570
    cpu.esp -= 4;
    sub_50a570(app, cpu);
    if (cpu.terminate) return;
    // 0050aed8  01d0                   +add eax, edx
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
    // 0050aeda  8b048594845600         -mov eax, dword ptr [eax*4 + 0x568494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5670036) /* 0x568494 */ + cpu.eax * 4);
    // 0050aee1  e96ffcffff             -jmp 0x50ab55
    goto L_0x0050ab55;
L_0x0050aee6:
    // 0050aee6  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050aeeb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050aeef  e8dcf6ffff             -call 0x50a5d0
    cpu.esp -= 4;
    sub_50a5d0(app, cpu);
    if (cpu.terminate) return;
    // 0050aef4  a390835600             -mov dword ptr [0x568390], eax
    app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */) = cpu.eax;
    // 0050aef9  e96bfdffff             -jmp 0x50ac69
    goto L_0x0050ac69;
L_0x0050aefe:
    // 0050aefe  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050af02  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050af05  741d                   -je 0x50af24
    if (cpu.flags.zf)
    {
        goto L_0x0050af24;
    }
    // 0050af07  83f910                 +cmp ecx, 0x10
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
    // 0050af0a  0f857efdffff           -jne 0x50ac8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050ac8e;
    }
    // 0050af10  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af15  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af1a  e8d1efffff             -call 0x509ef0
    cpu.esp -= 4;
    sub_509ef0(app, cpu);
    if (cpu.terminate) return;
    // 0050af1f  e96afdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af24:
    // 0050af24  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af29  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af2e  e8bdeeffff             -call 0x509df0
    cpu.esp -= 4;
    sub_509df0(app, cpu);
    if (cpu.terminate) return;
    // 0050af33  e956fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af38:
    // 0050af38  837c24446d             +cmp dword ptr [esp + 0x44], 0x6d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050af3d  0f843cfdffff           -je 0x50ac7f
    if (cpu.flags.zf)
    {
        goto L_0x0050ac7f;
    }
    // 0050af43  8b742440               -mov esi, dword ptr [esp + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050af47  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050af4a  741d                   -je 0x50af69
    if (cpu.flags.zf)
    {
        goto L_0x0050af69;
    }
    // 0050af4c  83fe10                 +cmp esi, 0x10
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
    // 0050af4f  0f8539fdffff           -jne 0x50ac8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050ac8e;
    }
    // 0050af55  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af5a  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af5f  e8ecefffff             -call 0x509f50
    cpu.esp -= 4;
    sub_509f50(app, cpu);
    if (cpu.terminate) return;
    // 0050af64  e925fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
L_0x0050af69:
    // 0050af69  ba14aca000             -mov edx, 0xa0ac14
    cpu.edx = 10529812 /*0xa0ac14*/;
    // 0050af6e  a190835600             -mov eax, dword ptr [0x568390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 0050af73  e8d8eeffff             -call 0x509e50
    cpu.esp -= 4;
    sub_509e50(app, cpu);
    if (cpu.terminate) return;
    // 0050af78  e911fdffff             -jmp 0x50ac8e
    goto L_0x0050ac8e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50af80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050af80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050af81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050af82  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050af87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050af89  e842fbffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050af8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050af8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050af90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50afa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050afa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050afa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050afa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050afa3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050afa5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050afa7  e824e9ffff             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 0050afac  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050afb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050afb3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050afb5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050afb7  e814fbffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050afbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050afbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50afc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050afc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050afc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050afc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050afc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050afc4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0050afc6  8b3db0099f00           -mov edi, dword ptr [0x9f09b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10422704) /* 0x9f09b0 */);
    // 0050afcc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050afce  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 0050afd4  7420                   -je 0x50aff6
    if (cpu.flags.zf)
    {
        goto L_0x0050aff6;
    }
    // 0050afd6  83ed01                 +sub ebp, 1
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
    // 0050afd9  7818                   -js 0x50aff3
    if (cpu.flags.sf)
    {
        goto L_0x0050aff3;
    }
L_0x0050afdb:
    // 0050afdb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050afdd  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050afe0  7411                   -je 0x50aff3
    if (cpu.flags.zf)
    {
        goto L_0x0050aff3;
    }
    // 0050afe2  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050afe5  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050afe8  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050afeb  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050afee  83ed01                 +sub ebp, 1
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
    // 0050aff1  79e8                   -jns 0x50afdb
    if (!cpu.flags.sf)
    {
        goto L_0x0050afdb;
    }
L_0x0050aff3:
    // 0050aff3  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050aff6:
    // 0050aff6  83ed02                 +sub ebp, 2
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
    // 0050aff9  7859                   -js 0x50b054
    if (cpu.flags.sf)
    {
        goto L_0x0050b054;
    }
L_0x0050affb:
    // 0050affb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050affd  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b000  7428                   -je 0x50b02a
    if (cpu.flags.zf)
    {
        goto L_0x0050b02a;
    }
    // 0050b002  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b005  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b008  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b00b  7439                   -je 0x50b046
    if (cpu.flags.zf)
    {
        goto L_0x0050b046;
    }
    // 0050b00d  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b010  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b016  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050b019  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b01b  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x0050b01d:
    // 0050b01d  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b020  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b023  83ed02                 +sub ebp, 2
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
    // 0050b026  79d3                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
    // 0050b028  eb2a                   -jmp 0x50b054
    goto L_0x0050b054;
L_0x0050b02a:
    // 0050b02a  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b02d  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b030  74eb                   -je 0x50b01d
    if (cpu.flags.zf)
    {
        goto L_0x0050b01d;
    }
    // 0050b032  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b035  66895a02               -mov word ptr [edx + 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 0050b039  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b03c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b03f  83ed02                 +sub ebp, 2
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
    // 0050b042  79b7                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
    // 0050b044  eb0e                   -jmp 0x50b054
    goto L_0x0050b054;
L_0x0050b046:
    // 0050b046  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050b049  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050b04c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050b04f  83ed02                 +sub ebp, 2
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
    // 0050b052  79a7                   -jns 0x50affb
    if (!cpu.flags.sf)
    {
        goto L_0x0050affb;
    }
L_0x0050b054:
    // 0050b054  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050b057  83ed01                 +sub ebp, 1
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
    // 0050b05a  7818                   -js 0x50b074
    if (cpu.flags.sf)
    {
        goto L_0x0050b074;
    }
L_0x0050b05c:
    // 0050b05c  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050b05e  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050b061  7411                   -je 0x50b074
    if (cpu.flags.zf)
    {
        goto L_0x0050b074;
    }
    // 0050b063  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 0050b066  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 0050b069  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050b06c  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050b06f  83ed01                 +sub ebp, 1
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
    // 0050b072  79e8                   -jns 0x50b05c
    if (!cpu.flags.sf)
    {
        goto L_0x0050b05c;
    }
L_0x0050b074:
    // 0050b074  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b075  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b076  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50b080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b082  81ec00190000           -sub esp, 0x1900
    (cpu.esp) -= x86::reg32(x86::sreg32(6400 /*0x1900*/));
    // 0050b088  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050b08a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b08c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050b08e  ff1518b0a000           -call dword ptr [0xa0b018]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b094  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050b096  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0050b098  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050b09a  ff1514b0a000           -call dword ptr [0xa0b014]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10530836) /* 0xa0b014 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b0a0  81c400190000           -add esp, 0x1900
    (cpu.esp) += x86::reg32(x86::sreg32(6400 /*0x1900*/));
    // 0050b0a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b0a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b0a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50b0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b0b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b0b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050b0b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b0b3  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b0b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b0b8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050b0bc  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050b0c0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050b0c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050b0c4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050b0c6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050b0c9  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050b0cf  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050b0d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b0d5  0f84d0020000           -je 0x50b3ab
    if (cpu.flags.zf)
    {
        goto L_0x0050b3ab;
    }
L_0x0050b0db:
    // 0050b0db  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050b0de  0fb62d11505600         -movzx ebp, byte ptr [0x565011]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */));
    // 0050b0e5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050b0e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b0eb  8b5720                 -mov edx, dword ptr [edi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0050b0ee  a318b0a000             -mov dword ptr [0xa0b018], eax
    app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */) = cpu.eax;
    // 0050b0f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b0f5  7402                   -je 0x50b0f9
    if (cpu.flags.zf)
    {
        goto L_0x0050b0f9;
    }
    // 0050b0f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x0050b0f9:
    // 0050b0f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050b0fb  752e                   -jne 0x50b12b
    if (!cpu.flags.zf)
    {
        goto L_0x0050b12b;
    }
    // 0050b0fd  b9acf95400             -mov ecx, 0x54f9ac
    cpu.ecx = 5568940 /*0x54f9ac*/;
    // 0050b102  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b103  bbbcf95400             -mov ebx, 0x54f9bc
    cpu.ebx = 5568956 /*0x54f9bc*/;
    // 0050b108  b82f000000             -mov eax, 0x2f
    cpu.eax = 47 /*0x2f*/;
    // 0050b10d  68ecf95400             -push 0x54f9ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569004 /*0x54f9ec*/;
    cpu.esp -= 4;
    // 0050b112  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050b118  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050b11e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050b123  e8e85eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050b128  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0050b12b:
    // 0050b12b  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0050b130  7540                   -jne 0x50b172
    if (!cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b132  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0050b134  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b139  39e8                   +cmp eax, ebp
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
    // 0050b13b  7435                   -je 0x50b172
    if (cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b13d  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b141  0f849f020000           -je 0x50b3e6
    if (cpu.flags.zf)
    {
        goto L_0x0050b3e6;
    }
    // 0050b147  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0050b14c:
    // 0050b14c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b150  e80bf8ffff             -call 0x50a960
    cpu.esp -= 4;
    sub_50a960(app, cpu);
    if (cpu.terminate) return;
    // 0050b155  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050b159  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b15b  0f848c020000           -je 0x50b3ed
    if (cpu.flags.zf)
    {
        goto L_0x0050b3ed;
    }
    // 0050b161  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b165  740b                   -je 0x50b172
    if (cpu.flags.zf)
    {
        goto L_0x0050b172;
    }
    // 0050b167  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b169  a318b0a000             -mov dword ptr [0xa0b018], eax
    app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */) = cpu.eax;
    // 0050b16e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x0050b172:
    // 0050b172  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0050b175  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b178  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b17a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050b17d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050b17f  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050b182  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050b188  40                     -inc eax
    (cpu.eax)++;
    // 0050b189  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050b18b  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0050b18e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050b190  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050b192  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b195  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0050b198  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050b19c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b19e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050b1a2  e819850100             -call 0x5236c0
    cpu.esp -= 4;
    sub_5236c0(app, cpu);
    if (cpu.terminate) return;
    // 0050b1a7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1a9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1ad  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0050b1b1  a104505600             -mov eax, dword ptr [0x565004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050b1b6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1b8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0050b1bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1bd  7e15                   -jle 0x50b1d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b1d4;
    }
    // 0050b1bf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050b1c3  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050b1c6  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1c8  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1cc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b1ce  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b1d0  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0050b1d4:
    // 0050b1d4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b1d8  8b350c505600           -mov esi, dword ptr [0x56500c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 0050b1de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b1e0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1e4  7e02                   -jle 0x50b1e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b1e8;
    }
    // 0050b1e6  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b1e8:
    // 0050b1e8  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b1ec  a100505600             -mov eax, dword ptr [0x565000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050b1f1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b1f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b1f5  7e20                   -jle 0x50b217
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b217;
    }
    // 0050b1f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b1f9  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b1fc  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0050b1ff  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050b202  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b204  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b208  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b20a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b20c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050b20f  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0050b213  01442420               -add dword ptr [esp + 0x20], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b217:
    // 0050b217  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b21b  8b3508505600           -mov esi, dword ptr [0x565008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 0050b221  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050b223  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050b225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b227  7e0e                   -jle 0x50b237
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b237;
    }
    // 0050b229  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b22b  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050b22e  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0050b231  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b233  01742420               -add dword ptr [esp + 0x20], esi
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0050b237:
    // 0050b237  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050b239  0f8e59010000           -jle 0x50b398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b398;
    }
    // 0050b23f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b241  0f8e51010000           -jle 0x50b398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b398;
    }
    // 0050b247  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050b24a  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050b24f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0050b253  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b255  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b25a  40                     -inc eax
    (cpu.eax)++;
    // 0050b25b  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050b25d  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050b260  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0050b263  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0050b266  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0050b26a  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050b26e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b272  8b1d20505600           -mov ebx, dword ptr [0x565020]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b278  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b27b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b27d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b281  8b3524505600           -mov esi, dword ptr [0x565024]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b287  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b28a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b28c  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050b28e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050b290  a11c505600             -mov eax, dword ptr [0x56501c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050b295  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b297  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b29b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b29d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050b2a1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050b2a5  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0050b2a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b2ab  0f857f010000           -jne 0x50b430
    if (!cpu.flags.zf)
    {
        goto L_0x0050b430;
    }
    // 0050b2b1  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b2b6  3c0f                   +cmp al, 0xf
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
    // 0050b2b8  0f837b010000           -jae 0x50b439
    if (!cpu.flags.cf)
    {
        goto L_0x0050b439;
    }
    // 0050b2be  3c04                   +cmp al, 4
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
    // 0050b2c0  0f83bb010000           -jae 0x50b481
    if (!cpu.flags.cf)
    {
        goto L_0x0050b481;
    }
L_0x0050b2c6:
    // 0050b2c6  833d18b0a00000         +cmp dword ptr [0xa0b018], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10530840) /* 0xa0b018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b2cd  0f85cf010000           -jne 0x50b4a2
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4a2;
    }
L_0x0050b2d3:
    // 0050b2d3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b2d7  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0050b2db  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b2df  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0050b2e3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b2e7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b2e9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0050b2ed:
    // 0050b2ed  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b2f1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050b2f3  745a                   -je 0x50b34f
    if (cpu.flags.zf)
    {
        goto L_0x0050b34f;
    }
    // 0050b2f5  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b2f9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050b2fb  a128505600             -mov eax, dword ptr [0x565028]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */);
    // 0050b300  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0050b302  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050b304  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b308  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050b30c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b30e  0f84bd010000           -je 0x50b4d1
    if (cpu.flags.zf)
    {
        goto L_0x0050b4d1;
    }
    // 0050b314  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b316  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x0050b31a:
    // 0050b31a  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b31e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b320  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b322  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b324  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b328  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b32c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b330  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050b334  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b336  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b338  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050b33a  8b1dec435600           -mov ebx, dword ptr [0x5643ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653484) /* 0x5643ec */);
    // 0050b340  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0050b344  39da                   +cmp edx, ebx
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
    // 0050b346  0f8f6d010000           -jg 0x50b4b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b4b9;
    }
L_0x0050b34c:
    // 0050b34c  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b34d  75cb                   -jne 0x50b31a
    if (!cpu.flags.zf)
    {
        goto L_0x0050b31a;
    }
L_0x0050b34f:
    // 0050b34f  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b353  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b355  7436                   -je 0x50b38d
    if (cpu.flags.zf)
    {
        goto L_0x0050b38d;
    }
    // 0050b357  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050b35a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b35c  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b360  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b364  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b366  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b368  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b36c  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b370  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b374  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050b378  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b37c  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050b37e  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b382  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b384  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b386  47                     -inc edi
    (cpu.edi)++;
    // 0050b387  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b389  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x0050b38d:
    // 0050b38d  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 0050b392  0f8f55ffffff           -jg 0x50b2ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b2ed;
    }
L_0x0050b398:
    // 0050b398  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050b39c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b39e  0f858d010000           -jne 0x50b531
    if (!cpu.flags.zf)
    {
        goto L_0x0050b531;
    }
L_0x0050b3a4:
    // 0050b3a4  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b3a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b3aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050b3ab:
    // 0050b3ab  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0050b3ad  b9acf95400             -mov ecx, 0x54f9ac
    cpu.ecx = 5568940 /*0x54f9ac*/;
    // 0050b3b2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b3b7  bbbcf95400             -mov ebx, 0x54f9bc
    cpu.ebx = 5568956 /*0x54f9bc*/;
    // 0050b3bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050b3bd  bd26000000             -mov ebp, 0x26
    cpu.ebp = 38 /*0x26*/;
    // 0050b3c2  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050b3c8  68c4f95400             -push 0x54f9c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5568964 /*0x54f9c4*/;
    cpu.esp -= 4;
    // 0050b3cd  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050b3d3  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050b3d9  e8325cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050b3de  83c408                 +add esp, 8
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
    // 0050b3e1  e9f5fcffff             -jmp 0x50b0db
    goto L_0x0050b0db;
L_0x0050b3e6:
    // 0050b3e6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050b3e8  e95ffdffff             -jmp 0x50b14c
    goto L_0x0050b14c;
L_0x0050b3ed:
    // 0050b3ed  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b3f1  7423                   -je 0x50b416
    if (cpu.flags.zf)
    {
        goto L_0x0050b416;
    }
    // 0050b3f3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0050b3f8:
    // 0050b3f8  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0050b3fb  83f801                 +cmp eax, 1
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
    // 0050b3fe  751a                   -jne 0x50b41a
    if (!cpu.flags.zf)
    {
        goto L_0x0050b41a;
    }
    // 0050b400  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050b402  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b404  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b406  e8c5f6ffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050b40b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050b40f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b411  e95cfdffff             -jmp 0x50b172
    goto L_0x0050b172;
L_0x0050b416:
    // 0050b416  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0050b418  ebde                   -jmp 0x50b3f8
    goto L_0x0050b3f8;
L_0x0050b41a:
    // 0050b41a  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050b41c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050b41e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b420  e8abf6ffff             -call 0x50aad0
    cpu.esp -= 4;
    sub_50aad0(app, cpu);
    if (cpu.terminate) return;
    // 0050b425  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050b429  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b42b  e942fdffff             -jmp 0x50b172
    goto L_0x0050b172;
L_0x0050b430:
    // 0050b430  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b434  e99afeffff             -jmp 0x50b2d3
    goto L_0x0050b2d3;
L_0x0050b439:
    // 0050b439  770c                   -ja 0x50b447
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b447;
    }
    // 0050b43b  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050b43e  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b442  e97ffeffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b447:
    // 0050b447  3c18                   +cmp al, 0x18
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
    // 0050b449  7314                   -jae 0x50b45f
    if (!cpu.flags.cf)
    {
        goto L_0x0050b45f;
    }
    // 0050b44b  3c10                   +cmp al, 0x10
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
    // 0050b44d  0f8573feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b453  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050b456  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b45a  e967feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b45f:
    // 0050b45f  770c                   -ja 0x50b46d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b46d;
    }
    // 0050b461  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050b464  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b468  e959feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b46d:
    // 0050b46d  3c20                   +cmp al, 0x20
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
    // 0050b46f  0f8551feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b475  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050b478  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b47c  e945feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b481:
    // 0050b481  770b                   -ja 0x50b48e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050b48e;
    }
    // 0050b483  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050b485  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b489  e938feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b48e:
    // 0050b48e  3c08                   +cmp al, 8
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
    // 0050b490  0f8530feffff           -jne 0x50b2c6
    if (!cpu.flags.zf)
    {
        goto L_0x0050b2c6;
    }
    // 0050b496  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0050b499  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0050b49d  e924feffff             -jmp 0x50b2c6
    goto L_0x0050b2c6;
L_0x0050b4a2:
    // 0050b4a2  bb80b05000             -mov ebx, 0x50b080
    cpu.ebx = 5288064 /*0x50b080*/;
    // 0050b4a7  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050b4ab  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0050b4af  a314b0a000             -mov dword ptr [0xa0b014], eax
    app->getMemory<x86::reg32>(x86::reg32(10530836) /* 0xa0b014 */) = cpu.eax;
    // 0050b4b4  e91afeffff             -jmp 0x50b2d3
    goto L_0x0050b2d3;
L_0x0050b4b9:
    // 0050b4b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b4bb  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0050b4bf  e81cdcfeff             -call 0x4f90e0
    cpu.esp -= 4;
    sub_4f90e0(app, cpu);
    if (cpu.terminate) return;
    // 0050b4c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b4c6  0f84d8feffff           -je 0x50b3a4
    if (cpu.flags.zf)
    {
        goto L_0x0050b3a4;
    }
    // 0050b4cc  e97bfeffff             -jmp 0x50b34c
    goto L_0x0050b34c;
L_0x0050b4d1:
    // 0050b4d1  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b4d6  7422                   -je 0x50b4fa
    if (cpu.flags.zf)
    {
        goto L_0x0050b4fa;
    }
L_0x0050b4d8:
    // 0050b4d8  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b4dc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b4de  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b4e0  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b4e2  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b4e6  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b4ea  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b4ee  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b4f0  01d1                   +add ecx, edx
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
    // 0050b4f2  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b4f3  75e3                   -jne 0x50b4d8
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b4f5  e955feffff             -jmp 0x50b34f
    goto L_0x0050b34f;
L_0x0050b4fa:
    // 0050b4fa  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 0050b4ff  75d7                   -jne 0x50b4d8
    if (!cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b501  817c243880b05000       +cmp dword ptr [esp + 0x38], 0x50b080
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5288064 /*0x50b080*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b509  74cd                   -je 0x50b4d8
    if (cpu.flags.zf)
    {
        goto L_0x0050b4d8;
    }
    // 0050b50b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050b50d  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0050b510  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050b514  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b516  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050b518  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050b51c  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050b520  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0050b523  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0050b528  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b52a  01f9                   +add ecx, edi
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
    // 0050b52c  e91efeffff             -jmp 0x50b34f
    goto L_0x0050b34f;
L_0x0050b531:
    // 0050b531  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050b533  e85863fdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0050b538  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050b53b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b53e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_50b540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b541  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050b542  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050b544  42                     -inc edx
    (cpu.edx)++;
    // 0050b545  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b547  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050b54a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050b54c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b54e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b54f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50b560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b560  83f820                 +cmp eax, 0x20
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
    // 0050b563  7c12                   -jl 0x50b577
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b577;
    }
    // 0050b565  83f87f                 +cmp eax, 0x7f
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
    // 0050b568  7f0d                   -jg 0x50b577
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050b577;
    }
    // 0050b56a  668b044594855600       -mov ax, word ptr [eax*2 + 0x568594]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5670292) /* 0x568594 */ + cpu.eax * 2);
    // 0050b572  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x0050b577:
    // 0050b577  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50b580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050b581  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050b582  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b584  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050b586  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0050b588  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0050b58a  42                     -inc edx
    (cpu.edx)++;
    // 0050b58b  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050b58d  7416                   -je 0x50b5a5
    if (cpu.flags.zf)
    {
        goto L_0x0050b5a5;
    }
    // 0050b58f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050b590  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0050b592  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050b595  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050b597  42                     -inc edx
    (cpu.edx)++;
    // 0050b598  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b59a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b59b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0050b59d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050b5a5:
    // 0050b5a5  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5aa  e8b1ffffff             -call 0x50b560
    cpu.esp -= 4;
    sub_50b560(app, cpu);
    if (cpu.terminate) return;
    // 0050b5af  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0050b5b1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050b5b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b5b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50b5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050b5c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050b5c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050b5c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050b5c3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050b5c6  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050b5ca  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0050b5ce  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0050b5d2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050b5d6  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050b5d9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b5db  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050b5de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050b5e1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b5e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050b5e5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050b5e7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050b5e9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0050b5ec  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b5f0  40                     -inc eax
    (cpu.eax)++;
    // 0050b5f1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050b5f3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050b5f7  8a2512505600           -mov ah, byte ptr [0x565012]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */);
    // 0050b5fd  8b2d80725600           -mov ebp, dword ptr [0x567280]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050b603  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0050b605  0f8585030000           -jne 0x50b990
    if (!cpu.flags.zf)
    {
        goto L_0x0050b990;
    }
    // 0050b60b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b60f  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b615  0f8c75030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b61b  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b621  0f8d69030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b627  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b62b  3b0504505600           +cmp eax, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b631  0f8c59030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b637  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b63d  0f8d4d030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b643  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b647  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b64b  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050b651  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b653  39d8                   +cmp eax, ebx
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
    // 0050b655  0f8c35030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b65b  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b661  0f8d29030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b667  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b66b  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b66f  8b1d04505600           -mov ebx, dword ptr [0x565004]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050b675  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b677  39d8                   +cmp eax, ebx
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
    // 0050b679  0f8c11030000           -jl 0x50b990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b67f  3b050c505600           +cmp eax, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050b685  0f8d05030000           -jge 0x50b990
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b990;
    }
    // 0050b68b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b68f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b691  8a1510505600           -mov dl, byte ptr [0x565010]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050b697  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b699  80fa10                 +cmp dl, 0x10
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
    // 0050b69c  0f8565010000           -jne 0x50b807
    if (!cpu.flags.zf)
    {
        goto L_0x0050b807;
    }
    // 0050b6a2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0050b6a5:
    // 0050b6a5  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b6a9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b6ad  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b6b3  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0050b6b6  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b6bc  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0050b6bf  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 0050b6c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b6c7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b6cb  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0050b6cf:
    // 0050b6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b6d1  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0050b6d3  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0050b6d6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b6da  81fb00000010           +cmp ebx, 0x10000000
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
    // 0050b6e0  726b                   -jb 0x50b74d
    if (cpu.flags.cf)
    {
        goto L_0x0050b74d;
    }
    // 0050b6e2  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0050b6e8  7340                   -jae 0x50b72a
    if (!cpu.flags.cf)
    {
        goto L_0x0050b72a;
    }
    // 0050b6ea  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050b6ed  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b6ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b6f1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050b6f4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050b6f7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050b6f9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050b6ff  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050b702  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050b707  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b70a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b70c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b70e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b711  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b713  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050b716  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b718  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b71b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b721  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b726  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b728  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b72a:
    // 0050b72a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b72c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b732  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050b735  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b737  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b73a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050b740  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b743  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b746  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b748  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b74a  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b74d:
    // 0050b74d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b750  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b752  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0050b754  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b757  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b75b  81fb00000010           +cmp ebx, 0x10000000
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
    // 0050b761  726b                   -jb 0x50b7ce
    if (cpu.flags.cf)
    {
        goto L_0x0050b7ce;
    }
    // 0050b763  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0050b769  7340                   -jae 0x50b7ab
    if (!cpu.flags.cf)
    {
        goto L_0x0050b7ab;
    }
    // 0050b76b  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050b76e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b770  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b772  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050b775  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050b778  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050b77a  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050b780  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050b783  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050b788  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b78b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b78d  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b78f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b792  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b794  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050b797  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b799  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b79c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b7a2  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b7a7  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b7a9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b7ab:
    // 0050b7ab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b7ad  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b7b3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050b7b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b7b8  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b7bb  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050b7c1  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b7c4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b7c7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b7c9  01d3                   +add ebx, edx
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
    // 0050b7cb  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b7ce:
    // 0050b7ce  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b7d1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050b7d5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050b7d6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b7d7  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0050b7db  0f85eefeffff           -jne 0x50b6cf
    if (!cpu.flags.zf)
    {
        goto L_0x0050b6cf;
    }
    // 0050b7e1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b7e5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0050b7e8  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b7ec  41                     -inc ecx
    (cpu.ecx)++;
    // 0050b7ed  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050b7ef  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050b7f3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b7f4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0050b7f8  0f85a7feffff           -jne 0x50b6a5
    if (!cpu.flags.zf)
    {
        goto L_0x0050b6a5;
    }
L_0x0050b7fe:
    // 0050b7fe  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050b801  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b802  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b803  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050b804  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050b807:
    // 0050b807  80fa0f                 +cmp dl, 0xf
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
    // 0050b80a  0f8577010000           -jne 0x50b987
    if (!cpu.flags.zf)
    {
        goto L_0x0050b987;
    }
    // 0050b810  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0050b814:
    // 0050b814  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b818  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b81c  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050b822  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0050b825  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050b82b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0050b82e  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 0050b834  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050b836  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b83a  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x0050b83e:
    // 0050b83e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b840  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0050b842  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0050b845  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050b848  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0050b84b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050b84d  81fb00000010           +cmp ebx, 0x10000000
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
    // 0050b853  7273                   -jb 0x50b8c8
    if (cpu.flags.cf)
    {
        goto L_0x0050b8c8;
    }
    // 0050b855  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0050b85b  7348                   -jae 0x50b8a5
    if (!cpu.flags.cf)
    {
        goto L_0x0050b8a5;
    }
    // 0050b85d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050b860  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b862  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050b867  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050b86a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b86c  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050b872  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050b875  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b877  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b87a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b87c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b87e  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b881  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b887  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b889  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b88c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b88e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b890  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b893  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b899  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b89b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b89e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b8a3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b8a5:
    // 0050b8a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b8a7  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b8ad  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050b8b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b8b2  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b8b5  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050b8bb  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050b8be  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b8c1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b8c3  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b8c5  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b8c8:
    // 0050b8c8  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b8cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050b8cd  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0050b8cf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b8d2  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b8d6  81fb00000010           +cmp ebx, 0x10000000
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
    // 0050b8dc  7273                   -jb 0x50b951
    if (cpu.flags.cf)
    {
        goto L_0x0050b951;
    }
    // 0050b8de  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0050b8e4  7348                   -jae 0x50b92e
    if (!cpu.flags.cf)
    {
        goto L_0x0050b92e;
    }
    // 0050b8e6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050b8e9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050b8eb  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050b8f0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050b8f3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050b8f5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050b8fb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050b8fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b900  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b903  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b905  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050b907  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050b90a  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b910  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050b912  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050b915  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b917  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b919  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050b91c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050b922  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050b924  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050b927  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050b92c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050b92e:
    // 0050b92e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b930  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050b936  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050b939  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050b93b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050b93e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050b944  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050b947  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050b94a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050b94c  01d3                   +add ebx, edx
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
    // 0050b94e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050b951:
    // 0050b951  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050b954  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0050b958  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050b959  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b95a  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0050b95e  0f85dafeffff           -jne 0x50b83e
    if (!cpu.flags.zf)
    {
        goto L_0x0050b83e;
    }
    // 0050b964  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b968  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050b96c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b970  40                     -inc eax
    (cpu.eax)++;
    // 0050b971  01f7                   +add edi, esi
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
    // 0050b973  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050b977  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050b978  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0050b97c  0f847cfeffff           -je 0x50b7fe
    if (cpu.flags.zf)
    {
        goto L_0x0050b7fe;
    }
    // 0050b982  e98dfeffff             -jmp 0x50b814
    goto L_0x0050b814;
L_0x0050b987:
    // 0050b987  80fa08                 +cmp dl, 8
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
    // 0050b98a  0f849c000000           -je 0x50ba2c
    if (cpu.flags.zf)
    {
        goto L_0x0050ba2c;
    }
L_0x0050b990:
    // 0050b990  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0050b994  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050b996  0f8e62feffff           -jle 0x50b7fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050b7fe;
    }
    // 0050b99c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050b9a0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050b9a4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050b9a8  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b9aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b9ac  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050b9b0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050b9b4:
    // 0050b9b4  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050b9b8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050b9ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050b9bc  7e51                   -jle 0x50ba0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ba0f;
    }
    // 0050b9be  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050b9c2  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050b9c6  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050b9ca  46                     -inc esi
    (cpu.esi)++;
    // 0050b9cb  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0050b9cf:
    // 0050b9cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050b9d1  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0050b9d3  47                     -inc edi
    (cpu.edi)++;
    // 0050b9d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050b9d6  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050b9d9  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0050b9dc  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050b9e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050b9e2  0f858f000000           -jne 0x50ba77
    if (!cpu.flags.zf)
    {
        goto L_0x0050ba77;
    }
L_0x0050b9e8:
    // 0050b9e8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050b9ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050b9ee  7411                   -je 0x50ba01
    if (cpu.flags.zf)
    {
        goto L_0x0050ba01;
    }
    // 0050b9f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050b9f2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050b9f6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050b9fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050b9fc  e85f7d0100             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
L_0x0050ba01:
    // 0050ba01  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050ba05  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050ba08  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050ba0b  39c1                   +cmp ecx, eax
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
    // 0050ba0d  7cc0                   -jl 0x50b9cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050b9cf;
    }
L_0x0050ba0f:
    // 0050ba0f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050ba13  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050ba17  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050ba1b  46                     -inc esi
    (cpu.esi)++;
    // 0050ba1c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050ba1e  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0050ba22  39d6                   +cmp esi, edx
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
    // 0050ba24  0f8dd4fdffff           -jge 0x50b7fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050b7fe;
    }
    // 0050ba2a  eb88                   -jmp 0x50b9b4
    goto L_0x0050b9b4;
L_0x0050ba2c:
    // 0050ba2c  8b1d1c505600           -mov ebx, dword ptr [0x56501c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050ba32  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba34  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ba37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba38  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050ba3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ba3d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050ba41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba42  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050ba46  8b0d20505600           -mov ecx, dword ptr [0x565020]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050ba4c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050ba4f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ba51  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050ba56  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0050ba58  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050ba5c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ba5e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ba60  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ba61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ba62  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050ba65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ba66  e8817f0100             -call 0x5239ec
    cpu.esp -= 4;
    sub_5239ec(app, cpu);
    if (cpu.terminate) return;
    // 0050ba6b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0050ba6e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0050ba71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ba74  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050ba77:
    // 0050ba77  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0050ba7b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050ba7f  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050ba83  01c8                   +add eax, ecx
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
    // 0050ba85  e8d67c0100             -call 0x523760
    cpu.esp -= 4;
    sub_523760(app, cpu);
    if (cpu.terminate) return;
    // 0050ba8a  e959ffffff             -jmp 0x50b9e8
    goto L_0x0050b9e8;
}

/* align: skip 0x90 */
void Application::sub_50ba90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ba90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ba91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ba92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ba93  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050ba96  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0050ba9a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050ba9e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0050baa2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050baa4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050baa6  0f8eae000000           -jle 0x50bb5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bb5a;
    }
    // 0050baac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050baae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050bab0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bab3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bab5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0050bab7  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0050babb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050babe  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050bac1  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 0050bac6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050bac9  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0050bacd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bacf  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bad1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050bad3  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050bad7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050badb:
    // 0050badb  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050badf  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0050bae2  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050bae6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bae8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050baea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050baec  7e4d                   -jle 0x50bb3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bb3b;
    }
    // 0050baee  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050baf2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050baf6  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050bafa  46                     -inc esi
    (cpu.esi)++;
    // 0050bafb  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0050baff:
    // 0050baff  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0050bb02  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bb04  47                     -inc edi
    (cpu.edi)++;
    // 0050bb05  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0050bb08  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050bb0b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050bb0d  7554                   -jne 0x50bb63
    if (!cpu.flags.zf)
    {
        goto L_0x0050bb63;
    }
L_0x0050bb0f:
    // 0050bb0f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050bb11  741a                   -je 0x50bb2d
    if (cpu.flags.zf)
    {
        goto L_0x0050bb2d;
    }
    // 0050bb13  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 0050bb1a  81c328725600           -add ebx, 0x567228
    (cpu.ebx) += x86::reg32(x86::sreg32(5665320 /*0x567228*/));
    // 0050bb20  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bb24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050bb26  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050bb28  e8d37f0100             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
L_0x0050bb2d:
    // 0050bb2d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0050bb31  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050bb34  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050bb37  39e9                   +cmp ecx, ebp
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
    // 0050bb39  7cc4                   -jl 0x50baff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050baff;
    }
L_0x0050bb3b:
    // 0050bb3b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050bb3f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050bb43  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050bb47  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050bb4b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bb4d  41                     -inc ecx
    (cpu.ecx)++;
    // 0050bb4e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050bb52  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050bb56  39d9                   +cmp ecx, ebx
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
    // 0050bb58  7c81                   -jl 0x50badb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050badb;
    }
L_0x0050bb5a:
    // 0050bb5a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050bb5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bb60  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050bb63:
    // 0050bb63  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0050bb66  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bb6a  81c328725600           -add ebx, 0x567228
    (cpu.ebx) += x86::reg32(x86::sreg32(5665320 /*0x567228*/));
    // 0050bb70  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050bb74  01c8                   +add eax, ecx
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
    // 0050bb76  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050bb78  e8837f0100             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 0050bb7d  eb90                   -jmp 0x50bb0f
    goto L_0x0050bb0f;
}

/* align: skip 0x90 */
void Application::sub_50bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bb80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bb81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bb82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bb83  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0050bb86  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050bb88  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050bb8c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050bb90  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0050bb94  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050bb99  3c10                   +cmp al, 0x10
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
    // 0050bb9b  7347                   -jae 0x50bbe4
    if (!cpu.flags.cf)
    {
        goto L_0x0050bbe4;
    }
    // 0050bb9d  3c08                   +cmp al, 8
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
    // 0050bb9f  0f83cd010000           -jae 0x50bd72
    if (!cpu.flags.cf)
    {
        goto L_0x0050bd72;
    }
L_0x0050bba5:
    // 0050bba5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bba7  bb18fa5400             -mov ebx, 0x54fa18
    cpu.ebx = 5569048 /*0x54fa18*/;
    // 0050bbac  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050bbb1  be28fa5400             -mov esi, 0x54fa28
    cpu.esi = 5569064 /*0x54fa28*/;
    // 0050bbb6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050bbb7  bff1000000             -mov edi, 0xf1
    cpu.edi = 241 /*0xf1*/;
    // 0050bbbc  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050bbc2  6834fa5400             -push 0x54fa34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569076 /*0x54fa34*/;
    cpu.esp -= 4;
    // 0050bbc7  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050bbcd  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050bbd3  e83854efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050bbd8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0050bbdb:
    // 0050bbdb  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050bbde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bbe1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0050bbe4:
    // 0050bbe4  0f8762010000           -ja 0x50bd4c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd4c;
    }
L_0x0050bbea:
    // 0050bbea  bf70c25000             -mov edi, 0x50c270
    cpu.edi = 5292656 /*0x50c270*/;
L_0x0050bbef:
    // 0050bbef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050bbf1  74b2                   -je 0x50bba5
    if (cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bbf3  8b2d00505600           -mov ebp, dword ptr [0x565000]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 0050bbf9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bbfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bbfd  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050bc01  39ee                   +cmp esi, ebp
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
    // 0050bc03  7d04                   -jge 0x50bc09
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bc09;
    }
    // 0050bc05  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050bc07  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0050bc09:
    // 0050bc09  8b0d04505600           -mov ecx, dword ptr [0x565004]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 0050bc0f  39ca                   +cmp edx, ecx
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
    // 0050bc11  7d06                   -jge 0x50bc19
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bc19;
    }
    // 0050bc13  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc15  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x0050bc19:
    // 0050bc19  8b2d08505600           -mov ebp, dword ptr [0x565008]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 0050bc1f  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 0050bc22  39e9                   +cmp ecx, ebp
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
    // 0050bc24  7e04                   -jle 0x50bc2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bc2a;
    }
    // 0050bc26  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bc28  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0050bc2a:
    // 0050bc2a  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050bc2e  8b2d0c505600           -mov ebp, dword ptr [0x56500c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 0050bc34  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc36  39e9                   +cmp ecx, ebp
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
    // 0050bc38  7e08                   -jle 0x50bc42
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bc42;
    }
    // 0050bc3a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0050bc3c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bc3e  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x0050bc42:
    // 0050bc42  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050bc44  7c95                   -jl 0x50bbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc46  837c244400             +cmp dword ptr [esp + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bc4b  7c8e                   -jl 0x50bbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc4d  39d8                   +cmp eax, ebx
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
    // 0050bc4f  7d8a                   -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc51  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bc55  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bc59  7d80                   -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bc5b  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050bc5f  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0050bc63  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 0050bc68  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050bc6b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050bc6f  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050bc72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050bc74  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0050bc77  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0050bc7a  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050bc7d  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050bc81  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bc83  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0050bc86  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050bc8a  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050bc8d  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0050bc91  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0050bc95  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0050bc99  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0050bc9c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050bca0  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050bca4  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0050bcaa  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bcac  8b2d14505600           -mov ebp, dword ptr [0x565014]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 0050bcb2  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0050bcb4  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0050bcba  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bcbc  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0050bcbf  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050bcc2  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050bcc4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050bcc6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050bcc8  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050bccb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050bccd  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0050bcd1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050bcd4  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0050bcd8  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bcda  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050bcdd  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050bce1  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050bce3  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0050bce8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0050bcea  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 0050bcec  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
    // 0050bcf0  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0050bcf4  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0050bcf6  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 0050bcf8  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
L_0x0050bcfc:
    // 0050bcfc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0050bd00  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050bd03  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0050bd07  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0050bd0b  39c8                   +cmp eax, ecx
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
    // 0050bd0d  0f8dc8feffff           -jge 0x50bbdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050bbdb;
    }
    // 0050bd13  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050bd17  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bd1b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050bd1f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bd21  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 0050bd25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050bd27  7562                   -jne 0x50bd8b
    if (!cpu.flags.zf)
    {
        goto L_0x0050bd8b;
    }
L_0x0050bd29:
    // 0050bd29  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 0050bd2e  0f858f000000           -jne 0x50bdc3
    if (!cpu.flags.zf)
    {
        goto L_0x0050bdc3;
    }
L_0x0050bd34:
    // 0050bd34  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0050bd38  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050bd3c  8b1d1c505600           -mov ebx, dword ptr [0x56501c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 0050bd42  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bd44  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050bd46  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050bd4a  ebb0                   -jmp 0x50bcfc
    goto L_0x0050bcfc;
L_0x0050bd4c:
    // 0050bd4c  3c18                   +cmp al, 0x18
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
    // 0050bd4e  0f8251feffff           -jb 0x50bba5
    if (cpu.flags.cf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd54  770a                   -ja 0x50bd60
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd60;
    }
    // 0050bd56  bfc0c25000             -mov edi, 0x50c2c0
    cpu.edi = 5292736 /*0x50c2c0*/;
    // 0050bd5b  e98ffeffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd60:
    // 0050bd60  3c20                   +cmp al, 0x20
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
    // 0050bd62  0f853dfeffff           -jne 0x50bba5
    if (!cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd68  bf50c35000             -mov edi, 0x50c350
    cpu.edi = 5292880 /*0x50c350*/;
    // 0050bd6d  e97dfeffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd72:
    // 0050bd72  770a                   -ja 0x50bd7e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050bd7e;
    }
    // 0050bd74  bf20c25000             -mov edi, 0x50c220
    cpu.edi = 5292576 /*0x50c220*/;
    // 0050bd79  e971feffff             -jmp 0x50bbef
    goto L_0x0050bbef;
L_0x0050bd7e:
    // 0050bd7e  3c0f                   +cmp al, 0xf
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
    // 0050bd80  0f851ffeffff           -jne 0x50bba5
    if (!cpu.flags.zf)
    {
        goto L_0x0050bba5;
    }
    // 0050bd86  e95ffeffff             -jmp 0x50bbea
    goto L_0x0050bbea;
L_0x0050bd8b:
    // 0050bd8b  8a5c2420               -mov bl, byte ptr [esp + 0x20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050bd8f  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bd91  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bd97  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 0050bd99  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050bd9e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0050bda0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bda2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bda4  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0050bda6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050bda7  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x0050bdab:
    // 0050bdab  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050bdac  0f8477ffffff           -je 0x50bd29
    if (cpu.flags.zf)
    {
        goto L_0x0050bd29;
    }
    // 0050bdb2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050bdb4  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bdba  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bdbc  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050bdbd  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bdbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bdc1  ebe8                   -jmp 0x50bdab
    goto L_0x0050bdab;
L_0x0050bdc3:
    // 0050bdc3  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bdc5  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050bdc9  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050bdcd  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 0050bdcf  8b1520725600           -mov edx, dword ptr [0x567220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050bdd5  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 0050bdd7  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050bddc  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050bdde  e951ffffff             -jmp 0x50bd34
    goto L_0x0050bd34;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50bdf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bdf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050bdf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050bdf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bdf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bdf4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bdf5  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0050bdfb  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0050be02  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 0050be09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be0b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0050be0d:
    // 0050be0d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050be10  8b8814a8a000           -mov ecx, dword ptr [eax + 0xa0a814]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be16  8b9814a8a000           -mov ebx, dword ptr [eax + 0xa0a814]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be1c  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0050be1f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050be22  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 0050be26  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 0050be2a  8a9814a8a000           -mov bl, byte ptr [eax + 0xa0a814]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10528788) /* 0xa0a814 */);
    // 0050be30  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050be33  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 0050be37  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050be3c  75cf                   -jne 0x50be0d
    if (!cpu.flags.zf)
    {
        goto L_0x0050be0d;
    }
    // 0050be3e  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0050be45  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050be47  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050be4a  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 0050be51  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x0050be58:
    // 0050be58  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0050be5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be61  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 0050be64  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 0050be6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be6d  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 0050be71  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 0050be78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050be7a  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0050be81  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 0050be85  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050be87  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x0050be8e:
    // 0050be8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050be90  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0050be93  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050be95  754b                   -jne 0x50bee2
    if (!cpu.flags.zf)
    {
        goto L_0x0050bee2;
    }
    // 0050be97  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0050be99:
    // 0050be99  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050be9b  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 0050bea2  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0050bea4  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 0050beab  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bead  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050beb0  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0050beb6  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0050beb8  39e9                   +cmp ecx, ebp
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
    // 0050beba  75d2                   -jne 0x50be8e
    if (!cpu.flags.zf)
    {
        goto L_0x0050be8e;
    }
    // 0050bebc  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0050bec3  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050bec6  47                     -inc edi
    (cpu.edi)++;
    // 0050bec7  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0050bece  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050bed4  7c82                   -jl 0x50be58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050be58;
    }
    // 0050bed6  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 0050bedc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bedd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bede  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bedf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bee0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050bee1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050bee2:
    // 0050bee2  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0050bee7  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 0050beee  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050bef0  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 0050bef7  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050befa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050befc  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0050beff  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 0050bf06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050bf08  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050bf0a  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 0050bf15  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 0050bf1c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf1e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf21  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf28  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 0050bf2f  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 0050bf33  3dff000000             +cmp eax, 0xff
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
    // 0050bf38  7e05                   -jle 0x50bf3f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf3f;
    }
    // 0050bf3a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050bf3f:
    // 0050bf3f  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 0050bf46  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050bf49  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 0050bf54  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 0050bf5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf5d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf60  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf67  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bf69  3dff000000             +cmp eax, 0xff
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
    // 0050bf6e  7e05                   -jle 0x50bf75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf75;
    }
    // 0050bf70  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050bf75:
    // 0050bf75  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 0050bf7c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0050bf7f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050bf81  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0050bf86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050bf88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050bf8b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050bf8d  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 0050bf94  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050bf96  39da                   +cmp edx, ebx
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
    // 0050bf98  7e02                   -jle 0x50bf9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050bf9c;
    }
    // 0050bf9a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0050bf9c:
    // 0050bf9c  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 0050bfa3  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 0050bfaa  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0050bfad  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050bfb0  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 0050bfb3  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050bfb5  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050bfb7  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050bfb9  e8a237feff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0050bfbe  e9d6feffff             -jmp 0x50be99
    goto L_0x0050be99;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50bfd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050bfd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050bfd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050bfd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050bfd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050bfd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050bfd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050bfd6  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050bfd9  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050bfdf  e8bc030000             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0050bfe4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050bfe6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050bfe8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050bfed  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050bff0  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050bff3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050bff6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050bffc  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0050c000  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050c003  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0050c006  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c00c  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0050c010  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 0050c013  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c015  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050c019  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0050c01c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c01e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0050c022:
    // 0050c022  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c02a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c02c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c02e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c031  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c035  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c03d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050c03f  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0050c042  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050c044  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c047  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c04b  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c053  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050c055  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0050c058  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c05a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c05d  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c061  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0050c069  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050c06b  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0050c06e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050c070  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050c073  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050c077  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c07a  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c080  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0050c083  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0050c086  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050c08a  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050c08c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050c090  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050c092  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c096  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050c098  39c1                   +cmp ecx, eax
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
    // 0050c09a  7586                   -jne 0x50c022
    if (!cpu.flags.zf)
    {
        goto L_0x0050c022;
    }
    // 0050c09c  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c0a3  760a                   -jbe 0x50c0af
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c0af;
    }
    // 0050c0a5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050c0a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c0af:
    // 0050c0af  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c0b5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050c0b9  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050c0bc  e82ffdffff             -call 0x50bdf0
    cpu.esp -= 4;
    sub_50bdf0(app, cpu);
    if (cpu.terminate) return;
    // 0050c0c1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050c0c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c0ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50c0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c0d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c0d1  833d8072560000         +cmp dword ptr [0x567280], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c0d8  754b                   -jne 0x50c125
    if (!cpu.flags.zf)
    {
        goto L_0x0050c125;
    }
    // 0050c0da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c0db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c0dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c0dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c0de  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 0050c0e3  bb18fa5400             -mov ebx, 0x54fa18
    cpu.ebx = 5569048 /*0x54fa18*/;
    // 0050c0e8  be60fa5400             -mov esi, 0x54fa60
    cpu.esi = 5569120 /*0x54fa60*/;
    // 0050c0ed  bf50010000             -mov edi, 0x150
    cpu.edi = 336 /*0x150*/;
    // 0050c0f2  b870fa5400             -mov eax, 0x54fa70
    cpu.eax = 5569136 /*0x54fa70*/;
    // 0050c0f7  890d84725600           -mov dword ptr [0x567284], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665412) /* 0x567284 */) = cpu.ecx;
    // 0050c0fd  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050c103  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050c109  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050c10b  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0050c111  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050c117  e80455fdff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0050c11c  a380725600             -mov dword ptr [0x567280], eax
    app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */) = cpu.eax;
    // 0050c121  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c122  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c123  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050c125:
    // 0050c125  e856000000             -call 0x50c180
    cpu.esp -= 4;
    sub_50c180(app, cpu);
    if (cpu.terminate) return;
    // 0050c12a  833d0872560001         +cmp dword ptr [0x567208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665288) /* 0x567208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c131  7423                   -je 0x50c156
    if (cpu.flags.zf)
    {
        goto L_0x0050c156;
    }
    // 0050c133  833d0c72560000         +cmp dword ptr [0x56720c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c13a  7426                   -je 0x50c162
    if (cpu.flags.zf)
    {
        goto L_0x0050c162;
    }
    // 0050c13c  c70588725600c0b55000   -mov dword ptr [0x567288], 0x50b5c0
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5289408 /*0x50b5c0*/;
L_0x0050c146:
    // 0050c146  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0050c148  893590725600           -mov dword ptr [0x567290], esi
    app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.esi;
    // 0050c14e  89358c725600           -mov dword ptr [0x56728c], esi
    app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.esi;
    // 0050c154  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c155  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c156:
    // 0050c156  c7058872560080bb5000   -mov dword ptr [0x567288], 0x50bb80
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5290880 /*0x50bb80*/;
    // 0050c160  ebe4                   -jmp 0x50c146
    goto L_0x0050c146;
L_0x0050c162:
    // 0050c162  c7058872560090ba5000   -mov dword ptr [0x567288], 0x50ba90
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = 5290640 /*0x50ba90*/;
    // 0050c16c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c16e  893590725600           -mov dword ptr [0x567290], esi
    app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.esi;
    // 0050c174  89358c725600           -mov dword ptr [0x56728c], esi
    app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.esi;
    // 0050c17a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c17b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_50c180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c181  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c182  833da472560000         +cmp dword ptr [0x5672a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665444) /* 0x5672a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c189  7515                   -jne 0x50c1a0
    if (!cpu.flags.zf)
    {
        goto L_0x0050c1a0;
    }
    // 0050c18b  833d0c72560000         +cmp dword ptr [0x56720c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c192  7409                   -je 0x50c19d
    if (cpu.flags.zf)
    {
        goto L_0x0050c19d;
    }
    // 0050c194  833d0872560004         +cmp dword ptr [0x567208], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665288) /* 0x567208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c19b  7431                   -je 0x50c1ce
    if (cpu.flags.zf)
    {
        goto L_0x0050c1ce;
    }
L_0x0050c19d:
    // 0050c19d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c19e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c19f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1a0:
    // 0050c1a0  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0050c1a5  b828725600             -mov eax, 0x567228
    cpu.eax = 5665320 /*0x567228*/;
    // 0050c1aa  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1b0  e83be3fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1b5  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c1bc  77df                   -ja 0x50c19d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050c19d;
    }
    // 0050c1be  a180725600             -mov eax, dword ptr [0x567280]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1c3  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0050c1c6  e825fcffff             -call 0x50bdf0
    cpu.esp -= 4;
    sub_50bdf0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1ce:
    // 0050c1ce  a120725600             -mov eax, dword ptr [0x567220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0050c1d3  e8f8fdffff             -call 0x50bfd0
    cpu.esp -= 4;
    sub_50bfd0(app, cpu);
    if (cpu.terminate) return;
    // 0050c1d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50c1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c1e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c1e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c1e2  8b1580725600           -mov edx, dword ptr [0x567280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */);
    // 0050c1e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c1ea  750b                   -jne 0x50c1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0050c1f7;
    }
    // 0050c1ec  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c1ee  893588725600           -mov dword ptr [0x567288], esi
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.esi;
    // 0050c1f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c1f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c1f7:
    // 0050c1f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c1f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c1fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c1fc  e88f56fdff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0050c201  890d80725600           -mov dword ptr [0x567280], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665408) /* 0x567280 */) = cpu.ecx;
    // 0050c207  890d84725600           -mov dword ptr [0x567284], ecx
    app->getMemory<x86::reg32>(x86::reg32(5665412) /* 0x567284 */) = cpu.ecx;
    // 0050c20d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c20e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c210  893588725600           -mov dword ptr [0x567288], esi
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.esi;
    // 0050c216  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c217  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c218  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50c220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c220  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c222  7532                   -jne 0x50c256
    if (!cpu.flags.zf)
    {
        goto L_0x0050c256;
    }
L_0x0050c224:
    // 0050c224  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c226  7403                   -je 0x50c22b
    if (cpu.flags.zf)
    {
        goto L_0x0050c22b;
    }
    // 0050c228  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x0050c22b:
    // 0050c22b  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c22d  7403                   -je 0x50c232
    if (cpu.flags.zf)
    {
        goto L_0x0050c232;
    }
    // 0050c22f  885302                 -mov byte ptr [ebx + 2], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0050c232:
    // 0050c232  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c234  7403                   -je 0x50c239
    if (cpu.flags.zf)
    {
        goto L_0x0050c239;
    }
    // 0050c236  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x0050c239:
    // 0050c239  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c23b  7403                   -je 0x50c240
    if (cpu.flags.zf)
    {
        goto L_0x0050c240;
    }
    // 0050c23d  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x0050c240:
    // 0050c240  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c242  7403                   -je 0x50c247
    if (cpu.flags.zf)
    {
        goto L_0x0050c247;
    }
    // 0050c244  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x0050c247:
    // 0050c247  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c249  7403                   -je 0x50c24e
    if (cpu.flags.zf)
    {
        goto L_0x0050c24e;
    }
    // 0050c24b  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x0050c24e:
    // 0050c24e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c250  7508                   -jne 0x50c25a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c25a;
    }
    // 0050c252  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050c255  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c256:
    // 0050c256  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 0050c258  ebca                   -jmp 0x50c224
    goto L_0x0050c224;
L_0x0050c25a:
    // 0050c25a  885307                 -mov byte ptr [ebx + 7], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 0050c25d  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050c260  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c271  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050c273  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c275  7539                   -jne 0x50c2b0
    if (!cpu.flags.zf)
    {
        goto L_0x0050c2b0;
    }
L_0x0050c277:
    // 0050c277  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c279  7404                   -je 0x50c27f
    if (cpu.flags.zf)
    {
        goto L_0x0050c27f;
    }
    // 0050c27b  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x0050c27f:
    // 0050c27f  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c281  7404                   -je 0x50c287
    if (cpu.flags.zf)
    {
        goto L_0x0050c287;
    }
    // 0050c283  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x0050c287:
    // 0050c287  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c289  7404                   -je 0x50c28f
    if (cpu.flags.zf)
    {
        goto L_0x0050c28f;
    }
    // 0050c28b  66895106               -mov word ptr [ecx + 6], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x0050c28f:
    // 0050c28f  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c291  7404                   -je 0x50c297
    if (cpu.flags.zf)
    {
        goto L_0x0050c297;
    }
    // 0050c293  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x0050c297:
    // 0050c297  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c299  7404                   -je 0x50c29f
    if (cpu.flags.zf)
    {
        goto L_0x0050c29f;
    }
    // 0050c29b  6689510a               -mov word ptr [ecx + 0xa], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x0050c29f:
    // 0050c29f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c2a1  7404                   -je 0x50c2a7
    if (cpu.flags.zf)
    {
        goto L_0x0050c2a7;
    }
    // 0050c2a3  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x0050c2a7:
    // 0050c2a7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c2a9  750a                   -jne 0x50c2b5
    if (!cpu.flags.zf)
    {
        goto L_0x0050c2b5;
    }
    // 0050c2ab  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050c2ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c2af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c2b0:
    // 0050c2b0  668913                 -mov word ptr [ebx], dx
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 0050c2b3  ebc2                   -jmp 0x50c277
    goto L_0x0050c277;
L_0x0050c2b5:
    // 0050c2b5  6689510e               -mov word ptr [ecx + 0xe], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0050c2b9  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050c2bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c2bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50c2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c2c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c2c1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c2c4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c2c7  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0050c2ca  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0050c2cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0050c2d0  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 0050c2d2  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp);
    // 0050c2d5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c2d7  755a                   -jne 0x50c333
    if (!cpu.flags.zf)
    {
        goto L_0x0050c333;
    }
L_0x0050c2d9:
    // 0050c2d9  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c2db  7409                   -je 0x50c2e6
    if (cpu.flags.zf)
    {
        goto L_0x0050c2e6;
    }
    // 0050c2dd  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050c2e0  887305                 -mov byte ptr [ebx + 5], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
    // 0050c2e3  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x0050c2e6:
    // 0050c2e6  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c2e8  7409                   -je 0x50c2f3
    if (cpu.flags.zf)
    {
        goto L_0x0050c2f3;
    }
    // 0050c2ea  886307                 -mov byte ptr [ebx + 7], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 0050c2ed  887308                 -mov byte ptr [ebx + 8], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
    // 0050c2f0  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x0050c2f3:
    // 0050c2f3  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c2f5  7409                   -je 0x50c300
    if (cpu.flags.zf)
    {
        goto L_0x0050c300;
    }
    // 0050c2f7  88630a                 -mov byte ptr [ebx + 0xa], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 0050c2fa  88730b                 -mov byte ptr [ebx + 0xb], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
    // 0050c2fd  885309                 -mov byte ptr [ebx + 9], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
L_0x0050c300:
    // 0050c300  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c302  7409                   -je 0x50c30d
    if (cpu.flags.zf)
    {
        goto L_0x0050c30d;
    }
    // 0050c304  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 0050c307  88730e                 -mov byte ptr [ebx + 0xe], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
    // 0050c30a  88530c                 -mov byte ptr [ebx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x0050c30d:
    // 0050c30d  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c30f  7409                   -je 0x50c31a
    if (cpu.flags.zf)
    {
        goto L_0x0050c31a;
    }
    // 0050c311  886310                 -mov byte ptr [ebx + 0x10], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 0050c314  887311                 -mov byte ptr [ebx + 0x11], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
    // 0050c317  88530f                 -mov byte ptr [ebx + 0xf], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
L_0x0050c31a:
    // 0050c31a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c31c  7409                   -je 0x50c327
    if (cpu.flags.zf)
    {
        goto L_0x0050c327;
    }
    // 0050c31e  886313                 -mov byte ptr [ebx + 0x13], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 0050c321  887314                 -mov byte ptr [ebx + 0x14], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 0050c324  885312                 -mov byte ptr [ebx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
L_0x0050c327:
    // 0050c327  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c329  7512                   -jne 0x50c33d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c33d;
    }
    // 0050c32b  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050c32e  83c404                 +add esp, 4
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
    // 0050c331  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c332  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c333:
    // 0050c333  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0050c336  887302                 -mov byte ptr [ebx + 2], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 0050c339  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 0050c33b  eb9c                   -jmp 0x50c2d9
    goto L_0x0050c2d9;
L_0x0050c33d:
    // 0050c33d  886316                 -mov byte ptr [ebx + 0x16], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 0050c340  887317                 -mov byte ptr [ebx + 0x17], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 0050c343  885315                 -mov byte ptr [ebx + 0x15], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 0050c346  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050c349  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050c34c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c34d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50c350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c351  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050c353  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0050c355  7533                   -jne 0x50c38a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c38a;
    }
L_0x0050c357:
    // 0050c357  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0050c359  7403                   -je 0x50c35e
    if (cpu.flags.zf)
    {
        goto L_0x0050c35e;
    }
    // 0050c35b  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0050c35e:
    // 0050c35e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 0050c360  7403                   -je 0x50c365
    if (cpu.flags.zf)
    {
        goto L_0x0050c365;
    }
    // 0050c362  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0050c365:
    // 0050c365  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050c367  7403                   -je 0x50c36c
    if (cpu.flags.zf)
    {
        goto L_0x0050c36c;
    }
    // 0050c369  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050c36c:
    // 0050c36c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050c36e  7403                   -je 0x50c373
    if (cpu.flags.zf)
    {
        goto L_0x0050c373;
    }
    // 0050c370  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0050c373:
    // 0050c373  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050c375  7403                   -je 0x50c37a
    if (cpu.flags.zf)
    {
        goto L_0x0050c37a;
    }
    // 0050c377  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0050c37a:
    // 0050c37a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050c37c  7403                   -je 0x50c381
    if (cpu.flags.zf)
    {
        goto L_0x0050c381;
    }
    // 0050c37e  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0050c381:
    // 0050c381  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050c383  7509                   -jne 0x50c38e
    if (!cpu.flags.zf)
    {
        goto L_0x0050c38e;
    }
    // 0050c385  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0050c388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c38a:
    // 0050c38a  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050c38c  ebc9                   -jmp 0x50c357
    goto L_0x0050c357;
L_0x0050c38e:
    // 0050c38e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0050c391  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0050c394  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c395  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c3a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c3a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c3a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050c3a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c3a8  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050c3ad  3c0f                   +cmp al, 0xf
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
    // 0050c3af  7354                   -jae 0x50c405
    if (!cpu.flags.cf)
    {
        goto L_0x0050c405;
    }
L_0x0050c3b1:
    // 0050c3b1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c3b3  7c08                   -jl 0x50c3bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c3bd;
    }
    // 0050c3b5  81fa00010000           +cmp edx, 0x100
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
    // 0050c3bb  7c38                   -jl 0x50c3f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c3f5;
    }
L_0x0050c3bd:
    // 0050c3bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3be  bb7cfa5400             -mov ebx, 0x54fa7c
    cpu.ebx = 5569148 /*0x54fa7c*/;
    // 0050c3c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c3c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c3c6  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 0050c3cb  be8cfa5400             -mov esi, 0x54fa8c
    cpu.esi = 5569164 /*0x54fa8c*/;
    // 0050c3d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c3d1  bfb8000000             -mov edi, 0xb8
    cpu.edi = 184 /*0xb8*/;
    // 0050c3d6  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050c3dc  6854fb5400             -push 0x54fb54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569364 /*0x54fb54*/;
    cpu.esp -= 4;
    // 0050c3e1  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050c3e7  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050c3ed  e81e4cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c3f2  83c410                 +add esp, 0x10
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
L_0x0050c3f5:
    // 0050c3f5  8b149514a8a000         -mov edx, dword ptr [edx*4 + 0xa0a814]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.edx * 4);
L_0x0050c3fc:
    // 0050c3fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c3fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c3ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c400  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c401  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c402  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c403  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c404  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c405:
    // 0050c405  0f877e000000           -ja 0x50c489
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050c489;
    }
    // 0050c40b  f7c20000ffff           +test edx, 0xffff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4294901760 /*0xffff0000*/));
    // 0050c411  7436                   -je 0x50c449
    if (cpu.flags.zf)
    {
        goto L_0x0050c449;
    }
    // 0050c413  bf7cfa5400             -mov edi, 0x54fa7c
    cpu.edi = 5569148 /*0x54fa7c*/;
    // 0050c418  bd8cfa5400             -mov ebp, 0x54fa8c
    cpu.ebp = 5569164 /*0x54fa8c*/;
    // 0050c41d  b990000000             -mov ecx, 0x90
    cpu.ecx = 144 /*0x90*/;
    // 0050c422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c423  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050c429  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050c42f  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0050c435  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c436  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c43b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c43c  6894fa5400             -push 0x54fa94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569172 /*0x54fa94*/;
    cpu.esp -= 4;
    // 0050c441  e8ca4befff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c446  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0050c449:
    // 0050c449  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 0050c44c  0f849d000000           -je 0x50c4ef
    if (cpu.flags.zf)
    {
        goto L_0x0050c4ef;
    }
    // 0050c452  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050c457:
    // 0050c457  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c459  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c45b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c45d  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 0050c460  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 0050c463  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c466  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c469  c1e618                 -shl esi, 0x18
    cpu.esi <<= 24 /*0x18*/ % 32;
    // 0050c46c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c46e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c471  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 0050c474  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 0050c477  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050c479  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050c47c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c47e  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c480  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c482  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c485  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c486  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c487  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c489:
    // 0050c489  3c18                   +cmp al, 0x18
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
    // 0050c48b  734b                   -jae 0x50c4d8
    if (!cpu.flags.cf)
    {
        goto L_0x0050c4d8;
    }
    // 0050c48d  3c10                   +cmp al, 0x10
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
    // 0050c48f  0f851cffffff           -jne 0x50c3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0050c3b1;
    }
    // 0050c495  f7c20000ffff           +test edx, 0xffff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4294901760 /*0xffff0000*/));
    // 0050c49b  7559                   -jne 0x50c4f6
    if (!cpu.flags.zf)
    {
        goto L_0x0050c4f6;
    }
L_0x0050c49d:
    // 0050c49d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050c49f  0f848c000000           -je 0x50c531
    if (cpu.flags.zf)
    {
        goto L_0x0050c531;
    }
    // 0050c4a5  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0050c4aa:
    // 0050c4aa  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c4ac  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c4ae  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0050c4b1  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 0050c4b4  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0050c4b7  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c4ba  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050c4bd  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0050c4c0  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 0050c4c3  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0050c4c6  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050c4c8  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0050c4cb  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c4cd  09c2                   +or edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c4cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c4d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c4d8:
    // 0050c4d8  0f861effffff           -jbe 0x50c3fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c3fc;
    }
    // 0050c4de  3c20                   +cmp al, 0x20
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
    // 0050c4e0  0f85cbfeffff           -jne 0x50c3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0050c3b1;
    }
    // 0050c4e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c4e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c4ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c4ef:
    // 0050c4ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c4f1  e961ffffff             -jmp 0x50c457
    goto L_0x0050c457;
L_0x0050c4f6:
    // 0050c4f6  b97cfa5400             -mov ecx, 0x54fa7c
    cpu.ecx = 5569148 /*0x54fa7c*/;
    // 0050c4fb  bb8cfa5400             -mov ebx, 0x54fa8c
    cpu.ebx = 5569164 /*0x54fa8c*/;
    // 0050c500  bea4000000             -mov esi, 0xa4
    cpu.esi = 164 /*0xa4*/;
    // 0050c505  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c506  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050c50c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050c512  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050c518  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c519  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c51e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050c51f  68f4fa5400             -push 0x54faf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569268 /*0x54faf4*/;
    cpu.esp -= 4;
    // 0050c524  e8e74aefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050c529  83c410                 +add esp, 0x10
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
    // 0050c52c  e96cffffff             -jmp 0x50c49d
    goto L_0x0050c49d;
L_0x0050c531:
    // 0050c531  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050c533  e972ffffff             -jmp 0x50c4aa
    goto L_0x0050c4aa;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c541  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c542  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c543  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c545  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0050c547  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0050c54c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050c54e  e8ed40fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0050c553  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050c555  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0050c557  7504                   -jne 0x50c55d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c55d;
    }
    // 0050c559  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c55c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c55d:
    // 0050c55d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050c55f  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050c561  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050c564  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0050c566  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c56b  8a8040215500           -mov al, byte ptr [eax + 0x552140]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5579072) /* 0x552140 */);
    // 0050c571  8a2432                 -mov ah, byte ptr [edx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1);
    // 0050c574  08c4                   -or ah, al
    cpu.ah |= x86::reg8(x86::sreg8(cpu.al));
    // 0050c576  41                     -inc ecx
    (cpu.ecx)++;
    // 0050c577  882432                 -mov byte ptr [edx + esi], ah
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) = cpu.ah;
    // 0050c57a  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050c57c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0050c57e  75dd                   -jne 0x50c55d
    if (!cpu.flags.zf)
    {
        goto L_0x0050c55d;
    }
    // 0050c580  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c581  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c582  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c584  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c585  ff0d9a875600           +dec dword ptr [0x56879a]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c58b  753f                   -jne 0x50c5cc
    if (!cpu.flags.zf)
    {
        goto L_0x0050c5cc;
    }
    // 0050c58d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c58f  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0050c591  7421                   -je 0x50c5b4
    if (cpu.flags.zf)
    {
        goto L_0x0050c5b4;
    }
    // 0050c593  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 0050c596  8a9294865600           -mov dl, byte ptr [edx + 0x568694]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670548) /* 0x568694 */);
L_0x0050c59c:
    // 0050c59c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c59d  7c2d                   -jl 0x50c5cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c5cc;
    }
    // 0050c59f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c5a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c5a1  ff14959e875600         -call dword ptr [edx*4 + 0x56879e]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5670814) /* 0x56879e */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c5a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050c5ac  ff059a875600           -inc dword ptr [0x56879a]
    (app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */))++;
    // 0050c5b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c5b4:
    // 0050c5b4  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0050c5b7  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c5bd  7c05                   -jl 0x50c5c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050c5c4;
    }
    // 0050c5bf  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x0050c5c4:
    // 0050c5c4  8a9214875600           -mov dl, byte ptr [edx + 0x568714]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670676) /* 0x568714 */);
    // 0050c5ca  ebd0                   -jmp 0x50c59c
    goto L_0x0050c59c;
L_0x0050c5cc:
    // 0050c5cc  ff059a875600           -inc dword ptr [0x56879a]
    (app->getMemory<x86::reg32>(x86::reg32(5670810) /* 0x56879a */))++;
    // 0050c5d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c5d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c5d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c5d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c5d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c5d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c5d9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050c5db  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050c5dd  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0050c5e2  ba9e875600             -mov edx, 0x56879e
    cpu.edx = 5670814 /*0x56879e*/;
L_0x0050c5e7:
    // 0050c5e7  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c5e9  7412                   -je 0x50c5fd
    if (cpu.flags.zf)
    {
        goto L_0x0050c5fd;
    }
    // 0050c5eb  66833a00               +cmp word ptr [edx], 0
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
    // 0050c5ef  740a                   -je 0x50c5fb
    if (cpu.flags.zf)
    {
        goto L_0x0050c5fb;
    }
    // 0050c5f1  83c204                 +add edx, 4
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
    // 0050c5f4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050c5f5  75f0                   -jne 0x50c5e7
    if (!cpu.flags.zf)
    {
        goto L_0x0050c5e7;
    }
    // 0050c5f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c5fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c5fb:
    // 0050c5fb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0050c5fd:
    // 0050c5fd  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 0050c602  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050c604:
    // 0050c604  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c606  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0050c608  740f                   -je 0x50c619
    if (cpu.flags.zf)
    {
        goto L_0x0050c619;
    }
    // 0050c60a  83fa7f                 +cmp edx, 0x7f
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
    // 0050c60d  7f06                   -jg 0x50c615
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050c615;
    }
    // 0050c60f  888294865600           -mov byte ptr [edx + 0x568694], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670548) /* 0x568694 */) = cpu.al;
L_0x0050c615:
    // 0050c615  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c619:
    // 0050c619  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0050c61c  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c622  7ff1                   -jg 0x50c615
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050c615;
    }
    // 0050c624  888214875600           -mov byte ptr [edx + 0x568714], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5670676) /* 0x568714 */) = cpu.al;
    // 0050c62a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c62d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0050c62e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c62f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c630  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c631  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c633  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050c635  ebcd                   -jmp 0x50c604
    goto L_0x0050c604;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50c640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c640  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050c641  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050c643  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c645  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50c648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c648  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c649  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050c64b  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050c64e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c64f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50c650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050c654  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050c657  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050c659  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c65c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050c65e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050c662  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0050c665  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050c667  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0050c66a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050c66c  886610                 -mov byte ptr [esi + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x0050c66f:
    // 0050c66f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0050c672  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0050c675  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0050c678  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0050c67a  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050c680  0f8462020000           -je 0x50c8e8
    if (cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c686  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050c688  fec0                   -inc al
    (cpu.al)++;
    // 0050c68a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c68f  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050c696  740e                   -je 0x50c6a6
    if (cpu.flags.zf)
    {
        goto L_0x0050c6a6;
    }
    // 0050c698  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c69a  e869030000             -call 0x50ca08
    cpu.esp -= 4;
    sub_50ca08(app, cpu);
    if (cpu.terminate) return;
    // 0050c69f  01c7                   +add edi, eax
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
    // 0050c6a1  e90c020000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c6a6:
    // 0050c6a6  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6a9  7425                   -je 0x50c6d0
    if (cpu.flags.zf)
    {
        goto L_0x0050c6d0;
    }
    // 0050c6ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c6ad  e88effffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050c6b2  39d8                   +cmp eax, ebx
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
    // 0050c6b4  0f84f7010000           -je 0x50c8b1
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b1;
    }
    // 0050c6ba  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c6be  0f8524020000           -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c6c4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c6c6  e87dffffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050c6cb  e918020000             -jmp 0x50c8e8
    goto L_0x0050c8e8;
L_0x0050c6d0:
    // 0050c6d0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050c6d3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c6d5  e82a020000             -call 0x50c904
    cpu.esp -= 4;
    sub_50c904(app, cpu);
    if (cpu.terminate) return;
    // 0050c6da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c6dc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050c6df  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050c6e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050c6e3  7404                   -je 0x50c6e9
    if (cpu.flags.zf)
    {
        goto L_0x0050c6e9;
    }
    // 0050c6e5  40                     -inc eax
    (cpu.eax)++;
    // 0050c6e6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0050c6e9:
    // 0050c6e9  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6ec  726e                   -jb 0x50c75c
    if (cpu.flags.cf)
    {
        goto L_0x0050c75c;
    }
    // 0050c6ee  0f86d0000000           -jbe 0x50c7c4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7c4;
    }
    // 0050c6f4  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c6f7  723c                   -jb 0x50c735
    if (cpu.flags.cf)
    {
        goto L_0x0050c735;
    }
    // 0050c6f9  0f86f6000000           -jbe 0x50c7f5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7f5;
    }
    // 0050c6ff  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c702  7223                   -jb 0x50c727
    if (cpu.flags.cf)
    {
        goto L_0x0050c727;
    }
    // 0050c704  0f863e010000           -jbe 0x50c848
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c848;
    }
    // 0050c70a  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c70d  0f829f010000           -jb 0x50c8b2
    if (cpu.flags.cf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c713  0f86f3000000           -jbe 0x50c80c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c80c;
    }
    // 0050c719  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c71c  0f84fe000000           -je 0x50c820
    if (cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c722  e98b010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c727:
    // 0050c727  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c72a  0f84f0000000           -je 0x50c820
    if (cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c730  e97d010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c735:
    // 0050c735  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c738  7214                   -jb 0x50c74e
    if (cpu.flags.cf)
    {
        goto L_0x0050c74e;
    }
    // 0050c73a  0f869e000000           -jbe 0x50c7de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c7de;
    }
    // 0050c740  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c743  0f843f010000           -je 0x50c888
    if (cpu.flags.zf)
    {
        goto L_0x0050c888;
    }
    // 0050c749  e964010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c74e:
    // 0050c74e  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c751  0f86e0000000           -jbe 0x50c837
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c757  e956010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c75c:
    // 0050c75c  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c75f  723c                   -jb 0x50c79d
    if (cpu.flags.cf)
    {
        goto L_0x0050c79d;
    }
    // 0050c761  0f86d0000000           -jbe 0x50c837
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c767  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c76a  7223                   -jb 0x50c78f
    if (cpu.flags.cf)
    {
        goto L_0x0050c78f;
    }
    // 0050c76c  0f86ae000000           -jbe 0x50c820
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c820;
    }
    // 0050c772  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c775  0f8237010000           -jb 0x50c8b2
    if (cpu.flags.cf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c77b  0f86d4000000           -jbe 0x50c855
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c855;
    }
    // 0050c781  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c784  0f84de000000           -je 0x50c868
    if (cpu.flags.zf)
    {
        goto L_0x0050c868;
    }
    // 0050c78a  e923010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c78f:
    // 0050c78f  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c792  0f84ac000000           -je 0x50c844
    if (cpu.flags.zf)
    {
        goto L_0x0050c844;
    }
    // 0050c798  e915010000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c79d:
    // 0050c79d  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7a0  7214                   -jb 0x50c7b6
    if (cpu.flags.cf)
    {
        goto L_0x0050c7b6;
    }
    // 0050c7a2  0f86bc000000           -jbe 0x50c864
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c864;
    }
    // 0050c7a8  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7ab  0f8486000000           -je 0x50c837
    if (cpu.flags.zf)
    {
        goto L_0x0050c837;
    }
    // 0050c7b1  e9fc000000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c7b6:
    // 0050c7b6  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050c7b9  0f84d8000000           -je 0x50c897
    if (cpu.flags.zf)
    {
        goto L_0x0050c897;
    }
    // 0050c7bf  e9ee000000             -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c7c4:
    // 0050c7c4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7c9  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0050c7ce  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c7d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c7d4  e817090000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c7d9  e995000000             -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c7de:
    // 0050c7de  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7e3  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c7e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c7e9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0050c7eb  e800090000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c7f0  e97e000000             -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c7f5:
    // 0050c7f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c7fa  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0050c7ff  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c803  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c805  e8e6080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c80a  eb67                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c80c:
    // 0050c80c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0050c811  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c815  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c817  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0050c819  e8d2080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c81e  eb53                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c820:
    // 0050c820  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0050c825  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0050c82a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c82e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c830  e8bb080000             -call 0x50d0f0
    cpu.esp -= 4;
    sub_50d0f0(app, cpu);
    if (cpu.terminate) return;
    // 0050c835  eb3c                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c837:
    // 0050c837  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c83b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c83d  e8d6050000             -call 0x50ce18
    cpu.esp -= 4;
    sub_50ce18(app, cpu);
    if (cpu.terminate) return;
    // 0050c842  eb2f                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c844:
    // 0050c844  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x0050c848:
    // 0050c848  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c84c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c84e  e8dd020000             -call 0x50cb30
    cpu.esp -= 4;
    sub_50cb30(app, cpu);
    if (cpu.terminate) return;
    // 0050c853  eb1e                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c855:
    // 0050c855  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050c857  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c85b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c85d  e8ca040000             -call 0x50cd2c
    cpu.esp -= 4;
    sub_50cd2c(app, cpu);
    if (cpu.terminate) return;
    // 0050c862  eb0f                   -jmp 0x50c873
    goto L_0x0050c873;
L_0x0050c864:
    // 0050c864  804e1020               -or byte ptr [esi + 0x10], 0x20
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0050c868:
    // 0050c868  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c86c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c86e  e8d5010000             -call 0x50ca48
    cpu.esp -= 4;
    sub_50ca48(app, cpu);
    if (cpu.terminate) return;
L_0x0050c873:
    // 0050c873  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050c875  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050c877  0f8e6b000000           -jle 0x50c8e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050c8e8;
    }
    // 0050c87d  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c87f  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050c883  742d                   -je 0x50c8b2
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b2;
    }
    // 0050c885  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050c886  eb2a                   -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c888:
    // 0050c888  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c88c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050c88e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c890  e8f3030000             -call 0x50cc88
    cpu.esp -= 4;
    sub_50cc88(app, cpu);
    if (cpu.terminate) return;
    // 0050c895  eb1b                   -jmp 0x50c8b2
    goto L_0x0050c8b2;
L_0x0050c897:
    // 0050c897  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c899  e8a2fdffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050c89e  39d8                   +cmp eax, ebx
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
    // 0050c8a0  740f                   -je 0x50c8b1
    if (cpu.flags.zf)
    {
        goto L_0x0050c8b1;
    }
    // 0050c8a2  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8a6  7540                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8a8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c8aa  e899fdffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050c8af  eb37                   -jmp 0x50c8e8
    goto L_0x0050c8e8;
L_0x0050c8b1:
    // 0050c8b1  47                     -inc edi
    (cpu.edi)++;
L_0x0050c8b2:
    // 0050c8b2  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8b6  0f84b3fdffff           -je 0x50c66f
    if (cpu.flags.zf)
    {
        goto L_0x0050c66f;
    }
    // 0050c8bc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050c8bf  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c8c2  7524                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8c4  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c8c7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050c8c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c8cb  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050c8ce  e831000000             -call 0x50c904
    cpu.esp -= 4;
    sub_50c904(app, cpu);
    if (cpu.terminate) return;
    // 0050c8d3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050c8d6  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c8d9  750d                   -jne 0x50c8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8e8;
    }
    // 0050c8db  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050c8df  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050c8e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050c8e3  e8a0030000             -call 0x50cc88
    cpu.esp -= 4;
    sub_50cc88(app, cpu);
    if (cpu.terminate) return;
L_0x0050c8e8:
    // 0050c8e8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050c8ea  750d                   -jne 0x50c8f9
    if (!cpu.flags.zf)
    {
        goto L_0x0050c8f9;
    }
    // 0050c8ec  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050c8f0  7407                   -je 0x50c8f9
    if (cpu.flags.zf)
    {
        goto L_0x0050c8f9;
    }
    // 0050c8f2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050c8f7  eb02                   -jmp 0x50c8fb
    goto L_0x0050c8fb;
L_0x0050c8f9:
    // 0050c8f9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0050c8fb:
    // 0050c8fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050c8fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c8ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c900  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50c904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050c904  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050c905  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050c906  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050c907  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050c908  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050c90a  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050c90d  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050c910  885710                 -mov byte ptr [edi + 0x10], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0050c913  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0050c915  c7470cffffffff         -mov dword ptr [edi + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 0050c91c  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0050c91f  887710                 -mov byte ptr [edi + 0x10], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 0050c922  80382a                 +cmp byte ptr [eax], 0x2a
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
    // 0050c925  750a                   -jne 0x50c931
    if (!cpu.flags.zf)
    {
        goto L_0x0050c931;
    }
    // 0050c927  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c92a  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050c92d  40                     -inc eax
    (cpu.eax)++;
    // 0050c92e  887f10                 -mov byte ptr [edi + 0x10], bh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0050c931:
    // 0050c931  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c933  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050c935  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 0050c937  fec2                   -inc dl
    (cpu.dl)++;
    // 0050c939  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050c93f  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050c946  7425                   -je 0x50c96d
    if (cpu.flags.zf)
    {
        goto L_0x0050c96d;
    }
    // 0050c948  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0050c94a:
    // 0050c94a  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0050c94d  83eb30                 -sub ebx, 0x30
    (cpu.ebx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050c950  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c952  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050c954  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c957  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0050c959  fec1                   -inc cl
    (cpu.cl)++;
    // 0050c95b  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0050c95e  8aaef04e5600           -mov ch, byte ptr [esi + 0x564ef0]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5656304) /* 0x564ef0 */);
    // 0050c964  40                     -inc eax
    (cpu.eax)++;
    // 0050c965  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0050c968  75e0                   -jne 0x50c94a
    if (!cpu.flags.zf)
    {
        goto L_0x0050c94a;
    }
    // 0050c96a  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050c96d:
    // 0050c96d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050c96f  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c972  80fb4e                 +cmp bl, 0x4e
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c975  750d                   -jne 0x50c984
    if (!cpu.flags.zf)
    {
        goto L_0x0050c984;
    }
    // 0050c977  8a6f10                 -mov ch, byte ptr [edi + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c97a  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0050c97d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c97f  886f10                 -mov byte ptr [edi + 0x10], ch
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0050c982  eb10                   -jmp 0x50c994
    goto L_0x0050c994;
L_0x0050c984:
    // 0050c984  80fb46                 +cmp bl, 0x46
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050c987  750b                   -jne 0x50c994
    if (!cpu.flags.zf)
    {
        goto L_0x0050c994;
    }
    // 0050c989  8a4f10                 -mov cl, byte ptr [edi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c98c  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0050c98f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050c991  884f10                 -mov byte ptr [edi + 0x10], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.cl;
L_0x0050c994:
    // 0050c994  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050c996  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050c999  80fa68                 +cmp dl, 0x68
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
    // 0050c99c  7213                   -jb 0x50c9b1
    if (cpu.flags.cf)
    {
        goto L_0x0050c9b1;
    }
    // 0050c99e  7622                   -jbe 0x50c9c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9c2;
    }
    // 0050c9a0  80fa6c                 +cmp dl, 0x6c
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
    // 0050c9a3  725e                   -jb 0x50ca03
    if (cpu.flags.cf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9a5  7625                   -jbe 0x50c9cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9cc;
    }
    // 0050c9a7  80fa77                 +cmp dl, 0x77
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
    // 0050c9aa  7420                   -je 0x50c9cc
    if (cpu.flags.zf)
    {
        goto L_0x0050c9cc;
    }
    // 0050c9ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9b1:
    // 0050c9b1  80fa49                 +cmp dl, 0x49
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
    // 0050c9b4  724d                   -jb 0x50ca03
    if (cpu.flags.cf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9b6  7633                   -jbe 0x50c9eb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050c9eb;
    }
    // 0050c9b8  80fa4c                 +cmp dl, 0x4c
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
    // 0050c9bb  741e                   -je 0x50c9db
    if (cpu.flags.zf)
    {
        goto L_0x0050c9db;
    }
    // 0050c9bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9c2:
    // 0050c9c2  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9c5  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0050c9c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c9ca  eb34                   -jmp 0x50ca00
    goto L_0x0050ca00;
L_0x0050c9cc:
    // 0050c9cc  8a5710                 -mov dl, byte ptr [edi + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9cf  80ca20                 -or dl, 0x20
    cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0050c9d2  40                     -inc eax
    (cpu.eax)++;
    // 0050c9d3  885710                 -mov byte ptr [edi + 0x10], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0050c9d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9db:
    // 0050c9db  8a4f10                 -mov cl, byte ptr [edi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9de  80c940                 -or cl, 0x40
    cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0050c9e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050c9e3  884f10                 -mov byte ptr [edi + 0x10], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 0050c9e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050c9ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050c9eb:
    // 0050c9eb  80780136               +cmp byte ptr [eax + 1], 0x36
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
    // 0050c9ef  7512                   -jne 0x50ca03
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9f1  80780234               +cmp byte ptr [eax + 2], 0x34
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
    // 0050c9f5  750c                   -jne 0x50ca03
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca03;
    }
    // 0050c9f7  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050c9fa  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0050c9fd  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0050ca00:
    // 0050ca00  887710                 -mov byte ptr [edi + 0x10], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x0050ca03:
    // 0050ca03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50ca08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ca08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ca09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ca0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ca0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ca0c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca0f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ca11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0050ca13:
    // 0050ca13  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ca15  e826fcffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050ca1a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050ca1d  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0050ca20  fec1                   -inc cl
    (cpu.cl)++;
    // 0050ca22  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0050ca25  f686f04e560002         +test byte ptr [esi + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050ca2c  7403                   -je 0x50ca31
    if (cpu.flags.zf)
    {
        goto L_0x0050ca31;
    }
    // 0050ca2e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050ca2f  ebe2                   -jmp 0x50ca13
    goto L_0x0050ca13;
L_0x0050ca31:
    // 0050ca31  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050ca35  7505                   -jne 0x50ca3c
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca3c;
    }
    // 0050ca37  e80cfcffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050ca3c:
    // 0050ca3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050ca3e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ca45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50ca48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ca48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ca49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ca4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ca4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ca4c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050ca4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ca4e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050ca51  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ca53  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050ca57  7437                   -je 0x50ca90
    if (cpu.flags.zf)
    {
        goto L_0x0050ca90;
    }
    // 0050ca59  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050ca5c  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050ca5f  740c                   -je 0x50ca6d
    if (cpu.flags.zf)
    {
        goto L_0x0050ca6d;
    }
    // 0050ca61  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca63  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ca66  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050ca68  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050ca6b  eb23                   -jmp 0x50ca90
    goto L_0x0050ca90;
L_0x0050ca6d:
    // 0050ca6d  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050ca70  7410                   -je 0x50ca82
    if (cpu.flags.zf)
    {
        goto L_0x0050ca82;
    }
    // 0050ca72  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca74  83c604                 +add esi, 4
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
    // 0050ca77  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050ca79  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050ca7b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050ca7d  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ca80  eb0e                   -jmp 0x50ca90
    goto L_0x0050ca90;
L_0x0050ca82:
    // 0050ca82  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050ca84  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ca87  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050ca89  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0050ca8b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050ca8d  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0050ca90:
    // 0050ca90  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050ca93  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ca95  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ca98  7505                   -jne 0x50ca9f
    if (!cpu.flags.zf)
    {
        goto L_0x0050ca9f;
    }
    // 0050ca9a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0050ca9f:
    // 0050ca9f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050caa1  0f8e7c000000           -jle 0x50cb23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050cb23;
    }
    // 0050caa7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050caa9  e892fbffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050caae  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cab1  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0050cab4  0f8569000000           -jne 0x50cb23
    if (!cpu.flags.zf)
    {
        goto L_0x0050cb23;
    }
    // 0050caba  45                     -inc ebp
    (cpu.ebp)++;
    // 0050cabb  4f                     -dec edi
    (cpu.edi)--;
    // 0050cabc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0050cabf  74de                   -je 0x50ca9f
    if (cpu.flags.zf)
    {
        goto L_0x0050ca9f;
    }
    // 0050cac1  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0050cac4  7453                   -je 0x50cb19
    if (cpu.flags.zf)
    {
        goto L_0x0050cb19;
    }
    // 0050cac6  8b1500b2a000           -mov edx, dword ptr [0xa0b200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
    // 0050cacc  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0050cad0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cad2  741f                   -je 0x50caf3
    if (cpu.flags.zf)
    {
        goto L_0x0050caf3;
    }
    // 0050cad4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cad9  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0050cadf  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050cae1  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cae6  740b                   -je 0x50caf3
    if (cpu.flags.zf)
    {
        goto L_0x0050caf3;
    }
    // 0050cae8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050caea  e851fbffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050caef  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0050caf3:
    // 0050caf3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0050caf8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050cafc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050cafe  e8fd700100             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 0050cb03  83f8ff                 +cmp eax, -1
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
    // 0050cb06  7504                   -jne 0x50cb0c
    if (!cpu.flags.zf)
    {
        goto L_0x0050cb0c;
    }
    // 0050cb08  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050cb0a  eb19                   -jmp 0x50cb25
    goto L_0x0050cb25;
L_0x0050cb0c:
    // 0050cb0c  83c602                 +add esi, 2
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
    // 0050cb0f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050cb12  66268946fe             -mov word ptr es:[esi - 2], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0050cb17  eb86                   -jmp 0x50ca9f
    goto L_0x0050ca9f;
L_0x0050cb19:
    // 0050cb19  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050cb1a  268846ff               -mov byte ptr es:[esi - 1], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0050cb1e  e97cffffff             -jmp 0x50ca9f
    goto L_0x0050ca9f;
L_0x0050cb23:
    // 0050cb23  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0050cb25:
    // 0050cb25  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050cb28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb29  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cb2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50cb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cb30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050cb31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cb32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cb33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cb34  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cb35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050cb36  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050cb39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cb3b  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 0050cb3f  7407                   -je 0x50cb48
    if (cpu.flags.zf)
    {
        goto L_0x0050cb48;
    }
    // 0050cb41  c644240802             -mov byte ptr [esp + 8], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 0050cb46  eb09                   -jmp 0x50cb51
    goto L_0x0050cb51;
L_0x0050cb48:
    // 0050cb48  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cb4c  c644240801             -mov byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0050cb51:
    // 0050cb51  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cb54  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0050cb57  7434                   -je 0x50cb8d
    if (cpu.flags.zf)
    {
        goto L_0x0050cb8d;
    }
    // 0050cb59  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050cb5c  740c                   -je 0x50cb6a
    if (cpu.flags.zf)
    {
        goto L_0x0050cb6a;
    }
    // 0050cb5e  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb60  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cb63  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050cb65  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050cb68  eb23                   -jmp 0x50cb8d
    goto L_0x0050cb8d;
L_0x0050cb6a:
    // 0050cb6a  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050cb6d  7410                   -je 0x50cb7f
    if (cpu.flags.zf)
    {
        goto L_0x0050cb7f;
    }
    // 0050cb6f  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb71  83c604                 +add esi, 4
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
    // 0050cb74  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cb76  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050cb78  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cb7a  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050cb7d  eb0e                   -jmp 0x50cb8d
    goto L_0x0050cb8d;
L_0x0050cb7f:
    // 0050cb7f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050cb81  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050cb84  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cb86  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0050cb88  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cb8a  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0050cb8d:
    // 0050cb8d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0050cb8f:
    // 0050cb8f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cb91  e8aafaffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cb96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cb98  fec0                   -inc al
    (cpu.al)++;
    // 0050cb9a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cb9f  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050cba6  7403                   -je 0x50cbab
    if (cpu.flags.zf)
    {
        goto L_0x0050cbab;
    }
    // 0050cba8  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050cba9  ebe4                   -jmp 0x50cb8f
    goto L_0x0050cb8f;
L_0x0050cbab:
    // 0050cbab  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050cbaf  7407                   -je 0x50cbb8
    if (cpu.flags.zf)
    {
        goto L_0x0050cbb8;
    }
    // 0050cbb1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050cbb3  e9a4000000             -jmp 0x50cc5c
    goto L_0x0050cc5c;
L_0x0050cbb8:
    // 0050cbb8  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050cbbb  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050cbbe  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050cbc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cbc3  0f848a000000           -je 0x50cc53
    if (cpu.flags.zf)
    {
        goto L_0x0050cc53;
    }
L_0x0050cbc9:
    // 0050cbc9  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cbcc  47                     -inc edi
    (cpu.edi)++;
    // 0050cbcd  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050cbcf  7460                   -je 0x50cc31
    if (cpu.flags.zf)
    {
        goto L_0x0050cc31;
    }
    // 0050cbd1  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cbd6  7505                   -jne 0x50cbdd
    if (!cpu.flags.zf)
    {
        goto L_0x0050cbdd;
    }
    // 0050cbd8  26881e                 -mov byte ptr es:[esi], bl
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 0050cbdb  eb4c                   -jmp 0x50cc29
    goto L_0x0050cc29;
L_0x0050cbdd:
    // 0050cbdd  8b2d00b2a000           -mov ebp, dword ptr [0xa0b200]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
    // 0050cbe3  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 0050cbe7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050cbe9  741e                   -je 0x50cc09
    if (cpu.flags.zf)
    {
        goto L_0x0050cc09;
    }
    // 0050cbeb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cbed  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cbef  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0050cbf5  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050cbf7  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cbfc  740b                   -je 0x50cc09
    if (cpu.flags.zf)
    {
        goto L_0x0050cc09;
    }
    // 0050cbfe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cc00  e83bfaffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cc05  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0050cc09:
    // 0050cc09  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0050cc0e  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050cc12  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050cc14  e8e76f0100             -call 0x523c00
    cpu.esp -= 4;
    sub_523c00(app, cpu);
    if (cpu.terminate) return;
    // 0050cc19  83f8ff                 +cmp eax, -1
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
    // 0050cc1c  7504                   -jne 0x50cc22
    if (!cpu.flags.zf)
    {
        goto L_0x0050cc22;
    }
    // 0050cc1e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050cc20  eb59                   -jmp 0x50cc7b
    goto L_0x0050cc7b;
L_0x0050cc22:
    // 0050cc22  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050cc25  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x0050cc29:
    // 0050cc29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cc2b  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050cc2f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050cc31:
    // 0050cc31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cc33  e800090000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cc38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cc3a  83f8ff                 +cmp eax, -1
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
    // 0050cc3d  741d                   -je 0x50cc5c
    if (cpu.flags.zf)
    {
        goto L_0x0050cc5c;
    }
    // 0050cc3f  fec0                   -inc al
    (cpu.al)++;
    // 0050cc41  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cc46  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050cc4d  0f8476ffffff           -je 0x50cbc9
    if (cpu.flags.zf)
    {
        goto L_0x0050cbc9;
    }
L_0x0050cc53:
    // 0050cc53  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050cc55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050cc57  e8ecf9ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050cc5c:
    // 0050cc5c  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050cc60  7417                   -je 0x50cc79
    if (cpu.flags.zf)
    {
        goto L_0x0050cc79;
    }
    // 0050cc62  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050cc64  7e13                   -jle 0x50cc79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050cc79;
    }
    // 0050cc66  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cc6b  7506                   -jne 0x50cc73
    if (!cpu.flags.zf)
    {
        goto L_0x0050cc73;
    }
    // 0050cc6d  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 0050cc71  eb06                   -jmp 0x50cc79
    goto L_0x0050cc79;
L_0x0050cc73:
    // 0050cc73  6626c7060000           -mov word ptr es:[esi], 0
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0050cc79:
    // 0050cc79  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0050cc7b:
    // 0050cc7b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050cc7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc7f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cc80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cc84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50cc88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cc88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cc89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cc8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cc8b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cc8c  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050cc8f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0050cc92  744d                   -je 0x50cce1
    if (cpu.flags.zf)
    {
        goto L_0x0050cce1;
    }
    // 0050cc94  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0050cc97  740c                   -je 0x50cca5
    if (cpu.flags.zf)
    {
        goto L_0x0050cca5;
    }
    // 0050cc99  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050cc9b  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cc9e  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0050cca0  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0050cca3  eb25                   -jmp 0x50ccca
    goto L_0x0050ccca;
L_0x0050cca5:
    // 0050cca5  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0050cca8  7410                   -je 0x50ccba
    if (cpu.flags.zf)
    {
        goto L_0x0050ccba;
    }
    // 0050ccaa  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0050ccac  83c604                 +add esi, 4
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
    // 0050ccaf  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0050ccb1  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0050ccb3  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0050ccb5  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0050ccb8  eb10                   -jmp 0x50ccca
    goto L_0x0050ccca;
L_0x0050ccba:
    // 0050ccba  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050ccbc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ccbf  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0050ccc1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050ccc3  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0050ccc5  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0050ccc7  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0050ccca:
    // 0050ccca  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050cccd  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0050ccd0  7409                   -je 0x50ccdb
    if (cpu.flags.zf)
    {
        goto L_0x0050ccdb;
    }
    // 0050ccd2  6626891a               -mov word ptr es:[edx], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 0050ccd6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ccda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ccdb:
    // 0050ccdb  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0050ccde  26891a                 -mov dword ptr es:[edx], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x0050cce1:
    // 0050cce1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050cce2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50cce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cce8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050cce9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ccea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cceb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cced  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ccef  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0050ccf4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050ccf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ccf8  e84339fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0050ccfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ccff  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050cd01  41                     -inc ecx
    (cpu.ecx)++;
    // 0050cd02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cd04  741f                   -je 0x50cd25
    if (cpu.flags.zf)
    {
        goto L_0x0050cd25;
    }
L_0x0050cd06:
    // 0050cd06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050cd08  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050cd0b  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0050cd0e  8a80a0885600           -mov al, byte ptr [eax + 0x5688a0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5671072) /* 0x5688a0 */);
    // 0050cd14  080432                 -or byte ptr [edx + esi], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 0050cd17  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050cd19  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050cd1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050cd1d  7406                   -je 0x50cd25
    if (cpu.flags.zf)
    {
        goto L_0x0050cd25;
    }
    // 0050cd1f  41                     -inc ecx
    (cpu.ecx)++;
    // 0050cd20  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cd23  75e1                   -jne 0x50cd06
    if (!cpu.flags.zf)
    {
        goto L_0x0050cd06;
    }
L_0x0050cd25:
    // 0050cd25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cd27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050cd2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50cd2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050cd2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050cd2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050cd2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050cd2f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050cd30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050cd31  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050cd34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050cd36  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050cd38  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050cd3a  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cd3d  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0050cd40  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0050cd46  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050cd4a  7403                   -je 0x50cd4f
    if (cpu.flags.zf)
    {
        goto L_0x0050cd4f;
    }
    // 0050cd4c  40                     -inc eax
    (cpu.eax)++;
    // 0050cd4d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0050cd4f:
    // 0050cd4f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050cd51  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050cd53  e890ffffff             -call 0x50cce8
    cpu.esp -= 4;
    sub_50cce8(app, cpu);
    if (cpu.terminate) return;
    // 0050cd58  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0050cd5a  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cd5d  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0050cd60  7434                   -je 0x50cd96
    if (cpu.flags.zf)
    {
        goto L_0x0050cd96;
    }
    // 0050cd62  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0050cd65  740c                   -je 0x50cd73
    if (cpu.flags.zf)
    {
        goto L_0x0050cd73;
    }
    // 0050cd67  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd69  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050cd6c  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0050cd6e  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 0050cd71  eb23                   -jmp 0x50cd96
    goto L_0x0050cd96;
L_0x0050cd73:
    // 0050cd73  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050cd76  7410                   -je 0x50cd88
    if (cpu.flags.zf)
    {
        goto L_0x0050cd88;
    }
    // 0050cd78  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd7a  83c304                 +add ebx, 4
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
    // 0050cd7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cd7f  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0050cd81  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cd83  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0050cd86  eb0e                   -jmp 0x50cd96
    goto L_0x0050cd96;
L_0x0050cd88:
    // 0050cd88  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0050cd8a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050cd8d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050cd8f  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0050cd91  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050cd93  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0050cd96:
    // 0050cd96  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050cd99  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050cd9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cd9d  7660                   -jbe 0x50cdff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050cdff;
    }
L_0x0050cd9f:
    // 0050cd9f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cda1  e89af8ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050cda6  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0050cdaa  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050cdae  754f                   -jne 0x50cdff
    if (!cpu.flags.zf)
    {
        goto L_0x0050cdff;
    }
    // 0050cdb0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050cdb2  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0050cdb5  0fb63c3c               -movzx edi, byte ptr [esp + edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + cpu.edi * 1));
    // 0050cdb9  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0050cdbd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050cdbf  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0050cdc2  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050cdc6  0fb6bfa0885600         -movzx edi, byte ptr [edi + 0x5688a0]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5671072) /* 0x5688a0 */));
    // 0050cdcd  85ef                   +test edi, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.ebp));
    // 0050cdcf  0f9444242c             -sete byte ptr [esp + 0x2c]
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.flags.zf;
    // 0050cdd4  0fb67c242c             -movzx edi, byte ptr [esp + 0x2c]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */));
    // 0050cdd9  3b7c2424               +cmp edi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cddd  7409                   -je 0x50cde8
    if (cpu.flags.zf)
    {
        goto L_0x0050cde8;
    }
    // 0050cddf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050cde1  e862f8ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
    // 0050cde6  eb17                   -jmp 0x50cdff
    goto L_0x0050cdff;
L_0x0050cde8:
    // 0050cde8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050cde9  8a6110                 -mov ah, byte ptr [ecx + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050cdec  4a                     -dec edx
    (cpu.edx)--;
    // 0050cded  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0050cdf0  7409                   -je 0x50cdfb
    if (cpu.flags.zf)
    {
        goto L_0x0050cdfb;
    }
    // 0050cdf2  46                     -inc esi
    (cpu.esi)++;
    // 0050cdf3  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050cdf7  268846ff               -mov byte ptr es:[esi - 1], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x0050cdfb:
    // 0050cdfb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050cdfd  77a0                   -ja 0x50cd9f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050cd9f;
    }
L_0x0050cdff:
    // 0050cdff  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050ce03  7408                   -je 0x50ce0d
    if (cpu.flags.zf)
    {
        goto L_0x0050ce0d;
    }
    // 0050ce05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ce07  7e04                   -jle 0x50ce0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ce0d;
    }
    // 0050ce09  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0050ce0d:
    // 0050ce0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050ce0f  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050ce12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce13  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050ce14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ce17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50ce18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ce18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ce19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ce1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ce1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ce1c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050ce1d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ce1e  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0050ce21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ce23  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0050ce27  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050ce29  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0050ce2b  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x0050ce2f:
    // 0050ce2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ce31  e80af8ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050ce36  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050ce38  fec2                   -inc dl
    (cpu.dl)++;
    // 0050ce3a  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 0050ce3d  8a95f04e5600           -mov dl, byte ptr [ebp + 0x564ef0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5656304) /* 0x564ef0 */);
    // 0050ce43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ce45  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0050ce48  7406                   -je 0x50ce50
    if (cpu.flags.zf)
    {
        goto L_0x0050ce50;
    }
    // 0050ce4a  ff442468               +inc dword ptr [esp + 0x68]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050ce4e  ebdf                   -jmp 0x50ce2f
    goto L_0x0050ce2f;
L_0x0050ce50:
    // 0050ce50  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050ce54  0f85d7010000           -jne 0x50d031
    if (!cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050ce5a  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050ce5d  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050ce60  89690c                 -mov dword ptr [ecx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0050ce63  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050ce65  0f84bd010000           -je 0x50d028
    if (cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
    // 0050ce6b  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ce6e  7405                   -je 0x50ce75
    if (cpu.flags.zf)
    {
        goto L_0x0050ce75;
    }
    // 0050ce70  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ce73  751e                   -jne 0x50ce93
    if (!cpu.flags.zf)
    {
        goto L_0x0050ce93;
    }
L_0x0050ce75:
    // 0050ce75  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0050ce79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050ce7b  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050ce7d  46                     -inc esi
    (cpu.esi)++;
    // 0050ce7e  e8b5060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050ce83  45                     -inc ebp
    (cpu.ebp)++;
    // 0050ce84  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ce86  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 0050ce8a  83f8ff                 +cmp eax, -1
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
    // 0050ce8d  0f849e010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050ce93:
    // 0050ce93  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050ce95  fec0                   -inc al
    (cpu.al)++;
    // 0050ce97  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ce9c  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cea3  7509                   -jne 0x50ceae
    if (!cpu.flags.zf)
    {
        goto L_0x0050ceae;
    }
    // 0050cea5  83fb2e                 +cmp ebx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cea8  0f857a010000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050ceae:
    // 0050ceae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ceb0  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0050ceb4  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050ceb6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050ceb8  fec0                   -inc al
    (cpu.al)++;
    // 0050ceba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cebf  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cec6  7441                   -je 0x50cf09
    if (cpu.flags.zf)
    {
        goto L_0x0050cf09;
    }
    // 0050cec8  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0050cecd:
    // 0050cecd  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cecf  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050ced2  46                     -inc esi
    (cpu.esi)++;
    // 0050ced3  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0050ced5  740f                   -je 0x50cee6
    if (cpu.flags.zf)
    {
        goto L_0x0050cee6;
    }
    // 0050ced7  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0050cedc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050cede  83eb30                 -sub ebx, 0x30
    (cpu.ebx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050cee1  66895c2466             -mov word ptr [esp + 0x66], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.bx;
L_0x0050cee6:
    // 0050cee6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cee8  47                     -inc edi
    (cpu.edi)++;
    // 0050cee9  e84a060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050ceee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cef0  83f8ff                 +cmp eax, -1
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
    // 0050cef3  0f8438010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cef9  fec0                   -inc al
    (cpu.al)++;
    // 0050cefb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf00  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf07  75c4                   -jne 0x50cecd
    if (!cpu.flags.zf)
    {
        goto L_0x0050cecd;
    }
L_0x0050cf09:
    // 0050cf09  83fb2e                 +cmp ebx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cf0c  0f8598000000           -jne 0x50cfaa
    if (!cpu.flags.zf)
    {
        goto L_0x0050cfaa;
    }
    // 0050cf12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cf14  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cf16  46                     -inc esi
    (cpu.esi)++;
    // 0050cf17  e81c060000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cf1c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cf1e  83f8ff                 +cmp eax, -1
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
    // 0050cf21  0f840a010000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cf27  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050cf29  7514                   -jne 0x50cf3f
    if (!cpu.flags.zf)
    {
        goto L_0x0050cf3f;
    }
    // 0050cf2b  fec0                   -inc al
    (cpu.al)++;
    // 0050cf2d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf32  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf39  0f84e9000000           -je 0x50d028
    if (cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050cf3f:
    // 0050cf3f  47                     -inc edi
    (cpu.edi)++;
L_0x0050cf40:
    // 0050cf40  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cf42  fec0                   -inc al
    (cpu.al)++;
    // 0050cf44  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cf49  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050cf50  7412                   -je 0x50cf64
    if (cpu.flags.zf)
    {
        goto L_0x0050cf64;
    }
    // 0050cf52  47                     -inc edi
    (cpu.edi)++;
    // 0050cf53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cf55  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cf57  46                     -inc esi
    (cpu.esi)++;
    // 0050cf58  e8db050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cf5d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cf5f  83f8ff                 +cmp eax, -1
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
    // 0050cf62  75dc                   -jne 0x50cf40
    if (!cpu.flags.zf)
    {
        goto L_0x0050cf40;
    }
L_0x0050cf64:
    // 0050cf64  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cf68  7437                   -je 0x50cfa1
    if (cpu.flags.zf)
    {
        goto L_0x0050cfa1;
    }
    // 0050cf6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050cf6c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050cf6e  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x0050cf72:
    // 0050cf72  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0050cf75  4d                     -dec ebp
    (cpu.ebp)--;
    // 0050cf76  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050cf78  741e                   -je 0x50cf98
    if (cpu.flags.zf)
    {
        goto L_0x0050cf98;
    }
    // 0050cf7a  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0050cf7c  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 0050cf84  88442462               -mov byte ptr [esp + 0x62], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 0050cf88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050cf8a  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0050cf8e  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0050cf92  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0050cf96  ebda                   -jmp 0x50cf72
    goto L_0x0050cf72;
L_0x0050cf98:
    // 0050cf98  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0050cf9c  6689442464             -mov word ptr [esp + 0x64], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x0050cfa1:
    // 0050cfa1  83fbff                 +cmp ebx, -1
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
    // 0050cfa4  0f8487000000           -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050cfaa:
    // 0050cfaa  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050cfae  0f8574000000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
    // 0050cfb4  83fb65                 +cmp ebx, 0x65
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfb7  7409                   -je 0x50cfc2
    if (cpu.flags.zf)
    {
        goto L_0x0050cfc2;
    }
    // 0050cfb9  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfbc  0f8566000000           -jne 0x50d028
    if (!cpu.flags.zf)
    {
        goto L_0x0050d028;
    }
L_0x0050cfc2:
    // 0050cfc2  47                     -inc edi
    (cpu.edi)++;
    // 0050cfc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cfc5  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cfc7  46                     -inc esi
    (cpu.esi)++;
    // 0050cfc8  e86b050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cfcd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cfcf  83f8ff                 +cmp eax, -1
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
    // 0050cfd2  745d                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050cfd4  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfd7  7405                   -je 0x50cfde
    if (cpu.flags.zf)
    {
        goto L_0x0050cfde;
    }
    // 0050cfd9  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050cfdc  7512                   -jne 0x50cff0
    if (!cpu.flags.zf)
    {
        goto L_0x0050cff0;
    }
L_0x0050cfde:
    // 0050cfde  47                     -inc edi
    (cpu.edi)++;
    // 0050cfdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050cfe1  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050cfe3  46                     -inc esi
    (cpu.esi)++;
    // 0050cfe4  e84f050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050cfe9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050cfeb  83f8ff                 +cmp eax, -1
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
    // 0050cfee  7441                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
L_0x0050cff0:
    // 0050cff0  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050cff2  fec0                   -inc al
    (cpu.al)++;
    // 0050cff4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050cff9  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050d000  7504                   -jne 0x50d006
    if (!cpu.flags.zf)
    {
        goto L_0x0050d006;
    }
    // 0050d002  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0050d004  eb22                   -jmp 0x50d028
    goto L_0x0050d028;
L_0x0050d006:
    // 0050d006  47                     -inc edi
    (cpu.edi)++;
    // 0050d007  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050d009  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 0050d00b  46                     -inc esi
    (cpu.esi)++;
    // 0050d00c  e827050000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d011  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050d013  83f8ff                 +cmp eax, -1
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
    // 0050d016  7419                   -je 0x50d031
    if (cpu.flags.zf)
    {
        goto L_0x0050d031;
    }
    // 0050d018  fec0                   -inc al
    (cpu.al)++;
    // 0050d01a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d01f  f680f04e560020         +test byte ptr [eax + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 0050d026  75de                   -jne 0x50d006
    if (!cpu.flags.zf)
    {
        goto L_0x0050d006;
    }
L_0x0050d028:
    // 0050d028  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050d02a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d02c  e817f6ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050d031:
    // 0050d031  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050d033  0f8eab000000           -jle 0x50d0e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d0e4;
    }
    // 0050d039  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0050d03d  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050d041  0f849d000000           -je 0x50d0e4
    if (cpu.flags.zf)
    {
        goto L_0x0050d0e4;
    }
    // 0050d047  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0050d04a  f6411010               +test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0050d04e  740c                   -je 0x50d05c
    if (cpu.flags.zf)
    {
        goto L_0x0050d05c;
    }
    // 0050d050  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d054  7512                   -jne 0x50d068
    if (!cpu.flags.zf)
    {
        goto L_0x0050d068;
    }
    // 0050d056  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0050d05a  eb0c                   -jmp 0x50d068
    goto L_0x0050d068;
L_0x0050d05c:
    // 0050d05c  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d060  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050d062  ff1568ac5600           -call dword ptr [0x56ac68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680232) /* 0x56ac68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0050d068:
    // 0050d068  8a6110                 -mov ah, byte ptr [ecx + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050d06b  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0050d06e  7410                   -je 0x50d080
    if (cpu.flags.zf)
    {
        goto L_0x0050d080;
    }
    // 0050d070  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d074  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d076  83c308                 +add ebx, 8
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
    // 0050d079  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0050d07b  c45bf8                 -les ebx, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0050d07e  eb2b                   -jmp 0x50d0ab
    goto L_0x0050d0ab;
L_0x0050d080:
    // 0050d080  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0050d083  7414                   -je 0x50d099
    if (cpu.flags.zf)
    {
        goto L_0x0050d099;
    }
    // 0050d085  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d089  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d08b  83c204                 +add edx, 4
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
    // 0050d08e  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d090  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d092  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d094  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d097  eb12                   -jmp 0x50d0ab
    goto L_0x0050d0ab;
L_0x0050d099:
    // 0050d099  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0050d09d  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d09f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d0a2  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 0050d0a4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d0a6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d0a8  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0050d0ab:
    // 0050d0ab  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050d0ae  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0050d0b1  7406                   -je 0x50d0b9
    if (cpu.flags.zf)
    {
        goto L_0x0050d0b9;
    }
    // 0050d0b3  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0050d0b7  eb28                   -jmp 0x50d0e1
    goto L_0x0050d0e1;
L_0x0050d0b9:
    // 0050d0b9  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0050d0bc  7505                   -jne 0x50d0c3
    if (!cpu.flags.zf)
    {
        goto L_0x0050d0c3;
    }
    // 0050d0be  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 0050d0c1  7411                   -je 0x50d0d4
    if (cpu.flags.zf)
    {
        goto L_0x0050d0d4;
    }
L_0x0050d0c3:
    // 0050d0c3  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d0c7  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 0050d0ca  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050d0ce  26894304               -mov dword ptr es:[ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050d0d2  eb10                   -jmp 0x50d0e4
    goto L_0x0050d0e4;
L_0x0050d0d4:
    // 0050d0d4  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0050d0d8  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0050d0dc  e8bf6b0100             -call 0x523ca0
    cpu.esp -= 4;
    sub_523ca0(app, cpu);
    if (cpu.terminate) return;
L_0x0050d0e1:
    // 0050d0e1  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x0050d0e4:
    // 0050d0e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d0e6  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0050d0e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ea  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d0eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d0ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50d0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d0f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d0f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d0f2  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050d0f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d0f4  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d0f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d0f9  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0050d0fd  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0050d101  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050d103  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d105  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050d109  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0050d10d  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0050d111  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0050d115:
    // 0050d115  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d117  e824f5ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050d11c  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d120  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d124  fec3                   -inc bl
    (cpu.bl)++;
    // 0050d126  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d12c  f683f04e560002         +test byte ptr [ebx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0050d133  7406                   -je 0x50d13b
    if (cpu.flags.zf)
    {
        goto L_0x0050d13b;
    }
    // 0050d135  ff442420               +inc dword ptr [esp + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050d139  ebda                   -jmp 0x50d115
    goto L_0x0050d115;
L_0x0050d13b:
    // 0050d13b  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050d13f  0f8590020000           -jne 0x50d3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d145  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0050d148  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0050d14b  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050d14e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050d150  0f8474020000           -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d156  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 0050d15b  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0050d15f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050d161  742e                   -je 0x50d191
    if (cpu.flags.zf)
    {
        goto L_0x0050d191;
    }
    // 0050d163  39d8                   +cmp eax, ebx
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
    // 0050d165  7405                   -je 0x50d16c
    if (cpu.flags.zf)
    {
        goto L_0x0050d16c;
    }
    // 0050d167  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d16a  7525                   -jne 0x50d191
    if (!cpu.flags.zf)
    {
        goto L_0x0050d191;
    }
L_0x0050d16c:
    // 0050d16c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d170  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d174  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050d178  41                     -inc ecx
    (cpu.ecx)++;
    // 0050d179  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d17b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050d17f  e8b4030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d184  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d188  83f8ff                 +cmp eax, -1
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
    // 0050d18b  0f8444020000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
L_0x0050d191:
    // 0050d191  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d195  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050d197  0f8569000000           -jne 0x50d206
    if (!cpu.flags.zf)
    {
        goto L_0x0050d206;
    }
    // 0050d19d  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d1a2  7558                   -jne 0x50d1fc
    if (!cpu.flags.zf)
    {
        goto L_0x0050d1fc;
    }
    // 0050d1a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d1a6  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0050d1ab  e888030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d1b0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d1b4  83f8ff                 +cmp eax, -1
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
    // 0050d1b7  0f8418020000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d1bd  83f878                 +cmp eax, 0x78
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
    // 0050d1c0  7405                   -je 0x50d1c7
    if (cpu.flags.zf)
    {
        goto L_0x0050d1c7;
    }
    // 0050d1c2  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d1c5  752b                   -jne 0x50d1f2
    if (!cpu.flags.zf)
    {
        goto L_0x0050d1f2;
    }
L_0x0050d1c7:
    // 0050d1c7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d1c9  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d1cd  e866030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d1d2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d1d4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d1d7  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d1db  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0050d1df  83f8ff                 +cmp eax, -1
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
    // 0050d1e2  0f84ed010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d1e8  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 0050d1f0  eb64                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d1f2:
    // 0050d1f2  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 0050d1fa  eb5a                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d1fc:
    // 0050d1fc  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 0050d204  eb50                   -jmp 0x50d256
    goto L_0x0050d256;
L_0x0050d206:
    // 0050d206  83fe10                 +cmp esi, 0x10
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
    // 0050d209  754b                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
    // 0050d20b  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d210  7544                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
    // 0050d212  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d214  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0050d219  e81a030000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d21e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d222  83f8ff                 +cmp eax, -1
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
    // 0050d225  0f84aa010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d22b  83f878                 +cmp eax, 0x78
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
    // 0050d22e  7405                   -je 0x50d235
    if (cpu.flags.zf)
    {
        goto L_0x0050d235;
    }
    // 0050d230  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d233  7521                   -jne 0x50d256
    if (!cpu.flags.zf)
    {
        goto L_0x0050d256;
    }
L_0x0050d235:
    // 0050d235  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d237  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d23b  e8f8020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d240  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d242  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d245  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d249  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0050d24d  83f8ff                 +cmp eax, -1
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
    // 0050d250  0f847f010000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
L_0x0050d256:
    // 0050d256  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0050d25a  0f84ff000000           -je 0x50d35f
    if (cpu.flags.zf)
    {
        goto L_0x0050d35f;
    }
    // 0050d260  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d264  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d266  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050d26a  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0050d26e:
    // 0050d26e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d272  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d276  e895020000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d27b  39d0                   +cmp eax, edx
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
    // 0050d27d  7d5d                   -jge 0x50d2dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d2dc;
    }
    // 0050d27f  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d283  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d286  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050d288  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d28c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050d290  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050d294  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d297  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d299  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d29c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d29e  e8496a0100             -call 0x523cec
    cpu.esp -= 4;
    sub_523cec(app, cpu);
    if (cpu.terminate) return;
    // 0050d2a3  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d2a6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d2a8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d2ac  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050d2ae  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d2b2  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d2b5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d2b7  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d2ba  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d2bc  01d8                   +add eax, ebx
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
    // 0050d2be  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0050d2c0  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d2c3  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d2c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d2c7  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d2c8  e86b020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d2cd  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d2d1  83f8ff                 +cmp eax, -1
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
    // 0050d2d4  0f84fb000000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d2da  eb92                   -jmp 0x50d26e
    goto L_0x0050d26e;
L_0x0050d2dc:
    // 0050d2dc  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d2e1  0f85e3000000           -jne 0x50d3ca
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d2e7  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0050d2eb  0f84d9000000           -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
L_0x0050d2f1:
    // 0050d2f1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d2f3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d2f4  e83f020000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d2f9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d2fd  83f8ff                 +cmp eax, -1
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
    // 0050d300  0f84cf000000           -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d306  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050d30a  e801020000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d30f  39f0                   +cmp eax, esi
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
    // 0050d311  0f8db3000000           -jge 0x50d3ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d3ca;
    }
    // 0050d317  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d31b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d31e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d320  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050d324  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050d328  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d32c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d32f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d331  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d334  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d336  e8b1690100             -call 0x523cec
    cpu.esp -= 4;
    sub_523cec(app, cpu);
    if (cpu.terminate) return;
    // 0050d33b  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d33e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d340  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d344  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050d346  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d34a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050d34d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d34f  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050d352  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050d354  01d8                   +add eax, ebx
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
    // 0050d356  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d358  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050d35b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050d35d  eb92                   -jmp 0x50d2f1
    goto L_0x0050d2f1;
L_0x0050d35f:
    // 0050d35f  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0050d363:
    // 0050d363  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d367  e8a4010000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d36c  39f0                   +cmp eax, esi
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
    // 0050d36e  7d20                   -jge 0x50d390
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d390;
    }
    // 0050d370  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d374  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d377  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d378  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d37a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d37c  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050d380  e8b3010000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d385  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d389  83f8ff                 +cmp eax, -1
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
    // 0050d38c  7447                   -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d38e  ebd3                   -jmp 0x50d363
    goto L_0x0050d363;
L_0x0050d390:
    // 0050d390  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d395  7533                   -jne 0x50d3ca
    if (!cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d397  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0050d39b  742d                   -je 0x50d3ca
    if (cpu.flags.zf)
    {
        goto L_0x0050d3ca;
    }
    // 0050d39d  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0050d3a1:
    // 0050d3a1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050d3a3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050d3a4  e88f010000             -call 0x50d538
    cpu.esp -= 4;
    sub_50d538(app, cpu);
    if (cpu.terminate) return;
    // 0050d3a9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0050d3ad  83f8ff                 +cmp eax, -1
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
    // 0050d3b0  7423                   -je 0x50d3d5
    if (cpu.flags.zf)
    {
        goto L_0x0050d3d5;
    }
    // 0050d3b2  e859010000             -call 0x50d510
    cpu.esp -= 4;
    sub_50d510(app, cpu);
    if (cpu.terminate) return;
    // 0050d3b7  39c8                   +cmp eax, ecx
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
    // 0050d3b9  7d0f                   -jge 0x50d3ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050d3ca;
    }
    // 0050d3bb  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d3bf  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050d3c2  01c3                   +add ebx, eax
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
    // 0050d3c4  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0050d3c8  ebd7                   -jmp 0x50d3a1
    goto L_0x0050d3a1;
L_0x0050d3ca:
    // 0050d3ca  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050d3ce  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050d3d0  e873f2ffff             -call 0x50c648
    cpu.esp -= 4;
    sub_50c648(app, cpu);
    if (cpu.terminate) return;
L_0x0050d3d5:
    // 0050d3d5  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0050d3d9  0f84a2000000           -je 0x50d481
    if (cpu.flags.zf)
    {
        goto L_0x0050d481;
    }
    // 0050d3df  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d3e4  7524                   -jne 0x50d40a
    if (!cpu.flags.zf)
    {
        goto L_0x0050d40a;
    }
    // 0050d3e6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d3ea  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d3ee  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0050d3f0  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0050d3f2  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050d3f6  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050d3f9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050d3fd  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050d401  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050d403  7501                   -jne 0x50d406
    if (!cpu.flags.zf)
    {
        goto L_0x0050d406;
    }
    // 0050d405  40                     -inc eax
    (cpu.eax)++;
L_0x0050d406:
    // 0050d406  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050d40a:
    // 0050d40a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050d40c  0f8ef1000000           -jle 0x50d503
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d503;
    }
    // 0050d412  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d416  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d419  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d41b  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0050d41e  0f84df000000           -je 0x50d503
    if (cpu.flags.zf)
    {
        goto L_0x0050d503;
    }
    // 0050d424  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0050d427  7414                   -je 0x50d43d
    if (cpu.flags.zf)
    {
        goto L_0x0050d43d;
    }
    // 0050d429  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d42d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d42f  83c208                 +add edx, 8
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
    // 0050d432  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d434  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d438  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0050d43b  eb32                   -jmp 0x50d46f
    goto L_0x0050d46f;
L_0x0050d43d:
    // 0050d43d  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0050d440  741d                   -je 0x50d45f
    if (cpu.flags.zf)
    {
        goto L_0x0050d45f;
    }
    // 0050d442  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d446  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d448  83c704                 +add edi, 4
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
    // 0050d44b  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0050d44d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d44f  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0050d452  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d456  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d458  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d459  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d45a  e9a4000000             -jmp 0x50d503
    goto L_0x0050d503;
L_0x0050d45f:
    // 0050d45f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d463  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d465  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d468  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050d46a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050d46c  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0050d46f:
    // 0050d46f  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050d473  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050d475  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d476  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050d477  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d479  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d47c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d47d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d47e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d47f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d480  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d481:
    // 0050d481  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d486  7504                   -jne 0x50d48c
    if (!cpu.flags.zf)
    {
        goto L_0x0050d48c;
    }
    // 0050d488  f75c2424               -neg dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x0050d48c:
    // 0050d48c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050d48e  0f8e6f000000           -jle 0x50d503
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050d503;
    }
    // 0050d494  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050d498  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d49b  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d49d  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0050d49f  7462                   -je 0x50d503
    if (cpu.flags.zf)
    {
        goto L_0x0050d503;
    }
    // 0050d4a1  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0050d4a3  7410                   -je 0x50d4b5
    if (cpu.flags.zf)
    {
        goto L_0x0050d4b5;
    }
    // 0050d4a5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4a9  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4ab  83c308                 +add ebx, 8
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
    // 0050d4ae  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0050d4b0  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0050d4b3  eb2a                   -jmp 0x50d4df
    goto L_0x0050d4df;
L_0x0050d4b5:
    // 0050d4b5  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0050d4b7  7414                   -je 0x50d4cd
    if (cpu.flags.zf)
    {
        goto L_0x0050d4cd;
    }
    // 0050d4b9  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4bd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4bf  83c204                 +add edx, 4
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
    // 0050d4c2  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0050d4c4  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050d4c6  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0050d4c8  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0050d4cb  eb12                   -jmp 0x50d4df
    goto L_0x0050d4df;
L_0x0050d4cd:
    // 0050d4cd  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050d4d1  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050d4d3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d4d6  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0050d4d8  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050d4da  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0050d4dc  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0050d4df:
    // 0050d4df  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050d4e2  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0050d4e5  7412                   -je 0x50d4f9
    if (cpu.flags.zf)
    {
        goto L_0x0050d4f9;
    }
    // 0050d4e7  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d4eb  66268918               -mov word ptr es:[eax], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 0050d4ef  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d4f1  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d4f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d4f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d4f9:
    // 0050d4f9  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0050d4fc  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050d500  268918                 -mov dword ptr es:[eax], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x0050d503:
    // 0050d503  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050d505  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d508  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d509  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050d50a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d50b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d50c  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
