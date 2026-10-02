#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52eb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052eb71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052eb72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052eb73  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052eb74  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0052eb76  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0052eb78  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052eb79  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052eb7b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052eb7e  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052eb81  8b1520649f00           -mov edx, dword ptr [0x9f6420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445856) /* 0x9f6420 */);
    // 0052eb87  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052eb89  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052eb8c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052eb8f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052eb91  7531                   -jne 0x52ebc4
    if (!cpu.flags.zf)
    {
        goto L_0x0052ebc4;
    }
    // 0052eb93  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052eb98  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0052eb9b  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0052eb9d  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052eb9f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0052eba1  8b1d70af5600           -mov ebx, dword ptr [0x56af70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052eba7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052eba9  e8921afbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052ebae  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0052ebb3  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 0052ebb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ebbb  e8c8fcfeff             -call 0x51e888
    cpu.esp -= 4;
    sub_51e888(app, cpu);
    if (cpu.terminate) return;
    // 0052ebc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ebc2  7431                   -je 0x52ebf5
    if (cpu.flags.zf)
    {
        goto L_0x0052ebf5;
    }
L_0x0052ebc4:
    // 0052ebc4  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebca  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052ebcd  05de000000             -add eax, 0xde
    (cpu.eax) += x86::reg32(x86::sreg32(222 /*0xde*/));
    // 0052ebd2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ebd3  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052ebd6  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebdd  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0052ebe0  e8eb04ffff             -call 0x51f0d0
    cpu.esp -= 4;
    sub_51f0d0(app, cpu);
    if (cpu.terminate) return;
    // 0052ebe5  ff15a4775600           -call dword ptr [0x5677a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666724) /* 0x5677a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebeb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052ebed  ff55fc                 -call dword ptr [ebp - 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ebf0  e827dcffff             -call 0x52c81c
    cpu.esp -= 4;
    sub_52c81c(app, cpu);
    if (cpu.terminate) return;
L_0x0052ebf5:
    // 0052ebf5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052ebf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebf8  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfa  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ebff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ec00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ec04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ec04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ec05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ec06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ec07  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052ec08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ec09  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052ec0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052ec0e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052ec10  833d60775600ff         +cmp dword ptr [0x567760], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ec17  7512                   -jne 0x52ec2b
    if (!cpu.flags.zf)
    {
        goto L_0x0052ec2b;
    }
    // 0052ec19  e80afcfeff             -call 0x51e828
    cpu.esp -= 4;
    sub_51e828(app, cpu);
    if (cpu.terminate) return;
    // 0052ec1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ec20  0f84be000000           -je 0x52ece4
    if (cpu.flags.zf)
    {
        goto L_0x0052ece4;
    }
    // 0052ec26  e839fdfeff             -call 0x51e964
    cpu.esp -= 4;
    sub_51e964(app, cpu);
    if (cpu.terminate) return;
L_0x0052ec2b:
    // 0052ec2b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0052ec2d  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052ec31  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0052ec35  2eff1510455300         -call dword ptr cs:[0x534510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457168) /* 0x534510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec3c  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0052ec40  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052ec42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ec44  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052ec46  be34215500             -mov esi, 0x552134
    cpu.esi = 5579060 /*0x552134*/;
    // 0052ec4b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0052ec4f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052ec54  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052ec55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052ec56  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052ec57  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec5e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ec62  e885f4feff             -call 0x51e0ec
    cpu.esp -= 4;
    sub_51e0ec(app, cpu);
    if (cpu.terminate) return;
    // 0052ec67  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ec69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec6a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec6c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec70  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ec77  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0052ec7b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0052ec7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec80  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec82  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0052ec86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ec87  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0052ec8d  6870eb5200             -push 0x52eb70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5434224 /*0x52eb70*/;
    cpu.esp -= 4;
    // 0052ec92  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0052ec98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ec99  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ec9b  2eff15a4445300         -call dword ptr cs:[0x5344a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457060) /* 0x5344a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052eca2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052eca4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052eca6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eca8  750a                   -jne 0x52ecb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052ecb4;
    }
    // 0052ecaa  c7442434ffffffff       -mov dword ptr [esp + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 0052ecb2  eb22                   -jmp 0x52ecd6
    goto L_0x0052ecd6;
L_0x0052ecb4:
    // 0052ecb4  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0052ecb6  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0052ecba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ecbb  2eff1534465300         -call dword ptr cs:[0x534634]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457460) /* 0x534634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ecc2  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0052ecc6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052ecc8  7404                   -je 0x52ecce
    if (cpu.flags.zf)
    {
        goto L_0x0052ecce;
    }
    // 0052ecca  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0052eccc  eb08                   -jmp 0x52ecd6
    goto L_0x0052ecd6;
L_0x0052ecce:
    // 0052ecce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052eccf  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ecd6:
    // 0052ecd6  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0052ecda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ecdb  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ece2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0052ece4:
    // 0052ece4  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052ece7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ece8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052ece9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ecea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ecec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ecf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ecf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ecf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ecf2  ff15a8775600           -call dword ptr [0x5677a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666728) /* 0x5677a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ecf8  e81f04ffff             -call 0x51f11c
    cpu.esp -= 4;
    sub_51f11c(app, cpu);
    if (cpu.terminate) return;
    // 0052ecfd  833d20649f0000         +cmp dword ptr [0x9f6420], 0
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
    // 0052ed04  750a                   -jne 0x52ed10
    if (!cpu.flags.zf)
    {
        goto L_0x0052ed10;
    }
    // 0052ed06  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ed0b  e8ccfbfeff             -call 0x51e8dc
    cpu.esp -= 4;
    sub_51e8dc(app, cpu);
    if (cpu.terminate) return;
L_0x0052ed10:
    // 0052ed10  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052ed12  2eff15c4445300         -call dword ptr cs:[0x5344c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457092) /* 0x5344c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ed19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52ed20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed20  ff1553785600           -call dword ptr [0x567853]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666899) /* 0x567853 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ed26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ed30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ed31  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ed38  7428                   -je 0x52ed62
    if (cpu.flags.zf)
    {
        goto L_0x0052ed62;
    }
    // 0052ed3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed3c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed3e  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052ed44  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052ed47  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052ed4d  7413                   -je 0x52ed62
    if (cpu.flags.zf)
    {
        goto L_0x0052ed62;
    }
    // 0052ed4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed51  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed53  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052ed56  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052ed59  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ed5e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ed60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ed62:
    // 0052ed62  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0052ed64  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ed69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ed6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ed70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ed71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ed72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ed73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ed76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ed78  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ed7a  e861000000             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ed7f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ed81  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052ed83  e828c8ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052ed88  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052ed8b  813db8b05600a4030000   +cmp dword ptr [0x56b0b8], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ed95  7526                   -jne 0x52edbd
    if (!cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052ed97  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ed9e  741d                   -je 0x52edbd
    if (cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052eda0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052eda2  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0052eda5  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052edab  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052edad  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052edb2  7409                   -je 0x52edbd
    if (cpu.flags.zf)
    {
        goto L_0x0052edbd;
    }
    // 0052edb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052edb6  e805010000             -call 0x52eec0
    cpu.esp -= 4;
    sub_52eec0(app, cpu);
    if (cpu.terminate) return;
    // 0052edbb  eb15                   -jmp 0x52edd2
    goto L_0x0052edd2;
L_0x0052edbd:
    // 0052edbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052edbf  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052edc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052edc4  2eff15fc465300         -call dword ptr cs:[0x5346fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457660) /* 0x5346fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052edcb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052edcd  e85effffff             -call 0x52ed30
    cpu.esp -= 4;
    sub_52ed30(app, cpu);
    if (cpu.terminate) return;
L_0x0052edd2:
    // 0052edd2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052edd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ede0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ede1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ede3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ede5  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 0052ede8  740c                   -je 0x52edf6
    if (cpu.flags.zf)
    {
        goto L_0x0052edf6;
    }
    // 0052edea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052edec  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0052edef  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052edf2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0052edf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052edf6:
    // 0052edf6  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0052edf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052edf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52edfa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052edfa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052edfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52ee00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ee00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ee01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee03  7c49                   -jl 0x52ee4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee4e;
    }
L_0x0052ee05:
    // 0052ee05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052ee07  7c49                   -jl 0x52ee52
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee52;
    }
L_0x0052ee09:
    // 0052ee09  8b35f84f5600           -mov esi, dword ptr [0x564ff8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052ee0f  39f0                   +cmp eax, esi
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
    // 0052ee11  7e02                   -jle 0x52ee15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee15;
    }
    // 0052ee13  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0052ee15:
    // 0052ee15  39f3                   +cmp ebx, esi
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
    // 0052ee17  7e02                   -jle 0x52ee1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee1b;
    }
    // 0052ee19  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0052ee1b:
    // 0052ee1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ee1d  7c37                   -jl 0x52ee56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee56;
    }
L_0x0052ee1f:
    // 0052ee1f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052ee21  7c37                   -jl 0x52ee5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ee5a;
    }
L_0x0052ee23:
    // 0052ee23  8b35fc4f5600           -mov esi, dword ptr [0x564ffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052ee29  39f2                   +cmp edx, esi
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
    // 0052ee2b  7e02                   -jle 0x52ee2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee2f;
    }
    // 0052ee2d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052ee2f:
    // 0052ee2f  39f1                   +cmp ecx, esi
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
    // 0052ee31  7e02                   -jle 0x52ee35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ee35;
    }
    // 0052ee33  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052ee35:
    // 0052ee35  891d08505600           -mov dword ptr [0x565008], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */) = cpu.ebx;
    // 0052ee3b  891504505600           -mov dword ptr [0x565004], edx
    app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */) = cpu.edx;
    // 0052ee41  890d0c505600           -mov dword ptr [0x56500c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */) = cpu.ecx;
    // 0052ee47  a300505600             -mov dword ptr [0x565000], eax
    app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */) = cpu.eax;
    // 0052ee4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ee4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ee4e:
    // 0052ee4e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052ee50  ebb3                   -jmp 0x52ee05
    goto L_0x0052ee05;
L_0x0052ee52:
    // 0052ee52  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052ee54  ebb3                   -jmp 0x52ee09
    goto L_0x0052ee09;
L_0x0052ee56:
    // 0052ee56  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052ee58  ebc5                   -jmp 0x52ee1f
    goto L_0x0052ee1f;
L_0x0052ee5a:
    // 0052ee5a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052ee5c  ebc5                   -jmp 0x52ee23
    goto L_0x0052ee23;
}

/* align: skip 0x00 0x00 */
void Application::sub_52ee60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ee60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052ee61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ee62  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ee65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ee67  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052ee69  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ee6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ee6d  e86effffff             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee72  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052ee74  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052ee76  e835c7ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee7b  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x0052ee7e:
    // 0052ee7e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee80  e83b62ffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee87  7518                   -jne 0x52eea1
    if (!cpu.flags.zf)
    {
        goto L_0x0052eea1;
    }
    // 0052ee89  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052ee8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee8d  e80ef5ffff             -call 0x52e3a0
    cpu.esp -= 4;
    sub_52e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0052ee92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ee94  740b                   -je 0x52eea1
    if (cpu.flags.zf)
    {
        goto L_0x0052eea1;
    }
    // 0052ee96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ee98  e86362ffff             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 0052ee9d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ee9f  ebdd                   -jmp 0x52ee7e
    goto L_0x0052ee7e;
L_0x0052eea1:
    // 0052eea1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052eea3  e81862ffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052eea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeaa  7404                   -je 0x52eeb0
    if (cpu.flags.zf)
    {
        goto L_0x0052eeb0;
    }
    // 0052eeac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052eeae  7504                   -jne 0x52eeb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052eeb4;
    }
L_0x0052eeb0:
    // 0052eeb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052eeb2  eb02                   -jmp 0x52eeb6
    goto L_0x0052eeb6;
L_0x0052eeb4:
    // 0052eeb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052eeb6:
    // 0052eeb6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052eeb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eeba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52eec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eec0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052eec1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052eec3  e818000000             -call 0x52eee0
    cpu.esp -= 4;
    sub_52eee0(app, cpu);
    if (cpu.terminate) return;
    // 0052eec8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeca  7403                   -je 0x52eecf
    if (cpu.flags.zf)
    {
        goto L_0x0052eecf;
    }
    // 0052eecc  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x0052eecf:
    // 0052eecf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052eed1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052eed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52eee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052eee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052eee1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052eee3  e848000000             -call 0x52ef30
    cpu.esp -= 4;
    sub_52ef30(app, cpu);
    if (cpu.terminate) return;
    // 0052eee8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052eeea  741f                   -je 0x52ef0b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef0b;
    }
    // 0052eeec  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052eef2  7211                   -jb 0x52ef05
    if (cpu.flags.cf)
    {
        goto L_0x0052ef05;
    }
    // 0052eef4  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052eefa  7709                   -ja 0x52ef05
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052ef05;
    }
    // 0052eefc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052ef01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef05:
    // 0052ef05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ef07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef0b:
    // 0052ef0b  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0052ef0d  fec0                   -inc al
    (cpu.al)++;
    // 0052ef0f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef14  8a80f04e5600           -mov al, byte ptr [eax + 0x564ef0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */);
    // 0052ef1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ef1c  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0052ef1e  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0052ef20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ef22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ef30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052ef31  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ef38  7431                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052ef3c  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052ef3f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef45  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052ef4b  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052ef4e  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052ef54  7415                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef56  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef5b  e810000000             -call 0x52ef70
    cpu.esp -= 4;
    sub_52ef70(app, cpu);
    if (cpu.terminate) return;
    // 0052ef60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ef62  7407                   -je 0x52ef6b
    if (cpu.flags.zf)
    {
        goto L_0x0052ef6b;
    }
    // 0052ef64  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ef69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef6b:
    // 0052ef6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ef6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ef6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ef70  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
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
    // 0052ef77  7429                   -je 0x52efa2
    if (cpu.flags.zf)
    {
        goto L_0x0052efa2;
    }
    // 0052ef79  813db8b05600a4030000   +cmp dword ptr [0x56b0b8], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ef83  740a                   -je 0x52ef8f
    if (cpu.flags.zf)
    {
        goto L_0x0052ef8f;
    }
    // 0052ef85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ef87  741b                   -je 0x52efa4
    if (cpu.flags.zf)
    {
        goto L_0x0052efa4;
    }
    // 0052ef89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ef8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ef8f:
    // 0052ef8f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ef94  8a80ddb65600           -mov al, byte ptr [eax + 0x56b6dd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5682909) /* 0x56b6dd */);
    // 0052ef9a  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0052ef9c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052efa1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052efa2:
    // 0052efa2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052efa4:
    // 0052efa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 68b956000000000003ffff000000000058b956000400000003ffff000000000048b956000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff80000000001800000010000000020000001000000007000000b0ef5200000000000000000068b956000000000003ffff800001000058b956000400000003ffff800001000048b956000800000003ffff8000010000c8b956000c00000003ffff8000010000b8b956001000000003ffff8000010000a8b956001400000003ffff800001000098b956001800000003ffff800001000098b956001c00000003ffff800001000088b956002000000010ffff800000000088b956002400000010ffff800000000088b956002800000010ffff800000000088b956002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c00000040f05200 */
void Application::sub_52f318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f318  833d2cd1560000         +cmp dword ptr [0x56d12c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f31f  751e                   -jne 0x52f33f
    if (!cpu.flags.zf)
    {
        goto L_0x0052f33f;
    }
    // 0052f321  68d8b95600             -push 0x56b9d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683672 /*0x56b9d8*/;
    cpu.esp -= 4;
    // 0052f326  ff158c455300           -call dword ptr [0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052f32c  a32cd15600             -mov dword ptr [0x56d12c], eax
    app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */) = cpu.eax;
    // 0052f331  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f333  750a                   -jne 0x52f33f
    if (!cpu.flags.zf)
    {
        goto L_0x0052f33f;
    }
    // 0052f335  c7052cd15600ffffffff   -mov dword ptr [0x56d12c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */) = 4294967295 /*0xffffffff*/;
L_0x0052f33f:
    // 0052f33f  833d2cd15600ff         +cmp dword ptr [0x56d12c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f346  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f34b  7420                   -je 0x52f36d
    if (cpu.flags.zf)
    {
        goto L_0x0052f36d;
    }
    // 0052f34d  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f351  ff352cd15600           -push dword ptr [0x56d12c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5689644) /* 0x56d12c */);
    cpu.esp -= 4;
    // 0052f357  ff1558455300           -call dword ptr [0x534558]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052f35d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052f361  83f801                 +cmp eax, 1
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
    // 0052f364  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052f366  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0052f368  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x0052f36d:
    // 0052f36d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f370  833d34d1560000         +cmp dword ptr [0x56d134], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f377  751f                   -jne 0x52f398
    if (!cpu.flags.zf)
    {
        goto L_0x0052f398;
    }
    // 0052f379  6834d15600             -push 0x56d134
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689652 /*0x56d134*/;
    cpu.esp -= 4;
    // 0052f37e  68e4b95600             -push 0x56b9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683684 /*0x56b9e4*/;
    cpu.esp -= 4;
    // 0052f383  e890ffffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f38a  740c                   -je 0x52f398
    if (cpu.flags.zf)
    {
        goto L_0x0052f398;
    }
    // 0052f38c  c70534d15600ffffffff   -mov dword ptr [0x56d134], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */) = 4294967295 /*0xffffffff*/;
    // 0052f396  eb20                   -jmp 0x52f3b8
    goto L_0x0052f3b8;
L_0x0052f398:
    // 0052f398  833d34d15600ff         +cmp dword ptr [0x56d134], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f39f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f3a4  7412                   -je 0x52f3b8
    if (cpu.flags.zf)
    {
        goto L_0x0052f3b8;
    }
    // 0052f3a6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3aa  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3ae  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3b2  ff1534d15600           -call dword ptr [0x56d134]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689652) /* 0x56d134 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f3b8:
    // 0052f3b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f3bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f3bb  833d38d1560000         +cmp dword ptr [0x56d138], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f3c2  751f                   -jne 0x52f3e3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f3e3;
    }
    // 0052f3c4  6838d15600             -push 0x56d138
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689656 /*0x56d138*/;
    cpu.esp -= 4;
    // 0052f3c9  68f0b95600             -push 0x56b9f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683696 /*0x56b9f0*/;
    cpu.esp -= 4;
    // 0052f3ce  e845ffffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f3d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f3d5  740c                   -je 0x52f3e3
    if (cpu.flags.zf)
    {
        goto L_0x0052f3e3;
    }
    // 0052f3d7  c70538d15600ffffffff   -mov dword ptr [0x56d138], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */) = 4294967295 /*0xffffffff*/;
    // 0052f3e1  eb20                   -jmp 0x52f403
    goto L_0x0052f403;
L_0x0052f3e3:
    // 0052f3e3  833d38d15600ff         +cmp dword ptr [0x56d138], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f3ea  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f3ef  7412                   -je 0x52f403
    if (cpu.flags.zf)
    {
        goto L_0x0052f403;
    }
    // 0052f3f1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3f5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3f9  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f3fd  ff1538d15600           -call dword ptr [0x56d138]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689656) /* 0x56d138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f403:
    // 0052f403  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f406(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f406  833d3cd1560000         +cmp dword ptr [0x56d13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f40d  751f                   -jne 0x52f42e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f42e;
    }
    // 0052f40f  683cd15600             -push 0x56d13c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689660 /*0x56d13c*/;
    cpu.esp -= 4;
    // 0052f414  6800ba5600             -push 0x56ba00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683712 /*0x56ba00*/;
    cpu.esp -= 4;
    // 0052f419  e8fafeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f41e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f420  740c                   -je 0x52f42e
    if (cpu.flags.zf)
    {
        goto L_0x0052f42e;
    }
    // 0052f422  c7053cd15600ffffffff   -mov dword ptr [0x56d13c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */) = 4294967295 /*0xffffffff*/;
    // 0052f42c  eb20                   -jmp 0x52f44e
    goto L_0x0052f44e;
L_0x0052f42e:
    // 0052f42e  833d3cd15600ff         +cmp dword ptr [0x56d13c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f435  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f43a  7412                   -je 0x52f44e
    if (cpu.flags.zf)
    {
        goto L_0x0052f44e;
    }
    // 0052f43c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f440  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f444  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f448  ff153cd15600           -call dword ptr [0x56d13c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689660) /* 0x56d13c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f44e:
    // 0052f44e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f451(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f451  833d40d1560000         +cmp dword ptr [0x56d140], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f458  751f                   -jne 0x52f479
    if (!cpu.flags.zf)
    {
        goto L_0x0052f479;
    }
    // 0052f45a  6840d15600             -push 0x56d140
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689664 /*0x56d140*/;
    cpu.esp -= 4;
    // 0052f45f  6814ba5600             -push 0x56ba14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683732 /*0x56ba14*/;
    cpu.esp -= 4;
    // 0052f464  e8affeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f469  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f46b  740c                   -je 0x52f479
    if (cpu.flags.zf)
    {
        goto L_0x0052f479;
    }
    // 0052f46d  c70540d15600ffffffff   -mov dword ptr [0x56d140], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */) = 4294967295 /*0xffffffff*/;
    // 0052f477  eb20                   -jmp 0x52f499
    goto L_0x0052f499;
L_0x0052f479:
    // 0052f479  833d40d15600ff         +cmp dword ptr [0x56d140], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f480  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f485  7412                   -je 0x52f499
    if (cpu.flags.zf)
    {
        goto L_0x0052f499;
    }
    // 0052f487  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f48b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f48f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f493  ff1540d15600           -call dword ptr [0x56d140]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689664) /* 0x56d140 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f499:
    // 0052f499  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f49c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f49c  833d44d1560000         +cmp dword ptr [0x56d144], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4a3  751f                   -jne 0x52f4c4
    if (!cpu.flags.zf)
    {
        goto L_0x0052f4c4;
    }
    // 0052f4a5  6844d15600             -push 0x56d144
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689668 /*0x56d144*/;
    cpu.esp -= 4;
    // 0052f4aa  6828ba5600             -push 0x56ba28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683752 /*0x56ba28*/;
    cpu.esp -= 4;
    // 0052f4af  e864feffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f4b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f4b6  740c                   -je 0x52f4c4
    if (cpu.flags.zf)
    {
        goto L_0x0052f4c4;
    }
    // 0052f4b8  c70544d15600ffffffff   -mov dword ptr [0x56d144], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */) = 4294967295 /*0xffffffff*/;
    // 0052f4c2  eb1c                   -jmp 0x52f4e0
    goto L_0x0052f4e0;
L_0x0052f4c4:
    // 0052f4c4  833d44d15600ff         +cmp dword ptr [0x56d144], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4cb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f4d0  740e                   -je 0x52f4e0
    if (cpu.flags.zf)
    {
        goto L_0x0052f4e0;
    }
    // 0052f4d2  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f4d6  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f4da  ff1544d15600           -call dword ptr [0x56d144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689668) /* 0x56d144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f4e0:
    // 0052f4e0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f4e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f4e3  833d48d1560000         +cmp dword ptr [0x56d148], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f4ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f4eb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f4ed  751f                   -jne 0x52f50e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f50e;
    }
    // 0052f4ef  6848d15600             -push 0x56d148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689672 /*0x56d148*/;
    cpu.esp -= 4;
    // 0052f4f4  683cba5600             -push 0x56ba3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683772 /*0x56ba3c*/;
    cpu.esp -= 4;
    // 0052f4f9  e81afeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f4fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f500  740c                   -je 0x52f50e
    if (cpu.flags.zf)
    {
        goto L_0x0052f50e;
    }
    // 0052f502  c70548d15600ffffffff   -mov dword ptr [0x56d148], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */) = 4294967295 /*0xffffffff*/;
    // 0052f50c  eb23                   -jmp 0x52f531
    goto L_0x0052f531;
L_0x0052f50e:
    // 0052f50e  833d48d15600ff         +cmp dword ptr [0x56d148], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f515  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f51a  7415                   -je 0x52f531
    if (cpu.flags.zf)
    {
        goto L_0x0052f531;
    }
    // 0052f51c  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f51f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f522  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f525  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f528  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f52b  ff1548d15600           -call dword ptr [0x56d148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689672) /* 0x56d148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f531:
    // 0052f531  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f532  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52f535(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f535  833d4cd1560000         +cmp dword ptr [0x56d14c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f53c  751f                   -jne 0x52f55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052f55d;
    }
    // 0052f53e  684cd15600             -push 0x56d14c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689676 /*0x56d14c*/;
    cpu.esp -= 4;
    // 0052f543  6850ba5600             -push 0x56ba50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683792 /*0x56ba50*/;
    cpu.esp -= 4;
    // 0052f548  e8cbfdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f54d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f54f  740c                   -je 0x52f55d
    if (cpu.flags.zf)
    {
        goto L_0x0052f55d;
    }
    // 0052f551  c7054cd15600ffffffff   -mov dword ptr [0x56d14c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */) = 4294967295 /*0xffffffff*/;
    // 0052f55b  eb20                   -jmp 0x52f57d
    goto L_0x0052f57d;
L_0x0052f55d:
    // 0052f55d  833d4cd15600ff         +cmp dword ptr [0x56d14c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f564  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f569  7412                   -je 0x52f57d
    if (cpu.flags.zf)
    {
        goto L_0x0052f57d;
    }
    // 0052f56b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f56f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f573  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f577  ff154cd15600           -call dword ptr [0x56d14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689676) /* 0x56d14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f57d:
    // 0052f57d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f580  833d50d1560000         +cmp dword ptr [0x56d150], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f587  751f                   -jne 0x52f5a8
    if (!cpu.flags.zf)
    {
        goto L_0x0052f5a8;
    }
    // 0052f589  6850d15600             -push 0x56d150
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689680 /*0x56d150*/;
    cpu.esp -= 4;
    // 0052f58e  685cba5600             -push 0x56ba5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683804 /*0x56ba5c*/;
    cpu.esp -= 4;
    // 0052f593  e880fdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f598  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f59a  740c                   -je 0x52f5a8
    if (cpu.flags.zf)
    {
        goto L_0x0052f5a8;
    }
    // 0052f59c  c70550d15600ffffffff   -mov dword ptr [0x56d150], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */) = 4294967295 /*0xffffffff*/;
    // 0052f5a6  eb20                   -jmp 0x52f5c8
    goto L_0x0052f5c8;
L_0x0052f5a8:
    // 0052f5a8  833d50d15600ff         +cmp dword ptr [0x56d150], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5af  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f5b4  7412                   -je 0x52f5c8
    if (cpu.flags.zf)
    {
        goto L_0x0052f5c8;
    }
    // 0052f5b6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5ba  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5be  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f5c2  ff1550d15600           -call dword ptr [0x56d150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689680) /* 0x56d150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f5c8:
    // 0052f5c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f5cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f5cb  833d54d1560000         +cmp dword ptr [0x56d154], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5d2  751f                   -jne 0x52f5f3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f5f3;
    }
    // 0052f5d4  6854d15600             -push 0x56d154
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689684 /*0x56d154*/;
    cpu.esp -= 4;
    // 0052f5d9  6870ba5600             -push 0x56ba70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683824 /*0x56ba70*/;
    cpu.esp -= 4;
    // 0052f5de  e835fdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f5e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f5e5  740c                   -je 0x52f5f3
    if (cpu.flags.zf)
    {
        goto L_0x0052f5f3;
    }
    // 0052f5e7  c70554d15600ffffffff   -mov dword ptr [0x56d154], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */) = 4294967295 /*0xffffffff*/;
    // 0052f5f1  eb20                   -jmp 0x52f613
    goto L_0x0052f613;
L_0x0052f5f3:
    // 0052f5f3  833d54d15600ff         +cmp dword ptr [0x56d154], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f5fa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f5ff  7412                   -je 0x52f613
    if (cpu.flags.zf)
    {
        goto L_0x0052f613;
    }
    // 0052f601  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f605  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f609  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f60d  ff1554d15600           -call dword ptr [0x56d154]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689684) /* 0x56d154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f613:
    // 0052f613  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f616(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f616  833d58d1560000         +cmp dword ptr [0x56d158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f61d  751f                   -jne 0x52f63e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f63e;
    }
    // 0052f61f  6858d15600             -push 0x56d158
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689688 /*0x56d158*/;
    cpu.esp -= 4;
    // 0052f624  6884ba5600             -push 0x56ba84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683844 /*0x56ba84*/;
    cpu.esp -= 4;
    // 0052f629  e8eafcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f62e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f630  740c                   -je 0x52f63e
    if (cpu.flags.zf)
    {
        goto L_0x0052f63e;
    }
    // 0052f632  c70558d15600ffffffff   -mov dword ptr [0x56d158], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */) = 4294967295 /*0xffffffff*/;
    // 0052f63c  eb20                   -jmp 0x52f65e
    goto L_0x0052f65e;
L_0x0052f63e:
    // 0052f63e  833d58d15600ff         +cmp dword ptr [0x56d158], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f645  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f64a  7412                   -je 0x52f65e
    if (cpu.flags.zf)
    {
        goto L_0x0052f65e;
    }
    // 0052f64c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f650  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f654  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f658  ff1558d15600           -call dword ptr [0x56d158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689688) /* 0x56d158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f65e:
    // 0052f65e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f661(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f661  833d5cd1560000         +cmp dword ptr [0x56d15c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f668  751f                   -jne 0x52f689
    if (!cpu.flags.zf)
    {
        goto L_0x0052f689;
    }
    // 0052f66a  685cd15600             -push 0x56d15c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689692 /*0x56d15c*/;
    cpu.esp -= 4;
    // 0052f66f  6898ba5600             -push 0x56ba98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683864 /*0x56ba98*/;
    cpu.esp -= 4;
    // 0052f674  e89ffcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f679  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f67b  740c                   -je 0x52f689
    if (cpu.flags.zf)
    {
        goto L_0x0052f689;
    }
    // 0052f67d  c7055cd15600ffffffff   -mov dword ptr [0x56d15c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */) = 4294967295 /*0xffffffff*/;
    // 0052f687  eb18                   -jmp 0x52f6a1
    goto L_0x0052f6a1;
L_0x0052f689:
    // 0052f689  833d5cd15600ff         +cmp dword ptr [0x56d15c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f690  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f695  740a                   -je 0x52f6a1
    if (cpu.flags.zf)
    {
        goto L_0x0052f6a1;
    }
    // 0052f697  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f69b  ff155cd15600           -call dword ptr [0x56d15c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689692) /* 0x56d15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f6a1:
    // 0052f6a1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_52f6a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f6a4  833d60d1560000         +cmp dword ptr [0x56d160], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f6ac  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f6ae  751f                   -jne 0x52f6cf
    if (!cpu.flags.zf)
    {
        goto L_0x0052f6cf;
    }
    // 0052f6b0  6860d15600             -push 0x56d160
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689696 /*0x56d160*/;
    cpu.esp -= 4;
    // 0052f6b5  68a4ba5600             -push 0x56baa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683876 /*0x56baa4*/;
    cpu.esp -= 4;
    // 0052f6ba  e859fcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f6bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f6c1  740c                   -je 0x52f6cf
    if (cpu.flags.zf)
    {
        goto L_0x0052f6cf;
    }
    // 0052f6c3  c70560d15600ffffffff   -mov dword ptr [0x56d160], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */) = 4294967295 /*0xffffffff*/;
    // 0052f6cd  eb20                   -jmp 0x52f6ef
    goto L_0x0052f6ef;
L_0x0052f6cf:
    // 0052f6cf  833d60d15600ff         +cmp dword ptr [0x56d160], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6d6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f6db  7412                   -je 0x52f6ef
    if (cpu.flags.zf)
    {
        goto L_0x0052f6ef;
    }
    // 0052f6dd  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f6e0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f6e3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f6e6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f6e9  ff1560d15600           -call dword ptr [0x56d160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689696) /* 0x56d160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f6ef:
    // 0052f6ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f6f0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52f6f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f6f3  833d64d1560000         +cmp dword ptr [0x56d164], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f6fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f6fb  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f6fd  751f                   -jne 0x52f71e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f71e;
    }
    // 0052f6ff  6864d15600             -push 0x56d164
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689700 /*0x56d164*/;
    cpu.esp -= 4;
    // 0052f704  68b8ba5600             -push 0x56bab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683896 /*0x56bab8*/;
    cpu.esp -= 4;
    // 0052f709  e80afcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f70e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f710  740c                   -je 0x52f71e
    if (cpu.flags.zf)
    {
        goto L_0x0052f71e;
    }
    // 0052f712  c70564d15600ffffffff   -mov dword ptr [0x56d164], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */) = 4294967295 /*0xffffffff*/;
    // 0052f71c  eb20                   -jmp 0x52f73e
    goto L_0x0052f73e;
L_0x0052f71e:
    // 0052f71e  833d64d15600ff         +cmp dword ptr [0x56d164], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f725  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f72a  7412                   -je 0x52f73e
    if (cpu.flags.zf)
    {
        goto L_0x0052f73e;
    }
    // 0052f72c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f72f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f732  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f735  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f738  ff1564d15600           -call dword ptr [0x56d164]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689700) /* 0x56d164 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f73e:
    // 0052f73e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f73f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52f742(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f742  833d68d1560000         +cmp dword ptr [0x56d168], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f749  751f                   -jne 0x52f76a
    if (!cpu.flags.zf)
    {
        goto L_0x0052f76a;
    }
    // 0052f74b  6868d15600             -push 0x56d168
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689704 /*0x56d168*/;
    cpu.esp -= 4;
    // 0052f750  68d0ba5600             -push 0x56bad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683920 /*0x56bad0*/;
    cpu.esp -= 4;
    // 0052f755  e8befbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f75a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f75c  740c                   -je 0x52f76a
    if (cpu.flags.zf)
    {
        goto L_0x0052f76a;
    }
    // 0052f75e  c70568d15600ffffffff   -mov dword ptr [0x56d168], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */) = 4294967295 /*0xffffffff*/;
    // 0052f768  eb20                   -jmp 0x52f78a
    goto L_0x0052f78a;
L_0x0052f76a:
    // 0052f76a  833d68d15600ff         +cmp dword ptr [0x56d168], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f771  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f776  7412                   -je 0x52f78a
    if (cpu.flags.zf)
    {
        goto L_0x0052f78a;
    }
    // 0052f778  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f77c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f780  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f784  ff1568d15600           -call dword ptr [0x56d168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689704) /* 0x56d168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f78a:
    // 0052f78a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f78d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f78d  833d6cd1560000         +cmp dword ptr [0x56d16c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f794  751f                   -jne 0x52f7b5
    if (!cpu.flags.zf)
    {
        goto L_0x0052f7b5;
    }
    // 0052f796  686cd15600             -push 0x56d16c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689708 /*0x56d16c*/;
    cpu.esp -= 4;
    // 0052f79b  68e4ba5600             -push 0x56bae4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683940 /*0x56bae4*/;
    cpu.esp -= 4;
    // 0052f7a0  e873fbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f7a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f7a7  740c                   -je 0x52f7b5
    if (cpu.flags.zf)
    {
        goto L_0x0052f7b5;
    }
    // 0052f7a9  c7056cd15600ffffffff   -mov dword ptr [0x56d16c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */) = 4294967295 /*0xffffffff*/;
    // 0052f7b3  eb20                   -jmp 0x52f7d5
    goto L_0x0052f7d5;
L_0x0052f7b5:
    // 0052f7b5  833d6cd15600ff         +cmp dword ptr [0x56d16c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f7bc  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f7c1  7412                   -je 0x52f7d5
    if (cpu.flags.zf)
    {
        goto L_0x0052f7d5;
    }
    // 0052f7c3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7c7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7cb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f7cf  ff156cd15600           -call dword ptr [0x56d16c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689708) /* 0x56d16c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f7d5:
    // 0052f7d5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f7d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f7d8  833d70d1560000         +cmp dword ptr [0x56d170], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f7df  751f                   -jne 0x52f800
    if (!cpu.flags.zf)
    {
        goto L_0x0052f800;
    }
    // 0052f7e1  6870d15600             -push 0x56d170
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689712 /*0x56d170*/;
    cpu.esp -= 4;
    // 0052f7e6  68f8ba5600             -push 0x56baf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683960 /*0x56baf8*/;
    cpu.esp -= 4;
    // 0052f7eb  e828fbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f7f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f7f2  740c                   -je 0x52f800
    if (cpu.flags.zf)
    {
        goto L_0x0052f800;
    }
    // 0052f7f4  c70570d15600ffffffff   -mov dword ptr [0x56d170], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */) = 4294967295 /*0xffffffff*/;
    // 0052f7fe  eb20                   -jmp 0x52f820
    goto L_0x0052f820;
L_0x0052f800:
    // 0052f800  833d70d15600ff         +cmp dword ptr [0x56d170], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f807  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f80c  7412                   -je 0x52f820
    if (cpu.flags.zf)
    {
        goto L_0x0052f820;
    }
    // 0052f80e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f812  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f816  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f81a  ff1570d15600           -call dword ptr [0x56d170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689712) /* 0x56d170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f820:
    // 0052f820  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52f823(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f823  833d74d1560000         +cmp dword ptr [0x56d174], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f82a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f82b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f82d  751f                   -jne 0x52f84e
    if (!cpu.flags.zf)
    {
        goto L_0x0052f84e;
    }
    // 0052f82f  6874d15600             -push 0x56d174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689716 /*0x56d174*/;
    cpu.esp -= 4;
    // 0052f834  680cbb5600             -push 0x56bb0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683980 /*0x56bb0c*/;
    cpu.esp -= 4;
    // 0052f839  e8dafaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f83e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f840  740c                   -je 0x52f84e
    if (cpu.flags.zf)
    {
        goto L_0x0052f84e;
    }
    // 0052f842  c70574d15600ffffffff   -mov dword ptr [0x56d174], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */) = 4294967295 /*0xffffffff*/;
    // 0052f84c  eb26                   -jmp 0x52f874
    goto L_0x0052f874;
L_0x0052f84e:
    // 0052f84e  833d74d15600ff         +cmp dword ptr [0x56d174], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f855  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f85a  7418                   -je 0x52f874
    if (cpu.flags.zf)
    {
        goto L_0x0052f874;
    }
    // 0052f85c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f85f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f862  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f865  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f868  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f86b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f86e  ff1574d15600           -call dword ptr [0x56d174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689716) /* 0x56d174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f874:
    // 0052f874  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f875  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f878(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f878  833d78d1560000         +cmp dword ptr [0x56d178], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f87f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f880  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f882  751f                   -jne 0x52f8a3
    if (!cpu.flags.zf)
    {
        goto L_0x0052f8a3;
    }
    // 0052f884  6878d15600             -push 0x56d178
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689720 /*0x56d178*/;
    cpu.esp -= 4;
    // 0052f889  6824bb5600             -push 0x56bb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684004 /*0x56bb24*/;
    cpu.esp -= 4;
    // 0052f88e  e885faffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f893  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f895  740c                   -je 0x52f8a3
    if (cpu.flags.zf)
    {
        goto L_0x0052f8a3;
    }
    // 0052f897  c70578d15600ffffffff   -mov dword ptr [0x56d178], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */) = 4294967295 /*0xffffffff*/;
    // 0052f8a1  eb26                   -jmp 0x52f8c9
    goto L_0x0052f8c9;
L_0x0052f8a3:
    // 0052f8a3  833d78d15600ff         +cmp dword ptr [0x56d178], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8aa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f8af  7418                   -je 0x52f8c9
    if (cpu.flags.zf)
    {
        goto L_0x0052f8c9;
    }
    // 0052f8b1  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f8b4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f8b7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f8ba  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f8bd  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f8c0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f8c3  ff1578d15600           -call dword ptr [0x56d178]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689720) /* 0x56d178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f8c9:
    // 0052f8c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f8ca  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f8cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f8cd  833d7cd1560000         +cmp dword ptr [0x56d17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f8d5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f8d7  751f                   -jne 0x52f8f8
    if (!cpu.flags.zf)
    {
        goto L_0x0052f8f8;
    }
    // 0052f8d9  687cd15600             -push 0x56d17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689724 /*0x56d17c*/;
    cpu.esp -= 4;
    // 0052f8de  683cbb5600             -push 0x56bb3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684028 /*0x56bb3c*/;
    cpu.esp -= 4;
    // 0052f8e3  e830faffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f8e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f8ea  740c                   -je 0x52f8f8
    if (cpu.flags.zf)
    {
        goto L_0x0052f8f8;
    }
    // 0052f8ec  c7057cd15600ffffffff   -mov dword ptr [0x56d17c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */) = 4294967295 /*0xffffffff*/;
    // 0052f8f6  eb26                   -jmp 0x52f91e
    goto L_0x0052f91e;
L_0x0052f8f8:
    // 0052f8f8  833d7cd15600ff         +cmp dword ptr [0x56d17c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f8ff  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f904  7418                   -je 0x52f91e
    if (cpu.flags.zf)
    {
        goto L_0x0052f91e;
    }
    // 0052f906  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052f909  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f90c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f90f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f912  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f915  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f918  ff157cd15600           -call dword ptr [0x56d17c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689724) /* 0x56d17c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f91e:
    // 0052f91e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f91f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52f922(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f922  833d80d1560000         +cmp dword ptr [0x56d180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f929  751f                   -jne 0x52f94a
    if (!cpu.flags.zf)
    {
        goto L_0x0052f94a;
    }
    // 0052f92b  6880d15600             -push 0x56d180
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689728 /*0x56d180*/;
    cpu.esp -= 4;
    // 0052f930  6854bb5600             -push 0x56bb54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684052 /*0x56bb54*/;
    cpu.esp -= 4;
    // 0052f935  e8def9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f93a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f93c  740c                   -je 0x52f94a
    if (cpu.flags.zf)
    {
        goto L_0x0052f94a;
    }
    // 0052f93e  c70580d15600ffffffff   -mov dword ptr [0x56d180], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */) = 4294967295 /*0xffffffff*/;
    // 0052f948  eb1c                   -jmp 0x52f966
    goto L_0x0052f966;
L_0x0052f94a:
    // 0052f94a  833d80d15600ff         +cmp dword ptr [0x56d180], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f951  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f956  740e                   -je 0x52f966
    if (cpu.flags.zf)
    {
        goto L_0x0052f966;
    }
    // 0052f958  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f95c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f960  ff1580d15600           -call dword ptr [0x56d180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689728) /* 0x56d180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f966:
    // 0052f966  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_52f969(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f969  833d84d1560000         +cmp dword ptr [0x56d184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f970  751f                   -jne 0x52f991
    if (!cpu.flags.zf)
    {
        goto L_0x0052f991;
    }
    // 0052f972  6884d15600             -push 0x56d184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689732 /*0x56d184*/;
    cpu.esp -= 4;
    // 0052f977  6868bb5600             -push 0x56bb68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684072 /*0x56bb68*/;
    cpu.esp -= 4;
    // 0052f97c  e897f9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f981  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f983  740c                   -je 0x52f991
    if (cpu.flags.zf)
    {
        goto L_0x0052f991;
    }
    // 0052f985  c70584d15600ffffffff   -mov dword ptr [0x56d184], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */) = 4294967295 /*0xffffffff*/;
    // 0052f98f  eb18                   -jmp 0x52f9a9
    goto L_0x0052f9a9;
L_0x0052f991:
    // 0052f991  833d84d15600ff         +cmp dword ptr [0x56d184], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f998  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f99d  740a                   -je 0x52f9a9
    if (cpu.flags.zf)
    {
        goto L_0x0052f9a9;
    }
    // 0052f99f  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0052f9a3  ff1584d15600           -call dword ptr [0x56d184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689732) /* 0x56d184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f9a9:
    // 0052f9a9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_52f9ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f9ac  833d88d1560000         +cmp dword ptr [0x56d188], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f9b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052f9b4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052f9b6  751f                   -jne 0x52f9d7
    if (!cpu.flags.zf)
    {
        goto L_0x0052f9d7;
    }
    // 0052f9b8  6888d15600             -push 0x56d188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689736 /*0x56d188*/;
    cpu.esp -= 4;
    // 0052f9bd  687cbb5600             -push 0x56bb7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684092 /*0x56bb7c*/;
    cpu.esp -= 4;
    // 0052f9c2  e851f9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052f9c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052f9c9  740c                   -je 0x52f9d7
    if (cpu.flags.zf)
    {
        goto L_0x0052f9d7;
    }
    // 0052f9cb  c70588d15600ffffffff   -mov dword ptr [0x56d188], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */) = 4294967295 /*0xffffffff*/;
    // 0052f9d5  eb23                   -jmp 0x52f9fa
    goto L_0x0052f9fa;
L_0x0052f9d7:
    // 0052f9d7  833d88d15600ff         +cmp dword ptr [0x56d188], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052f9de  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052f9e3  7415                   -je 0x52f9fa
    if (cpu.flags.zf)
    {
        goto L_0x0052f9fa;
    }
    // 0052f9e5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052f9e8  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052f9eb  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052f9ee  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052f9f1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052f9f4  ff1588d15600           -call dword ptr [0x56d188]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689736) /* 0x56d188 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052f9fa:
    // 0052f9fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052f9fb  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52f9fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052f9fe  833d8cd1560000         +cmp dword ptr [0x56d18c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fa06  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fa08  751f                   -jne 0x52fa29
    if (!cpu.flags.zf)
    {
        goto L_0x0052fa29;
    }
    // 0052fa0a  688cd15600             -push 0x56d18c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689740 /*0x56d18c*/;
    cpu.esp -= 4;
    // 0052fa0f  688cbb5600             -push 0x56bb8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684108 /*0x56bb8c*/;
    cpu.esp -= 4;
    // 0052fa14  e8fff8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fa19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fa1b  740c                   -je 0x52fa29
    if (cpu.flags.zf)
    {
        goto L_0x0052fa29;
    }
    // 0052fa1d  c7058cd15600ffffffff   -mov dword ptr [0x56d18c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */) = 4294967295 /*0xffffffff*/;
    // 0052fa27  eb20                   -jmp 0x52fa49
    goto L_0x0052fa49;
L_0x0052fa29:
    // 0052fa29  833d8cd15600ff         +cmp dword ptr [0x56d18c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa30  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fa35  7412                   -je 0x52fa49
    if (cpu.flags.zf)
    {
        goto L_0x0052fa49;
    }
    // 0052fa37  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fa3a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fa3d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa40  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fa43  ff158cd15600           -call dword ptr [0x56d18c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689740) /* 0x56d18c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fa49:
    // 0052fa49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fa4a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fa4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fa4d  833d90d1560000         +cmp dword ptr [0x56d190], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa54  751f                   -jne 0x52fa75
    if (!cpu.flags.zf)
    {
        goto L_0x0052fa75;
    }
    // 0052fa56  6890d15600             -push 0x56d190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689744 /*0x56d190*/;
    cpu.esp -= 4;
    // 0052fa5b  68a4bb5600             -push 0x56bba4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684132 /*0x56bba4*/;
    cpu.esp -= 4;
    // 0052fa60  e8b3f8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fa65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fa67  740c                   -je 0x52fa75
    if (cpu.flags.zf)
    {
        goto L_0x0052fa75;
    }
    // 0052fa69  c70590d15600ffffffff   -mov dword ptr [0x56d190], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */) = 4294967295 /*0xffffffff*/;
    // 0052fa73  eb20                   -jmp 0x52fa95
    goto L_0x0052fa95;
L_0x0052fa75:
    // 0052fa75  833d90d15600ff         +cmp dword ptr [0x56d190], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa7c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fa81  7412                   -je 0x52fa95
    if (cpu.flags.zf)
    {
        goto L_0x0052fa95;
    }
    // 0052fa83  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa87  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa8b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fa8f  ff1590d15600           -call dword ptr [0x56d190]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689744) /* 0x56d190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fa95:
    // 0052fa95  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fa98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fa98  833d94d1560000         +cmp dword ptr [0x56d194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fa9f  751f                   -jne 0x52fac0
    if (!cpu.flags.zf)
    {
        goto L_0x0052fac0;
    }
    // 0052faa1  6894d15600             -push 0x56d194
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689748 /*0x56d194*/;
    cpu.esp -= 4;
    // 0052faa6  68b0bb5600             -push 0x56bbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684144 /*0x56bbb0*/;
    cpu.esp -= 4;
    // 0052faab  e868f8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fab0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fab2  740c                   -je 0x52fac0
    if (cpu.flags.zf)
    {
        goto L_0x0052fac0;
    }
    // 0052fab4  c70594d15600ffffffff   -mov dword ptr [0x56d194], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */) = 4294967295 /*0xffffffff*/;
    // 0052fabe  eb20                   -jmp 0x52fae0
    goto L_0x0052fae0;
L_0x0052fac0:
    // 0052fac0  833d94d15600ff         +cmp dword ptr [0x56d194], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fac7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052facc  7412                   -je 0x52fae0
    if (cpu.flags.zf)
    {
        goto L_0x0052fae0;
    }
    // 0052face  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fad2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fad6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fada  ff1594d15600           -call dword ptr [0x56d194]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689748) /* 0x56d194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fae0:
    // 0052fae0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fae3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fae3  833d98d1560000         +cmp dword ptr [0x56d198], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052faea  751f                   -jne 0x52fb0b
    if (!cpu.flags.zf)
    {
        goto L_0x0052fb0b;
    }
    // 0052faec  6898d15600             -push 0x56d198
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689752 /*0x56d198*/;
    cpu.esp -= 4;
    // 0052faf1  68bcbb5600             -push 0x56bbbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684156 /*0x56bbbc*/;
    cpu.esp -= 4;
    // 0052faf6  e81df8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fafb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fafd  740c                   -je 0x52fb0b
    if (cpu.flags.zf)
    {
        goto L_0x0052fb0b;
    }
    // 0052faff  c70598d15600ffffffff   -mov dword ptr [0x56d198], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */) = 4294967295 /*0xffffffff*/;
    // 0052fb09  eb20                   -jmp 0x52fb2b
    goto L_0x0052fb2b;
L_0x0052fb0b:
    // 0052fb0b  833d98d15600ff         +cmp dword ptr [0x56d198], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb12  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fb17  7412                   -je 0x52fb2b
    if (cpu.flags.zf)
    {
        goto L_0x0052fb2b;
    }
    // 0052fb19  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb1d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb21  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb25  ff1598d15600           -call dword ptr [0x56d198]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689752) /* 0x56d198 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fb2b:
    // 0052fb2b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fb2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fb2e  833d9cd1560000         +cmp dword ptr [0x56d19c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb35  751f                   -jne 0x52fb56
    if (!cpu.flags.zf)
    {
        goto L_0x0052fb56;
    }
    // 0052fb37  689cd15600             -push 0x56d19c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689756 /*0x56d19c*/;
    cpu.esp -= 4;
    // 0052fb3c  68c8bb5600             -push 0x56bbc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684168 /*0x56bbc8*/;
    cpu.esp -= 4;
    // 0052fb41  e8d2f7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fb46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fb48  740c                   -je 0x52fb56
    if (cpu.flags.zf)
    {
        goto L_0x0052fb56;
    }
    // 0052fb4a  c7059cd15600ffffffff   -mov dword ptr [0x56d19c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */) = 4294967295 /*0xffffffff*/;
    // 0052fb54  eb20                   -jmp 0x52fb76
    goto L_0x0052fb76;
L_0x0052fb56:
    // 0052fb56  833d9cd15600ff         +cmp dword ptr [0x56d19c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb5d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fb62  7412                   -je 0x52fb76
    if (cpu.flags.zf)
    {
        goto L_0x0052fb76;
    }
    // 0052fb64  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb68  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb6c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fb70  ff159cd15600           -call dword ptr [0x56d19c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689756) /* 0x56d19c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fb76:
    // 0052fb76  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52fb79(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fb79  833da0d1560000         +cmp dword ptr [0x56d1a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fb80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fb81  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fb83  751f                   -jne 0x52fba4
    if (!cpu.flags.zf)
    {
        goto L_0x0052fba4;
    }
    // 0052fb85  68a0d15600             -push 0x56d1a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689760 /*0x56d1a0*/;
    cpu.esp -= 4;
    // 0052fb8a  68d4bb5600             -push 0x56bbd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684180 /*0x56bbd4*/;
    cpu.esp -= 4;
    // 0052fb8f  e884f7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fb94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fb96  740c                   -je 0x52fba4
    if (cpu.flags.zf)
    {
        goto L_0x0052fba4;
    }
    // 0052fb98  c705a0d15600ffffffff   -mov dword ptr [0x56d1a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */) = 4294967295 /*0xffffffff*/;
    // 0052fba2  eb29                   -jmp 0x52fbcd
    goto L_0x0052fbcd;
L_0x0052fba4:
    // 0052fba4  833da0d15600ff         +cmp dword ptr [0x56d1a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fbab  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fbb0  741b                   -je 0x52fbcd
    if (cpu.flags.zf)
    {
        goto L_0x0052fbcd;
    }
    // 0052fbb2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fbb5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fbb8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fbbb  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fbbe  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fbc1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fbc4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fbc7  ff15a0d15600           -call dword ptr [0x56d1a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689760) /* 0x56d1a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fbcd:
    // 0052fbcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fbce  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fbd1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fbd1  833da4d1560000         +cmp dword ptr [0x56d1a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fbd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fbd9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fbdb  751f                   -jne 0x52fbfc
    if (!cpu.flags.zf)
    {
        goto L_0x0052fbfc;
    }
    // 0052fbdd  68a4d15600             -push 0x56d1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689764 /*0x56d1a4*/;
    cpu.esp -= 4;
    // 0052fbe2  68e0bb5600             -push 0x56bbe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684192 /*0x56bbe0*/;
    cpu.esp -= 4;
    // 0052fbe7  e82cf7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fbec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fbee  740c                   -je 0x52fbfc
    if (cpu.flags.zf)
    {
        goto L_0x0052fbfc;
    }
    // 0052fbf0  c705a4d15600ffffffff   -mov dword ptr [0x56d1a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */) = 4294967295 /*0xffffffff*/;
    // 0052fbfa  eb29                   -jmp 0x52fc25
    goto L_0x0052fc25;
L_0x0052fbfc:
    // 0052fbfc  833da4d15600ff         +cmp dword ptr [0x56d1a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc03  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fc08  741b                   -je 0x52fc25
    if (cpu.flags.zf)
    {
        goto L_0x0052fc25;
    }
    // 0052fc0a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fc0d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fc10  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fc13  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fc16  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fc19  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fc1c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fc1f  ff15a4d15600           -call dword ptr [0x56d1a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689764) /* 0x56d1a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fc25:
    // 0052fc25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fc26  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fc29(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fc29  833da8d1560000         +cmp dword ptr [0x56d1a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fc31  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fc33  751f                   -jne 0x52fc54
    if (!cpu.flags.zf)
    {
        goto L_0x0052fc54;
    }
    // 0052fc35  68a8d15600             -push 0x56d1a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689768 /*0x56d1a8*/;
    cpu.esp -= 4;
    // 0052fc3a  68f0bb5600             -push 0x56bbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684208 /*0x56bbf0*/;
    cpu.esp -= 4;
    // 0052fc3f  e8d4f6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fc44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fc46  740c                   -je 0x52fc54
    if (cpu.flags.zf)
    {
        goto L_0x0052fc54;
    }
    // 0052fc48  c705a8d15600ffffffff   -mov dword ptr [0x56d1a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */) = 4294967295 /*0xffffffff*/;
    // 0052fc52  eb29                   -jmp 0x52fc7d
    goto L_0x0052fc7d;
L_0x0052fc54:
    // 0052fc54  833da8d15600ff         +cmp dword ptr [0x56d1a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc5b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fc60  741b                   -je 0x52fc7d
    if (cpu.flags.zf)
    {
        goto L_0x0052fc7d;
    }
    // 0052fc62  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fc65  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fc68  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fc6b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fc6e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fc71  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fc74  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fc77  ff15a8d15600           -call dword ptr [0x56d1a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689768) /* 0x56d1a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fc7d:
    // 0052fc7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fc7e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fc81(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fc81  833dacd1560000         +cmp dword ptr [0x56d1ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fc88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fc89  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fc8b  751f                   -jne 0x52fcac
    if (!cpu.flags.zf)
    {
        goto L_0x0052fcac;
    }
    // 0052fc8d  68acd15600             -push 0x56d1ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689772 /*0x56d1ac*/;
    cpu.esp -= 4;
    // 0052fc92  6800bc5600             -push 0x56bc00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684224 /*0x56bc00*/;
    cpu.esp -= 4;
    // 0052fc97  e87cf6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fc9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fc9e  740c                   -je 0x52fcac
    if (cpu.flags.zf)
    {
        goto L_0x0052fcac;
    }
    // 0052fca0  c705acd15600ffffffff   -mov dword ptr [0x56d1ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */) = 4294967295 /*0xffffffff*/;
    // 0052fcaa  eb29                   -jmp 0x52fcd5
    goto L_0x0052fcd5;
L_0x0052fcac:
    // 0052fcac  833dacd15600ff         +cmp dword ptr [0x56d1ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fcb3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fcb8  741b                   -je 0x52fcd5
    if (cpu.flags.zf)
    {
        goto L_0x0052fcd5;
    }
    // 0052fcba  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fcbd  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fcc0  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fcc3  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fcc6  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fcc9  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fccc  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fccf  ff15acd15600           -call dword ptr [0x56d1ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689772) /* 0x56d1ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fcd5:
    // 0052fcd5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fcd6  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fcd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fcd9  833db0d1560000         +cmp dword ptr [0x56d1b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fce0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fce1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fce3  751f                   -jne 0x52fd04
    if (!cpu.flags.zf)
    {
        goto L_0x0052fd04;
    }
    // 0052fce5  68b0d15600             -push 0x56d1b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689776 /*0x56d1b0*/;
    cpu.esp -= 4;
    // 0052fcea  6814bc5600             -push 0x56bc14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684244 /*0x56bc14*/;
    cpu.esp -= 4;
    // 0052fcef  e824f6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fcf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fcf6  740c                   -je 0x52fd04
    if (cpu.flags.zf)
    {
        goto L_0x0052fd04;
    }
    // 0052fcf8  c705b0d15600ffffffff   -mov dword ptr [0x56d1b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */) = 4294967295 /*0xffffffff*/;
    // 0052fd02  eb29                   -jmp 0x52fd2d
    goto L_0x0052fd2d;
L_0x0052fd04:
    // 0052fd04  833db0d15600ff         +cmp dword ptr [0x56d1b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd0b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fd10  741b                   -je 0x52fd2d
    if (cpu.flags.zf)
    {
        goto L_0x0052fd2d;
    }
    // 0052fd12  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fd15  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fd18  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fd1b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fd1e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fd21  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fd24  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fd27  ff15b0d15600           -call dword ptr [0x56d1b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689776) /* 0x56d1b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fd2d:
    // 0052fd2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fd2e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fd31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fd31  833db4d1560000         +cmp dword ptr [0x56d1b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fd39  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fd3b  751f                   -jne 0x52fd5c
    if (!cpu.flags.zf)
    {
        goto L_0x0052fd5c;
    }
    // 0052fd3d  68b4d15600             -push 0x56d1b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689780 /*0x56d1b4*/;
    cpu.esp -= 4;
    // 0052fd42  6828bc5600             -push 0x56bc28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684264 /*0x56bc28*/;
    cpu.esp -= 4;
    // 0052fd47  e8ccf5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fd4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fd4e  740c                   -je 0x52fd5c
    if (cpu.flags.zf)
    {
        goto L_0x0052fd5c;
    }
    // 0052fd50  c705b4d15600ffffffff   -mov dword ptr [0x56d1b4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */) = 4294967295 /*0xffffffff*/;
    // 0052fd5a  eb29                   -jmp 0x52fd85
    goto L_0x0052fd85;
L_0x0052fd5c:
    // 0052fd5c  833db4d15600ff         +cmp dword ptr [0x56d1b4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd63  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fd68  741b                   -je 0x52fd85
    if (cpu.flags.zf)
    {
        goto L_0x0052fd85;
    }
    // 0052fd6a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0052fd6d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052fd70  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052fd73  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fd76  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fd79  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fd7c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fd7f  ff15b4d15600           -call dword ptr [0x56d1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689780) /* 0x56d1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fd85:
    // 0052fd85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fd86  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_52fd89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fd89  833db8d1560000         +cmp dword ptr [0x56d1b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fd90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fd91  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fd93  751f                   -jne 0x52fdb4
    if (!cpu.flags.zf)
    {
        goto L_0x0052fdb4;
    }
    // 0052fd95  68b8d15600             -push 0x56d1b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689784 /*0x56d1b8*/;
    cpu.esp -= 4;
    // 0052fd9a  683cbc5600             -push 0x56bc3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684284 /*0x56bc3c*/;
    cpu.esp -= 4;
    // 0052fd9f  e874f5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fda4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fda6  740c                   -je 0x52fdb4
    if (cpu.flags.zf)
    {
        goto L_0x0052fdb4;
    }
    // 0052fda8  c705b8d15600ffffffff   -mov dword ptr [0x56d1b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */) = 4294967295 /*0xffffffff*/;
    // 0052fdb2  eb20                   -jmp 0x52fdd4
    goto L_0x0052fdd4;
L_0x0052fdb4:
    // 0052fdb4  833db8d15600ff         +cmp dword ptr [0x56d1b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fdbb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fdc0  7412                   -je 0x52fdd4
    if (cpu.flags.zf)
    {
        goto L_0x0052fdd4;
    }
    // 0052fdc2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fdc5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fdc8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fdcb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fdce  ff15b8d15600           -call dword ptr [0x56d1b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689784) /* 0x56d1b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fdd4:
    // 0052fdd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fdd5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fdd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fdd8  833dbcd1560000         +cmp dword ptr [0x56d1bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fddf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fde0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fde2  751f                   -jne 0x52fe03
    if (!cpu.flags.zf)
    {
        goto L_0x0052fe03;
    }
    // 0052fde4  68bcd15600             -push 0x56d1bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689788 /*0x56d1bc*/;
    cpu.esp -= 4;
    // 0052fde9  6850bc5600             -push 0x56bc50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684304 /*0x56bc50*/;
    cpu.esp -= 4;
    // 0052fdee  e825f5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fdf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fdf5  740c                   -je 0x52fe03
    if (cpu.flags.zf)
    {
        goto L_0x0052fe03;
    }
    // 0052fdf7  c705bcd15600ffffffff   -mov dword ptr [0x56d1bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */) = 4294967295 /*0xffffffff*/;
    // 0052fe01  eb20                   -jmp 0x52fe23
    goto L_0x0052fe23;
L_0x0052fe03:
    // 0052fe03  833dbcd15600ff         +cmp dword ptr [0x56d1bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe0a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fe0f  7412                   -je 0x52fe23
    if (cpu.flags.zf)
    {
        goto L_0x0052fe23;
    }
    // 0052fe11  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fe14  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fe17  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fe1a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fe1d  ff15bcd15600           -call dword ptr [0x56d1bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689788) /* 0x56d1bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fe23:
    // 0052fe23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fe24  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fe27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fe27  833dc0d1560000         +cmp dword ptr [0x56d1c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fe2f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fe31  751f                   -jne 0x52fe52
    if (!cpu.flags.zf)
    {
        goto L_0x0052fe52;
    }
    // 0052fe33  68c0d15600             -push 0x56d1c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689792 /*0x56d1c0*/;
    cpu.esp -= 4;
    // 0052fe38  6864bc5600             -push 0x56bc64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684324 /*0x56bc64*/;
    cpu.esp -= 4;
    // 0052fe3d  e8d6f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fe42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fe44  740c                   -je 0x52fe52
    if (cpu.flags.zf)
    {
        goto L_0x0052fe52;
    }
    // 0052fe46  c705c0d15600ffffffff   -mov dword ptr [0x56d1c0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */) = 4294967295 /*0xffffffff*/;
    // 0052fe50  eb20                   -jmp 0x52fe72
    goto L_0x0052fe72;
L_0x0052fe52:
    // 0052fe52  833dc0d15600ff         +cmp dword ptr [0x56d1c0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe59  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fe5e  7412                   -je 0x52fe72
    if (cpu.flags.zf)
    {
        goto L_0x0052fe72;
    }
    // 0052fe60  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052fe63  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052fe66  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052fe69  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052fe6c  ff15c0d15600           -call dword ptr [0x56d1c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689792) /* 0x56d1c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fe72:
    // 0052fe72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fe73  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_52fe76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fe76  833dc4d1560000         +cmp dword ptr [0x56d1c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fe7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fe7e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fe80  751f                   -jne 0x52fea1
    if (!cpu.flags.zf)
    {
        goto L_0x0052fea1;
    }
    // 0052fe82  68c4d15600             -push 0x56d1c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689796 /*0x56d1c4*/;
    cpu.esp -= 4;
    // 0052fe87  6878bc5600             -push 0x56bc78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684344 /*0x56bc78*/;
    cpu.esp -= 4;
    // 0052fe8c  e887f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fe91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fe93  740c                   -je 0x52fea1
    if (cpu.flags.zf)
    {
        goto L_0x0052fea1;
    }
    // 0052fe95  c705c4d15600ffffffff   -mov dword ptr [0x56d1c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */) = 4294967295 /*0xffffffff*/;
    // 0052fe9f  eb23                   -jmp 0x52fec4
    goto L_0x0052fec4;
L_0x0052fea1:
    // 0052fea1  833dc4d15600ff         +cmp dword ptr [0x56d1c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fea8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fead  7415                   -je 0x52fec4
    if (cpu.flags.zf)
    {
        goto L_0x0052fec4;
    }
    // 0052feaf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052feb2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052feb5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052feb8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052febb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052febe  ff15c4d15600           -call dword ptr [0x56d1c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689796) /* 0x56d1c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052fec4:
    // 0052fec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052fec5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_52fec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052fec8  833dc8d1560000         +cmp dword ptr [0x56d1c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fecf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052fed0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052fed2  751f                   -jne 0x52fef3
    if (!cpu.flags.zf)
    {
        goto L_0x0052fef3;
    }
    // 0052fed4  68c8d15600             -push 0x56d1c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689800 /*0x56d1c8*/;
    cpu.esp -= 4;
    // 0052fed9  688cbc5600             -push 0x56bc8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684364 /*0x56bc8c*/;
    cpu.esp -= 4;
    // 0052fede  e835f4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052fee3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052fee5  740c                   -je 0x52fef3
    if (cpu.flags.zf)
    {
        goto L_0x0052fef3;
    }
    // 0052fee7  c705c8d15600ffffffff   -mov dword ptr [0x56d1c8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */) = 4294967295 /*0xffffffff*/;
    // 0052fef1  eb26                   -jmp 0x52ff19
    goto L_0x0052ff19;
L_0x0052fef3:
    // 0052fef3  833dc8d15600ff         +cmp dword ptr [0x56d1c8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fefa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052feff  7418                   -je 0x52ff19
    if (cpu.flags.zf)
    {
        goto L_0x0052ff19;
    }
    // 0052ff01  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ff04  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ff07  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ff0a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ff0d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ff10  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ff13  ff15c8d15600           -call dword ptr [0x56d1c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689800) /* 0x56d1c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ff19:
    // 0052ff19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ff1a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ff1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ff1d  833dccd1560000         +cmp dword ptr [0x56d1cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ff25  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ff27  751f                   -jne 0x52ff48
    if (!cpu.flags.zf)
    {
        goto L_0x0052ff48;
    }
    // 0052ff29  68ccd15600             -push 0x56d1cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689804 /*0x56d1cc*/;
    cpu.esp -= 4;
    // 0052ff2e  68a0bc5600             -push 0x56bca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684384 /*0x56bca0*/;
    cpu.esp -= 4;
    // 0052ff33  e8e0f3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ff38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ff3a  740c                   -je 0x52ff48
    if (cpu.flags.zf)
    {
        goto L_0x0052ff48;
    }
    // 0052ff3c  c705ccd15600ffffffff   -mov dword ptr [0x56d1cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */) = 4294967295 /*0xffffffff*/;
    // 0052ff46  eb26                   -jmp 0x52ff6e
    goto L_0x0052ff6e;
L_0x0052ff48:
    // 0052ff48  833dccd15600ff         +cmp dword ptr [0x56d1cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff4f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052ff54  7418                   -je 0x52ff6e
    if (cpu.flags.zf)
    {
        goto L_0x0052ff6e;
    }
    // 0052ff56  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ff59  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ff5c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ff5f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ff62  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ff65  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ff68  ff15ccd15600           -call dword ptr [0x56d1cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689804) /* 0x56d1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ff6e:
    // 0052ff6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ff6f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ff72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ff72  833dd0d1560000         +cmp dword ptr [0x56d1d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ff79  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ff7a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ff7c  751f                   -jne 0x52ff9d
    if (!cpu.flags.zf)
    {
        goto L_0x0052ff9d;
    }
    // 0052ff7e  68d0d15600             -push 0x56d1d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689808 /*0x56d1d0*/;
    cpu.esp -= 4;
    // 0052ff83  68b4bc5600             -push 0x56bcb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684404 /*0x56bcb4*/;
    cpu.esp -= 4;
    // 0052ff88  e88bf3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ff8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ff8f  740c                   -je 0x52ff9d
    if (cpu.flags.zf)
    {
        goto L_0x0052ff9d;
    }
    // 0052ff91  c705d0d15600ffffffff   -mov dword ptr [0x56d1d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */) = 4294967295 /*0xffffffff*/;
    // 0052ff9b  eb26                   -jmp 0x52ffc3
    goto L_0x0052ffc3;
L_0x0052ff9d:
    // 0052ff9d  833dd0d15600ff         +cmp dword ptr [0x56d1d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ffa4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052ffa9  7418                   -je 0x52ffc3
    if (cpu.flags.zf)
    {
        goto L_0x0052ffc3;
    }
    // 0052ffab  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0052ffae  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0052ffb1  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0052ffb4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0052ffb7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0052ffba  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0052ffbd  ff15d0d15600           -call dword ptr [0x56d1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689808) /* 0x56d1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052ffc3:
    // 0052ffc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ffc4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_52ffc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ffc7  833dd4d1560000         +cmp dword ptr [0x56d1d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ffce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ffcf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052ffd1  751f                   -jne 0x52fff2
    if (!cpu.flags.zf)
    {
        goto L_0x0052fff2;
    }
    // 0052ffd3  68d4d15600             -push 0x56d1d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689812 /*0x56d1d4*/;
    cpu.esp -= 4;
    // 0052ffd8  68c8bc5600             -push 0x56bcc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684424 /*0x56bcc8*/;
    cpu.esp -= 4;
    // 0052ffdd  e836f3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0052ffe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ffe4  740c                   -je 0x52fff2
    if (cpu.flags.zf)
    {
        goto L_0x0052fff2;
    }
    // 0052ffe6  c705d4d15600ffffffff   -mov dword ptr [0x56d1d4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */) = 4294967295 /*0xffffffff*/;
    // 0052fff0  eb23                   -jmp 0x530015
    goto L_0x00530015;
L_0x0052fff2:
    // 0052fff2  833dd4d15600ff         +cmp dword ptr [0x56d1d4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052fff9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0052fffe  7415                   -je 0x530015
    if (cpu.flags.zf)
    {
        goto L_0x00530015;
    }
    // 00530000  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530003  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530006  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530009  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053000c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053000f  ff15d4d15600           -call dword ptr [0x56d1d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689812) /* 0x56d1d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530015:
    // 00530015  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530016  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530019(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530019  833dd8d1560000         +cmp dword ptr [0x56d1d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530020  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530021  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530023  751f                   -jne 0x530044
    if (!cpu.flags.zf)
    {
        goto L_0x00530044;
    }
    // 00530025  68d8d15600             -push 0x56d1d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689816 /*0x56d1d8*/;
    cpu.esp -= 4;
    // 0053002a  68dcbc5600             -push 0x56bcdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684444 /*0x56bcdc*/;
    cpu.esp -= 4;
    // 0053002f  e8e4f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530036  740c                   -je 0x530044
    if (cpu.flags.zf)
    {
        goto L_0x00530044;
    }
    // 00530038  c705d8d15600ffffffff   -mov dword ptr [0x56d1d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */) = 4294967295 /*0xffffffff*/;
    // 00530042  eb23                   -jmp 0x530067
    goto L_0x00530067;
L_0x00530044:
    // 00530044  833dd8d15600ff         +cmp dword ptr [0x56d1d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053004b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530050  7415                   -je 0x530067
    if (cpu.flags.zf)
    {
        goto L_0x00530067;
    }
    // 00530052  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530055  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530058  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053005b  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053005e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530061  ff15d8d15600           -call dword ptr [0x56d1d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689816) /* 0x56d1d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530067:
    // 00530067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530068  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_53006b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053006b  833ddcd1560000         +cmp dword ptr [0x56d1dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530072  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530073  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530075  751f                   -jne 0x530096
    if (!cpu.flags.zf)
    {
        goto L_0x00530096;
    }
    // 00530077  68dcd15600             -push 0x56d1dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689820 /*0x56d1dc*/;
    cpu.esp -= 4;
    // 0053007c  68f0bc5600             -push 0x56bcf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684464 /*0x56bcf0*/;
    cpu.esp -= 4;
    // 00530081  e892f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530086  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530088  740c                   -je 0x530096
    if (cpu.flags.zf)
    {
        goto L_0x00530096;
    }
    // 0053008a  c705dcd15600ffffffff   -mov dword ptr [0x56d1dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */) = 4294967295 /*0xffffffff*/;
    // 00530094  eb23                   -jmp 0x5300b9
    goto L_0x005300b9;
L_0x00530096:
    // 00530096  833ddcd15600ff         +cmp dword ptr [0x56d1dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053009d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005300a2  7415                   -je 0x5300b9
    if (cpu.flags.zf)
    {
        goto L_0x005300b9;
    }
    // 005300a4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005300a7  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005300aa  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005300ad  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300b0  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005300b3  ff15dcd15600           -call dword ptr [0x56d1dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689820) /* 0x56d1dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005300b9:
    // 005300b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005300ba  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5300bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005300bd  833de0d1560000         +cmp dword ptr [0x56d1e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005300c4  751f                   -jne 0x5300e5
    if (!cpu.flags.zf)
    {
        goto L_0x005300e5;
    }
    // 005300c6  68e0d15600             -push 0x56d1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689824 /*0x56d1e0*/;
    cpu.esp -= 4;
    // 005300cb  6804bd5600             -push 0x56bd04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684484 /*0x56bd04*/;
    cpu.esp -= 4;
    // 005300d0  e843f2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005300d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005300d7  740c                   -je 0x5300e5
    if (cpu.flags.zf)
    {
        goto L_0x005300e5;
    }
    // 005300d9  c705e0d15600ffffffff   -mov dword ptr [0x56d1e0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */) = 4294967295 /*0xffffffff*/;
    // 005300e3  eb20                   -jmp 0x530105
    goto L_0x00530105;
L_0x005300e5:
    // 005300e5  833de0d15600ff         +cmp dword ptr [0x56d1e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005300ec  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005300f1  7412                   -je 0x530105
    if (cpu.flags.zf)
    {
        goto L_0x00530105;
    }
    // 005300f3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300f7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300fb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005300ff  ff15e0d15600           -call dword ptr [0x56d1e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689824) /* 0x56d1e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530105:
    // 00530105  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530108(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530108  833de4d1560000         +cmp dword ptr [0x56d1e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053010f  751f                   -jne 0x530130
    if (!cpu.flags.zf)
    {
        goto L_0x00530130;
    }
    // 00530111  68e4d15600             -push 0x56d1e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689828 /*0x56d1e4*/;
    cpu.esp -= 4;
    // 00530116  681cbd5600             -push 0x56bd1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684508 /*0x56bd1c*/;
    cpu.esp -= 4;
    // 0053011b  e8f8f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530120  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530122  740c                   -je 0x530130
    if (cpu.flags.zf)
    {
        goto L_0x00530130;
    }
    // 00530124  c705e4d15600ffffffff   -mov dword ptr [0x56d1e4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */) = 4294967295 /*0xffffffff*/;
    // 0053012e  eb20                   -jmp 0x530150
    goto L_0x00530150;
L_0x00530130:
    // 00530130  833de4d15600ff         +cmp dword ptr [0x56d1e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530137  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053013c  7412                   -je 0x530150
    if (cpu.flags.zf)
    {
        goto L_0x00530150;
    }
    // 0053013e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530142  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530146  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053014a  ff15e4d15600           -call dword ptr [0x56d1e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689828) /* 0x56d1e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530150:
    // 00530150  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530153(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530153  833de8d1560000         +cmp dword ptr [0x56d1e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053015a  751f                   -jne 0x53017b
    if (!cpu.flags.zf)
    {
        goto L_0x0053017b;
    }
    // 0053015c  68e8d15600             -push 0x56d1e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689832 /*0x56d1e8*/;
    cpu.esp -= 4;
    // 00530161  6834bd5600             -push 0x56bd34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684532 /*0x56bd34*/;
    cpu.esp -= 4;
    // 00530166  e8adf1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053016b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053016d  740c                   -je 0x53017b
    if (cpu.flags.zf)
    {
        goto L_0x0053017b;
    }
    // 0053016f  c705e8d15600ffffffff   -mov dword ptr [0x56d1e8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */) = 4294967295 /*0xffffffff*/;
    // 00530179  eb20                   -jmp 0x53019b
    goto L_0x0053019b;
L_0x0053017b:
    // 0053017b  833de8d15600ff         +cmp dword ptr [0x56d1e8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530182  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530187  7412                   -je 0x53019b
    if (cpu.flags.zf)
    {
        goto L_0x0053019b;
    }
    // 00530189  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053018d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530191  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530195  ff15e8d15600           -call dword ptr [0x56d1e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689832) /* 0x56d1e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053019b:
    // 0053019b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53019e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053019e  833decd1560000         +cmp dword ptr [0x56d1ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301a5  751f                   -jne 0x5301c6
    if (!cpu.flags.zf)
    {
        goto L_0x005301c6;
    }
    // 005301a7  68ecd15600             -push 0x56d1ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689836 /*0x56d1ec*/;
    cpu.esp -= 4;
    // 005301ac  684cbd5600             -push 0x56bd4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684556 /*0x56bd4c*/;
    cpu.esp -= 4;
    // 005301b1  e862f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005301b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005301b8  740c                   -je 0x5301c6
    if (cpu.flags.zf)
    {
        goto L_0x005301c6;
    }
    // 005301ba  c705ecd15600ffffffff   -mov dword ptr [0x56d1ec], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */) = 4294967295 /*0xffffffff*/;
    // 005301c4  eb20                   -jmp 0x5301e6
    goto L_0x005301e6;
L_0x005301c6:
    // 005301c6  833decd15600ff         +cmp dword ptr [0x56d1ec], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301cd  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005301d2  7412                   -je 0x5301e6
    if (cpu.flags.zf)
    {
        goto L_0x005301e6;
    }
    // 005301d4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301d8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301dc  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005301e0  ff15ecd15600           -call dword ptr [0x56d1ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689836) /* 0x56d1ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005301e6:
    // 005301e6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5301e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005301e9  833df0d1560000         +cmp dword ptr [0x56d1f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005301f0  751f                   -jne 0x530211
    if (!cpu.flags.zf)
    {
        goto L_0x00530211;
    }
    // 005301f2  68f0d15600             -push 0x56d1f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689840 /*0x56d1f0*/;
    cpu.esp -= 4;
    // 005301f7  6868bd5600             -push 0x56bd68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684584 /*0x56bd68*/;
    cpu.esp -= 4;
    // 005301fc  e817f1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530201  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530203  740c                   -je 0x530211
    if (cpu.flags.zf)
    {
        goto L_0x00530211;
    }
    // 00530205  c705f0d15600ffffffff   -mov dword ptr [0x56d1f0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */) = 4294967295 /*0xffffffff*/;
    // 0053020f  eb20                   -jmp 0x530231
    goto L_0x00530231;
L_0x00530211:
    // 00530211  833df0d15600ff         +cmp dword ptr [0x56d1f0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530218  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053021d  7412                   -je 0x530231
    if (cpu.flags.zf)
    {
        goto L_0x00530231;
    }
    // 0053021f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530223  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530227  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053022b  ff15f0d15600           -call dword ptr [0x56d1f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689840) /* 0x56d1f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530231:
    // 00530231  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530234  833df4d1560000         +cmp dword ptr [0x56d1f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053023b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053023c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053023e  751f                   -jne 0x53025f
    if (!cpu.flags.zf)
    {
        goto L_0x0053025f;
    }
    // 00530240  68f4d15600             -push 0x56d1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689844 /*0x56d1f4*/;
    cpu.esp -= 4;
    // 00530245  6884bd5600             -push 0x56bd84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684612 /*0x56bd84*/;
    cpu.esp -= 4;
    // 0053024a  e8c9f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053024f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530251  740c                   -je 0x53025f
    if (cpu.flags.zf)
    {
        goto L_0x0053025f;
    }
    // 00530253  c705f4d15600ffffffff   -mov dword ptr [0x56d1f4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */) = 4294967295 /*0xffffffff*/;
    // 0053025d  eb23                   -jmp 0x530282
    goto L_0x00530282;
L_0x0053025f:
    // 0053025f  833df4d15600ff         +cmp dword ptr [0x56d1f4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530266  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053026b  7415                   -je 0x530282
    if (cpu.flags.zf)
    {
        goto L_0x00530282;
    }
    // 0053026d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530270  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530273  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530276  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530279  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053027c  ff15f4d15600           -call dword ptr [0x56d1f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689844) /* 0x56d1f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530282:
    // 00530282  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530283  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530286(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530286  833df8d1560000         +cmp dword ptr [0x56d1f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053028d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053028e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530290  751f                   -jne 0x5302b1
    if (!cpu.flags.zf)
    {
        goto L_0x005302b1;
    }
    // 00530292  68f8d15600             -push 0x56d1f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689848 /*0x56d1f8*/;
    cpu.esp -= 4;
    // 00530297  6898bd5600             -push 0x56bd98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684632 /*0x56bd98*/;
    cpu.esp -= 4;
    // 0053029c  e877f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005302a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005302a3  740c                   -je 0x5302b1
    if (cpu.flags.zf)
    {
        goto L_0x005302b1;
    }
    // 005302a5  c705f8d15600ffffffff   -mov dword ptr [0x56d1f8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */) = 4294967295 /*0xffffffff*/;
    // 005302af  eb23                   -jmp 0x5302d4
    goto L_0x005302d4;
L_0x005302b1:
    // 005302b1  833df8d15600ff         +cmp dword ptr [0x56d1f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005302b8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005302bd  7415                   -je 0x5302d4
    if (cpu.flags.zf)
    {
        goto L_0x005302d4;
    }
    // 005302bf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005302c2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005302c5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005302c8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005302cb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005302ce  ff15f8d15600           -call dword ptr [0x56d1f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689848) /* 0x56d1f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005302d4:
    // 005302d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005302d5  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5302d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005302d8  833dfcd1560000         +cmp dword ptr [0x56d1fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005302df  751f                   -jne 0x530300
    if (!cpu.flags.zf)
    {
        goto L_0x00530300;
    }
    // 005302e1  68fcd15600             -push 0x56d1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689852 /*0x56d1fc*/;
    cpu.esp -= 4;
    // 005302e6  68acbd5600             -push 0x56bdac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684652 /*0x56bdac*/;
    cpu.esp -= 4;
    // 005302eb  e828f0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005302f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005302f2  740c                   -je 0x530300
    if (cpu.flags.zf)
    {
        goto L_0x00530300;
    }
    // 005302f4  c705fcd15600ffffffff   -mov dword ptr [0x56d1fc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */) = 4294967295 /*0xffffffff*/;
    // 005302fe  eb20                   -jmp 0x530320
    goto L_0x00530320;
L_0x00530300:
    // 00530300  833dfcd15600ff         +cmp dword ptr [0x56d1fc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530307  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053030c  7412                   -je 0x530320
    if (cpu.flags.zf)
    {
        goto L_0x00530320;
    }
    // 0053030e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530312  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530316  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053031a  ff15fcd15600           -call dword ptr [0x56d1fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689852) /* 0x56d1fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530320:
    // 00530320  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530323(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530323  833d00d2560000         +cmp dword ptr [0x56d200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053032a  751f                   -jne 0x53034b
    if (!cpu.flags.zf)
    {
        goto L_0x0053034b;
    }
    // 0053032c  6800d25600             -push 0x56d200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689856 /*0x56d200*/;
    cpu.esp -= 4;
    // 00530331  68c4bd5600             -push 0x56bdc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684676 /*0x56bdc4*/;
    cpu.esp -= 4;
    // 00530336  e8ddefffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053033b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053033d  740c                   -je 0x53034b
    if (cpu.flags.zf)
    {
        goto L_0x0053034b;
    }
    // 0053033f  c70500d25600ffffffff   -mov dword ptr [0x56d200], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */) = 4294967295 /*0xffffffff*/;
    // 00530349  eb20                   -jmp 0x53036b
    goto L_0x0053036b;
L_0x0053034b:
    // 0053034b  833d00d25600ff         +cmp dword ptr [0x56d200], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530352  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530357  7412                   -je 0x53036b
    if (cpu.flags.zf)
    {
        goto L_0x0053036b;
    }
    // 00530359  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053035d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530361  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530365  ff1500d25600           -call dword ptr [0x56d200]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689856) /* 0x56d200 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053036b:
    // 0053036b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53036e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053036e  833d04d2560000         +cmp dword ptr [0x56d204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530375  751f                   -jne 0x530396
    if (!cpu.flags.zf)
    {
        goto L_0x00530396;
    }
    // 00530377  6804d25600             -push 0x56d204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689860 /*0x56d204*/;
    cpu.esp -= 4;
    // 0053037c  68dcbd5600             -push 0x56bddc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684700 /*0x56bddc*/;
    cpu.esp -= 4;
    // 00530381  e892efffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530386  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530388  740c                   -je 0x530396
    if (cpu.flags.zf)
    {
        goto L_0x00530396;
    }
    // 0053038a  c70504d25600ffffffff   -mov dword ptr [0x56d204], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */) = 4294967295 /*0xffffffff*/;
    // 00530394  eb20                   -jmp 0x5303b6
    goto L_0x005303b6;
L_0x00530396:
    // 00530396  833d04d25600ff         +cmp dword ptr [0x56d204], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053039d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005303a2  7412                   -je 0x5303b6
    if (cpu.flags.zf)
    {
        goto L_0x005303b6;
    }
    // 005303a4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303a8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303ac  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303b0  ff1504d25600           -call dword ptr [0x56d204]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689860) /* 0x56d204 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005303b6:
    // 005303b6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5303b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005303b9  833d08d2560000         +cmp dword ptr [0x56d208], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005303c0  751f                   -jne 0x5303e1
    if (!cpu.flags.zf)
    {
        goto L_0x005303e1;
    }
    // 005303c2  6808d25600             -push 0x56d208
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689864 /*0x56d208*/;
    cpu.esp -= 4;
    // 005303c7  68f0bd5600             -push 0x56bdf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684720 /*0x56bdf0*/;
    cpu.esp -= 4;
    // 005303cc  e847efffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005303d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005303d3  740c                   -je 0x5303e1
    if (cpu.flags.zf)
    {
        goto L_0x005303e1;
    }
    // 005303d5  c70508d25600ffffffff   -mov dword ptr [0x56d208], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */) = 4294967295 /*0xffffffff*/;
    // 005303df  eb20                   -jmp 0x530401
    goto L_0x00530401;
L_0x005303e1:
    // 005303e1  833d08d25600ff         +cmp dword ptr [0x56d208], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005303e8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005303ed  7412                   -je 0x530401
    if (cpu.flags.zf)
    {
        goto L_0x00530401;
    }
    // 005303ef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303f3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303f7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005303fb  ff1508d25600           -call dword ptr [0x56d208]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689864) /* 0x56d208 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530401:
    // 00530401  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530404  833d0cd2560000         +cmp dword ptr [0x56d20c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053040b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053040c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053040e  751f                   -jne 0x53042f
    if (!cpu.flags.zf)
    {
        goto L_0x0053042f;
    }
    // 00530410  680cd25600             -push 0x56d20c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689868 /*0x56d20c*/;
    cpu.esp -= 4;
    // 00530415  6804be5600             -push 0x56be04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684740 /*0x56be04*/;
    cpu.esp -= 4;
    // 0053041a  e8f9eeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053041f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530421  740c                   -je 0x53042f
    if (cpu.flags.zf)
    {
        goto L_0x0053042f;
    }
    // 00530423  c7050cd25600ffffffff   -mov dword ptr [0x56d20c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */) = 4294967295 /*0xffffffff*/;
    // 0053042d  eb26                   -jmp 0x530455
    goto L_0x00530455;
L_0x0053042f:
    // 0053042f  833d0cd25600ff         +cmp dword ptr [0x56d20c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530436  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053043b  7418                   -je 0x530455
    if (cpu.flags.zf)
    {
        goto L_0x00530455;
    }
    // 0053043d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530440  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530443  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530446  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530449  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053044c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053044f  ff150cd25600           -call dword ptr [0x56d20c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689868) /* 0x56d20c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530455:
    // 00530455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530456  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530459(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530459  833d10d2560000         +cmp dword ptr [0x56d210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530460  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530461  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530463  751f                   -jne 0x530484
    if (!cpu.flags.zf)
    {
        goto L_0x00530484;
    }
    // 00530465  6810d25600             -push 0x56d210
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689872 /*0x56d210*/;
    cpu.esp -= 4;
    // 0053046a  6818be5600             -push 0x56be18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684760 /*0x56be18*/;
    cpu.esp -= 4;
    // 0053046f  e8a4eeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530474  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530476  740c                   -je 0x530484
    if (cpu.flags.zf)
    {
        goto L_0x00530484;
    }
    // 00530478  c70510d25600ffffffff   -mov dword ptr [0x56d210], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */) = 4294967295 /*0xffffffff*/;
    // 00530482  eb26                   -jmp 0x5304aa
    goto L_0x005304aa;
L_0x00530484:
    // 00530484  833d10d25600ff         +cmp dword ptr [0x56d210], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053048b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530490  7418                   -je 0x5304aa
    if (cpu.flags.zf)
    {
        goto L_0x005304aa;
    }
    // 00530492  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530495  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530498  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053049b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053049e  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005304a1  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005304a4  ff1510d25600           -call dword ptr [0x56d210]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689872) /* 0x56d210 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005304aa:
    // 005304aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005304ab  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5304ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005304ae  833d14d2560000         +cmp dword ptr [0x56d214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005304b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005304b6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005304b8  751f                   -jne 0x5304d9
    if (!cpu.flags.zf)
    {
        goto L_0x005304d9;
    }
    // 005304ba  6814d25600             -push 0x56d214
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689876 /*0x56d214*/;
    cpu.esp -= 4;
    // 005304bf  682cbe5600             -push 0x56be2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684780 /*0x56be2c*/;
    cpu.esp -= 4;
    // 005304c4  e84feeffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005304c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005304cb  740c                   -je 0x5304d9
    if (cpu.flags.zf)
    {
        goto L_0x005304d9;
    }
    // 005304cd  c70514d25600ffffffff   -mov dword ptr [0x56d214], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */) = 4294967295 /*0xffffffff*/;
    // 005304d7  eb26                   -jmp 0x5304ff
    goto L_0x005304ff;
L_0x005304d9:
    // 005304d9  833d14d25600ff         +cmp dword ptr [0x56d214], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005304e0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005304e5  7418                   -je 0x5304ff
    if (cpu.flags.zf)
    {
        goto L_0x005304ff;
    }
    // 005304e7  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005304ea  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005304ed  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005304f0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005304f3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005304f6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005304f9  ff1514d25600           -call dword ptr [0x56d214]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689876) /* 0x56d214 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005304ff:
    // 005304ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530500  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530503(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530503  833d18d2560000         +cmp dword ptr [0x56d218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053050a  751f                   -jne 0x53052b
    if (!cpu.flags.zf)
    {
        goto L_0x0053052b;
    }
    // 0053050c  6818d25600             -push 0x56d218
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689880 /*0x56d218*/;
    cpu.esp -= 4;
    // 00530511  6840be5600             -push 0x56be40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684800 /*0x56be40*/;
    cpu.esp -= 4;
    // 00530516  e8fdedffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053051b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053051d  740c                   -je 0x53052b
    if (cpu.flags.zf)
    {
        goto L_0x0053052b;
    }
    // 0053051f  c70518d25600ffffffff   -mov dword ptr [0x56d218], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */) = 4294967295 /*0xffffffff*/;
    // 00530529  eb1c                   -jmp 0x530547
    goto L_0x00530547;
L_0x0053052b:
    // 0053052b  833d18d25600ff         +cmp dword ptr [0x56d218], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530532  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530537  740e                   -je 0x530547
    if (cpu.flags.zf)
    {
        goto L_0x00530547;
    }
    // 00530539  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053053d  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530541  ff1518d25600           -call dword ptr [0x56d218]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689880) /* 0x56d218 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530547:
    // 00530547  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53054a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053054a  833d1cd2560000         +cmp dword ptr [0x56d21c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530551  751f                   -jne 0x530572
    if (!cpu.flags.zf)
    {
        goto L_0x00530572;
    }
    // 00530553  681cd25600             -push 0x56d21c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689884 /*0x56d21c*/;
    cpu.esp -= 4;
    // 00530558  6850be5600             -push 0x56be50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684816 /*0x56be50*/;
    cpu.esp -= 4;
    // 0053055d  e8b6edffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530562  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530564  740c                   -je 0x530572
    if (cpu.flags.zf)
    {
        goto L_0x00530572;
    }
    // 00530566  c7051cd25600ffffffff   -mov dword ptr [0x56d21c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */) = 4294967295 /*0xffffffff*/;
    // 00530570  eb1c                   -jmp 0x53058e
    goto L_0x0053058e;
L_0x00530572:
    // 00530572  833d1cd25600ff         +cmp dword ptr [0x56d21c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530579  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053057e  740e                   -je 0x53058e
    if (cpu.flags.zf)
    {
        goto L_0x0053058e;
    }
    // 00530580  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530584  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530588  ff151cd25600           -call dword ptr [0x56d21c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689884) /* 0x56d21c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053058e:
    // 0053058e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530591(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530591  833d20d2560000         +cmp dword ptr [0x56d220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530598  751f                   -jne 0x5305b9
    if (!cpu.flags.zf)
    {
        goto L_0x005305b9;
    }
    // 0053059a  6820d25600             -push 0x56d220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689888 /*0x56d220*/;
    cpu.esp -= 4;
    // 0053059f  6864be5600             -push 0x56be64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684836 /*0x56be64*/;
    cpu.esp -= 4;
    // 005305a4  e86fedffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005305a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005305ab  740c                   -je 0x5305b9
    if (cpu.flags.zf)
    {
        goto L_0x005305b9;
    }
    // 005305ad  c70520d25600ffffffff   -mov dword ptr [0x56d220], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */) = 4294967295 /*0xffffffff*/;
    // 005305b7  eb1c                   -jmp 0x5305d5
    goto L_0x005305d5;
L_0x005305b9:
    // 005305b9  833d20d25600ff         +cmp dword ptr [0x56d220], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005305c0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005305c5  740e                   -je 0x5305d5
    if (cpu.flags.zf)
    {
        goto L_0x005305d5;
    }
    // 005305c7  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005305cb  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005305cf  ff1520d25600           -call dword ptr [0x56d220]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005305d5:
    // 005305d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5305d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005305d8  833d24d2560000         +cmp dword ptr [0x56d224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005305df  751f                   -jne 0x530600
    if (!cpu.flags.zf)
    {
        goto L_0x00530600;
    }
    // 005305e1  6824d25600             -push 0x56d224
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689892 /*0x56d224*/;
    cpu.esp -= 4;
    // 005305e6  6878be5600             -push 0x56be78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684856 /*0x56be78*/;
    cpu.esp -= 4;
    // 005305eb  e828edffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005305f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005305f2  740c                   -je 0x530600
    if (cpu.flags.zf)
    {
        goto L_0x00530600;
    }
    // 005305f4  c70524d25600ffffffff   -mov dword ptr [0x56d224], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */) = 4294967295 /*0xffffffff*/;
    // 005305fe  eb1c                   -jmp 0x53061c
    goto L_0x0053061c;
L_0x00530600:
    // 00530600  833d24d25600ff         +cmp dword ptr [0x56d224], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530607  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053060c  740e                   -je 0x53061c
    if (cpu.flags.zf)
    {
        goto L_0x0053061c;
    }
    // 0053060e  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530612  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530616  ff1524d25600           -call dword ptr [0x56d224]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053061c:
    // 0053061c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53061f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053061f  833d28d2560000         +cmp dword ptr [0x56d228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530626  751f                   -jne 0x530647
    if (!cpu.flags.zf)
    {
        goto L_0x00530647;
    }
    // 00530628  6828d25600             -push 0x56d228
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689896 /*0x56d228*/;
    cpu.esp -= 4;
    // 0053062d  688cbe5600             -push 0x56be8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684876 /*0x56be8c*/;
    cpu.esp -= 4;
    // 00530632  e8e1ecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530639  740c                   -je 0x530647
    if (cpu.flags.zf)
    {
        goto L_0x00530647;
    }
    // 0053063b  c70528d25600ffffffff   -mov dword ptr [0x56d228], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */) = 4294967295 /*0xffffffff*/;
    // 00530645  eb1c                   -jmp 0x530663
    goto L_0x00530663;
L_0x00530647:
    // 00530647  833d28d25600ff         +cmp dword ptr [0x56d228], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053064e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530653  740e                   -je 0x530663
    if (cpu.flags.zf)
    {
        goto L_0x00530663;
    }
    // 00530655  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530659  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053065d  ff1528d25600           -call dword ptr [0x56d228]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530663:
    // 00530663  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530666(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530666  833d2cd2560000         +cmp dword ptr [0x56d22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053066d  751f                   -jne 0x53068e
    if (!cpu.flags.zf)
    {
        goto L_0x0053068e;
    }
    // 0053066f  682cd25600             -push 0x56d22c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689900 /*0x56d22c*/;
    cpu.esp -= 4;
    // 00530674  68a4be5600             -push 0x56bea4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684900 /*0x56bea4*/;
    cpu.esp -= 4;
    // 00530679  e89aecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053067e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530680  740c                   -je 0x53068e
    if (cpu.flags.zf)
    {
        goto L_0x0053068e;
    }
    // 00530682  c7052cd25600ffffffff   -mov dword ptr [0x56d22c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */) = 4294967295 /*0xffffffff*/;
    // 0053068c  eb20                   -jmp 0x5306ae
    goto L_0x005306ae;
L_0x0053068e:
    // 0053068e  833d2cd25600ff         +cmp dword ptr [0x56d22c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530695  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053069a  7412                   -je 0x5306ae
    if (cpu.flags.zf)
    {
        goto L_0x005306ae;
    }
    // 0053069c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a8  ff152cd25600           -call dword ptr [0x56d22c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005306ae:
    // 005306ae  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5306b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005306b1  833d30d2560000         +cmp dword ptr [0x56d230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005306b8  751f                   -jne 0x5306d9
    if (!cpu.flags.zf)
    {
        goto L_0x005306d9;
    }
    // 005306ba  6830d25600             -push 0x56d230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689904 /*0x56d230*/;
    cpu.esp -= 4;
    // 005306bf  68b4be5600             -push 0x56beb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684916 /*0x56beb4*/;
    cpu.esp -= 4;
    // 005306c4  e84fecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005306c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005306cb  740c                   -je 0x5306d9
    if (cpu.flags.zf)
    {
        goto L_0x005306d9;
    }
    // 005306cd  c70530d25600ffffffff   -mov dword ptr [0x56d230], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */) = 4294967295 /*0xffffffff*/;
    // 005306d7  eb20                   -jmp 0x5306f9
    goto L_0x005306f9;
L_0x005306d9:
    // 005306d9  833d30d25600ff         +cmp dword ptr [0x56d230], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005306e0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005306e5  7412                   -je 0x5306f9
    if (cpu.flags.zf)
    {
        goto L_0x005306f9;
    }
    // 005306e7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306eb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306ef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306f3  ff1530d25600           -call dword ptr [0x56d230]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005306f9:
    // 005306f9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5306fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005306fc  833d34d2560000         +cmp dword ptr [0x56d234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530703  751f                   -jne 0x530724
    if (!cpu.flags.zf)
    {
        goto L_0x00530724;
    }
    // 00530705  6834d25600             -push 0x56d234
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689908 /*0x56d234*/;
    cpu.esp -= 4;
    // 0053070a  68c4be5600             -push 0x56bec4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684932 /*0x56bec4*/;
    cpu.esp -= 4;
    // 0053070f  e804ecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530714  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530716  740c                   -je 0x530724
    if (cpu.flags.zf)
    {
        goto L_0x00530724;
    }
    // 00530718  c70534d25600ffffffff   -mov dword ptr [0x56d234], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */) = 4294967295 /*0xffffffff*/;
    // 00530722  eb20                   -jmp 0x530744
    goto L_0x00530744;
L_0x00530724:
    // 00530724  833d34d25600ff         +cmp dword ptr [0x56d234], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053072b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530730  7412                   -je 0x530744
    if (cpu.flags.zf)
    {
        goto L_0x00530744;
    }
    // 00530732  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530736  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053073a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053073e  ff1534d25600           -call dword ptr [0x56d234]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530744:
    // 00530744  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530747(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530747  833d38d2560000         +cmp dword ptr [0x56d238], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053074e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053074f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530751  751f                   -jne 0x530772
    if (!cpu.flags.zf)
    {
        goto L_0x00530772;
    }
    // 00530753  6838d25600             -push 0x56d238
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689912 /*0x56d238*/;
    cpu.esp -= 4;
    // 00530758  68d4be5600             -push 0x56bed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684948 /*0x56bed4*/;
    cpu.esp -= 4;
    // 0053075d  e8b6ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530762  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530764  740c                   -je 0x530772
    if (cpu.flags.zf)
    {
        goto L_0x00530772;
    }
    // 00530766  c70538d25600ffffffff   -mov dword ptr [0x56d238], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */) = 4294967295 /*0xffffffff*/;
    // 00530770  eb23                   -jmp 0x530795
    goto L_0x00530795;
L_0x00530772:
    // 00530772  833d38d25600ff         +cmp dword ptr [0x56d238], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530779  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053077e  7415                   -je 0x530795
    if (cpu.flags.zf)
    {
        goto L_0x00530795;
    }
    // 00530780  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530783  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530786  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530789  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053078c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053078f  ff1538d25600           -call dword ptr [0x56d238]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530795:
    // 00530795  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530796  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530799(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530799  833d3cd2560000         +cmp dword ptr [0x56d23c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005307a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005307a3  751f                   -jne 0x5307c4
    if (!cpu.flags.zf)
    {
        goto L_0x005307c4;
    }
    // 005307a5  683cd25600             -push 0x56d23c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689916 /*0x56d23c*/;
    cpu.esp -= 4;
    // 005307aa  68e4be5600             -push 0x56bee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684964 /*0x56bee4*/;
    cpu.esp -= 4;
    // 005307af  e864ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005307b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005307b6  740c                   -je 0x5307c4
    if (cpu.flags.zf)
    {
        goto L_0x005307c4;
    }
    // 005307b8  c7053cd25600ffffffff   -mov dword ptr [0x56d23c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */) = 4294967295 /*0xffffffff*/;
    // 005307c2  eb23                   -jmp 0x5307e7
    goto L_0x005307e7;
L_0x005307c4:
    // 005307c4  833d3cd25600ff         +cmp dword ptr [0x56d23c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307cb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005307d0  7415                   -je 0x5307e7
    if (cpu.flags.zf)
    {
        goto L_0x005307e7;
    }
    // 005307d2  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005307d5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005307d8  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005307db  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005307de  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005307e1  ff153cd25600           -call dword ptr [0x56d23c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005307e7:
    // 005307e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005307e8  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5307eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005307eb  833d40d2560000         +cmp dword ptr [0x56d240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005307f3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005307f5  751f                   -jne 0x530816
    if (!cpu.flags.zf)
    {
        goto L_0x00530816;
    }
    // 005307f7  6840d25600             -push 0x56d240
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689920 /*0x56d240*/;
    cpu.esp -= 4;
    // 005307fc  68f4be5600             -push 0x56bef4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684980 /*0x56bef4*/;
    cpu.esp -= 4;
    // 00530801  e812ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530806  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530808  740c                   -je 0x530816
    if (cpu.flags.zf)
    {
        goto L_0x00530816;
    }
    // 0053080a  c70540d25600ffffffff   -mov dword ptr [0x56d240], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */) = 4294967295 /*0xffffffff*/;
    // 00530814  eb23                   -jmp 0x530839
    goto L_0x00530839;
L_0x00530816:
    // 00530816  833d40d25600ff         +cmp dword ptr [0x56d240], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053081d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530822  7415                   -je 0x530839
    if (cpu.flags.zf)
    {
        goto L_0x00530839;
    }
    // 00530824  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530827  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053082a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053082d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530830  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530833  ff1540d25600           -call dword ptr [0x56d240]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530839:
    // 00530839  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053083a  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_53083d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053083d  833d44d2560000         +cmp dword ptr [0x56d244], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530844  751f                   -jne 0x530865
    if (!cpu.flags.zf)
    {
        goto L_0x00530865;
    }
    // 00530846  6844d25600             -push 0x56d244
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689924 /*0x56d244*/;
    cpu.esp -= 4;
    // 0053084b  6804bf5600             -push 0x56bf04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684996 /*0x56bf04*/;
    cpu.esp -= 4;
    // 00530850  e8c3eaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530855  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530857  740c                   -je 0x530865
    if (cpu.flags.zf)
    {
        goto L_0x00530865;
    }
    // 00530859  c70544d25600ffffffff   -mov dword ptr [0x56d244], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */) = 4294967295 /*0xffffffff*/;
    // 00530863  eb20                   -jmp 0x530885
    goto L_0x00530885;
L_0x00530865:
    // 00530865  833d44d25600ff         +cmp dword ptr [0x56d244], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053086c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530871  7412                   -je 0x530885
    if (cpu.flags.zf)
    {
        goto L_0x00530885;
    }
    // 00530873  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530877  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053087b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053087f  ff1544d25600           -call dword ptr [0x56d244]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530885:
    // 00530885  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530888  833d48d2560000         +cmp dword ptr [0x56d248], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053088f  751f                   -jne 0x5308b0
    if (!cpu.flags.zf)
    {
        goto L_0x005308b0;
    }
    // 00530891  6848d25600             -push 0x56d248
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689928 /*0x56d248*/;
    cpu.esp -= 4;
    // 00530896  6818bf5600             -push 0x56bf18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685016 /*0x56bf18*/;
    cpu.esp -= 4;
    // 0053089b  e878eaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005308a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005308a2  740c                   -je 0x5308b0
    if (cpu.flags.zf)
    {
        goto L_0x005308b0;
    }
    // 005308a4  c70548d25600ffffffff   -mov dword ptr [0x56d248], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */) = 4294967295 /*0xffffffff*/;
    // 005308ae  eb20                   -jmp 0x5308d0
    goto L_0x005308d0;
L_0x005308b0:
    // 005308b0  833d48d25600ff         +cmp dword ptr [0x56d248], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005308b7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005308bc  7412                   -je 0x5308d0
    if (cpu.flags.zf)
    {
        goto L_0x005308d0;
    }
    // 005308be  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308c2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308c6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308ca  ff1548d25600           -call dword ptr [0x56d248]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005308d0:
    // 005308d0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5308d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005308d3  833d4cd2560000         +cmp dword ptr [0x56d24c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005308da  751f                   -jne 0x5308fb
    if (!cpu.flags.zf)
    {
        goto L_0x005308fb;
    }
    // 005308dc  684cd25600             -push 0x56d24c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689932 /*0x56d24c*/;
    cpu.esp -= 4;
    // 005308e1  682cbf5600             -push 0x56bf2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685036 /*0x56bf2c*/;
    cpu.esp -= 4;
    // 005308e6  e82deaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005308eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005308ed  740c                   -je 0x5308fb
    if (cpu.flags.zf)
    {
        goto L_0x005308fb;
    }
    // 005308ef  c7054cd25600ffffffff   -mov dword ptr [0x56d24c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */) = 4294967295 /*0xffffffff*/;
    // 005308f9  eb20                   -jmp 0x53091b
    goto L_0x0053091b;
L_0x005308fb:
    // 005308fb  833d4cd25600ff         +cmp dword ptr [0x56d24c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530902  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530907  7412                   -je 0x53091b
    if (cpu.flags.zf)
    {
        goto L_0x0053091b;
    }
    // 00530909  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053090d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530911  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530915  ff154cd25600           -call dword ptr [0x56d24c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053091b:
    // 0053091b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53091e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053091e  833d50d2560000         +cmp dword ptr [0x56d250], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530925  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530926  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530928  751f                   -jne 0x530949
    if (!cpu.flags.zf)
    {
        goto L_0x00530949;
    }
    // 0053092a  6850d25600             -push 0x56d250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689936 /*0x56d250*/;
    cpu.esp -= 4;
    // 0053092f  6840bf5600             -push 0x56bf40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685056 /*0x56bf40*/;
    cpu.esp -= 4;
    // 00530934  e8dfe9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530939  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053093b  740c                   -je 0x530949
    if (cpu.flags.zf)
    {
        goto L_0x00530949;
    }
    // 0053093d  c70550d25600ffffffff   -mov dword ptr [0x56d250], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */) = 4294967295 /*0xffffffff*/;
    // 00530947  eb20                   -jmp 0x530969
    goto L_0x00530969;
L_0x00530949:
    // 00530949  833d50d25600ff         +cmp dword ptr [0x56d250], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530950  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530955  7412                   -je 0x530969
    if (cpu.flags.zf)
    {
        goto L_0x00530969;
    }
    // 00530957  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053095a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053095d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530960  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530963  ff1550d25600           -call dword ptr [0x56d250]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530969:
    // 00530969  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053096a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53096d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053096d  833d54d2560000         +cmp dword ptr [0x56d254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530974  751f                   -jne 0x530995
    if (!cpu.flags.zf)
    {
        goto L_0x00530995;
    }
    // 00530976  6854d25600             -push 0x56d254
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689940 /*0x56d254*/;
    cpu.esp -= 4;
    // 0053097b  6850bf5600             -push 0x56bf50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685072 /*0x56bf50*/;
    cpu.esp -= 4;
    // 00530980  e893e9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530985  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530987  740c                   -je 0x530995
    if (cpu.flags.zf)
    {
        goto L_0x00530995;
    }
    // 00530989  c70554d25600ffffffff   -mov dword ptr [0x56d254], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */) = 4294967295 /*0xffffffff*/;
    // 00530993  eb20                   -jmp 0x5309b5
    goto L_0x005309b5;
L_0x00530995:
    // 00530995  833d54d25600ff         +cmp dword ptr [0x56d254], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053099c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005309a1  7412                   -je 0x5309b5
    if (cpu.flags.zf)
    {
        goto L_0x005309b5;
    }
    // 005309a3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309a7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309ab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309af  ff1554d25600           -call dword ptr [0x56d254]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005309b5:
    // 005309b5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5309b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005309b8  833d58d2560000         +cmp dword ptr [0x56d258], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005309bf  751f                   -jne 0x5309e0
    if (!cpu.flags.zf)
    {
        goto L_0x005309e0;
    }
    // 005309c1  6858d25600             -push 0x56d258
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689944 /*0x56d258*/;
    cpu.esp -= 4;
    // 005309c6  685cbf5600             -push 0x56bf5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685084 /*0x56bf5c*/;
    cpu.esp -= 4;
    // 005309cb  e848e9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005309d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005309d2  740c                   -je 0x5309e0
    if (cpu.flags.zf)
    {
        goto L_0x005309e0;
    }
    // 005309d4  c70558d25600ffffffff   -mov dword ptr [0x56d258], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */) = 4294967295 /*0xffffffff*/;
    // 005309de  eb20                   -jmp 0x530a00
    goto L_0x00530a00;
L_0x005309e0:
    // 005309e0  833d58d25600ff         +cmp dword ptr [0x56d258], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005309e7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005309ec  7412                   -je 0x530a00
    if (cpu.flags.zf)
    {
        goto L_0x00530a00;
    }
    // 005309ee  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309f2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309f6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309fa  ff1558d25600           -call dword ptr [0x56d258]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a00:
    // 00530a00  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530a03(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530a03  833d5cd2560000         +cmp dword ptr [0x56d25c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a0a  751f                   -jne 0x530a2b
    if (!cpu.flags.zf)
    {
        goto L_0x00530a2b;
    }
    // 00530a0c  685cd25600             -push 0x56d25c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689948 /*0x56d25c*/;
    cpu.esp -= 4;
    // 00530a11  686cbf5600             -push 0x56bf6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685100 /*0x56bf6c*/;
    cpu.esp -= 4;
    // 00530a16  e8fde8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530a1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530a1d  740c                   -je 0x530a2b
    if (cpu.flags.zf)
    {
        goto L_0x00530a2b;
    }
    // 00530a1f  c7055cd25600ffffffff   -mov dword ptr [0x56d25c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */) = 4294967295 /*0xffffffff*/;
    // 00530a29  eb20                   -jmp 0x530a4b
    goto L_0x00530a4b;
L_0x00530a2b:
    // 00530a2b  833d5cd25600ff         +cmp dword ptr [0x56d25c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a32  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530a37  7412                   -je 0x530a4b
    if (cpu.flags.zf)
    {
        goto L_0x00530a4b;
    }
    // 00530a39  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a3d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a41  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a45  ff155cd25600           -call dword ptr [0x56d25c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a4b:
    // 00530a4b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530a4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530a4e  833d60d2560000         +cmp dword ptr [0x56d260], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530a56  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530a58  751f                   -jne 0x530a79
    if (!cpu.flags.zf)
    {
        goto L_0x00530a79;
    }
    // 00530a5a  6860d25600             -push 0x56d260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689952 /*0x56d260*/;
    cpu.esp -= 4;
    // 00530a5f  687cbf5600             -push 0x56bf7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685116 /*0x56bf7c*/;
    cpu.esp -= 4;
    // 00530a64  e8afe8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530a69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530a6b  740c                   -je 0x530a79
    if (cpu.flags.zf)
    {
        goto L_0x00530a79;
    }
    // 00530a6d  c70560d25600ffffffff   -mov dword ptr [0x56d260], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */) = 4294967295 /*0xffffffff*/;
    // 00530a77  eb26                   -jmp 0x530a9f
    goto L_0x00530a9f;
L_0x00530a79:
    // 00530a79  833d60d25600ff         +cmp dword ptr [0x56d260], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a80  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530a85  7418                   -je 0x530a9f
    if (cpu.flags.zf)
    {
        goto L_0x00530a9f;
    }
    // 00530a87  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530a8a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530a8d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530a90  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530a93  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a96  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530a99  ff1560d25600           -call dword ptr [0x56d260]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a9f:
    // 00530a9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530aa0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530aa3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530aa3  833d64d2560000         +cmp dword ptr [0x56d264], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530aaa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530aab  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530aad  751f                   -jne 0x530ace
    if (!cpu.flags.zf)
    {
        goto L_0x00530ace;
    }
    // 00530aaf  6864d25600             -push 0x56d264
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689956 /*0x56d264*/;
    cpu.esp -= 4;
    // 00530ab4  6888bf5600             -push 0x56bf88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685128 /*0x56bf88*/;
    cpu.esp -= 4;
    // 00530ab9  e85ae8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530abe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530ac0  740c                   -je 0x530ace
    if (cpu.flags.zf)
    {
        goto L_0x00530ace;
    }
    // 00530ac2  c70564d25600ffffffff   -mov dword ptr [0x56d264], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */) = 4294967295 /*0xffffffff*/;
    // 00530acc  eb26                   -jmp 0x530af4
    goto L_0x00530af4;
L_0x00530ace:
    // 00530ace  833d64d25600ff         +cmp dword ptr [0x56d264], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ad5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ada  7418                   -je 0x530af4
    if (cpu.flags.zf)
    {
        goto L_0x00530af4;
    }
    // 00530adc  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530adf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530ae2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530ae5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530ae8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530aeb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530aee  ff1564d25600           -call dword ptr [0x56d264]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530af4:
    // 00530af4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530af5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530af8  833d68d2560000         +cmp dword ptr [0x56d268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530aff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530b00  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530b02  751f                   -jne 0x530b23
    if (!cpu.flags.zf)
    {
        goto L_0x00530b23;
    }
    // 00530b04  6868d25600             -push 0x56d268
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689960 /*0x56d268*/;
    cpu.esp -= 4;
    // 00530b09  6894bf5600             -push 0x56bf94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685140 /*0x56bf94*/;
    cpu.esp -= 4;
    // 00530b0e  e805e8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530b13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530b15  740c                   -je 0x530b23
    if (cpu.flags.zf)
    {
        goto L_0x00530b23;
    }
    // 00530b17  c70568d25600ffffffff   -mov dword ptr [0x56d268], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */) = 4294967295 /*0xffffffff*/;
    // 00530b21  eb26                   -jmp 0x530b49
    goto L_0x00530b49;
L_0x00530b23:
    // 00530b23  833d68d25600ff         +cmp dword ptr [0x56d268], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b2a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530b2f  7418                   -je 0x530b49
    if (cpu.flags.zf)
    {
        goto L_0x00530b49;
    }
    // 00530b31  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530b34  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530b37  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530b3a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530b3d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530b40  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b43  ff1568d25600           -call dword ptr [0x56d268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530b49:
    // 00530b49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530b4a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530b4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530b4d  833d6cd2560000         +cmp dword ptr [0x56d26c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b54  751f                   -jne 0x530b75
    if (!cpu.flags.zf)
    {
        goto L_0x00530b75;
    }
    // 00530b56  686cd25600             -push 0x56d26c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689964 /*0x56d26c*/;
    cpu.esp -= 4;
    // 00530b5b  68a0bf5600             -push 0x56bfa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685152 /*0x56bfa0*/;
    cpu.esp -= 4;
    // 00530b60  e8b3e7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530b65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530b67  740c                   -je 0x530b75
    if (cpu.flags.zf)
    {
        goto L_0x00530b75;
    }
    // 00530b69  c7056cd25600ffffffff   -mov dword ptr [0x56d26c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */) = 4294967295 /*0xffffffff*/;
    // 00530b73  eb1c                   -jmp 0x530b91
    goto L_0x00530b91;
L_0x00530b75:
    // 00530b75  833d6cd25600ff         +cmp dword ptr [0x56d26c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b7c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530b81  740e                   -je 0x530b91
    if (cpu.flags.zf)
    {
        goto L_0x00530b91;
    }
    // 00530b83  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b87  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b8b  ff156cd25600           -call dword ptr [0x56d26c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530b91:
    // 00530b91  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530b94  833d70d2560000         +cmp dword ptr [0x56d270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b9b  751f                   -jne 0x530bbc
    if (!cpu.flags.zf)
    {
        goto L_0x00530bbc;
    }
    // 00530b9d  6870d25600             -push 0x56d270
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689968 /*0x56d270*/;
    cpu.esp -= 4;
    // 00530ba2  68b8bf5600             -push 0x56bfb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685176 /*0x56bfb8*/;
    cpu.esp -= 4;
    // 00530ba7  e86ce7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530bac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530bae  740c                   -je 0x530bbc
    if (cpu.flags.zf)
    {
        goto L_0x00530bbc;
    }
    // 00530bb0  c70570d25600ffffffff   -mov dword ptr [0x56d270], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */) = 4294967295 /*0xffffffff*/;
    // 00530bba  eb1c                   -jmp 0x530bd8
    goto L_0x00530bd8;
L_0x00530bbc:
    // 00530bbc  833d70d25600ff         +cmp dword ptr [0x56d270], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530bc3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530bc8  740e                   -je 0x530bd8
    if (cpu.flags.zf)
    {
        goto L_0x00530bd8;
    }
    // 00530bca  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530bce  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530bd2  ff1570d25600           -call dword ptr [0x56d270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530bd8:
    // 00530bd8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530bdb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530bdb  833d74d2560000         +cmp dword ptr [0x56d274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530be2  751f                   -jne 0x530c03
    if (!cpu.flags.zf)
    {
        goto L_0x00530c03;
    }
    // 00530be4  6874d25600             -push 0x56d274
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689972 /*0x56d274*/;
    cpu.esp -= 4;
    // 00530be9  68d0bf5600             -push 0x56bfd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685200 /*0x56bfd0*/;
    cpu.esp -= 4;
    // 00530bee  e825e7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530bf5  740c                   -je 0x530c03
    if (cpu.flags.zf)
    {
        goto L_0x00530c03;
    }
    // 00530bf7  c70574d25600ffffffff   -mov dword ptr [0x56d274], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */) = 4294967295 /*0xffffffff*/;
    // 00530c01  eb1c                   -jmp 0x530c1f
    goto L_0x00530c1f;
L_0x00530c03:
    // 00530c03  833d74d25600ff         +cmp dword ptr [0x56d274], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c0a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530c0f  740e                   -je 0x530c1f
    if (cpu.flags.zf)
    {
        goto L_0x00530c1f;
    }
    // 00530c11  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530c15  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530c19  ff1574d25600           -call dword ptr [0x56d274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530c1f:
    // 00530c1f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530c22(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530c22  833d78d2560000         +cmp dword ptr [0x56d278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c29  751f                   -jne 0x530c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00530c4a;
    }
    // 00530c2b  6878d25600             -push 0x56d278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689976 /*0x56d278*/;
    cpu.esp -= 4;
    // 00530c30  68e8bf5600             -push 0x56bfe8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685224 /*0x56bfe8*/;
    cpu.esp -= 4;
    // 00530c35  e8dee6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530c3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530c3c  740c                   -je 0x530c4a
    if (cpu.flags.zf)
    {
        goto L_0x00530c4a;
    }
    // 00530c3e  c70578d25600ffffffff   -mov dword ptr [0x56d278], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */) = 4294967295 /*0xffffffff*/;
    // 00530c48  eb20                   -jmp 0x530c6a
    goto L_0x00530c6a;
L_0x00530c4a:
    // 00530c4a  833d78d25600ff         +cmp dword ptr [0x56d278], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c51  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530c56  7412                   -je 0x530c6a
    if (cpu.flags.zf)
    {
        goto L_0x00530c6a;
    }
    // 00530c58  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c5c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c60  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c64  ff1578d25600           -call dword ptr [0x56d278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530c6a:
    // 00530c6a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530c6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530c6d  833d7cd2560000         +cmp dword ptr [0x56d27c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c74  751f                   -jne 0x530c95
    if (!cpu.flags.zf)
    {
        goto L_0x00530c95;
    }
    // 00530c76  687cd25600             -push 0x56d27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689980 /*0x56d27c*/;
    cpu.esp -= 4;
    // 00530c7b  68f8bf5600             -push 0x56bff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685240 /*0x56bff8*/;
    cpu.esp -= 4;
    // 00530c80  e893e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530c85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530c87  740c                   -je 0x530c95
    if (cpu.flags.zf)
    {
        goto L_0x00530c95;
    }
    // 00530c89  c7057cd25600ffffffff   -mov dword ptr [0x56d27c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */) = 4294967295 /*0xffffffff*/;
    // 00530c93  eb20                   -jmp 0x530cb5
    goto L_0x00530cb5;
L_0x00530c95:
    // 00530c95  833d7cd25600ff         +cmp dword ptr [0x56d27c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c9c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ca1  7412                   -je 0x530cb5
    if (cpu.flags.zf)
    {
        goto L_0x00530cb5;
    }
    // 00530ca3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ca7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530cab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530caf  ff157cd25600           -call dword ptr [0x56d27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530cb5:
    // 00530cb5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530cb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530cb8  833d80d2560000         +cmp dword ptr [0x56d280], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530cbf  751f                   -jne 0x530ce0
    if (!cpu.flags.zf)
    {
        goto L_0x00530ce0;
    }
    // 00530cc1  6880d25600             -push 0x56d280
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689984 /*0x56d280*/;
    cpu.esp -= 4;
    // 00530cc6  6808c05600             -push 0x56c008
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685256 /*0x56c008*/;
    cpu.esp -= 4;
    // 00530ccb  e848e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530cd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530cd2  740c                   -je 0x530ce0
    if (cpu.flags.zf)
    {
        goto L_0x00530ce0;
    }
    // 00530cd4  c70580d25600ffffffff   -mov dword ptr [0x56d280], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */) = 4294967295 /*0xffffffff*/;
    // 00530cde  eb1c                   -jmp 0x530cfc
    goto L_0x00530cfc;
L_0x00530ce0:
    // 00530ce0  833d80d25600ff         +cmp dword ptr [0x56d280], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ce7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530cec  740e                   -je 0x530cfc
    if (cpu.flags.zf)
    {
        goto L_0x00530cfc;
    }
    // 00530cee  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530cf2  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530cf6  ff1580d25600           -call dword ptr [0x56d280]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530cfc:
    // 00530cfc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530cff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530cff  833d84d2560000         +cmp dword ptr [0x56d284], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d06  751f                   -jne 0x530d27
    if (!cpu.flags.zf)
    {
        goto L_0x00530d27;
    }
    // 00530d08  6884d25600             -push 0x56d284
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689988 /*0x56d284*/;
    cpu.esp -= 4;
    // 00530d0d  681cc05600             -push 0x56c01c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685276 /*0x56c01c*/;
    cpu.esp -= 4;
    // 00530d12  e801e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530d17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530d19  740c                   -je 0x530d27
    if (cpu.flags.zf)
    {
        goto L_0x00530d27;
    }
    // 00530d1b  c70584d25600ffffffff   -mov dword ptr [0x56d284], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */) = 4294967295 /*0xffffffff*/;
    // 00530d25  eb1c                   -jmp 0x530d43
    goto L_0x00530d43;
L_0x00530d27:
    // 00530d27  833d84d25600ff         +cmp dword ptr [0x56d284], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d2e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530d33  740e                   -je 0x530d43
    if (cpu.flags.zf)
    {
        goto L_0x00530d43;
    }
    // 00530d35  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d39  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d3d  ff1584d25600           -call dword ptr [0x56d284]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530d43:
    // 00530d43  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

}
