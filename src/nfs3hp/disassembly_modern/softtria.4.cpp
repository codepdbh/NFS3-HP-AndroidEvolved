#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8d 0x40 0x00 */
void sub_a99698(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99698  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9969d  e9f6000000             -jmp 0xa99798
    return sub_a99798(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a996a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a996a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a996a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a996a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a996a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a996a9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a996ae  e875feffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a996b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a996b5  83f801                 +cmp eax, 1
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
    // 00a996b8  7425                   -je 0xa996df
    if (cpu.flags.zf)
    {
        goto L_0x00a996df;
    }
    // 00a996ba  83f802                 +cmp eax, 2
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
    // 00a996bd  7420                   -je 0xa996df
    if (cpu.flags.zf)
    {
        goto L_0x00a996df;
    }
    // 00a996bf  83f803                 +cmp eax, 3
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
    // 00a996c2  741b                   -je 0xa996df
    if (cpu.flags.zf)
    {
        goto L_0x00a996df;
    }
    // 00a996c4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a996c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a996cb  e810feffff             -call 0xa994e0
    cpu.esp -= 4;
    sub_a994e0(app, cpu);
    if (cpu.terminate) return;
    // 00a996d0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a996d5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a996d7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a996d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a996db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a996df:
    // 00a996df  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a996e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a996e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a996e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a996e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a996e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a996ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a996eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a996ed  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a996ef  83f801                 +cmp eax, 1
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
    // 00a996f2  7c05                   -jl 0xa996f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a996f9;
    }
    // 00a996f4  83f80c                 +cmp eax, 0xc
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
    // 00a996f7  7e13                   -jle 0xa9970c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9970c;
    }
L_0x00a996f9:
    // 00a996f9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a996fe  e8bddcffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a99703  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a99708  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9970a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9970b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9970c:
    // 00a9970c  c7057ce7a9009896a900   -mov dword ptr [0xa9e77c], 0xa99698
    app->getMemory<x86::reg32>(x86::reg32(11134844) /* 0xa9e77c */) = 11114136 /*0xa99698*/;
    // 00a99716  83f902                 +cmp ecx, 2
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
    // 00a99719  741f                   -je 0xa9973a
    if (cpu.flags.zf)
    {
        goto L_0x00a9973a;
    }
    // 00a9971b  83f903                 +cmp ecx, 3
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
    // 00a9971e  741a                   -je 0xa9973a
    if (cpu.flags.zf)
    {
        goto L_0x00a9973a;
    }
    // 00a99720  e827feffff             -call 0xa9954c
    cpu.esp -= 4;
    sub_a9954c(app, cpu);
    if (cpu.terminate) return;
    // 00a99725  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99727  7411                   -je 0xa9973a
    if (cpu.flags.zf)
    {
        goto L_0x00a9973a;
    }
    // 00a99729  83fb02                 +cmp ebx, 2
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
    // 00a9972c  750c                   -jne 0xa9973a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9973a;
    }
    // 00a9972e  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00a99733  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99735  e826210000             -call 0xa9b860
    cpu.esp -= 4;
    sub_a9b860(app, cpu);
    if (cpu.terminate) return;
L_0x00a9973a:
    // 00a9973a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9973c  e8e7fdffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a99741  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a99743  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a99745  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99747  e894fdffff             -call 0xa994e0
    cpu.esp -= 4;
    sub_a994e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9974c  e8a3feffff             -call 0xa995f4
    cpu.esp -= 4;
    sub_a995f4(app, cpu);
    if (cpu.terminate) return;
    // 00a99751  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99753  7407                   -je 0xa9975c
    if (cpu.flags.zf)
    {
        goto L_0x00a9975c;
    }
    // 00a99755  e8d2feffff             -call 0xa9962c
    cpu.esp -= 4;
    sub_a9962c(app, cpu);
    if (cpu.terminate) return;
    // 00a9975a  eb05                   -jmp 0xa99761
    goto L_0x00a99761;
L_0x00a9975c:
    // 00a9975c  e8fbfeffff             -call 0xa9965c
    cpu.esp -= 4;
    sub_a9965c(app, cpu);
    if (cpu.terminate) return;
L_0x00a99761:
    // 00a99761  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a99763  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99764  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99765  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99766  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a99798(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a99798  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99799  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9979a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9979b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9979d  e886fdffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a997a2  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00a997a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a997a7  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a997aa  774d                   -ja 0xa997f9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a997f9;
    }
    // 00a997ac  2eff24956897a900       -jmp dword ptr cs:[edx*4 + 0xa99768]
    cpu.ip = app->getMemory<x86::reg32>(11114344 + cpu.edx * 4); goto dynamic_jump;
  case 0x00a997b4:
    // 00a997b4  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a997b9  e8e6feffff             -call 0xa996a4
    cpu.esp -= 4;
    sub_a996a4(app, cpu);
    if (cpu.terminate) return;
    // 00a997be  eb42                   -jmp 0xa99802
    goto L_0x00a99802;
  case 0x00a997c0:
    // 00a997c0  83f802                 +cmp eax, 2
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
    // 00a997c3  7505                   -jne 0xa997ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a997ca;
    }
    // 00a997c5  e87e200000             -call 0xa9b848
    cpu.esp -= 4;
    sub_a9b848(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00a997ca:
L_0x00a997ca:
    // 00a997ca  83f901                 +cmp ecx, 1
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
    // 00a997cd  741a                   -je 0xa997e9
    if (cpu.flags.zf)
    {
        goto L_0x00a997e9;
    }
    // 00a997cf  83f902                 +cmp ecx, 2
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
    // 00a997d2  7415                   -je 0xa997e9
    if (cpu.flags.zf)
    {
        goto L_0x00a997e9;
    }
    // 00a997d4  83f903                 +cmp ecx, 3
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
    // 00a997d7  7410                   -je 0xa997e9
    if (cpu.flags.zf)
    {
        goto L_0x00a997e9;
    }
    // 00a997d9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a997de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a997e0  e8fbfcffff             -call 0xa994e0
    cpu.esp -= 4;
    sub_a994e0(app, cpu);
    if (cpu.terminate) return;
    // 00a997e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a997e7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a997e9:
    // 00a997e9  e806feffff             -call 0xa995f4
    cpu.esp -= 4;
    sub_a995f4(app, cpu);
    if (cpu.terminate) return;
    // 00a997ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a997f0  7510                   -jne 0xa99802
    if (!cpu.flags.zf)
    {
        goto L_0x00a99802;
    }
    // 00a997f2  e865feffff             -call 0xa9965c
    cpu.esp -= 4;
    sub_a9965c(app, cpu);
    if (cpu.terminate) return;
    // 00a997f7  eb09                   -jmp 0xa99802
    goto L_0x00a99802;
L_0x00a997f9:
    // 00a997f9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a997fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a997ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99801  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99802:
    // 00a99802  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99804  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99805  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99806  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99807  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a99808(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99808  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99809  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9980a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9980b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9980c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9980d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00a99812:
    // 00a99812  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99818  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00a9981b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9981d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9981f  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00a99822  8db2e8e5a900           -lea esi, [edx + 0xa9e5e8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(11134440) /* 0xa9e5e8 */);
    // 00a99828  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9982b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9982c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9982d  83fa68                 +cmp edx, 0x68
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99830  75e0                   -jne 0xa99812
    if (!cpu.flags.zf)
    {
        goto L_0x00a99812;
    }
    // 00a99832  ba7095a900             -mov edx, 0xa99570
    cpu.edx = 11113840 /*0xa99570*/;
    // 00a99837  bb9897a900             -mov ebx, 0xa99798
    cpu.ebx = 11114392 /*0xa99798*/;
    // 00a9983c  8915a0e3a900           -mov dword ptr [0xa9e3a0], edx
    app->getMemory<x86::reg32>(x86::reg32(11133856) /* 0xa9e3a0 */) = cpu.edx;
    // 00a99842  891da4e3a900           -mov dword ptr [0xa9e3a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133860) /* 0xa9e3a4 */) = cpu.ebx;
    // 00a99848  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a99849  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9984a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9984b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9984c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9984d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a99850(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99850  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99851  e89efdffff             -call 0xa995f4
    cpu.esp -= 4;
    sub_a995f4(app, cpu);
    if (cpu.terminate) return;
    // 00a99856  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99858  7423                   -je 0xa9987d
    if (cpu.flags.zf)
    {
        goto L_0x00a9987d;
    }
    // 00a9985a  e8fdfdffff             -call 0xa9965c
    cpu.esp -= 4;
    sub_a9965c(app, cpu);
    if (cpu.terminate) return;
    // 00a9985f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a99864  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a99869  e872fcffff             -call 0xa994e0
    cpu.esp -= 4;
    sub_a994e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9986e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a99873  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a99878  e863fcffff             -call 0xa994e0
    cpu.esp -= 4;
    sub_a994e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a9987d:
    // 00a9987d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9987e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a99880(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99881  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99882  ba0898a900             -mov edx, 0xa99808
    cpu.edx = 11114504 /*0xa99808*/;
    // 00a99887  bb5098a900             -mov ebx, 0xa99850
    cpu.ebx = 11114576 /*0xa99850*/;
    // 00a9988c  8915d4e2a900           -mov dword ptr [0xa9e2d4], edx
    app->getMemory<x86::reg32>(x86::reg32(11133652) /* 0xa9e2d4 */) = cpu.edx;
    // 00a99892  891dd8e2a900           -mov dword ptr [0xa9e2d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133656) /* 0xa9e2d8 */) = cpu.ebx;
    // 00a99898  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99899  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9989a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a998a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a998a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a998a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a998a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a998a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a998a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a998a5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a998a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a998aa  83f8ff                 +cmp eax, -1
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
    // 00a998ad  750e                   -jne 0xa998bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a998bd;
    }
    // 00a998af  2eff15b4cda900         -call dword ptr cs:[0xa9cdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128244) /* 0xa9cdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a998b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a998b8  e998000000             -jmp 0xa99955
    goto L_0x00a99955;
L_0x00a998bd:
    // 00a998bd  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a998c0  750e                   -jne 0xa998d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a998d0;
    }
    // 00a998c2  2eff15f4cda900         -call dword ptr cs:[0xa9cdf4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128308) /* 0xa9cdf4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a998c9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a998cb  e985000000             -jmp 0xa99955
    goto L_0x00a99955;
L_0x00a998d0:
    // 00a998d0  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a998d3  7526                   -jne 0xa998fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a998fb;
    }
    // 00a998d5  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a998da  b8001eaa00             -mov eax, 0xaa1e00
    cpu.eax = 11148800 /*0xaa1e00*/;
    // 00a998df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a998e1  e88ab2ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a998e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a998e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a998ea  8915f01daa00           -mov dword ptr [0xaa1df0], edx
    app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */) = cpu.edx;
    // 00a998f0  891554e6a900           -mov dword ptr [0xa9e654], edx
    app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */) = cpu.edx;
    // 00a998f6  e9ff000000             -jmp 0xa999fa
    goto L_0x00a999fa;
L_0x00a998fb:
    // 00a998fb  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a998fe  7555                   -jne 0xa99955
    if (!cpu.flags.zf)
    {
        goto L_0x00a99955;
    }
    // 00a99900  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a99905  b8001eaa00             -mov eax, 0xaa1e00
    cpu.eax = 11148800 /*0xaa1e00*/;
    // 00a9990a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9990c  e85fb2ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a99911  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 00a99916  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x00a99918:
    // 00a99918  40                     -inc eax
    (cpu.eax)++;
    // 00a99919  8890001eaa00           -mov byte ptr [eax + 0xaa1e00], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148800) /* 0xaa1e00 */) = cpu.dl;
    // 00a9991f  3d9f000000             +cmp eax, 0x9f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(159 /*0x9f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99924  7ef2                   -jle 0xa99918
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99918;
    }
    // 00a99926  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00a9992b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x00a9992d:
    // 00a9992d  40                     -inc eax
    (cpu.eax)++;
    // 00a9992e  88b0001eaa00           -mov byte ptr [eax + 0xaa1e00], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148800) /* 0xaa1e00 */) = cpu.dh;
    // 00a99934  3dfc000000             +cmp eax, 0xfc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99939  7ef2                   -jle 0xa9992d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9992d;
    }
    // 00a9993b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a99940  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 00a99945  892df01daa00           -mov dword ptr [0xaa1df0], ebp
    app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */) = cpu.ebp;
    // 00a9994b  a354e6a900             -mov dword ptr [0xa9e654], eax
    app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */) = cpu.eax;
    // 00a99950  e9a3000000             -jmp 0xa999f8
    goto L_0x00a999f8;
L_0x00a99955:
    // 00a99955  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a99957  7505                   -jne 0xa9995e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9995e;
    }
    // 00a99959  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00a9995e:
    // 00a9995e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a99960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99961  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99962  2eff15b8cda900         -call dword ptr cs:[0xa9cdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128248) /* 0xa9cdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99969  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9996b  750e                   -jne 0xa9997b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9997b;
    }
    // 00a9996d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a99972  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a99975  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99976  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99977  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99978  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99979  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9997a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9997b:
    // 00a9997b  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a99980  b8001eaa00             -mov eax, 0xaa1e00
    cpu.eax = 11148800 /*0xaa1e00*/;
    // 00a99985  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99987  e8e4b1ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9998c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9998e  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a99992  890df01daa00           -mov dword ptr [0xaa1df0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */) = cpu.ecx;
    // 00a99998  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a9999a  740a                   -je 0xa999a6
    if (cpu.flags.zf)
    {
        goto L_0x00a999a6;
    }
    // 00a9999c  c705f01daa0001000000   -mov dword ptr [0xaa1df0], 1
    app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */) = 1 /*0x1*/;
L_0x00a999a6:
    // 00a999a6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a999a8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a999aa  eb1c                   -jmp 0xa999c8
    goto L_0x00a999c8;
L_0x00a999ac:
    // 00a999ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a999ae  8a441c06               -mov al, byte ptr [esp + ebx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
    // 00a999b2  eb07                   -jmp 0xa999bb
    goto L_0x00a999bb;
L_0x00a999b4:
    // 00a999b4  40                     -inc eax
    (cpu.eax)++;
    // 00a999b5  8888001eaa00           -mov byte ptr [eax + 0xaa1e00], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148800) /* 0xaa1e00 */) = cpu.cl;
L_0x00a999bb:
    // 00a999bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a999bd  8a541c07               -mov dl, byte ptr [esp + ebx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
    // 00a999c1  39d0                   +cmp eax, edx
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
    // 00a999c3  7eef                   -jle 0xa999b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a999b4;
    }
    // 00a999c5  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a999c8:
    // 00a999c8  807c1c0600             +cmp byte ptr [esp + ebx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a999cd  75dd                   -jne 0xa999ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a999ac;
    }
    // 00a999cf  807c1c0700             +cmp byte ptr [esp + ebx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a999d4  75d6                   -jne 0xa999ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a999ac;
    }
    // 00a999d6  83fe01                 +cmp esi, 1
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
    // 00a999d9  7517                   -jne 0xa999f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a999f2;
    }
    // 00a999db  2eff15f4cda900         -call dword ptr cs:[0xa9cdf4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128308) /* 0xa9cdf4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a999e2  a354e6a900             -mov dword ptr [0xa9e654], eax
    app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */) = cpu.eax;
    // 00a999e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a999e9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a999ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a999f2:
    // 00a999f2  893554e6a900           -mov dword ptr [0xa9e654], esi
    app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */) = cpu.esi;
L_0x00a999f8:
    // 00a999f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a999fa:
    // 00a999fa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a999fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a999ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99a00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99a01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a99a04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99a04  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a99a06  781e                   -js 0xa99a26
    if (cpu.flags.sf)
    {
        goto L_0x00a99a26;
    }
    // 00a99a08  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a99a0a  7806                   -js 0xa99a12
    if (cpu.flags.sf)
    {
        goto L_0x00a99a12;
    }
    // 00a99a0c  e848000000             -call 0xa99a59
    cpu.esp -= 4;
    sub_a99a59(app, cpu);
    if (cpu.terminate) return;
    // 00a99a11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a12:
    // 00a99a12  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99a14  f7db                   +neg ebx
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
    // 00a99a16  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a19  e83b000000             -call 0xa99a59
    cpu.esp -= 4;
    sub_a99a59(app, cpu);
    if (cpu.terminate) return;
    // 00a99a1e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a99a20  f7d8                   +neg eax
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
    // 00a99a22  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a26:
    // 00a99a26  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a99a28  f7d8                   +neg eax
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
    // 00a99a2a  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a2d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a99a2f  7914                   -jns 0xa99a45
    if (!cpu.flags.sf)
    {
        goto L_0x00a99a45;
    }
    // 00a99a31  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99a33  f7db                   +neg ebx
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
    // 00a99a35  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a38  e81c000000             -call 0xa99a59
    cpu.esp -= 4;
    sub_a99a59(app, cpu);
    if (cpu.terminate) return;
    // 00a99a3d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99a3f  f7db                   +neg ebx
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
    // 00a99a41  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a45:
    // 00a99a45  e80f000000             -call 0xa99a59
    cpu.esp -= 4;
    sub_a99a59(app, cpu);
    if (cpu.terminate) return;
    // 00a99a4a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99a4c  f7db                   +neg ebx
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
    // 00a99a4e  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a51  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a99a53  f7d8                   +neg eax
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
    // 00a99a55  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a99a58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99a59(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99a59  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a99a5b  751a                   -jne 0xa99a77
    if (!cpu.flags.zf)
    {
        goto L_0x00a99a77;
    }
    // 00a99a5d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99a5e  7416                   -je 0xa99a76
    if (cpu.flags.zf)
    {
        goto L_0x00a99a76;
    }
    // 00a99a60  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99a61  39d3                   +cmp ebx, edx
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
    // 00a99a63  7709                   -ja 0xa99a6e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a99a6e;
    }
    // 00a99a65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a99a67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99a69  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99a6b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a99a6d  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x00a99a6e:
    // 00a99a6e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a99a70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a99a72  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a99a74  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a99a76:
    // 00a99a76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a77:
    // 00a99a77  39d1                   +cmp ecx, edx
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
    // 00a99a79  721c                   -jb 0xa99a97
    if (cpu.flags.cf)
    {
        goto L_0x00a99a97;
    }
    // 00a99a7b  7512                   -jne 0xa99a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00a99a8f;
    }
    // 00a99a7d  39c3                   +cmp ebx, eax
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
    // 00a99a7f  770e                   -ja 0xa99a8f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a99a8f;
    }
    // 00a99a81  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a99a83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99a85  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99a87  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99a89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a99a8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a8f:
    // 00a99a8f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99a91  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a99a93  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99a94  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 00a99a96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99a97:
    // 00a99a97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99a98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99a99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99a9a  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a99a9c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a99a9e  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00a99aa0:
    // 00a99aa0  01db                   +add ebx, ebx
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
    // 00a99aa2  11c9                   +adc ecx, ecx
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
    // 00a99aa4  7213                   -jb 0xa99ab9
    if (cpu.flags.cf)
    {
        goto L_0x00a99ab9;
    }
    // 00a99aa6  45                     -inc ebp
    (cpu.ebp)++;
    // 00a99aa7  39d1                   +cmp ecx, edx
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
    // 00a99aa9  72f5                   -jb 0xa99aa0
    if (cpu.flags.cf)
    {
        goto L_0x00a99aa0;
    }
    // 00a99aab  7704                   -ja 0xa99ab1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a99ab1;
    }
    // 00a99aad  39c3                   +cmp ebx, eax
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
    // 00a99aaf  76ef                   -jbe 0xa99aa0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a99aa0;
    }
L_0x00a99ab1:
    // 00a99ab1  f8                     +clc 
    cpu.flags.cf = 0;
L_0x00a99ab2:
    // 00a99ab2  11f6                   +adc esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99ab4  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99ab6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99ab7  7822                   -js 0xa99adb
    if (cpu.flags.sf)
    {
        goto L_0x00a99adb;
    }
L_0x00a99ab9:
    // 00a99ab9  d1d9                   +rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
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
    // 00a99abb  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 00a99abd  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99abf  19ca                   +sbb edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99ac1  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 00a99ac2  72ee                   -jb 0xa99ab2
    if (cpu.flags.cf)
    {
        goto L_0x00a99ab2;
    }
L_0x00a99ac4:
    // 00a99ac4  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99ac6  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99ac8  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99ac9  780c                   -js 0xa99ad7
    if (cpu.flags.sf)
    {
        goto L_0x00a99ad7;
    }
    // 00a99acb  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a99acd  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 00a99acf  01d8                   +add eax, ebx
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
    // 00a99ad1  11ca                   +adc edx, ecx
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
    // 00a99ad3  73ef                   -jae 0xa99ac4
    if (!cpu.flags.cf)
    {
        goto L_0x00a99ac4;
    }
    // 00a99ad5  ebdb                   -jmp 0xa99ab2
    goto L_0x00a99ab2;
L_0x00a99ad7:
    // 00a99ad7  01d8                   +add eax, ebx
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
    // 00a99ad9  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x00a99adb:
    // 00a99adb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99add  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a99adf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a99ae1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a99ae3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99ae4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99ae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99ae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99ae7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99ae7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99ae8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a99aea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99aeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99aec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99aed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99aee  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a99af1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99af3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a99af5  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99afb  7c05                   -jl 0xa99b02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a99b02;
    }
    // 00a99afd  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a99b02:
    // 00a99b02  b958e6a900             -mov ecx, 0xa9e658
    cpu.ecx = 11134552 /*0xa9e658*/;
    // 00a99b07  eb2e                   -jmp 0xa99b37
    goto L_0x00a99b37;
L_0x00a99b09:
    // 00a99b09  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a99b0e  7422                   -je 0xa99b32
    if (cpu.flags.zf)
    {
        goto L_0x00a99b32;
    }
    // 00a99b10  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a99b14  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a99b18  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a99b1b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a99b1e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99b21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a99b23  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a99b25  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a99b28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a99b2a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99b2c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99b2e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99b30  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a99b32:
    // 00a99b32  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a99b34  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a99b37:
    // 00a99b37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a99b39  7fce                   -jg 0xa99b09
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a99b09;
    }
    // 00a99b3b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a99b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99b3b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a99b3b;
    // 00a99ae7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99ae8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a99aea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99aeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99aec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99aed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99aee  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a99af1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99af3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a99af5  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99afb  7c05                   -jl 0xa99b02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a99b02;
    }
    // 00a99afd  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a99b02:
    // 00a99b02  b958e6a900             -mov ecx, 0xa9e658
    cpu.ecx = 11134552 /*0xa9e658*/;
    // 00a99b07  eb2e                   -jmp 0xa99b37
    goto L_0x00a99b37;
L_0x00a99b09:
    // 00a99b09  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a99b0e  7422                   -je 0xa99b32
    if (cpu.flags.zf)
    {
        goto L_0x00a99b32;
    }
    // 00a99b10  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a99b14  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a99b18  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a99b1b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a99b1e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99b21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a99b23  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a99b25  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a99b28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a99b2a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99b2c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99b2e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99b30  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a99b32:
    // 00a99b32  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a99b34  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a99b37:
    // 00a99b37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a99b39  7fce                   -jg 0xa99b09
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a99b09;
    }
L_entry_0x00a99b3b:
    // 00a99b3b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a99b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99b44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99b44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99b45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a99b47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99b48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99b49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99b4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99b4b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a99b4e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a99b50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99b52  74e7                   -je 0xa99b3b
    if (cpu.flags.zf)
    {
        return sub_a99b3b(app, cpu);
    }
    // 00a99b54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99b56  9b                     -wait 
    /*nothing*/;
    // 00a99b57  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99b5a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b5b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a99b5d  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a99b60  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a99b65  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 00a99b6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99b6b  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99b6e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99b6f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a99b71  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 00a99b75  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00a99b7a  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a99b7d  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a99b80  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99b82  7d1b                   -jge 0xa99b9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99b9f;
    }
    // 00a99b84  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99b87  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a99b89  e859ffffff             -call 0xa99ae7
    cpu.esp -= 4;
    sub_a99ae7(app, cpu);
    if (cpu.terminate) return;
    // 00a99b8e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a99b90  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99b93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99b95  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99b97  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99b99  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99b9b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99b9d  eb17                   -jmp 0xa99bb6
    goto L_0x00a99bb6;
L_0x00a99b9f:
    // 00a99b9f  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99ba2  e840ffffff             -call 0xa99ae7
    cpu.esp -= 4;
    sub_a99ae7(app, cpu);
    if (cpu.terminate) return;
    // 00a99ba7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a99ba9  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99bac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99bae  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99bb0  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99bb2  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99bb4  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a99bb6:
    // 00a99bb6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a99bb8  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 00a99bbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99bbc  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99bbf  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99bc0  e976ffffff             -jmp 0xa99b3b
    return sub_a99b3b(app, cpu);
}

/* align: skip  */
void sub_a99bc5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99bc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99bc6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99bc7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a99bc9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a99bcb  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99bd1  7e12                   -jle 0xa99be5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99be5;
    }
    // 00a99bd3  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 00a99bd8  e867ffffff             -call 0xa99b44
    cpu.esp -= 4;
    sub_a99b44(app, cpu);
    if (cpu.terminate) return;
    // 00a99bdd  81eb00100000           +sub ebx, 0x1000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99be3  eb18                   -jmp 0xa99bfd
    goto L_0x00a99bfd;
L_0x00a99be5:
    // 00a99be5  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99beb  7d10                   -jge 0xa99bfd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99bfd;
    }
    // 00a99bed  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 00a99bf2  e84dffffff             -call 0xa99b44
    cpu.esp -= 4;
    sub_a99b44(app, cpu);
    if (cpu.terminate) return;
    // 00a99bf7  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x00a99bfd:
    // 00a99bfd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a99bff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99c01  e83effffff             -call 0xa99b44
    cpu.esp -= 4;
    sub_a99b44(app, cpu);
    if (cpu.terminate) return;
    // 00a99c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: 8bc0b29ca900ee9ca900c09ca900de9ca900b29ca900 */
void sub_a99c1f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a99c1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99c20  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a99c22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99c23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99c24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99c25  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a99c2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99c2d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a99c2f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a99c32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99c34  9b                     -wait 
    /*nothing*/;
    // 00a99c35  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99c38  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c39  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a99c3c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a99c3f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a99c44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99c45  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99c48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c49  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a99c50  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a99c54  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a99c58  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a99c5b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a99c5e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a99c60  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a99c63  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a99c67  7407                   -je 0xa99c70
    if (cpu.flags.zf)
    {
        goto L_0x00a99c70;
    }
    // 00a99c69  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a99c70:
    // 00a99c70  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a99c74  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a99c7b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a99c82  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a99c89  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99c8c  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a99c93  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a99c95  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a99c9c  e80b1c0000             -call 0xa9b8ac
    cpu.esp -= 4;
    sub_a9b8ac(app, cpu);
    if (cpu.terminate) return;
    // 00a99ca1  83f804                 +cmp eax, 4
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
    // 00a99ca4  0f8749010000           -ja 0xa99df3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a99df3;
    }
    // 00a99caa  2eff24850b9ca900       -jmp dword ptr cs:[eax*4 + 0xa99c0b]
    cpu.ip = app->getMemory<x86::reg32>(11115531 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a99cb2:
    // 00a99cb2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a99cb9:
    // 00a99cb9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a99cbb  e933010000             -jmp 0xa99df3
    goto L_0x00a99df3;
  case 0x00a99cc0:
    // 00a99cc0  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a99cc3  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a99cc6  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a99cca  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a99cce:
    // 00a99cce  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a99cd2  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a99cd9  e970030000             -jmp 0xa9a04e
    return sub_a9a04e(app, cpu);
  case 0x00a99cde:
    // 00a99cde  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a99ce1  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a99ce4  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a99ce8  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a99cec  ebe0                   -jmp 0xa99cce
    goto L_0x00a99cce;
  case 0x00a99cee:
    // 00a99cee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99cf0  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99cf4  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a99cfa  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a99d00  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a99d05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99d07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a99d0a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a99d0c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a99d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a99d11  0f84dc000000           -je 0xa99df3
    if (cpu.flags.zf)
    {
        goto L_0x00a99df3;
    }
    // 00a99d17  7d0f                   -jge 0xa99d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99d28;
    }
    // 00a99d19  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99d1b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a99d1e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a99d21  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a99d23  e9bf000000             -jmp 0xa99de7
    goto L_0x00a99de7;
L_0x00a99d28:
    // 00a99d28  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99d2b  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99d30  7287                   -jb 0xa99cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a99cb9;
    }
    // 00a99d32  750d                   -jne 0xa99d41
    if (!cpu.flags.zf)
    {
        goto L_0x00a99d41;
    }
    // 00a99d34  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d3b  0f8278ffffff           -jb 0xa99cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a99cb9;
    }
L_0x00a99d41:
    // 00a99d41  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99d44  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99d48  7220                   -jb 0xa99d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a99d6a;
    }
    // 00a99d4a  0f8594000000           -jne 0xa99de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a99de4;
    }
    // 00a99d50  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a99d53  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d59  720f                   -jb 0xa99d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a99d6a;
    }
    // 00a99d5b  0f8583000000           -jne 0xa99de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a99de4;
    }
    // 00a99d61  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d68  737a                   -jae 0xa99de4
    if (!cpu.flags.cf)
    {
        goto L_0x00a99de4;
    }
L_0x00a99d6a:
    // 00a99d6a  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a99d6f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99d72  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99d75  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a99d79  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a99d7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99d80  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a99d83  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d86  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a99d89  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99d8b  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99d8d  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99d8f  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99d91  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d94  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d97  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99d9a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99d9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99d9e  9b                     -wait 
    /*nothing*/;
    // 00a99d9f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99da2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99da3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99da4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a99da7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99da8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99dab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99dac  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a99db0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99db3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99db4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99db5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99db7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99db8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a99dbb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99dbc  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99dbe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99dc1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99dc4  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99dc6  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99dc8  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99dca  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99dcc  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dcf  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99dd2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dd5  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a99dda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99ddc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99dde  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99de0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99de2  eb0f                   -jmp 0xa99df3
    goto L_0x00a99df3;
L_0x00a99de4:
    // 00a99de4  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a99de7:
    // 00a99de7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a99de9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dec  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a99dee  e8d2fdffff             -call 0xa99bc5
    cpu.esp -= 4;
    sub_a99bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a99df3:
    // 00a99df3  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a99df7  7416                   -je 0xa99e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a99e0f;
    }
    // 00a99df9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99dfb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99dfd  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a99e00  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a99e03  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a99e06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99e08  7e0d                   -jle 0xa99e17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99e17;
    }
    // 00a99e0a  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99e0d  eb08                   -jmp 0xa99e17
    goto L_0x00a99e17;
L_0x00a99e0f:
    // 00a99e0f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99e11  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a99e14  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a99e17:
    // 00a99e17  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a99e1a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a99e1f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a99e22  7405                   -je 0xa99e29
    if (cpu.flags.zf)
    {
        goto L_0x00a99e29;
    }
    // 00a99e24  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a99e29:
    // 00a99e29  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a99e2d  7402                   -je 0xa99e31
    if (cpu.flags.zf)
    {
        goto L_0x00a99e31;
    }
    // 00a99e2f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a99e31:
    // 00a99e31  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a99e34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a99e37  39d8                   +cmp eax, ebx
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
    // 00a99e39  7d03                   -jge 0xa99e3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99e3e;
    }
    // 00a99e3b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a99e3e:
    // 00a99e3e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a99e45  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a99e47  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a99e4d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a99e53  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a99e56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99e58  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00a99e5b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a99e5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99e60  0f8ee8000000           -jle 0xa99f4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a99f4e(app, cpu);
    }
    // 00a99e66  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a99e69  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a99e6c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99e6e  7572                   -jne 0xa99ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00a99ee2;
    }
    // 00a99e70  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a99e76  0f84d2000000           -je 0xa99f4e
    if (cpu.flags.zf)
    {
        return sub_a99f4e(app, cpu);
    }
    // 00a99e7c  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99e7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99e81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e83  9b                     -wait 
    /*nothing*/;
    // 00a99e84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99e87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e89  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a99e8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99e90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e91  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a99e95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99e98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99e9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99e9e  7e42                   -jle 0xa99ee2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99ee2;
    }
    // 00a99ea0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99ea3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99ea6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99ea7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a99eaa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99eab  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99ead  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99eb0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99eb3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99eb5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99eb7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99eb9  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99ebb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a99ec0  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a99ec5  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99ec8  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a99ecc  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a99ecf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a99ed1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99ed4  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a99ed7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99eda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99edc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99ede  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99ee0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a99ee2:
    // 00a99ee2  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a99ee5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a99ee7  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a99eea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99eeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99eec  e802000000             -call 0xa99ef3
    cpu.esp -= 4;
    sub_a99ef3(app, cpu);
    if (cpu.terminate) return;
    // 00a99ef1  eb45                   -jmp 0xa99f38
    return sub_a99f38(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a99e5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x00a99e5b;
    // 00a99c1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99c20  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a99c22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99c23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99c24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99c25  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a99c2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99c2d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a99c2f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a99c32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99c34  9b                     -wait 
    /*nothing*/;
    // 00a99c35  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99c38  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c39  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a99c3c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a99c3f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a99c44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99c45  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99c48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99c49  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a99c50  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a99c54  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a99c58  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a99c5b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a99c5e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a99c60  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a99c63  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a99c67  7407                   -je 0xa99c70
    if (cpu.flags.zf)
    {
        goto L_0x00a99c70;
    }
    // 00a99c69  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a99c70:
    // 00a99c70  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a99c74  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a99c7b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a99c82  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a99c89  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99c8c  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a99c93  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a99c95  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a99c9c  e80b1c0000             -call 0xa9b8ac
    cpu.esp -= 4;
    sub_a9b8ac(app, cpu);
    if (cpu.terminate) return;
    // 00a99ca1  83f804                 +cmp eax, 4
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
    // 00a99ca4  0f8749010000           -ja 0xa99df3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a99df3;
    }
    // 00a99caa  2eff24850b9ca900       -jmp dword ptr cs:[eax*4 + 0xa99c0b]
    cpu.ip = app->getMemory<x86::reg32>(11115531 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a99cb2:
    // 00a99cb2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a99cb9:
    // 00a99cb9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a99cbb  e933010000             -jmp 0xa99df3
    goto L_0x00a99df3;
  case 0x00a99cc0:
    // 00a99cc0  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a99cc3  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a99cc6  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a99cca  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a99cce:
    // 00a99cce  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a99cd2  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a99cd9  e970030000             -jmp 0xa9a04e
    return sub_a9a04e(app, cpu);
  case 0x00a99cde:
    // 00a99cde  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a99ce1  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a99ce4  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a99ce8  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a99cec  ebe0                   -jmp 0xa99cce
    goto L_0x00a99cce;
  case 0x00a99cee:
    // 00a99cee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99cf0  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99cf4  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a99cfa  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a99d00  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a99d05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99d07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a99d0a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a99d0c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a99d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a99d11  0f84dc000000           -je 0xa99df3
    if (cpu.flags.zf)
    {
        goto L_0x00a99df3;
    }
    // 00a99d17  7d0f                   -jge 0xa99d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99d28;
    }
    // 00a99d19  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a99d1b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a99d1e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a99d21  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a99d23  e9bf000000             -jmp 0xa99de7
    goto L_0x00a99de7;
L_0x00a99d28:
    // 00a99d28  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99d2b  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99d30  7287                   -jb 0xa99cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a99cb9;
    }
    // 00a99d32  750d                   -jne 0xa99d41
    if (!cpu.flags.zf)
    {
        goto L_0x00a99d41;
    }
    // 00a99d34  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d3b  0f8278ffffff           -jb 0xa99cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a99cb9;
    }
L_0x00a99d41:
    // 00a99d41  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a99d44  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99d48  7220                   -jb 0xa99d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a99d6a;
    }
    // 00a99d4a  0f8594000000           -jne 0xa99de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a99de4;
    }
    // 00a99d50  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a99d53  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d59  720f                   -jb 0xa99d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a99d6a;
    }
    // 00a99d5b  0f8583000000           -jne 0xa99de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a99de4;
    }
    // 00a99d61  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99d68  737a                   -jae 0xa99de4
    if (!cpu.flags.cf)
    {
        goto L_0x00a99de4;
    }
L_0x00a99d6a:
    // 00a99d6a  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a99d6f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99d72  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99d75  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a99d79  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a99d7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99d80  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a99d83  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d86  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a99d89  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99d8b  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99d8d  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99d8f  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99d91  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d94  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99d97  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99d9a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99d9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99d9e  9b                     -wait 
    /*nothing*/;
    // 00a99d9f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99da2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99da3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99da4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a99da7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99da8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99dab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99dac  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a99db0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99db3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99db4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99db5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99db7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99db8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a99dbb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99dbc  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99dbe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99dc1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a99dc4  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99dc6  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99dc8  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99dca  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99dcc  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dcf  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a99dd2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dd5  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a99dda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99ddc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99dde  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99de0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99de2  eb0f                   -jmp 0xa99df3
    goto L_0x00a99df3;
L_0x00a99de4:
    // 00a99de4  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a99de7:
    // 00a99de7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a99de9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99dec  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a99dee  e8d2fdffff             -call 0xa99bc5
    cpu.esp -= 4;
    sub_a99bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a99df3:
    // 00a99df3  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a99df7  7416                   -je 0xa99e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a99e0f;
    }
    // 00a99df9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99dfb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a99dfd  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a99e00  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a99e03  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a99e06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99e08  7e0d                   -jle 0xa99e17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99e17;
    }
    // 00a99e0a  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99e0d  eb08                   -jmp 0xa99e17
    goto L_0x00a99e17;
L_0x00a99e0f:
    // 00a99e0f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99e11  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a99e14  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a99e17:
    // 00a99e17  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a99e1a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a99e1f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a99e22  7405                   -je 0xa99e29
    if (cpu.flags.zf)
    {
        goto L_0x00a99e29;
    }
    // 00a99e24  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a99e29:
    // 00a99e29  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a99e2d  7402                   -je 0xa99e31
    if (cpu.flags.zf)
    {
        goto L_0x00a99e31;
    }
    // 00a99e2f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a99e31:
    // 00a99e31  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a99e34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a99e37  39d8                   +cmp eax, ebx
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
    // 00a99e39  7d03                   -jge 0xa99e3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99e3e;
    }
    // 00a99e3b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a99e3e:
    // 00a99e3e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a99e45  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a99e47  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a99e4d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a99e53  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a99e56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99e58  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x00a99e5b:
    // 00a99e5b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a99e5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99e60  0f8ee8000000           -jle 0xa99f4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a99f4e(app, cpu);
    }
    // 00a99e66  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a99e69  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a99e6c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99e6e  7572                   -jne 0xa99ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00a99ee2;
    }
    // 00a99e70  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a99e76  0f84d2000000           -je 0xa99f4e
    if (cpu.flags.zf)
    {
        return sub_a99f4e(app, cpu);
    }
    // 00a99e7c  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99e7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99e81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e83  9b                     -wait 
    /*nothing*/;
    // 00a99e84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a99e87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e89  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a99e8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99e8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99e90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e91  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a99e95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a99e98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99e9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a99e9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99e9e  7e42                   -jle 0xa99ee2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99ee2;
    }
    // 00a99ea0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99ea3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99ea6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a99ea7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a99eaa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99eab  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99ead  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99eb0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99eb3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99eb5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99eb7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99eb9  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a99ebb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a99ec0  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a99ec5  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a99ec8  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a99ecc  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a99ecf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a99ed1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99ed4  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a99ed7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a99eda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a99edc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a99ede  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a99ee0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a99ee2:
    // 00a99ee2  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a99ee5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a99ee7  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a99eea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99eeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99eec  e802000000             -call 0xa99ef3
    cpu.esp -= 4;
    sub_a99ef3(app, cpu);
    if (cpu.terminate) return;
    // 00a99ef1  eb45                   -jmp 0xa99f38
    return sub_a99f38(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a99ef3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a99ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99efa  39c8                   +cmp eax, ecx
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
    // 00a99efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99efd  7203                   -jb 0xa99f02
    if (cpu.flags.cf)
    {
        goto L_0x00a99f02;
    }
    // 00a99eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f02:
    // 00a99f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f03  e801000000             -call 0xa99f09
    cpu.esp -= 4;
    sub_a99f09(app, cpu);
    if (cpu.terminate) return;
    // 00a99f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a99f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99f10  39c8                   +cmp eax, ecx
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
    // 00a99f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f13  7204                   -jb 0xa99f19
    if (cpu.flags.cf)
    {
        goto L_0x00a99f19;
    }
    // 00a99f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f19:
    // 00a99f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f1a  e801000000             -call 0xa99f20
    cpu.esp -= 4;
    sub_a99f20(app, cpu);
    if (cpu.terminate) return;
    // 00a99f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a99f22  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f26  7204                   -jb 0xa99f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a99f2c;
    }
    // 00a99f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a99f2c:
    // 00a99f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a99f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a99f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99f09(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a99f09;
    // 00a99ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a99ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99efa  39c8                   +cmp eax, ecx
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
    // 00a99efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99efd  7203                   -jb 0xa99f02
    if (cpu.flags.cf)
    {
        goto L_0x00a99f02;
    }
    // 00a99eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f02:
    // 00a99f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f03  e801000000             -call 0xa99f09
    cpu.esp -= 4;
    sub_a99f09(app, cpu);
    if (cpu.terminate) return;
    // 00a99f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a99f09:
    // 00a99f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a99f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99f10  39c8                   +cmp eax, ecx
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
    // 00a99f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f13  7204                   -jb 0xa99f19
    if (cpu.flags.cf)
    {
        goto L_0x00a99f19;
    }
    // 00a99f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f19:
    // 00a99f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f1a  e801000000             -call 0xa99f20
    cpu.esp -= 4;
    sub_a99f20(app, cpu);
    if (cpu.terminate) return;
    // 00a99f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a99f22  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f26  7204                   -jb 0xa99f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a99f2c;
    }
    // 00a99f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a99f2c:
    // 00a99f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a99f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a99f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99f20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a99f20;
    // 00a99ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a99ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99efa  39c8                   +cmp eax, ecx
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
    // 00a99efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99efd  7203                   -jb 0xa99f02
    if (cpu.flags.cf)
    {
        goto L_0x00a99f02;
    }
    // 00a99eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f02:
    // 00a99f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f03  e801000000             -call 0xa99f09
    cpu.esp -= 4;
    sub_a99f09(app, cpu);
    if (cpu.terminate) return;
    // 00a99f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a99f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99f10  39c8                   +cmp eax, ecx
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
    // 00a99f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f13  7204                   -jb 0xa99f19
    if (cpu.flags.cf)
    {
        goto L_0x00a99f19;
    }
    // 00a99f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a99f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a99f19:
    // 00a99f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99f1a  e801000000             -call 0xa99f20
    cpu.esp -= 4;
    sub_a99f20(app, cpu);
    if (cpu.terminate) return;
    // 00a99f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a99f20:
    // 00a99f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a99f22  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f26  7204                   -jb 0xa99f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a99f2c;
    }
    // 00a99f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a99f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a99f2c:
    // 00a99f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a99f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a99f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a99f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a99f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99f38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99f38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99f3a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a99f3c  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a99f3e  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 00a99f41  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a99f44  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a99f46  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00a99f49  e90dffffff             -jmp 0xa99e5b
    return sub_a99e5b(app, cpu);
}

/* align: skip  */
void sub_a99f4e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99f4e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a99f51  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a99f57  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a99f5a:
    // 00a99f5a  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99f5d  7505                   -jne 0xa99f64
    if (!cpu.flags.zf)
    {
        goto L_0x00a99f64;
    }
    // 00a99f5f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99f60  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99f61  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a99f62  ebf6                   -jmp 0xa99f5a
    goto L_0x00a99f5a;
L_0x00a99f64:
    // 00a99f64  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a99f67  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99f69  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a99f6c  740a                   -je 0xa99f78
    if (cpu.flags.zf)
    {
        goto L_0x00a99f78;
    }
    // 00a99f6e  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a99f71  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a99f74  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99f76  eb15                   -jmp 0xa99f8d
    goto L_0x00a99f8d;
L_0x00a99f78:
    // 00a99f78  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a99f7b  7410                   -je 0xa99f8d
    if (cpu.flags.zf)
    {
        goto L_0x00a99f8d;
    }
    // 00a99f7d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a99f80  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99f82  7e03                   -jle 0xa99f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99f87;
    }
    // 00a99f84  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a99f85  eb02                   -jmp 0xa99f89
    goto L_0x00a99f89;
L_0x00a99f87:
    // 00a99f87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a99f89:
    // 00a99f89  41                     -inc ecx
    (cpu.ecx)++;
    // 00a99f8a  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a99f8d:
    // 00a99f8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99f8f  0f8c65000000           -jl 0xa99ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a99ffa;
    }
    // 00a99f95  39c7                   +cmp edi, eax
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
    // 00a99f97  7e02                   -jle 0xa99f9b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99f9b;
    }
    // 00a99f99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a99f9b:
    // 00a99f9b  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a99fa0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a99fa4  7405                   -je 0xa99fab
    if (cpu.flags.zf)
    {
        goto L_0x00a99fab;
    }
    // 00a99fa6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a99fab:
    // 00a99fab  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a99faf  7402                   -je 0xa99fb3
    if (cpu.flags.zf)
    {
        goto L_0x00a99fb3;
    }
    // 00a99fb1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a99fb3:
    // 00a99fb3  39df                   +cmp edi, ebx
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
    // 00a99fb5  7e03                   -jle 0xa99fba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99fba;
    }
    // 00a99fb7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a99fba:
    // 00a99fba  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a99fbe  39f8                   +cmp eax, edi
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
    // 00a99fc0  7e0a                   -jle 0xa99fcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99fcc;
    }
    // 00a99fc2  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99fc6  7204                   -jb 0xa99fcc
    if (cpu.flags.cf)
    {
        goto L_0x00a99fcc;
    }
    // 00a99fc8  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a99fcc:
    // 00a99fcc  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a99fcf  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a99fd2:
    // 00a99fd2  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99fd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a99fd6  48                     -dec eax
    (cpu.eax)--;
    // 00a99fd7  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a99fda  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a99fdc  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a99fdf  38fb                   +cmp bl, bh
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
    // 00a99fe1  7503                   -jne 0xa99fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00a99fe6;
    }
    // 00a99fe3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99fe4  ebec                   -jmp 0xa99fd2
    goto L_0x00a99fd2;
L_0x00a99fe6:
    // 00a99fe6  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99fe9  7506                   -jne 0xa99ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a99ff1;
    }
    // 00a99feb  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a99fed  fec7                   -inc bh
    (cpu.bh)++;
    // 00a99fef  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a99ff1:
    // 00a99ff1  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99ff5  7d03                   -jge 0xa99ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99ffa;
    }
    // 00a99ff7  4a                     -dec edx
    (cpu.edx)--;
    // 00a99ff8  47                     -inc edi
    (cpu.edi)++;
    // 00a99ff9  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a99ffa:
    // 00a99ffa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99ffc  7f18                   -jg 0xa9a016
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a016;
    }
    // 00a99ffe  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a9a003  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a9a005  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a007  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a9a00d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a9a013  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a9a016:
    // 00a9a016  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9a019  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a9a01c  7514                   -jne 0xa9a032
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a032;
    }
    // 00a9a01e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a9a021  741e                   -je 0xa9a041
    if (cpu.flags.zf)
    {
        goto L_0x00a9a041;
    }
    // 00a9a023  83f9fc                 +cmp ecx, -4
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
    // 00a9a026  7c04                   -jl 0xa9a02c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a02c;
    }
    // 00a9a028  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a02a  7c06                   -jl 0xa9a032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a032;
    }
L_0x00a9a02c:
    // 00a9a02c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a9a030  740f                   -je 0xa9a041
    if (cpu.flags.zf)
    {
        goto L_0x00a9a041;
    }
L_0x00a9a032:
    // 00a9a032  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9a036  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9a038  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9a03a  e822000000             -call 0xa9a061
    cpu.esp -= 4;
    sub_a9a061(app, cpu);
    if (cpu.terminate) return;
    // 00a9a03f  eb0d                   -jmp 0xa9a04e
    goto L_0x00a9a04e;
L_0x00a9a041:
    // 00a9a041  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a044  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a045  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9a047  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9a049  e831020000             -call 0xa9a27f
    cpu.esp -= 4;
    sub_a9a27f(app, cpu);
    if (cpu.terminate) return;
L_0x00a9a04e:
    // 00a9a04e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a050  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a055  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a9a058  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a059  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a05c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a060  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9a04e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a9a04e;
    // 00a99f4e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a99f51  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a99f57  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a99f5a:
    // 00a99f5a  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99f5d  7505                   -jne 0xa99f64
    if (!cpu.flags.zf)
    {
        goto L_0x00a99f64;
    }
    // 00a99f5f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99f60  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99f61  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a99f62  ebf6                   -jmp 0xa99f5a
    goto L_0x00a99f5a;
L_0x00a99f64:
    // 00a99f64  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a99f67  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a99f69  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a99f6c  740a                   -je 0xa99f78
    if (cpu.flags.zf)
    {
        goto L_0x00a99f78;
    }
    // 00a99f6e  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a99f71  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a99f74  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a99f76  eb15                   -jmp 0xa99f8d
    goto L_0x00a99f8d;
L_0x00a99f78:
    // 00a99f78  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a99f7b  7410                   -je 0xa99f8d
    if (cpu.flags.zf)
    {
        goto L_0x00a99f8d;
    }
    // 00a99f7d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a99f80  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99f82  7e03                   -jle 0xa99f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99f87;
    }
    // 00a99f84  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a99f85  eb02                   -jmp 0xa99f89
    goto L_0x00a99f89;
L_0x00a99f87:
    // 00a99f87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a99f89:
    // 00a99f89  41                     -inc ecx
    (cpu.ecx)++;
    // 00a99f8a  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a99f8d:
    // 00a99f8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99f8f  0f8c65000000           -jl 0xa99ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a99ffa;
    }
    // 00a99f95  39c7                   +cmp edi, eax
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
    // 00a99f97  7e02                   -jle 0xa99f9b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99f9b;
    }
    // 00a99f99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a99f9b:
    // 00a99f9b  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a99fa0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a99fa4  7405                   -je 0xa99fab
    if (cpu.flags.zf)
    {
        goto L_0x00a99fab;
    }
    // 00a99fa6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a99fab:
    // 00a99fab  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a99faf  7402                   -je 0xa99fb3
    if (cpu.flags.zf)
    {
        goto L_0x00a99fb3;
    }
    // 00a99fb1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a99fb3:
    // 00a99fb3  39df                   +cmp edi, ebx
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
    // 00a99fb5  7e03                   -jle 0xa99fba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99fba;
    }
    // 00a99fb7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a99fba:
    // 00a99fba  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a99fbe  39f8                   +cmp eax, edi
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
    // 00a99fc0  7e0a                   -jle 0xa99fcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a99fcc;
    }
    // 00a99fc2  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99fc6  7204                   -jb 0xa99fcc
    if (cpu.flags.cf)
    {
        goto L_0x00a99fcc;
    }
    // 00a99fc8  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a99fcc:
    // 00a99fcc  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a99fcf  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a99fd2:
    // 00a99fd2  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a99fd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a99fd6  48                     -dec eax
    (cpu.eax)--;
    // 00a99fd7  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a99fda  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a99fdc  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a99fdf  38fb                   +cmp bl, bh
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
    // 00a99fe1  7503                   -jne 0xa99fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00a99fe6;
    }
    // 00a99fe3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a99fe4  ebec                   -jmp 0xa99fd2
    goto L_0x00a99fd2;
L_0x00a99fe6:
    // 00a99fe6  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99fe9  7506                   -jne 0xa99ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a99ff1;
    }
    // 00a99feb  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a99fed  fec7                   -inc bh
    (cpu.bh)++;
    // 00a99fef  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a99ff1:
    // 00a99ff1  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99ff5  7d03                   -jge 0xa99ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a99ffa;
    }
    // 00a99ff7  4a                     -dec edx
    (cpu.edx)--;
    // 00a99ff8  47                     -inc edi
    (cpu.edi)++;
    // 00a99ff9  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a99ffa:
    // 00a99ffa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a99ffc  7f18                   -jg 0xa9a016
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a016;
    }
    // 00a99ffe  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a9a003  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a9a005  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a007  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a9a00d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a9a013  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a9a016:
    // 00a9a016  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9a019  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a9a01c  7514                   -jne 0xa9a032
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a032;
    }
    // 00a9a01e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a9a021  741e                   -je 0xa9a041
    if (cpu.flags.zf)
    {
        goto L_0x00a9a041;
    }
    // 00a9a023  83f9fc                 +cmp ecx, -4
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
    // 00a9a026  7c04                   -jl 0xa9a02c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a02c;
    }
    // 00a9a028  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a02a  7c06                   -jl 0xa9a032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a032;
    }
L_0x00a9a02c:
    // 00a9a02c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a9a030  740f                   -je 0xa9a041
    if (cpu.flags.zf)
    {
        goto L_0x00a9a041;
    }
L_0x00a9a032:
    // 00a9a032  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9a036  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9a038  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9a03a  e822000000             -call 0xa9a061
    cpu.esp -= 4;
    sub_a9a061(app, cpu);
    if (cpu.terminate) return;
    // 00a9a03f  eb0d                   -jmp 0xa9a04e
    goto L_0x00a9a04e;
L_0x00a9a041:
    // 00a9a041  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a044  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a045  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9a047  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9a049  e831020000             -call 0xa9a27f
    cpu.esp -= 4;
    sub_a9a27f(app, cpu);
    if (cpu.terminate) return;
L_0x00a9a04e:
L_entry_0x00a9a04e:
    // 00a9a04e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a050  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a055  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a9a058  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a059  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a05c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a05f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a060  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9a061(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a061  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a062  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9a064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a066  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9a069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a06a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9a06b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a06c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9a06e  41                     -inc ecx
    (cpu.ecx)++;
    // 00a9a06f  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a9a072  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a9a075  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9a078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a07a  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a9a07d  7425                   -je 0xa9a0a4
    if (cpu.flags.zf)
    {
        goto L_0x00a9a0a4;
    }
    // 00a9a07f  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a082  7d0c                   -jge 0xa9a090
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a090;
    }
    // 00a9a084  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a087  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a9a08b  7503                   -jne 0xa9a090
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a090;
    }
    // 00a9a08d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a9a090:
    // 00a9a090  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a093  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a096  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a098  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a9a09b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9a09d  7d05                   -jge 0xa9a0a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a0a4;
    }
    // 00a9a09f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a0a1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a9a0a4:
    // 00a9a0a4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a0a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9a0a9  0f8fa4000000           -jg 0xa9a153
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a153;
    }
    // 00a9a0af  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0b2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a9a0b6  7526                   -jne 0xa9a0de
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a0de;
    }
    // 00a9a0b8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a0bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9a0bd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a0bf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a0c2  42                     -inc edx
    (cpu.edx)++;
    // 00a9a0c3  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a9a0c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9a0c8  7f09                   -jg 0xa9a0d3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a0d3;
    }
    // 00a9a0ca  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0cd  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a9a0d1  740b                   -je 0xa9a0de
    if (cpu.flags.zf)
    {
        goto L_0x00a9a0de;
    }
L_0x00a9a0d3:
    // 00a9a0d3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a0d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9a0d8  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a0da  42                     -inc edx
    (cpu.edx)++;
    // 00a9a0db  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a9a0de:
    // 00a9a0de  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0e1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a9a0e4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a0e7  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a0ea  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a9a0ec  39fe                   +cmp esi, edi
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
    // 00a9a0ee  7e0a                   -jle 0xa9a0fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a0fa;
    }
    // 00a9a0f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9a0f2  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a9a0f5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a9a0f7  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a9a0fa:
    // 00a9a0fa  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0fd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a100  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a9a103  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9a105  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a9a108  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a9a10a  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a9a10d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a110  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a112  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a9a115  39fb                   +cmp ebx, edi
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
    // 00a9a117  7e02                   -jle 0xa9a11b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a11b;
    }
    // 00a9a119  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a9a11b:
    // 00a9a11b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a11e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a121  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a123  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a125  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a126  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a128  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a12a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a12b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a12d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a130  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a132  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a134  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a137  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a139  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a13a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a13b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a13e  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a9a141  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a144  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a146  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9a148  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a14b  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a9a14e  e90d010000             -jmp 0xa9a260
    goto L_0x00a9a260;
L_0x00a9a153:
    // 00a9a153  39f3                   +cmp ebx, esi
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
    // 00a9a155  7d70                   -jge 0xa9a1c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a1c7;
    }
    // 00a9a157  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a15a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a15d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a15f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a160  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a162  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a167  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a16a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a16c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a16e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a171  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a174  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a175  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a178  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a9a17b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a17e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a180  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a182  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a185  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a9a188  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a18b  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a18e  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9a191  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a9a194  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a9a197  7520                   -jne 0xa9a1b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a1b9;
    }
    // 00a9a199  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a9a19d  7f05                   -jg 0xa9a1a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a1a4;
    }
    // 00a9a19f  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a9a1a2  7415                   -je 0xa9a1b9
    if (cpu.flags.zf)
    {
        goto L_0x00a9a1b9;
    }
L_0x00a9a1a4:
    // 00a9a1a4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a1a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9a1a9  01cb                   +add ebx, ecx
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
    // 00a9a1ab  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a9a1ae  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1b1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a1b2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a9a1b9:
    // 00a9a1b9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1bc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a1bf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a9a1c2  e999000000             -jmp 0xa9a260
    goto L_0x00a9a260;
L_0x00a9a1c7:
    // 00a9a1c7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a1ca  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9a1cc  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a1cf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a1d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a1d2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a1d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a1d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a1d7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a1da  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a1dc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a1de  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a1e1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a1e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a1e4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a1e5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1e8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a1eb  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a9a1ee  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a1f0  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a1f2  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a9a1f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a9a1f8  7518                   -jne 0xa9a212
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a212;
    }
    // 00a9a1fa  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a9a1fe  7f05                   -jg 0xa9a205
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a205;
    }
    // 00a9a200  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a9a203  741c                   -je 0xa9a221
    if (cpu.flags.zf)
    {
        goto L_0x00a9a221;
    }
L_0x00a9a205:
    // 00a9a205  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a208  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9a20a  01c7                   +add edi, eax
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
    // 00a9a20c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a20d  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a9a210  eb0f                   -jmp 0xa9a221
    goto L_0x00a9a221;
L_0x00a9a212:
    // 00a9a212  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a215  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a218  7507                   -jne 0xa9a221
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a221;
    }
    // 00a9a21a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a9a221:
    // 00a9a221  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a224  39cb                   +cmp ebx, ecx
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
    // 00a9a226  7e02                   -jle 0xa9a22a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a22a;
    }
    // 00a9a228  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a9a22a:
    // 00a9a22a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a22d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a9a230  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a233  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a235  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a237  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a238  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a23a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a23c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a23d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a23f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a242  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a244  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a246  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a249  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a24b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a24c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a24d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a250  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a252  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a9a255  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a258  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a25a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a25d  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a9a260:
    // 00a9a260  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a9a263  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00a9a266  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a9a269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a9a266(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a9a266;
    // 00a9a061  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a062  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9a064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a066  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9a069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a06a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9a06b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a06c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9a06e  41                     -inc ecx
    (cpu.ecx)++;
    // 00a9a06f  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a9a072  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a9a075  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9a078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a07a  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a9a07d  7425                   -je 0xa9a0a4
    if (cpu.flags.zf)
    {
        goto L_0x00a9a0a4;
    }
    // 00a9a07f  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a082  7d0c                   -jge 0xa9a090
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a090;
    }
    // 00a9a084  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a087  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a9a08b  7503                   -jne 0xa9a090
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a090;
    }
    // 00a9a08d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a9a090:
    // 00a9a090  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a093  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a096  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a098  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a9a09b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9a09d  7d05                   -jge 0xa9a0a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a0a4;
    }
    // 00a9a09f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a0a1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a9a0a4:
    // 00a9a0a4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a0a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9a0a9  0f8fa4000000           -jg 0xa9a153
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a153;
    }
    // 00a9a0af  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0b2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a9a0b6  7526                   -jne 0xa9a0de
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a0de;
    }
    // 00a9a0b8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a0bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9a0bd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a0bf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a0c2  42                     -inc edx
    (cpu.edx)++;
    // 00a9a0c3  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a9a0c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9a0c8  7f09                   -jg 0xa9a0d3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a0d3;
    }
    // 00a9a0ca  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0cd  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a9a0d1  740b                   -je 0xa9a0de
    if (cpu.flags.zf)
    {
        goto L_0x00a9a0de;
    }
L_0x00a9a0d3:
    // 00a9a0d3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a0d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9a0d8  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a0da  42                     -inc edx
    (cpu.edx)++;
    // 00a9a0db  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a9a0de:
    // 00a9a0de  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0e1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a9a0e4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a0e7  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a0ea  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a9a0ec  39fe                   +cmp esi, edi
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
    // 00a9a0ee  7e0a                   -jle 0xa9a0fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a0fa;
    }
    // 00a9a0f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9a0f2  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a9a0f5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a9a0f7  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a9a0fa:
    // 00a9a0fa  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a0fd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a100  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a9a103  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9a105  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a9a108  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a9a10a  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a9a10d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a110  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a112  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a9a115  39fb                   +cmp ebx, edi
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
    // 00a9a117  7e02                   -jle 0xa9a11b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a11b;
    }
    // 00a9a119  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a9a11b:
    // 00a9a11b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a11e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a121  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a123  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a125  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a126  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a128  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a12a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a12b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a12d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a130  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a132  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a134  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a137  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a139  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a13a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a13b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a13e  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a9a141  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a144  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a146  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9a148  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a14b  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a9a14e  e90d010000             -jmp 0xa9a260
    goto L_0x00a9a260;
L_0x00a9a153:
    // 00a9a153  39f3                   +cmp ebx, esi
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
    // 00a9a155  7d70                   -jge 0xa9a1c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a1c7;
    }
    // 00a9a157  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a15a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a15d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a15f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a160  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a162  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a167  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a16a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a16c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a16e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a171  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a174  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a175  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a178  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a9a17b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a17e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a180  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a182  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a185  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a9a188  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a18b  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a18e  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9a191  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a9a194  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a9a197  7520                   -jne 0xa9a1b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a1b9;
    }
    // 00a9a199  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a9a19d  7f05                   -jg 0xa9a1a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a1a4;
    }
    // 00a9a19f  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a9a1a2  7415                   -je 0xa9a1b9
    if (cpu.flags.zf)
    {
        goto L_0x00a9a1b9;
    }
L_0x00a9a1a4:
    // 00a9a1a4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a1a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9a1a9  01cb                   +add ebx, ecx
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
    // 00a9a1ab  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a9a1ae  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1b1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a1b2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a9a1b9:
    // 00a9a1b9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1bc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a1bf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a9a1c2  e999000000             -jmp 0xa9a260
    goto L_0x00a9a260;
L_0x00a9a1c7:
    // 00a9a1c7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a1ca  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9a1cc  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a1cf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a1d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a1d2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a1d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a1d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a1d7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a1da  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a1dc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a1de  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a1e1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a1e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a1e4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a1e5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a1e8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a1eb  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a9a1ee  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a1f0  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a1f2  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a9a1f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a9a1f8  7518                   -jne 0xa9a212
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a212;
    }
    // 00a9a1fa  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a9a1fe  7f05                   -jg 0xa9a205
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a205;
    }
    // 00a9a200  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a9a203  741c                   -je 0xa9a221
    if (cpu.flags.zf)
    {
        goto L_0x00a9a221;
    }
L_0x00a9a205:
    // 00a9a205  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a208  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9a20a  01c7                   +add edi, eax
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
    // 00a9a20c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a20d  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a9a210  eb0f                   -jmp 0xa9a221
    goto L_0x00a9a221;
L_0x00a9a212:
    // 00a9a212  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a215  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a218  7507                   -jne 0xa9a221
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a221;
    }
    // 00a9a21a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a9a221:
    // 00a9a221  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a224  39cb                   +cmp ebx, ecx
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
    // 00a9a226  7e02                   -jle 0xa9a22a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a22a;
    }
    // 00a9a228  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a9a22a:
    // 00a9a22a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a22d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a9a230  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a233  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a235  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a237  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a238  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a23a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a23c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a23d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a23f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a242  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a244  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a246  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a249  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a24b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a24c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a24d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a250  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a252  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a9a255  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a258  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a25a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a25d  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a9a260:
    // 00a9a260  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a9a263  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x00a9a266:
    // 00a9a266  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a9a269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a26c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a9a27f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a9a27f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a280  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9a282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a284  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9a287  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9a288  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9a289  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9a28a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a28b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9a28d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a9a290  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a293  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9a296  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9a298  7f05                   -jg 0xa9a29f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a29f;
    }
    // 00a9a29a  0155ec                 +add dword ptr [ebp - 0x14], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9a29d  eb0e                   -jmp 0xa9a2ad
    goto L_0x00a9a2ad;
L_0x00a9a29f:
    // 00a9a29f  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a2a2  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a2a4  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a9a2a7  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a9a2aa  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x00a9a2ad:
    // 00a9a2ad  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a2b0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a2b2  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9a2b5  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a9a2b8  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00a9a2bb  741b                   -je 0xa9a2d8
    if (cpu.flags.zf)
    {
        goto L_0x00a9a2d8;
    }
    // 00a9a2bd  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a2c0  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a2c3  7d03                   -jge 0xa9a2c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a2c8;
    }
    // 00a9a2c5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x00a9a2c8:
    // 00a9a2c8  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a2cb  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a9a2cc  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a9a2cf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a2d1  7d05                   -jge 0xa9a2d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a2d8;
    }
    // 00a9a2d3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a2d5  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x00a9a2d8:
    // 00a9a2d8  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a2db  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9a2de  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9a2e0  7f16                   -jg 0xa9a2f8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a2f8;
    }
    // 00a9a2e2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a2e5  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a2e8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a2eb  01d8                   +add eax, ebx
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
    // 00a9a2ed  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a9a2f0  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00a9a2f3  e97c000000             -jmp 0xa9a374
    goto L_0x00a9a374;
L_0x00a9a2f8:
    // 00a9a2f8  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a2fb  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a9a2fe  39d7                   +cmp edi, edx
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
    // 00a9a300  7e03                   -jle 0xa9a305
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a305;
    }
    // 00a9a302  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x00a9a305:
    // 00a9a305  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a308  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a30b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a30e  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a9a311  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a313  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a316  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a317  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a319  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a31b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a31c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a31e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a321  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a323  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a325  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a328  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a32a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a32b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a32c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a32f  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a9a332  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a335  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00a9a338  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a33a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a33c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a9a33f  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00a9a342  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a9a345  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00a9a348  39d8                   +cmp eax, ebx
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
    // 00a9a34a  7d28                   -jge 0xa9a374
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a374;
    }
    // 00a9a34c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a34f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9a351  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a354  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a356  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a9a35b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9a35e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a361  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a364  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a366  e805a8ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9a36b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a36e  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a9a371  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x00a9a374:
    // 00a9a374  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a377  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a37a  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a9a37d  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a9a381  7520                   -jne 0xa9a3a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a3a3;
    }
    // 00a9a383  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00a9a387  7f09                   -jg 0xa9a392
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9a392;
    }
    // 00a9a389  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a38c  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a9a390  7411                   -je 0xa9a3a3
    if (cpu.flags.zf)
    {
        goto L_0x00a9a3a3;
    }
L_0x00a9a392:
    // 00a9a392  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a395  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a398  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a39b  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a39d  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a9a3a0  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x00a9a3a3:
    // 00a9a3a3  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a3a6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9a3a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9a3ab  7d25                   -jge 0xa9a3d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a3d2;
    }
    // 00a9a3ad  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a3b0  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a3b3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9a3b5  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a9a3b8  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a9a3bd  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00a9a3bf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a3c1  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00a9a3c4  e8a7a7ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9a3c9  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a3cc  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a9a3cf  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x00a9a3d2:
    // 00a9a3d2  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a3d5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9a3d7  7e49                   -jle 0xa9a422
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a422;
    }
    // 00a9a3d9  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a3dc  7d03                   -jge 0xa9a3e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a3e1;
    }
    // 00a9a3de  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x00a9a3e1:
    // 00a9a3e1  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a3e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a3e6  7426                   -je 0xa9a40e
    if (cpu.flags.zf)
    {
        goto L_0x00a9a40e;
    }
    // 00a9a3e8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a3eb  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a3ee  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a9a3f1  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a3f3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9a3f5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9a3f6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9a3f8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9a3fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a3fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9a3fd  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9a400  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9a402  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9a404  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9a407  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9a409  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a40a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9a40b  015df4                 -add dword ptr [ebp - 0xc], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a9a40e:
    // 00a9a40e  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a411  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a414  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a417  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a9a41a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a41d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a41f  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00a9a422:
    // 00a9a422  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a425  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00a9a429  7416                   -je 0xa9a441
    if (cpu.flags.zf)
    {
        goto L_0x00a9a441;
    }
    // 00a9a42b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a42e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a431  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a434  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a437  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a439  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a9a43c  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a9a43f  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a9a441:
    // 00a9a441  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a444  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a447  40                     -inc eax
    (cpu.eax)++;
    // 00a9a448  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9a44a  7c0f                   -jl 0xa9a45b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a45b;
    }
    // 00a9a44c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a44f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a9a452  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a455  c604022b               -mov byte ptr [edx + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a9a459  eb14                   -jmp 0xa9a46f
    goto L_0x00a9a46f;
L_0x00a9a45b:
    // 00a9a45b  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a45e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a9a460  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a9a463  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a9a465  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a468  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00a9a46b  c604022d               -mov byte ptr [edx + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x00a9a46f:
    // 00a9a46f  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a472  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a9a475  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a478  773e                   -ja 0xa9a4b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9a4b8;
    }
    // 00a9a47a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9a47c  2eff24856fa2a900       -jmp dword ptr cs:[eax*4 + 0xa9a26f]
    cpu.ip = app->getMemory<x86::reg32>(11117167 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a9a484:
    // 00a9a484  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a48b  7d26                   -jge 0xa9a4b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a4b3;
    }
    // 00a9a48d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00a9a492  eb24                   -jmp 0xa9a4b8
    goto L_0x00a9a4b8;
  case 0x00a9a494:
    // 00a9a494  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a498  7c05                   -jl 0xa9a49f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a49f;
    }
    // 00a9a49a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x00a9a49f:
L_0x00a9a49f:
    // 00a9a49f  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a4a3  7c05                   -jl 0xa9a4aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a4aa;
    }
    // 00a9a4a5  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x00a9a4aa:
L_0x00a9a4aa:
    // 00a9a4aa  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a4b1  7c05                   -jl 0xa9a4b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a4b8;
    }
L_0x00a9a4b3:
    // 00a9a4b3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x00a9a4b8:
    // 00a9a4b8  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a4bb  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a9a4be  83fb04                 +cmp ebx, 4
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
    // 00a9a4c1  7c4b                   -jl 0xa9a50e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a50e;
    }
    // 00a9a4c3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a4c5  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a4c8  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a9a4cb  3de8030000             +cmp eax, 0x3e8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a4d0  7c26                   -jl 0xa9a4f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a4f8;
    }
    // 00a9a4d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a4d4  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 00a9a4d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a9a4dc  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a9a4de  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9a4e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a4e3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00a9a4e6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a4e8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a9a4eb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a4ed  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a4f0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a9a4f3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a4f5  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a9a4f8:
    // 00a9a4f8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a4fb  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a4fe  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a501  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a504  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a506  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a9a509  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a9a50c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a9a50e:
    // 00a9a50e  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a511  7c49                   -jl 0xa9a55c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a55c;
    }
    // 00a9a513  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a515  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a518  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a9a51b  83f864                 +cmp eax, 0x64
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
    // 00a9a51e  7c26                   -jl 0xa9a546
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a546;
    }
    // 00a9a520  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a522  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00a9a527  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a9a52a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a9a52c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9a52f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a531  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a9a534  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a536  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a9a539  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a53b  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a53e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a9a541  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a543  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a9a546:
    // 00a9a546  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a549  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a54c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a54f  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a552  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a554  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a9a557  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a9a55a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a9a55c:
    // 00a9a55c  83fb02                 +cmp ebx, 2
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
    // 00a9a55f  7c43                   -jl 0xa9a5a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a5a4;
    }
    // 00a9a561  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a563  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a566  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a9a569  83f80a                 +cmp eax, 0xa
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
    // 00a9a56c  7c20                   -jl 0xa9a58e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a58e;
    }
    // 00a9a56e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a570  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a9a575  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a9a578  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a9a57a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9a57d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9a57f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a9a582  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9a584  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a587  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a589  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a58b  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a9a58e:
    // 00a9a58e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a591  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a594  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a597  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a59a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a59c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a9a59f  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a9a5a2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a9a5a4:
    // 00a9a5a4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a5a7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a9a5aa  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a5ad  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a5b0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a5b2  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a9a5b5  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a9a5b7  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a5ba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9a5bc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00a9a5bf  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9a5c1  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a5c4  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00a9a5c7  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00a9a5ca  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a9a5cd  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a9a5d0  e991fcffff             -jmp 0xa9a266
    return sub_a9a266(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a9a5d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a5d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a5d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9a5d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a5d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a5da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a5db  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00a9a5de  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9a5e0  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a9a5e3  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a9a5e6:
    // 00a9a5e6  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9a5e8  80fa20                 +cmp dl, 0x20
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
    // 00a9a5eb  740a                   -je 0xa9a5f7
    if (cpu.flags.zf)
    {
        goto L_0x00a9a5f7;
    }
    // 00a9a5ed  80fa09                 +cmp dl, 9
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
    // 00a9a5f0  7208                   -jb 0xa9a5fa
    if (cpu.flags.cf)
    {
        goto L_0x00a9a5fa;
    }
    // 00a9a5f2  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a5f5  7703                   -ja 0xa9a5fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9a5fa;
    }
L_0x00a9a5f7:
    // 00a9a5f7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a5f8  ebec                   -jmp 0xa9a5e6
    goto L_0x00a9a5e6;
L_0x00a9a5fa:
    // 00a9a5fa  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a5fd  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a9a5ff  80fa2b                 +cmp dl, 0x2b
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
    // 00a9a602  7407                   -je 0xa9a60b
    if (cpu.flags.zf)
    {
        goto L_0x00a9a60b;
    }
    // 00a9a604  80fa2d                 +cmp dl, 0x2d
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
    // 00a9a607  7504                   -jne 0xa9a60d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a60d;
    }
    // 00a9a609  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a9a60b:
    // 00a9a60b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9a60d:
    // 00a9a60d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a60f  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 00a9a611  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x00a9a614:
    // 00a9a614  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9a616  40                     -inc eax
    (cpu.eax)++;
    // 00a9a617  80fa2e                 +cmp dl, 0x2e
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
    // 00a9a61a  750a                   -jne 0xa9a626
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a626;
    }
    // 00a9a61c  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a9a61f  752d                   -jne 0xa9a64e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a64e;
    }
    // 00a9a621  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a9a624  ebee                   -jmp 0xa9a614
    goto L_0x00a9a614;
L_0x00a9a626:
    // 00a9a626  80fa30                 +cmp dl, 0x30
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
    // 00a9a629  7223                   -jb 0xa9a64e
    if (cpu.flags.cf)
    {
        goto L_0x00a9a64e;
    }
    // 00a9a62b  80fa39                 +cmp dl, 0x39
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
    // 00a9a62e  771e                   -ja 0xa9a64e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9a64e;
    }
    // 00a9a630  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a9a633  7403                   -je 0xa9a638
    if (cpu.flags.zf)
    {
        goto L_0x00a9a638;
    }
    // 00a9a635  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x00a9a638:
    // 00a9a638  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9a63a  80fe30                 +cmp dh, 0x30
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
    // 00a9a63d  740a                   -je 0xa9a649
    if (cpu.flags.zf)
    {
        goto L_0x00a9a649;
    }
    // 00a9a63f  83fb13                 +cmp ebx, 0x13
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
    // 00a9a642  7d04                   -jge 0xa9a648
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a648;
    }
    // 00a9a644  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x00a9a648:
    // 00a9a648  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a9a649:
    // 00a9a649  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a9a64c  ebc6                   -jmp 0xa9a614
    goto L_0x00a9a614;
L_0x00a9a64e:
    // 00a9a64e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9a650  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a9a653  0f8465000000           -je 0xa9a6be
    if (cpu.flags.zf)
    {
        goto L_0x00a9a6be;
    }
    // 00a9a659  80fa65                 +cmp dl, 0x65
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a65c  7405                   -je 0xa9a663
    if (cpu.flags.zf)
    {
        goto L_0x00a9a663;
    }
    // 00a9a65e  80fa45                 +cmp dl, 0x45
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a661  7557                   -jne 0xa9a6ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a6ba;
    }
L_0x00a9a663:
    // 00a9a663  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00a9a666  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9a668  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a9a66b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9a66e  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a671  7408                   -je 0xa9a67b
    if (cpu.flags.zf)
    {
        goto L_0x00a9a67b;
    }
    // 00a9a673  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a676  7505                   -jne 0xa9a67d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a67d;
    }
    // 00a9a678  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a9a67b:
    // 00a9a67b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a9a67d:
    // 00a9a67d  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00a9a680:
    // 00a9a680  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9a682  80fa30                 +cmp dl, 0x30
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
    // 00a9a685  7222                   -jb 0xa9a6a9
    if (cpu.flags.cf)
    {
        goto L_0x00a9a6a9;
    }
    // 00a9a687  80fa39                 +cmp dl, 0x39
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
    // 00a9a68a  771d                   -ja 0xa9a6a9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9a6a9;
    }
    // 00a9a68c  81fee8030000           +cmp esi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a692  7d0f                   -jge 0xa9a6a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a6a3;
    }
    // 00a9a694  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a9a697  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00a9a69a  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 00a9a69d  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00a9a6a0  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00a9a6a3:
    // 00a9a6a3  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a9a6a6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a6a7  ebd7                   -jmp 0xa9a680
    goto L_0x00a9a680;
L_0x00a9a6a9:
    // 00a9a6a9  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00a9a6ac  7402                   -je 0xa9a6b0
    if (cpu.flags.zf)
    {
        goto L_0x00a9a6b0;
    }
    // 00a9a6ae  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x00a9a6b0:
    // 00a9a6b0  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a9a6b3  7506                   -jne 0xa9a6bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a6bb;
    }
    // 00a9a6b5  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a9a6b8  eb01                   -jmp 0xa9a6bb
    goto L_0x00a9a6bb;
L_0x00a9a6ba:
    // 00a9a6ba  48                     -dec eax
    (cpu.eax)--;
L_0x00a9a6bb:
    // 00a9a6bb  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a9a6be:
    // 00a9a6be  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a6c2  7408                   -je 0xa9a6cc
    if (cpu.flags.zf)
    {
        goto L_0x00a9a6cc;
    }
    // 00a9a6c4  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a6c7  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9a6ca  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a9a6cc:
    // 00a9a6cc  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00a9a6cf  83fb13                 +cmp ebx, 0x13
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
    // 00a9a6d2  7e0a                   -jle 0xa9a6de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a6de;
    }
    // 00a9a6d4  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 00a9a6d7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9a6d9  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x00a9a6de:
    // 00a9a6de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a6e0  7e0b                   -jle 0xa9a6ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a6ed;
    }
    // 00a9a6e2  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a6e7  7504                   -jne 0xa9a6ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a6ed;
    }
    // 00a9a6e9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a6ea  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9a6eb  ebf1                   -jmp 0xa9a6de
    goto L_0x00a9a6de;
L_0x00a9a6ed:
    // 00a9a6ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a6ef  7511                   -jne 0xa9a702
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a702;
    }
    // 00a9a6f1  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a9a6f7  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a9a6fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9a6fc  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a9a6fe  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a9a700  eb5f                   -jmp 0xa9a761
    goto L_0x00a9a761;
L_0x00a9a702:
    // 00a9a702  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9a704  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a9a707  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 00a9a70b  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a70e  e8e9110000             -call 0xa9b8fc
    cpu.esp -= 4;
    sub_a9b8fc(app, cpu);
    if (cpu.terminate) return;
    // 00a9a713  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9a715  740a                   -je 0xa9a721
    if (cpu.flags.zf)
    {
        goto L_0x00a9a721;
    }
    // 00a9a717  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a71a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9a71c  e8a4f4ffff             -call 0xa99bc5
    cpu.esp -= 4;
    sub_a99bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a9a721:
    // 00a9a721  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00a9a724  7404                   -je 0xa9a72a
    if (cpu.flags.zf)
    {
        goto L_0x00a9a72a;
    }
    // 00a9a726  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a9a72a:
    // 00a9a72a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a72d  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00a9a731  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a9a734  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9a737  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a73a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00a9a73c  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 00a9a740  3d34010000             +cmp eax, 0x134
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(308 /*0x134*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a745  7e07                   -jle 0xa9a74e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a74e;
    }
    // 00a9a747  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a9a74c  eb13                   -jmp 0xa9a761
    goto L_0x00a9a761;
L_0x00a9a74e:
    // 00a9a74e  3dccfeffff             +cmp eax, 0xfffffecc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966988 /*0xfffffecc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a753  7d07                   -jge 0xa9a75c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a75c;
    }
    // 00a9a755  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a9a75a  eb05                   -jmp 0xa9a761
    goto L_0x00a9a761;
L_0x00a9a75c:
    // 00a9a75c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a9a761:
    // 00a9a761  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9a764  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a765  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a766  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a768  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9a769(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a769  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a76a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9a76c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9a76d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a76e  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00a9a771  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9a773  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a776  e85afeffff             -call 0xa9a5d5
    cpu.esp -= 4;
    sub_a9a5d5(app, cpu);
    if (cpu.terminate) return;
    // 00a9a77b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9a77d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9a77f  750b                   -jne 0xa9a78c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a78c;
    }
    // 00a9a781  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a9a784:
    // 00a9a784  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a9a787  e9ad000000             -jmp 0xa9a839
    goto L_0x00a9a839;
L_0x00a9a78c:
    // 00a9a78c  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a9a78f  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a9a792  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a9a797  3dff430000             +cmp eax, 0x43ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17407 /*0x43ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a79c  7c2a                   -jl 0xa9a7c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a7c8;
    }
    // 00a9a79e  e841ccffff             -call 0xa973e4
    cpu.esp -= 4;
    sub_a973e4(app, cpu);
    if (cpu.terminate) return;
    // 00a9a7a3  f645dd80               +test byte ptr [ebp - 0x23], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) & 128 /*0x80*/));
    // 00a9a7a7  7410                   -je 0xa9a7b9
    if (cpu.flags.zf)
    {
        goto L_0x00a9a7b9;
    }
    // 00a9a7a9  dd0528f4a900           +fld qword ptr [0xa9f428]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11138088) /* 0xa9f428 */)));
    // 00a9a7af  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a9a7b1  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a9a7b4  e980000000             -jmp 0xa9a839
    goto L_0x00a9a839;
L_0x00a9a7b9:
    // 00a9a7b9  a128f4a900             -mov eax, dword ptr [0xa9f428]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11138088) /* 0xa9f428 */);
    // 00a9a7be  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a9a7c1  a12cf4a900             -mov eax, dword ptr [0xa9f42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11138092) /* 0xa9f42c */);
    // 00a9a7c6  ebbc                   -jmp 0xa9a784
    goto L_0x00a9a784;
L_0x00a9a7c8:
    // 00a9a7c8  3dcd3b0000             +cmp eax, 0x3bcd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15309 /*0x3bcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a7cd  7d42                   -jge 0xa9a811
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a811;
    }
    // 00a9a7cf  83f8cc                 +cmp eax, -0x34
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-52 /*-0x34*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a7d2  7d0f                   -jge 0xa9a7e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a7e3;
    }
    // 00a9a7d4  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a9a7d6  e809ccffff             -call 0xa973e4
    cpu.esp -= 4;
    sub_a973e4(app, cpu);
    if (cpu.terminate) return;
    // 00a9a7db  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a9a7de  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00a9a7e1  eb56                   -jmp 0xa9a839
    goto L_0x00a9a839;
L_0x00a9a7e3:
    // 00a9a7e3  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a7e6  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a7e9  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a9a7eb  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a9a7ed  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a7f0  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9a7f3  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a7f6  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a7f9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a9a7fc  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 00a9a801  7504                   -jne 0xa9a807
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a807;
    }
    // 00a9a803  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a805  742d                   -je 0xa9a834
    if (cpu.flags.zf)
    {
        goto L_0x00a9a834;
    }
L_0x00a9a807:
    // 00a9a807  66f745f6f07f           +test word ptr [ebp - 0xa], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) & 32752 /*0x7ff0*/));
    // 00a9a80d  752a                   -jne 0xa9a839
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a839;
    }
    // 00a9a80f  eb23                   -jmp 0xa9a834
    goto L_0x00a9a834;
L_0x00a9a811:
    // 00a9a811  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a814  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a9a817  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a9a819  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a9a81b  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a81e  7414                   -je 0xa9a834
    if (cpu.flags.zf)
    {
        goto L_0x00a9a834;
    }
    // 00a9a820  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a9a823  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00a9a826  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9a829  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a9a82c  66f745e6f07f           +test word ptr [ebp - 0x1a], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) & 32752 /*0x7ff0*/));
    // 00a9a832  7505                   -jne 0xa9a839
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a839;
    }
L_0x00a9a834:
    // 00a9a834  e8abcbffff             -call 0xa973e4
    cpu.esp -= 4;
    sub_a973e4(app, cpu);
    if (cpu.terminate) return;
L_0x00a9a839:
    // 00a9a839  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a9a83c  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a9a83f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a840  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a841  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9a850(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a851  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a852  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9a854  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a856  740f                   -je 0xa9a867
    if (cpu.flags.zf)
    {
        goto L_0x00a9a867;
    }
L_0x00a9a858:
    // 00a9a858  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a85b  740a                   -je 0xa9a867
    if (cpu.flags.zf)
    {
        goto L_0x00a9a867;
    }
    // 00a9a85d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a85e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9a860  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a861  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00a9a864  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9a865  75f1                   -jne 0xa9a858
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a858;
    }
L_0x00a9a867:
    // 00a9a867  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a9a869:
    // 00a9a869  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9a86b  7407                   -je 0xa9a874
    if (cpu.flags.zf)
    {
        goto L_0x00a9a874;
    }
    // 00a9a86d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a86e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9a86f  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a9a872  ebf5                   -jmp 0xa9a869
    goto L_0x00a9a869;
L_0x00a9a874:
    // 00a9a874  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9a876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a877  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9a880(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9a881  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9a882  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9a883  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9a886  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a9a88a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a9a88e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a9a890  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a9a894  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9a896  7402                   -je 0xa9a89a
    if (cpu.flags.zf)
    {
        goto L_0x00a9a89a;
    }
    // 00a9a898  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a9a89a:
    // 00a9a89a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a9a89e:
    // 00a9a89e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9a8a0  fec0                   -inc al
    (cpu.al)++;
    // 00a9a8a2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9a8a7  f6808ce1a90002         +test byte ptr [eax + 0xa9e18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11133324) /* 0xa9e18c */) & 2 /*0x2*/));
    // 00a9a8ae  7403                   -je 0xa9a8b3
    if (cpu.flags.zf)
    {
        goto L_0x00a9a8b3;
    }
    // 00a9a8b0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a8b1  ebeb                   -jmp 0xa9a89e
    goto L_0x00a9a89e;
L_0x00a9a8b3:
    // 00a9a8b3  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9a8b5  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8b8  7405                   -je 0xa9a8bf
    if (cpu.flags.zf)
    {
        goto L_0x00a9a8bf;
    }
    // 00a9a8ba  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8bd  7501                   -jne 0xa9a8c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a8c0;
    }
L_0x00a9a8bf:
    // 00a9a8bf  42                     -inc edx
    (cpu.edx)++;
L_0x00a9a8c0:
    // 00a9a8c0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9a8c2  752c                   -jne 0xa9a8f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a8f0;
    }
    // 00a9a8c4  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8c7  7514                   -jne 0xa9a8dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a8dd;
    }
    // 00a9a8c9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a9a8cc  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8cf  7405                   -je 0xa9a8d6
    if (cpu.flags.zf)
    {
        goto L_0x00a9a8d6;
    }
    // 00a9a8d1  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8d4  7507                   -jne 0xa9a8dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a8dd;
    }
L_0x00a9a8d6:
    // 00a9a8d6  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a9a8db  eb33                   -jmp 0xa9a910
    goto L_0x00a9a910;
L_0x00a9a8dd:
    // 00a9a8dd  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a8e0  7507                   -jne 0xa9a8e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a8e9;
    }
    // 00a9a8e2  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a9a8e7  eb3c                   -jmp 0xa9a925
    goto L_0x00a9a925;
L_0x00a9a8e9:
    // 00a9a8e9  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00a9a8ee  eb35                   -jmp 0xa9a925
    goto L_0x00a9a925;
L_0x00a9a8f0:
    // 00a9a8f0  83fe02                 +cmp esi, 2
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
    // 00a9a8f3  7c05                   -jl 0xa9a8fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9a8fa;
    }
    // 00a9a8f5  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a8f8  7e11                   -jle 0xa9a90b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a9a90b;
    }
L_0x00a9a8fa:
    // 00a9a8fa  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a9a8ff  e8bccaffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9a904  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9a906  e9c1000000             -jmp 0xa9a9cc
    goto L_0x00a9a9cc;
L_0x00a9a90b:
    // 00a9a90b  83fe10                 +cmp esi, 0x10
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
    // 00a9a90e  7515                   -jne 0xa9a925
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a925;
    }
L_0x00a9a910:
    // 00a9a910  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a913  7510                   -jne 0xa9a925
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a925;
    }
    // 00a9a915  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a9a918  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a91b  7405                   -je 0xa9a922
    if (cpu.flags.zf)
    {
        goto L_0x00a9a922;
    }
    // 00a9a91d  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a920  7503                   -jne 0xa9a925
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a925;
    }
L_0x00a9a922:
    // 00a9a922  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a9a925:
    // 00a9a925  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a9a928  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00a9a92f  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a9a931  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a9a933:
    // 00a9a933  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9a935  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9a937  e8b4000000             -call 0xa9a9f0
    cpu.esp -= 4;
    sub_a9a9f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9a93c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9a93e  39f0                   +cmp eax, esi
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
    // 00a9a940  7d1a                   -jge 0xa9a95c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9a95c;
    }
    // 00a9a942  3b9ddce6a900           +cmp ebx, dword ptr [ebp + 0xa9e6dc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(11134684) /* 0xa9e6dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a948  7602                   -jbe 0xa9a94c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9a94c;
    }
    // 00a9a94a  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a9a94c:
    // 00a9a94c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9a94e  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00a9a951  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9a953  39c3                   +cmp ebx, eax
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
    // 00a9a955  7302                   -jae 0xa9a959
    if (!cpu.flags.cf)
    {
        goto L_0x00a9a959;
    }
    // 00a9a957  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a9a959:
    // 00a9a959  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9a95a  ebd7                   -jmp 0xa9a933
    goto L_0x00a9a933;
L_0x00a9a95c:
    // 00a9a95c  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a95f  7504                   -jne 0xa9a965
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a965;
    }
    // 00a9a961  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a9a965:
    // 00a9a965  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9a969  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9a96b  7402                   -je 0xa9a96f
    if (cpu.flags.zf)
    {
        goto L_0x00a9a96f;
    }
    // 00a9a96d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x00a9a96f:
    // 00a9a96f  837c240801             +cmp dword ptr [esp + 8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a974  750f                   -jne 0xa9a985
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a985;
    }
    // 00a9a976  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9a97c  7207                   -jb 0xa9a985
    if (cpu.flags.cf)
    {
        goto L_0x00a9a985;
    }
    // 00a9a97e  7509                   -jne 0xa9a989
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a989;
    }
    // 00a9a980  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a983  7504                   -jne 0xa9a989
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a989;
    }
L_0x00a9a985:
    // 00a9a985  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a9a987  743a                   -je 0xa9a9c3
    if (cpu.flags.zf)
    {
        goto L_0x00a9a9c3;
    }
L_0x00a9a989:
    // 00a9a989  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a9a98e  e82dcaffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9a993  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a9a998  750c                   -jne 0xa9a9a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a9a6;
    }
    // 00a9a99a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9a99f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9a9a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9a9a6:
    // 00a9a9a6  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a9a9  750c                   -jne 0xa9a9b7
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a9b7;
    }
    // 00a9a9ab  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 00a9a9b0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9a9b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9a9b7:
    // 00a9a9b7  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00a9a9bc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9a9bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9a9c3:
    // 00a9a9c3  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9a9c6  7502                   -jne 0xa9a9ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a9a9ca;
    }
    // 00a9a9c8  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00a9a9ca:
    // 00a9a9ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9a9cc:
    // 00a9a9cc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9a9cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9a9d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a9d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a9d5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9a9d7  e8a4feffff             -call 0xa9a880
    cpu.esp -= 4;
    sub_a9a880(app, cpu);
    if (cpu.terminate) return;
    // 00a9a9dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9a9e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a9e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9a9e1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a9a9e6  e895feffff             -call 0xa9a880
    cpu.esp -= 4;
    sub_a9a880(app, cpu);
    if (cpu.terminate) return;
    // 00a9a9eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9a9ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9a9f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9a9f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9a9f1  3c30                   +cmp al, 0x30
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
    // 00a9a9f3  720e                   -jb 0xa9aa03
    if (cpu.flags.cf)
    {
        goto L_0x00a9aa03;
    }
    // 00a9a9f5  3c39                   +cmp al, 0x39
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
    // 00a9a9f7  770a                   -ja 0xa9aa03
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9aa03;
    }
    // 00a9a9f9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9a9fe  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a9aa01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aa03:
    // 00a9aa03  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9aa08  e8930f0000             -call 0xa9b9a0
    cpu.esp -= 4;
    sub_a9b9a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9aa0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9aa0f  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9aa11  720d                   -jb 0xa9aa20
    if (cpu.flags.cf)
    {
        goto L_0x00a9aa20;
    }
    // 00a9aa13  3c69                   +cmp al, 0x69
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
    // 00a9aa15  7709                   -ja 0xa9aa20
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9aa20;
    }
    // 00a9aa17  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9aa19  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a9aa1b  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a9aa1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aa20:
    // 00a9aa20  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9aa22  720e                   -jb 0xa9aa32
    if (cpu.flags.cf)
    {
        goto L_0x00a9aa32;
    }
    // 00a9aa24  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9aa26  770a                   -ja 0xa9aa32
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9aa32;
    }
    // 00a9aa28  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9aa2d  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a9aa30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aa32:
    // 00a9aa32  3c73                   +cmp al, 0x73
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
    // 00a9aa34  720e                   -jb 0xa9aa44
    if (cpu.flags.cf)
    {
        goto L_0x00a9aa44;
    }
    // 00a9aa36  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9aa38  770a                   -ja 0xa9aa44
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9aa44;
    }
    // 00a9aa3a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9aa3f  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a9aa42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aa44:
    // 00a9aa44  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00a9aa49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9aa50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9aa50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9aa51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9aa52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9aa53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9aa54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9aa55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9aa56  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9aa59  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9aa5b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a9aa60  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a9aa65  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a9aa68  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a9aa6d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a9aa71  e83a0f0000             -call 0xa9b9b0
    cpu.esp -= 4;
    sub_a9b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00a9aa76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9aa78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9aa7a  750a                   -jne 0xa9aa86
    if (!cpu.flags.zf)
    {
        goto L_0x00a9aa86;
    }
    // 00a9aa7c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9aa81  e97c010000             -jmp 0xa9ac02
    goto L_0x00a9ac02;
L_0x00a9aa86:
    // 00a9aa86  39e8                   +cmp eax, ebp
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
    // 00a9aa88  750f                   -jne 0xa9aa99
    if (!cpu.flags.zf)
    {
        goto L_0x00a9aa99;
    }
    // 00a9aa8a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9aa8f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9aa92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aa98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aa99:
    // 00a9aa99  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9aa9b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a9aa9f  40                     -inc eax
    (cpu.eax)++;
    // 00a9aaa0  e8dba1ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9aaa5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9aaa7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9aaab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9aaad  750f                   -jne 0xa9aabe
    if (!cpu.flags.zf)
    {
        goto L_0x00a9aabe;
    }
    // 00a9aaaf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9aab4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9aab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aab8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aab9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aaba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aabb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aabc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aabd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aabe:
    // 00a9aabe  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9aac2  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a9aac4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9aac6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9aac7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9aac9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9aacb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9aacc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9aace  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9aad1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9aad3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9aad5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9aad8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9aada  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aadb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9aadc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9aae0  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a9aae3  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a9aae7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9aae9  e8220f0000             -call 0xa9ba10
    cpu.esp -= 4;
    sub_a9ba10(app, cpu);
    if (cpu.terminate) return;
    // 00a9aaee  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a9aaf2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9aaf4  744b                   -je 0xa9ab41
    if (cpu.flags.zf)
    {
        goto L_0x00a9ab41;
    }
    // 00a9aaf6  40                     -inc eax
    (cpu.eax)++;
    // 00a9aaf7  e884a1ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9aafc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9aafe  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a9ab02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ab04  7516                   -jne 0xa9ab1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ab1c;
    }
    // 00a9ab06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9ab08  e863a2ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9ab0d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ab12  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9ab15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ab1c:
    // 00a9ab1c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9ab20  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9ab22  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9ab23  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9ab25  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9ab27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9ab28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9ab2a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9ab2d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9ab2f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9ab31  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9ab34  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9ab36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab37  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab38  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9ab3c  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a9ab3f  eb04                   -jmp 0xa9ab45
    goto L_0x00a9ab45;
L_0x00a9ab41:
    // 00a9ab41  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a9ab45:
    // 00a9ab45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9ab49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9ab4a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9ab4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9ab4f  2eff1524cea900         -call dword ptr cs:[0xa9ce24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128356) /* 0xa9ce24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9ab56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9ab58  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9ab5c  e80fa2ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9ab61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9ab65  e806a2ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9ab6a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9ab6c  750f                   -jne 0xa9ab7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ab7d;
    }
    // 00a9ab6e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ab73  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9ab76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ab7d:
    // 00a9ab7d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9ab7f  e888000000             -call 0xa9ac0c
    cpu.esp -= 4;
    sub_a9ac0c(app, cpu);
    if (cpu.terminate) return;
    // 00a9ab84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ab86  740f                   -je 0xa9ab97
    if (cpu.flags.zf)
    {
        goto L_0x00a9ab97;
    }
    // 00a9ab88  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ab8d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9ab90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ab96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ab97:
    // 00a9ab97  833d0810aa0000         +cmp dword ptr [0xaa1008], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9ab9e  7462                   -je 0xa9ac02
    if (cpu.flags.zf)
    {
        goto L_0x00a9ac02;
    }
    // 00a9aba0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9aba2  e8690e0000             -call 0xa9ba10
    cpu.esp -= 4;
    sub_a9ba10(app, cpu);
    if (cpu.terminate) return;
    // 00a9aba7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9abaa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9abad  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a9abb0  e8cba0ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9abb5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9abb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9abb9  7519                   -jne 0xa9abd4
    if (!cpu.flags.zf)
    {
        goto L_0x00a9abd4;
    }
    // 00a9abbb  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9abc0  e857e4ffff             -call 0xa9901c
    cpu.esp -= 4;
    sub_a9901c(app, cpu);
    if (cpu.terminate) return;
    // 00a9abc5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9abca  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9abcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9abd4:
    // 00a9abd4  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a9abd9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a9abdb  e8600e0000             -call 0xa9ba40
    cpu.esp -= 4;
    sub_a9ba40(app, cpu);
    if (cpu.terminate) return;
    // 00a9abe0  83f8ff                 +cmp eax, -1
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
    // 00a9abe3  7516                   -jne 0xa9abfb
    if (!cpu.flags.zf)
    {
        goto L_0x00a9abfb;
    }
    // 00a9abe5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9abe7  e884a1ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9abec  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9abf1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9abf4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abf7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9abfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9abfb:
    // 00a9abfb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9abfd  e856100000             -call 0xa9bc58
    cpu.esp -= 4;
    sub_a9bc58(app, cpu);
    if (cpu.terminate) return;
L_0x00a9ac02:
    // 00a9ac02  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9ac05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9ac0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ac0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9ac0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9ac0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9ac0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9ac10  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9ac11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9ac12  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9ac15  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9ac19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ac1b  750a                   -jne 0xa9ac27
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ac27;
    }
    // 00a9ac1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ac22  e989010000             -jmp 0xa9adb0
    goto L_0x00a9adb0;
L_0x00a9ac27:
    // 00a9ac27  803800                 +cmp byte ptr [eax], 0
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
    // 00a9ac2a  7415                   -je 0xa9ac41
    if (cpu.flags.zf)
    {
        goto L_0x00a9ac41;
    }
    // 00a9ac2c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9ac2f  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ac32  740d                   -je 0xa9ac41
    if (cpu.flags.zf)
    {
        goto L_0x00a9ac41;
    }
L_0x00a9ac34:
    // 00a9ac34  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ac37  7408                   -je 0xa9ac41
    if (cpu.flags.zf)
    {
        goto L_0x00a9ac41;
    }
    // 00a9ac39  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a9ac3c  42                     -inc edx
    (cpu.edx)++;
    // 00a9ac3d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a9ac3f  75f3                   -jne 0xa9ac34
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ac34;
    }
L_0x00a9ac41:
    // 00a9ac41  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ac44  750f                   -jne 0xa9ac55
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ac55;
    }
    // 00a9ac46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ac4b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9ac4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ac55:
    // 00a9ac55  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ac59  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a9ac5c  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 00a9ac5f  a10410aa00             -mov eax, dword ptr [0xaa1004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9ac64  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9ac68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ac6a  7541                   -jne 0xa9acad
    if (!cpu.flags.zf)
    {
        goto L_0x00a9acad;
    }
    // 00a9ac6c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9ac6e  0f853c010000           -jne 0xa9adb0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9adb0;
    }
    // 00a9ac74  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9ac79  e802a0ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9ac7e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9ac82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ac84  750f                   -jne 0xa9ac95
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ac95;
    }
    // 00a9ac86  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ac8b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9ac8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ac94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ac95:
    // 00a9ac95  a30410aa00             -mov dword ptr [0xaa1004], eax
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.eax;
    // 00a9ac9a  83c008                 +add eax, 8
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
    // 00a9ac9d  8968f8                 -mov dword ptr [eax - 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebp;
    // 00a9aca0  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00a9aca3  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a9aca8  e9e5000000             -jmp 0xa9ad92
    goto L_0x00a9ad92;
L_0x00a9acad:
    // 00a9acad  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9acb1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a9acb3  e804010000             -call 0xa9adbc
    cpu.esp -= 4;
    sub_a9adbc(app, cpu);
    if (cpu.terminate) return;
    // 00a9acb8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9acba  0f85ee000000           -jne 0xa9adae
    if (!cpu.flags.zf)
    {
        goto L_0x00a9adae;
    }
    // 00a9acc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9acc2  0f8fc7000000           -jg 0xa9ad8f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9ad8f;
    }
    // 00a9acc8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9acca  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00a9accc  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a9accf  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 00a9acd6  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9acd9  8b350010aa00           -mov esi, dword ptr [0xaa1000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9acdf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9ace2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9ace4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9ace6  754f                   -jne 0xa9ad37
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ad37;
    }
    // 00a9ace8  e8939fffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9aced  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9acef  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9acf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9acf5  750f                   -jne 0xa9ad06
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ad06;
    }
    // 00a9acf7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9acfc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9acff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ad06:
    // 00a9ad06  8b350410aa00           -mov esi, dword ptr [0xaa1004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9ad0c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9ad0e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9ad0f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9ad11  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9ad13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9ad14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9ad16  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9ad19  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9ad1b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9ad1d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9ad20  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9ad22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad23  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad24  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9ad27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9ad29  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9ad2b  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a9ad30  e83b9effff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9ad35  eb3c                   -jmp 0xa9ad73
    goto L_0x00a9ad73;
L_0x00a9ad37:
    // 00a9ad37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9ad39  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9ad3d  e85ee3ffff             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ad42  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9ad46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ad48  750f                   -jne 0xa9ad59
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ad59;
    }
    // 00a9ad4a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9ad4f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9ad52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ad58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ad59:
    // 00a9ad59  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9ad5c  8b150010aa00           -mov edx, dword ptr [0xaa1000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9ad62  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9ad64  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a9ad66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9ad68  e883110000             -call 0xa9bef0
    cpu.esp -= 4;
    sub_a9bef0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ad6d  890d0010aa00           -mov dword ptr [0xaa1000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.ecx;
L_0x00a9ad73:
    // 00a9ad73  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9ad77  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a9ad7e  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9ad80  893d0410aa00           -mov dword ptr [0xaa1004], edi
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.edi;
    // 00a9ad86  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a9ad8d  eb03                   -jmp 0xa9ad92
    goto L_0x00a9ad92;
L_0x00a9ad8f:
    // 00a9ad8f  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a9ad92:
    // 00a9ad92  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9ad96  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a9ad9d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9ad9f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9ada3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9ada5  a10010aa00             -mov eax, dword ptr [0xaa1000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9adaa  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00a9adae:
    // 00a9adae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9adb0:
    // 00a9adb0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9adb3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9adb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9adbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9adbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9adbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9adbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9adbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9adc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9adc1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9adc3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a9adc5  8b350410aa00           -mov esi, dword ptr [0xaa1004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9adcb  e9cb000000             -jmp 0xa9ae9b
    goto L_0x00a9ae9b;
L_0x00a9add0:
    // 00a9add0  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00a9add2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9add4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a9add6  0f84bc000000           -je 0xa9ae98
    if (cpu.flags.zf)
    {
        goto L_0x00a9ae98;
    }
L_0x00a9addc:
    // 00a9addc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9adde  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9ade0  e8fbd7ffff             -call 0xa985e0
    cpu.esp -= 4;
    sub_a985e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ade5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9ade7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9ade9  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a9adeb  e8f0d7ffff             -call 0xa985e0
    cpu.esp -= 4;
    sub_a985e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9adf0  39c1                   +cmp ecx, eax
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
    // 00a9adf2  0f85a0000000           -jne 0xa9ae98
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ae98;
    }
    // 00a9adf8  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9adfb  0f858a000000           -jne 0xa9ae8b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ae8b;
    }
    // 00a9ae01  8b150410aa00           -mov edx, dword ptr [0xaa1004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9ae07  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a9ae09  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9ae0b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a9ae0e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9ae10  0f846c000000           -je 0xa9ae82
    if (cpu.flags.zf)
    {
        goto L_0x00a9ae82;
    }
    // 00a9ae16  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9ae18  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9ae1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9ae1c  740f                   -je 0xa9ae2d
    if (cpu.flags.zf)
    {
        goto L_0x00a9ae2d;
    }
L_0x00a9ae1e:
    // 00a9ae1e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9ae21  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a9ae23  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9ae26  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9ae29  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9ae2b  75f1                   -jne 0xa9ae1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ae1e;
    }
L_0x00a9ae2d:
    // 00a9ae2d  8b350010aa00           -mov esi, dword ptr [0xaa1000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9ae33  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9ae35  7443                   -je 0xa9ae7a
    if (cpu.flags.zf)
    {
        goto L_0x00a9ae7a;
    }
    // 00a9ae37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9ae39  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ae3d  7407                   -je 0xa9ae46
    if (cpu.flags.zf)
    {
        goto L_0x00a9ae46;
    }
    // 00a9ae3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9ae41  e82a9fffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a9ae46:
    // 00a9ae46  8b2d0410aa00           -mov ebp, dword ptr [0xaa1004]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9ae4c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a9ae4e  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9ae50  8b150010aa00           -mov edx, dword ptr [0xaa1000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9ae56  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a9ae59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9ae5b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a9ae5d  e88e100000             -call 0xa9bef0
    cpu.esp -= 4;
    sub_a9bef0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ae62  890d0010aa00           -mov dword ptr [0xaa1000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.ecx;
    // 00a9ae68  39f7                   +cmp edi, esi
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
    // 00a9ae6a  7d0e                   -jge 0xa9ae7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9ae7a;
    }
    // 00a9ae6c  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a9ae6f:
    // 00a9ae6f  40                     -inc eax
    (cpu.eax)++;
    // 00a9ae70  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9ae72  47                     -inc edi
    (cpu.edi)++;
    // 00a9ae73  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a9ae76  39f7                   +cmp edi, esi
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
    // 00a9ae78  7cf5                   -jl 0xa9ae6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9ae6f;
    }
L_0x00a9ae7a:
    // 00a9ae7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9ae7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ae82:
    // 00a9ae82  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a9ae85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ae8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ae8b:
    // 00a9ae8b  42                     -inc edx
    (cpu.edx)++;
    // 00a9ae8c  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a9ae8f  43                     -inc ebx
    (cpu.ebx)++;
    // 00a9ae90  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a9ae92  0f8544ffffff           -jne 0xa9addc
    if (!cpu.flags.zf)
    {
        goto L_0x00a9addc;
    }
L_0x00a9ae98:
    // 00a9ae98  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a9ae9b:
    // 00a9ae9b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9ae9d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9ae9f  0f852bffffff           -jne 0xa9add0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9add0;
    }
    // 00a9aea5  a10410aa00             -mov eax, dword ptr [0xaa1004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9aeaa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9aeac  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a9aeaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aeb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aeb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aeb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aeb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aeb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9aec0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9aec0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9aec1  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9aec8  7428                   -je 0xa9aef2
    if (cpu.flags.zf)
    {
        goto L_0x00a9aef2;
    }
    // 00a9aeca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9aecc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9aece  8a92011eaa00           -mov dl, byte ptr [edx + 0xaa1e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a9aed4  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9aed7  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a9aedd  7413                   -je 0xa9aef2
    if (cpu.flags.zf)
    {
        goto L_0x00a9aef2;
    }
    // 00a9aedf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9aee1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9aee3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a9aee6  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9aee9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9aeee  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9aef0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9aef2:
    // 00a9aef2  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9aef4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9aef9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aefa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9af00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9af00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9af01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9af02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9af03  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9af06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9af08  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a9af0a  e861000000             -call 0xa9af70
    cpu.esp -= 4;
    sub_a9af70(app, cpu);
    if (cpu.terminate) return;
    // 00a9af0f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9af11  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9af13  e838dcffff             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a9af18  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a9af1b  813d54e6a900a4030000   +cmp dword ptr [0xa9e654], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9af25  7526                   -jne 0xa9af4d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9af4d;
    }
    // 00a9af27  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9af2e  741d                   -je 0xa9af4d
    if (cpu.flags.zf)
    {
        goto L_0x00a9af4d;
    }
    // 00a9af30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9af32  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00a9af35  8a80011eaa00           -mov al, byte ptr [eax + 0xaa1e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a9af3b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9af3d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a9af42  7409                   -je 0xa9af4d
    if (cpu.flags.zf)
    {
        goto L_0x00a9af4d;
    }
    // 00a9af44  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9af46  e8f50f0000             -call 0xa9bf40
    cpu.esp -= 4;
    sub_a9bf40(app, cpu);
    if (cpu.terminate) return;
    // 00a9af4b  eb15                   -jmp 0xa9af62
    goto L_0x00a9af62;
L_0x00a9af4d:
    // 00a9af4d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a9af4f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9af53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9af54  2eff1568cda900         -call dword ptr cs:[0xa9cd68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128168) /* 0xa9cd68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9af5b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9af5d  e85effffff             -call 0xa9aec0
    cpu.esp -= 4;
    sub_a9aec0(app, cpu);
    if (cpu.terminate) return;
L_0x00a9af62:
    // 00a9af62  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9af65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9af66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9af67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9af68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9af70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9af70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9af71  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9af73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9af75  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 00a9af78  740c                   -je 0xa9af86
    if (cpu.flags.zf)
    {
        goto L_0x00a9af86;
    }
    // 00a9af7a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a9af7c  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00a9af7f  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a9af82  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a9af84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9af85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9af86:
    // 00a9af86  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a9af88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9af89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9af90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9af90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9af91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9af92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9af93  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9af95  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9af9b  833de0e2a90000         +cmp dword ptr [0xa9e2e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133664) /* 0xa9e2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9afa2  741d                   -je 0xa9afc1
    if (cpu.flags.zf)
    {
        goto L_0x00a9afc1;
    }
    // 00a9afa4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9afa6  ff15e0e2a900           -call dword ptr [0xa9e2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133664) /* 0xa9e2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9afac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9afae  7411                   -je 0xa9afc1
    if (cpu.flags.zf)
    {
        goto L_0x00a9afc1;
    }
    // 00a9afb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9afb2  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9afb8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9afbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9afc1:
    // 00a9afc1  a188e3a900             -mov eax, dword ptr [0xa9e388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9afc6  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a9afc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9afca  2eff15dccda900         -call dword ptr cs:[0xa9cddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128284) /* 0xa9cddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9afd1  83f802                 +cmp eax, 2
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
    // 00a9afd4  7511                   -jne 0xa9afe7
    if (!cpu.flags.zf)
    {
        goto L_0x00a9afe7;
    }
    // 00a9afd6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9afd8  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9afde  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9afe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9afe6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9afe7:
    // 00a9afe7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9afe9  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9afef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9aff1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aff2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aff3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9aff4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b000(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b002  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9b004  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b005  2eff15d8cda900         -call dword ptr cs:[0xa9cdd8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128280) /* 0xa9cdd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b00c  83f8ff                 +cmp eax, -1
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
    // 00a9b00f  7508                   -jne 0xa9b019
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b019;
    }
    // 00a9b011  e86ee0ffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b016  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b017  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b019:
    // 00a9b019  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a9b01c  7411                   -je 0xa9b02f
    if (cpu.flags.zf)
    {
        goto L_0x00a9b02f;
    }
    // 00a9b01e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a9b020  740d                   -je 0xa9b02f
    if (cpu.flags.zf)
    {
        goto L_0x00a9b02f;
    }
    // 00a9b022  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9b027  e8f0dfffff             -call 0xa9901c
    cpu.esp -= 4;
    sub_a9901c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b02c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b02d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b02e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b02f:
    // 00a9b02f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b033  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b040(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b044  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9b045  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b048  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9b04a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9b04c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a9b051  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b053  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9b055  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9b057  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a9b05a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9b05c  740e                   -je 0xa9b06c
    if (cpu.flags.zf)
    {
        goto L_0x00a9b06c;
    }
    // 00a9b05e  3b1580e7a900           +cmp edx, dword ptr [0xa9e780]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11134848) /* 0xa9e780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b064  7504                   -jne 0xa9b06a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b06a;
    }
    // 00a9b066  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a9b068  eb02                   -jmp 0xa9b06c
    goto L_0x00a9b06c;
L_0x00a9b06a:
    // 00a9b06a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x00a9b06c:
    // 00a9b06c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a9b06e  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b070  7208                   -jb 0xa9b07a
    if (cpu.flags.cf)
    {
        goto L_0x00a9b07a;
    }
    // 00a9b072  760c                   -jbe 0xa9b080
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b080;
    }
    // 00a9b074  3c77                   +cmp al, 0x77
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b076  740d                   -je 0xa9b085
    if (cpu.flags.zf)
    {
        goto L_0x00a9b085;
    }
    // 00a9b078  eb15                   -jmp 0xa9b08f
    goto L_0x00a9b08f;
L_0x00a9b07a:
    // 00a9b07a  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b07c  740c                   -je 0xa9b08a
    if (cpu.flags.zf)
    {
        goto L_0x00a9b08a;
    }
    // 00a9b07e  eb0f                   -jmp 0xa9b08f
    goto L_0x00a9b08f;
L_0x00a9b080:
    // 00a9b080  80cb01                 +or bl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a9b083  eb1b                   -jmp 0xa9b0a0
    goto L_0x00a9b0a0;
L_0x00a9b085:
    // 00a9b085  80cb02                 +or bl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a9b088  eb16                   -jmp 0xa9b0a0
    goto L_0x00a9b0a0;
L_0x00a9b08a:
    // 00a9b08a  80cb82                 +or bl, 0x82
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 00a9b08d  eb11                   -jmp 0xa9b0a0
    goto L_0x00a9b0a0;
L_0x00a9b08f:
    // 00a9b08f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9b094  e827c3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b099  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b09b  e9cf000000             -jmp 0xa9b16f
    goto L_0x00a9b16f;
L_0x00a9b0a0:
    // 00a9b0a0  8a6101                 -mov ah, byte ptr [ecx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a9b0a3  41                     -inc ecx
    (cpu.ecx)++;
    // 00a9b0a4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a9b0a6  0f84ae000000           -je 0xa9b15a
    if (cpu.flags.zf)
    {
        goto L_0x00a9b15a;
    }
L_0x00a9b0ac:
    // 00a9b0ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9b0ae  0f84a6000000           -je 0xa9b15a
    if (cpu.flags.zf)
    {
        goto L_0x00a9b15a;
    }
    // 00a9b0b4  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a9b0b6  3c63                   +cmp al, 0x63
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
    // 00a9b0b8  721d                   -jb 0xa9b0d7
    if (cpu.flags.cf)
    {
        goto L_0x00a9b0d7;
    }
    // 00a9b0ba  0f8665000000           -jbe 0xa9b125
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b125;
    }
    // 00a9b0c0  3c6e                   +cmp al, 0x6e
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
    // 00a9b0c2  0f8286000000           -jb 0xa9b14e
    if (cpu.flags.cf)
    {
        goto L_0x00a9b14e;
    }
    // 00a9b0c8  0f866c000000           -jbe 0xa9b13a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b13a;
    }
    // 00a9b0ce  3c74                   +cmp al, 0x74
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(116 /*0x74*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b0d0  7432                   -je 0xa9b104
    if (cpu.flags.zf)
    {
        goto L_0x00a9b104;
    }
    // 00a9b0d2  e977000000             -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b0d7:
    // 00a9b0d7  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b0d9  0f826f000000           -jb 0xa9b14e
    if (cpu.flags.cf)
    {
        goto L_0x00a9b14e;
    }
    // 00a9b0df  7609                   -jbe 0xa9b0ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b0ea;
    }
    // 00a9b0e1  3c62                   +cmp al, 0x62
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(98 /*0x62*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b0e3  742e                   -je 0xa9b113
    if (cpu.flags.zf)
    {
        goto L_0x00a9b113;
    }
    // 00a9b0e5  e964000000             -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b0ea:
    // 00a9b0ea  833c2400               +cmp dword ptr [esp], 0
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
    // 00a9b0ee  7407                   -je 0xa9b0f7
    if (cpu.flags.zf)
    {
        goto L_0x00a9b0f7;
    }
    // 00a9b0f0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b0f2  e957000000             -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b0f7:
    // 00a9b0f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9b0fc  80cb03                 +or bl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9b0ff  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9b102  eb4a                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b104:
    // 00a9b104  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9b106  7404                   -je 0xa9b10c
    if (cpu.flags.zf)
    {
        goto L_0x00a9b10c;
    }
    // 00a9b108  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b10a  eb42                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b10c:
    // 00a9b10c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a9b111  eb3b                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b113:
    // 00a9b113  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9b115  7404                   -je 0xa9b11b
    if (cpu.flags.zf)
    {
        goto L_0x00a9b11b;
    }
    // 00a9b117  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b119  eb33                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b11b:
    // 00a9b11b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a9b120  80cb40                 +or bl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00a9b123  eb29                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b125:
    // 00a9b125  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9b127  7404                   -je 0xa9b12d
    if (cpu.flags.zf)
    {
        goto L_0x00a9b12d;
    }
    // 00a9b129  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b12b  eb21                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b12d:
    // 00a9b12d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9b12f  0c01                   +or al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a9b131  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a9b136  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a9b138  eb14                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b13a:
    // 00a9b13a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9b13c  7404                   -je 0xa9b142
    if (cpu.flags.zf)
    {
        goto L_0x00a9b142;
    }
    // 00a9b13e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b140  eb0c                   -jmp 0xa9b14e
    goto L_0x00a9b14e;
L_0x00a9b142:
    // 00a9b142  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9b144  80e4fe                 -and ah, 0xfe
    cpu.ah &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a9b147  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a9b14c  8826                   -mov byte ptr [esi], ah
    app->getMemory<x86::reg8>(cpu.esi) = cpu.ah;
L_0x00a9b14e:
    // 00a9b14e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a9b151  41                     -inc ecx
    (cpu.ecx)++;
    // 00a9b152  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a9b154  0f8552ffffff           -jne 0xa9b0ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b0ac;
    }
L_0x00a9b15a:
    // 00a9b15a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9b15c  750f                   -jne 0xa9b16d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b16d;
    }
    // 00a9b15e  813d6ce1a90000020000   +cmp dword ptr [0xa9e16c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133292) /* 0xa9e16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b168  7503                   -jne 0xa9b16d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b16d;
    }
    // 00a9b16a  80cb40                 -or bl, 0x40
    cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a9b16d:
    // 00a9b16d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00a9b16f:
    // 00a9b16f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9b171  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b174  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b175  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b176  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b177  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b178  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b179  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9b17c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b17c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b17d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b17e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9b17f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9b181  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a9b183  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9b185  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9b189  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a9b18d  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b190  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9b195  e806080000             -call 0xa9b9a0
    cpu.esp -= 4;
    sub_a9b9a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b19a  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b19c  7522                   -jne 0xa9b1c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b1c0;
    }
    // 00a9b19e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b1a0  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a9b1a3  7405                   -je 0xa9b1aa
    if (cpu.flags.zf)
    {
        goto L_0x00a9b1aa;
    }
    // 00a9b1a5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00a9b1aa:
    // 00a9b1aa  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a9b1ad  7405                   -je 0xa9b1b4
    if (cpu.flags.zf)
    {
        goto L_0x00a9b1b4;
    }
    // 00a9b1af  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a9b1b2  eb03                   -jmp 0xa9b1b7
    goto L_0x00a9b1b7;
L_0x00a9b1b4:
    // 00a9b1b4  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x00a9b1b7:
    // 00a9b1b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9b1b9  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9b1bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b1be  eb30                   -jmp 0xa9b1f0
    goto L_0x00a9b1f0;
L_0x00a9b1c0:
    // 00a9b1c0  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a9b1c3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a9b1c6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9b1cb  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 00a9b1ce  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a9b1d1  7404                   -je 0xa9b1d7
    if (cpu.flags.zf)
    {
        goto L_0x00a9b1d7;
    }
    // 00a9b1d3  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a9b1d5  eb02                   -jmp 0xa9b1d9
    goto L_0x00a9b1d9;
L_0x00a9b1d7:
    // 00a9b1d7  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a9b1d9:
    // 00a9b1d9  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a9b1dc  7405                   -je 0xa9b1e3
    if (cpu.flags.zf)
    {
        goto L_0x00a9b1e3;
    }
    // 00a9b1de  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a9b1e1  eb03                   -jmp 0xa9b1e6
    goto L_0x00a9b1e6;
L_0x00a9b1e3:
    // 00a9b1e3  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00a9b1e6:
    // 00a9b1e6  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00a9b1eb  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9b1ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00a9b1f0:
    // 00a9b1f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b1f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b1f2  e89d0d0000             -call 0xa9bf94
    cpu.esp -= 4;
    sub_a9bf94(app, cpu);
    if (cpu.terminate) return;
    // 00a9b1f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9b1fa  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a9b1fd  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b201  750b                   -jne 0xa9b20e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b20e;
    }
    // 00a9b203  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b205  e87abeffff             -call 0xa97084
    cpu.esp -= 4;
    sub_a97084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b20a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9b20c  eb4e                   -jmp 0xa9b25c
    goto L_0x00a9b25c;
L_0x00a9b20e:
    // 00a9b20e  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a9b215  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9b218  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a9b21f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a9b226  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9b229  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a9b22c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9b22f  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 00a9b236  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9b239  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a9b240  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a9b243  740e                   -je 0xa9b253
    if (cpu.flags.zf)
    {
        goto L_0x00a9b253;
    }
    // 00a9b245  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a9b24a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b24c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b24e  e8f50f0000             -call 0xa9c248
    cpu.esp -= 4;
    sub_a9c248(app, cpu);
    if (cpu.terminate) return;
L_0x00a9b253:
    // 00a9b253  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b255  e8d6d9ffff             -call 0xa98c30
    cpu.esp -= 4;
    sub_a98c30(app, cpu);
    if (cpu.terminate) return;
    // 00a9b25a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a9b25c:
    // 00a9b25c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b25d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b25e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b25f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9b264(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b264  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b265  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b266  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b267  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b26a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9b26c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9b26e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a9b270  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a9b272  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b274  e8c7fdffff             -call 0xa9b040
    cpu.esp -= 4;
    sub_a9b040(app, cpu);
    if (cpu.terminate) return;
    // 00a9b279  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b27b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b27d  7422                   -je 0xa9b2a1
    if (cpu.flags.zf)
    {
        goto L_0x00a9b2a1;
    }
    // 00a9b27f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b281  e83abdffff             -call 0xa96fc0
    cpu.esp -= 4;
    sub_a96fc0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b286  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9b288  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b28a  7413                   -je 0xa9b29f
    if (cpu.flags.zf)
    {
        goto L_0x00a9b29f;
    }
    // 00a9b28c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b28d  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b28f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b290  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b292  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a9b294  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9b298  e8dffeffff             -call 0xa9b17c
    cpu.esp -= 4;
    sub_a9b17c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b29d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a9b29f:
    // 00a9b29f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a9b2a1:
    // 00a9b2a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b2a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b2a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b2a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b2a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b2ab  e8b4ffffff             -call 0xa9b264
    cpu.esp -= 4;
    sub_a9b264(app, cpu);
    if (cpu.terminate) return;
    // 00a9b2b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9b2b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b2b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b2b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b2b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b2b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b2b9  ff15a8e2a900           -call dword ptr [0xa9e2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133608) /* 0xa9e2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b2bf  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a9b2c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b2c6  742b                   -je 0xa9b2f3
    if (cpu.flags.zf)
    {
        goto L_0x00a9b2f3;
    }
L_0x00a9b2c8:
    // 00a9b2c8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9b2cb  39d3                   +cmp ebx, edx
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
    // 00a9b2cd  751e                   -jne 0xa9b2ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b2ed;
    }
    // 00a9b2cf  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a9b2d3  740c                   -je 0xa9b2e1
    if (cpu.flags.zf)
    {
        goto L_0x00a9b2e1;
    }
    // 00a9b2d5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a9b2da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b2dc  e823bfffff             -call 0xa97204
    cpu.esp -= 4;
    sub_a97204(app, cpu);
    if (cpu.terminate) return;
L_0x00a9b2e1:
    // 00a9b2e1  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b2e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b2e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b2ed:
    // 00a9b2ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9b2ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b2f1  75d5                   -jne 0xa9b2c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b2c8;
    }
L_0x00a9b2f3:
    // 00a9b2f3  bae40faa00             -mov edx, 0xaa0fe4
    cpu.edx = 11145188 /*0xaa0fe4*/;
L_0x00a9b2f8:
    // 00a9b2f8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9b2fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b2fc  7426                   -je 0xa9b324
    if (cpu.flags.zf)
    {
        goto L_0x00a9b324;
    }
    // 00a9b2fe  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00a9b301  751d                   -jne 0xa9b320
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b320;
    }
    // 00a9b303  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9b305  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a9b307  8b15e00faa00           -mov edx, dword ptr [0xaa0fe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a9b30d  a3e00faa00             -mov dword ptr [0xaa0fe0], eax
    app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */) = cpu.eax;
    // 00a9b312  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9b314  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b31a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b31c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b31d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b31e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b31f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b320:
    // 00a9b320  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9b322  ebd4                   -jmp 0xa9b2f8
    goto L_0x00a9b2f8;
L_0x00a9b324:
    // 00a9b324  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a9b329  e892c0ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b32e  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b334  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b336  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b338  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b339  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9b33c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b33c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b33d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b33e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b33f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9b340  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b343  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9b345  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9b347  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a9b349  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b34b  e8f0fcffff             -call 0xa9b040
    cpu.esp -= 4;
    sub_a9b040(app, cpu);
    if (cpu.terminate) return;
    // 00a9b350  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9b352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b354  7455                   -je 0xa9b3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a9b3ab;
    }
    // 00a9b356  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a9b359  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b35b  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b361  833de4e2a90000         +cmp dword ptr [0xa9e2e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133668) /* 0xa9e2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b368  7408                   -je 0xa9b372
    if (cpu.flags.zf)
    {
        goto L_0x00a9b372;
    }
    // 00a9b36a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b36c  ff15e4e2a900           -call dword ptr [0xa9e2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133668) /* 0xa9e2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a9b372:
    // 00a9b372  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b374  e83bffffff             -call 0xa9b2b4
    cpu.esp -= 4;
    sub_a9b2b4(app, cpu);
    if (cpu.terminate) return;
    // 00a9b379  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b37b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b37d  7422                   -je 0xa9b3a1
    if (cpu.flags.zf)
    {
        goto L_0x00a9b3a1;
    }
    // 00a9b37f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b380  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a9b383  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b385  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00a9b38b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9b38d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a9b390  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a9b392  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9b394  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a9b396  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9b39a  e8ddfdffff             -call 0xa9b17c
    cpu.esp -= 4;
    sub_a9b17c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b39f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a9b3a1:
    // 00a9b3a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b3a3  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b3a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9b3ab:
    // 00a9b3ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b3ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b3c0  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b3c6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9b3cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b3cc  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b3d2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9b3d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b3e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b3e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b3e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b3e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b3e3  2eff1514cea900         -call dword ptr cs:[0xa9ce14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128340) /* 0xa9ce14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b3ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b3ec  7507                   -jne 0xa9b3f5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b3f5;
    }
    // 00a9b3ee  e891dcffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b3f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b3f5:
    // 00a9b3f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b3f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b3f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b400(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b401  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b403  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b406  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9b408  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9b40a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b40c  7525                   -jne 0xa9b433
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b433;
    }
    // 00a9b40e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00a9b413  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b415  e86698ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9b41a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9b41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b41e  7511                   -jne 0xa9b431
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b431;
    }
    // 00a9b420  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9b425  e896bfffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b42a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9b42c  e974000000             -jmp 0xa9b4a5
    goto L_0x00a9b4a5;
L_0x00a9b431:
    // 00a9b431  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a9b433:
    // 00a9b433  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a9b435  7405                   -je 0xa9b43c
    if (cpu.flags.zf)
    {
        goto L_0x00a9b43c;
    }
    // 00a9b437  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9b43a  7510                   -jne 0xa9b44c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b44c;
    }
L_0x00a9b43c:
    // 00a9b43c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a9b43e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b440  e86b000000             -call 0xa9b4b0
    cpu.esp -= 4;
    sub_a9b4b0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b445  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b44b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b44c:
    // 00a9b44c  bafcf3a900             -mov edx, 0xa9f3fc
    cpu.edx = 11138044 /*0xa9f3fc*/;
    // 00a9b451  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b453  e8680f0000             -call 0xa9c3c0
    cpu.esp -= 4;
    sub_a9c3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b45a  7528                   -jne 0xa9b484
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b484;
    }
    // 00a9b45c  83fb04                 +cmp ebx, 4
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
    // 00a9b45f  731a                   -jae 0xa9b47b
    if (!cpu.flags.cf)
    {
        goto L_0x00a9b47b;
    }
    // 00a9b461  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9b463  e80899ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9b468  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a9b46d  e84ebfffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b472  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b474  83c404                 +add esp, 4
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
    // 00a9b477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b478  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b47a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b47b:
    // 00a9b47b  a1fcf3a900             -mov eax, dword ptr [0xa9f3fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11138044) /* 0xa9f3fc */);
    // 00a9b480  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a9b482  eb1f                   -jmp 0xa9b4a3
    goto L_0x00a9b4a3;
L_0x00a9b484:
    // 00a9b484  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9b486  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b487  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b489  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b48a  2eff15e0cda900         -call dword ptr cs:[0xa9cde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128288) /* 0xa9cde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b491  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b493  750e                   -jne 0xa9b4a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b4a3;
    }
    // 00a9b495  e8eadbffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b49a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b49c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b49f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b4a3:
    // 00a9b4a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a9b4a5:
    // 00a9b4a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b4a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b4ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9b4b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b4b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b4b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b4b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b4b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b4b4  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a9b4ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b4bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9b4be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9b4c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b4c1  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a9b4c6  2eff15c4cda900         -call dword ptr cs:[0xa9cdc4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128260) /* 0xa9cdc4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b4cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9b4cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b4d1  7509                   -jne 0xa9b4dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b4dc;
    }
    // 00a9b4d3  e8acdbffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b4d8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9b4da  eb65                   -jmp 0xa9b541
    goto L_0x00a9b541;
L_0x00a9b4dc:
    // 00a9b4dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9b4de  7529                   -jne 0xa9b509
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b509;
    }
    // 00a9b4e0  40                     -inc eax
    (cpu.eax)++;
    // 00a9b4e1  39c6                   +cmp esi, eax
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
    // 00a9b4e3  7602                   -jbe 0xa9b4e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b4e7;
    }
    // 00a9b4e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a9b4e7:
    // 00a9b4e7  e89497ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9b4ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b4ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b4f0  7532                   -jne 0xa9b524
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b524;
    }
    // 00a9b4f2  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9b4f7  e8c4beffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b4fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b4fe  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a9b504  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b505  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b506  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b507  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b508  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b509:
    // 00a9b509  39f0                   +cmp eax, esi
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
    // 00a9b50b  7617                   -jbe 0xa9b524
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b524;
    }
    // 00a9b50d  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a9b512  e8a9beffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b517  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b519  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a9b51f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b520  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b522  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b523  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b524:
    // 00a9b524  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00a9b526  41                     -inc ecx
    (cpu.ecx)++;
    // 00a9b527  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a9b529  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9b52a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9b52c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9b52e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b52f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b531  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9b534  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9b536  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9b538  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9b53b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9b53d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b53e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9b53f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9b541:
    // 00a9b541  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a9b547  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b548  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b549  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b54a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b54b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9b550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b553  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b555  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b557  7c08                   -jl 0xa9b561
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9b561;
    }
    // 00a9b559  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11134320) /* 0xa9e570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b55f  7613                   -jbe 0xa9b574
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b574;
    }
L_0x00a9b561:
    // 00a9b561  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a9b566  e855beffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b56b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9b570  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b571  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b572  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b573  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b574:
    // 00a9b574  8b1588e3a900           -mov edx, dword ptr [0xa9e388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9b57a  8b149a                 -mov edx, dword ptr [edx + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a9b57d  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b583  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a9b585  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9b587  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9b589  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b58a  2eff1530cea900         -call dword ptr cs:[0xa9ce30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128368) /* 0xa9ce30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b591  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9b593  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b595  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b59b  83faff                 +cmp edx, -1
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
    // 00a9b59e  7505                   -jne 0xa9b5a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b5a5;
    }
    // 00a9b5a0  e8dfdaffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
L_0x00a9b5a5:
    // 00a9b5a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9b5a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b5b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b5b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b5b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9b5b3  2eff159ccda900         -call dword ptr cs:[0xa9cd9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128220) /* 0xa9cd9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b5ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b5bc  7508                   -jne 0xa9b5c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b5c6;
    }
    // 00a9b5be  e8c1daffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9b5c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b5c6:
    // 00a9b5c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b5c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b5ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b5d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b5d0  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b5d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9b5d5  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a9b5d7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b5e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b5e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b5e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b5e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9b5e8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9b5ea  ff15b0e2a900           -call dword ptr [0xa9e2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b5f0  b878e1a900             -mov eax, 0xa9e178
    cpu.eax = 11133304 /*0xa9e178*/;
    // 00a9b5f5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9b5f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b5f9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a9b5fb  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 00a9b5fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9b600  e817000000             -call 0xa9b61c
    cpu.esp -= 4;
    sub_a9b61c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b607  0f85bb010000           -jne 0xa9b7c8
    if (!cpu.flags.zf)
    {
        return sub_a9b7c8(app, cpu);
    }
    // 00a9b60d  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b613  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9b615  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b61a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b61b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b61c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b61c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b61d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b61e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9b61f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9b622  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a9b626  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9b628  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a9b62a  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 00a9b62d  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a9b62f  39d8                   +cmp eax, ebx
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
    // 00a9b631  7307                   -jae 0xa9b63a
    if (!cpu.flags.cf)
    {
        goto L_0x00a9b63a;
    }
    // 00a9b633  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9b638  eb0a                   -jmp 0xa9b644
    goto L_0x00a9b644;
L_0x00a9b63a:
    // 00a9b63a  83f810                 +cmp eax, 0x10
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
    // 00a9b63d  7305                   -jae 0xa9b644
    if (!cpu.flags.cf)
    {
        goto L_0x00a9b644;
    }
    // 00a9b63f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00a9b644:
    // 00a9b644  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00a9b647  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a9b64a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9b64c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a9b64f  39d0                   +cmp eax, edx
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
    // 00a9b651  0f860b010000           -jbe 0xa9b762
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9b762;
    }
    // 00a9b657  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b65a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b65c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00a9b65e:
    // 00a9b65e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a9b661  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a9b663  83fbff                 +cmp ebx, -1
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
    // 00a9b666  750a                   -jne 0xa9b672
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b672;
    }
    // 00a9b668  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a9b66d  e94d010000             -jmp 0xa9b7bf
    goto L_0x00a9b7bf;
L_0x00a9b672:
    // 00a9b672  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a9b675  0f85d9000000           -jne 0xa9b754
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b754;
    }
    // 00a9b67b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9b67e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9b682  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9b685  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9b687  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9b68b  b878e1a900             -mov eax, 0xa9e178
    cpu.eax = 11133304 /*0xa9e178*/;
    // 00a9b690  663b54240c             +cmp dx, word ptr [esp + 0xc]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9b695  7521                   -jne 0xa9b6b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b6b8;
    }
    // 00a9b697  8b3578e1a900           -mov esi, dword ptr [0xa9e178]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a9b69d  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a9b6a1  7415                   -je 0xa9b6b8
    if (cpu.flags.zf)
    {
        goto L_0x00a9b6b8;
    }
L_0x00a9b6a3:
    // 00a9b6a3  39fe                   +cmp esi, edi
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
    // 00a9b6a5  7708                   -ja 0xa9b6af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9b6af;
    }
    // 00a9b6a7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9b6a9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9b6ab  39f8                   +cmp eax, edi
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
    // 00a9b6ad  7709                   -ja 0xa9b6b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9b6b8;
    }
L_0x00a9b6af:
    // 00a9b6af  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9b6b2  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a9b6b6  75eb                   -jne 0xa9b6a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b6a3;
    }
L_0x00a9b6b8:
    // 00a9b6b8  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a9b6bb  39d1                   +cmp ecx, edx
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
    // 00a9b6bd  7506                   -jne 0xa9b6c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b6c5;
    }
    // 00a9b6bf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a9b6c2  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a9b6c5:
    // 00a9b6c5  3b5d00                 +cmp ebx, dword ptr [ebp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b6c8  720c                   -jb 0xa9b6d6
    if (cpu.flags.cf)
    {
        goto L_0x00a9b6d6;
    }
    // 00a9b6ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b6cc  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a9b6cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b6d1  83f810                 +cmp eax, 0x10
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
    // 00a9b6d4  7334                   -jae 0xa9b70a
    if (!cpu.flags.cf)
    {
        goto L_0x00a9b70a;
    }
L_0x00a9b6d6:
    // 00a9b6d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9b6da  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9b6de  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a9b6e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9b6e3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9b6e7  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a9b6ea  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b6ed  0118                   -add dword ptr [eax], ebx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b6ef  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a9b6f2  48                     -dec eax
    (cpu.eax)--;
    // 00a9b6f3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9b6f5  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a9b6f8  88154116aa00           -mov byte ptr [0xaa1641], dl
    app->getMemory<x86::reg8>(x86::reg32(11146817) /* 0xaa1641 */) = cpu.dl;
    // 00a9b6fe  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a9b701  39d3                   +cmp ebx, edx
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
    // 00a9b703  7244                   -jb 0xa9b749
    if (cpu.flags.cf)
    {
        goto L_0x00a9b749;
    }
    // 00a9b705  e9b3000000             -jmp 0xa9b7bd
    goto L_0x00a9b7bd;
L_0x00a9b70a:
    // 00a9b70a  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b70c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a9b70e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9b712  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9b715  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9b719  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9b71c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9b720  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a9b723  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9b727  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a9b72a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b72d  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a9b730  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9b732  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b734  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b736  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a9b738  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a9b73a  88254116aa00           -mov byte ptr [0xaa1641], ah
    app->getMemory<x86::reg8>(x86::reg32(11146817) /* 0xaa1641 */) = cpu.ah;
    // 00a9b740  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b742  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9b745  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b746  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b749:
    // 00a9b749  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9b74b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b74d  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9b74f  e90affffff             -jmp 0xa9b65e
    goto L_0x00a9b65e;
L_0x00a9b754:
    // 00a9b754  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a9b759  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b75b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9b75e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b75f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b761  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b762:
    // 00a9b762  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b764  83fa10                 +cmp edx, 0x10
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
    // 00a9b767  7254                   -jb 0xa9b7bd
    if (cpu.flags.cf)
    {
        goto L_0x00a9b7bd;
    }
    // 00a9b769  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b76b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b76e  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9b771  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9b774  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00a9b776  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a9b779  b878e1a900             -mov eax, 0xa9e178
    cpu.eax = 11133304 /*0xa9e178*/;
    // 00a9b77e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a9b781  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a9b783  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9b785  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9b789  6639da                 +cmp dx, bx
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
    // 00a9b78c  7521                   -jne 0xa9b7af
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b7af;
    }
    // 00a9b78e  8b3578e1a900           -mov esi, dword ptr [0xa9e178]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a9b794  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a9b798  7415                   -je 0xa9b7af
    if (cpu.flags.zf)
    {
        goto L_0x00a9b7af;
    }
L_0x00a9b79a:
    // 00a9b79a  39fe                   +cmp esi, edi
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
    // 00a9b79c  7708                   -ja 0xa9b7a6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9b7a6;
    }
    // 00a9b79e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9b7a0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9b7a2  39f8                   +cmp eax, edi
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
    // 00a9b7a4  7709                   -ja 0xa9b7af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9b7af;
    }
L_0x00a9b7a6:
    // 00a9b7a6  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a9b7a9  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a9b7ad  75eb                   -jne 0xa9b79a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b79a;
    }
L_0x00a9b7af:
    // 00a9b7af  ff4618                 -inc dword ptr [esi + 0x18]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))++;
    // 00a9b7b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b7b5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b7b8  e8b395ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a9b7bd:
    // 00a9b7bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a9b7bf:
    // 00a9b7bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b7c1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9b7c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b7c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7c8  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b7ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b7d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b7d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b7d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b7e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b7e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9b7e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7e4  ff1570e7a900           -call dword ptr [0xa9e770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134832) /* 0xa9e770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b7ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9b7ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7ec  ff1574e7a900           -call dword ptr [0xa9e774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134836) /* 0xa9e774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b7f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9b7f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7f4  ff1578e7a900           -call dword ptr [0xa9e778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134840) /* 0xa9e778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b7fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9b7fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b7fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b7fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b7fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b800  7410                   -je 0xa9b812
    if (cpu.flags.zf)
    {
        goto L_0x00a9b812;
    }
    // 00a9b802  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9b804  8b3570e7a900           -mov esi, dword ptr [0xa9e770]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11134832) /* 0xa9e770 */);
    // 00a9b80a  890d70e7a900           -mov dword ptr [0xa9e770], ecx
    app->getMemory<x86::reg32>(x86::reg32(11134832) /* 0xa9e770 */) = cpu.ecx;
    // 00a9b810  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x00a9b812:
    // 00a9b812  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9b814  740f                   -je 0xa9b825
    if (cpu.flags.zf)
    {
        goto L_0x00a9b825;
    }
    // 00a9b816  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9b818  8b0d74e7a900           -mov ecx, dword ptr [0xa9e774]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11134836) /* 0xa9e774 */);
    // 00a9b81e  a374e7a900             -mov dword ptr [0xa9e774], eax
    app->getMemory<x86::reg32>(x86::reg32(11134836) /* 0xa9e774 */) = cpu.eax;
    // 00a9b823  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x00a9b825:
    // 00a9b825  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9b827  740f                   -je 0xa9b838
    if (cpu.flags.zf)
    {
        goto L_0x00a9b838;
    }
    // 00a9b829  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a9b82b  8b1578e7a900           -mov edx, dword ptr [0xa9e778]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134840) /* 0xa9e778 */);
    // 00a9b831  a378e7a900             -mov dword ptr [0xa9e778], eax
    app->getMemory<x86::reg32>(x86::reg32(11134840) /* 0xa9e778 */) = cpu.eax;
    // 00a9b836  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00a9b838:
    // 00a9b838  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b839  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b83a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b840  ff157ce7a900           -call dword ptr [0xa9e77c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134844) /* 0xa9e77c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b846  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a9b848  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b849  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a9b84e  b800f4a900             -mov eax, 0xa9f400
    cpu.eax = 11138048 /*0xa9f400*/;
    // 00a9b853  e844b7ffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b848(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a9b848;
    // 00a9b840  ff157ce7a900           -call dword ptr [0xa9e77c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134844) /* 0xa9e77c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9b846  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a9b848:
    // 00a9b848  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b849  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a9b84e  b800f4a900             -mov eax, 0xa9f400
    cpu.eax = 11138048 /*0xa9f400*/;
    // 00a9b853  e844b7ffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a9b858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9b860(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b862  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b864  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b867  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b869  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9b86b  8a2588e1a900           -mov ah, byte ptr [0xa9e188]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11133320) /* 0xa9e188 */);
    // 00a9b871  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00a9b874  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a9b876  7426                   -je 0xa9b89e
    if (cpu.flags.zf)
    {
        goto L_0x00a9b89e;
    }
    // 00a9b878  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a9b87a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a9b87d  9b                     -wait 
    /*nothing*/;
    // 00a9b87e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9b880  741c                   -je 0xa9b89e
    if (cpu.flags.zf)
    {
        goto L_0x00a9b89e;
    }
    // 00a9b882  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9b884  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9b887  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a9b889  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9b88b  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9b88d  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b88f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a9b891  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9b894  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 00a9b897  9b                     -wait 
    /*nothing*/;
    // 00a9b898  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a9b89a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a9b89d  9b                     -wait 
    /*nothing*/;
L_0x00a9b89e:
    // 00a9b89e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b8a0  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 00a9b8a4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b8a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b8ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b8ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b8ad  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9b8b1  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a9b8b4  6681faff7f             +cmp dx, 0x7fff
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
    // 00a9b8b9  751c                   -jne 0xa9b8d7
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8d7;
    }
    // 00a9b8bb  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
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
    // 00a9b8c2  750c                   -jne 0xa9b8d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8d0;
    }
    // 00a9b8c4  833800                 +cmp dword ptr [eax], 0
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
    // 00a9b8c7  7507                   -jne 0xa9b8d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8d0;
    }
    // 00a9b8c9  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a9b8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b8d0:
    // 00a9b8d0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a9b8d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b8d7:
    // 00a9b8d7  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 00a9b8dd  7516                   -jne 0xa9b8f5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8f5;
    }
    // 00a9b8df  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a9b8e3  7509                   -jne 0xa9b8ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8ee;
    }
    // 00a9b8e5  833800                 +cmp dword ptr [eax], 0
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
    // 00a9b8e8  7504                   -jne 0xa9b8ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b8ee;
    }
    // 00a9b8ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b8ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b8ee:
    // 00a9b8ee  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a9b8f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9b8f5:
    // 00a9b8f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9b8fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b8fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b8fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b8fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9b8fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9b8fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9b8ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b901  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9b902  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9b904  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b906  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9b908  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9b90a  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9b90c:
    // 00a9b90c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9b90e  3c00                   +cmp al, 0
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
    // 00a9b910  742f                   -je 0xa9b941
    if (cpu.flags.zf)
    {
        goto L_0x00a9b941;
    }
    // 00a9b912  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9b914  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a9b916  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9b918  01ed                   +add ebp, ebp
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
    // 00a9b91a  11c9                   +adc ecx, ecx
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
    // 00a9b91c  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a9b91e  01ed                   +add ebp, ebp
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
    // 00a9b920  11c9                   +adc ecx, ecx
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
    // 00a9b922  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a9b924  01c5                   +add ebp, eax
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
    // 00a9b926  11d9                   +adc ecx, ebx
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
    // 00a9b928  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00a9b92a  01ed                   +add ebp, ebp
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
    // 00a9b92c  11c9                   +adc ecx, ecx
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
    // 00a9b92e  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a9b930  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b932  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9b934  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00a9b936  01c5                   +add ebp, eax
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
    // 00a9b938  83d100                 +adc ecx, 0
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
    // 00a9b93b  83d200                 +adc edx, 0
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
    // 00a9b93e  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9b93f  ebcb                   -jmp 0xa9b90c
    goto L_0x00a9b90c;
L_0x00a9b941:
    // 00a9b941  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b943  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 00a9b948  e811000000             -call 0xa9b95e
    cpu.esp -= 4;
    sub_a9b95e(app, cpu);
    if (cpu.terminate) return;
    // 00a9b94d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b94e  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a9b951  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a9b954  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 00a9b958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b95a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b95b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b95c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9b95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9b95e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b95e  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9b960  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9b962  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9b964  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00a9b966  7436                   -je 0xa9b99e
    if (cpu.flags.zf)
    {
        goto L_0x00a9b99e;
    }
    // 00a9b968  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b96a  7509                   -jne 0xa9b975
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b975;
    }
    // 00a9b96c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9b96e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9b970  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9b972  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a9b975:
    // 00a9b975  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b977  7509                   -jne 0xa9b982
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b982;
    }
    // 00a9b979  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9b97b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9b97d  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9b97f  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a9b982:
    // 00a9b982  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9b984  7809                   -js 0xa9b98f
    if (cpu.flags.sf)
    {
        goto L_0x00a9b98f;
    }
    // 00a9b986  4f                     -dec edi
    (cpu.edi)--;
    // 00a9b987  01ed                   +add ebp, ebp
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
    // 00a9b989  11c0                   +adc eax, eax
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
    // 00a9b98b  11d2                   +adc edx, edx
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
    // 00a9b98d  ebf3                   -jmp 0xa9b982
    goto L_0x00a9b982;
L_0x00a9b98f:
    // 00a9b98f  01ed                   +add ebp, ebp
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
    // 00a9b991  83d000                 +adc eax, 0
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
    // 00a9b994  83d200                 +adc edx, 0
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
    // 00a9b997  7303                   -jae 0xa9b99c
    if (!cpu.flags.cf)
    {
        goto L_0x00a9b99c;
    }
    // 00a9b999  d1da                   -rcr edx, 1
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
    // 00a9b99b  47                     -inc edi
    (cpu.edi)++;
L_0x00a9b99c:
    // 00a9b99c  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00a9b99e:
    // 00a9b99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a9b9a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b9a0  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b9a3  7c08                   -jl 0xa9b9ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9b9ad;
    }
    // 00a9b9a5  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9b9a8  7f03                   -jg 0xa9b9ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9b9ad;
    }
    // 00a9b9aa  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a9b9ad:
    // 00a9b9ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a9b9b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9b9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9b9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9b9b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9b9b5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b9b7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9b9b9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a9b9bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9b9bd  e8aef5ffff             -call 0xa9af70
    cpu.esp -= 4;
    sub_a9af70(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9c2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9b9c4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9b9c6  e885d1ffff             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9cb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x00a9b9ce:
    // 00a9b9ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b9d0  e80bb3ffff             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b9d7  7518                   -jne 0xa9b9f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a9b9f1;
    }
    // 00a9b9d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a9b9db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b9dd  e8eed1ffff             -call 0xa98bd0
    cpu.esp -= 4;
    sub_a98bd0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b9e4  740b                   -je 0xa9b9f1
    if (cpu.flags.zf)
    {
        goto L_0x00a9b9f1;
    }
    // 00a9b9e6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b9e8  e893b3ffff             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9b9ef  ebdd                   -jmp 0xa9b9ce
    goto L_0x00a9b9ce;
L_0x00a9b9f1:
    // 00a9b9f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9b9f3  e8e8b2ffff             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a9b9f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9b9fa  7404                   -je 0xa9ba00
    if (cpu.flags.zf)
    {
        goto L_0x00a9ba00;
    }
    // 00a9b9fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a9b9fe  7504                   -jne 0xa9ba04
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ba04;
    }
L_0x00a9ba00:
    // 00a9ba00  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9ba02  eb02                   -jmp 0xa9ba06
    goto L_0x00a9ba06;
L_0x00a9ba04:
    // 00a9ba04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9ba06:
    // 00a9ba06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9ba09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9ba10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ba10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9ba11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9ba12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9ba14  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a9ba16:
    // 00a9ba16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9ba18  e8c3b2ffff             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ba1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ba1f  750c                   -jne 0xa9ba2d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ba2d;
    }
    // 00a9ba21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9ba23  e858b3ffff             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a9ba28  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9ba29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9ba2b  ebe9                   -jmp 0xa9ba16
    goto L_0x00a9ba16;
L_0x00a9ba2d:
    // 00a9ba2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9ba2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9ba40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ba40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9ba41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9ba42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9ba43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9ba44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9ba46  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9ba48  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a9ba4a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9ba4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ba4e  7438                   -je 0xa9ba88
    if (cpu.flags.zf)
    {
        goto L_0x00a9ba88;
    }
L_0x00a9ba50:
    // 00a9ba50  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9ba52  765a                   -jbe 0xa9baae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9baae;
    }
    // 00a9ba54  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ba57  7418                   -je 0xa9ba71
    if (cpu.flags.zf)
    {
        goto L_0x00a9ba71;
    }
    // 00a9ba59  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a9ba5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9ba60  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9ba62  e8490b0000             -call 0xa9c5b0
    cpu.esp -= 4;
    sub_a9c5b0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ba67  83f8ff                 +cmp eax, -1
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
    // 00a9ba6a  750c                   -jne 0xa9ba78
    if (!cpu.flags.zf)
    {
        goto L_0x00a9ba78;
    }
    // 00a9ba6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9ba70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ba71:
    // 00a9ba71  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a9ba76  eb36                   -jmp 0xa9baae
    goto L_0x00a9baae;
L_0x00a9ba78:
    // 00a9ba78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9ba7a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a9ba7b  e800b3ffff             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a9ba80  83c602                 +add esi, 2
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
    // 00a9ba83  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9ba84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9ba86  ebc8                   -jmp 0xa9ba50
    goto L_0x00a9ba50;
L_0x00a9ba88:
    // 00a9ba88  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00a9ba8d:
    // 00a9ba8d  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9ba90  741c                   -je 0xa9baae
    if (cpu.flags.zf)
    {
        goto L_0x00a9baae;
    }
    // 00a9ba92  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a9ba94  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9ba96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9ba98  e8130b0000             -call 0xa9c5b0
    cpu.esp -= 4;
    sub_a9c5b0(app, cpu);
    if (cpu.terminate) return;
    // 00a9ba9d  83f8ff                 +cmp eax, -1
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
    // 00a9baa0  740e                   -je 0xa9bab0
    if (cpu.flags.zf)
    {
        goto L_0x00a9bab0;
    }
    // 00a9baa2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9baa4  e8d7b2ffff             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a9baa9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9baaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9baac  ebdf                   -jmp 0xa9ba8d
    goto L_0x00a9ba8d;
L_0x00a9baae:
    // 00a9baae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a9bab0:
    // 00a9bab0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bab1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bab2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bab3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bab4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9bac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9bac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9bac5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9bac6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bac9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9bacb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a9bad0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a9bad4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a9bad7  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a9badc  e86f0b0000             -call 0xa9c650
    cpu.esp -= 4;
    sub_a9c650(app, cpu);
    if (cpu.terminate) return;
    // 00a9bae1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bae5  750a                   -jne 0xa9baf1
    if (!cpu.flags.zf)
    {
        goto L_0x00a9baf1;
    }
    // 00a9bae7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9baec  e95a010000             -jmp 0xa9bc4b
    goto L_0x00a9bc4b;
L_0x00a9baf1:
    // 00a9baf1  39c8                   +cmp eax, ecx
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
    // 00a9baf3  750f                   -jne 0xa9bb04
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bb04;
    }
    // 00a9baf5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bafa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bafd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bafe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9baff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bb04:
    // 00a9bb04  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9bb06  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a9bb08  8d2c4500000000         -lea ebp, [eax*2]
    cpu.ebp = x86::reg32(cpu.eax * 2);
    // 00a9bb0f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a9bb12  e86991ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb17  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9bb19  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9bb1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bb1f  750f                   -jne 0xa9bb30
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bb30;
    }
    // 00a9bb21  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bb26  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bb29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bb30:
    // 00a9bb30  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a9bb32  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9bb34  e8b7d8ffff             -call 0xa993f0
    cpu.esp -= 4;
    sub_a993f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb39  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a9bb3c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9bb3e  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a9bb44  e887d8ffff             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bb4b  7442                   -je 0xa9bb8f
    if (cpu.flags.zf)
    {
        goto L_0x00a9bb8f;
    }
    // 00a9bb4d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9bb4f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a9bb53  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9bb56  e82591ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bb5d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9bb5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bb61  7516                   -jne 0xa9bb79
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bb79;
    }
    // 00a9bb63  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9bb65  e80692ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb6a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bb6f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bb72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bb78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bb79:
    // 00a9bb79  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9bb7d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9bb81  01f7                   +add edi, esi
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
    // 00a9bb83  e868d8ffff             -call 0xa993f0
    cpu.esp -= 4;
    sub_a993f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb88  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a9bb8d  eb02                   -jmp 0xa9bb91
    goto L_0x00a9bb91;
L_0x00a9bb8f:
    // 00a9bb8f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a9bb91:
    // 00a9bb91  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9bb95  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a9bb97  e8e40a0000             -call 0xa9c680
    cpu.esp -= 4;
    sub_a9c680(app, cpu);
    if (cpu.terminate) return;
    // 00a9bb9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9bb9e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9bba2  e8c991ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9bba7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9bba9  e8c291ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9bbae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9bbb0  750f                   -jne 0xa9bbc1
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bbc1;
    }
    // 00a9bbb2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bbb7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bbba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bbc1:
    // 00a9bbc1  833d0810aa0000         +cmp dword ptr [0xaa1008], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9bbc8  7505                   -jne 0xa9bbcf
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bbcf;
    }
    // 00a9bbca  e8b10b0000             -call 0xa9c780
    cpu.esp -= 4;
    sub_a9c780(app, cpu);
    if (cpu.terminate) return;
L_0x00a9bbcf:
    // 00a9bbcf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9bbd1  e882000000             -call 0xa9bc58
    cpu.esp -= 4;
    sub_a9bc58(app, cpu);
    if (cpu.terminate) return;
    // 00a9bbd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bbd8  740f                   -je 0xa9bbe9
    if (cpu.flags.zf)
    {
        goto L_0x00a9bbe9;
    }
    // 00a9bbda  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bbdf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bbe2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bbe8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bbe9:
    // 00a9bbe9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9bbeb  e8e0d7ffff             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bbf0  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9bbf3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9bbf7  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a9bbfa  e88190ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9bbff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9bc01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bc03  7519                   -jne 0xa9bc1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bc1e;
    }
    // 00a9bc05  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9bc0a  e80dd4ffff             -call 0xa9901c
    cpu.esp -= 4;
    sub_a9901c(app, cpu);
    if (cpu.terminate) return;
    // 00a9bc0f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bc14  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bc17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bc1e:
    // 00a9bc1e  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a9bc22  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9bc24  e8b70b0000             -call 0xa9c7e0
    cpu.esp -= 4;
    sub_a9c7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bc29  83f8ff                 +cmp eax, -1
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
    // 00a9bc2c  7516                   -jne 0xa9bc44
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bc44;
    }
    // 00a9bc2e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9bc30  e83b91ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9bc35  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bc3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bc3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bc44:
    // 00a9bc44  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9bc46  e8c1efffff             -call 0xa9ac0c
    cpu.esp -= 4;
    sub_a9ac0c(app, cpu);
    if (cpu.terminate) return;
L_0x00a9bc4b:
    // 00a9bc4b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bc4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bc54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9bc58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bc58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bc59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bc5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bc5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9bc5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9bc5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9bc5e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bc61  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bc63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bc65  750a                   -jne 0xa9bc71
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bc71;
    }
    // 00a9bc67  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bc6c  e963010000             -jmp 0xa9bdd4
    goto L_0x00a9bdd4;
L_0x00a9bc71:
    // 00a9bc71  66833800               +cmp word ptr [eax], 0
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
    // 00a9bc75  741b                   -je 0xa9bc92
    if (cpu.flags.zf)
    {
        goto L_0x00a9bc92;
    }
    // 00a9bc77  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a9bc7a  66833a00               +cmp word ptr [edx], 0
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
    // 00a9bc7e  7412                   -je 0xa9bc92
    if (cpu.flags.zf)
    {
        goto L_0x00a9bc92;
    }
L_0x00a9bc80:
    // 00a9bc80  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9bc84  740c                   -je 0xa9bc92
    if (cpu.flags.zf)
    {
        goto L_0x00a9bc92;
    }
    // 00a9bc86  668b7202               -mov si, word ptr [edx + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00a9bc8a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9bc8d  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a9bc90  75ee                   -jne 0xa9bc80
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bc80;
    }
L_0x00a9bc92:
    // 00a9bc92  66833a00               +cmp word ptr [edx], 0
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
    // 00a9bc96  750f                   -jne 0xa9bca7
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bca7;
    }
    // 00a9bc98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bc9d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bca0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bca7:
    // 00a9bca7  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9bcac  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a9bcaf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9bcb1  8b0d0810aa00           -mov ecx, dword ptr [0xaa1008]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9bcb7  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00a9bcb9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a9bcbb  7541                   -jne 0xa9bcfe
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bcfe;
    }
    // 00a9bcbd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9bcbf  0f850d010000           -jne 0xa9bdd2
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bdd2;
    }
    // 00a9bcc5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9bcca  e8b18fffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9bccf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9bcd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bcd3  750f                   -jne 0xa9bce4
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bce4;
    }
    // 00a9bcd5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bcda  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bcdd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bcde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bcdf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bce0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bce1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bce3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bce4:
    // 00a9bce4  a30810aa00             -mov dword ptr [0xaa1008], eax
    app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */) = cpu.eax;
    // 00a9bce9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bcec  8958f8                 -mov dword ptr [eax - 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a9bcef  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a9bcf1  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a9bcf4  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a9bcf9  e9c8000000             -jmp 0xa9bdc6
    goto L_0x00a9bdc6;
L_0x00a9bcfe:
    // 00a9bcfe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a9bd00  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9bd02  e8d9000000             -call 0xa9bde0
    cpu.esp -= 4;
    sub_a9bde0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bd07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9bd09  0f85c3000000           -jne 0xa9bdd2
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bdd2;
    }
    // 00a9bd0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bd11  0f8fac000000           -jg 0xa9bdc3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9bdc3;
    }
    // 00a9bd17  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a9bd19  8b2d0010aa00           -mov ebp, dword ptr [0xaa1000]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9bd1f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9bd21  40                     -inc eax
    (cpu.eax)++;
    // 00a9bd22  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 00a9bd29  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9bd2c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9bd2f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9bd32  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9bd36  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9bd38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9bd3a  753e                   -jne 0xa9bd7a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bd7a;
    }
    // 00a9bd3c  e83f8fffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9bd41  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9bd43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9bd45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bd47  750f                   -jne 0xa9bd58
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bd58;
    }
    // 00a9bd49  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bd4e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bd51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bd58:
    // 00a9bd58  8b150810aa00           -mov edx, dword ptr [0xaa1008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9bd5e  e88dd6ffff             -call 0xa993f0
    cpu.esp -= 4;
    sub_a993f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bd63  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9bd67  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9bd6a  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9bd6c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a9bd6e  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a9bd73  e8f88dffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9bd78  eb39                   -jmp 0xa9bdb3
    goto L_0x00a9bdb3;
L_0x00a9bd7a:
    // 00a9bd7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9bd7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9bd7e  e81dd3ffff             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bd83  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9bd85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bd87  750f                   -jne 0xa9bd98
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bd98;
    }
    // 00a9bd89  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bd8e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bd91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bd97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bd98:
    // 00a9bd98  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9bd9c  8b150010aa00           -mov edx, dword ptr [0xaa1000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9bda2  01c5                   +add ebp, eax
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
    // 00a9bda4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a9bda6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9bda8  e843010000             -call 0xa9bef0
    cpu.esp -= 4;
    sub_a9bef0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bdad  892d0010aa00           -mov dword ptr [0xaa1000], ebp
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.ebp;
L_0x00a9bdb3:
    // 00a9bdb3  890d0810aa00           -mov dword ptr [0xaa1008], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */) = cpu.ecx;
    // 00a9bdb9  c744b10400000000       -mov dword ptr [ecx + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) = 0 /*0x0*/;
    // 00a9bdc1  eb03                   -jmp 0xa9bdc6
    goto L_0x00a9bdc6;
L_0x00a9bdc3:
    // 00a9bdc3  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a9bdc6:
    // 00a9bdc6  a10010aa00             -mov eax, dword ptr [0xaa1000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9bdcb  893cb1                 -mov dword ptr [ecx + esi*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edi;
    // 00a9bdce  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a9bdd2:
    // 00a9bdd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9bdd4:
    // 00a9bdd4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9bdd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bdd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bdd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bdda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bddb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bddc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bddd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9bde0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9bde3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9bde4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9bde5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bde7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a9bde9  8b350810aa00           -mov esi, dword ptr [0xaa1008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9bdef  e9d7000000             -jmp 0xa9becb
    goto L_0x00a9becb;
L_0x00a9bdf4:
    // 00a9bdf4  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 00a9bdf7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a9bdf9  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a9bdfc  0f84c6000000           -je 0xa9bec8
    if (cpu.flags.zf)
    {
        goto L_0x00a9bec8;
    }
L_0x00a9be02:
    // 00a9be02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9be04  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00a9be07  e8940a0000             -call 0xa9c8a0
    cpu.esp -= 4;
    sub_a9c8a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9be0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9be0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9be10  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 00a9be13  e8880a0000             -call 0xa9c8a0
    cpu.esp -= 4;
    sub_a9c8a0(app, cpu);
    if (cpu.terminate) return;
    // 00a9be18  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9be1b  0f85a7000000           -jne 0xa9bec8
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bec8;
    }
    // 00a9be21  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9be25  0f858a000000           -jne 0xa9beb5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9beb5;
    }
    // 00a9be2b  8b150810aa00           -mov edx, dword ptr [0xaa1008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9be31  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a9be33  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9be35  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a9be38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9be3a  0f846c000000           -je 0xa9beac
    if (cpu.flags.zf)
    {
        goto L_0x00a9beac;
    }
    // 00a9be40  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9be42  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a9be44  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9be46  740f                   -je 0xa9be57
    if (cpu.flags.zf)
    {
        goto L_0x00a9be57;
    }
L_0x00a9be48:
    // 00a9be48  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9be4b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a9be4d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9be50  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9be53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9be55  75f1                   -jne 0xa9be48
    if (!cpu.flags.zf)
    {
        goto L_0x00a9be48;
    }
L_0x00a9be57:
    // 00a9be57  8b350010aa00           -mov esi, dword ptr [0xaa1000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9be5d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9be5f  7443                   -je 0xa9bea4
    if (cpu.flags.zf)
    {
        goto L_0x00a9bea4;
    }
    // 00a9be61  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9be63  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9be67  7407                   -je 0xa9be70
    if (cpu.flags.zf)
    {
        goto L_0x00a9be70;
    }
    // 00a9be69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9be6b  e8008fffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a9be70:
    // 00a9be70  8b2d0810aa00           -mov ebp, dword ptr [0xaa1008]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9be76  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a9be78  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a9be7a  8b150010aa00           -mov edx, dword ptr [0xaa1000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a9be80  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a9be83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9be85  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a9be87  e864000000             -call 0xa9bef0
    cpu.esp -= 4;
    sub_a9bef0(app, cpu);
    if (cpu.terminate) return;
    // 00a9be8c  890d0010aa00           -mov dword ptr [0xaa1000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.ecx;
    // 00a9be92  39f7                   +cmp edi, esi
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
    // 00a9be94  7d0e                   -jge 0xa9bea4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9bea4;
    }
    // 00a9be96  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a9be99:
    // 00a9be99  40                     -inc eax
    (cpu.eax)++;
    // 00a9be9a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9be9c  47                     -inc edi
    (cpu.edi)++;
    // 00a9be9d  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a9bea0  39f7                   +cmp edi, esi
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
    // 00a9bea2  7cf5                   -jl 0xa9be99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9be99;
    }
L_0x00a9bea4:
    // 00a9bea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9bea6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bea7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bea8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9beac:
    // 00a9beac  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a9beaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9beb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9beb5:
    // 00a9beb5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9beb8  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a9bebc  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9bebf  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00a9bec2  0f853affffff           -jne 0xa9be02
    if (!cpu.flags.zf)
    {
        goto L_0x00a9be02;
    }
L_0x00a9bec8:
    // 00a9bec8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a9becb:
    // 00a9becb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9becd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9becf  0f851fffffff           -jne 0xa9bdf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a9bdf4;
    }
    // 00a9bed5  a10810aa00             -mov eax, dword ptr [0xaa1008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145224) /* 0xaa1008 */);
    // 00a9beda  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9bedc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a9bedf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bee0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bee1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bee2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bee3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9bef0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9bef2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9bef3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a9bef5  39c2                   +cmp edx, eax
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
    // 00a9bef7  7440                   -je 0xa9bf39
    if (cpu.flags.zf)
    {
        goto L_0x00a9bf39;
    }
    // 00a9bef9  7328                   -jae 0xa9bf23
    if (!cpu.flags.cf)
    {
        goto L_0x00a9bf23;
    }
    // 00a9befb  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a9befe  39c7                   +cmp edi, eax
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
    // 00a9bf00  7621                   -jbe 0xa9bf23
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9bf23;
    }
    // 00a9bf02  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00a9bf05  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00a9bf08  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9bf0a  4f                     -dec edi
    (cpu.edi)--;
    // 00a9bf0b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9bf0c  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a9bf0e  fd                     -std 
    cpu.flags.df = 1;
    // 00a9bf0f  4e                     -dec esi
    (cpu.esi)--;
    // 00a9bf10  4f                     -dec edi
    (cpu.edi)--;
    // 00a9bf11  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a9bf13  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
            cpu.esi -= 2;
        }
        else
        {
            cpu.edi += 2;
            cpu.esi += 2;
        }
        --cpu.ecx;
    }
    // 00a9bf16  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00a9bf18  46                     -inc esi
    (cpu.esi)++;
    // 00a9bf19  47                     -inc edi
    (cpu.edi)++;
    // 00a9bf1a  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9bf1d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf1e  fc                     -cld 
    cpu.flags.df = 0;
    // 00a9bf1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9bf23:
    // 00a9bf23  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9bf25  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bf27  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9bf29  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9bf2a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a9bf2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bf2d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9bf30  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9bf32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf33  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a9bf36  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9bf38  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a9bf39:
    // 00a9bf39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a9bf40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bf40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bf41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9bf43  e868090000             -call 0xa9c8b0
    cpu.esp -= 4;
    sub_a9c8b0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bf48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bf4a  7403                   -je 0xa9bf4f
    if (cpu.flags.zf)
    {
        goto L_0x00a9bf4f;
    }
    // 00a9bf4c  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00a9bf4f:
    // 00a9bf4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9bf51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9bf60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bf60  c70580e7a90001000000   -mov dword ptr [0xa9e780], 1
    app->getMemory<x86::reg32>(x86::reg32(11134848) /* 0xa9e780 */) = 1 /*0x1*/;
    // 00a9bf6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9bf70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bf70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bf71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bf72  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9bf76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9bf79  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9bf7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9bf7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9bf7f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a9bf83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bf84  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a9bf88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bf89  e806000000             -call 0xa9bf94
    cpu.esp -= 4;
    sub_a9bf94(app, cpu);
    if (cpu.terminate) return;
    // 00a9bf8e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9bf91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bf93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9bf94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bf94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9bf95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9bf96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9bf97  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9bf9a  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a9bf9e  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a9bfa0  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a9bfa4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a9bfa8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9bfab  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9bfaf  e808000000             -call 0xa9bfbc
    cpu.esp -= 4;
    sub_a9bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00a9bfb4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9bfb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bfb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bfb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9bfba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9bfbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9bfbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9bfbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9bfbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9bfbf  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a9bfc2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9bfc4  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a9bfc8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a9bfca  e831b5ffff             -call 0xa97500
    cpu.esp -= 4;
    sub_a97500(app, cpu);
    if (cpu.terminate) return;
    // 00a9bfcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9bfd1  7414                   -je 0xa9bfe7
    if (cpu.flags.zf)
    {
        goto L_0x00a9bfe7;
    }
    // 00a9bfd3  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00a9bfd8  e8e3b3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9bfdd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9bfe2  e9fe010000             -jmp 0xa9c1e5
    goto L_0x00a9c1e5;
L_0x00a9bfe7:
    // 00a9bfe7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9bfe9  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9bfed  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a9bff0  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9bff4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9bff6  e835090000             -call 0xa9c930
    cpu.esp -= 4;
    sub_a9c930(app, cpu);
    if (cpu.terminate) return;
    // 00a9bffb  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9bfff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9c001  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9c003  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00a9c005  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 00a9c00a  e855090000             -call 0xa9c964
    cpu.esp -= 4;
    sub_a9c964(app, cpu);
    if (cpu.terminate) return;
    // 00a9c00f  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00a9c014  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a9c018  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a9c01c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a9c01f  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00a9c022  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a9c025  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9c02a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a9c02e  833de8e2a90000         +cmp dword ptr [0xa9e2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133672) /* 0xa9e2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c035  7434                   -je 0xa9c06b
    if (cpu.flags.zf)
    {
        goto L_0x00a9c06b;
    }
    // 00a9c037  ba18f4a900             -mov edx, 0xa9f418
    cpu.edx = 11138072 /*0xa9f418*/;
    // 00a9c03c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9c03e  e87d030000             -call 0xa9c3c0
    cpu.esp -= 4;
    sub_a9c3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c043  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c045  7524                   -jne 0xa9c06b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c06b;
    }
    // 00a9c047  e8f4b6ffff             -call 0xa97740
    cpu.esp -= 4;
    sub_a97740(app, cpu);
    if (cpu.terminate) return;
    // 00a9c04c  ff15a0e2a900           -call dword ptr [0xa9e2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133600) /* 0xa9e2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c052  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a9c054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c055  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c056  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00a9c05b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c05d  ff15e8e2a900           -call dword ptr [0xa9e2e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133672) /* 0xa9e2e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c063  83c40c                 +add esp, 0xc
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
    // 00a9c066  e92a010000             -jmp 0xa9c195
    goto L_0x00a9c195;
L_0x00a9c06b:
    // 00a9c06b  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a9c06f  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00a9c072  0f8472000000           -je 0xa9c0ea
    if (cpu.flags.zf)
    {
        goto L_0x00a9c0ea;
    }
    // 00a9c078  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a9c07a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c07d  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00a9c07f  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a9c082  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a9c086  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00a9c08c  a184e7a900             -mov eax, dword ptr [0xa9e784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134852) /* 0xa9e784 */);
    // 00a9c091  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a9c095  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a9c097  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c099  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a9c09d  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 00a9c0a2  740c                   -je 0xa9c0b0
    if (cpu.flags.zf)
    {
        goto L_0x00a9c0b0;
    }
    // 00a9c0a4  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 00a9c0a9  7505                   -jne 0xa9c0b0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c0b0;
    }
    // 00a9c0ab  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00a9c0b0:
    // 00a9c0b0  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 00a9c0b5  740d                   -je 0xa9c0c4
    if (cpu.flags.zf)
    {
        goto L_0x00a9c0c4;
    }
    // 00a9c0b7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a9c0bc  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a9c0c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c0c2  eb37                   -jmp 0xa9c0fb
    goto L_0x00a9c0fb;
L_0x00a9c0c4:
    // 00a9c0c4  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 00a9c0c9  740f                   -je 0xa9c0da
    if (cpu.flags.zf)
    {
        goto L_0x00a9c0da;
    }
    // 00a9c0cb  c744241802000000       -mov dword ptr [esp + 0x18], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
    // 00a9c0d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9c0d8  eb21                   -jmp 0xa9c0fb
    goto L_0x00a9c0fb;
L_0x00a9c0da:
    // 00a9c0da  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00a9c0df  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a9c0e4  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00a9c0e8  eb11                   -jmp 0xa9c0fb
    goto L_0x00a9c0fb;
L_0x00a9c0ea:
    // 00a9c0ea  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00a9c0ed  7407                   -je 0xa9c0f6
    if (cpu.flags.zf)
    {
        goto L_0x00a9c0f6;
    }
    // 00a9c0ef  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9c0f4  eb05                   -jmp 0xa9c0fb
    goto L_0x00a9c0fb;
L_0x00a9c0f6:
    // 00a9c0f6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00a9c0fb:
    // 00a9c0fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c0fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c0fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c0ff  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a9c103  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c104  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a9c108  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c109  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a9c10d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c10e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c10f  2eff1590cda900         -call dword ptr cs:[0xa9cd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128208) /* 0xa9cd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c116  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9c118  83f8ff                 +cmp eax, -1
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
    // 00a9c11b  7536                   -jne 0xa9c153
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c153;
    }
    // 00a9c11d  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 00a9c122  741e                   -je 0xa9c142
    if (cpu.flags.zf)
    {
        goto L_0x00a9c142;
    }
    // 00a9c124  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c126  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c127  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a9c12b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c12c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c12e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a9c132  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c133  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a9c137  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c138  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c139  2eff1590cda900         -call dword ptr cs:[0xa9cd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128208) /* 0xa9cd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c140  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a9c142:
    // 00a9c142  83fbff                 +cmp ebx, -1
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
    // 00a9c145  750c                   -jne 0xa9c153
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c153;
    }
    // 00a9c147  e838cfffff             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a9c14c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a9c14f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c150  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c151  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c152  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c153:
    // 00a9c153  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9c155  ff15a0e2a900           -call dword ptr [0xa9e2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133600) /* 0xa9e2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c15b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c15d  8b3d70e5a900           -mov edi, dword ptr [0xa9e570]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11134320) /* 0xa9e570 */);
    // 00a9c163  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c165  39f8                   +cmp eax, edi
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
    // 00a9c167  721e                   -jb 0xa9c187
    if (cpu.flags.cf)
    {
        goto L_0x00a9c187;
    }
    // 00a9c169  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c16a  2eff1588cda900         -call dword ptr cs:[0xa9cd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128200) /* 0xa9cd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c171  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9c176  e845b2ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c17b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c180  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a9c183  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c186  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c187:
    // 00a9c187  e804eeffff             -call 0xa9af90
    cpu.esp -= 4;
    sub_a9af90(app, cpu);
    if (cpu.terminate) return;
    // 00a9c18c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c18e  7405                   -je 0xa9c195
    if (cpu.flags.zf)
    {
        goto L_0x00a9c195;
    }
    // 00a9c190  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00a9c195:
    // 00a9c195  83fe02                 +cmp esi, 2
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
    // 00a9c198  7505                   -jne 0xa9c19f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c19f;
    }
    // 00a9c19a  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9c19d  eb11                   -jmp 0xa9c1b0
    goto L_0x00a9c1b0;
L_0x00a9c19f:
    // 00a9c19f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c1a1  7505                   -jne 0xa9c1a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c1a8;
    }
    // 00a9c1a3  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a9c1a6  eb08                   -jmp 0xa9c1b0
    goto L_0x00a9c1b0;
L_0x00a9c1a8:
    // 00a9c1a8  83fe01                 +cmp esi, 1
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
    // 00a9c1ab  7503                   -jne 0xa9c1b0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c1b0;
    }
    // 00a9c1ad  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a9c1b0:
    // 00a9c1b0  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 00a9c1b5  7403                   -je 0xa9c1ba
    if (cpu.flags.zf)
    {
        goto L_0x00a9c1ba;
    }
    // 00a9c1b7  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a9c1ba:
    // 00a9c1ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c1bc  8a5c241d               -mov bl, byte ptr [esp + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 00a9c1c0  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a9c1c2  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 00a9c1c5  7407                   -je 0xa9c1ce
    if (cpu.flags.zf)
    {
        goto L_0x00a9c1ce;
    }
    // 00a9c1c7  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a9c1ca  7410                   -je 0xa9c1dc
    if (cpu.flags.zf)
    {
        goto L_0x00a9c1dc;
    }
    // 00a9c1cc  eb0c                   -jmp 0xa9c1da
    goto L_0x00a9c1da;
L_0x00a9c1ce:
    // 00a9c1ce  813d6ce1a90000020000   +cmp dword ptr [0xa9e16c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133292) /* 0xa9e16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c1d8  7502                   -jne 0xa9c1dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c1dc;
    }
L_0x00a9c1da:
    // 00a9c1da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a9c1dc:
    // 00a9c1dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c1de  e805ceffff             -call 0xa98fe8
    cpu.esp -= 4;
    sub_a98fe8(app, cpu);
    if (cpu.terminate) return;
    // 00a9c1e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a9c1e5:
    // 00a9c1e5  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a9c1e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c1e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c1ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c1eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9c1f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c1f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c1f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c1f4  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c1f7  7f2c                   -jg 0xa9c225
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a9c225;
    }
    // 00a9c1f9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a9c1fc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9c1fe  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9c201  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9c203  39d8                   +cmp eax, ebx
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
    // 00a9c205  7c1e                   -jl 0xa9c225
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9c225;
    }
    // 00a9c207  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a9c20a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9c20c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a9c20f  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a9c212  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c214  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a9c217  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c219  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a9c21b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c21d  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a9c220  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c221  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c222  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c223  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c224  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c225:
    // 00a9c225  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9c22a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c22b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c22c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c22d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c22e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9c230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c231  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a9c235  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9c238  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a9c23b  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a9c242  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9c244  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9c248(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c248  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c249  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c24a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c24b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c24d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9c24f  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a9c252  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c258  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a9c25b  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 00a9c25e  0f8475000000           -je 0xa9c2d9
    if (cpu.flags.zf)
    {
        goto L_0x00a9c2d9;
    }
    // 00a9c264  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a9c268  742f                   -je 0xa9c299
    if (cpu.flags.zf)
    {
        goto L_0x00a9c299;
    }
    // 00a9c26a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c26c  e8af8fffff             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
    // 00a9c271  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c273  743b                   -je 0xa9c2b0
    if (cpu.flags.zf)
    {
        goto L_0x00a9c2b0;
    }
    // 00a9c275  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9c277  750e                   -jne 0xa9c287
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c287;
    }
    // 00a9c279  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c27b  7d0a                   -jge 0xa9c287
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9c287;
    }
L_0x00a9c27d:
    // 00a9c27d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9c282  e839b1ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c287:
    // 00a9c287  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c28a  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c290  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c295  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c297  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c298  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c299:
    // 00a9c299  83fb01                 +cmp ebx, 1
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
    // 00a9c29c  7503                   -jne 0xa9c2a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c2a1;
    }
    // 00a9c29e  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x00a9c2a1:
    // 00a9c2a1  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9c2a4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9c2a7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a9c2ae  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00a9c2b0:
    // 00a9c2b0  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 00a9c2b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9c2b6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c2b9  e862b1ffff             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
    // 00a9c2be  83f8ff                 +cmp eax, -1
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
    // 00a9c2c1  0f85e4000000           -jne 0xa9c3ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c3ab;
    }
    // 00a9c2c7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c2ca  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c2d0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c2d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c2d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c2d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c2d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c2d9:
    // 00a9c2d9  83fb01                 +cmp ebx, 1
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
    // 00a9c2dc  720d                   -jb 0xa9c2eb
    if (cpu.flags.cf)
    {
        goto L_0x00a9c2eb;
    }
    // 00a9c2de  7611                   -jbe 0xa9c2f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c2f1;
    }
    // 00a9c2e0  83fb02                 +cmp ebx, 2
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
    // 00a9c2e3  0f848a000000           -je 0xa9c373
    if (cpu.flags.zf)
    {
        goto L_0x00a9c373;
    }
    // 00a9c2e9  eb92                   -jmp 0xa9c27d
    goto L_0x00a9c27d;
L_0x00a9c2eb:
    // 00a9c2eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9c2ed  7445                   -je 0xa9c334
    if (cpu.flags.zf)
    {
        goto L_0x00a9c334;
    }
    // 00a9c2ef  eb8c                   -jmp 0xa9c27d
    goto L_0x00a9c27d;
L_0x00a9c2f1:
    // 00a9c2f1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9c2f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9c2f5  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9c2f8  e8f3feffff             -call 0xa9c1f0
    cpu.esp -= 4;
    sub_a9c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c2fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c2ff  0f84a6000000           -je 0xa9c3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a9c3ab;
    }
    // 00a9c305  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9c307  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c30a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9c30c  e80fb1ffff             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
    // 00a9c311  83f8ff                 +cmp eax, -1
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
    // 00a9c314  7512                   -jne 0xa9c328
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c328;
    }
    // 00a9c316  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c319  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c31f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c324  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c325  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c328:
    // 00a9c328  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c32a  e801ffffff             -call 0xa9c230
    cpu.esp -= 4;
    sub_a9c230(app, cpu);
    if (cpu.terminate) return;
    // 00a9c32f  e977000000             -jmp 0xa9c3ab
    goto L_0x00a9c3ab;
L_0x00a9c334:
    // 00a9c334  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c337  e814f2ffff             -call 0xa9b550
    cpu.esp -= 4;
    sub_a9b550(app, cpu);
    if (cpu.terminate) return;
    // 00a9c33c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9c33f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a9c341  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c343  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c345  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9c347  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9c349  e8a2feffff             -call 0xa9c1f0
    cpu.esp -= 4;
    sub_a9c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c34e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c350  7459                   -je 0xa9c3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a9c3ab;
    }
    // 00a9c352  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9c354  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c357  e8c4b0ffff             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
    // 00a9c35c  83f8ff                 +cmp eax, -1
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
    // 00a9c35f  75c7                   -jne 0xa9c328
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c328;
    }
    // 00a9c361  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c364  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c36a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c36f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c370  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c371  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c372  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c373:
    // 00a9c373  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a9c375  80e2ef                 -and dl, 0xef
    cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a9c378  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9c37b  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00a9c37e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9c381  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a9c383  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9c385  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c388  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a9c38f  e88cb0ffff             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
    // 00a9c394  83f8ff                 +cmp eax, -1
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
    // 00a9c397  7512                   -jne 0xa9c3ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c3ab;
    }
    // 00a9c399  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c39c  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c3a2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9c3a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c3ab:
    // 00a9c3ab  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9c3ae  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c3b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c3b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c3c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a9c3c3:
    // 00a9c3c3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a9c3c5  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9c3c7  3c41                   +cmp al, 0x41
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c3c9  7206                   -jb 0xa9c3d1
    if (cpu.flags.cf)
    {
        goto L_0x00a9c3d1;
    }
    // 00a9c3cb  3c5a                   +cmp al, 0x5a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c3cd  7702                   -ja 0xa9c3d1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9c3d1;
    }
    // 00a9c3cf  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a9c3d1:
    // 00a9c3d1  80fc41                 +cmp ah, 0x41
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c3d4  7208                   -jb 0xa9c3de
    if (cpu.flags.cf)
    {
        goto L_0x00a9c3de;
    }
    // 00a9c3d6  80fc5a                 +cmp ah, 0x5a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c3d9  7703                   -ja 0xa9c3de
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9c3de;
    }
    // 00a9c3db  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a9c3de:
    // 00a9c3de  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c3e0  7508                   -jne 0xa9c3ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c3ea;
    }
    // 00a9c3e2  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a9c3e4  7404                   -je 0xa9c3ea
    if (cpu.flags.zf)
    {
        goto L_0x00a9c3ea;
    }
    // 00a9c3e6  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9c3e7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a9c3e8  ebd9                   -jmp 0xa9c3c3
    goto L_0x00a9c3c3;
L_0x00a9c3ea:
    // 00a9c3ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c3ec  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a9c3ee  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a9c3f0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9c3f5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c3f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c3f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c3fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c400(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c401  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c403  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9c404  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a9c406  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a9c408  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c409  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9c40b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9c40e  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a9c411  8b151010aa00           -mov edx, dword ptr [0xaa1010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145232) /* 0xaa1010 */);
    // 00a9c417  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9c419  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a9c41c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a9c41f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9c421  7531                   -jne 0xa9c454
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c454;
    }
    // 00a9c423  a1dce5a900             -mov eax, dword ptr [0xa9e5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a9c428  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a9c42b  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a9c42d  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c42f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a9c431  8b1ddce5a900           -mov ebx, dword ptr [0xa9e5dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a9c437  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c439  e83287ffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c43e  a1dce5a900             -mov eax, dword ptr [0xa9e5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a9c443  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a9c449  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c44b  e888b6ffff             -call 0xa97ad8
    cpu.esp -= 4;
    sub_a97ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a9c450  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c452  7431                   -je 0xa9c485
    if (cpu.flags.zf)
    {
        goto L_0x00a9c485;
    }
L_0x00a9c454:
    // 00a9c454  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c45a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a9c45d  05de000000             -add eax, 0xde
    (cpu.eax) += x86::reg32(x86::sreg32(222 /*0xde*/));
    // 00a9c462  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c463  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a9c466  2eff152ccea900         -call dword ptr cs:[0xa9ce2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128364) /* 0xa9ce2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c46d  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a9c470  e8abbeffff             -call 0xa98320
    cpu.esp -= 4;
    sub_a98320(app, cpu);
    if (cpu.terminate) return;
    // 00a9c475  ff15d4e2a900           -call dword ptr [0xa9e2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133652) /* 0xa9e2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c47b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9c47d  ff55fc                 -call dword ptr [ebp - 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c480  e867f3ffff             -call 0xa9b7ec
    cpu.esp -= 4;
    sub_a9b7ec(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c485:
    // 00a9c485  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a9c487  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c488  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9c48a  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9c48c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9c48d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c48e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c48f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9c494(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c494  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c495  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c496  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c497  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9c498  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c499  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a9c49c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c49e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a9c4a0  833d90e2a900ff         +cmp dword ptr [0xa9e290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c4a7  7512                   -jne 0xa9c4bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c4bb;
    }
    // 00a9c4a9  e8cab5ffff             -call 0xa97a78
    cpu.esp -= 4;
    sub_a97a78(app, cpu);
    if (cpu.terminate) return;
    // 00a9c4ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c4b0  0f84be000000           -je 0xa9c574
    if (cpu.flags.zf)
    {
        goto L_0x00a9c574;
    }
    // 00a9c4b6  e8f9b6ffff             -call 0xa97bb4
    cpu.esp -= 4;
    sub_a97bb4(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c4bb:
    // 00a9c4bb  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a9c4bd  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a9c4c1  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a9c4c5  2eff15d0cda900         -call dword ptr cs:[0xa9cdd0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128272) /* 0xa9cdd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c4cc  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a9c4d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9c4d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9c4d4  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9c4d6  be1cf4a900             -mov esi, 0xa9f41c
    cpu.esi = 11138076 /*0xa9f41c*/;
    // 00a9c4db  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00a9c4df  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a9c4e4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9c4e5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9c4e6  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9c4e7  2eff15cccda900         -call dword ptr cs:[0xa9cdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128268) /* 0xa9cdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c4ee  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9c4f2  e825bfffff             -call 0xa9841c
    cpu.esp -= 4;
    sub_a9841c(app, cpu);
    if (cpu.terminate) return;
    // 00a9c4f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9c4f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c4fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c4fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c4fe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c500  2eff158ccda900         -call dword ptr cs:[0xa9cd8c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128204) /* 0xa9cd8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c507  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a9c50b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a9c50f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c510  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c512  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a9c516  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c517  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a9c51d  6800c4a900             -push 0xa9c400
    app->getMemory<x86::reg32>(cpu.esp-4) = 11125760 /*0xa9c400*/;
    cpu.esp -= 4;
    // 00a9c522  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00a9c528  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c529  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c52b  2eff1594cda900         -call dword ptr cs:[0xa9cd94]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128212) /* 0xa9cd94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c532  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9c534  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9c536  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c538  750a                   -jne 0xa9c544
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c544;
    }
    // 00a9c53a  c7442434ffffffff       -mov dword ptr [esp + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00a9c542  eb22                   -jmp 0xa9c566
    goto L_0x00a9c566;
L_0x00a9c544:
    // 00a9c544  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a9c546  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a9c54a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c54b  2eff1564cea900         -call dword ptr cs:[0xa9ce64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128420) /* 0xa9ce64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c552  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a9c556  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c558  7404                   -je 0xa9c55e
    if (cpu.flags.zf)
    {
        goto L_0x00a9c55e;
    }
    // 00a9c55a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a9c55c  eb08                   -jmp 0xa9c566
    goto L_0x00a9c566;
L_0x00a9c55e:
    // 00a9c55e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c55f  2eff1588cda900         -call dword ptr cs:[0xa9cd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128200) /* 0xa9cd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a9c566:
    // 00a9c566  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a9c56a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c56b  2eff1588cda900         -call dword ptr cs:[0xa9cd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128200) /* 0xa9cd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c572  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a9c574:
    // 00a9c574  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a9c577  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c578  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9c579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c57a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c57b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c57c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9c580(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c581  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c582  ff15d8e2a900           -call dword ptr [0xa9e2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133656) /* 0xa9e2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c588  e8dfbdffff             -call 0xa9836c
    cpu.esp -= 4;
    sub_a9836c(app, cpu);
    if (cpu.terminate) return;
    // 00a9c58d  833d1010aa0000         +cmp dword ptr [0xaa1010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145232) /* 0xaa1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c594  750a                   -jne 0xa9c5a0
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c5a0;
    }
    // 00a9c596  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9c59b  e88cb5ffff             -call 0xa97b2c
    cpu.esp -= 4;
    sub_a97b2c(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c5a0:
    // 00a9c5a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9c5a2  2eff15a8cda900         -call dword ptr cs:[0xa9cda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128232) /* 0xa9cda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c5a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9c5b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c5b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c5b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c5b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c5b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a9c5b6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c5b9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9c5bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9c5bd  7507                   -jne 0xa9c5c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c5c6;
    }
    // 00a9c5bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9c5c1  e983000000             -jmp 0xa9c649
    goto L_0x00a9c649;
L_0x00a9c5c6:
    // 00a9c5c6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9c5c8  0f8676000000           -jbe 0xa9c644
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c644;
    }
    // 00a9c5ce  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c5d1  7512                   -jne 0xa9c5e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c5e5;
    }
    // 00a9c5d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c5d5  7405                   -je 0xa9c5dc
    if (cpu.flags.zf)
    {
        goto L_0x00a9c5dc;
    }
    // 00a9c5d7  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
L_0x00a9c5dc:
    // 00a9c5dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c5de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a9c5e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c5e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c5e5:
    // 00a9c5e5  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c5ec  7419                   -je 0xa9c607
    if (cpu.flags.zf)
    {
        goto L_0x00a9c607;
    }
    // 00a9c5ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c5f0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9c5f2  8a80011eaa00           -mov al, byte ptr [eax + 0xaa1e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a9c5f8  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9c5fa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a9c5ff  7406                   -je 0xa9c607
    if (cpu.flags.zf)
    {
        goto L_0x00a9c607;
    }
    // 00a9c601  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9c605  743d                   -je 0xa9c644
    if (cpu.flags.zf)
    {
        goto L_0x00a9c644;
    }
L_0x00a9c607:
    // 00a9c607  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c609  e842c5ffff             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a9c60e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a9c610  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a9c613  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9c615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c616  39c3                   +cmp ebx, eax
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
    // 00a9c618  7302                   -jae 0xa9c61c
    if (!cpu.flags.cf)
    {
        goto L_0x00a9c61c;
    }
    // 00a9c61a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9c61c:
    // 00a9c61c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c61d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c61e  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a9c620  a154e6a900             -mov eax, dword ptr [0xa9e654]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */);
    // 00a9c625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c626  2eff1518cea900         -call dword ptr cs:[0xa9ce18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128344) /* 0xa9ce18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c62d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c62f  7413                   -je 0xa9c644
    if (cpu.flags.zf)
    {
        goto L_0x00a9c644;
    }
    // 00a9c631  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c633  7406                   -je 0xa9c63b
    if (cpu.flags.zf)
    {
        goto L_0x00a9c63b;
    }
    // 00a9c635  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a9c638  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00a9c63b:
    // 00a9c63b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9c63d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a9c63f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c640  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c642  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c644:
    // 00a9c644  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a9c649:
    // 00a9c649  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a9c64b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c64c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c64d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c64e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c64f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9c650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c653  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a9c656  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9c658  6639ca                 +cmp dx, cx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c65b  7416                   -je 0xa9c673
    if (cpu.flags.zf)
    {
        goto L_0x00a9c673;
    }
L_0x00a9c65d:
    // 00a9c65d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c65f  668b3a                 -mov di, word ptr [edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx);
    // 00a9c662  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9c665  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 00a9c668  7407                   -je 0xa9c671
    if (cpu.flags.zf)
    {
        goto L_0x00a9c671;
    }
    // 00a9c66a  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c66d  7404                   -je 0xa9c673
    if (cpu.flags.zf)
    {
        goto L_0x00a9c673;
    }
    // 00a9c66f  ebec                   -jmp 0xa9c65d
    goto L_0x00a9c65d;
L_0x00a9c671:
    // 00a9c671  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9c673:
    // 00a9c673  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c674  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c675  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c676  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c680(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c682  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c683  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c685  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c688  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9c68b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a9c68d  66813d71e3a9000080     +cmp word ptr [0xa9e371], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(11133809) /* 0xa9e371 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c696  730e                   -jae 0xa9c6a6
    if (!cpu.flags.cf)
    {
        goto L_0x00a9c6a6;
    }
    // 00a9c698  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c699  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9c69a  2eff1528cea900         -call dword ptr cs:[0xa9ce28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128360) /* 0xa9ce28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c6a1  e9c3000000             -jmp 0xa9c769
    goto L_0x00a9c769;
L_0x00a9c6a6:
    // 00a9c6a6  e825cdffff             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c6ab  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c6ad  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9c6b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c6b2  e8c985ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9c6b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c6b9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9c6bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c6bd  0f84a6000000           -je 0xa9c769
    if (cpu.flags.zf)
    {
        goto L_0x00a9c769;
    }
    // 00a9c6c3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9c6c5  7504                   -jne 0xa9c6cb
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c6cb;
    }
    // 00a9c6c7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a9c6c9  eb2b                   -jmp 0xa9c6f6
    goto L_0x00a9c6f6;
L_0x00a9c6cb:
    // 00a9c6cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9c6cd  e8feccffff             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c6d2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c6d4  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9c6d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c6d9  e8a285ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9c6de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9c6e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c6e2  7512                   -jne 0xa9c6f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c6f6;
    }
    // 00a9c6e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c6e6  e88586ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c6eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c6ed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c6f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c6f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c6f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c6f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c6f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c6f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c6f6:
    // 00a9c6f6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9c6f9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a9c6fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9c6fd  e8de000000             -call 0xa9c7e0
    cpu.esp -= 4;
    sub_a9c7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c702  83f8ff                 +cmp eax, -1
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
    // 00a9c705  751d                   -jne 0xa9c724
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c724;
    }
    // 00a9c707  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9c709  e86286ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c70e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c710  7407                   -je 0xa9c719
    if (cpu.flags.zf)
    {
        goto L_0x00a9c719;
    }
    // 00a9c712  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9c714  e85786ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c719:
    // 00a9c719  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c71b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c71e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c71f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c720  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c723  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c724:
    // 00a9c724  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c726  7422                   -je 0xa9c74a
    if (cpu.flags.zf)
    {
        goto L_0x00a9c74a;
    }
    // 00a9c728  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a9c72a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a9c72c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9c72e  e8ad000000             -call 0xa9c7e0
    cpu.esp -= 4;
    sub_a9c7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c733  83f8ff                 +cmp eax, -1
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
    // 00a9c736  7512                   -jne 0xa9c74a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c74a;
    }
    // 00a9c738  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9c73a  e83186ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c73f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c741  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c744  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c745  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c746  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c747  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c748  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c749  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c74a:
    // 00a9c74a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c74b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c74c  2eff1524cea900         -call dword ptr cs:[0xa9ce24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128356) /* 0xa9ce24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9c753  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c755  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9c757  e81486ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c75c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c75e  7407                   -je 0xa9c767
    if (cpu.flags.zf)
    {
        goto L_0x00a9c767;
    }
    // 00a9c760  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9c762  e80986ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a9c767:
    // 00a9c767  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a9c769:
    // 00a9c769  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c76c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c76d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c76e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c76f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c770  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c771  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c784  8b350410aa00           -mov esi, dword ptr [0xaa1004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a9c78a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9c78c  7441                   -je 0xa9c7cf
    if (cpu.flags.zf)
    {
        goto L_0x00a9c7cf;
    }
L_0x00a9c78e:
    // 00a9c78e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9c790  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9c793  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9c795  7438                   -je 0xa9c7cf
    if (cpu.flags.zf)
    {
        goto L_0x00a9c7cf;
    }
    // 00a9c797  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c799  e872f2ffff             -call 0xa9ba10
    cpu.esp -= 4;
    sub_a9ba10(app, cpu);
    if (cpu.terminate) return;
    // 00a9c79e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9c7a1  8d045d00000000         -lea eax, [ebx*2]
    cpu.eax = x86::reg32(cpu.ebx * 2);
    // 00a9c7a8  e8d384ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9c7ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c7af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c7b1  74db                   -je 0xa9c78e
    if (cpu.flags.zf)
    {
        goto L_0x00a9c78e;
    }
    // 00a9c7b3  e888f2ffff             -call 0xa9ba40
    cpu.esp -= 4;
    sub_a9ba40(app, cpu);
    if (cpu.terminate) return;
    // 00a9c7b8  83f8ff                 +cmp eax, -1
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
    // 00a9c7bb  7409                   -je 0xa9c7c6
    if (cpu.flags.zf)
    {
        goto L_0x00a9c7c6;
    }
    // 00a9c7bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c7bf  e894f4ffff             -call 0xa9bc58
    cpu.esp -= 4;
    sub_a9bc58(app, cpu);
    if (cpu.terminate) return;
    // 00a9c7c4  ebc8                   -jmp 0xa9c78e
    goto L_0x00a9c78e;
L_0x00a9c7c6:
    // 00a9c7c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c7c8  e8a385ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9c7cd  ebbf                   -jmp 0xa9c78e
    goto L_0x00a9c78e;
L_0x00a9c7cf:
    // 00a9c7cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c7d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c7d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c7d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c7d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c7e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9c7e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9c7e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c7e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9c7e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9c7e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9c7eb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a9c7ed  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a9c7f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9c7f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c7f4  0f8471000000           -je 0xa9c86b
    if (cpu.flags.zf)
    {
        goto L_0x00a9c86b;
    }
L_0x00a9c7fa:
    // 00a9c7fa  833c2400               +cmp dword ptr [esp], 0
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
    // 00a9c7fe  0f8689000000           -jbe 0xa9c88d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c88d;
    }
    // 00a9c804  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a9c808  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a9c80b  7420                   -je 0xa9c82d
    if (cpu.flags.zf)
    {
        goto L_0x00a9c82d;
    }
    // 00a9c80d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c80f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9c813  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00a9c816  e875bbffff             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a9c81b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c81d  83f8ff                 +cmp eax, -1
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
    // 00a9c820  0f8469000000           -je 0xa9c88f
    if (cpu.flags.zf)
    {
        goto L_0x00a9c88f;
    }
    // 00a9c826  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00a9c829  7762                   -ja 0xa9c88d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9c88d;
    }
    // 00a9c82b  eb09                   -jmp 0xa9c836
    goto L_0x00a9c836;
L_0x00a9c82d:
    // 00a9c82d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9c831  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a9c834  eb57                   -jmp 0xa9c88d
    goto L_0x00a9c88d;
L_0x00a9c836:
    // 00a9c836  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9c83a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a9c83e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9c840  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9c841  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a9c843  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9c845  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9c846  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9c848  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9c84b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a9c84d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9c84f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9c852  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a9c854  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c855  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9c856  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9c859  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c85b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9c85e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c860  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9c862  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a9c866  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9c869  eb8f                   -jmp 0xa9c7fa
    goto L_0x00a9c7fa;
L_0x00a9c86b:
    // 00a9c86b  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c870  741b                   -je 0xa9c88d
    if (cpu.flags.zf)
    {
        goto L_0x00a9c88d;
    }
    // 00a9c872  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c874  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a9c878  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a9c87c  e80fbbffff             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a9c881  83f8ff                 +cmp eax, -1
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
    // 00a9c884  7409                   -je 0xa9c88f
    if (cpu.flags.zf)
    {
        goto L_0x00a9c88f;
    }
    // 00a9c886  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9c889  01c3                   +add ebx, eax
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
    // 00a9c88b  ebde                   -jmp 0xa9c86b
    goto L_0x00a9c86b;
L_0x00a9c88d:
    // 00a9c88d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a9c88f:
    // 00a9c88f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a9c892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c893  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c894  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c8a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c8a0  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c8a4  7209                   -jb 0xa9c8af
    if (cpu.flags.cf)
    {
        goto L_0x00a9c8af;
    }
    // 00a9c8a6  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9c8aa  7703                   -ja 0xa9c8af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9c8af;
    }
    // 00a9c8ac  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a9c8af:
    // 00a9c8af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9c8b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c8b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c8b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c8b3  e808010000             -call 0xa9c9c0
    cpu.esp -= 4;
    sub_a9c9c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9c8b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c8ba  741f                   -je 0xa9c8db
    if (cpu.flags.zf)
    {
        goto L_0x00a9c8db;
    }
    // 00a9c8bc  81fa81820000           +cmp edx, 0x8281
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
    // 00a9c8c2  7211                   -jb 0xa9c8d5
    if (cpu.flags.cf)
    {
        goto L_0x00a9c8d5;
    }
    // 00a9c8c4  81fa9a820000           +cmp edx, 0x829a
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
    // 00a9c8ca  7709                   -ja 0xa9c8d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9c8d5;
    }
    // 00a9c8cc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a9c8d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c8d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c8d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c8d5:
    // 00a9c8d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c8d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c8d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c8da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c8db:
    // 00a9c8db  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a9c8dd  fec0                   -inc al
    (cpu.al)++;
    // 00a9c8df  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9c8e4  8a808ce1a900           -mov al, byte ptr [eax + 0xa9e18c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11133324) /* 0xa9e18c */);
    // 00a9c8ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9c8ec  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a9c8ee  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a9c8f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9c8f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c8f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a9c900(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c900  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a9c902  740e                   -je 0xa9c912
    if (cpu.flags.zf)
    {
        goto L_0x00a9c912;
    }
    // 00a9c904  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a9c90a  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a9c910  eb0c                   -jmp 0xa9c91e
    goto L_0x00a9c91e;
L_0x00a9c912:
    // 00a9c912  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a9c918  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x00a9c91e:
    // 00a9c91e  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a9c920  7403                   -je 0xa9c925
    if (cpu.flags.zf)
    {
        goto L_0x00a9c925;
    }
    // 00a9c922  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a9c925:
    // 00a9c925  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a9c927  7403                   -je 0xa9c92c
    if (cpu.flags.zf)
    {
        goto L_0x00a9c92c;
    }
    // 00a9c929  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00a9c92c:
    // 00a9c92c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9c930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c930  83f802                 +cmp eax, 2
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
    // 00a9c933  750d                   -jne 0xa9c942
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c942;
    }
    // 00a9c935  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a9c93b  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a9c941  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c942:
    // 00a9c942  83f801                 +cmp eax, 1
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
    // 00a9c945  750d                   -jne 0xa9c954
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c954;
    }
    // 00a9c947  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 00a9c94d  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a9c953  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c954:
    // 00a9c954  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a9c95a  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a9c960  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9c964(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9c965  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9c967  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a9c96a  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a9c96d  83f820                 +cmp eax, 0x20
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
    // 00a9c970  7210                   -jb 0xa9c982
    if (cpu.flags.cf)
    {
        goto L_0x00a9c982;
    }
    // 00a9c972  7638                   -jbe 0xa9c9ac
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c9ac;
    }
    // 00a9c974  83f830                 +cmp eax, 0x30
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
    // 00a9c977  7241                   -jb 0xa9c9ba
    if (cpu.flags.cf)
    {
        goto L_0x00a9c9ba;
    }
    // 00a9c979  7629                   -jbe 0xa9c9a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c9a4;
    }
    // 00a9c97b  83f840                 +cmp eax, 0x40
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
    // 00a9c97e  7434                   -je 0xa9c9b4
    if (cpu.flags.zf)
    {
        goto L_0x00a9c9b4;
    }
    // 00a9c980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c981  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c982:
    // 00a9c982  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c984  7607                   -jbe 0xa9c98d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9c98d;
    }
    // 00a9c986  83f810                 +cmp eax, 0x10
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
    // 00a9c989  7411                   -je 0xa9c99c
    if (cpu.flags.zf)
    {
        goto L_0x00a9c99c;
    }
    // 00a9c98b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c98c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c98d:
    // 00a9c98d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a9c993  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9c995  7523                   -jne 0xa9c9ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a9c9ba;
    }
    // 00a9c997  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a9c99a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c99b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c99c:
    // 00a9c99c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00a9c9a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c9a4:
    // 00a9c9a4  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 00a9c9aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c9ac:
    // 00a9c9ac  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a9c9b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c9b4:
    // 00a9c9b4  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x00a9c9ba:
    // 00a9c9ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a9c9c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9c9c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9c9c1  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9c9c8  7431                   -je 0xa9c9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a9c9fb;
    }
    // 00a9c9ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9c9cc  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a9c9cf  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9c9d5  8a92011eaa00           -mov dl, byte ptr [edx + 0xaa1e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a9c9db  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9c9de  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a9c9e4  7415                   -je 0xa9c9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a9c9fb;
    }
    // 00a9c9e6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9c9eb  e810000000             -call 0xa9ca00
    cpu.esp -= 4;
    sub_a9ca00(app, cpu);
    if (cpu.terminate) return;
    // 00a9c9f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9c9f2  7407                   -je 0xa9c9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a9c9fb;
    }
    // 00a9c9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9c9f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9c9fb:
    // 00a9c9fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9c9fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9c9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a9ca00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9ca00  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9ca07  7429                   -je 0xa9ca32
    if (cpu.flags.zf)
    {
        goto L_0x00a9ca32;
    }
    // 00a9ca09  813d54e6a900a4030000   +cmp dword ptr [0xa9e654], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9ca13  740a                   -je 0xa9ca1f
    if (cpu.flags.zf)
    {
        goto L_0x00a9ca1f;
    }
    // 00a9ca15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9ca17  741b                   -je 0xa9ca34
    if (cpu.flags.zf)
    {
        goto L_0x00a9ca34;
    }
    // 00a9ca19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9ca1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ca1f:
    // 00a9ca1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9ca24  8a8089e7a900           -mov al, byte ptr [eax + 0xa9e789]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11134857) /* 0xa9e789 */);
    // 00a9ca2a  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a9ca2c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a9ca31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9ca32:
    // 00a9ca32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9ca34:
    // 00a9ca34  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
