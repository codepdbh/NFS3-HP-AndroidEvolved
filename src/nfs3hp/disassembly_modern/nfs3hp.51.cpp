#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_51bdc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bdc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051bdc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bdc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051bdc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bdc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bdc5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051bdc7  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bdce  7c18                   -jl 0x51bde8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051bde8;
    }
    // 0051bdd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051bdd2  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051bdd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bdd6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bdd8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051bdda  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051bddc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bdde  b8b40c5500             -mov eax, 0x550cb4
    cpu.eax = 5573812 /*0x550cb4*/;
    // 0051bde3  e89863ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051bde8:
    // 0051bde8  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051bded  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0051bdef  e85c23ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051bdf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051bdf6  746e                   -je 0x51be66
    if (cpu.flags.zf)
    {
        goto L_0x0051be66;
    }
    // 0051bdf8  8b1dec6d5600           -mov ebx, dword ptr [0x566dec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051bdfe  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0051be00  83fb01                 +cmp ebx, 1
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
    // 0051be03  7c18                   -jl 0x51be1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051be1d;
    }
    // 0051be05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051be07  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051be0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051be0b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051be0d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051be0f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051be11  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051be13  b8c40c5500             -mov eax, 0x550cc4
    cpu.eax = 5573828 /*0x550cc4*/;
    // 0051be18  e86363ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051be1d:
    // 0051be1d  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051be24  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051be27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051be29  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051be2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051be2e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051be30  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051be33  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051be38  e81320ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051be3d  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051be44  7d06                   -jge 0x51be4c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051be4c;
    }
L_0x0051be46:
    // 0051be46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051be4c:
    // 0051be4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051be4e  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051be51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051be52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051be54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051be56  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051be58  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051be5a  b8d00c5500             -mov eax, 0x550cd0
    cpu.eax = 5573840 /*0x550cd0*/;
    // 0051be5f  e81c63ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051be64  ebe0                   -jmp 0x51be46
    goto L_0x0051be46;
L_0x0051be66:
    // 0051be66  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051be6d  7cd7                   -jl 0x51be46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051be46;
    }
    // 0051be6f  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051be72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051be73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051be75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051be77  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051be79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051be7b  b8dc0c5500             -mov eax, 0x550cdc
    cpu.eax = 5573852 /*0x550cdc*/;
    // 0051be80  e8fb62ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051be85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051be8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51be90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051be90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051be91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051be92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051be93  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051be96  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051be98  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0051be9a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051be9c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051be9e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051bea1  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051bea4  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051bea7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051bea9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051beab  7512                   -jne 0x51bebf
    if (!cpu.flags.zf)
    {
        goto L_0x0051bebf;
    }
    // 0051bead  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051beaf  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x0051beb2:
    // 0051beb2  39d0                   +cmp eax, edx
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
    // 0051beb4  7309                   -jae 0x51bebf
    if (!cpu.flags.cf)
    {
        goto L_0x0051bebf;
    }
    // 0051beb6  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051beb9  7404                   -je 0x51bebf
    if (cpu.flags.zf)
    {
        goto L_0x0051bebf;
    }
    // 0051bebb  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051bebc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051bebd  ebf3                   -jmp 0x51beb2
    goto L_0x0051beb2;
L_0x0051bebf:
    // 0051bebf  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0051bec2  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051bec5  0f8585000000           -jne 0x51bf50
    if (!cpu.flags.zf)
    {
        goto L_0x0051bf50;
    }
    // 0051becb  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051bece  39d9                   +cmp ecx, ebx
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
    // 0051bed0  0f8771000000           -ja 0x51bf47
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051bf47;
    }
    // 0051bed6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bed8  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051bedb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051bedd  3b5708                 +cmp edx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bee0  0f87bb000000           -ja 0x51bfa1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051bfa1;
    }
    // 0051bee6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051bee8  39d9                   +cmp ecx, ebx
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
    // 0051beea  775b                   -ja 0x51bf47
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051bf47;
    }
    // 0051beec  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0051beee  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051bef0  e8abfdffff             -call 0x51bca0
    cpu.esp -= 4;
    sub_51bca0(app, cpu);
    if (cpu.terminate) return;
    // 0051bef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051bef7  0f8498000000           -je 0x51bf95
    if (cpu.flags.zf)
    {
        goto L_0x0051bf95;
    }
    // 0051befd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051bf00  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051bf04  740f                   -je 0x51bf15
    if (cpu.flags.zf)
    {
        goto L_0x0051bf15;
    }
    // 0051bf06  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051bf09  a1f06d5600             -mov eax, dword ptr [0x566df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051bf0e  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0051bf11  c6470d01               -mov byte ptr [edi + 0xd], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */) = 1 /*0x1*/;
L_0x0051bf15:
    // 0051bf15  8a7501                 -mov dh, byte ptr [ebp + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0051bf18  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bf1a  80feff                 +cmp dh, 0xff
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051bf1d  7535                   -jne 0x51bf54
    if (!cpu.flags.zf)
    {
        goto L_0x0051bf54;
    }
    // 0051bf1f  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bf26  7c18                   -jl 0x51bf40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051bf40;
    }
    // 0051bf28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051bf2a  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051bf2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bf2e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bf30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051bf32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051bf34  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bf36  b8ec0c5500             -mov eax, 0x550cec
    cpu.eax = 5573868 /*0x550cec*/;
    // 0051bf3b  e84062ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051bf40:
    // 0051bf40  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051bf42  e879feffff             -call 0x51bdc0
    cpu.esp -= 4;
    sub_51bdc0(app, cpu);
    if (cpu.terminate) return;
L_0x0051bf47:
    // 0051bf47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0051bf49:
    // 0051bf49  83c404                 +add esp, 4
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
    // 0051bf4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bf50:
    // 0051bf50  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051bf52  ebf5                   -jmp 0x51bf49
    goto L_0x0051bf49;
L_0x0051bf54:
    // 0051bf54  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0051bf56  74ef                   -je 0x51bf47
    if (cpu.flags.zf)
    {
        goto L_0x0051bf47;
    }
    // 0051bf58  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051bf5f  7c1b                   -jl 0x51bf7c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051bf7c;
    }
    // 0051bf61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051bf63  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051bf66  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051bf68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051bf69  8d5d04                 -lea ebx, [ebp + 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0051bf6c  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 0051bf6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051bf70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bf72  b8fc0c5500             -mov eax, 0x550cfc
    cpu.eax = 5573884 /*0x550cfc*/;
    // 0051bf77  e80462ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051bf7c:
    // 0051bf7c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051bf7f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051bf81  8d5504                 -lea edx, [ebp + 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0051bf84  8a5d01                 -mov bl, byte ptr [ebp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0051bf87  e86467ffff             -call 0x5126f0
    cpu.esp -= 4;
    sub_5126f0(app, cpu);
    if (cpu.terminate) return;
    // 0051bf8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bf8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bf91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bf95:
    // 0051bf95  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051bf98  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bf9a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bf9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bf9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfa0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bfa1:
    // 0051bfa1  80fafe                 +cmp dl, 0xfe
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051bfa4  7411                   -je 0x51bfb7
    if (cpu.flags.zf)
    {
        goto L_0x0051bfb7;
    }
    // 0051bfa6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051bfab  40                     -inc eax
    (cpu.eax)++;
    // 0051bfac  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051bfae  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bfb0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bfb3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051bfb7:
    // 0051bfb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051bfb9  40                     -inc eax
    (cpu.eax)++;
    // 0051bfba  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051bfbc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051bfbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051bfc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051bfc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_51bfd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051bfd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051bfd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051bfd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051bfd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051bfd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051bfd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051bfd6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051bfd9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051bfdb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051bfdd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051bfe0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051bfe2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051bfe6  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051bfe9  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051bfec  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051bff0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051bff2  0f858f000000           -jne 0x51c087
    if (!cpu.flags.zf)
    {
        goto L_0x0051c087;
    }
L_0x0051bff8:
    // 0051bff8  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0051bffb  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0051bffe  39c8                   +cmp eax, ecx
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
    // 0051c000  7617                   -jbe 0x51c019
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051c019;
    }
    // 0051c002  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c006  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051c008  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0051c00b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051c00f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c011  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c013  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c016  01471c                 -add dword ptr [edi + 0x1c], eax
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0051c019:
    // 0051c019  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0051c01c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c01e  7452                   -je 0x51c072
    if (cpu.flags.zf)
    {
        goto L_0x0051c072;
    }
    // 0051c020  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c022  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0051c024:
    // 0051c024  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051c026  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0051c028  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0051c02b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c02d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051c02f  e85cfeffff             -call 0x51be90
    cpu.esp -= 4;
    sub_51be90(app, cpu);
    if (cpu.terminate) return;
    // 0051c034  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c038  807a1f00               +cmp byte ptr [edx + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051c03c  7516                   -jne 0x51c054
    if (!cpu.flags.zf)
    {
        goto L_0x0051c054;
    }
    // 0051c03e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c040  7412                   -je 0x51c054
    if (cpu.flags.zf)
    {
        goto L_0x0051c054;
    }
    // 0051c042  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c044  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051c046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c048  740a                   -je 0x51c054
    if (cpu.flags.zf)
    {
        goto L_0x0051c054;
    }
    // 0051c04a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051c04e  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051c052  75d0                   -jne 0x51c024
    if (!cpu.flags.zf)
    {
        goto L_0x0051c024;
    }
L_0x0051c054:
    // 0051c054  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c058  80781f00               +cmp byte ptr [eax + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051c05c  7514                   -jne 0x51c072
    if (!cpu.flags.zf)
    {
        goto L_0x0051c072;
    }
    // 0051c05e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051c060  7410                   -je 0x51c072
    if (cpu.flags.zf)
    {
        goto L_0x0051c072;
    }
    // 0051c062  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0051c065  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051c067  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0051c06a  e881e4fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051c06f  89771c                 -mov dword ptr [edi + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.esi;
L_0x0051c072:
    // 0051c072  833c2400               +cmp dword ptr [esp], 0
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
    // 0051c076  741b                   -je 0x51c093
    if (cpu.flags.zf)
    {
        goto L_0x0051c093;
    }
    // 0051c078  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c07d  83c40c                 +add esp, 0xc
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
    // 0051c080  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c081  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c082  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c083  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c085  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c086  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c087:
    // 0051c087  c7471c00000000         -mov dword ptr [edi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0051c08e  e965ffffff             -jmp 0x51bff8
    goto L_0x0051bff8;
L_0x0051c093:
    // 0051c093  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c095  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051c098  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c099  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c09a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c09b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c09c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c09d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c09e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51c0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c0a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051c0a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c0a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c0a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c0a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c0a6  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051c0a9  8b15ec6d5600           -mov edx, dword ptr [0x566dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051c0af  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051c0b2  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c0b5  7d14                   -jge 0x51c0cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051c0cb;
    }
L_0x0051c0b7:
    // 0051c0b7  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c0bb  7409                   -je 0x51c0c6
    if (cpu.flags.zf)
    {
        goto L_0x0051c0c6;
    }
L_0x0051c0bd:
    // 0051c0bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c0bf  ff5510                 -call dword ptr [ebp + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c0c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c0c4  7523                   -jne 0x51c0e9
    if (!cpu.flags.zf)
    {
        goto L_0x0051c0e9;
    }
L_0x0051c0c6:
    // 0051c0c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c0cb:
    // 0051c0cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c0cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c0cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c0cf  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c0d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c0d3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c0d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c0d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c0d9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051c0db  b8040d5500             -mov eax, 0x550d04
    cpu.eax = 5573892 /*0x550d04*/;
    // 0051c0e0  e89b60ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c0e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0e7  ebce                   -jmp 0x51c0b7
    goto L_0x0051c0b7;
L_0x0051c0e9:
    // 0051c0e9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c0eb  e8e0feffff             -call 0x51bfd0
    cpu.esp -= 4;
    sub_51bfd0(app, cpu);
    if (cpu.terminate) return;
    // 0051c0f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c0f2  75c9                   -jne 0x51c0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0051c0bd;
    }
    // 0051c0f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c0f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51c100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c100  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c101  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c102  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c103  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051c106  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c108  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0051c10c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051c10e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051c112  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051c116  83fb06                 +cmp ebx, 6
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
    // 0051c119  0f8cce020000           -jl 0x51c3ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c3ed;
    }
    // 0051c11f  81fbfa000000           +cmp ebx, 0xfa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c125  0f8ecf020000           -jle 0x51c3fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051c3fa;
    }
    // 0051c12b  bb100d5500             -mov ebx, 0x550d10
    cpu.ebx = 5573904 /*0x550d10*/;
    // 0051c130  68fa000000             -push 0xfa
    app->getMemory<x86::reg32>(cpu.esp-4) = 250 /*0xfa*/;
    cpu.esp -= 4;
    // 0051c135  bf200d5500             -mov edi, 0x550d20
    cpu.edi = 5573920 /*0x550d20*/;
    // 0051c13a  b828010000             -mov eax, 0x128
    cpu.eax = 296 /*0x128*/;
    // 0051c13f  683c0d5500             -push 0x550d3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5573948 /*0x550d3c*/;
    cpu.esp -= 4;
    // 0051c144  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0051c14a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0051c150  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0051c155  e8b64eeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051c15a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0051c15d:
    // 0051c15d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051c15f  7433                   -je 0x51c194
    if (cpu.flags.zf)
    {
        goto L_0x0051c194;
    }
    // 0051c161  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c165  742d                   -je 0x51c194
    if (cpu.flags.zf)
    {
        goto L_0x0051c194;
    }
    // 0051c167  bb100d5500             -mov ebx, 0x550d10
    cpu.ebx = 5573904 /*0x550d10*/;
    // 0051c16c  bf200d5500             -mov edi, 0x550d20
    cpu.edi = 5573920 /*0x550d20*/;
    // 0051c171  b82d010000             -mov eax, 0x12d
    cpu.eax = 301 /*0x12d*/;
    // 0051c176  68cc0d5500             -push 0x550dcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574092 /*0x550dcc*/;
    cpu.esp -= 4;
    // 0051c17b  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0051c181  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0051c187  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0051c18c  e87f4eeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051c191  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051c194:
    // 0051c194  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c198  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c19a  8a421e                 -mov al, byte ptr [edx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 0051c19d  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 0051c1a1  7e04                   -jle 0x51c1a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051c1a7;
    }
    // 0051c1a3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0051c1a7:
    // 0051c1a7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c1ab  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051c1ae  b9fe000000             -mov ecx, 0xfe
    cpu.ecx = 254 /*0xfe*/;
    // 0051c1b3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051c1b5  7505                   -jne 0x51c1bc
    if (!cpu.flags.zf)
    {
        goto L_0x0051c1bc;
    }
    // 0051c1b7  b9fc010000             -mov ecx, 0x1fc
    cpu.ecx = 508 /*0x1fc*/;
L_0x0051c1bc:
    // 0051c1bc  8d4124                 -lea eax, [ecx + 0x24]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0051c1bf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051c1c1  0f841f020000           -je 0x51c3e6
    if (cpu.flags.zf)
    {
        goto L_0x0051c3e6;
    }
    // 0051c1c7  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0051c1ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051c1cc  0f857b020000           -jne 0x51c44d
    if (!cpu.flags.zf)
    {
        goto L_0x0051c44d;
    }
    // 0051c1d2  bf100d5500             -mov edi, 0x550d10
    cpu.edi = 5573904 /*0x550d10*/;
    // 0051c1d7  ba200d5500             -mov edx, 0x550d20
    cpu.edx = 5573920 /*0x550d20*/;
    // 0051c1dc  bb45010000             -mov ebx, 0x145
    cpu.ebx = 325 /*0x145*/;
    // 0051c1e1  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0051c1e7  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 0051c1ed  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0051c1f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051c1f5  b8040e5500             -mov eax, 0x550e04
    cpu.eax = 5574148 /*0x550e04*/;
    // 0051c1fa  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0051c200  e81b54fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051c205  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051c207  c744240401000000       -mov dword ptr [esp + 4], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x0051c20f:
    // 0051c20f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051c211  0f84c2010000           -je 0x51c3d9
    if (cpu.flags.zf)
    {
        goto L_0x0051c3d9;
    }
    // 0051c217  8d5724                 -lea edx, [edi + 0x24]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051c21a  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0051c220  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051c227  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0051c22a  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0051c22d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051c230  c74618b0504f00         -mov dword ptr [esi + 0x18], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 5198000 /*0x4f50b0*/;
    // 0051c237  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051c23b  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0051c23d  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051c240  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c242  668b462a               -mov ax, word ptr [esi + 0x2a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 0051c246  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0051c249  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051c24d  88470c                 -mov byte ptr [edi + 0xc], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0051c250  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c254  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051c257  a10cac5600             -mov eax, dword ptr [0x56ac0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680140) /* 0x56ac0c */);
    // 0051c25c  6689470e               -mov word ptr [edi + 0xe], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0051c260  40                     -inc eax
    (cpu.eax)++;
    // 0051c261  c6470d00               -mov byte ptr [edi + 0xd], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 0051c265  a30cac5600             -mov dword ptr [0x56ac0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5680140) /* 0x56ac0c */) = cpu.eax;
    // 0051c26a  e871f0fcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051c26f  c7471c00000000         -mov dword ptr [edi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0051c276  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0051c279  895714                 -mov dword ptr [edi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0051c27c  8b15f06d5600           -mov edx, dword ptr [0x566df0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051c282  894f18                 -mov dword ptr [edi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0051c285  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051c287  752d                   -jne 0x51c2b6
    if (!cpu.flags.zf)
    {
        goto L_0x0051c2b6;
    }
    // 0051c289  b9100d5500             -mov ecx, 0x550d10
    cpu.ecx = 5573904 /*0x550d10*/;
    // 0051c28e  bb200d5500             -mov ebx, 0x550d20
    cpu.ebx = 5573920 /*0x550d20*/;
    // 0051c293  b86d010000             -mov eax, 0x16d
    cpu.eax = 365 /*0x16d*/;
    // 0051c298  680c0e5500             -push 0x550e0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574156 /*0x550e0c*/;
    cpu.esp -= 4;
    // 0051c29d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0051c2a3  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051c2a9  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0051c2ae  e85d4deeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051c2b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051c2b6:
    // 0051c2b6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c2ba  baa0c05100             -mov edx, 0x51c0a0
    cpu.edx = 5357728 /*0x51c0a0*/;
    // 0051c2bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c2c1  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c2c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c2c5  0f84c2010000           -je 0x51c48d
    if (cpu.flags.zf)
    {
        goto L_0x0051c48d;
    }
    // 0051c2cb  c7462400ca9a3b         -mov dword ptr [esi + 0x24], 0x3b9aca00
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 1000000000 /*0x3b9aca00*/;
    // 0051c2d2  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051c2d7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c2d9  e8721bffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051c2de  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c2e5  0f8d69010000           -jge 0x51c454
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051c454;
    }
L_0x0051c2eb:
    // 0051c2eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c2ed  e83e36fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051c2f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c2f4  0f8477010000           -je 0x51c471
    if (cpu.flags.zf)
    {
        goto L_0x0051c471;
    }
    // 0051c2fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c2ff  e81cb4fcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051c304  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c306  7c09                   -jl 0x51c311
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c311;
    }
L_0x0051c308:
    // 0051c308  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c30a  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c30d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c30f  7405                   -je 0x51c316
    if (cpu.flags.zf)
    {
        goto L_0x0051c316;
    }
L_0x0051c311:
    // 0051c311  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051c316:
    // 0051c316  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051c318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c31a  7421                   -je 0x51c33d
    if (cpu.flags.zf)
    {
        goto L_0x0051c33d;
    }
    // 0051c31c  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c323  7c18                   -jl 0x51c33d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c33d;
    }
    // 0051c325  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c327  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c32a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c32b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c32d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c32f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c331  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c333  b8400e5500             -mov eax, 0x550e40
    cpu.eax = 5574208 /*0x550e40*/;
    // 0051c338  e8435effff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c33d:
    // 0051c33d  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c341  7407                   -je 0x51c34a
    if (cpu.flags.zf)
    {
        goto L_0x0051c34a;
    }
    // 0051c343  c7462400ca9a3b         -mov dword ptr [esi + 0x24], 0x3b9aca00
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 1000000000 /*0x3b9aca00*/;
L_0x0051c34a:
    // 0051c34a  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c34e  740a                   -je 0x51c35a
    if (cpu.flags.zf)
    {
        goto L_0x0051c35a;
    }
    // 0051c350  807f0d00               +cmp byte ptr [edi + 0xd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051c354  7504                   -jne 0x51c35a
    if (!cpu.flags.zf)
    {
        goto L_0x0051c35a;
    }
    // 0051c356  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051c358  7491                   -je 0x51c2eb
    if (cpu.flags.zf)
    {
        goto L_0x0051c2eb;
    }
L_0x0051c35a:
    // 0051c35a  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c35e  0f851c010000           -jne 0x51c480
    if (!cpu.flags.zf)
    {
        goto L_0x0051c480;
    }
L_0x0051c364:
    // 0051c364  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0051c367  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051c369  751e                   -jne 0x51c389
    if (!cpu.flags.zf)
    {
        goto L_0x0051c389;
    }
    // 0051c36b  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c372  7c15                   -jl 0x51c389
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c389;
    }
    // 0051c374  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c376  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c379  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c37a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c37c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c37d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c37f  b8500e5500             -mov eax, 0x550e50
    cpu.eax = 5574224 /*0x550e50*/;
    // 0051c384  e8f75dffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c389:
    // 0051c389  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051c390  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051c394  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c396  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051c399:
    // 0051c399  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c39d  0f8412010000           -je 0x51c4b5
    if (cpu.flags.zf)
    {
        goto L_0x0051c4b5;
    }
    // 0051c3a3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051c3a5  0f850a010000           -jne 0x51c4b5
    if (!cpu.flags.zf)
    {
        goto L_0x0051c4b5;
    }
    // 0051c3ab  a1f06d5600             -mov eax, dword ptr [0x566df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051c3b0  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0051c3b3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051c3b6  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0051c3b9  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c3c0  7c17                   -jl 0x51c3d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c3d9;
    }
    // 0051c3c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c3c4  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c3c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c3c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c3ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c3cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c3cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c3cf  b8700e5500             -mov eax, 0x550e70
    cpu.eax = 5574256 /*0x550e70*/;
    // 0051c3d4  e8a75dffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c3d9:
    // 0051c3d9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051c3db  0f8423010000           -je 0x51c504
    if (cpu.flags.zf)
    {
        goto L_0x0051c504;
    }
    // 0051c3e1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051c3e6:
    // 0051c3e6  83c410                 +add esp, 0x10
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
    // 0051c3e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c3ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c3eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c3ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c3ed:
    // 0051c3ed  c744240c06000000       -mov dword ptr [esp + 0xc], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 6 /*0x6*/;
    // 0051c3f5  e963fdffff             -jmp 0x51c15d
    goto L_0x0051c15d;
L_0x0051c3fa:
    // 0051c3fa  668b5a1c               -mov bx, word ptr [edx + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0051c3fe  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 0051c401  0f8456fdffff           -je 0x51c15d
    if (cpu.flags.zf)
    {
        goto L_0x0051c15d;
    }
    // 0051c407  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051c40b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c40d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051c410  6689d8                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051c413  39c2                   +cmp edx, eax
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
    // 0051c415  0f8642fdffff           -jbe 0x51c15d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051c15d;
    }
    // 0051c41b  b8100d5500             -mov eax, 0x550d10
    cpu.eax = 5573904 /*0x550d10*/;
    // 0051c420  ba200d5500             -mov edx, 0x550d20
    cpu.edx = 5573920 /*0x550d20*/;
    // 0051c425  b92a010000             -mov ecx, 0x12a
    cpu.ecx = 298 /*0x12a*/;
    // 0051c42a  687c0d5500             -push 0x550d7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574012 /*0x550d7c*/;
    cpu.esp -= 4;
    // 0051c42f  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0051c434  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 0051c43a  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 0051c440  e8cb4beeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051c445  83c404                 +add esp, 4
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
    // 0051c448  e910fdffff             -jmp 0x51c15d
    goto L_0x0051c15d;
L_0x0051c44d:
    // 0051c44d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051c44f  e9bbfdffff             -jmp 0x51c20f
    goto L_0x0051c20f;
L_0x0051c454:
    // 0051c454  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c456  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c459  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c45a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c45c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c45e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c460  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051c462  b8340e5500             -mov eax, 0x550e34
    cpu.eax = 5574196 /*0x550e34*/;
    // 0051c467  e8145dffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c46c  e97afeffff             -jmp 0x51c2eb
    goto L_0x0051c2eb;
L_0x0051c471:
    // 0051c471  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c476  e86534fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051c47b  e988feffff             -jmp 0x51c308
    goto L_0x0051c308;
L_0x0051c480:
    // 0051c480  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051c482  0f85dcfeffff           -jne 0x51c364
    if (!cpu.flags.zf)
    {
        goto L_0x0051c364;
    }
    // 0051c488  e90cffffff             -jmp 0x51c399
    goto L_0x0051c399;
L_0x0051c48d:
    // 0051c48d  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c494  0f8cfffeffff           -jl 0x51c399
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c399;
    }
    // 0051c49a  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c49d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c49e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c4a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c4a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c4a4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051c4a6  b8600e5500             -mov eax, 0x550e60
    cpu.eax = 5574240 /*0x550e60*/;
    // 0051c4ab  e8d05cffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c4b0  e9e4feffff             -jmp 0x51c399
    goto L_0x0051c399;
L_0x0051c4b5:
    // 0051c4b5  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c4bc  7c18                   -jl 0x51c4d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c4d6;
    }
    // 0051c4be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c4c0  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c4c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c4c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c4c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c4c8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c4ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c4cc  b8840e5500             -mov eax, 0x550e84
    cpu.eax = 5574276 /*0x550e84*/;
    // 0051c4d1  e8aa5cffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c4d6:
    // 0051c4d6  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051c4db  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c4dd  e86e1cffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051c4e2  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051c4e7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c4e9  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051c4ed  e85e1cffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051c4f2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051c4f4  740e                   -je 0x51c504
    if (cpu.flags.zf)
    {
        goto L_0x0051c504;
    }
    // 0051c4f6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c4f8  e89353fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051c4fd  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0051c504:
    // 0051c504  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c506  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051c509  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c50a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c50b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c50c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51c510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c510  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c511  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c512  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c513  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c514  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0051c51a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0051c51c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051c51e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c520  7431                   -je 0x51c553
    if (cpu.flags.zf)
    {
        goto L_0x0051c553;
    }
    // 0051c522  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051c526  742b                   -je 0x51c553
    if (cpu.flags.zf)
    {
        goto L_0x0051c553;
    }
    // 0051c528  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051c52b  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c52e  7730                   -ja 0x51c560
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051c560;
    }
L_0x0051c530:
    // 0051c530  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051c532  755b                   -jne 0x51c58f
    if (!cpu.flags.zf)
    {
        goto L_0x0051c58f;
    }
    // 0051c534  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c53b  7c16                   -jl 0x51c553
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c553;
    }
    // 0051c53d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c53f  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 0051c542  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c543  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051c545  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051c547  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c549  b8e40e5500             -mov eax, 0x550ee4
    cpu.eax = 5574372 /*0x550ee4*/;
    // 0051c54e  e82d5cffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c553:
    // 0051c553  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c555  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0051c55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c55e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c55f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c560:
    // 0051c560  b8100d5500             -mov eax, 0x550d10
    cpu.eax = 5573904 /*0x550d10*/;
    // 0051c565  bb980e5500             -mov ebx, 0x550e98
    cpu.ebx = 5574296 /*0x550e98*/;
    // 0051c56a  bdb1010000             -mov ebp, 0x1b1
    cpu.ebp = 433 /*0x1b1*/;
    // 0051c56f  68b00e5500             -push 0x550eb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574320 /*0x550eb0*/;
    cpu.esp -= 4;
    // 0051c574  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0051c579  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051c57f  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0051c585  e8864aeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051c58a  83c404                 +add esp, 4
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
    // 0051c58d  eba1                   -jmp 0x51c530
    goto L_0x0051c530;
L_0x0051c58f:
    // 0051c58f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051c591  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c593  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c595  e836f7ffff             -call 0x51bcd0
    cpu.esp -= 4;
    sub_51bcd0(app, cpu);
    if (cpu.terminate) return;
    // 0051c59a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c59c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c59e  e84df7ffff             -call 0x51bcf0
    cpu.esp -= 4;
    sub_51bcf0(app, cpu);
    if (cpu.terminate) return;
    // 0051c5a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c5a8  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0051c5ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c5af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c5b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c5b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c5b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51c5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c5c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c5c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c5c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051c5c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c5c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c5c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c5c7  8b15ec6d5600           -mov edx, dword ptr [0x566dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051c5cd  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051c5d0  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c5d3  7d6a                   -jge 0x51c63f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051c63f;
    }
L_0x0051c5d5:
    // 0051c5d5  ff4e24                 -dec dword ptr [esi + 0x24]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))--;
    // 0051c5d8  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0051c5db  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051c5dd  7526                   -jne 0x51c605
    if (!cpu.flags.zf)
    {
        goto L_0x0051c605;
    }
    // 0051c5df  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c5e6  7c15                   -jl 0x51c5fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c5fd;
    }
    // 0051c5e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c5ea  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c5ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c5ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c5f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c5f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c5f3  b8fc0e5500             -mov eax, 0x550efc
    cpu.eax = 5574396 /*0x550efc*/;
    // 0051c5f8  e8835bffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c5fd:
    // 0051c5fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c5ff  ff561c                 -call dword ptr [esi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c602  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0051c605:
    // 0051c605  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c609  7551                   -jne 0x51c65c
    if (!cpu.flags.zf)
    {
        goto L_0x0051c65c;
    }
L_0x0051c60b:
    // 0051c60b  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c612  7c19                   -jl 0x51c62d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c62d;
    }
    // 0051c614  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c616  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c619  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c61a  8d5624                 -lea edx, [esi + 0x24]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0051c61d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c61f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051c621  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c623  b8080f5500             -mov eax, 0x550f08
    cpu.eax = 5574408 /*0x550f08*/;
    // 0051c628  e8535bffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c62d:
    // 0051c62d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c62f  e88cf7ffff             -call 0x51bdc0
    cpu.esp -= 4;
    sub_51bdc0(app, cpu);
    if (cpu.terminate) return;
L_0x0051c634:
    // 0051c634  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c63a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c63b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c63c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c63d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c63e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c63f:
    // 0051c63f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c641  8a470e                 -mov al, byte ptr [edi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0051c644  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c645  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c647  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c649  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c64b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051c64d  b8f00e5500             -mov eax, 0x550ef0
    cpu.eax = 5574384 /*0x550ef0*/;
    // 0051c652  e8295bffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c657  e979ffffff             -jmp 0x51c5d5
    goto L_0x0051c5d5;
L_0x0051c65c:
    // 0051c65c  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051c65f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c661  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c666  74a3                   -je 0x51c60b
    if (cpu.flags.zf)
    {
        goto L_0x0051c60b;
    }
    // 0051c668  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0051c66b  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0051c66e  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0051c671  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051c673  7fbf                   -jg 0x51c634
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051c634;
    }
    // 0051c675  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c677  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c679  e8d2f6ffff             -call 0x51bd50
    cpu.esp -= 4;
    sub_51bd50(app, cpu);
    if (cpu.terminate) return;
    // 0051c67e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c683  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c684  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c685  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c686  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c687  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c688  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51c690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c691  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051c692  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c695  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c697  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c699  0f84b7000000           -je 0x51c756
    if (cpu.flags.zf)
    {
        goto L_0x0051c756;
    }
    // 0051c69f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051c6a2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051c6a4  0f84ac000000           -je 0x51c756
    if (cpu.flags.zf)
    {
        goto L_0x0051c756;
    }
    // 0051c6aa  8b0dec6d5600           -mov ecx, dword ptr [0x566dec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051c6b0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051c6b2  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0051c6b5  83f901                 +cmp ecx, 1
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
    // 0051c6b8  7d49                   -jge 0x51c703
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051c703;
    }
L_0x0051c6ba:
    // 0051c6ba  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051c6bf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c6c1  e88a1affff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051c6c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c6c8  0f8490000000           -je 0x51c75e
    if (cpu.flags.zf)
    {
        goto L_0x0051c75e;
    }
    // 0051c6ce  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c6d2  7466                   -je 0x51c73a
    if (cpu.flags.zf)
    {
        goto L_0x0051c73a;
    }
    // 0051c6d4  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0051c6d9  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x0051c6e0:
    // 0051c6e0  49                     -dec ecx
    (cpu.ecx)--;
    // 0051c6e1  83f9ff                 +cmp ecx, -1
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
    // 0051c6e4  7445                   -je 0x51c72b
    if (cpu.flags.zf)
    {
        goto L_0x0051c72b;
    }
    // 0051c6e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c6e8  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c6eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c6ed  743c                   -je 0x51c72b
    if (cpu.flags.zf)
    {
        goto L_0x0051c72b;
    }
    // 0051c6ef  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0051c6f4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c6f6  e855f6ffff             -call 0x51bd50
    cpu.esp -= 4;
    sub_51bd50(app, cpu);
    if (cpu.terminate) return;
    // 0051c6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c6fd  7420                   -je 0x51c71f
    if (cpu.flags.zf)
    {
        goto L_0x0051c71f;
    }
    // 0051c6ff  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0051c701  ebdd                   -jmp 0x51c6e0
    goto L_0x0051c6e0;
L_0x0051c703:
    // 0051c703  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c704  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c706  8a420e                 -mov al, byte ptr [edx + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0051c709  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c70a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c70c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c70e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c710  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051c712  b8140f5500             -mov eax, 0x550f14
    cpu.eax = 5574420 /*0x550f14*/;
    // 0051c717  e8645affff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c71c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c71d  eb9b                   -jmp 0x51c6ba
    goto L_0x0051c6ba;
L_0x0051c71f:
    // 0051c71f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c724  e8b73ffdff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 0051c729  ebb5                   -jmp 0x51c6e0
    goto L_0x0051c6e0;
L_0x0051c72b:
    // 0051c72b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0051c730  e8ab3ffdff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 0051c735  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c737  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051c73a:
    // 0051c73a  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051c73f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c741  e80a17ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
L_0x0051c746:
    // 0051c746  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051c74b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051c74d  e8fe19ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051c752  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051c754  751d                   -jne 0x51c773
    if (!cpu.flags.zf)
    {
        goto L_0x0051c773;
    }
L_0x0051c756:
    // 0051c756  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c758  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c759  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c75a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c75b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c75c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c75d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c75e:
    // 0051c75e  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c762  74e2                   -je 0x51c746
    if (cpu.flags.zf)
    {
        goto L_0x0051c746;
    }
    // 0051c764  68240f5500             -push 0x550f24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574436 /*0x550f24*/;
    cpu.esp -= 4;
    // 0051c769  e88241fcff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 0051c76e  83c404                 +add esp, 4
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
    // 0051c771  ebd3                   -jmp 0x51c746
    goto L_0x0051c746;
L_0x0051c773:
    // 0051c773  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0051c776  e8e5ebfcff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0051c77b  807f0c00               +cmp byte ptr [edi + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051c77f  740e                   -je 0x51c78f
    if (cpu.flags.zf)
    {
        goto L_0x0051c78f;
    }
    // 0051c781  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c783  e80851fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051c788  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0051c78f:
    // 0051c78f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c794  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c795  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c796  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c799  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51c7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c7a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c7a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051c7a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051c7a5  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0051c7a7  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c7a9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c7ab  39c8                   +cmp eax, ecx
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
    // 0051c7ad  7303                   -jae 0x51c7b2
    if (!cpu.flags.cf)
    {
        goto L_0x0051c7b2;
    }
    // 0051c7af  43                     -inc ebx
    (cpu.ebx)++;
    // 0051c7b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0051c7b2:
    // 0051c7b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c7b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_51c7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c7c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c7c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051c7c3  c6400500               -mov byte ptr [eax + 5], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 0051c7c7  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0051c7ca  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0051c7cd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051c7cf  e8ac7ffdff             -call 0x4f4780
    cpu.esp -= 4;
    sub_4f4780(app, cpu);
    if (cpu.terminate) return;
    // 0051c7d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051c7d6  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051c7d9  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0051c7dc  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0051c7df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c7e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51c7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c7f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c7f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c7f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051c7f4  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051c7f7  8a7805                 -mov bh, byte ptr [eax + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0051c7fa  e8c1ffffff             -call 0x51c7c0
    cpu.esp -= 4;
    sub_51c7c0(app, cpu);
    if (cpu.terminate) return;
    // 0051c7ff  663b5904               +cmp bx, word ptr [ecx + 4]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0051c803  7508                   -jne 0x51c80d
    if (!cpu.flags.zf)
    {
        goto L_0x0051c80d;
    }
    // 0051c805  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051c80a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c80b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c80c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c80d:
    // 0051c80d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c80f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c810  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_51c820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c821  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051c822  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051c825  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051c827  83c078                 -add eax, 0x78
    (cpu.eax) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0051c82a  e8a11affff             -call 0x50e2d0
    cpu.esp -= 4;
    sub_50e2d0(app, cpu);
    if (cpu.terminate) return;
    // 0051c82f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051c832  83f8ff                 +cmp eax, -1
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
    // 0051c835  7428                   -je 0x51c85f
    if (cpu.flags.zf)
    {
        goto L_0x0051c85f;
    }
L_0x0051c837:
    // 0051c837  48                     -dec eax
    (cpu.eax)--;
    // 0051c838  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051c83b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0051c83d  668b402a               -mov ax, word ptr [eax + 0x2a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(42) /* 0x2a */);
    // 0051c841  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0051c846  8b0dec6d5600           -mov ecx, dword ptr [0x566dec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051c84c  89422c                 -mov dword ptr [edx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0051c84f  83f903                 +cmp ecx, 3
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
    // 0051c852  7d10                   -jge 0x51c864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051c864;
    }
    // 0051c854  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0051c857  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0051c859  83c404                 +add esp, 4
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
    // 0051c85c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c85d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c85e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c85f:
    // 0051c85f  8b4274                 -mov eax, dword ptr [edx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 0051c862  ebd3                   -jmp 0x51c837
    goto L_0x0051c837;
L_0x0051c864:
    // 0051c864  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c865  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c867  8a420d                 -mov al, byte ptr [edx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0051c86a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c86b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c86d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c86f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c871  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051c875  b8680f5500             -mov eax, 0x550f68
    cpu.eax = 5574504 /*0x550f68*/;
    // 0051c87a  e80159ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051c87f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c880  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0051c883  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0051c885  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051c888  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c889  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c88a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51c890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c890  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c891  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c892  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c893  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051c896  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c898  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051c89a  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 0051c89d  8d5a54                 -lea ebx, [edx + 0x54]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 0051c8a0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051c8a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051c8a5  e87621ffff             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 0051c8aa  8b6a30                 -mov ebp, dword ptr [edx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0051c8ad  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051c8b1  45                     -inc ebp
    (cpu.ebp)++;
    // 0051c8b2  896a30                 -mov dword ptr [edx + 0x30], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.ebp;
    // 0051c8b5  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051c8b9  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0051c8bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051c8be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051c8c0  e87b21ffff             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 0051c8c5  c74608ffffffff         -mov dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 0051c8cc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051c8cf  8a4604                 -mov al, byte ptr [esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051c8d2  c6460cfe               -mov byte ptr [esi + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 0051c8d6  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0051c8d8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051c8da  88460e                 -mov byte ptr [esi + 0xe], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0051c8dd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051c8df  884e0d                 -mov byte ptr [esi + 0xd], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 0051c8e2  e809dcfcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051c8e7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051c8ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c8eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c8ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c8ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51c8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051c8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051c8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051c8f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051c8f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051c8f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051c8f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051c8f7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051c8fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051c8fc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051c8fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c900  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0051c902  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0051c905  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051c908  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0051c90b  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c90e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c910  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051c912  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051c915  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051c918  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0051c91b  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0051c91e  39d0                   +cmp eax, edx
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
    // 0051c920  734d                   -jae 0x51c96f
    if (!cpu.flags.cf)
    {
        goto L_0x0051c96f;
    }
    // 0051c922  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0051c926  0f8cec000000           -jl 0x51ca18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051ca18;
    }
    // 0051c92c  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c933  7c19                   -jl 0x51c94e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c94e;
    }
    // 0051c935  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c937  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0051c93a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c93b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051c93e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051c940  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051c942  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c944  b8980f5500             -mov eax, 0x550f98
    cpu.eax = 5574552 /*0x550f98*/;
L_0x0051c949:
    // 0051c949  e83258ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c94e:
    // 0051c94e  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c952  0f84e6000000           -je 0x51ca3e
    if (cpu.flags.zf)
    {
        goto L_0x0051ca3e;
    }
L_0x0051c958:
    // 0051c958  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051c95b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c95d  668b422e               -mov ax, word ptr [edx + 0x2e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 0051c961  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051c964  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0051c967  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051c969  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c96a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c96b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c96c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c96d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051c96e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051c96f:
    // 0051c96f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051c971  e8aafeffff             -call 0x51c820
    cpu.esp -= 4;
    sub_51c820(app, cpu);
    if (cpu.terminate) return;
    // 0051c976  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0051c978  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c97a  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051c97d  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0051c980  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0051c983  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0051c986  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051c988  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051c98a  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051c98d  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051c990  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0051c993  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0051c996  e825feffff             -call 0x51c7c0
    cpu.esp -= 4;
    sub_51c7c0(app, cpu);
    if (cpu.terminate) return;
    // 0051c99b  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0051c99e  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051c9a1  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051c9a4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051c9a7  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051c9aa  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0051c9ad  39d0                   +cmp eax, edx
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
    // 0051c9af  7540                   -jne 0x51c9f1
    if (!cpu.flags.zf)
    {
        goto L_0x0051c9f1;
    }
    // 0051c9b1  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c9b8  7c24                   -jl 0x51c9de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c9de;
    }
    // 0051c9ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051c9bc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051c9bf  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0051c9c2  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0051c9c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051c9c6  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0051c9c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051c9cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051c9cd  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051c9d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051c9d2  7c16                   -jl 0x51c9ea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c9ea;
    }
    // 0051c9d4  b8780f5500             -mov eax, 0x550f78
    cpu.eax = 5574520 /*0x550f78*/;
L_0x0051c9d9:
    // 0051c9d9  e8a257ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051c9de:
    // 0051c9de  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0051c9e5  e96effffff             -jmp 0x51c958
    goto L_0x0051c958;
L_0x0051c9ea:
    // 0051c9ea  b8700f5500             -mov eax, 0x550f70
    cpu.eax = 5574512 /*0x550f70*/;
    // 0051c9ef  ebe8                   -jmp 0x51c9d9
    goto L_0x0051c9d9;
L_0x0051c9f1:
    // 0051c9f1  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051c9f8  0f8c50ffffff           -jl 0x51c94e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c94e;
    }
    // 0051c9fe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051ca00  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0051ca03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ca04  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051ca07  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051ca09  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051ca0b  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0051ca0e  b8800f5500             -mov eax, 0x550f80
    cpu.eax = 5574528 /*0x550f80*/;
    // 0051ca13  e931ffffff             -jmp 0x51c949
    goto L_0x0051c949;
L_0x0051ca18:
    // 0051ca18  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ca1f  0f8c29ffffff           -jl 0x51c94e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051c94e;
    }
    // 0051ca25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051ca27  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0051ca2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ca2b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051ca2e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051ca30  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051ca32  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0051ca34  b8900f5500             -mov eax, 0x550f90
    cpu.eax = 5574544 /*0x550f90*/;
    // 0051ca39  e90bffffff             -jmp 0x51c949
    goto L_0x0051c949;
L_0x0051ca3e:
    // 0051ca3e  c7460801000000         -mov dword ptr [esi + 8], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0051ca45  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0051ca48  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051ca4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51ca50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ca50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ca51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ca52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ca53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051ca54  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ca57  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051ca59  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051ca5b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0051ca5e  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0051ca60  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0051ca67  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051ca6a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051ca6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ca6e  ff550c                 -call dword ptr [ebp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ca71  83f806                 +cmp eax, 6
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
    // 0051ca74  730a                   -jae 0x51ca80
    if (!cpu.flags.cf)
    {
        goto L_0x0051ca80;
    }
L_0x0051ca76:
    // 0051ca76  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051ca78  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ca7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ca7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ca80:
    // 0051ca80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051ca82  e899fdffff             -call 0x51c820
    cpu.esp -= 4;
    sub_51c820(app, cpu);
    if (cpu.terminate) return;
    // 0051ca87  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0051ca8c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051ca91  c6410cfe               -mov byte ptr [ecx + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 0051ca95  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 0051ca98  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0051ca9d  88610e                 -mov byte ptr [ecx + 0xe], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ah;
    // 0051caa0  8d690c                 -lea ebp, [ecx + 0xc]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0051caa3  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0051caa6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051caa8  c6410d00               -mov byte ptr [ecx + 0xd], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 0051caac  e80ffdffff             -call 0x51c7c0
    cpu.esp -= 4;
    sub_51c7c0(app, cpu);
    if (cpu.terminate) return;
    // 0051cab1  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051cab4  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0051cab6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051cab8  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051cabb  83f806                 +cmp eax, 6
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
    // 0051cabe  7524                   -jne 0x51cae4
    if (!cpu.flags.zf)
    {
        goto L_0x0051cae4;
    }
    // 0051cac0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0051cac5:
    // 0051cac5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051cac7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051cac9  74ab                   -je 0x51ca76
    if (cpu.flags.zf)
    {
        goto L_0x0051ca76;
    }
    // 0051cacb  833c247f               +cmp dword ptr [esp], 0x7f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cacf  77a5                   -ja 0x51ca76
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051ca76;
    }
    // 0051cad1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cad3  668b472c               -mov ax, word ptr [edi + 0x2c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 0051cad7  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051cada  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051cadc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cadf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cae0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cae1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cae2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cae3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cae4:
    // 0051cae4  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0051cae6  ebdd                   -jmp 0x51cac5
    goto L_0x0051cac5;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_51caf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051caf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051caf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051caf2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051caf4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051caf6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051caf8  740d                   -je 0x51cb07
    if (cpu.flags.zf)
    {
        goto L_0x0051cb07;
    }
    // 0051cafa  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051cafd  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0051cb00  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051cb03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cb05  7e08                   -jle 0x51cb0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051cb0f;
    }
L_0x0051cb07:
    // 0051cb07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051cb0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cb0f:
    // 0051cb0f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051cb10  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cb17  7c1b                   -jl 0x51cb34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051cb34;
    }
    // 0051cb19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051cb1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cb1c  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051cb1f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cb20  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051cb23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cb25  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051cb27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cb29  b8a00f5500             -mov eax, 0x550fa0
    cpu.eax = 5574560 /*0x550fa0*/;
    // 0051cb2e  e84d56ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cb33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051cb34:
    // 0051cb34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051cb36  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051cb39  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0051cb3c  83e37f                 -and ebx, 0x7f
    cpu.ebx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0051cb3f  e80cffffff             -call 0x51ca50
    cpu.esp -= 4;
    sub_51ca50(app, cpu);
    if (cpu.terminate) return;
    // 0051cb44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_51cb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051cb50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051cb51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051cb52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051cb53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051cb54  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cb57  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051cb59  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0051cb5e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051cb64  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0051cb67  e834fcffff             -call 0x51c7a0
    cpu.esp -= 4;
    sub_51c7a0(app, cpu);
    if (cpu.terminate) return;
    // 0051cb6c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051cb6f  3b4630                 +cmp eax, dword ptr [esi + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cb72  7349                   -jae 0x51cbbd
    if (!cpu.flags.cf)
    {
        goto L_0x0051cbbd;
    }
    // 0051cb74  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cb77  7644                   -jbe 0x51cbbd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cbbd;
    }
    // 0051cb79  8b3dec6d5600           -mov edi, dword ptr [0x566dec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051cb7f  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0051cb82  83ff03                 +cmp edi, 3
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
    // 0051cb85  7d1a                   -jge 0x51cba1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051cba1;
    }
L_0x0051cb87:
    // 0051cb87  8d5e38                 -lea ebx, [esi + 0x38]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0051cb8a  8d4e54                 -lea ecx, [esi + 0x54]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
L_0x0051cb8d:
    // 0051cb8d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051cb8f  e83c17ffff             -call 0x50e2d0
    cpu.esp -= 4;
    sub_50e2d0(app, cpu);
    if (cpu.terminate) return;
    // 0051cb94  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cb97  7649                   -jbe 0x51cbe2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cbe2;
    }
L_0x0051cb99:
    // 0051cb99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cb9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cb9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cba1:
    // 0051cba1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cba3  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051cba6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cba7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051cbab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cbad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051cbaf  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051cbb1  b8a80f5500             -mov eax, 0x550fa8
    cpu.eax = 5574568 /*0x550fa8*/;
    // 0051cbb6  e8c555ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cbbb  ebca                   -jmp 0x51cb87
    goto L_0x0051cb87;
L_0x0051cbbd:
    // 0051cbbd  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cbc4  7cc1                   -jl 0x51cb87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051cb87;
    }
    // 0051cbc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cbc8  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051cbcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cbcc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051cbd0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cbd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051cbd4  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051cbd6  b8b00f5500             -mov eax, 0x550fb0
    cpu.eax = 5574576 /*0x550fb0*/;
    // 0051cbdb  e8a055ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cbe0  eba5                   -jmp 0x51cb87
    goto L_0x0051cb87;
L_0x0051cbe2:
    // 0051cbe2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051cbe4  e87713ffff             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 0051cbe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cbeb  74ac                   -je 0x51cb99
    if (cpu.flags.zf)
    {
        goto L_0x0051cb99;
    }
    // 0051cbed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051cbef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051cbf1  e85a12ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051cbf6  eb95                   -jmp 0x51cb8d
    goto L_0x0051cb8d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_51cc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051cc00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051cc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051cc02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051cc03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051cc04  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cc07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051cc09  8d4854                 -lea ecx, [eax + 0x54]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0051cc0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051cc0e  e8bd16ffff             -call 0x50e2d0
    cpu.esp -= 4;
    sub_50e2d0(app, cpu);
    if (cpu.terminate) return;
    // 0051cc13  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0051cc18  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051cc1e  e87dfbffff             -call 0x51c7a0
    cpu.esp -= 4;
    sub_51c7a0(app, cpu);
    if (cpu.terminate) return;
    // 0051cc23  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051cc26  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051cc28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051cc2a  e8d118ffff             -call 0x50e500
    cpu.esp -= 4;
    sub_50e500(app, cpu);
    if (cpu.terminate) return;
    // 0051cc2f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051cc31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cc33  7410                   -je 0x51cc45
    if (cpu.flags.zf)
    {
        goto L_0x0051cc45;
    }
    // 0051cc35  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cc3c  7d0f                   -jge 0x51cc4d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051cc4d;
    }
    // 0051cc3e  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0051cc45:
    // 0051cc45  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cc48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cc4d:
    // 0051cc4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cc4f  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051cc52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cc53  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051cc57  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cc59  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051cc5b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cc5d  b8b80f5500             -mov eax, 0x550fb8
    cpu.eax = 5574584 /*0x550fb8*/;
    // 0051cc62  e81955ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cc67  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051cc6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051cc71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cc75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_51cc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051cc80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051cc81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051cc82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051cc83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051cc84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051cc85  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051cc87  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cc8e  7c18                   -jl 0x51cca8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051cca8;
    }
    // 0051cc90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cc92  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051cc95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cc96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cc98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cc9a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051cc9c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051cc9e  b8c00f5500             -mov eax, 0x550fc0
    cpu.eax = 5574592 /*0x550fc0*/;
    // 0051cca3  e8d854ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051cca8:
    // 0051cca8  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051ccad  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0051ccaf  e89c14ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051ccb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ccb6  746e                   -je 0x51cd26
    if (cpu.flags.zf)
    {
        goto L_0x0051cd26;
    }
    // 0051ccb8  8b1dec6d5600           -mov ebx, dword ptr [0x566dec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051ccbe  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0051ccc0  83fb01                 +cmp ebx, 1
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
    // 0051ccc3  7c18                   -jl 0x51ccdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051ccdd;
    }
    // 0051ccc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051ccc7  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051ccca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cccb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cccd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cccf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051ccd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ccd3  b8d00f5500             -mov eax, 0x550fd0
    cpu.eax = 5574608 /*0x550fd0*/;
    // 0051ccd8  e8a354ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051ccdd:
    // 0051ccdd  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051cce4  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051cce7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051cce9  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ccec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051ccee  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051ccf0  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ccf3  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051ccf8  e85311ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051ccfd  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cd04  7d06                   -jge 0x51cd0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051cd0c;
    }
L_0x0051cd06:
    // 0051cd06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cd0c:
    // 0051cd0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cd0e  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051cd11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cd12  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cd14  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cd16  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051cd18  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051cd1a  b8dc0f5500             -mov eax, 0x550fdc
    cpu.eax = 5574620 /*0x550fdc*/;
    // 0051cd1f  e85c54ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cd24  ebe0                   -jmp 0x51cd06
    goto L_0x0051cd06;
L_0x0051cd26:
    // 0051cd26  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cd2d  7cd7                   -jl 0x51cd06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051cd06;
    }
    // 0051cd2f  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051cd32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cd33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cd35  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051cd37  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051cd39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051cd3b  b8e80f5500             -mov eax, 0x550fe8
    cpu.eax = 5574632 /*0x550fe8*/;
    // 0051cd40  e83b54ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cd45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cd4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_51cd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051cd50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051cd51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051cd52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051cd53  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051cd56  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051cd58  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0051cd5c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0051cd5e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051cd60  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051cd62  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051cd66  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051cd69  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051cd6b  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051cd6e  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0051cd71  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051cd73  7512                   -jne 0x51cd87
    if (!cpu.flags.zf)
    {
        goto L_0x0051cd87;
    }
    // 0051cd75  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051cd77  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x0051cd7a:
    // 0051cd7a  39d0                   +cmp eax, edx
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
    // 0051cd7c  7309                   -jae 0x51cd87
    if (!cpu.flags.cf)
    {
        goto L_0x0051cd87;
    }
    // 0051cd7e  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051cd81  7404                   -je 0x51cd87
    if (cpu.flags.zf)
    {
        goto L_0x0051cd87;
    }
    // 0051cd83  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051cd84  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051cd85  ebf3                   -jmp 0x51cd7a
    goto L_0x0051cd7a;
L_0x0051cd87:
    // 0051cd87  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0051cd8a  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051cd8d  7529                   -jne 0x51cdb8
    if (!cpu.flags.zf)
    {
        goto L_0x0051cdb8;
    }
    // 0051cd8f  8d4e06                 -lea ecx, [esi + 6]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0051cd92  39d9                   +cmp ecx, ebx
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
    // 0051cd94  7626                   -jbe 0x51cdbc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cdbc;
    }
L_0x0051cd96:
    // 0051cd96  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051cd99  83c728                 -add edi, 0x28
    (cpu.edi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0051cd9c  39d6                   +cmp esi, edx
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
    // 0051cd9e  0f8677010000           -jbe 0x51cf1b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cf1b;
    }
    // 0051cda4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051cda9  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0051cdab  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051cdad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051cdaf  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x0051cdb1:
    // 0051cdb1  83c410                 +add esp, 0x10
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
    // 0051cdb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cdb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cdb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cdb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cdb8:
    // 0051cdb8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051cdba  ebf5                   -jmp 0x51cdb1
    goto L_0x0051cdb1;
L_0x0051cdbc:
    // 0051cdbc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051cdbe  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051cdc1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051cdc3  3b5708                 +cmp edx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cdc6  0f8733010000           -ja 0x51ceff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051ceff;
    }
    // 0051cdcc  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051cdce  39d9                   +cmp ecx, ebx
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
    // 0051cdd0  77c4                   -ja 0x51cd96
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051cd96;
    }
    // 0051cdd2  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0051cdd4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051cdd6  e815faffff             -call 0x51c7f0
    cpu.esp -= 4;
    sub_51c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0051cddb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cddd  0f8414010000           -je 0x51cef7
    if (cpu.flags.zf)
    {
        goto L_0x0051cef7;
    }
    // 0051cde3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051cde7  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051cdeb  740c                   -je 0x51cdf9
    if (cpu.flags.zf)
    {
        goto L_0x0051cdf9;
    }
    // 0051cded  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051cdf1  a1f06d5600             -mov eax, dword ptr [0x566df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051cdf6  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0051cdf9:
    // 0051cdf9  ff4710                 -inc dword ptr [edi + 0x10]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))++;
    // 0051cdfc  8a7503                 -mov dh, byte ptr [ebp + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0051cdff  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051ce01  80fe7f                 +cmp dh, 0x7f
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
    // 0051ce04  770c                   -ja 0x51ce12
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051ce12;
    }
    // 0051ce06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ce08  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051ce0a  8a5503                 -mov dl, byte ptr [ebp + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0051ce0d  e83efdffff             -call 0x51cb50
    cpu.esp -= 4;
    sub_51cb50(app, cpu);
    if (cpu.terminate) return;
L_0x0051ce12:
    // 0051ce12  8a5d01                 -mov bl, byte ptr [ebp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0051ce15  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0051ce18  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051ce1a  7408                   -je 0x51ce24
    if (cpu.flags.zf)
    {
        goto L_0x0051ce24;
    }
    // 0051ce1c  8a7d02                 -mov bh, byte ptr [ebp + 2]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0051ce1f  80ff7f                 +cmp bh, 0x7f
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
    // 0051ce22  7642                   -jbe 0x51ce66
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ce66;
    }
L_0x0051ce24:
    // 0051ce24  8a4d02                 -mov cl, byte ptr [ebp + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0051ce27  80f97f                 +cmp cl, 0x7f
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
    // 0051ce2a  0f86b7000000           -jbe 0x51cee7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cee7;
    }
    // 0051ce30  80f9ff                 +cmp cl, 0xff
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
    // 0051ce33  0f855dffffff           -jne 0x51cd96
    if (!cpu.flags.zf)
    {
        goto L_0x0051cd96;
    }
    // 0051ce39  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ce40  7c18                   -jl 0x51ce5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051ce5a;
    }
    // 0051ce42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051ce44  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051ce47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ce48  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051ce4a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051ce4c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051ce4e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051ce50  b800105500             -mov eax, 0x551000
    cpu.eax = 5574656 /*0x551000*/;
    // 0051ce55  e82653ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051ce5a:
    // 0051ce5a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051ce5c  e81ffeffff             -call 0x51cc80
    cpu.esp -= 4;
    sub_51cc80(app, cpu);
    if (cpu.terminate) return;
    // 0051ce61  e930ffffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051ce66:
    // 0051ce66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051ce68  8b4770                 -mov eax, dword ptr [edi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 0051ce6b  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 0051ce6d  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0051ce72  e829f9ffff             -call 0x51c7a0
    cpu.esp -= 4;
    sub_51c7a0(app, cpu);
    if (cpu.terminate) return;
    // 0051ce77  8d5f78                 -lea ebx, [edi + 0x78]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0051ce7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051ce7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051ce7e  e87d19ffff             -call 0x50e800
    cpu.esp -= 4;
    sub_50e800(app, cpu);
    if (cpu.terminate) return;
    // 0051ce83  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051ce87  c6470e00               -mov byte ptr [edi + 0xe], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0051ce8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ce8d  0f8403ffffff           -je 0x51cd96
    if (cpu.flags.zf)
    {
        goto L_0x0051cd96;
    }
    // 0051ce93  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051ce96  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051ce98  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051ce9a  e851d6fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051ce9f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051cea3  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0051cea9  e8f211ffff             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051ceae  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ceb2  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0051ceb4  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051cebb  0f8cd5feffff           -jl 0x51cd96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051cd96;
    }
    // 0051cec1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cec3  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051cec6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051cec7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051cecb  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0051cecd  8d5812                 -lea ebx, [eax + 0x12]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0051ced0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051ced2  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051ced5  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0051ced8  b8f80f5500             -mov eax, 0x550ff8
    cpu.eax = 5574648 /*0x550ff8*/;
    // 0051cedd  e89e52ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051cee2  e9affeffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051cee7:
    // 0051cee7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051cee9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051ceeb  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0051ceed  e80efdffff             -call 0x51cc00
    cpu.esp -= 4;
    sub_51cc00(app, cpu);
    if (cpu.terminate) return;
    // 0051cef2  e99ffeffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051cef7:
    // 0051cef7  83c603                 +add esi, 3
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051cefa  e997feffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051ceff:
    // 0051ceff  80fafe                 +cmp dl, 0xfe
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051cf02  740d                   -je 0x51cf11
    if (cpu.flags.zf)
    {
        goto L_0x0051cf11;
    }
    // 0051cf04  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051cf09  40                     -inc eax
    (cpu.eax)++;
    // 0051cf0a  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051cf0c  e985feffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051cf11:
    // 0051cf11  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cf13  40                     -inc eax
    (cpu.eax)++;
    // 0051cf14  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051cf16  e97bfeffff             -jmp 0x51cd96
    goto L_0x0051cd96;
L_0x0051cf1b:
    // 0051cf1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cf1d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0051cf1f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051cf21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051cf23  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0051cf25  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051cf28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cf29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cf2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cf2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_51cf30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051cf30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051cf31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051cf32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051cf33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051cf34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051cf35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051cf36  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051cf39  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051cf3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051cf3d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051cf40  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051cf42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051cf46  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051cf49  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051cf4c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051cf50  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051cf52  0f858f000000           -jne 0x51cfe7
    if (!cpu.flags.zf)
    {
        goto L_0x0051cfe7;
    }
L_0x0051cf58:
    // 0051cf58  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051cf5b  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0051cf5e  39c8                   +cmp eax, ecx
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
    // 0051cf60  7617                   -jbe 0x51cf79
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051cf79;
    }
    // 0051cf62  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051cf66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051cf68  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0051cf6b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051cf6f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cf71  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051cf73  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051cf76  014724                 -add dword ptr [edi + 0x24], eax
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0051cf79:
    // 0051cf79  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051cf7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cf7e  7452                   -je 0x51cfd2
    if (cpu.flags.zf)
    {
        goto L_0x0051cfd2;
    }
    // 0051cf80  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051cf82  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0051cf84:
    // 0051cf84  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051cf86  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0051cf88  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0051cf8b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051cf8d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051cf8f  e8bcfdffff             -call 0x51cd50
    cpu.esp -= 4;
    sub_51cd50(app, cpu);
    if (cpu.terminate) return;
    // 0051cf94  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051cf98  807a1f00               +cmp byte ptr [edx + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051cf9c  7516                   -jne 0x51cfb4
    if (!cpu.flags.zf)
    {
        goto L_0x0051cfb4;
    }
    // 0051cf9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cfa0  7412                   -je 0x51cfb4
    if (cpu.flags.zf)
    {
        goto L_0x0051cfb4;
    }
    // 0051cfa2  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cfa4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051cfa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051cfa8  740a                   -je 0x51cfb4
    if (cpu.flags.zf)
    {
        goto L_0x0051cfb4;
    }
    // 0051cfaa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051cfae  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051cfb2  75d0                   -jne 0x51cf84
    if (!cpu.flags.zf)
    {
        goto L_0x0051cf84;
    }
L_0x0051cfb4:
    // 0051cfb4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051cfb8  80781f00               +cmp byte ptr [eax + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051cfbc  7514                   -jne 0x51cfd2
    if (!cpu.flags.zf)
    {
        goto L_0x0051cfd2;
    }
    // 0051cfbe  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051cfc0  7410                   -je 0x51cfd2
    if (cpu.flags.zf)
    {
        goto L_0x0051cfd2;
    }
    // 0051cfc2  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0051cfc5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051cfc7  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0051cfca  e821d5fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051cfcf  897724                 -mov dword ptr [edi + 0x24], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0051cfd2:
    // 0051cfd2  833c2400               +cmp dword ptr [esp], 0
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
    // 0051cfd6  741b                   -je 0x51cff3
    if (cpu.flags.zf)
    {
        goto L_0x0051cff3;
    }
    // 0051cfd8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051cfdd  83c40c                 +add esp, 0xc
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
    // 0051cfe0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cfe6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051cfe7:
    // 0051cfe7  c7472400000000         -mov dword ptr [edi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051cfee  e965ffffff             -jmp 0x51cf58
    goto L_0x0051cf58;
L_0x0051cff3:
    // 0051cff3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051cff5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051cff8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cff9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cffb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cffc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cffd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051cffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51d000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d000  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051d003  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_51d010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d010  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051d013  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051d015  7e0f                   -jle 0x51d026
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051d026;
    }
    // 0051d017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051d018  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051d01b  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0051d01e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051d020  7e0a                   -jle 0x51d02c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051d02c;
    }
    // 0051d022  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d024  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d025  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d026:
    // 0051d026  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d02b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d02c:
    // 0051d02c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d032  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51d040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d040  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0051d044  0f8ea6f8ffff           -jle 0x51c8f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_51c8f0(app, cpu);
    }
    // 0051d04a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d04f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51d050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051d051  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051d052  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051d053  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051d054  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051d055  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051d056  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051d058  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051d05b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0051d05e  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051d061  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0051d064  8b15ec6d5600           -mov edx, dword ptr [0x566dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051d06a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0051d06d  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d070  0f8d68010000           -jge 0x51d1de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051d1de;
    }
L_0x0051d076:
    // 0051d076  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051d079  c7472800000000         -mov dword ptr [edi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0051d080  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051d084  0f844b010000           -je 0x51d1d5
    if (cpu.flags.zf)
    {
        goto L_0x0051d1d5;
    }
    // 0051d08a  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0051d090  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0051d093  8d4754                 -lea eax, [edi + 0x54]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 0051d096  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0051d099  8d4778                 -lea eax, [edi + 0x78]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0051d09c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0051d09f  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0051d0a2  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0051d0a5:
    // 0051d0a5  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0051d0a8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051d0ab  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051d0ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d0b0  0f8545010000           -jne 0x51d1fb
    if (!cpu.flags.zf)
    {
        goto L_0x0051d1fb;
    }
L_0x0051d0b6:
    // 0051d0b6  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0051d0b9  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0051d0bc  8b5770                 -mov edx, dword ptr [edi + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 0051d0bf  e83c17ffff             -call 0x50e800
    cpu.esp -= 4;
    sub_50e800(app, cpu);
    if (cpu.terminate) return;
    // 0051d0c4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051d0c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d0c8  0f8485000000           -je 0x51d153
    if (cpu.flags.zf)
    {
        goto L_0x0051d153;
    }
L_0x0051d0ce:
    // 0051d0ce  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d0d5  7c1d                   -jl 0x51d0f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d0f4;
    }
    // 0051d0d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d0d9  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d0dc  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0051d0df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d0e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d0e2  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051d0e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d0e7  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d0ea  b81c105500             -mov eax, 0x55101c
    cpu.eax = 5574684 /*0x55101c*/;
    // 0051d0ef  e88c50ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d0f4:
    // 0051d0f4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051d0f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d0f9  8d5612                 -lea edx, [esi + 0x12]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0051d0fc  8a5e0d                 -mov bl, byte ptr [esi + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d0ff  e8ec55ffff             -call 0x5126f0
    cpu.esp -= 4;
    sub_5126f0(app, cpu);
    if (cpu.terminate) return;
    // 0051d104  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d106  0f84fb000000           -je 0x51d207
    if (cpu.flags.zf)
    {
        goto L_0x0051d207;
    }
    // 0051d10c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051d10f  e80c19ffff             -call 0x50ea20
    cpu.esp -= 4;
    sub_50ea20(app, cpu);
    if (cpu.terminate) return;
    // 0051d114  8b5774                 -mov edx, dword ptr [edi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */);
    // 0051d117  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0051d11a  894f74                 -mov dword ptr [edi + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0051d11d  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0051d120  ff4770                 -inc dword ptr [edi + 0x70]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */))++;
    // 0051d123  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051d125  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051d128  e81319ffff             -call 0x50ea40
    cpu.esp -= 4;
    sub_50ea40(app, cpu);
    if (cpu.terminate) return;
    // 0051d12d  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0051d130  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d132  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051d139  e8620fffff             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051d13e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051d141  8b5770                 -mov edx, dword ptr [edi + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 0051d144  e8b716ffff             -call 0x50e800
    cpu.esp -= 4;
    sub_50e800(app, cpu);
    if (cpu.terminate) return;
    // 0051d149  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051d14b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d14d  0f857bffffff           -jne 0x51d0ce
    if (!cpu.flags.zf)
    {
        goto L_0x0051d0ce;
    }
L_0x0051d153:
    // 0051d153  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d157  0f8548ffffff           -jne 0x51d0a5
    if (!cpu.flags.zf)
    {
        goto L_0x0051d0a5;
    }
    // 0051d15d  807f0e00               +cmp byte ptr [edi + 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051d161  0f85d6000000           -jne 0x51d23d
    if (!cpu.flags.zf)
    {
        goto L_0x0051d23d;
    }
    // 0051d167  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0051d16d  e85e11ffff             -call 0x50e2d0
    cpu.esp -= 4;
    sub_50e2d0(app, cpu);
    if (cpu.terminate) return;
    // 0051d172  83f8ff                 +cmp eax, -1
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
    // 0051d175  0f84bb000000           -je 0x51d236
    if (cpu.flags.zf)
    {
        goto L_0x0051d236;
    }
    // 0051d17b  3b4770                 +cmp eax, dword ptr [edi + 0x70]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d17e  0f84b2000000           -je 0x51d236
    if (cpu.flags.zf)
    {
        goto L_0x0051d236;
    }
    // 0051d184  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051d189:
    // 0051d189  c6470e01               -mov byte ptr [edi + 0xe], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
L_0x0051d18d:
    // 0051d18d  837f2800               +cmp dword ptr [edi + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d191  0f84ad000000           -je 0x51d244
    if (cpu.flags.zf)
    {
        goto L_0x0051d244;
    }
L_0x0051d197:
    // 0051d197  833dec6d560004         +cmp dword ptr [0x566dec], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d19e  7c23                   -jl 0x51d1c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d1c3;
    }
    // 0051d1a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d1a2  8b7728                 -mov esi, dword ptr [edi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0051d1a5  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d1a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d1aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d1ab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d1ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d1af  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051d1b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051d1b3  0f849c000000           -je 0x51d255
    if (cpu.flags.zf)
    {
        goto L_0x0051d255;
    }
    // 0051d1b9  b82c105500             -mov eax, 0x55102c
    cpu.eax = 5574700 /*0x55102c*/;
L_0x0051d1be:
    // 0051d1be  e8bd4fffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d1c3:
    // 0051d1c3  8d4778                 -lea eax, [edi + 0x78]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0051d1c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d1c8  e8a312ffff             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 0051d1cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d1cf  0f858a000000           -jne 0x51d25f
    if (!cpu.flags.zf)
    {
        goto L_0x0051d25f;
    }
L_0x0051d1d5:
    // 0051d1d5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051d1d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d1dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d1de:
    // 0051d1de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d1e0  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d1e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d1e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d1e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d1e8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d1ea  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051d1ec  b810105500             -mov eax, 0x551010
    cpu.eax = 5574672 /*0x551010*/;
    // 0051d1f1  e88a4fffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051d1f6  e97bfeffff             -jmp 0x51d076
    goto L_0x0051d076;
L_0x0051d1fb:
    // 0051d1fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d1fd  e82efdffff             -call 0x51cf30
    cpu.esp -= 4;
    sub_51cf30(app, cpu);
    if (cpu.terminate) return;
    // 0051d202  e9affeffff             -jmp 0x51d0b6
    goto L_0x0051d0b6;
L_0x0051d207:
    // 0051d207  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d20e  7c17                   -jl 0x51d227
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d227;
    }
    // 0051d210  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d213  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d214  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051d217  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d219  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051d21b  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051d21d  b824105500             -mov eax, 0x551024
    cpu.eax = 5574692 /*0x551024*/;
    // 0051d222  e8594fffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d227:
    // 0051d227  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0051d22a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d22c  e86f0effff             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051d231  e91dffffff             -jmp 0x51d153
    goto L_0x0051d153;
L_0x0051d236:
    // 0051d236  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051d238  e94cffffff             -jmp 0x51d189
    goto L_0x0051d189;
L_0x0051d23d:
    // 0051d23d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051d23f  e949ffffff             -jmp 0x51d18d
    goto L_0x0051d18d;
L_0x0051d244:
    // 0051d244  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d246  0f854bffffff           -jne 0x51d197
    if (!cpu.flags.zf)
    {
        goto L_0x0051d197;
    }
    // 0051d24c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051d24e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d24f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d251  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d252  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d253  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d254  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d255:
    // 0051d255  b834105500             -mov eax, 0x551034
    cpu.eax = 5574708 /*0x551034*/;
    // 0051d25a  e95fffffff             -jmp 0x51d1be
    goto L_0x0051d1be;
L_0x0051d25f:
    // 0051d25f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051d261  e88af8ffff             -call 0x51caf0
    cpu.esp -= 4;
    sub_51caf0(app, cpu);
    if (cpu.terminate) return;
    // 0051d266  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051d268  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d26a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d26b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d26c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d26d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d26e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51d270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d270  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051d271  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051d272  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051d273  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0051d276  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051d278  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0051d27c  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d280  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d282  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0051d286  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0051d28a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0051d28e  83fd06                 +cmp ebp, 6
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d291  0f8c47020000           -jl 0x51d4de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d4de;
    }
    // 0051d297  81fdfa000000           +cmp ebp, 0xfa
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d29d  0f8e48020000           -jle 0x51d4eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051d4eb;
    }
    // 0051d2a3  bd3c105500             -mov ebp, 0x55103c
    cpu.ebp = 5574716 /*0x55103c*/;
    // 0051d2a8  68fa000000             -push 0xfa
    app->getMemory<x86::reg32>(cpu.esp-4) = 250 /*0xfa*/;
    cpu.esp -= 4;
    // 0051d2ad  b84c105500             -mov eax, 0x55104c
    cpu.eax = 5574732 /*0x55104c*/;
    // 0051d2b2  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 0051d2b7  6864105500             -push 0x551064
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574756 /*0x551064*/;
    cpu.esp -= 4;
    // 0051d2bc  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0051d2c2  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0051d2c7  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0051d2cd  e83e3deeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d2d2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0051d2d5:
    // 0051d2d5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051d2d7  7433                   -je 0x51d30c
    if (cpu.flags.zf)
    {
        goto L_0x0051d30c;
    }
    // 0051d2d9  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d2dd  742d                   -je 0x51d30c
    if (cpu.flags.zf)
    {
        goto L_0x0051d30c;
    }
    // 0051d2df  bd3c105500             -mov ebp, 0x55103c
    cpu.ebp = 5574716 /*0x55103c*/;
    // 0051d2e4  b84c105500             -mov eax, 0x55104c
    cpu.eax = 5574732 /*0x55104c*/;
    // 0051d2e9  ba0a020000             -mov edx, 0x20a
    cpu.edx = 522 /*0x20a*/;
    // 0051d2ee  68f4105500             -push 0x5510f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574900 /*0x5510f4*/;
    cpu.esp -= 4;
    // 0051d2f3  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0051d2f9  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0051d2fe  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0051d304  e8073deeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d309  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051d30c:
    // 0051d30c  83f902                 +cmp ecx, 2
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
    // 0051d30f  0f8d26020000           -jge 0x51d53b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051d53b;
    }
    // 0051d315  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x0051d31a:
    // 0051d31a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051d31e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d320  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d324  8a421e                 -mov al, byte ptr [edx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 0051d327  39d8                   +cmp eax, ebx
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
    // 0051d329  7e04                   -jle 0x51d32f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051d32f;
    }
    // 0051d32b  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0051d32f:
    // 0051d32f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051d334  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0051d336  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051d338  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051d33b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d33d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0051d33f  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0051d342  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 0051d347  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051d34b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0051d34f  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0051d352  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0051d356  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0051d358  7508                   -jne 0x51d362
    if (!cpu.flags.zf)
    {
        goto L_0x0051d362;
    }
    // 0051d35a  c744240800020000       -mov dword ptr [esp + 8], 0x200
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 512 /*0x200*/;
L_0x0051d362:
    // 0051d362  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0051d366  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0051d369  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051d36b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d36f  83c015                 -add eax, 0x15
    (cpu.eax) += x86::reg32(x86::sreg32(21 /*0x15*/));
    // 0051d372  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0051d374  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051d377  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051d37b  05b0000000             -add eax, 0xb0
    (cpu.eax) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 0051d380  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051d382  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051d384  0f84c4010000           -je 0x51d54e
    if (cpu.flags.zf)
    {
        goto L_0x0051d54e;
    }
    // 0051d38a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0051d38d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051d38f  0f85c4010000           -jne 0x51d559
    if (!cpu.flags.zf)
    {
        goto L_0x0051d559;
    }
    // 0051d395  bb3c105500             -mov ebx, 0x55103c
    cpu.ebx = 5574716 /*0x55103c*/;
    // 0051d39a  bf4c105500             -mov edi, 0x55104c
    cpu.edi = 5574732 /*0x55104c*/;
    // 0051d39f  ba2b020000             -mov edx, 0x22b
    cpu.edx = 555 /*0x22b*/;
    // 0051d3a4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0051d3a9  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0051d3af  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0051d3b5  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0051d3bb  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0051d3c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051d3c3  b82c115500             -mov eax, 0x55112c
    cpu.eax = 5574956 /*0x55112c*/;
    // 0051d3c8  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0051d3cc  e84f42fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051d3d1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0051d3d3:
    // 0051d3d3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051d3d5  0f844a030000           -je 0x51d725
    if (cpu.flags.zf)
    {
        goto L_0x0051d725;
    }
    // 0051d3db  8d8fb0000000           -lea ecx, [edi + 0xb0]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(176) /* 0xb0 */);
    // 0051d3e1  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0051d3e7  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051d3ee  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0051d3f1  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0051d3f4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051d3f8  c74618b0504f00         -mov dword ptr [esi + 0x18], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 5198000 /*0x4f50b0*/;
    // 0051d3ff  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d403  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0051d405  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051d408  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d40a  668b462a               -mov ax, word ptr [esi + 0x2a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 0051d40e  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0051d411  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051d415  88470c                 -mov byte ptr [edi + 0xc], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0051d418  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051d41c  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051d41f  a124ac5600             -mov eax, dword ptr [0x56ac24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680164) /* 0x56ac24 */);
    // 0051d424  88470d                 -mov byte ptr [edi + 0xd], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0051d427  40                     -inc eax
    (cpu.eax)++;
    // 0051d428  a324ac5600             -mov dword ptr [0x56ac24], eax
    app->getMemory<x86::reg32>(x86::reg32(5680164) /* 0x56ac24 */) = cpu.eax;
    // 0051d42d  c7471000000000         -mov dword ptr [edi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0051d434  e8a7defcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0051d439  c7473001000000         -mov dword ptr [edi + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0051d440  c7473400000000         -mov dword ptr [edi + 0x34], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 0051d447  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d449  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0051d44c  8d4738                 -lea eax, [edi + 0x38]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 0051d44f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d451  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051d454  e87708ffff             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 0051d459  8d4754                 -lea eax, [edi + 0x54]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 0051d45c  ba00d05100             -mov edx, 0x51d000
    cpu.edx = 5361664 /*0x51d000*/;
    // 0051d461  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051d463  e86808ffff             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 0051d468  ba00d05100             -mov edx, 0x51d000
    cpu.edx = 5361664 /*0x51d000*/;
    // 0051d46d  8d4778                 -lea eax, [edi + 0x78]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0051d470  c7477001000000         -mov dword ptr [edi + 0x70], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */) = 1 /*0x1*/;
    // 0051d477  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051d479  c7477401000000         -mov dword ptr [edi + 0x74], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */) = 1 /*0x1*/;
    // 0051d480  e84b08ffff             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 0051d485  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0051d48b  ba00d05100             -mov edx, 0x51d000
    cpu.edx = 5361664 /*0x51d000*/;
    // 0051d490  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051d492  e83908ffff             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 0051d497  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d49b  83c015                 -add eax, 0x15
    (cpu.eax) += x86::reg32(x86::sreg32(21 /*0x15*/));
    // 0051d49e  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0051d4a0  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051d4a3  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0051d4a7:
    // 0051d4a7  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0051d4ab  48                     -dec eax
    (cpu.eax)--;
    // 0051d4ac  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0051d4b0  83f8ff                 +cmp eax, -1
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
    // 0051d4b3  0f84a7000000           -je 0x51d560
    if (cpu.flags.zf)
    {
        goto L_0x0051d560;
    }
    // 0051d4b9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051d4bb  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0051d4c1  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051d4c5  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051d4cc  01c1                   +add ecx, eax
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
    // 0051d4ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051d4d0  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051d4d7  e87409ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051d4dc  ebc9                   -jmp 0x51d4a7
    goto L_0x0051d4a7;
L_0x0051d4de:
    // 0051d4de  c744241406000000       -mov dword ptr [esp + 0x14], 6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 6 /*0x6*/;
    // 0051d4e6  e9eafdffff             -jmp 0x51d2d5
    goto L_0x0051d2d5;
L_0x0051d4eb:
    // 0051d4eb  668b5a1c               -mov bx, word ptr [edx + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0051d4ef  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 0051d4f2  0f84ddfdffff           -je 0x51d2d5
    if (cpu.flags.zf)
    {
        goto L_0x0051d2d5;
    }
    // 0051d4f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d4fa  8d5506                 -lea edx, [ebp + 6]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0051d4fd  6689d8                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051d500  39c2                   +cmp edx, eax
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
    // 0051d502  0f86cdfdffff           -jbe 0x51d2d5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051d2d5;
    }
    // 0051d508  ba3c105500             -mov edx, 0x55103c
    cpu.edx = 5574716 /*0x55103c*/;
    // 0051d50d  bb4c105500             -mov ebx, 0x55104c
    cpu.ebx = 5574732 /*0x55104c*/;
    // 0051d512  bf07020000             -mov edi, 0x207
    cpu.edi = 519 /*0x207*/;
    // 0051d517  68a4105500             -push 0x5510a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574820 /*0x5510a4*/;
    cpu.esp -= 4;
    // 0051d51c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0051d522  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051d528  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0051d52e  e8dd3aeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d533  83c404                 +add esp, 4
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
    // 0051d536  e99afdffff             -jmp 0x51d2d5
    goto L_0x0051d2d5;
L_0x0051d53b:
    // 0051d53b  83f907                 +cmp ecx, 7
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
    // 0051d53e  0f8ed6fdffff           -jle 0x51d31a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051d31a;
    }
    // 0051d544  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0051d549  e9ccfdffff             -jmp 0x51d31a
    goto L_0x0051d31a;
L_0x0051d54e:
    // 0051d54e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051d550  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051d552  83c42c                 +add esp, 0x2c
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
    // 0051d555  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d556  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d557  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d559:
    // 0051d559  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0051d55b  e973feffff             -jmp 0x51d3d3
    goto L_0x0051d3d3;
L_0x0051d560:
    // 0051d560  8d4778                 -lea eax, [edi + 0x78]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0051d563  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0051d567  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051d56b  83c015                 -add eax, 0x15
    (cpu.eax) += x86::reg32(x86::sreg32(21 /*0x15*/));
    // 0051d56e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0051d572:
    // 0051d572  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051d576  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0051d578  4d                     -dec ebp
    (cpu.ebp)--;
    // 0051d579  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d57b  83fdff                 +cmp ebp, -1
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
    // 0051d57e  7428                   -je 0x51d5a8
    if (cpu.flags.zf)
    {
        goto L_0x0051d5a8;
    }
    // 0051d580  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051d582  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0051d588  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051d58a  8b4774                 -mov eax, dword ptr [edi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */);
    // 0051d58d  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051d590  895f74                 -mov dword ptr [edi + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0051d593  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051d596  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051d59a  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051d5a1  e8fa0affff             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051d5a6  ebca                   -jmp 0x51d572
    goto L_0x0051d572;
L_0x0051d5a8:
    // 0051d5a8  c7472400000000         -mov dword ptr [edi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051d5af  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0051d5b2  894f18                 -mov dword ptr [edi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0051d5b5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051d5b9  8b15f06d5600           -mov edx, dword ptr [0x566df0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051d5bf  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0051d5c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051d5c4  752e                   -jne 0x51d5f4
    if (!cpu.flags.zf)
    {
        goto L_0x0051d5f4;
    }
    // 0051d5c6  b93c105500             -mov ecx, 0x55103c
    cpu.ecx = 5574716 /*0x55103c*/;
    // 0051d5cb  bb4c105500             -mov ebx, 0x55104c
    cpu.ebx = 5574732 /*0x55104c*/;
    // 0051d5d0  bd76020000             -mov ebp, 0x276
    cpu.ebp = 630 /*0x276*/;
    // 0051d5d5  6834115500             -push 0x551134
    app->getMemory<x86::reg32>(cpu.esp-4) = 5574964 /*0x551134*/;
    cpu.esp -= 4;
    // 0051d5da  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0051d5e0  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051d5e6  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0051d5ec  e81f3aeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d5f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051d5f4:
    // 0051d5f4  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051d5f8  ba50d05100             -mov edx, 0x51d050
    cpu.edx = 5361744 /*0x51d050*/;
    // 0051d5fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051d5ff  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051d601  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d603  0f8475010000           -je 0x51d77e
    if (cpu.flags.zf)
    {
        goto L_0x0051d77e;
    }
    // 0051d609  c7462400ca9a3b         -mov dword ptr [esi + 0x24], 0x3b9aca00
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 1000000000 /*0x3b9aca00*/;
    // 0051d610  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051d615  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d617  e83408ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 0051d61c  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d623  0f8d12010000           -jge 0x51d73b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051d73b;
    }
L_0x0051d629:
    // 0051d629  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0051d62b:
    // 0051d62b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051d62d  e8fe22fcff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 0051d632  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d634  0f841e010000           -je 0x51d758
    if (cpu.flags.zf)
    {
        goto L_0x0051d758;
    }
    // 0051d63a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d63f  e8dca0fcff             -call 0x4e7720
    cpu.esp -= 4;
    sub_4e7720(app, cpu);
    if (cpu.terminate) return;
    // 0051d644  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d646  7c0d                   -jl 0x51d655
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d655;
    }
L_0x0051d648:
    // 0051d648  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051d64a  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051d64d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d64f  0f8412010000           -je 0x51d767
    if (cpu.flags.zf)
    {
        goto L_0x0051d767;
    }
L_0x0051d655:
    // 0051d655  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0051d65a:
    // 0051d65a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0051d65e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051d660  7420                   -je 0x51d682
    if (cpu.flags.zf)
    {
        goto L_0x0051d682;
    }
    // 0051d662  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d669  7c17                   -jl 0x51d682
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d682;
    }
    // 0051d66b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d66d  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d670  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d671  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0051d673  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0051d675  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051d676  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0051d678  b868115500             -mov eax, 0x551168
    cpu.eax = 5575016 /*0x551168*/;
    // 0051d67d  e8fe4affff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d682:
    // 0051d682  3b6e24                 +cmp ebp, dword ptr [esi + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d685  7407                   -je 0x51d68e
    if (cpu.flags.zf)
    {
        goto L_0x0051d68e;
    }
    // 0051d687  c7462400ca9a3b         -mov dword ptr [esi + 0x24], 0x3b9aca00
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 1000000000 /*0x3b9aca00*/;
L_0x0051d68e:
    // 0051d68e  3b6e24                 +cmp ebp, dword ptr [esi + 0x24]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d691  740d                   -je 0x51d6a0
    if (cpu.flags.zf)
    {
        goto L_0x0051d6a0;
    }
    // 0051d693  8b5710                 -mov edx, dword ptr [edi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0051d696  39d5                   +cmp ebp, edx
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
    // 0051d698  7506                   -jne 0x51d6a0
    if (!cpu.flags.zf)
    {
        goto L_0x0051d6a0;
    }
    // 0051d69a  3b542424               +cmp edx, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d69e  748b                   -je 0x51d62b
    if (cpu.flags.zf)
    {
        goto L_0x0051d62b;
    }
L_0x0051d6a0:
    // 0051d6a0  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d6a4  0f85c4000000           -jne 0x51d76e
    if (!cpu.flags.zf)
    {
        goto L_0x0051d76e;
    }
L_0x0051d6aa:
    // 0051d6aa  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0051d6ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d6af  751f                   -jne 0x51d6d0
    if (!cpu.flags.zf)
    {
        goto L_0x0051d6d0;
    }
    // 0051d6b1  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d6b8  7c16                   -jl 0x51d6d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d6d0;
    }
    // 0051d6ba  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d6bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d6be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d6c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d6c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d6c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d6c6  b878115500             -mov eax, 0x551178
    cpu.eax = 5575032 /*0x551178*/;
    // 0051d6cb  e8b04affff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d6d0:
    // 0051d6d0  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0051d6d7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051d6db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051d6dd  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051d6e0:
    // 0051d6e0  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d6e4  0f84be000000           -je 0x51d7a8
    if (cpu.flags.zf)
    {
        goto L_0x0051d7a8;
    }
    // 0051d6ea  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051d6ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051d6f0  0f85b2000000           -jne 0x51d7a8
    if (!cpu.flags.zf)
    {
        goto L_0x0051d7a8;
    }
    // 0051d6f6  a1f06d5600             -mov eax, dword ptr [0x566df0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664240) /* 0x566df0 */);
    // 0051d6fb  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0051d6fe  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051d702  8b15ec6d5600           -mov edx, dword ptr [0x566dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051d708  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0051d70b  83fa01                 +cmp edx, 1
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
    // 0051d70e  7c15                   -jl 0x51d725
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d725;
    }
    // 0051d710  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d712  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d715  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d716  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d718  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051d719  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d71b  b898115500             -mov eax, 0x551198
    cpu.eax = 5575064 /*0x551198*/;
    // 0051d720  e85b4affff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d725:
    // 0051d725  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051d727  0f84c9000000           -je 0x51d7f6
    if (cpu.flags.zf)
    {
        goto L_0x0051d7f6;
    }
    // 0051d72d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051d732  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051d734  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0051d737  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d739  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d73a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d73b:
    // 0051d73b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d73d  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d740  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d741  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d743  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d745  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d747  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051d749  b85c115500             -mov eax, 0x55115c
    cpu.eax = 5575004 /*0x55115c*/;
    // 0051d74e  e82d4affff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051d753  e9d1feffff             -jmp 0x51d629
    goto L_0x0051d629;
L_0x0051d758:
    // 0051d758  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d75d  e87e21fcff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051d762  e9e1feffff             -jmp 0x51d648
    goto L_0x0051d648;
L_0x0051d767:
    // 0051d767  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0051d769  e9ecfeffff             -jmp 0x51d65a
    goto L_0x0051d65a;
L_0x0051d76e:
    // 0051d76e  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 0051d773  0f8531ffffff           -jne 0x51d6aa
    if (!cpu.flags.zf)
    {
        goto L_0x0051d6aa;
    }
    // 0051d779  e962ffffff             -jmp 0x51d6e0
    goto L_0x0051d6e0;
L_0x0051d77e:
    // 0051d77e  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d785  0f8c55ffffff           -jl 0x51d6e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d6e0;
    }
    // 0051d78b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d78d  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d790  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d791  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d793  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d795  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d797  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051d799  b888115500             -mov eax, 0x551188
    cpu.eax = 5575048 /*0x551188*/;
    // 0051d79e  e8dd49ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051d7a3  e938ffffff             -jmp 0x51d6e0
    goto L_0x0051d6e0;
L_0x0051d7a8:
    // 0051d7a8  833dec6d560001         +cmp dword ptr [0x566dec], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d7af  7c18                   -jl 0x51d7c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d7c9;
    }
    // 0051d7b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d7b3  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0051d7b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d7b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d7b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d7bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d7bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d7bf  b8ac115500             -mov eax, 0x5511ac
    cpu.eax = 5575084 /*0x5511ac*/;
    // 0051d7c4  e8b749ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d7c9:
    // 0051d7c9  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051d7ce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d7d0  e87b09ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051d7d5  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051d7da  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d7dc  e86f09ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051d7e1  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 0051d7e6  740e                   -je 0x51d7f6
    if (cpu.flags.zf)
    {
        goto L_0x0051d7f6;
    }
    // 0051d7e8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d7ea  e8a140fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051d7ef  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0051d7f6:
    // 0051d7f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d7f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051d7fa  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0051d7fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d7fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d7ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51d810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051d811  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051d812  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051d813  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051d814  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0051d816  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d818  7406                   -je 0x51d820
    if (cpu.flags.zf)
    {
        goto L_0x0051d820;
    }
    // 0051d81a  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051d81e  7507                   -jne 0x51d827
    if (!cpu.flags.zf)
    {
        goto L_0x0051d827;
    }
L_0x0051d820:
    // 0051d820  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d822  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d823  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d824  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d825  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d826  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d827:
    // 0051d827  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051d82a  8d4638                 -lea eax, [esi + 0x38]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0051d82d  e82e07ffff             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 0051d832  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0051d835  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051d837  39e9                   +cmp ecx, ebp
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
    // 0051d839  762d                   -jbe 0x51d868
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051d868;
    }
    // 0051d83b  b83c105500             -mov eax, 0x55103c
    cpu.eax = 5574716 /*0x55103c*/;
    // 0051d840  bbc0115500             -mov ebx, 0x5511c0
    cpu.ebx = 5575104 /*0x5511c0*/;
    // 0051d845  bdba020000             -mov ebp, 0x2ba
    cpu.ebp = 698 /*0x2ba*/;
    // 0051d84a  68d4115500             -push 0x5511d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575124 /*0x5511d4*/;
    cpu.esp -= 4;
    // 0051d84f  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 0051d854  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051d85a  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0051d860  e8ab37eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d865  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051d868:
    // 0051d868  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051d86a  7526                   -jne 0x51d892
    if (!cpu.flags.zf)
    {
        goto L_0x0051d892;
    }
    // 0051d86c  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d873  7cab                   -jl 0x51d820
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d820;
    }
    // 0051d875  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d877  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d87a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d87b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051d87d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051d87f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d881  b85c125500             -mov eax, 0x55125c
    cpu.eax = 5575260 /*0x55125c*/;
    // 0051d886  e8f548ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051d88b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d88d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d88e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d88f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d890  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d891  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d892:
    // 0051d892  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051d894  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d896  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d898  e8f3efffff             -call 0x51c890
    cpu.esp -= 4;
    sub_51c890(app, cpu);
    if (cpu.terminate) return;
    // 0051d89d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d89f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d8a1  e84af0ffff             -call 0x51c8f0
    cpu.esp -= 4;
    sub_51c8f0(app, cpu);
    if (cpu.terminate) return;
    // 0051d8a6  8d4654                 -lea eax, [esi + 0x54]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0051d8a9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051d8ab  e8f007ffff             -call 0x50e0a0
    cpu.esp -= 4;
    sub_50e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051d8b0  837e3000               +cmp dword ptr [esi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d8b4  752e                   -jne 0x51d8e4
    if (!cpu.flags.zf)
    {
        goto L_0x0051d8e4;
    }
    // 0051d8b6  b93c105500             -mov ecx, 0x55103c
    cpu.ecx = 5574716 /*0x55103c*/;
    // 0051d8bb  bbc0115500             -mov ebx, 0x5511c0
    cpu.ebx = 5575104 /*0x5511c0*/;
    // 0051d8c0  bec6020000             -mov esi, 0x2c6
    cpu.esi = 710 /*0x2c6*/;
    // 0051d8c5  6808125500             -push 0x551208
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575176 /*0x551208*/;
    cpu.esp -= 4;
    // 0051d8ca  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0051d8d0  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0051d8d6  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0051d8dc  e82f37eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051d8e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0051d8e4:
    // 0051d8e4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d8e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d8ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d8eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d8ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d8ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51d8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051d8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051d8f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051d8f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051d8f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051d8f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051d8f7  8b15ec6d5600           -mov edx, dword ptr [0x566dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051d8fd  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051d900  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d903  7d6a                   -jge 0x51d96f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051d96f;
    }
L_0x0051d905:
    // 0051d905  ff4f24                 -dec dword ptr [edi + 0x24]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */))--;
    // 0051d908  8b5f24                 -mov ebx, dword ptr [edi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051d90b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051d90d  7526                   -jne 0x51d935
    if (!cpu.flags.zf)
    {
        goto L_0x0051d935;
    }
    // 0051d90f  833dec6d560003         +cmp dword ptr [0x566dec], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d916  7c15                   -jl 0x51d92d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d92d;
    }
    // 0051d918  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d91a  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d91d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d91e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051d921  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051d923  b874125500             -mov eax, 0x551274
    cpu.eax = 5575284 /*0x551274*/;
    // 0051d928  e85348ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d92d:
    // 0051d92d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d92f  ff571c                 -call dword ptr [edi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051d932  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0051d935:
    // 0051d935  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d939  7551                   -jne 0x51d98c
    if (!cpu.flags.zf)
    {
        goto L_0x0051d98c;
    }
L_0x0051d93b:
    // 0051d93b  833dec6d560002         +cmp dword ptr [0x566dec], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051d942  7c19                   -jl 0x51d95d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051d95d;
    }
    // 0051d944  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d946  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d949  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d94a  8d5724                 -lea edx, [edi + 0x24]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051d94d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d94f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051d951  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d953  b880125500             -mov eax, 0x551280
    cpu.eax = 5575296 /*0x551280*/;
    // 0051d958  e82348ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x0051d95d:
    // 0051d95d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051d95f  e81cf3ffff             -call 0x51cc80
    cpu.esp -= 4;
    sub_51cc80(app, cpu);
    if (cpu.terminate) return;
L_0x0051d964:
    // 0051d964  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d969  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d96a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d96b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d96c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d96d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d96e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051d96f:
    // 0051d96f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051d971  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0051d974  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051d975  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051d977  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051d979  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051d97b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051d97d  b868125500             -mov eax, 0x551268
    cpu.eax = 5575272 /*0x551268*/;
    // 0051d982  e8f947ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051d987  e979ffffff             -jmp 0x51d905
    goto L_0x0051d905;
L_0x0051d98c:
    // 0051d98c  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051d98f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d991  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051d994  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d996  74a3                   -je 0x51d93b
    if (cpu.flags.zf)
    {
        goto L_0x0051d93b;
    }
    // 0051d998  8d7e54                 -lea edi, [esi + 0x54]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0051d99b  ba10d05100             -mov edx, 0x51d010
    cpu.edx = 5361680 /*0x51d010*/;
    // 0051d9a0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051d9a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d9a4  e80710ffff             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 0051d9a9  ba40d05100             -mov edx, 0x51d040
    cpu.edx = 5361728 /*0x51d040*/;
    // 0051d9ae  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051d9b0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051d9b2  e8290fffff             -call 0x50e8e0
    cpu.esp -= 4;
    sub_50e8e0(app, cpu);
    if (cpu.terminate) return;
    // 0051d9b7  8b462c                 -mov eax, dword ptr [esi + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0051d9ba  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0051d9bd  89562c                 -mov dword ptr [esi + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0051d9c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d9c2  7fa0                   -jg 0x51d964
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051d964;
    }
    // 0051d9c4  bbfb000000             -mov ebx, 0xfb
    cpu.ebx = 251 /*0xfb*/;
    // 0051d9c9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051d9cb  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0051d9ce  e87df0ffff             -call 0x51ca50
    cpu.esp -= 4;
    sub_51ca50(app, cpu);
    if (cpu.terminate) return;
    // 0051d9d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051d9d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d9d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d9da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051d9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51d9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051d9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051d9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051d9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051d9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051d9e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051d9e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051d9e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051d9e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051d9ea  0f84b8000000           -je 0x51daa8
    if (cpu.flags.zf)
    {
        goto L_0x0051daa8;
    }
    // 0051d9f0  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051d9f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051d9f5  0f84ad000000           -je 0x51daa8
    if (cpu.flags.zf)
    {
        goto L_0x0051daa8;
    }
    // 0051d9fb  8b0dec6d5600           -mov ecx, dword ptr [0x566dec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664236) /* 0x566dec */);
    // 0051da01  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051da03  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0051da06  83f901                 +cmp ecx, 1
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
    // 0051da09  7d4c                   -jge 0x51da57
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051da57;
    }
L_0x0051da0b:
    // 0051da0b  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 0051da10  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051da12  e83907ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051da17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051da19  0f8492000000           -je 0x51dab1
    if (cpu.flags.zf)
    {
        goto L_0x0051dab1;
    }
    // 0051da1f  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051da23  7467                   -je 0x51da8c
    if (cpu.flags.zf)
    {
        goto L_0x0051da8c;
    }
    // 0051da25  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0051da2a  c7472400000000         -mov dword ptr [edi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x0051da31:
    // 0051da31  49                     -dec ecx
    (cpu.ecx)--;
    // 0051da32  83f9ff                 +cmp ecx, -1
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
    // 0051da35  7446                   -je 0x51da7d
    if (cpu.flags.zf)
    {
        goto L_0x0051da7d;
    }
    // 0051da37  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051da39  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051da3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051da3e  743d                   -je 0x51da7d
    if (cpu.flags.zf)
    {
        goto L_0x0051da7d;
    }
    // 0051da40  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0051da45  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051da47  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0051da4a  e801f0ffff             -call 0x51ca50
    cpu.esp -= 4;
    sub_51ca50(app, cpu);
    if (cpu.terminate) return;
    // 0051da4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051da51  741e                   -je 0x51da71
    if (cpu.flags.zf)
    {
        goto L_0x0051da71;
    }
    // 0051da53  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0051da55  ebda                   -jmp 0x51da31
    goto L_0x0051da31;
L_0x0051da57:
    // 0051da57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051da59  8a420d                 -mov al, byte ptr [edx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0051da5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051da5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051da5f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051da61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051da63  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051da65  b88c125500             -mov eax, 0x55128c
    cpu.eax = 5575308 /*0x55128c*/;
    // 0051da6a  e81147ffff             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 0051da6f  eb9a                   -jmp 0x51da0b
    goto L_0x0051da0b;
L_0x0051da71:
    // 0051da71  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051da76  e8652cfdff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 0051da7b  ebb4                   -jmp 0x51da31
    goto L_0x0051da31;
L_0x0051da7d:
    // 0051da7d  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0051da82  e8592cfdff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 0051da87  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051da89  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051da8c:
    // 0051da8c  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051da91  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051da93  e8b803ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
L_0x0051da98:
    // 0051da98  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 0051da9d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051da9f  e8ac06ffff             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 0051daa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051daa6  751e                   -jne 0x51dac6
    if (!cpu.flags.zf)
    {
        goto L_0x0051dac6;
    }
L_0x0051daa8:
    // 0051daa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051daaa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051daab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051daac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051daad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051daae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051daaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dab0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051dab1:
    // 0051dab1  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051dab5  74e1                   -je 0x51da98
    if (cpu.flags.zf)
    {
        goto L_0x0051da98;
    }
    // 0051dab7  689c125500             -push 0x55129c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575324 /*0x55129c*/;
    cpu.esp -= 4;
    // 0051dabc  e82f2efcff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 0051dac1  83c404                 +add esp, 4
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
    // 0051dac4  ebd2                   -jmp 0x51da98
    goto L_0x0051da98;
L_0x0051dac6:
    // 0051dac6  8d4638                 -lea eax, [esi + 0x38]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0051dac9  e81203ffff             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 0051dace  8d4654                 -lea eax, [esi + 0x54]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0051dad1  e80a03ffff             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 0051dad6  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0051dad9  e80203ffff             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 0051dade  8d8694000000           -lea eax, [esi + 0x94]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0051dae4  e8f702ffff             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 0051dae9  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0051daec  e86fd8fcff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0051daf1  807e0c00               +cmp byte ptr [esi + 0xc], 0
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
    // 0051daf5  740e                   -je 0x51db05
    if (cpu.flags.zf)
    {
        goto L_0x0051db05;
    }
    // 0051daf7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051daf9  e8923dfcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051dafe  c7471000000000         -mov dword ptr [edi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0051db05:
    // 0051db05  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051db0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_51db20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051db20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051db21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051db22  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051db25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051db27  7415                   -je 0x51db3e
    if (cpu.flags.zf)
    {
        goto L_0x0051db3e;
    }
    // 0051db29  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051db2d  740f                   -je 0x51db3e
    if (cpu.flags.zf)
    {
        goto L_0x0051db3e;
    }
    // 0051db2f  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051db32  833b00                 +cmp dword ptr [ebx], 0
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
    // 0051db35  7507                   -jne 0x51db3e
    if (!cpu.flags.zf)
    {
        goto L_0x0051db3e;
    }
    // 0051db37  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051db3a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051db3c  7506                   -jne 0x51db44
    if (!cpu.flags.zf)
    {
        goto L_0x0051db44;
    }
L_0x0051db3e:
    // 0051db3e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051db41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051db44:
    // 0051db44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051db45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051db46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051db47  8b7b30                 -mov edi, dword ptr [ebx + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0051db4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051db4b  68e0125500             -push 0x5512e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575392 /*0x5512e0*/;
    cpu.esp -= 4;
    // 0051db50  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051db54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051db55  e8361bfcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051db5a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051db5d  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051db61  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051db63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051db64  2bc9                   +sub ecx, ecx
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
    // 0051db66  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051db67  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051db69  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051db6b  4f                     -dec edi
    (cpu.edi)--;
L_0x0051db6c:
    // 0051db6c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051db6e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051db70  3c00                   +cmp al, 0
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
    // 0051db72  7410                   -je 0x51db84
    if (cpu.flags.zf)
    {
        goto L_0x0051db84;
    }
    // 0051db74  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051db77  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051db7a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051db7d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051db80  3c00                   +cmp al, 0
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
    // 0051db82  75e8                   -jne 0x51db6c
    if (!cpu.flags.zf)
    {
        goto L_0x0051db6c;
    }
L_0x0051db84:
    // 0051db84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051db85  8b6b34                 -mov ebp, dword ptr [ebx + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 0051db88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051db89  68f0125500             -push 0x5512f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575408 /*0x5512f0*/;
    cpu.esp -= 4;
    // 0051db8e  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051db92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051db93  e8f81afcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051db98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051db9b  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051db9f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dba0  2bc9                   +sub ecx, ecx
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
    // 0051dba2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dba3  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dba5  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dba7  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dba8:
    // 0051dba8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dbaa  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dbac  3c00                   +cmp al, 0
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
    // 0051dbae  7410                   -je 0x51dbc0
    if (cpu.flags.zf)
    {
        goto L_0x0051dbc0;
    }
    // 0051dbb0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dbb3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dbb6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dbb9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dbbc  3c00                   +cmp al, 0
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
    // 0051dbbe  75e8                   -jne 0x51dba8
    if (!cpu.flags.zf)
    {
        goto L_0x0051dba8;
    }
L_0x0051dbc0:
    // 0051dbc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dbc1  8d4338                 -lea eax, [ebx + 0x38]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(56) /* 0x38 */);
    // 0051dbc4  e80706ffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 0051dbc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dbca  6800135500             -push 0x551300
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575424 /*0x551300*/;
    cpu.esp -= 4;
    // 0051dbcf  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dbd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dbd4  e8b71afcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dbd9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dbdc  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dbe0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dbe1  2bc9                   +sub ecx, ecx
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
    // 0051dbe3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dbe4  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dbe6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dbe8  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dbe9:
    // 0051dbe9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dbeb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dbed  3c00                   +cmp al, 0
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
    // 0051dbef  7410                   -je 0x51dc01
    if (cpu.flags.zf)
    {
        goto L_0x0051dc01;
    }
    // 0051dbf1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dbf4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dbf7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dbfa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dbfd  3c00                   +cmp al, 0
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
    // 0051dbff  75e8                   -jne 0x51dbe9
    if (!cpu.flags.zf)
    {
        goto L_0x0051dbe9;
    }
L_0x0051dc01:
    // 0051dc01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dc02  8d4354                 -lea eax, [ebx + 0x54]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0051dc05  e8c605ffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 0051dc0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dc0b  6810135500             -push 0x551310
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575440 /*0x551310*/;
    cpu.esp -= 4;
    // 0051dc10  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dc14  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dc15  e8761afcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dc1a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dc1d  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dc21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dc22  2bc9                   +sub ecx, ecx
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
    // 0051dc24  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dc25  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dc27  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dc29  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dc2a:
    // 0051dc2a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dc2c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dc2e  3c00                   +cmp al, 0
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
    // 0051dc30  7410                   -je 0x51dc42
    if (cpu.flags.zf)
    {
        goto L_0x0051dc42;
    }
    // 0051dc32  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dc35  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dc38  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dc3b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dc3e  3c00                   +cmp al, 0
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
    // 0051dc40  75e8                   -jne 0x51dc2a
    if (!cpu.flags.zf)
    {
        goto L_0x0051dc2a;
    }
L_0x0051dc42:
    // 0051dc42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dc43  8b4370                 -mov eax, dword ptr [ebx + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0051dc46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dc47  6820135500             -push 0x551320
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575456 /*0x551320*/;
    cpu.esp -= 4;
    // 0051dc4c  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dc50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dc51  e83a1afcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dc56  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dc59  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dc5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dc5e  2bc9                   +sub ecx, ecx
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
    // 0051dc60  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dc61  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dc63  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dc65  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dc66:
    // 0051dc66  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dc68  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dc6a  3c00                   +cmp al, 0
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
    // 0051dc6c  7410                   -je 0x51dc7e
    if (cpu.flags.zf)
    {
        goto L_0x0051dc7e;
    }
    // 0051dc6e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dc71  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dc74  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dc77  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dc7a  3c00                   +cmp al, 0
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
    // 0051dc7c  75e8                   -jne 0x51dc66
    if (!cpu.flags.zf)
    {
        goto L_0x0051dc66;
    }
L_0x0051dc7e:
    // 0051dc7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dc7f  8b4b74                 -mov ecx, dword ptr [ebx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(116) /* 0x74 */);
    // 0051dc82  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051dc83  6830135500             -push 0x551330
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575472 /*0x551330*/;
    cpu.esp -= 4;
    // 0051dc88  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dc8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dc8d  e8fe19fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dc92  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dc95  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dc99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dc9a  2bc9                   +sub ecx, ecx
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
    // 0051dc9c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dc9d  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dc9f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dca1  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dca2:
    // 0051dca2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dca4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dca6  3c00                   +cmp al, 0
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
    // 0051dca8  7410                   -je 0x51dcba
    if (cpu.flags.zf)
    {
        goto L_0x0051dcba;
    }
    // 0051dcaa  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dcad  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dcb0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dcb3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dcb6  3c00                   +cmp al, 0
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
    // 0051dcb8  75e8                   -jne 0x51dca2
    if (!cpu.flags.zf)
    {
        goto L_0x0051dca2;
    }
L_0x0051dcba:
    // 0051dcba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dcbb  8d4378                 -lea eax, [ebx + 0x78]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(120) /* 0x78 */);
    // 0051dcbe  e80d05ffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 0051dcc3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dcc4  6840135500             -push 0x551340
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575488 /*0x551340*/;
    cpu.esp -= 4;
    // 0051dcc9  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dccd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dcce  e8bd19fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dcd3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dcd6  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dcda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dcdb  2bc9                   +sub ecx, ecx
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
    // 0051dcdd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dcde  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dce0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dce2  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dce3:
    // 0051dce3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dce5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dce7  3c00                   +cmp al, 0
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
    // 0051dce9  7410                   -je 0x51dcfb
    if (cpu.flags.zf)
    {
        goto L_0x0051dcfb;
    }
    // 0051dceb  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dcee  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dcf1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dcf4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dcf7  3c00                   +cmp al, 0
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
    // 0051dcf9  75e8                   -jne 0x51dce3
    if (!cpu.flags.zf)
    {
        goto L_0x0051dce3;
    }
L_0x0051dcfb:
    // 0051dcfb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dcfc  8d8394000000           -lea eax, [ebx + 0x94]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(148) /* 0x94 */);
    // 0051dd02  e8c904ffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 0051dd07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dd08  6850135500             -push 0x551350
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575504 /*0x551350*/;
    cpu.esp -= 4;
    // 0051dd0d  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051dd11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051dd12  e87919fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dd17  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dd1a  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051dd1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dd1f  2bc9                   +sub ecx, ecx
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
    // 0051dd21  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dd22  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dd24  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dd26  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dd27:
    // 0051dd27  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051dd29  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051dd2b  3c00                   +cmp al, 0
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
    // 0051dd2d  7410                   -je 0x51dd3f
    if (cpu.flags.zf)
    {
        goto L_0x0051dd3f;
    }
    // 0051dd2f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051dd32  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dd35  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dd38  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051dd3b  3c00                   +cmp al, 0
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
    // 0051dd3d  75e8                   -jne 0x51dd27
    if (!cpu.flags.zf)
    {
        goto L_0x0051dd27;
    }
L_0x0051dd3f:
    // 0051dd3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd43  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0051dd46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dd48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_51dd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051dd50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051dd51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051dd52  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051dd55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051dd57  0f846c000000           -je 0x51ddc9
    if (cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dd5d  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0051dd61  7466                   -je 0x51ddc9
    if (cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dd63  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051dd66  833e00                 +cmp dword ptr [esi], 0
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
    // 0051dd69  755e                   -jne 0x51ddc9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dd6b  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0051dd6e  83fa01                 +cmp edx, 1
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
    // 0051dd71  735c                   -jae 0x51ddcf
    if (!cpu.flags.cf)
    {
        goto L_0x0051ddcf;
    }
    // 0051dd73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051dd75  7552                   -jne 0x51ddc9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dd77  8d5054                 -lea edx, [eax + 0x54]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(84) /* 0x54 */);
L_0x0051dd7a:
    // 0051dd7a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051dd7d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051dd7f  7448                   -je 0x51ddc9
    if (cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dd81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dd82  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051dd83  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0051dd85:
    // 0051dd85  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0051dd88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051dd89  6860135500             -push 0x551360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575520 /*0x551360*/;
    cpu.esp -= 4;
    // 0051dd8e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051dd92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051dd93  e8f818fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0051dd98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051dd9b  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051dd9f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dda0  2bc9                   +sub ecx, ecx
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
    // 0051dda2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051dda3  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0051dda5  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051dda7  4f                     -dec edi
    (cpu.edi)--;
L_0x0051dda8:
    // 0051dda8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051ddaa  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0051ddac  3c00                   +cmp al, 0
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
    // 0051ddae  7410                   -je 0x51ddc0
    if (cpu.flags.zf)
    {
        goto L_0x0051ddc0;
    }
    // 0051ddb0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051ddb3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051ddb6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051ddb9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051ddbc  3c00                   +cmp al, 0
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
    // 0051ddbe  75e8                   -jne 0x51dda8
    if (!cpu.flags.zf)
    {
        goto L_0x0051dda8;
    }
L_0x0051ddc0:
    // 0051ddc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ddc1  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0051ddc3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051ddc5  75be                   -jne 0x51dd85
    if (!cpu.flags.zf)
    {
        goto L_0x0051dd85;
    }
    // 0051ddc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ddc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051ddc9:
    // 0051ddc9  83c410                 +add esp, 0x10
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
    // 0051ddcc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ddcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ddce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ddcf:
    // 0051ddcf  7705                   -ja 0x51ddd6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051ddd6;
    }
    // 0051ddd1  8d5078                 -lea edx, [eax + 0x78]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 0051ddd4  eba4                   -jmp 0x51dd7a
    goto L_0x0051dd7a;
L_0x0051ddd6:
    // 0051ddd6  83fa02                 +cmp edx, 2
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
    // 0051ddd9  75ee                   -jne 0x51ddc9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ddc9;
    }
    // 0051dddb  8d9094000000           -lea edx, [eax + 0x94]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0051dde1  eb97                   -jmp 0x51dd7a
    goto L_0x0051dd7a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51ddf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ddf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ddf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ddf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051ddf3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051ddf5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051ddf7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0051ddf9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051ddfb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051ddfd  7e5a                   -jle 0x51de59
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051de59;
    }
    // 0051ddff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051de00  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 0051de05  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0051de07:
    // 0051de07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051de09  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0051de0b  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051de11  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0051de14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051de16  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051de19  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051de1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051de1d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 0051de1f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0051de22  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051de28  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051de2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051de2d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051de30  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051de32  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051de35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051de37  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0051de3a  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051de40  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0051de43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051de45  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051de48  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051de4a  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051de4d  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051de50  46                     -inc esi
    (cpu.esi)++;
    // 0051de51  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051de54  39fe                   +cmp esi, edi
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
    // 0051de56  7caf                   -jl 0x51de07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051de07;
    }
    // 0051de58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051de59:
    // 0051de59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051de5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051de5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051de5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51de60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051de60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051de61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051de62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051de63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051de64  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051de66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051de68  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051de6a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051de6c  7e68                   -jle 0x51ded6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051ded6;
    }
    // 0051de6e  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 0051de73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051de75  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0051de77:
    // 0051de77  81feff000000           +cmp esi, 0xff
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
    // 0051de7d  755c                   -jne 0x51dedb
    if (!cpu.flags.zf)
    {
        goto L_0x0051dedb;
    }
    // 0051de7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051de81:
    // 0051de81  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051de83  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0051de86  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0051de88  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051de8e  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051de91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051de93  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051de96  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051de98  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0051de9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051de9d  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0051dea0  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051dea6  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0051dea9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051deab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051deae  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051deb0  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051deb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051deb5  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051deb8  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 0051debe  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0051dec1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051dec3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051dec6  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051dec8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051decb  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051dece  46                     -inc esi
    (cpu.esi)++;
    // 0051decf  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0051ded2  39fe                   +cmp esi, edi
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
    // 0051ded4  7ca1                   -jl 0x51de77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051de77;
    }
L_0x0051ded6:
    // 0051ded6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ded7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ded8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ded9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051deda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051dedb:
    // 0051dedb  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0051dee0  eb9f                   -jmp 0x51de81
    goto L_0x0051de81;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_51def0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051def0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051def1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051def2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051def3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051def5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051def7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0051def9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051defb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051defd  7e5a                   -jle 0x51df59
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051df59;
    }
    // 0051deff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051df00  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0051df05  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0051df07:
    // 0051df07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051df09  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0051df0b  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051df0e  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0051df14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051df16  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051df19  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051df1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051df1d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 0051df1f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0051df22  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051df25  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0051df2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051df2d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051df30  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051df32  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051df35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051df37  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0051df3a  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051df3d  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0051df43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051df45  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051df48  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051df4a  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051df4d  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051df50  46                     -inc esi
    (cpu.esi)++;
    // 0051df51  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051df54  39fe                   +cmp esi, edi
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
    // 0051df56  7caf                   -jl 0x51df07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051df07;
    }
    // 0051df58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051df59:
    // 0051df59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051df5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051df5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051df5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51df60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051df60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051df61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051df62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051df63  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051df66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051df68  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051df6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051df6c  7e33                   -jle 0x51dfa1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051dfa1;
    }
    // 0051df6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0051df70:
    // 0051df70  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051df76  7430                   -je 0x51dfa8
    if (cpu.flags.zf)
    {
        goto L_0x0051dfa8;
    }
    // 0051df78  c70424ff000000         -mov dword ptr [esp], 0xff
    app->getMemory<x86::reg32>(cpu.esp) = 255 /*0xff*/;
L_0x0051df7f:
    // 0051df7f  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0051df82  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 0051df85  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0051df87  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0051df8a  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0051df8d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051df90  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0051df93  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051df96  8a5aff                 -mov bl, byte ptr [edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051df99  41                     -inc ecx
    (cpu.ecx)++;
    // 0051df9a  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 0051df9d  39f1                   +cmp ecx, esi
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
    // 0051df9f  7ccf                   -jl 0x51df70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051df70;
    }
L_0x0051dfa1:
    // 0051dfa1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051dfa4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dfa5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dfa6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051dfa7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051dfa8:
    // 0051dfa8  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0051dfaa  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0051dfad  ebd0                   -jmp 0x51df7f
    goto L_0x0051df7f;
}

/* align: skip 0x90 */
void Application::sub_51dfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051dfb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051dfb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051dfb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051dfb3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051dfb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051dfb7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0051dfb9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051dfbb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051dfbd  7e5c                   -jle 0x51e01b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e01b;
    }
    // 0051dfbf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051dfc0  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0051dfc5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0051dfc7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0051dfc9:
    // 0051dfc9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051dfcb  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051dfce  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051dfd1  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0051dfd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051dfd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051dfdc  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051dfde  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051dfe0  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0051dfe2  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0051dfe5  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051dfe8  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0051dfee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051dff0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051dff3  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051dff5  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051dff8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051dffa  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0051dffc  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 0051dfff  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0051e005  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e007  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0051e00a  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0051e00c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051e00f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e012  46                     -inc esi
    (cpu.esi)++;
    // 0051e013  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051e016  39fe                   +cmp esi, edi
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
    // 0051e018  7caf                   -jl 0x51dfc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051dfc9;
    }
    // 0051e01a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051e01b:
    // 0051e01b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e01c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e01d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e01e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e022  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e024  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051e026  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e028  7e26                   -jle 0x51e050
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e050;
    }
    // 0051e02a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0051e02c:
    // 0051e02c  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0051e02f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0051e031  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0051e034  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e037  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0051e03a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051e03d  8a5afc                 -mov bl, byte ptr [edx - 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0051e040  41                     -inc ecx
    (cpu.ecx)++;
    // 0051e041  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0051e044  39f1                   +cmp ecx, esi
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
    // 0051e046  7ce4                   -jl 0x51e02c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e02c;
    }
    // 0051e048  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051e04e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_0x0051e050:
    // 0051e050  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e052  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e061  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e064  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051e067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e069  742a                   -je 0x51e095
    if (cpu.flags.zf)
    {
        goto L_0x0051e095;
    }
    // 0051e06b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e06d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e06f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0051e071  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051e072  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051e074  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051e078  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051e079  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0051e07e  8b15b8b05600           -mov edx, dword ptr [0x56b0b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
    // 0051e084  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e085  2eff1538465300         -call dword ptr cs:[0x534638]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457464) /* 0x534638 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e08c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e08e  7505                   -jne 0x51e095
    if (!cpu.flags.zf)
    {
        goto L_0x0051e095;
    }
    // 0051e090  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0051e095:
    // 0051e095  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e098  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e0a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e0a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e0a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e0a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e0a4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0051e0a7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0051e0a9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051e0ab  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051e0ad  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0051e0af  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0051e0b3  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x0051e0b6:
    // 0051e0b6  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051e0ba  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0051e0be  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051e0c0  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0051e0c2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0051e0c4  8a823cac5600           -mov al, byte ptr [edx + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 0051e0ca  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 0051e0cc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051e0d0  41                     -inc ecx
    (cpu.ecx)++;
    // 0051e0d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e0d3  75e1                   -jne 0x51e0b6
    if (!cpu.flags.zf)
    {
        goto L_0x0051e0b6;
    }
L_0x0051e0d5:
    // 0051e0d5  46                     -inc esi
    (cpu.esi)++;
    // 0051e0d6  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0051e0d9  49                     -dec ecx
    (cpu.ecx)--;
    // 0051e0da  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051e0dd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0051e0df  75f4                   -jne 0x51e0d5
    if (!cpu.flags.zf)
    {
        goto L_0x0051e0d5;
    }
    // 0051e0e1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051e0e3  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0051e0e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e0e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e0e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e0e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e0ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e0ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e0ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e0ed  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051e0ef  83fb0a                 +cmp ebx, 0xa
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
    // 0051e0f2  750a                   -jne 0x51e0fe
    if (!cpu.flags.zf)
    {
        goto L_0x0051e0fe;
    }
    // 0051e0f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e0f6  7d06                   -jge 0x51e0fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e0fe;
    }
    // 0051e0f8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0051e0fa  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 0051e0fd  42                     -inc edx
    (cpu.edx)++;
L_0x0051e0fe:
    // 0051e0fe  e89dffffff             -call 0x51e0a0
    cpu.esp -= 4;
    sub_51e0a0(app, cpu);
    if (cpu.terminate) return;
    // 0051e103  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051e105  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e106  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e110  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e111  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051e116  b868135500             -mov eax, 0x551368
    cpu.eax = 5575528 /*0x551368*/;
    // 0051e11b  e8ec3bffff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0051e120  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e132  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e133  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051e134  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e135  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0051e138  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e13a  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0051e13e  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051e142  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0051e146  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0051e148  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 0051e14c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0051e14e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051e150  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0051e152  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051e153  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051e154  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0051e158  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0051e15c  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x0051e15f:
    // 0051e15f  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0051e163  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051e167  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051e16b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051e16f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051e172  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051e174  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051e177  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051e179  e8db7b0000             -call 0x525d59
    cpu.esp -= 4;
    sub_525d59(app, cpu);
    if (cpu.terminate) return;
    // 0051e17e  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0051e181  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051e183  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0051e186  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0051e188  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0051e18c  8a806cac5600           -mov al, byte ptr [eax + 0x56ac6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680236) /* 0x56ac6c */);
    // 0051e192  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 0051e195  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0051e199  45                     -inc ebp
    (cpu.ebp)++;
    // 0051e19a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051e19c  75c1                   -jne 0x51e15f
    if (!cpu.flags.zf)
    {
        goto L_0x0051e15f;
    }
    // 0051e19e  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051e1a3  75ba                   -jne 0x51e15f
    if (!cpu.flags.zf)
    {
        goto L_0x0051e15f;
    }
L_0x0051e1a5:
    // 0051e1a5  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0051e1a9  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 0051e1ac  4d                     -dec ebp
    (cpu.ebp)--;
    // 0051e1ad  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0051e1b0  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 0051e1b2  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0051e1b6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0051e1b8  75eb                   -jne 0x51e1a5
    if (!cpu.flags.zf)
    {
        goto L_0x0051e1a5;
    }
    // 0051e1ba  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0051e1be  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0051e1c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e1c2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051e1c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e1c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e1c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e1c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e1c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e1c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e1c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e1ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e1cb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051e1cc  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051e1cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e1d1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051e1d3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0051e1d5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0051e1d7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0051e1d9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051e1da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051e1db  83fb0a                 +cmp ebx, 0xa
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
    // 0051e1de  752d                   -jne 0x51e20d
    if (!cpu.flags.zf)
    {
        goto L_0x0051e20d;
    }
    // 0051e1e0  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 0051e1e5  7426                   -je 0x51e20d
    if (cpu.flags.zf)
    {
        goto L_0x0051e20d;
    }
    // 0051e1e7  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 0051e1ea  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e1ed  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051e1f1  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 0051e1f3  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0051e1f5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0051e1f8  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051e1fc  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e1ff  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0051e202  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051e203  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0051e206  7501                   -jne 0x51e209
    if (!cpu.flags.zf)
    {
        goto L_0x0051e209;
    }
    // 0051e208  46                     -inc esi
    (cpu.esi)++;
L_0x0051e209:
    // 0051e209  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x0051e20d:
    // 0051e20d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051e20f  e81cffffff             -call 0x51e130
    cpu.esp -= 4;
    sub_51e130(app, cpu);
    if (cpu.terminate) return;
    // 0051e214  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051e216  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051e219  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051e21a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e21b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e21c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e21d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_51e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e220  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e221  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e222  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e223  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e224  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0051e227  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0051e229  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051e22b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051e22d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0051e22f  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0051e233  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x0051e236:
    // 0051e236  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051e23a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0051e23e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051e240  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0051e242  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0051e244  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051e248  41                     -inc ecx
    (cpu.ecx)++;
    // 0051e249  8a9b94ac5600           -mov bl, byte ptr [ebx + 0x56ac94]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680276) /* 0x56ac94 */);
    // 0051e24f  8859ff                 -mov byte ptr [ecx - 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0051e252  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e254  75e0                   -jne 0x51e236
    if (!cpu.flags.zf)
    {
        goto L_0x0051e236;
    }
L_0x0051e256:
    // 0051e256  46                     -inc esi
    (cpu.esi)++;
    // 0051e257  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0051e25a  49                     -dec ecx
    (cpu.ecx)--;
    // 0051e25b  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051e25e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0051e260  75f4                   -jne 0x51e256
    if (!cpu.flags.zf)
    {
        goto L_0x0051e256;
    }
    // 0051e262  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051e264  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0051e267  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e268  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e269  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e26a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e26b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e26c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e26c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e26d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051e26f  83fb0a                 +cmp ebx, 0xa
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
    // 0051e272  750a                   -jne 0x51e27e
    if (!cpu.flags.zf)
    {
        goto L_0x0051e27e;
    }
    // 0051e274  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e276  7d06                   -jge 0x51e27e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e27e;
    }
    // 0051e278  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0051e27a  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 0051e27d  42                     -inc edx
    (cpu.edx)++;
L_0x0051e27e:
    // 0051e27e  e89dffffff             -call 0x51e220
    cpu.esp -= 4;
    sub_51e220(app, cpu);
    if (cpu.terminate) return;
    // 0051e283  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051e285  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e286  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e290  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0051e296  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0051e298  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051e29d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e2a0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051e2a2  e9f9780000             -jmp 0x525ba0
    return sub_525ba0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e2b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e2b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e2b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e2b3  8b0dbcac5600           -mov ecx, dword ptr [0x56acbc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e2b9  a1c0ac5600             -mov eax, dword ptr [0x56acc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e2be  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
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
    // 0051e2c4  7304                   -jae 0x51e2ca
    if (!cpu.flags.cf)
    {
        goto L_0x0051e2ca;
    }
    // 0051e2c6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051e2c8  eb2f                   -jmp 0x51e2f9
    goto L_0x0051e2f9;
L_0x0051e2ca:
    // 0051e2ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e2cc  7e26                   -jle 0x51e2f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e2f4;
    }
    // 0051e2ce  8b1dc0ac5600           -mov ebx, dword ptr [0x56acc0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e2d4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0051e2d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051e2d8  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
L_0x0051e2db:
    // 0051e2db  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 0051e2df  750c                   -jne 0x51e2ed
    if (!cpu.flags.zf)
    {
        goto L_0x0051e2ed;
    }
    // 0051e2e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051e2e3  890dbcac5600           -mov dword ptr [0x56acbc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */) = cpu.ecx;
    // 0051e2e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e2ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e2eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051e2ed:
    // 0051e2ed  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e2f0  39d8                   +cmp eax, ebx
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
    // 0051e2f2  7ce7                   -jl 0x51e2db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e2db;
    }
L_0x0051e2f4:
    // 0051e2f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051e2f9:
    // 0051e2f9  890dbcac5600           -mov dword ptr [0x56acbc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */) = cpu.ecx;
    // 0051e2ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e300  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e301  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e302  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e304(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e304  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e305  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e306  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e307  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e308  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e30a  ff1598775600           -call dword ptr [0x567798]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666712) /* 0x567798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e310  8b1dc0ac5600           -mov ebx, dword ptr [0x56acc0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e316  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051e318  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051e31a  7e2d                   -jle 0x51e349
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e349;
    }
    // 0051e31c  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 0051e323  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0051e325:
    // 0051e325  8b1dbcac5600           -mov ebx, dword ptr [0x56acbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e32b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051e32d  833b00                 +cmp dword ptr [ebx], 0
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
    // 0051e330  750f                   -jne 0x51e341
    if (!cpu.flags.zf)
    {
        goto L_0x0051e341;
    }
    // 0051e332  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0051e334  ff159c775600           -call dword ptr [0x56779c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666716) /* 0x56779c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e33a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e33c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e33d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e33e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e33f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e340  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051e341:
    // 0051e341  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e344  42                     -inc edx
    (cpu.edx)++;
    // 0051e345  39c8                   +cmp eax, ecx
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
    // 0051e347  7cdc                   -jl 0x51e325
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e325;
    }
L_0x0051e349:
    // 0051e349  8b15c0ac5600           -mov edx, dword ptr [0x56acc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e34f  42                     -inc edx
    (cpu.edx)++;
    // 0051e350  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e355  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0051e358  e863a2ffff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0051e35d  8b15c0ac5600           -mov edx, dword ptr [0x56acc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e363  a3bcac5600             -mov dword ptr [0x56acbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */) = cpu.eax;
    // 0051e368  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0051e36b  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 0051e36e  890dc0ac5600           -mov dword ptr [0x56acc0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */) = cpu.ecx;
    // 0051e374  ff159c775600           -call dword ptr [0x56779c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666716) /* 0x56779c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e37a  a1c0ac5600             -mov eax, dword ptr [0x56acc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e37f  48                     -dec eax
    (cpu.eax)--;
    // 0051e380  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e381  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e383  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e388  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e389  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e38a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e38b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e38c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e38d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e390  8b3dbcac5600           -mov edi, dword ptr [0x56acbc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e396  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0051e399  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051e39b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e39d  0f8caa000000           -jl 0x51e44d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e44d;
    }
    // 0051e3a3  ff1598775600           -call dword ptr [0x567798]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666712) /* 0x567798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e3a9  83fa01                 +cmp edx, 1
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
    // 0051e3ac  7209                   -jb 0x51e3b7
    if (cpu.flags.cf)
    {
        goto L_0x0051e3b7;
    }
    // 0051e3ae  7613                   -jbe 0x51e3c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051e3c3;
    }
    // 0051e3b0  83fa02                 +cmp edx, 2
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
    // 0051e3b3  7416                   -je 0x51e3cb
    if (cpu.flags.zf)
    {
        goto L_0x0051e3cb;
    }
    // 0051e3b5  eb21                   -jmp 0x51e3d8
    goto L_0x0051e3d8;
L_0x0051e3b7:
    // 0051e3b7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e3b9  751d                   -jne 0x51e3d8
    if (!cpu.flags.zf)
    {
        goto L_0x0051e3d8;
    }
    // 0051e3bb  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e3be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e3bf  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 0051e3c1  eb0e                   -jmp 0x51e3d1
    goto L_0x0051e3d1;
L_0x0051e3c3:
    // 0051e3c3  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e3c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e3c7  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0051e3c9  eb06                   -jmp 0x51e3d1
    goto L_0x0051e3d1;
L_0x0051e3cb:
    // 0051e3cb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e3ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e3cf  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x0051e3d1:
    // 0051e3d1  2eff15f8455300         -call dword ptr cs:[0x5345f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457400) /* 0x5345f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051e3d8:
    // 0051e3d8  8b2dc0ac5600           -mov ebp, dword ptr [0x56acc0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e3de  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0051e3e5  8b3dbcac5600           -mov edi, dword ptr [0x56acbc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e3eb  39ee                   +cmp esi, ebp
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
    // 0051e3ed  7d09                   -jge 0x51e3f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e3f8;
    }
    // 0051e3ef  01f9                   +add ecx, edi
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
    // 0051e3f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e3f4  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0051e3f6  eb49                   -jmp 0x51e441
    goto L_0x0051e441;
L_0x0051e3f8:
    // 0051e3f8  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051e3fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051e3fd  e8bea1ffff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0051e402  8b15c0ac5600           -mov edx, dword ptr [0x56acc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */);
    // 0051e408  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051e40a  39f2                   +cmp edx, esi
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
    // 0051e40c  7d18                   -jge 0x51e426
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e426;
    }
    // 0051e40e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051e415  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0051e417:
    // 0051e417  c7040300000000         -mov dword ptr [ebx + eax], 0
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 0051e41e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e421  42                     -inc edx
    (cpu.edx)++;
    // 0051e422  39c8                   +cmp eax, ecx
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
    // 0051e424  7cf1                   -jl 0x51e417
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e417;
    }
L_0x0051e426:
    // 0051e426  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0051e42d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051e430  46                     -inc esi
    (cpu.esi)++;
    // 0051e431  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051e433  893dbcac5600           -mov dword ptr [0x56acbc], edi
    app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */) = cpu.edi;
    // 0051e439  8935c0ac5600           -mov dword ptr [0x56acc0], esi
    app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */) = cpu.esi;
    // 0051e43f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0051e441:
    // 0051e441  ff159c775600           -call dword ptr [0x56779c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666716) /* 0x56779c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e447  8b3dbcac5600           -mov edi, dword ptr [0x56acbc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
L_0x0051e44d:
    // 0051e44d  8b3dbcac5600           -mov edi, dword ptr [0x56acbc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e453  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e456  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e457  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e458  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e459  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e45a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e45b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e45c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e45c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e45d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e45f  ff1598775600           -call dword ptr [0x567798]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666712) /* 0x567798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e465  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e467  7e1c                   -jle 0x51e485
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e485;
    }
    // 0051e469  3b15c0ac5600           +cmp edx, dword ptr [0x56acc0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680320) /* 0x56acc0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051e46f  7d14                   -jge 0x51e485
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e485;
    }
    // 0051e471  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051e478  8b15bcac5600           -mov edx, dword ptr [0x56acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e47e  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
L_0x0051e485:
    // 0051e485  ff159c775600           -call dword ptr [0x56779c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666716) /* 0x56779c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e48b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e48c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e490  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e491  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e492  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 0051e494  2eff155c455300         -call dword ptr cs:[0x53455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457244) /* 0x53455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e49b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e49d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e49f  7405                   -je 0x51e4a6
    if (cpu.flags.zf)
    {
        goto L_0x0051e4a6;
    }
    // 0051e4a1  83f8ff                 +cmp eax, -1
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
    // 0051e4a4  7505                   -jne 0x51e4ab
    if (!cpu.flags.zf)
    {
        goto L_0x0051e4ab;
    }
L_0x0051e4a6:
    // 0051e4a6  e845000000             -call 0x51e4f0
    cpu.esp -= 4;
    sub_51e4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051e4ab:
    // 0051e4ab  e854feffff             -call 0x51e304
    cpu.esp -= 4;
    sub_51e304(app, cpu);
    if (cpu.terminate) return;
    // 0051e4b0  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 0051e4b2  2eff155c455300         -call dword ptr cs:[0x53455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457244) /* 0x53455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e4b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e4bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e4bd  7405                   -je 0x51e4c4
    if (cpu.flags.zf)
    {
        goto L_0x0051e4c4;
    }
    // 0051e4bf  83f8ff                 +cmp eax, -1
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
    // 0051e4c2  7505                   -jne 0x51e4c9
    if (!cpu.flags.zf)
    {
        goto L_0x0051e4c9;
    }
L_0x0051e4c4:
    // 0051e4c4  e827000000             -call 0x51e4f0
    cpu.esp -= 4;
    sub_51e4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051e4c9:
    // 0051e4c9  e836feffff             -call 0x51e304
    cpu.esp -= 4;
    sub_51e304(app, cpu);
    if (cpu.terminate) return;
    // 0051e4ce  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 0051e4d0  2eff155c455300         -call dword ptr cs:[0x53455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457244) /* 0x53455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e4d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e4d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e4db  7405                   -je 0x51e4e2
    if (cpu.flags.zf)
    {
        goto L_0x0051e4e2;
    }
    // 0051e4dd  83f8ff                 +cmp eax, -1
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
    // 0051e4e0  7505                   -jne 0x51e4e7
    if (!cpu.flags.zf)
    {
        goto L_0x0051e4e7;
    }
L_0x0051e4e2:
    // 0051e4e2  e809000000             -call 0x51e4f0
    cpu.esp -= 4;
    sub_51e4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051e4e7:
    // 0051e4e7  e818feffff             -call 0x51e304
    cpu.esp -= 4;
    sub_51e304(app, cpu);
    if (cpu.terminate) return;
    // 0051e4ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e4ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e4ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e4f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e4f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e4f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e4f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e4f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e4f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e4fa  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e501  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e503  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e505  750d                   -jne 0x51e514
    if (!cpu.flags.zf)
    {
        goto L_0x0051e514;
    }
    // 0051e507  8b15c4ac5600           -mov edx, dword ptr [0x56acc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680324) /* 0x56acc4 */);
    // 0051e50d  42                     -inc edx
    (cpu.edx)++;
    // 0051e50e  8915c4ac5600           -mov dword ptr [0x56acc4], edx
    app->getMemory<x86::reg32>(x86::reg32(5680324) /* 0x56acc4 */) = cpu.edx;
L_0x0051e514:
    // 0051e514  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e516  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e517  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e518  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e51c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e51c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e51d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e51e  8b15bcac5600           -mov edx, dword ptr [0x56acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051e524  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e526  740f                   -je 0x51e537
    if (cpu.flags.zf)
    {
        goto L_0x0051e537;
    }
    // 0051e528  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e52a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051e52c  e8bf94fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051e531  891dbcac5600           -mov dword ptr [0x56acbc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */) = cpu.ebx;
L_0x0051e537:
    // 0051e537  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e538  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e539  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51e540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e544(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e545  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e546  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e548  8b1580baa000           -mov edx, dword ptr [0xa0ba80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10533504) /* 0xa0ba80 */);
    // 0051e54e  83fa40                 +cmp edx, 0x40
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
    // 0051e551  7d1e                   -jge 0x51e571
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051e571;
    }
    // 0051e553  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051e55a  bb50b4a000             -mov ebx, 0xa0b450
    cpu.ebx = 10531920 /*0xa0b450*/;
    // 0051e55f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051e561  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0051e564  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0051e567  893580baa000           -mov dword ptr [0xa0ba80], esi
    app->getMemory<x86::reg32>(x86::reg32(10533504) /* 0xa0ba80 */) = cpu.esi;
    // 0051e56d  01c3                   +add ebx, eax
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
    // 0051e56f  eb67                   -jmp 0x51e5d8
    goto L_0x0051e5d8;
L_0x0051e571:
    // 0051e571  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0051e576  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051e57b  e870780000             -call 0x525df0
    cpu.esp -= 4;
    sub_525df0(app, cpu);
    if (cpu.terminate) return;
    // 0051e580  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e584  750f                   -jne 0x51e595
    if (!cpu.flags.zf)
    {
        goto L_0x0051e595;
    }
    // 0051e586  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051e58b  b88c135500             -mov eax, 0x55138c
    cpu.eax = 5575564 /*0x55138c*/;
    // 0051e590  e87737ffff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_0x0051e595:
    // 0051e595  8b1584baa000           -mov edx, dword ptr [0xa0ba84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10533508) /* 0xa0ba84 */);
    // 0051e59b  42                     -inc edx
    (cpu.edx)++;
    // 0051e59c  a188baa000             -mov eax, dword ptr [0xa0ba88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */);
    // 0051e5a1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0051e5a4  e817a0ffff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0051e5a9  a388baa000             -mov dword ptr [0xa0ba88], eax
    app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */) = cpu.eax;
    // 0051e5ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e5b0  750f                   -jne 0x51e5c1
    if (!cpu.flags.zf)
    {
        goto L_0x0051e5c1;
    }
    // 0051e5b2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051e5b7  b8b0135500             -mov eax, 0x5513b0
    cpu.eax = 5575600 /*0x5513b0*/;
    // 0051e5bc  e84b37ffff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_0x0051e5c1:
    // 0051e5c1  a184baa000             -mov eax, dword ptr [0xa0ba84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10533508) /* 0xa0ba84 */);
    // 0051e5c6  8b1588baa000           -mov edx, dword ptr [0xa0ba88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */);
    // 0051e5cc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051e5cf  891c82                 -mov dword ptr [edx + eax*4], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ebx;
    // 0051e5d2  890d84baa000           -mov dword ptr [0xa0ba84], ecx
    app->getMemory<x86::reg32>(x86::reg32(10533508) /* 0xa0ba84 */) = cpu.ecx;
L_0x0051e5d8:
    // 0051e5d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e5d9  2eff1584455300         -call dword ptr cs:[0x534584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457284) /* 0x534584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e5e0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051e5e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e5e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e5e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e5e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e5e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e5e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e5e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e5e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e5ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e5eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e5ec  8b1580baa000           -mov edx, dword ptr [0xa0ba80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10533504) /* 0xa0ba80 */);
    // 0051e5f2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051e5f4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e5f6  7e1b                   -jle 0x51e613
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e613;
    }
    // 0051e5f8  bb50b4a000             -mov ebx, 0xa0b450
    cpu.ebx = 10531920 /*0xa0b450*/;
L_0x0051e5fd:
    // 0051e5fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e5fe  46                     -inc esi
    (cpu.esi)++;
    // 0051e5ff  2eff15ac445300         -call dword ptr cs:[0x5344ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457068) /* 0x5344ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e606  8b0d80baa000           -mov ecx, dword ptr [0xa0ba80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10533504) /* 0xa0ba80 */);
    // 0051e60c  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0051e60f  39ce                   +cmp esi, ecx
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
    // 0051e611  7cea                   -jl 0x51e5fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e5fd;
    }
L_0x0051e613:
    // 0051e613  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e614  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e615  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e616  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e619  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e61a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e61b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e61c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e61d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e61e  8b1584baa000           -mov edx, dword ptr [0xa0ba84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10533508) /* 0xa0ba84 */);
    // 0051e624  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0051e626  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e628  7e2d                   -jle 0x51e657
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051e657;
    }
    // 0051e62a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0051e62c:
    // 0051e62c  a188baa000             -mov eax, dword ptr [0xa0ba88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */);
    // 0051e631  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0051e634  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e635  2eff15ac445300         -call dword ptr cs:[0x5344ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457068) /* 0x5344ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e63c  a188baa000             -mov eax, dword ptr [0xa0ba88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */);
    // 0051e641  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0051e644  46                     -inc esi
    (cpu.esi)++;
    // 0051e645  e8a693fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051e64a  8b3d84baa000           -mov edi, dword ptr [0xa0ba84]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10533508) /* 0xa0ba84 */);
    // 0051e650  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051e653  39fe                   +cmp esi, edi
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
    // 0051e655  7cd5                   -jl 0x51e62c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051e62c;
    }
L_0x0051e657:
    // 0051e657  8b2d88baa000           -mov ebp, dword ptr [0xa0ba88]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10533512) /* 0xa0ba88 */);
    // 0051e65d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051e65f  7407                   -je 0x51e668
    if (cpu.flags.zf)
    {
        goto L_0x0051e668;
    }
    // 0051e661  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051e663  e88893fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0051e668:
    // 0051e668  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e669  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e66a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e66b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e66c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e66d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e66e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e670  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051e677  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0051e67e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e680  b820b3a000             -mov eax, 0xa0b320
    cpu.eax = 10531616 /*0xa0b320*/;
    // 0051e685  e992000000             -jmp 0x51e71c
    return sub_51e71c(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e68c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e68c  b820b3a000             -mov eax, 0xa0b320
    cpu.eax = 10531616 /*0xa0b320*/;
    // 0051e691  e9ea000000             -jmp 0x51e780
    return sub_51e780(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e698(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e698  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0051e69b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0051e69e  0540b3a000             +add eax, 0xa0b340
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10531648 /*0xa0b340*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051e6a3  e974000000             -jmp 0x51e71c
    return sub_51e71c(app, cpu);
}

/* align: skip  */
void Application::sub_51e6a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6a8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0051e6ab  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0051e6ae  0540b3a000             +add eax, 0xa0b340
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10531648 /*0xa0b340*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051e6b3  e9c8000000             -jmp 0x51e780
    return sub_51e780(app, cpu);
}

/* align: skip  */
void Application::sub_51e6b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6b8  e947fcffff             -jmp 0x51e304
    return sub_51e304(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e6c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e6c3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0051e6c6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0051e6c9  0540b3a000             -add eax, 0xa0b340
    (cpu.eax) += x86::reg32(x86::sreg32(10531648 /*0xa0b340*/));
    // 0051e6ce  e89dffffff             -call 0x51e670
    cpu.esp -= 4;
    sub_51e670(app, cpu);
    if (cpu.terminate) return;
    // 0051e6d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e6d5  e882fdffff             -call 0x51e45c
    cpu.esp -= 4;
    sub_51e45c(app, cpu);
    if (cpu.terminate) return;
    // 0051e6da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e6db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e6dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6dc  b840b4a000             -mov eax, 0xa0b440
    cpu.eax = 10531904 /*0xa0b440*/;
    // 0051e6e1  eb39                   -jmp 0x51e71c
    return sub_51e71c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_51e6e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6e4  b840b4a000             -mov eax, 0xa0b440
    cpu.eax = 10531904 /*0xa0b440*/;
    // 0051e6e9  e992000000             -jmp 0x51e780
    return sub_51e780(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6f0  b830b3a000             -mov eax, 0xa0b330
    cpu.eax = 10531632 /*0xa0b330*/;
    // 0051e6f5  eb25                   -jmp 0x51e71c
    return sub_51e71c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_51e6f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e6f8  b830b3a000             -mov eax, 0xa0b330
    cpu.eax = 10531632 /*0xa0b330*/;
    // 0051e6fd  e97e000000             -jmp 0x51e780
    return sub_51e780(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e704  b860baa000             -mov eax, 0xa0ba60
    cpu.eax = 10533472 /*0xa0ba60*/;
    // 0051e709  eb11                   -jmp 0x51e71c
    return sub_51e71c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_51e70c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e70c  b860baa000             -mov eax, 0xa0ba60
    cpu.eax = 10533472 /*0xa0ba60*/;
    // 0051e711  eb6d                   -jmp 0x51e780
    return sub_51e780(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_51e714(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e714  b870baa000             -mov eax, 0xa0ba70
    cpu.eax = 10533488 /*0xa0ba70*/;
    // 0051e719  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051e71c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e71d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e71e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e71f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e720  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e721  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e723  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e72a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051e72d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e72f  39d0                   +cmp eax, edx
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
    // 0051e731  743b                   -je 0x51e76e
    if (cpu.flags.zf)
    {
        goto L_0x0051e76e;
    }
    // 0051e733  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 0051e737  7528                   -jne 0x51e761
    if (!cpu.flags.zf)
    {
        goto L_0x0051e761;
    }
    // 0051e739  b850baa000             -mov eax, 0xa0ba50
    cpu.eax = 10533456 /*0xa0ba50*/;
    // 0051e73e  e8d9ffffff             -call 0x51e71c
    cpu.esp -= 4;
    sub_51e71c(app, cpu);
    if (cpu.terminate) return;
    // 0051e743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 0051e747  750e                   -jne 0x51e757
    if (!cpu.flags.zf)
    {
        goto L_0x0051e757;
    }
    // 0051e749  e8f6fdffff             -call 0x51e544
    cpu.esp -= 4;
    sub_51e544(app, cpu);
    if (cpu.terminate) return;
    // 0051e74e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0051e755  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0051e757:
    // 0051e757  b850baa000             -mov eax, 0xa0ba50
    cpu.eax = 10533456 /*0xa0ba50*/;
    // 0051e75c  e81f000000             -call 0x51e780
    cpu.esp -= 4;
    sub_51e780(app, cpu);
    if (cpu.terminate) return;
L_0x0051e761:
    // 0051e761  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051e763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e764  2eff15b8445300         -call dword ptr cs:[0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e76b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0051e76e:
    // 0051e76e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 0051e771  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e772  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e773  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e71c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0051e71c;
    // 0051e714  b870baa000             -mov eax, 0xa0ba70
    cpu.eax = 10533488 /*0xa0ba70*/;
    // 0051e719  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0051e71c:
    // 0051e71c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e71d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e71e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e71f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e720  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e721  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e723  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e72a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051e72d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e72f  39d0                   +cmp eax, edx
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
    // 0051e731  743b                   -je 0x51e76e
    if (cpu.flags.zf)
    {
        goto L_0x0051e76e;
    }
    // 0051e733  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 0051e737  7528                   -jne 0x51e761
    if (!cpu.flags.zf)
    {
        goto L_0x0051e761;
    }
    // 0051e739  b850baa000             -mov eax, 0xa0ba50
    cpu.eax = 10533456 /*0xa0ba50*/;
    // 0051e73e  e8d9ffffff             -call 0x51e71c
    cpu.esp -= 4;
    sub_51e71c(app, cpu);
    if (cpu.terminate) return;
    // 0051e743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 0051e747  750e                   -jne 0x51e757
    if (!cpu.flags.zf)
    {
        goto L_0x0051e757;
    }
    // 0051e749  e8f6fdffff             -call 0x51e544
    cpu.esp -= 4;
    sub_51e544(app, cpu);
    if (cpu.terminate) return;
    // 0051e74e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0051e755  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0051e757:
    // 0051e757  b850baa000             -mov eax, 0xa0ba50
    cpu.eax = 10533456 /*0xa0ba50*/;
    // 0051e75c  e81f000000             -call 0x51e780
    cpu.esp -= 4;
    sub_51e780(app, cpu);
    if (cpu.terminate) return;
L_0x0051e761:
    // 0051e761  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051e763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e764  2eff15b8445300         -call dword ptr cs:[0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e76b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0051e76e:
    // 0051e76e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 0051e771  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e772  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e773  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e778  b870baa000             -mov eax, 0xa0ba70
    cpu.eax = 10533488 /*0xa0ba70*/;
    // 0051e77d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051e780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e784  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051e787  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e789  7617                   -jbe 0x51e7a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051e7a2;
    }
    // 0051e78b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051e78e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0051e791  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051e793  750d                   -jne 0x51e7a2
    if (!cpu.flags.zf)
    {
        goto L_0x0051e7a2;
    }
    // 0051e795  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0051e797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e798  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0051e79b  2eff1588455300         -call dword ptr cs:[0x534588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051e7a2:
    // 0051e7a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0051e780;
    // 0051e778  b870baa000             -mov eax, 0xa0ba70
    cpu.eax = 10533488 /*0xa0ba70*/;
    // 0051e77d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0051e780:
    // 0051e780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e784  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0051e787  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051e789  7617                   -jbe 0x51e7a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051e7a2;
    }
    // 0051e78b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051e78e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0051e791  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051e793  750d                   -jne 0x51e7a2
    if (!cpu.flags.zf)
    {
        goto L_0x0051e7a2;
    }
    // 0051e795  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0051e797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e798  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0051e79b  2eff1588455300         -call dword ptr cs:[0x534588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051e7a2:
    // 0051e7a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e7a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e7a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e7a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e7aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e7ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e7ac  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e7b3  8b1560775600           -mov edx, dword ptr [0x567760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e7b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e7ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051e7bc  2eff1514465300         -call dword ptr cs:[0x534614]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457428) /* 0x534614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e7c3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e7c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e7c7  7507                   -jne 0x51e7d0
    if (!cpu.flags.zf)
    {
        goto L_0x0051e7d0;
    }
    // 0051e7c9  e842760000             -call 0x525e10
    cpu.esp -= 4;
    sub_525e10(app, cpu);
    if (cpu.terminate) return;
    // 0051e7ce  eb0b                   -jmp 0x51e7db
    goto L_0x0051e7db;
L_0x0051e7d0:
    // 0051e7d0  80785300               +cmp byte ptr [eax + 0x53], 0
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
    // 0051e7d4  7407                   -je 0x51e7dd
    if (cpu.flags.zf)
    {
        goto L_0x0051e7dd;
    }
    // 0051e7d6  e871760000             -call 0x525e4c
    cpu.esp -= 4;
    sub_525e4c(app, cpu);
    if (cpu.terminate) return;
L_0x0051e7db:
    // 0051e7db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0051e7dd:
    // 0051e7dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e7de  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e7e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051e7e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e7eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e7ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e7ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e7ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e7ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e7f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e7f2  7526                   -jne 0x51e81a
    if (!cpu.flags.zf)
    {
        goto L_0x0051e81a;
    }
    // 0051e7f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051e7f9  8b1570af5600           -mov edx, dword ptr [0x56af70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0051e7ff  e8ec750000             -call 0x525df0
    cpu.esp -= 4;
    sub_525df0(app, cpu);
    if (cpu.terminate) return;
    // 0051e804  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051e806  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e808  7410                   -je 0x51e81a
    if (cpu.flags.zf)
    {
        goto L_0x0051e81a;
    }
    // 0051e80a  8b1d70af5600           -mov ebx, dword ptr [0x56af70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 0051e810  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 0051e814  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x0051e81a:
    // 0051e81a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e81c  e80f780000             -call 0x526030
    cpu.esp -= 4;
    sub_526030(app, cpu);
    if (cpu.terminate) return;
    // 0051e821  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051e823  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e824  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e825  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e828(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e828  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e829  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e82a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e82b  8b1d60775600           -mov ebx, dword ptr [0x567760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e831  83fbff                 +cmp ebx, -1
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
    // 0051e834  753b                   -jne 0x51e871
    if (!cpu.flags.zf)
    {
        goto L_0x0051e871;
    }
    // 0051e836  2eff150c465300         -call dword ptr cs:[0x53460c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457420) /* 0x53460c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e83d  668b1541785600         -mov dx, word ptr [0x567841]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */);
    // 0051e844  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e846  6681fa0080             +cmp dx, 0x8000
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
    // 0051e84b  7224                   -jb 0x51e871
    if (cpu.flags.cf)
    {
        goto L_0x0051e871;
    }
    // 0051e84d  803d3f78560004         +cmp byte ptr [0x56783f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5666879) /* 0x56783f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051e854  731b                   -jae 0x51e871
    if (!cpu.flags.cf)
    {
        goto L_0x0051e871;
    }
L_0x0051e856:
    // 0051e856  83fbff                 +cmp ebx, -1
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
    // 0051e859  7416                   -je 0x51e871
    if (cpu.flags.zf)
    {
        goto L_0x0051e871;
    }
    // 0051e85b  83fb02                 +cmp ebx, 2
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
    // 0051e85e  7711                   -ja 0x51e871
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051e871;
    }
    // 0051e860  891d60775600           -mov dword ptr [0x567760], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */) = cpu.ebx;
    // 0051e866  2eff150c465300         -call dword ptr cs:[0x53460c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457420) /* 0x53460c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e86d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e86f  ebe5                   -jmp 0x51e856
    goto L_0x0051e856;
L_0x0051e871:
    // 0051e871  83fbff                 +cmp ebx, -1
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
    // 0051e874  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0051e877  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051e87c  891d60775600           -mov dword ptr [0x567760], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */) = cpu.ebx;
    // 0051e882  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e883  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e884  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e885  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e889  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e88a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e88b  833d60775600ff         +cmp dword ptr [0x567760], -1
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
    // 0051e892  7506                   -jne 0x51e89a
    if (!cpu.flags.zf)
    {
        goto L_0x0051e89a;
    }
    // 0051e894  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051e896  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e897  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e898  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e899  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051e89a:
    // 0051e89a  e84dffffff             -call 0x51e7ec
    cpu.esp -= 4;
    sub_51e7ec(app, cpu);
    if (cpu.terminate) return;
    // 0051e89f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e8a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e8a3  7432                   -je 0x51e8d7
    if (cpu.flags.zf)
    {
        goto L_0x0051e8d7;
    }
    // 0051e8a5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0051e8a7  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 0051e8ad  e86e760000             -call 0x525f20
    cpu.esp -= 4;
    sub_525f20(app, cpu);
    if (cpu.terminate) return;
    // 0051e8b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e8b4  750d                   -jne 0x51e8c3
    if (!cpu.flags.zf)
    {
        goto L_0x0051e8c3;
    }
    // 0051e8b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051e8b8  e83391fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051e8bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051e8bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051e8c3:
    // 0051e8c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e8c4  8b1d60775600           -mov ebx, dword ptr [0x567760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e8ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e8cb  2eff1518465300         -call dword ptr cs:[0x534618]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457432) /* 0x534618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e8d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051e8d7:
    // 0051e8d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e8da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51e8dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e8dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e8dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e8de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e8df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e8e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e8e1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051e8e3  8b1560775600           -mov edx, dword ptr [0x567760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e8e9  83faff                 +cmp edx, -1
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
    // 0051e8ec  743d                   -je 0x51e92b
    if (cpu.flags.zf)
    {
        goto L_0x0051e92b;
    }
    // 0051e8ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e8ef  2eff1514465300         -call dword ptr cs:[0x534614]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457428) /* 0x534614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e8f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051e8f8  7431                   -je 0x51e92b
    if (cpu.flags.zf)
    {
        goto L_0x0051e92b;
    }
    // 0051e8fa  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 0051e900  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 0051e906  e879760000             -call 0x525f84
    cpu.esp -= 4;
    sub_525f84(app, cpu);
    if (cpu.terminate) return;
    // 0051e90b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051e90d  8b3d60775600           -mov edi, dword ptr [0x567760]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e913  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e914  2eff1518465300         -call dword ptr cs:[0x534618]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457432) /* 0x534618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e91b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051e91d  740c                   -je 0x51e92b
    if (cpu.flags.zf)
    {
        goto L_0x0051e92b;
    }
    // 0051e91f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051e921  7408                   -je 0x51e92b
    if (cpu.flags.zf)
    {
        goto L_0x0051e92b;
    }
    // 0051e923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e924  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051e92b:
    // 0051e92b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e92c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e92d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e92e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e92f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e930  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51e934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e934  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051e939  e89effffff             -call 0x51e8dc
    cpu.esp -= 4;
    sub_51e8dc(app, cpu);
    if (cpu.terminate) return;
    // 0051e93e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0051e940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e941  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e942  8b1560775600           -mov edx, dword ptr [0x567760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e948  83faff                 +cmp edx, -1
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
    // 0051e94b  7412                   -je 0x51e95f
    if (cpu.flags.zf)
    {
        goto L_0x0051e95f;
    }
    // 0051e94d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e94e  2eff1510465300         -call dword ptr cs:[0x534610]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457424) /* 0x534610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e955  c70560775600ffffffff   -mov dword ptr [0x567760], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */) = 4294967295 /*0xffffffff*/;
L_0x0051e95f:
    // 0051e95f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e960  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e961  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51e940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0051e940;
    // 0051e934  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051e939  e89effffff             -call 0x51e8dc
    cpu.esp -= 4;
    sub_51e8dc(app, cpu);
    if (cpu.terminate) return;
    // 0051e93e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0051e940:
    // 0051e940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e941  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e942  8b1560775600           -mov edx, dword ptr [0x567760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051e948  83faff                 +cmp edx, -1
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
    // 0051e94b  7412                   -je 0x51e95f
    if (cpu.flags.zf)
    {
        goto L_0x0051e95f;
    }
    // 0051e94d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e94e  2eff1510465300         -call dword ptr cs:[0x534610]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457424) /* 0x534610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051e955  c70560775600ffffffff   -mov dword ptr [0x567760], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */) = 4294967295 /*0xffffffff*/;
L_0x0051e95f:
    // 0051e95f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e960  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051e961  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51e964(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051e964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051e965  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051e966  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051e967  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051e968  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051e969  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051e96a  ba98e65100             -mov edx, 0x51e698
    cpu.edx = 5367448 /*0x51e698*/;
    // 0051e96f  bba8e65100             -mov ebx, 0x51e6a8
    cpu.ebx = 5367464 /*0x51e6a8*/;
    // 0051e974  b9b8e65100             -mov ecx, 0x51e6b8
    cpu.ecx = 5367480 /*0x51e6b8*/;
    // 0051e979  bec0e65100             -mov esi, 0x51e6c0
    cpu.esi = 5367488 /*0x51e6c0*/;
    // 0051e97e  bf80e65100             -mov edi, 0x51e680
    cpu.edi = 5367424 /*0x51e680*/;
    // 0051e983  bd8ce65100             -mov ebp, 0x51e68c
    cpu.ebp = 5367436 /*0x51e68c*/;
    // 0051e988  b804e75100             -mov eax, 0x51e704
    cpu.eax = 5367556 /*0x51e704*/;
    // 0051e98d  891568775600           -mov dword ptr [0x567768], edx
    app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */) = cpu.edx;
    // 0051e993  891d6c775600           -mov dword ptr [0x56776c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */) = cpu.ebx;
    // 0051e999  890d70775600           -mov dword ptr [0x567770], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666672) /* 0x567770 */) = cpu.ecx;
    // 0051e99f  893574775600           -mov dword ptr [0x567774], esi
    app->getMemory<x86::reg32>(x86::reg32(5666676) /* 0x567774 */) = cpu.esi;
    // 0051e9a5  893d78775600           -mov dword ptr [0x567778], edi
    app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */) = cpu.edi;
    // 0051e9ab  892d7c775600           -mov dword ptr [0x56777c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */) = cpu.ebp;
    // 0051e9b1  a390775600             -mov dword ptr [0x567790], eax
    app->getMemory<x86::reg32>(x86::reg32(5666704) /* 0x567790 */) = cpu.eax;
    // 0051e9b6  ba0ce75100             -mov edx, 0x51e70c
    cpu.edx = 5367564 /*0x51e70c*/;
    // 0051e9bb  bb1ce75100             -mov ebx, 0x51e71c
    cpu.ebx = 5367580 /*0x51e71c*/;
    // 0051e9c0  b980e75100             -mov ecx, 0x51e780
    cpu.ecx = 5367680 /*0x51e780*/;
    // 0051e9c5  be70e65100             -mov esi, 0x51e670
    cpu.esi = 5367408 /*0x51e670*/;
    // 0051e9ca  bfdce65100             -mov edi, 0x51e6dc
    cpu.edi = 5367516 /*0x51e6dc*/;
    // 0051e9cf  bdf0e65100             -mov ebp, 0x51e6f0
    cpu.ebp = 5367536 /*0x51e6f0*/;
    // 0051e9d4  b8e4e65100             -mov eax, 0x51e6e4
    cpu.eax = 5367524 /*0x51e6e4*/;
    // 0051e9d9  891594775600           -mov dword ptr [0x567794], edx
    app->getMemory<x86::reg32>(x86::reg32(5666708) /* 0x567794 */) = cpu.edx;
    // 0051e9df  891dc8ac5600           -mov dword ptr [0x56acc8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5680328) /* 0x56acc8 */) = cpu.ebx;
    // 0051e9e5  890dccac5600           -mov dword ptr [0x56accc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5680332) /* 0x56accc */) = cpu.ecx;
    // 0051e9eb  8935d0ac5600           -mov dword ptr [0x56acd0], esi
    app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */) = cpu.esi;
    // 0051e9f1  893d80775600           -mov dword ptr [0x567780], edi
    app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */) = cpu.edi;
    // 0051e9f7  892d84775600           -mov dword ptr [0x567784], ebp
    app->getMemory<x86::reg32>(x86::reg32(5666692) /* 0x567784 */) = cpu.ebp;
    // 0051e9fd  a388775600             -mov dword ptr [0x567788], eax
    app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */) = cpu.eax;
    // 0051ea02  baf8e65100             -mov edx, 0x51e6f8
    cpu.edx = 5367544 /*0x51e6f8*/;
    // 0051ea07  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051ea0c  b914e75100             -mov ecx, 0x51e714
    cpu.ecx = 5367572 /*0x51e714*/;
    // 0051ea11  be78e75100             -mov esi, 0x51e778
    cpu.esi = 5367672 /*0x51e778*/;
    // 0051ea16  bf34e95100             -mov edi, 0x51e934
    cpu.edi = 5368116 /*0x51e934*/;
    // 0051ea1b  89158c775600           -mov dword ptr [0x56778c], edx
    app->getMemory<x86::reg32>(x86::reg32(5666700) /* 0x56778c */) = cpu.edx;
    // 0051ea21  e81efbffff             -call 0x51e544
    cpu.esp -= 4;
    sub_51e544(app, cpu);
    if (cpu.terminate) return;
    // 0051ea26  8b152c649f00           -mov edx, dword ptr [0x9f642c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10445868) /* 0x9f642c */);
    // 0051ea2c  a350baa000             -mov dword ptr [0xa0ba50], eax
    app->getMemory<x86::reg32>(x86::reg32(10533456) /* 0xa0ba50 */) = cpu.eax;
    // 0051ea31  891d54baa000           -mov dword ptr [0xa0ba54], ebx
    app->getMemory<x86::reg32>(x86::reg32(10533460) /* 0xa0ba54 */) = cpu.ebx;
    // 0051ea37  890d98775600           -mov dword ptr [0x567798], ecx
    app->getMemory<x86::reg32>(x86::reg32(5666712) /* 0x567798 */) = cpu.ecx;
    // 0051ea3d  89359c775600           -mov dword ptr [0x56779c], esi
    app->getMemory<x86::reg32>(x86::reg32(5666716) /* 0x56779c */) = cpu.esi;
    // 0051ea43  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 0051ea49  893da0775600           -mov dword ptr [0x5677a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5666720) /* 0x5677a0 */) = cpu.edi;
    // 0051ea4f  e8cc740000             -call 0x525f20
    cpu.esp -= 4;
    sub_525f20(app, cpu);
    if (cpu.terminate) return;
    // 0051ea54  8b2d2c649f00           -mov ebp, dword ptr [0x9f642c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10445868) /* 0x9f642c */);
    // 0051ea5a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051ea5b  a160775600             -mov eax, dword ptr [0x567760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 0051ea60  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ea61  2eff1518465300         -call dword ptr cs:[0x534618]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457432) /* 0x534618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ea68  c70564775600a8e75100   -mov dword ptr [0x567764], 0x51e7a8
    app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */) = 5367720 /*0x51e7a8*/;
    // 0051ea72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ea78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51ea7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ea7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ea7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ea7e  b820b3a000             -mov eax, 0xa0b320
    cpu.eax = 10531616 /*0xa0b320*/;
    // 0051ea83  ba40b3a000             -mov edx, 0xa0b340
    cpu.edx = 10531648 /*0xa0b340*/;
    // 0051ea88  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ea8e  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x0051ea94:
    // 0051ea94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051ea96  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051ea99  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ea9f  39da                   +cmp edx, ebx
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
    // 0051eaa1  75f1                   -jne 0x51ea94
    if (!cpu.flags.zf)
    {
        goto L_0x0051ea94;
    }
    // 0051eaa3  b870baa000             -mov eax, 0xa0ba70
    cpu.eax = 10533488 /*0xa0ba70*/;
    // 0051eaa8  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eaae  e865fbffff             -call 0x51e618
    cpu.esp -= 4;
    sub_51e618(app, cpu);
    if (cpu.terminate) return;
    // 0051eab3  e8a8750000             -call 0x526060
    cpu.esp -= 4;
    sub_526060(app, cpu);
    if (cpu.terminate) return;
    // 0051eab8  e803570000             -call 0x5241c0
    cpu.esp -= 4;
    sub_5241c0(app, cpu);
    if (cpu.terminate) return;
    // 0051eabd  b840b4a000             -mov eax, 0xa0b440
    cpu.eax = 10531904 /*0xa0b440*/;
    // 0051eac2  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eac8  b830b3a000             -mov eax, 0xa0b330
    cpu.eax = 10531632 /*0xa0b330*/;
    // 0051eacd  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ead3  b860baa000             -mov eax, 0xa0ba60
    cpu.eax = 10533472 /*0xa0ba60*/;
    // 0051ead8  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eade  b850baa000             -mov eax, 0xa0ba50
    cpu.eax = 10533456 /*0xa0ba50*/;
    // 0051eae3  ff15d0ac5600           -call dword ptr [0x56acd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680336) /* 0x56acd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eae9  e8fafaffff             -call 0x51e5e8
    cpu.esp -= 4;
    sub_51e5e8(app, cpu);
    if (cpu.terminate) return;
    // 0051eaee  e84dfeffff             -call 0x51e940
    cpu.esp -= 4;
    sub_51e940(app, cpu);
    if (cpu.terminate) return;
    // 0051eaf3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eaf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eaf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51eb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051eb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051eb01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051eb02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051eb03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051eb04  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051eb06  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051eb08  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051eb0a  2eff1574455300         -call dword ptr cs:[0x534574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457268) /* 0x534574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eb11  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051eb14  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0051eb19  663d0080               +cmp ax, 0x8000
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
    // 0051eb1d  730f                   -jae 0x51eb2e
    if (!cpu.flags.cf)
    {
        goto L_0x0051eb2e;
    }
    // 0051eb1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051eb20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051eb21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051eb22  2eff1548455300         -call dword ptr cs:[0x534548]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457224) /* 0x534548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eb29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051eb2e:
    // 0051eb2e  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 0051eb33  e8c88dfdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051eb38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051eb3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051eb3c  7452                   -je 0x51eb90
    if (cpu.flags.zf)
    {
        goto L_0x0051eb90;
    }
    // 0051eb3e  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 0051eb43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051eb44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051eb45  2eff1544455300         -call dword ptr cs:[0x534544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457220) /* 0x534544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eb4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051eb4e  750e                   -jne 0x51eb5e
    if (!cpu.flags.zf)
    {
        goto L_0x0051eb5e;
    }
    // 0051eb50  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051eb52  e8998efdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051eb57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051eb59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051eb5e:
    // 0051eb5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051eb5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051eb60  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0051eb62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051eb63  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051eb65  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0051eb67  2eff1598455300         -call dword ptr cs:[0x534598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457304) /* 0x534598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eb6e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051eb70  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051eb72  e8798efdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0051eb77  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051eb79  7507                   -jne 0x51eb82
    if (!cpu.flags.zf)
    {
        goto L_0x0051eb82;
    }
    // 0051eb7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051eb7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051eb82:
    // 0051eb82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051eb84  66c7447efe0000         -mov word ptr [esi + edi*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.edi * 2) = 0 /*0x0*/;
    // 0051eb8b  e870670000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
L_0x0051eb90:
    // 0051eb90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eb94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051eba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051eba1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051eba2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051eba3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051eba4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051eba6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051eba8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051eba9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0051ebab  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0051ebad  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051ebaf  49                     -dec ecx
    (cpu.ecx)--;
    // 0051ebb0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051ebb2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051ebb4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0051ebb6  49                     -dec ecx
    (cpu.ecx)--;
    // 0051ebb7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051ebb8  41                     -inc ecx
    (cpu.ecx)++;
    // 0051ebb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051ebbb  e8408dfdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051ebc0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051ebc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ebc4  7418                   -je 0x51ebde
    if (cpu.flags.zf)
    {
        goto L_0x0051ebde;
    }
    // 0051ebc6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0051ebc8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051ebc9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0051ebcb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0051ebcd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ebce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051ebd0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0051ebd3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051ebd5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0051ebd7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0051ebda  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051ebdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ebdd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x0051ebde:
    // 0051ebde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051ebe0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ebe1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ebe2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ebe3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ebe4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51ebf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ebf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ebf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ebf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ebf3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051ebf5  e806670000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0051ebfa  40                     -inc eax
    (cpu.eax)++;
    // 0051ebfb  8d1c4500000000         -lea ebx, [eax*2]
    cpu.ebx = x86::reg32(cpu.eax * 2);
    // 0051ec02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051ec04  e8f78cfdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0051ec09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051ec0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ec0d  7405                   -je 0x51ec14
    if (cpu.flags.zf)
    {
        goto L_0x0051ec14;
    }
    // 0051ec0f  e80c670000             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
L_0x0051ec14:
    // 0051ec14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051ec16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51ec20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ec20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ec21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ec22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ec23  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051ec26  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051ec28  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051ec2a  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0051ec2c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ec30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ec31  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051ec35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ec36  2eff152c465300         -call dword ptr cs:[0x53462c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457452) /* 0x53462c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ec3d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051ec40  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0051ec44  668b0d41785600         -mov cx, word ptr [0x567841]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */);
    // 0051ec4b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051ec4f  6681f90080             +cmp cx, 0x8000
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
    // 0051ec54  7307                   -jae 0x51ec5d
    if (!cpu.flags.cf)
    {
        goto L_0x0051ec5d;
    }
    // 0051ec56  0500300000             +add eax, 0x3000
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
    // 0051ec5b  eb17                   -jmp 0x51ec74
    goto L_0x0051ec74;
L_0x0051ec5d:
    // 0051ec5d  7210                   -jb 0x51ec6f
    if (cpu.flags.cf)
    {
        goto L_0x0051ec6f;
    }
    // 0051ec5f  803d3f78560004         +cmp byte ptr [0x56783f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5666879) /* 0x56783f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051ec66  7307                   -jae 0x51ec6f
    if (!cpu.flags.cf)
    {
        goto L_0x0051ec6f;
    }
    // 0051ec68  0500200100             +add eax, 0x12000
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
    // 0051ec6d  eb05                   -jmp 0x51ec74
    goto L_0x0051ec74;
L_0x0051ec6f:
    // 0051ec6f  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x0051ec74:
    // 0051ec74  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051ec76  7402                   -je 0x51ec7a
    if (cpu.flags.zf)
    {
        goto L_0x0051ec7a;
    }
    // 0051ec78  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0051ec7a:
    // 0051ec7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0051ec7c  7402                   -je 0x51ec80
    if (cpu.flags.zf)
    {
        goto L_0x0051ec80;
    }
    // 0051ec7e  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x0051ec80:
    // 0051ec80  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051ec83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ec86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51ec90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ec90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ec91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051ec92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051ec93  68d4135500             -push 0x5513d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575636 /*0x5513d4*/;
    cpu.esp -= 4;
    // 0051ec98  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ec9f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051eca1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051eca3  7417                   -je 0x51ecbc
    if (cpu.flags.zf)
    {
        goto L_0x0051ecbc;
    }
    // 0051eca5  68e0135500             -push 0x5513e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5575648 /*0x5513e0*/;
    cpu.esp -= 4;
    // 0051ecaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051ecab  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ecb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051ecb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ecb6  7404                   -je 0x51ecbc
    if (cpu.flags.zf)
    {
        goto L_0x0051ecbc;
    }
    // 0051ecb8  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051ecba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0051ecbc:
    // 0051ecbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051ecbe  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0051ecc1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051ecc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ecc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ecc8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ecc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51eccc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051eccc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051eccd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ecce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051eccf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0051ecd1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0051ecd3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051ecd5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051ecd7  7408                   -je 0x51ece1
    if (cpu.flags.zf)
    {
        goto L_0x0051ece1;
    }
L_0x0051ecd9:
    // 0051ecd9  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051ecdc  40                     -inc eax
    (cpu.eax)++;
    // 0051ecdd  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0051ecdf  75f8                   -jne 0x51ecd9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ecd9;
    }
L_0x0051ece1:
    // 0051ece1  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x0051ece4:
    // 0051ece4  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0051ece6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0051ece8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051ecea  7412                   -je 0x51ecfe
    if (cpu.flags.zf)
    {
        goto L_0x0051ecfe;
    }
    // 0051ecec  80f930                 +cmp cl, 0x30
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
    // 0051ecef  7508                   -jne 0x51ecf9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ecf9;
    }
    // 0051ecf1  807a0178               +cmp byte ptr [edx + 1], 0x78
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
    // 0051ecf5  7502                   -jne 0x51ecf9
    if (!cpu.flags.zf)
    {
        goto L_0x0051ecf9;
    }
    // 0051ecf7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0051ecf9:
    // 0051ecf9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051ecfa  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051ecfb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051ecfc  ebe6                   -jmp 0x51ece4
    goto L_0x0051ece4;
L_0x0051ecfe:
    // 0051ecfe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051ed00  741c                   -je 0x51ed1e
    if (cpu.flags.zf)
    {
        goto L_0x0051ed1e;
    }
    // 0051ed02  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051ed04  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0051ed06  7416                   -je 0x51ed1e
    if (cpu.flags.zf)
    {
        goto L_0x0051ed1e;
    }
L_0x0051ed08:
    // 0051ed08  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051ed0a  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0051ed0d  4b                     -dec ebx
    (cpu.ebx)--;
    // 0051ed0e  8a92dcac5600           -mov dl, byte ptr [edx + 0x56acdc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680348) /* 0x56acdc */);
    // 0051ed14  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0051ed17  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0051ed1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ed1c  75ea                   -jne 0x51ed08
    if (!cpu.flags.zf)
    {
        goto L_0x0051ed08;
    }
L_0x0051ed1e:
    // 0051ed1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ed1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ed20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ed21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51ed24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ed24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ed25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ed26  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0051ed2c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0051ed33  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ed35  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051ed38  e853ffffff             -call 0x51ec90
    cpu.esp -= 4;
    sub_51ec90(app, cpu);
    if (cpu.terminate) return;
    // 0051ed3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051ed3f  750a                   -jne 0x51ed4b
    if (!cpu.flags.zf)
    {
        goto L_0x0051ed4b;
    }
    // 0051ed41  e8ee69ffff             -call 0x515734
    cpu.esp -= 4;
    sub_515734(app, cpu);
    if (cpu.terminate) return;
    // 0051ed46  83f8ff                 +cmp eax, -1
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
    // 0051ed49  7507                   -jne 0x51ed52
    if (!cpu.flags.zf)
    {
        goto L_0x0051ed52;
    }
L_0x0051ed4b:
    // 0051ed4b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051ed4d  e98c010000             -jmp 0x51eede
    goto L_0x0051eede;
L_0x0051ed52:
    // 0051ed52  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0051ed54  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0051ed57  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0051ed59  3d900000c0             +cmp eax, 0xc0000090
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
    // 0051ed5e  724d                   -jb 0x51edad
    if (cpu.flags.cf)
    {
        goto L_0x0051edad;
    }
    // 0051ed60  0f86c2000000           -jbe 0x51ee28
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee28;
    }
    // 0051ed66  3d930000c0             +cmp eax, 0xc0000093
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
    // 0051ed6b  7233                   -jb 0x51eda0
    if (cpu.flags.cf)
    {
        goto L_0x0051eda0;
    }
    // 0051ed6d  0f86ab000000           -jbe 0x51ee1e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee1e;
    }
    // 0051ed73  3d960000c0             +cmp eax, 0xc0000096
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
    // 0051ed78  7216                   -jb 0x51ed90
    if (cpu.flags.cf)
    {
        goto L_0x0051ed90;
    }
    // 0051ed7a  0f86ec000000           -jbe 0x51ee6c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee6c;
    }
    // 0051ed80  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 0051ed85  0f84f6000000           -je 0x51ee81
    if (cpu.flags.zf)
    {
        goto L_0x0051ee81;
    }
    // 0051ed8b  e9f8000000             -jmp 0x51ee88
    goto L_0x0051ee88;
L_0x0051ed90:
    // 0051ed90  3d940000c0             +cmp eax, 0xc0000094
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
    // 0051ed95  0f84df000000           -je 0x51ee7a
    if (cpu.flags.zf)
    {
        goto L_0x0051ee7a;
    }
    // 0051ed9b  e9e8000000             -jmp 0x51ee88
    goto L_0x0051ee88;
L_0x0051eda0:
    // 0051eda0  3d910000c0             +cmp eax, 0xc0000091
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
    // 0051eda5  0f8669000000           -jbe 0x51ee14
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee14;
    }
    // 0051edab  eb2f                   -jmp 0x51eddc
    goto L_0x0051eddc;
L_0x0051edad:
    // 0051edad  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 0051edb2  720b                   -jb 0x51edbf
    if (cpu.flags.cf)
    {
        goto L_0x0051edbf;
    }
    // 0051edb4  7640                   -jbe 0x51edf6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051edf6;
    }
    // 0051edb6  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 0051edbb  7643                   -jbe 0x51ee00
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee00;
    }
    // 0051edbd  eb4b                   -jmp 0x51ee0a
    goto L_0x0051ee0a;
L_0x0051edbf:
    // 0051edbf  3d050000c0             +cmp eax, 0xc0000005
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
    // 0051edc4  0f82be000000           -jb 0x51ee88
    if (cpu.flags.cf)
    {
        goto L_0x0051ee88;
    }
    // 0051edca  7666                   -jbe 0x51ee32
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ee32;
    }
    // 0051edcc  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 0051edd1  0f849c000000           -je 0x51ee73
    if (cpu.flags.zf)
    {
        goto L_0x0051ee73;
    }
    // 0051edd7  e9ac000000             -jmp 0x51ee88
    goto L_0x0051ee88;
L_0x0051eddc:
    // 0051eddc  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 0051ede0  740a                   -je 0x51edec
    if (cpu.flags.zf)
    {
        goto L_0x0051edec;
    }
    // 0051ede2  baf0135500             -mov edx, 0x5513f0
    cpu.edx = 5575664 /*0x5513f0*/;
    // 0051ede7  e9af000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051edec:
    // 0051edec  ba44145500             -mov edx, 0x551444
    cpu.edx = 5575748 /*0x551444*/;
    // 0051edf1  e9a5000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051edf6:
    // 0051edf6  ba98145500             -mov edx, 0x551498
    cpu.edx = 5575832 /*0x551498*/;
    // 0051edfb  e99b000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee00:
    // 0051ee00  baec145500             -mov edx, 0x5514ec
    cpu.edx = 5575916 /*0x5514ec*/;
    // 0051ee05  e991000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee0a:
    // 0051ee0a  ba40155500             -mov edx, 0x551540
    cpu.edx = 5576000 /*0x551540*/;
    // 0051ee0f  e987000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee14:
    // 0051ee14  ba94155500             -mov edx, 0x551594
    cpu.edx = 5576084 /*0x551594*/;
    // 0051ee19  e97d000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee1e:
    // 0051ee1e  bae0155500             -mov edx, 0x5515e0
    cpu.edx = 5576160 /*0x5515e0*/;
    // 0051ee23  e973000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee28:
    // 0051ee28  ba30165500             -mov edx, 0x551630
    cpu.edx = 5576240 /*0x551630*/;
    // 0051ee2d  e969000000             -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee32:
    // 0051ee32  ba88165500             -mov edx, 0x551688
    cpu.edx = 5576328 /*0x551688*/;
    // 0051ee37  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee39  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0051ee3c  e88bfeffff             -call 0x51eccc
    cpu.esp -= 4;
    sub_51eccc(app, cpu);
    if (cpu.terminate) return;
    // 0051ee41  babc165500             -mov edx, 0x5516bc
    cpu.edx = 5576380 /*0x5516bc*/;
    // 0051ee46  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee48  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0051ee4b  e87cfeffff             -call 0x51eccc
    cpu.esp -= 4;
    sub_51eccc(app, cpu);
    if (cpu.terminate) return;
    // 0051ee50  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 0051ee54  750b                   -jne 0x51ee61
    if (!cpu.flags.zf)
    {
        goto L_0x0051ee61;
    }
    // 0051ee56  bae4165500             -mov edx, 0x5516e4
    cpu.edx = 5576420 /*0x5516e4*/;
    // 0051ee5b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee5d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051ee5f  eb3f                   -jmp 0x51eea0
    goto L_0x0051eea0;
L_0x0051ee61:
    // 0051ee61  baec165500             -mov edx, 0x5516ec
    cpu.edx = 5576428 /*0x5516ec*/;
    // 0051ee66  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee68  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0051ee6a  eb34                   -jmp 0x51eea0
    goto L_0x0051eea0;
L_0x0051ee6c:
    // 0051ee6c  baf8165500             -mov edx, 0x5516f8
    cpu.edx = 5576440 /*0x5516f8*/;
    // 0051ee71  eb28                   -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee73:
    // 0051ee73  ba38175500             -mov edx, 0x551738
    cpu.edx = 5576504 /*0x551738*/;
    // 0051ee78  eb21                   -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee7a:
    // 0051ee7a  ba74175500             -mov edx, 0x551774
    cpu.edx = 5576564 /*0x551774*/;
    // 0051ee7f  eb1a                   -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee81:
    // 0051ee81  bab8175500             -mov edx, 0x5517b8
    cpu.edx = 5576632 /*0x5517b8*/;
    // 0051ee86  eb13                   -jmp 0x51ee9b
    goto L_0x0051ee9b;
L_0x0051ee88:
    // 0051ee88  baf4175500             -mov edx, 0x5517f4
    cpu.edx = 5576692 /*0x5517f4*/;
    // 0051ee8d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee8f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0051ee91  e836feffff             -call 0x51eccc
    cpu.esp -= 4;
    sub_51eccc(app, cpu);
    if (cpu.terminate) return;
    // 0051ee96  ba28185500             -mov edx, 0x551828
    cpu.edx = 5576744 /*0x551828*/;
L_0x0051ee9b:
    // 0051ee9b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051ee9d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x0051eea0:
    // 0051eea0  e827feffff             -call 0x51eccc
    cpu.esp -= 4;
    sub_51eccc(app, cpu);
    if (cpu.terminate) return;
    // 0051eea5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0051eea7  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0051eeae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051eeaf  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051eeb3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0051eeb4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0051eeb6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0051eeb8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051eeba  49                     -dec ecx
    (cpu.ecx)--;
    // 0051eebb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051eebd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0051eebf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0051eec1  49                     -dec ecx
    (cpu.ecx)--;
    // 0051eec2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051eec3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051eec4  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051eec8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051eec9  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0051eece  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051eed1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051eed2  2eff1540465300         -call dword ptr cs:[0x534640]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457472) /* 0x534640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051eed9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051eede:
    // 0051eede  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0051eee4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eee5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051eee6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51ef08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0051ef08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ef09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ef0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051ef0b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051ef0e  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051ef12  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051ef16  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 0051ef1a  0f85a1010000           -jne 0x51f0c1
    if (!cpu.flags.zf)
    {
        goto L_0x0051f0c1;
    }
    // 0051ef20  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0051ef22  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 0051ef27  83f806                 +cmp eax, 6
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
    // 0051ef2a  0f871f010000           -ja 0x51f04f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051f04f;
    }
    // 0051ef30  2eff2485ecee5100       -jmp dword ptr cs:[eax*4 + 0x51eeec]
    cpu.ip = app->getMemory<x86::reg32>(5369580 + cpu.eax * 4); goto dynamic_jump;
  case 0x0051ef38:
    // 0051ef38  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 0051ef3c  740a                   -je 0x51ef48
    if (cpu.flags.zf)
    {
        goto L_0x0051ef48;
    }
    // 0051ef3e  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 0051ef43  e9ca000000             -jmp 0x51f012
    goto L_0x0051f012;
L_0x0051ef48:
    // 0051ef48  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 0051ef4d  e9c0000000             -jmp 0x51f012
    goto L_0x0051f012;
  case 0x0051ef52:
    // 0051ef52  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 0051ef57  e9b6000000             -jmp 0x51f012
    goto L_0x0051f012;
  case 0x0051ef5c:
    // 0051ef5c  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 0051ef61  e9ac000000             -jmp 0x51f012
    goto L_0x0051f012;
  case 0x0051ef66:
    // 0051ef66  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 0051ef6b  e9a2000000             -jmp 0x51f012
    goto L_0x0051f012;
  case 0x0051ef70:
    // 0051ef70  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 0051ef75  e998000000             -jmp 0x51f012
    goto L_0x0051f012;
  case 0x0051ef7a:
    // 0051ef7a  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0051ef7d  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0051ef80  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 0051ef85  6681fad9fa             +cmp dx, 0xfad9
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
    // 0051ef8a  750a                   -jne 0x51ef96
    if (!cpu.flags.zf)
    {
        goto L_0x0051ef96;
    }
    // 0051ef8c  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 0051ef91  e97c000000             -jmp 0x51f012
    goto L_0x0051f012;
L_0x0051ef96:
    // 0051ef96  6681fad9f1             +cmp dx, 0xf1d9
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
    // 0051ef9b  750a                   -jne 0x51efa7
    if (!cpu.flags.zf)
    {
        goto L_0x0051efa7;
    }
    // 0051ef9d  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 0051efa2  e96b000000             -jmp 0x51f012
    goto L_0x0051f012;
L_0x0051efa7:
    // 0051efa7  750a                   -jne 0x51efb3
    if (!cpu.flags.zf)
    {
        goto L_0x0051efb3;
    }
    // 0051efa9  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 0051efae  e95f000000             -jmp 0x51f012
    goto L_0x0051f012;
L_0x0051efb3:
    // 0051efb3  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 0051efb5  80fedb                 +cmp dh, 0xdb
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
    // 0051efb8  7405                   -je 0x51efbf
    if (cpu.flags.zf)
    {
        goto L_0x0051efbf;
    }
    // 0051efba  80fedf                 +cmp dh, 0xdf
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
    // 0051efbd  7510                   -jne 0x51efcf
    if (!cpu.flags.zf)
    {
        goto L_0x0051efcf;
    }
L_0x0051efbf:
    // 0051efbf  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051efc2  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0051efc5  80fa10                 +cmp dl, 0x10
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
    // 0051efc8  7505                   -jne 0x51efcf
    if (!cpu.flags.zf)
    {
        goto L_0x0051efcf;
    }
    // 0051efca  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x0051efcf:
    // 0051efcf  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 0051efd2  7539                   -jne 0x51f00d
    if (!cpu.flags.zf)
    {
        goto L_0x0051f00d;
    }
    // 0051efd4  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051efd7  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0051efd9  3c30                   +cmp al, 0x30
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
    // 0051efdb  7530                   -jne 0x51f00d
    if (!cpu.flags.zf)
    {
        goto L_0x0051f00d;
    }
    // 0051efdd  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0051efe0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0051efe5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0051efe8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051efea  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 0051efee  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0051eff1  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 0051eff4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0051effa  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051effc  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0051effe  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0051f001  83fa01                 +cmp edx, 1
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
    // 0051f004  7507                   -jne 0x51f00d
    if (!cpu.flags.zf)
    {
        goto L_0x0051f00d;
    }
  [[fallthrough]];
  case 0x0051f006:
    // 0051f006  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 0051f00b  eb05                   -jmp 0x51f012
    goto L_0x0051f012;
L_0x0051f00d:
    // 0051f00d  83fbff                 +cmp ebx, -1
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
    // 0051f010  743d                   -je 0x51f04f
    if (cpu.flags.zf)
    {
        goto L_0x0051f04f;
    }
L_0x0051f012:
    // 0051f012  c60594baa00001         -mov byte ptr [0xa0ba94], 1
    app->getMemory<x86::reg8>(x86::reg32(10533524) /* 0xa0ba94 */) = 1 /*0x1*/;
    // 0051f019  e852700000             -call 0x526070
    cpu.esp -= 4;
    sub_526070(app, cpu);
    if (cpu.terminate) return;
    // 0051f01e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051f020  e81f720000             -call 0x526244
    cpu.esp -= 4;
    sub_526244(app, cpu);
    if (cpu.terminate) return;
    // 0051f025  83f8ff                 +cmp eax, -1
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
    // 0051f028  0f8474000000           -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f02e  803d94baa00000         +cmp byte ptr [0xa0ba94], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10533524) /* 0xa0ba94 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051f035  0f8467000000           -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f03b  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0051f03f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0051f041  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0051f044  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051f046  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 0051f04a  e977000000             -jmp 0x51f0c6
    goto L_0x0051f0c6;
L_0x0051f04f:
    // 0051f04f  833dd8ac560000         +cmp dword ptr [0x56acd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5680344) /* 0x56acd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f056  744a                   -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f058  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051f05d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x0051f05f:
    // 0051f05f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051f061  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0051f063  ff15d4ac5600           -call dword ptr [0x56acd4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680340) /* 0x56acd4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051f06b  742f                   -je 0x51f09c
    if (cpu.flags.zf)
    {
        goto L_0x0051f09c;
    }
    // 0051f06d  83f801                 +cmp eax, 1
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
    // 0051f070  7430                   -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f072  83f802                 +cmp eax, 2
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
    // 0051f075  742b                   -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f077  83f803                 +cmp eax, 3
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
    // 0051f07a  7426                   -je 0x51f0a2
    if (cpu.flags.zf)
    {
        goto L_0x0051f0a2;
    }
    // 0051f07c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051f07e  880d94baa000           -mov byte ptr [0xa0ba94], cl
    app->getMemory<x86::reg8>(x86::reg32(10533524) /* 0xa0ba94 */) = cpu.cl;
    // 0051f084  ff15d8ac5600           -call dword ptr [0x56acd8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5680344) /* 0x56acd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f08a  803d94baa00000         +cmp byte ptr [0xa0ba94], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10533524) /* 0xa0ba94 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051f091  7409                   -je 0x51f09c
    if (cpu.flags.zf)
    {
        goto L_0x0051f09c;
    }
    // 0051f093  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051f095  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f098  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f099  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f09a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f09b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f09c:
    // 0051f09c  43                     -inc ebx
    (cpu.ebx)++;
    // 0051f09d  83fb0c                 +cmp ebx, 0xc
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
    // 0051f0a0  7ebd                   -jle 0x51f05f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051f05f;
    }
L_0x0051f0a2:
    // 0051f0a2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0051f0a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f0a5  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051f0a9  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0051f0ad  2eff151c465300         -call dword ptr cs:[0x53461c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457436) /* 0x53461c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f0b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051f0b6  7409                   -je 0x51f0c1
    if (cpu.flags.zf)
    {
        goto L_0x0051f0c1;
    }
    // 0051f0b8  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0051f0ba  2eff15c0445300         -call dword ptr cs:[0x5344c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457088) /* 0x5344c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051f0c1:
    // 0051f0c1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0051f0c6:
    // 0051f0c6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f0c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f0ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f0cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f0cc  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51f0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f0d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051f0d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051f0d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051f0d4  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f0da  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0051f0dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051f0df  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 0051f0e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051f0e4  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f0ea  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0051f0ed  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0051f0ef  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f0f5  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0051f0f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051f0fa  c7400408ef5100         -mov dword ptr [eax + 4], 0x51ef08
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 5369608 /*0x51ef08*/;
    // 0051f101  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f107  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0051f10a  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 0051f10d  6824ed5100             -push 0x51ed24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5369124 /*0x51ed24*/;
    cpu.esp -= 4;
    // 0051f112  2eff1500465300         -call dword ptr cs:[0x534600]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457408) /* 0x534600 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f119  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f11a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f11b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f11c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f11c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051f11d  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f123  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0051f126  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051f128  7407                   -je 0x51f131
    if (cpu.flags.zf)
    {
        goto L_0x0051f131;
    }
    // 0051f12a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051f12c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051f12e  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x0051f131:
    // 0051f131  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051f137  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 0051f13e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f13f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f141  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f143  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051f144  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f145  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051f146  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0051f149  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051f14b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0051f14d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051f14f  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 0051f152  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 0051f155  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 0051f158  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051f15b  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 0051f15d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051f162  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f165  7523                   -jne 0x51f18a
    if (!cpu.flags.zf)
    {
        goto L_0x0051f18a;
    }
    // 0051f167  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0051f169  7505                   -jne 0x51f170
    if (!cpu.flags.zf)
    {
        goto L_0x0051f170;
    }
    // 0051f16b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0051f170:
    // 0051f170  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 0051f177  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0051f17a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051f17f  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f182  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 0051f185  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 0051f188  eb1f                   -jmp 0x51f1a9
    goto L_0x0051f1a9;
L_0x0051f18a:
    // 0051f18a  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f18d  750d                   -jne 0x51f19c
    if (!cpu.flags.zf)
    {
        goto L_0x0051f19c;
    }
    // 0051f18f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0051f194  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 0051f197  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 0051f19a  eb0d                   -jmp 0x51f1a9
    goto L_0x0051f1a9;
L_0x0051f19c:
    // 0051f19c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 0051f1a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051f1a3  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 0051f1a6  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x0051f1a9:
    // 0051f1a9  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 0051f1ad  7404                   -je 0x51f1b3
    if (cpu.flags.zf)
    {
        goto L_0x0051f1b3;
    }
    // 0051f1af  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0051f1b3:
    // 0051f1b3  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0051f1b5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f1b8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051f1ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051f1bc  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0051f1bf  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0051f1c2  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0051f1c5  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0051f1c8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0051f1cb  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0051f1ce  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 0051f1d0  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051f1d2  83fbff                 +cmp ebx, -1
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
    // 0051f1d5  7505                   -jne 0x51f1dc
    if (!cpu.flags.zf)
    {
        goto L_0x0051f1dc;
    }
    // 0051f1d7  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x0051f1dc:
    // 0051f1dc  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0051f1df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051f1e1  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 0051f1e4  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 0051f1e7  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0051f1ea  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0051f1ed  e8c175ffff             -call 0x5167b3
    cpu.esp -= 4;
    sub_5167b3(app, cpu);
    if (cpu.terminate) return;
    // 0051f1f2  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0051f1f5  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0051f1f8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0051f1fb  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0051f1fe  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0051f201  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0051f204  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0051f207  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0051f20a  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f20e  7d0f                   -jge 0x51f21f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051f21f;
    }
    // 0051f210  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0051f213  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051f216  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0051f219  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 0051f21d  eb29                   -jmp 0x51f248
    goto L_0x0051f248;
L_0x0051f21f:
    // 0051f21f  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 0051f222  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0051f225  740f                   -je 0x51f236
    if (cpu.flags.zf)
    {
        goto L_0x0051f236;
    }
    // 0051f227  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0051f22a  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051f22d  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0051f230  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 0051f234  eb12                   -jmp 0x51f248
    goto L_0x0051f248;
L_0x0051f236:
    // 0051f236  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 0051f239  740d                   -je 0x51f248
    if (cpu.flags.zf)
    {
        goto L_0x0051f248;
    }
    // 0051f23b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0051f23e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051f241  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0051f244  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x0051f248:
    // 0051f248  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0051f24a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051f24c  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051f24f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f252  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f253  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f254  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f255  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051f257  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051f259  e85890fdff             -call 0x4f82b6
    cpu.esp -= 4;
    sub_4f82b6(app, cpu);
    if (cpu.terminate) return;
    // 0051f25e  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051f260  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f261  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51f270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f270  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_51f272(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f272  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 0051f274  9b                     -wait 
    /*nothing*/;
    // 0051f275  dbe3                   +fninit 
    cpu.fpu.init();
    // 0051f277  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0051f279  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0051f27b  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f27d  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0051f27f  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0051f281  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0051f283  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051f285  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 0051f287  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051f288  7402                   -je 0x51f28c
    if (cpu.flags.zf)
    {
        goto L_0x0051f28c;
    }
    // 0051f28a  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x0051f28c:
    // 0051f28c  9b                     -wait 
    /*nothing*/;
    // 0051f28d  dbe3                   -fninit 
    cpu.fpu.init();
    // 0051f28f  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 0051f292  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 0051f296  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0051f298  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51f2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f2a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051f2a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051f2a3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051f2a6  c7442408000000c0       -mov dword ptr [esp + 8], 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 3221225472 /*0xc0000000*/;
    // 0051f2ae  c744240c7e015041       -mov dword ptr [esp + 0xc], 0x4150017e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1095762302 /*0x4150017e*/;
    // 0051f2b6  c7042400000080         -mov dword ptr [esp], 0x80000000
    app->getMemory<x86::reg32>(cpu.esp) = 2147483648 /*0x80000000*/;
    // 0051f2bd  c7442404ffff4741       -mov dword ptr [esp + 4], 0x4147ffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1095237631 /*0x4147ffff*/;
    // 0051f2c5  803dc144560003         +cmp byte ptr [0x5644c1], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051f2cc  7249                   -jb 0x51f317
    if (cpu.flags.cf)
    {
        goto L_0x0051f317;
    }
    // 0051f2ce  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f2d2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051f2d6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051f2d9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f2dd  e85a710000             -call 0x52643c
    cpu.esp -= 4;
    sub_52643c(app, cpu);
    if (cpu.terminate) return;
    // 0051f2e2  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051f2e5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f2e9  e811750000             -call 0x5267ff
    cpu.esp -= 4;
    sub_5267ff(app, cpu);
    if (cpu.terminate) return;
    // 0051f2ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051f2f0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051f2f2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f2f6  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051f2fa  e843730000             -call 0x526642
    cpu.esp -= 4;
    sub_526642(app, cpu);
    if (cpu.terminate) return;
    // 0051f2ff  bb3a8c30e2             -mov ebx, 0xe2308c3a
    cpu.ebx = 3794832442 /*0xe2308c3a*/;
    // 0051f304  b98e79453e             -mov ecx, 0x3e45798e
    cpu.ecx = 1044740494 /*0x3e45798e*/;
    // 0051f309  e88e760000             -call 0x52699c
    cpu.esp -= 4;
    sub_52699c(app, cpu);
    if (cpu.terminate) return;
    // 0051f30e  7e07                   -jle 0x51f317
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051f317;
    }
    // 0051f310  800d5878560001         -or byte ptr [0x567858], 1
    app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0051f317:
    // 0051f317  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051f31a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f31b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f31c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f31d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_51f320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0051f320  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051f322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051f323  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f326  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051f32a  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0051f32d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f331  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f333  0f83d7010000           -jae 0x51f510
    if (!cpu.flags.cf)
    {
        goto L_0x0051f510;
    }
    // 0051f339  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051f33d  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f33f  0f83cb010000           -jae 0x51f510
    if (!cpu.flags.cf)
    {
        goto L_0x0051f510;
    }
    // 0051f345  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f349  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051f34d  81e1ff7f0000           +and ecx, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 0051f353  0f84b7010000           -je 0x51f510
    if (cpu.flags.zf)
    {
        goto L_0x0051f510;
    }
    // 0051f359  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 0051f35e  0f84ac010000           -je 0x51f510
    if (cpu.flags.zf)
    {
        goto L_0x0051f510;
    }
    // 0051f364  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 0051f36a  0f84a0010000           -je 0x51f510
    if (cpu.flags.zf)
    {
        goto L_0x0051f510;
    }
    // 0051f370  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f375  0f8495010000           -je 0x51f510
    if (cpu.flags.zf)
    {
        goto L_0x0051f510;
    }
    // 0051f37b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0051f37f  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 0051f381  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 0051f384  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 0051f386  d97c2418               -fnstcw word ptr [esp + 0x18]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.fpu.control.word;
    // 0051f38a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f38e  81ca3f030000           -or edx, 0x33f
    cpu.edx |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 0051f394  81e2fff30000           -and edx, 0xf3ff
    cpu.edx &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 0051f39a  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0051f39e  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051f3a2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0051f3a4  d8d1                   +fcom st(1)
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(cpu.fpu.st(1)));
    // 0051f3a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f3a7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0051f3a9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0051f3aa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f3ab  7203                   -jb 0x51f3b0
    if (cpu.flags.cf)
    {
        goto L_0x0051f3b0;
    }
    // 0051f3ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0051f3af  42                     -inc edx
    (cpu.edx)++;
L_0x0051f3b0:
    // 0051f3b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f3b1  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0051f3b6  e830770000             -call 0x526aeb
    cpu.esp -= 4;
    sub_526aeb(app, cpu);
    if (cpu.terminate) return;
    // 0051f3bb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f3bc  d9056ccb5600           -fld dword ptr [0x56cb6c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5688172) /* 0x56cb6c */)));
    // 0051f3c2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0051f3c4  db5c2420               -fistp dword ptr [esp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0051f3c8  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051f3cc  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0051f3cf  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0051f3d3  d80d70cb5600           -fmul dword ptr [0x56cb70]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688176) /* 0x56cb70 */));
    // 0051f3d9  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0051f3db  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0051f3dd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0051f3df  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f3e1  dd0528cb5600           -fld qword ptr [0x56cb28]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5688104) /* 0x56cb28 */)));
    // 0051f3e7  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f3e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f3ea  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0051f3ef  e8f7760000             -call 0x526aeb
    cpu.esp -= 4;
    sub_526aeb(app, cpu);
    if (cpu.terminate) return;
    // 0051f3f4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f3f5  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0051f3f7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0051f3f9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0051f3fb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0051f3fd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0051f3ff  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0051f401  db2da6cb5600           -fld xword ptr [0x56cba6]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688230) /* 0x56cba6 */)));
    // 0051f407  db2d9ccb5600           -fld xword ptr [0x56cb9c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688220) /* 0x56cb9c */)));
    // 0051f40d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0051f40f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0051f411  db2d92cb5600           -fld xword ptr [0x56cb92]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688210) /* 0x56cb92 */)));
    // 0051f417  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f419  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0051f41b  db2d88cb5600           -fld xword ptr [0x56cb88]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688200) /* 0x56cb88 */)));
    // 0051f421  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f423  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 0051f425  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0051f427  decc                   -fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f429  db2d7ecb5600           -fld xword ptr [0x56cb7e]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688190) /* 0x56cb7e */)));
    // 0051f42f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0051f431  dec4                   -faddp st(4)
    cpu.fpu.st(4) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f433  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051f437  db2d74cb5600           -fld xword ptr [0x56cb74]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688180) /* 0x56cb74 */)));
    // 0051f43d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0051f43f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051f442  d8ce                   -fmul st(6)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(6));
    // 0051f444  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f446  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f448  d8cd                   +fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 0051f44a  d9cb                   +fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0051f44c  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0051f44e  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f450  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f452  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f456  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 0051f458  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f45a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051f45d  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f45f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0051f461  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f463  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f465  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f467  11d2                   +adc edx, edx
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
    // 0051f469  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f46b  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f46d  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0051f46f  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f471  dba9b0cb5600           +fld xword ptr [ecx + 0x56cbb0]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.ecx + x86::reg32(5688240) /* 0x56cbb0 */)));
    // 0051f477  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f479  ff249538cb5600         -jmp dword ptr [edx*4 + 0x56cb38]
    cpu.ip = app->getMemory<x86::reg32>(5688120 + cpu.edx * 4); goto dynamic_jump;
  case 0x0051f480:
    // 0051f480  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f484  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f487  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f488  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f489  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f48a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f48b:
    // 0051f48b  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0051f48d  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f491  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f494  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f495  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f496  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f497  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f498:
    // 0051f498  db2d58cb5600           -fld xword ptr [0x56cb58]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688152) /* 0x56cb58 */)));
    // 0051f49e  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051f4a0  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f4a4  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f4a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4a9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4aa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f4ab:
    // 0051f4ab  db2d58cb5600           -fld xword ptr [0x56cb58]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688152) /* 0x56cb58 */)));
    // 0051f4b1  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051f4b3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0051f4b5  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f4b9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f4bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4be  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4bf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f4c0:
    // 0051f4c0  db2d62cb5600           -fld xword ptr [0x56cb62]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688162) /* 0x56cb62 */)));
    // 0051f4c6  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051f4c8  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f4cc  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f4cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4d1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f4d3:
    // 0051f4d3  db2d62cb5600           -fld xword ptr [0x56cb62]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688162) /* 0x56cb62 */)));
    // 0051f4d9  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051f4db  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0051f4dd  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f4e1  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f4e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4e6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4e7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f4e8:
    // 0051f4e8  db2d62cb5600           -fld xword ptr [0x56cb62]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688162) /* 0x56cb62 */)));
    // 0051f4ee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f4f0  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f4f4  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f4f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4f9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f4fa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0051f4fb:
    // 0051f4fb  db2d62cb5600           -fld xword ptr [0x56cb62]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5688162) /* 0x56cb62 */)));
    // 0051f501  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0051f503  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0051f505  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f509  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f50c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f50d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f50e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f50f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f510:
    // 0051f510  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 0051f513  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0051f517  d9f3                   -fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0051f519  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0051f51c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f51d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f51e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f51f  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

}
