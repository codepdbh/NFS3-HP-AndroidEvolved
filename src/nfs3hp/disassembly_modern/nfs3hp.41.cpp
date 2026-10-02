#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f2360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2362  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2364  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004f236a  891d0c445600           -mov dword ptr [0x56440c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ebx;
    // 004f2370  e86bffffff             -call 0x4f22e0
    cpu.esp -= 4;
    sub_4f22e0(app, cpu);
    if (cpu.terminate) return;
    // 004f2375  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004f237b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f237c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f237d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2383  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2384  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2385  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2387  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004f238a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 004f2390  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004f2393  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2395  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f2398  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f239a  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f239c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f239e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f23a5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23a7  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f23ae  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f23b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f23b6  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004f23bc  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f23bf  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f23c1  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f23c3  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f23c5  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23c7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f23cc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23ce  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f23d5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23d7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23d9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004f23dc  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004f23df  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004f23e2  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 004f23e5  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f23e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f23f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f23f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f23f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f23f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f23f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f23f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f23f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f23f7  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004f23fa  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 004f2400  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004f2403  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2405  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004f240b  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f240e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f2410  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2412  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f2414  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2416  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f241b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f241d  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f2424  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2426  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2428  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f242a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f242c  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f242f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f2431  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2433  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f2435  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2437  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f243c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f243e  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f2445  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2447  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2449  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f244b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004f244e  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004f2451  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004f2454  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 004f2457  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f2459  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f2460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2460  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2461  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2463  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2465  7504                   -jne 0x4f246b
    if (!cpu.flags.zf)
    {
        goto L_0x004f246b;
    }
L_0x004f2467:
    // 004f2467  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2469  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f246a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f246b:
    // 004f246b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f246d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004f2470  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004f2476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2478  741d                   -je 0x4f2497
    if (cpu.flags.zf)
    {
        goto L_0x004f2497;
    }
L_0x004f247a:
    // 004f247a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f247c  74e9                   -je 0x4f2467
    if (cpu.flags.zf)
    {
        goto L_0x004f2467;
    }
    // 004f247e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2480  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2485  83f87c                 +cmp eax, 0x7c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2488  744b                   -je 0x4f24d5
    if (cpu.flags.zf)
    {
        goto L_0x004f24d5;
    }
    // 004f248a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f248c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f248f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2491  7447                   -je 0x4f24da
    if (cpu.flags.zf)
    {
        goto L_0x004f24da;
    }
    // 004f2493  01c2                   +add edx, eax
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
    // 004f2495  ebe3                   -jmp 0x4f247a
    goto L_0x004f247a;
L_0x004f2497:
    // 004f2497  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2499  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f249a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f249c  b9d4ca5400             -mov ecx, 0x54cad4
    cpu.ecx = 5556948 /*0x54cad4*/;
    // 004f24a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f24a6  bbe4ca5400             -mov ebx, 0x54cae4
    cpu.ebx = 5556964 /*0x54cae4*/;
    // 004f24ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f24ac  be31000000             -mov esi, 0x31
    cpu.esi = 49 /*0x31*/;
    // 004f24b1  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f24b7  68f8ca5400             -push 0x54caf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556984 /*0x54caf8*/;
    cpu.esp -= 4;
    // 004f24bc  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f24c2  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f24c8  e843ebf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f24cd  83c408                 +add esp, 8
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
    // 004f24d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d3  eba5                   -jmp 0x4f247a
    goto L_0x004f247a;
L_0x004f24d5:
    // 004f24d5  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f24d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f24da:
    // 004f24da  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f24dc  eb9c                   -jmp 0x4f247a
    goto L_0x004f247a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f24e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f24e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f24e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f24e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f24e5  7504                   -jne 0x4f24eb
    if (!cpu.flags.zf)
    {
        goto L_0x004f24eb;
    }
L_0x004f24e7:
    // 004f24e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f24e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f24eb:
    // 004f24eb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f24ed  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004f24f0  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004f24f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f24f8  741d                   -je 0x4f2517
    if (cpu.flags.zf)
    {
        goto L_0x004f2517;
    }
L_0x004f24fa:
    // 004f24fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f24fc  74e9                   -je 0x4f24e7
    if (cpu.flags.zf)
    {
        goto L_0x004f24e7;
    }
    // 004f24fe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2500  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2505  83f86f                 +cmp eax, 0x6f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2508  744b                   -je 0x4f2555
    if (cpu.flags.zf)
    {
        goto L_0x004f2555;
    }
    // 004f250a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f250c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f250f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2511  7447                   -je 0x4f255a
    if (cpu.flags.zf)
    {
        goto L_0x004f255a;
    }
    // 004f2513  01c2                   +add edx, eax
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
    // 004f2515  ebe3                   -jmp 0x4f24fa
    goto L_0x004f24fa;
L_0x004f2517:
    // 004f2517  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2518  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2519  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f251a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f251c  b9d4ca5400             -mov ecx, 0x54cad4
    cpu.ecx = 5556948 /*0x54cad4*/;
    // 004f2521  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2526  bb28cb5400             -mov ebx, 0x54cb28
    cpu.ebx = 5557032 /*0x54cb28*/;
    // 004f252b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f252c  be69000000             -mov esi, 0x69
    cpu.esi = 105 /*0x69*/;
    // 004f2531  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f2537  6838cb5400             -push 0x54cb38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557048 /*0x54cb38*/;
    cpu.esp -= 4;
    // 004f253c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f2542  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f2548  e8c3eaf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f254d  83c408                 +add esp, 8
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
    // 004f2550  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2551  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2552  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2553  eba5                   -jmp 0x4f24fa
    goto L_0x004f24fa;
L_0x004f2555:
    // 004f2555  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f2558  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2559  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f255a:
    // 004f255a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f255c  eb9c                   -jmp 0x4f24fa
    goto L_0x004f24fa;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2561  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2562  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2564  8a6001                 -mov ah, byte ptr [eax + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f2567  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2569  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f256c  7519                   -jne 0x4f2587
    if (!cpu.flags.zf)
    {
        goto L_0x004f2587;
    }
L_0x004f256e:
    // 004f256e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2570  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004f2572  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2574  731c                   -jae 0x4f2592
    if (!cpu.flags.cf)
    {
        goto L_0x004f2592;
    }
    // 004f2576  3c18                   +cmp al, 0x18
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
    // 004f2578  7362                   -jae 0x4f25dc
    if (!cpu.flags.cf)
    {
        goto L_0x004f25dc;
    }
    // 004f257a  3c10                   +cmp al, 0x10
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
    // 004f257c  0f8465000000           -je 0x4f25e7
    if (cpu.flags.zf)
    {
        goto L_0x004f25e7;
    }
L_0x004f2582:
    // 004f2582  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2584  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2586  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2587:
    // 004f2587  807e0132               +cmp byte ptr [esi + 1], 0x32
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f258b  74e1                   -je 0x4f256e
    if (cpu.flags.zf)
    {
        goto L_0x004f256e;
    }
    // 004f258d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f258f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2590  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2591  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2592:
    // 004f2592  7608                   -jbe 0x4f259c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f259c;
    }
    // 004f2594  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2596  7317                   -jae 0x4f25af
    if (!cpu.flags.cf)
    {
        goto L_0x004f25af;
    }
    // 004f2598  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f259a  75e6                   -jne 0x4f2582
    if (!cpu.flags.zf)
    {
        goto L_0x004f2582;
    }
L_0x004f259c:
    // 004f259c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25a3  e8a8c70100             -call 0x50ed50
    cpu.esp -= 4;
    sub_50ed50(app, cpu);
    if (cpu.terminate) return;
    // 004f25a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25af:
    // 004f25af  765c                   -jbe 0x4f260d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f260d;
    }
    // 004f25b1  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f25b3  75cd                   -jne 0x4f2582
    if (!cpu.flags.zf)
    {
        goto L_0x004f2582;
    }
    // 004f25b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f25b6  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004f25bb  8d4602                 -lea eax, [esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004f25be  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f25c0  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f25c2  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f25c4  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f25cb  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004f25cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25cf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25d1  e83adb0100             -call 0x510110
    cpu.esp -= 4;
    sub_510110(app, cpu);
    if (cpu.terminate) return;
    // 004f25d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25dc:
    // 004f25dc  761c                   -jbe 0x4f25fa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f25fa;
    }
    // 004f25de  3c30                   +cmp al, 0x30
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
    // 004f25e0  74ba                   -je 0x4f259c
    if (cpu.flags.zf)
    {
        goto L_0x004f259c;
    }
    // 004f25e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25e7:
    // 004f25e7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25ee  e8b1dc0100             -call 0x5102a4
    cpu.esp -= 4;
    sub_5102a4(app, cpu);
    if (cpu.terminate) return;
    // 004f25f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25fa:
    // 004f25fa  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2601  e85ae10100             -call 0x510760
    cpu.esp -= 4;
    sub_510760(app, cpu);
    if (cpu.terminate) return;
    // 004f2606  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2608  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f260a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f260b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f260c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f260d:
    // 004f260d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f260f  e85ce20100             -call 0x510870
    cpu.esp -= 4;
    sub_510870(app, cpu);
    if (cpu.terminate) return;
    // 004f2614  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2619  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f261a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2622  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2624  e837ffffff             -call 0x4f2560
    cpu.esp -= 4;
    sub_4f2560(app, cpu);
    if (cpu.terminate) return;
    // 004f2629  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f262b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f262d  751b                   -jne 0x4f264a
    if (!cpu.flags.zf)
    {
        goto L_0x004f264a;
    }
    // 004f262f  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004f2636  7412                   -je 0x4f264a
    if (cpu.flags.zf)
    {
        goto L_0x004f264a;
    }
    // 004f2638  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 004f263a  80fc10                 +cmp ah, 0x10
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
    // 004f263d  720b                   -jb 0x4f264a
    if (cpu.flags.cf)
    {
        goto L_0x004f264a;
    }
    // 004f263f  80fc80                 +cmp ah, 0x80
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(128 /*0x80*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2642  7306                   -jae 0x4f264a
    if (!cpu.flags.cf)
    {
        goto L_0x004f264a;
    }
    // 004f2644  807b01fb               +cmp byte ptr [ebx + 1], 0xfb
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2648  7405                   -je 0x4f264f
    if (cpu.flags.zf)
    {
        goto L_0x004f264f;
    }
L_0x004f264a:
    // 004f264a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f264c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f264d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f264e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f264f:
    // 004f264f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2652  be68cb5400             -mov esi, 0x54cb68
    cpu.esi = 5557096 /*0x54cb68*/;
    // 004f2657  bf78cb5400             -mov edi, 0x54cb78
    cpu.edi = 5557112 /*0x54cb78*/;
    // 004f265c  bd6d000000             -mov ebp, 0x6d
    cpu.ebp = 109 /*0x6d*/;
    // 004f2661  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f2666  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2668  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f266e  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f2674  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f267a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f267c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f267e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f2680  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f2687  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f2689  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f268a  6880cb5400             -push 0x54cb80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557120 /*0x54cb80*/;
    cpu.esp -= 4;
    // 004f268f  e87ce9f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f2694  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f2697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2698  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2699  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f269c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f26a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f26a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f26a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f26a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f26a4  8a6001                 -mov ah, byte ptr [eax + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f26a7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f26a9  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26ac  7515                   -jne 0x4f26c3
    if (!cpu.flags.zf)
    {
        goto L_0x004f26c3;
    }
L_0x004f26ae:
    // 004f26ae  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f26b0  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004f26b2  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26b4  7318                   -jae 0x4f26ce
    if (!cpu.flags.cf)
    {
        goto L_0x004f26ce;
    }
    // 004f26b6  3c18                   +cmp al, 0x18
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
    // 004f26b8  7349                   -jae 0x4f2703
    if (!cpu.flags.cf)
    {
        goto L_0x004f2703;
    }
    // 004f26ba  3c10                   +cmp al, 0x10
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
    // 004f26bc  741a                   -je 0x4f26d8
    if (cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
L_0x004f26be:
    // 004f26be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26c3:
    // 004f26c3  807a0132               +cmp byte ptr [edx + 1], 0x32
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26c7  74e5                   -je 0x4f26ae
    if (cpu.flags.zf)
    {
        goto L_0x004f26ae;
    }
    // 004f26c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26ce:
    // 004f26ce  7608                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26d0  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26d2  7322                   -jae 0x4f26f6
    if (!cpu.flags.cf)
    {
        goto L_0x004f26f6;
    }
    // 004f26d4  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26d6  75e6                   -jne 0x4f26be
    if (!cpu.flags.zf)
    {
        goto L_0x004f26be;
    }
L_0x004f26d8:
    // 004f26d8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004f26dd  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f26e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f26e2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f26e4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f26e6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f26ed  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004f26ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f26f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26f6:
    // 004f26f6  76e0                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26f8  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26fa  72c2                   -jb 0x4f26be
    if (cpu.flags.cf)
    {
        goto L_0x004f26be;
    }
    // 004f26fc  76da                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2700  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2702  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2703:
    // 004f2703  76d3                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f2705  3c30                   +cmp al, 0x30
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
    // 004f2707  74cf                   -je 0x4f26d8
    if (cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f2709  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f270b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f270c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f270d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f2710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2711  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2712  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2714  e887ffffff             -call 0x4f26a0
    cpu.esp -= 4;
    sub_4f26a0(app, cpu);
    if (cpu.terminate) return;
    // 004f2719  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f271b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f271d  7512                   -jne 0x4f2731
    if (!cpu.flags.zf)
    {
        goto L_0x004f2731;
    }
    // 004f271f  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004f2721  80fc10                 +cmp ah, 0x10
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
    // 004f2724  720b                   -jb 0x4f2731
    if (cpu.flags.cf)
    {
        goto L_0x004f2731;
    }
    // 004f2726  80fc80                 +cmp ah, 0x80
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(128 /*0x80*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2729  7306                   -jae 0x4f2731
    if (!cpu.flags.cf)
    {
        goto L_0x004f2731;
    }
    // 004f272b  807a01fb               +cmp byte ptr [edx + 1], 0xfb
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f272f  7405                   -je 0x4f2736
    if (cpu.flags.zf)
    {
        goto L_0x004f2736;
    }
L_0x004f2731:
    // 004f2731  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2733  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2735  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2736:
    // 004f2736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2737  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2738  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2739  b968cb5400             -mov ecx, 0x54cb68
    cpu.ecx = 5557096 /*0x54cb68*/;
    // 004f273e  bea4cb5400             -mov esi, 0x54cba4
    cpu.esi = 5557156 /*0x54cba4*/;
    // 004f2743  bfc9000000             -mov edi, 0xc9
    cpu.edi = 201 /*0xc9*/;
    // 004f2748  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f274a  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f2750  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f2756  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f275b  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f2761  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f2763  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f2765  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f2767  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f276e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f2770  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f2771  68b0cb5400             -push 0x54cbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557168 /*0x54cbb0*/;
    cpu.esp -= 4;
    // 004f2776  e895e8f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f277b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f277e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f277f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2780  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2781  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2784  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2785  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f2790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2792  ff1564465300           -call dword ptr [0x534664]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457508) /* 0x534664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2798  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2799  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f279a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f279c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f279c  90                     -nop 
    ;
    // 004f279d  90                     -nop 
    ;
    // 004f279e  90                     -nop 
    ;
    // 004f279f  90                     -nop 
    ;
    // 004f27a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f27a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f27a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f27a4  e857d3feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f27a9  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27af  a3ac525600             -mov dword ptr [0x5652ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.eax;
    // 004f27b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f27b6  7455                   -je 0x4f280d
    if (cpu.flags.zf)
    {
        goto L_0x004f280d;
    }
L_0x004f27b8:
    // 004f27b8  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f27bd  e8aed3feff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f27c2  8b1d340c9f00           -mov ebx, dword ptr [0x9f0c34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f27ca  7438                   -je 0x4f2804
    if (cpu.flags.zf)
    {
        goto L_0x004f2804;
    }
    // 004f27cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27cd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27d3  8b3d000c9f00           -mov edi, dword ptr [0x9f0c00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f27d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f27db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f27dd  7419                   -je 0x4f27f8
    if (cpu.flags.zf)
    {
        goto L_0x004f27f8;
    }
L_0x004f27df:
    // 004f27df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f27e1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f27e4  ff90000c9f00           -call dword ptr [eax + 0x9f0c00]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27ea  83fa20                 +cmp edx, 0x20
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
    // 004f27ed  7d09                   -jge 0x4f27f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f27f8;
    }
    // 004f27ef  83ba000c9f0000         +cmp dword ptr [edx + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f27f6  75e7                   -jne 0x4f27df
    if (!cpu.flags.zf)
    {
        goto L_0x004f27df;
    }
L_0x004f27f8:
    // 004f27f8  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f27fe  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f2804:
    // 004f2804  833d340c9f0000         +cmp dword ptr [0x9f0c34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f280b  75ab                   -jne 0x4f27b8
    if (!cpu.flags.zf)
    {
        goto L_0x004f27b8;
    }
L_0x004f280d:
    // 004f280d  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2812  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2814  e8e7d3feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f2819  8915ac525600           -mov dword ptr [0x5652ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.edx;
    // 004f281f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2821  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2822  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f27a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f27a0;
    // 004f279c  90                     -nop 
    ;
    // 004f279d  90                     -nop 
    ;
    // 004f279e  90                     -nop 
    ;
    // 004f279f  90                     -nop 
    ;
L_entry_0x004f27a0:
    // 004f27a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f27a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f27a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f27a4  e857d3feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f27a9  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27af  a3ac525600             -mov dword ptr [0x5652ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.eax;
    // 004f27b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f27b6  7455                   -je 0x4f280d
    if (cpu.flags.zf)
    {
        goto L_0x004f280d;
    }
L_0x004f27b8:
    // 004f27b8  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f27bd  e8aed3feff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f27c2  8b1d340c9f00           -mov ebx, dword ptr [0x9f0c34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f27ca  7438                   -je 0x4f2804
    if (cpu.flags.zf)
    {
        goto L_0x004f2804;
    }
    // 004f27cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27cd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27d3  8b3d000c9f00           -mov edi, dword ptr [0x9f0c00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f27d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f27db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f27dd  7419                   -je 0x4f27f8
    if (cpu.flags.zf)
    {
        goto L_0x004f27f8;
    }
L_0x004f27df:
    // 004f27df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f27e1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f27e4  ff90000c9f00           -call dword ptr [eax + 0x9f0c00]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27ea  83fa20                 +cmp edx, 0x20
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
    // 004f27ed  7d09                   -jge 0x4f27f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f27f8;
    }
    // 004f27ef  83ba000c9f0000         +cmp dword ptr [edx + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f27f6  75e7                   -jne 0x4f27df
    if (!cpu.flags.zf)
    {
        goto L_0x004f27df;
    }
L_0x004f27f8:
    // 004f27f8  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f27fe  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f2804:
    // 004f2804  833d340c9f0000         +cmp dword ptr [0x9f0c34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f280b  75ab                   -jne 0x4f27b8
    if (!cpu.flags.zf)
    {
        goto L_0x004f27b8;
    }
L_0x004f280d:
    // 004f280d  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2812  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2814  e8e7d3feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f2819  8915ac525600           -mov dword ptr [0x5652ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.edx;
    // 004f281f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2821  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2822  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f2830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2833  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2839  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f283b  7504                   -jne 0x4f2841
    if (!cpu.flags.zf)
    {
        goto L_0x004f2841;
    }
L_0x004f283d:
    // 004f283d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f283e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f283f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2840  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2841:
    // 004f2841  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2842  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f2844  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f284a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f284c  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2851  890d340c9f00           -mov dword ptr [0x9f0c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.ecx;
    // 004f2857  e8d4d2feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f285c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f285d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2863  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2865  e8f68affff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004f286a  b8200c9f00             -mov eax, 0x9f0c20
    cpu.eax = 10423328 /*0x9f0c20*/;
    // 004f286f  e8bcd0feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f2874  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2876  75c5                   -jne 0x4f283d
    if (!cpu.flags.zf)
    {
        goto L_0x004f283d;
    }
    // 004f2878  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f287a:
    // 004f287a  3b1dac525600           +cmp ebx, dword ptr [0x5652ac]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2880  74bb                   -je 0x4f283d
    if (cpu.flags.zf)
    {
        goto L_0x004f283d;
    }
    // 004f2882  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2884  e857d0feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f2889  ebef                   -jmp 0x4f287a
    goto L_0x004f287a;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2893  b830284f00             -mov eax, 0x4f2830
    cpu.eax = 5187632 /*0x4f2830*/;
    // 004f2898  e8db010000             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f289d  e83e8affff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f28a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f28a3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f28a8  a3340c9f00             -mov dword ptr [0x9f0c34], eax
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.eax;
    // 004f28ad  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f28b3  68200c9f00             -push 0x9f0c20
    app->getMemory<x86::reg32>(cpu.esp-4) = 10423328 /*0x9f0c20*/;
    cpu.esp -= 4;
    // 004f28b8  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f28bd  b8a0274f00             -mov eax, 0x4f27a0
    cpu.eax = 5187488 /*0x4f27a0*/;
    // 004f28c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f28c4  e8d7cefeff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f28c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f28cb  7548                   -jne 0x4f2915
    if (!cpu.flags.zf)
    {
        goto L_0x004f2915;
    }
    // 004f28cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f28ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f28cf  bbd8cb5400             -mov ebx, 0x54cbd8
    cpu.ebx = 5557208 /*0x54cbd8*/;
    // 004f28d4  bee8cb5400             -mov esi, 0x54cbe8
    cpu.esi = 5557224 /*0x54cbe8*/;
    // 004f28d9  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f28de  bf4d000000             -mov edi, 0x4d
    cpu.edi = 77 /*0x4d*/;
    // 004f28e3  e8788affff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004f28e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f28ea  68f8cb5400             -push 0x54cbf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557240 /*0x54cbf8*/;
    cpu.esp -= 4;
    // 004f28ef  890d340c9f00           -mov dword ptr [0x9f0c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.ecx;
    // 004f28f5  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f28fb  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f2901  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f2907  e804e7f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f290c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f290f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2910  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2913  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2914  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2915:
    // 004f2915  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f291b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f291c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2922  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2924  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f2930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2934  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2936  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f293c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f2941  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f2943  744d                   -je 0x4f2992
    if (cpu.flags.zf)
    {
        goto L_0x004f2992;
    }
L_0x004f2945:
    // 004f2945  8b0d340c9f00           -mov ecx, dword ptr [0x9f0c34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f294b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f294c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2952  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2954  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f2956:
    // 004f2956  83b8000c9f0000         +cmp dword ptr [eax + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f295d  7504                   -jne 0x4f2963
    if (!cpu.flags.zf)
    {
        goto L_0x004f2963;
    }
    // 004f295f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f2961  7c36                   -jl 0x4f2999
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2999;
    }
L_0x004f2963:
    // 004f2963  3bb0000c9f00           +cmp esi, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2969  7432                   -je 0x4f299d
    if (cpu.flags.zf)
    {
        goto L_0x004f299d;
    }
L_0x004f296b:
    // 004f296b  42                     -inc edx
    (cpu.edx)++;
    // 004f296c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f296f  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2972  7ce2                   -jl 0x4f2956
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2956;
    }
    // 004f2974  83fbff                 +cmp ebx, -1
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
    // 004f2977  7407                   -je 0x4f2980
    if (cpu.flags.zf)
    {
        goto L_0x004f2980;
    }
    // 004f2979  89349d000c9f00         -mov dword ptr [ebx*4 + 0x9f0c00], esi
    app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */ + cpu.ebx * 4) = cpu.esi;
L_0x004f2980:
    // 004f2980  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2987  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f298d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f298e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f298f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2991  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2992:
    // 004f2992  e8f9feffff             -call 0x4f2890
    cpu.esp -= 4;
    sub_4f2890(app, cpu);
    if (cpu.terminate) return;
    // 004f2997  ebac                   -jmp 0x4f2945
    goto L_0x004f2945;
L_0x004f2999:
    // 004f2999  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f299b  ebce                   -jmp 0x4f296b
    goto L_0x004f296b;
L_0x004f299d:
    // 004f299d  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f29a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f29a3  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f29a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f29b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f29b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f29b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f29b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f29b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f29b4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f29b6  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f29bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f29be  7505                   -jne 0x4f29c5
    if (!cpu.flags.zf)
    {
        goto L_0x004f29c5;
    }
L_0x004f29c0:
    // 004f29c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f29c5:
    // 004f29c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f29c6  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f29cc  8b35000c9f00           -mov esi, dword ptr [0x9f0c00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f29d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f29d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f29d6  39f3                   +cmp ebx, esi
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
    // 004f29d8  7411                   -je 0x4f29eb
    if (cpu.flags.zf)
    {
        goto L_0x004f29eb;
    }
L_0x004f29da:
    // 004f29da  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f29dd  42                     -inc edx
    (cpu.edx)++;
    // 004f29de  83f820                 +cmp eax, 0x20
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
    // 004f29e1  7d08                   -jge 0x4f29eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f29eb;
    }
    // 004f29e3  3b98000c9f00           +cmp ebx, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29e9  75ef                   -jne 0x4f29da
    if (!cpu.flags.zf)
    {
        goto L_0x004f29da;
    }
L_0x004f29eb:
    // 004f29eb  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29ee  7d37                   -jge 0x4f2a27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a27;
    }
    // 004f29f0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f29f7  3b98000c9f00           +cmp ebx, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29fd  7528                   -jne 0x4f2a27
    if (!cpu.flags.zf)
    {
        goto L_0x004f2a27;
    }
    // 004f29ff  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a02  7d1c                   -jge 0x4f2a20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a20;
    }
L_0x004f2a04:
    // 004f2a04  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2a07  8b90000c9f00           -mov edx, dword ptr [eax + 0x9f0c00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f2a0d  8990fc0b9f00           -mov dword ptr [eax + 0x9f0bfc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423292) /* 0x9f0bfc */) = cpu.edx;
    // 004f2a13  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a16  7cec                   -jl 0x4f2a04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2a04;
    }
    // 004f2a18  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f2a1e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_0x004f2a20:
    // 004f2a20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a22  a31c0c9f00             -mov dword ptr [0x9f0c1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10423324) /* 0x9f0c1c */) = cpu.eax;
L_0x004f2a27:
    // 004f2a27  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2a2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2a2e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2a34  8b0d000c9f00           -mov ecx, dword ptr [0x9f0c00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f2a3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
L_0x004f2a3e:
    // 004f2a3e  7580                   -jne 0x4f29c0
    if (!cpu.flags.zf)
    {
        goto L_0x004f29c0;
    }
    // 004f2a40  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2a43  83f820                 +cmp eax, 0x20
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
    // 004f2a46  7d09                   -jge 0x4f2a51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a51;
    }
    // 004f2a48  83b8000c9f0000         +cmp dword ptr [eax + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a4f  ebed                   -jmp 0x4f2a3e
    goto L_0x004f2a3e;
L_0x004f2a51:
    // 004f2a51  e8dafdffff             -call 0x4f2830
    cpu.esp -= 4;
    sub_4f2830(app, cpu);
    if (cpu.terminate) return;
    // 004f2a56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2a60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2a61  8b15ac525600           -mov edx, dword ptr [0x5652ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2a67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f2a69  7502                   -jne 0x4f2a6d
    if (!cpu.flags.zf)
    {
        goto L_0x004f2a6d;
    }
    // 004f2a6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2a6d:
    // 004f2a6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f2a6f  e8bcd0feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f2a74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2a78  e9a3510000             -jmp 0x4f7c20
    return sub_4f7c20(app, cpu);
}

/* align: skip  */
void Application::sub_4f2a7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f2a7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a7f  e880d2feff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004f2a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2a90  142b                   -adc al, 0x2b
    (cpu.al) += x86::reg8(x86::sreg8(43 /*0x2b*/) + cpu.flags.cf);
    // 004f2a92  4f                     -dec edi
    (cpu.edi)--;
    // 004f2a93  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a95  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2a98  b82b4f00ad             -mov eax, 0xad004f2b
    cpu.eax = 2902478635 /*0xad004f2b*/;
    // 004f2a9d  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa0  a22b4f0097             -mov byte ptr [0x97004f2b], al
    app->getMemory<x86::reg8>(x86::reg32(2533379883) /* 0x97004f2b */) = cpu.al;
    // 004f2aa5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa8  8c2b                   -mov word ptr [ebx], gs
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.gs;
    // 004f2aaa  4f                     -dec edi
    (cpu.edi)--;
    // 004f2aab  00812b4f0076           -add byte ptr [ecx + 0x76004f2b], al
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1979731755) /* 0x76004f2b */)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2ab1  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ab4  6b2b4f                 -imul ebp, dword ptr [ebx], 0x4f
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(79 /*0x4f*/)));
    // 004f2ab7  00602b                 -add byte ptr [eax + 0x2b], ah
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.ah));
    // 004f2aba  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abb  00552b                 -add byte ptr [ebp + 0x2b], dl
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004f2abe  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abf  004a2b                 -add byte ptr [edx + 0x2b], cl
    (app->getMemory<x86::reg8>(cpu.edx + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f2ac2  4f                     -dec edi
    (cpu.edi)--;
    // 004f2ac3  003f                   -add byte ptr [edi], bh
    (app->getMemory<x86::reg8>(cpu.edi)) += x86::reg8(x86::sreg8(cpu.bh));
    // 004f2ac5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ac8  342b                   -xor al, 0x2b
    cpu.al ^= x86::reg8(x86::sreg8(43 /*0x2b*/));
    // 004f2aca  4f                     -dec edi
    (cpu.edi)--;
    // 004f2acb  0029                   -add byte ptr [ecx], ch
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.ch));
    // 004f2acd  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2ad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2ad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2ad3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2ad5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2ad7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2ad9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f2adb  7411                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2add  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f2adf:
    // 004f2adf  48                     -dec eax
    (cpu.eax)--;
    // 004f2ae0  83f8ff                 +cmp eax, -1
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
    // 004f2ae3  7409                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2ae5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae6  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2ae8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae9  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004f2aec  ebf1                   -jmp 0x4f2adf
    goto L_0x004f2adf;
L_0x004f2aee:
    // 004f2aee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f2af0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2af2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2af4  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004f2af7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2af9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f2afb  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2afe  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f2b01  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 004f2b04  83fe0f                 +cmp esi, 0xf
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
    // 004f2b07  0f87c6000000           -ja 0x4f2bd3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b0d  ff24b5902a4f00         -jmp dword ptr [esi*4 + 0x4f2a90]
    cpu.ip = app->getMemory<x86::reg32>(5188240 + cpu.esi * 4); goto dynamic_jump;
  case 0x004f2b14:
L_0x004f2b14:
    // 004f2b14  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f2b15  83fdff                 +cmp ebp, -1
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
    // 004f2b18  0f84b5000000           -je 0x4f2bd3
    if (cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b1e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b21  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b23  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b26  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b29:
    // 004f2b29  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b2c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b2e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b31  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b34:
    // 004f2b34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b37  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b39  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b3c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b3f:
    // 004f2b3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b42  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b44  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b47  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b4a:
    // 004f2b4a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b4d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b4f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b52  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b55:
    // 004f2b55  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b58  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b5a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b5d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b60:
    // 004f2b60  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b63  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b65  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b68  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b6b:
    // 004f2b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b6e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b70  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b73  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b76:
    // 004f2b76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b79  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b7b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b7e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b81:
    // 004f2b81  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b84  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b86  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b89  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b8c:
    // 004f2b8c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b8f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b91  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b94  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b97:
    // 004f2b97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b9c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2ba2:
    // 004f2ba2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2ba5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2ba7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2baa  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bad:
    // 004f2bad  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bb2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb5  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bb8:
    // 004f2bb8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bbb  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bbd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc0  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bc3:
    // 004f2bc3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bc8  83c204                 +add edx, 4
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
    // 004f2bcb  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004f2bce  e941ffffff             -jmp 0x4f2b14
    goto L_0x004f2b14;
L_0x004f2bd3:
    // 004f2bd3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f2bd5:
    // 004f2bd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2bd6  83fbff                 +cmp ebx, -1
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
    // 004f2bd9  740d                   -je 0x4f2be8
    if (cpu.flags.zf)
    {
        goto L_0x004f2be8;
    }
    // 004f2bdb  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004f2bde  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004f2be1  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f2be3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2be4  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004f2be6  ebed                   -jmp 0x4f2bd5
    goto L_0x004f2bd5;
L_0x004f2be8:
    // 004f2be8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2be9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2bea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2beb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip  */
void Application::sub_4f2ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x004f2ad0;
    // 004f2a7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a7f  e880d2feff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004f2a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2a90  142b                   -adc al, 0x2b
    (cpu.al) += x86::reg8(x86::sreg8(43 /*0x2b*/) + cpu.flags.cf);
    // 004f2a92  4f                     -dec edi
    (cpu.edi)--;
    // 004f2a93  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a95  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2a98  b82b4f00ad             -mov eax, 0xad004f2b
    cpu.eax = 2902478635 /*0xad004f2b*/;
    // 004f2a9d  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa0  a22b4f0097             -mov byte ptr [0x97004f2b], al
    app->getMemory<x86::reg8>(x86::reg32(2533379883) /* 0x97004f2b */) = cpu.al;
    // 004f2aa5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa8  8c2b                   -mov word ptr [ebx], gs
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.gs;
    // 004f2aaa  4f                     -dec edi
    (cpu.edi)--;
    // 004f2aab  00812b4f0076           -add byte ptr [ecx + 0x76004f2b], al
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1979731755) /* 0x76004f2b */)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2ab1  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ab4  6b2b4f                 -imul ebp, dword ptr [ebx], 0x4f
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(79 /*0x4f*/)));
    // 004f2ab7  00602b                 -add byte ptr [eax + 0x2b], ah
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.ah));
    // 004f2aba  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abb  00552b                 -add byte ptr [ebp + 0x2b], dl
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004f2abe  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abf  004a2b                 -add byte ptr [edx + 0x2b], cl
    (app->getMemory<x86::reg8>(cpu.edx + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f2ac2  4f                     -dec edi
    (cpu.edi)--;
    // 004f2ac3  003f                   -add byte ptr [edi], bh
    (app->getMemory<x86::reg8>(cpu.edi)) += x86::reg8(x86::sreg8(cpu.bh));
    // 004f2ac5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ac8  342b                   -xor al, 0x2b
    cpu.al ^= x86::reg8(x86::sreg8(43 /*0x2b*/));
    // 004f2aca  4f                     -dec edi
    (cpu.edi)--;
    // 004f2acb  0029                   -add byte ptr [ecx], ch
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.ch));
    // 004f2acd  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
L_entry_0x004f2ad0:
    // 004f2ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2ad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2ad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2ad3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2ad5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2ad7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2ad9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f2adb  7411                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2add  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f2adf:
    // 004f2adf  48                     -dec eax
    (cpu.eax)--;
    // 004f2ae0  83f8ff                 +cmp eax, -1
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
    // 004f2ae3  7409                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2ae5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae6  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2ae8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae9  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004f2aec  ebf1                   -jmp 0x4f2adf
    goto L_0x004f2adf;
L_0x004f2aee:
    // 004f2aee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f2af0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2af2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2af4  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004f2af7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2af9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f2afb  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2afe  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f2b01  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 004f2b04  83fe0f                 +cmp esi, 0xf
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
    // 004f2b07  0f87c6000000           -ja 0x4f2bd3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b0d  ff24b5902a4f00         -jmp dword ptr [esi*4 + 0x4f2a90]
    cpu.ip = app->getMemory<x86::reg32>(5188240 + cpu.esi * 4); goto dynamic_jump;
  case 0x004f2b14:
L_0x004f2b14:
    // 004f2b14  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f2b15  83fdff                 +cmp ebp, -1
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
    // 004f2b18  0f84b5000000           -je 0x4f2bd3
    if (cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b1e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b21  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b23  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b26  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b29:
    // 004f2b29  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b2c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b2e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b31  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b34:
    // 004f2b34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b37  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b39  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b3c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b3f:
    // 004f2b3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b42  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b44  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b47  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b4a:
    // 004f2b4a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b4d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b4f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b52  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b55:
    // 004f2b55  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b58  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b5a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b5d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b60:
    // 004f2b60  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b63  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b65  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b68  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b6b:
    // 004f2b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b6e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b70  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b73  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b76:
    // 004f2b76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b79  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b7b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b7e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b81:
    // 004f2b81  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b84  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b86  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b89  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b8c:
    // 004f2b8c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b8f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b91  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b94  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b97:
    // 004f2b97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b9c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2ba2:
    // 004f2ba2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2ba5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2ba7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2baa  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bad:
    // 004f2bad  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bb2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb5  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bb8:
    // 004f2bb8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bbb  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bbd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc0  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bc3:
    // 004f2bc3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bc8  83c204                 +add edx, 4
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
    // 004f2bcb  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004f2bce  e941ffffff             -jmp 0x4f2b14
    goto L_0x004f2b14;
L_0x004f2bd3:
    // 004f2bd3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f2bd5:
    // 004f2bd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2bd6  83fbff                 +cmp ebx, -1
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
    // 004f2bd9  740d                   -je 0x4f2be8
    if (cpu.flags.zf)
    {
        goto L_0x004f2be8;
    }
    // 004f2bdb  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004f2bde  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004f2be1  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f2be3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2be4  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004f2be6  ebed                   -jmp 0x4f2bd5
    goto L_0x004f2bd5;
L_0x004f2be8:
    // 004f2be8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2be9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2bea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2beb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f2bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2bf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2bf2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2bf4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f2bf6  83fb04                 +cmp ebx, 4
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
    // 004f2bf9  7d13                   -jge 0x4f2c0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2c0e;
    }
L_0x004f2bfb:
    // 004f2bfb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2bfd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f2bff:
    // 004f2bff  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2c00  83fbff                 +cmp ebx, -1
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
    // 004f2c03  742a                   -je 0x4f2c2f
    if (cpu.flags.zf)
    {
        goto L_0x004f2c2f;
    }
    // 004f2c05  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f2c06  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f2c09  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f2c0a  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004f2c0c  ebf1                   -jmp 0x4f2bff
    goto L_0x004f2bff;
L_0x004f2c0e:
    // 004f2c0e  39c2                   +cmp edx, eax
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
    // 004f2c10  7607                   -jbe 0x4f2c19
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f2c19;
    }
    // 004f2c12  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004f2c15  39ca                   +cmp edx, ecx
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
    // 004f2c17  72e2                   -jb 0x4f2bfb
    if (cpu.flags.cf)
    {
        goto L_0x004f2bfb;
    }
L_0x004f2c19:
    // 004f2c19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2c1b  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004f2c20  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2c23  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2c25  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f2c27  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2c2a  e8a1feffff             -call 0x4f2ad0
    cpu.esp -= 4;
    sub_4f2ad0(app, cpu);
    if (cpu.terminate) return;
L_0x004f2c2f:
    // 004f2c2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f2c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c41  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c43  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004f2c45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c49  e8a2ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f2c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c51  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c57  e894ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f2c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c61  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c65  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2c67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c69  e882ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f2c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2c72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2c74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f2c76  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f2c78  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f2c7b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2c7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2c81  e86affffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f2c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c91  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c93  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f2c96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c9a  e851ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2ca0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f2cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2cb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2cb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2cb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2cb4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2cb6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2cb8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2cba  b9b0525600             -mov ecx, 0x5652b0
    cpu.ecx = 5657264 /*0x5652b0*/;
    // 004f2cbf  e8ec830100             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 004f2cc4  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 004f2cca  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004f2cd0  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 004f2cd3  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004f2cd7  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004f2cdd  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004f2ce3  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 004f2ce7  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004f2cea  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f2ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f2d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2d01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2d02  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d05  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d08  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004f2d0b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004f2d0e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004f2d11  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004f2d14  e897ffffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f2d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2d21  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f2d24  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d27  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d29  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004f2d2c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d2f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d31  e87affffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f2d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2d41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2d42  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d45  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d48  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004f2d4b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004f2d4e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004f2d51  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004f2d54  e857ffffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f2d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2d61  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f2d64  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d67  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d69  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004f2d6c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d6f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d71  e83affffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f2d78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d78  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2d79  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f2d7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f2d7c  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004f2d7f  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f2d82  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004f2d84  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004f2d87  e8a4eeffff             -call 0x4f1c30
    cpu.esp -= 4;
    sub_4f1c30(app, cpu);
    if (cpu.terminate) return;
    // 004f2d8c  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004f2d8e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d90  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f2da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2da4  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004f2daa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2dac  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f2dae  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2db0  e8ab00ffff             -call 0x4e2e60
    cpu.esp -= 4;
    sub_4e2e60(app, cpu);
    if (cpu.terminate) return;
    // 004f2db5  8d43f8                 -lea eax, [ebx - 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-8) /* -0x8 */);
    // 004f2db8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f2dba  3d00010000             +cmp eax, 0x100
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
    // 004f2dbf  7d05                   -jge 0x4f2dc6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2dc6;
    }
    // 004f2dc1  83f808                 +cmp eax, 8
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
    // 004f2dc4  7e36                   -jle 0x4f2dfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f2dfc;
    }
L_0x004f2dc6:
    // 004f2dc6  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004f2dc9  3d00010000             +cmp eax, 0x100
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
    // 004f2dce  7d25                   -jge 0x4f2df5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2df5;
    }
L_0x004f2dd0:
    // 004f2dd0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004f2dd2:
    // 004f2dd2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004f2dd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2dd6  e80500ffff             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004f2ddb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2ddd  7524                   -jne 0x4f2e03
    if (!cpu.flags.zf)
    {
        goto L_0x004f2e03;
    }
L_0x004f2ddf:
    // 004f2ddf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2de1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2de3  e87800ffff             -call 0x4e2e60
    cpu.esp -= 4;
    sub_4e2e60(app, cpu);
    if (cpu.terminate) return;
    // 004f2de8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2dea  81c400010000           +add esp, 0x100
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2df0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2df1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2df2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2df3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2df4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2df5:
    // 004f2df5  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004f2dfa  ebd4                   -jmp 0x4f2dd0
    goto L_0x004f2dd0;
L_0x004f2dfc:
    // 004f2dfc  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004f2e01  ebcf                   -jmp 0x4f2dd2
    goto L_0x004f2dd2;
L_0x004f2e03:
    // 004f2e03  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f2e05  e806f9ffff             -call 0x4f2710
    cpu.esp -= 4;
    sub_4f2710(app, cpu);
    if (cpu.terminate) return;
    // 004f2e0a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f2e0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2e0e  75cf                   -jne 0x4f2ddf
    if (!cpu.flags.zf)
    {
        goto L_0x004f2ddf;
    }
    // 004f2e10  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004f2e12  ebcb                   -jmp 0x4f2ddf
    goto L_0x004f2ddf;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f2e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2e22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2e23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2e24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2e25  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f2e28  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f2e2a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004f2e2c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2e2e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f2e32  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f2e34  e887e0feff             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 004f2e39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2e3b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f2e3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2e41  750d                   -jne 0x4f2e50
    if (!cpu.flags.zf)
    {
        goto L_0x004f2e50;
    }
L_0x004f2e43:
    // 004f2e43  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f2e47  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f2e4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2e50:
    // 004f2e50  e8bbf8ffff             -call 0x4f2710
    cpu.esp -= 4;
    sub_4f2710(app, cpu);
    if (cpu.terminate) return;
    // 004f2e55  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f2e59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2e5b  7511                   -jne 0x4f2e6e
    if (!cpu.flags.zf)
    {
        goto L_0x004f2e6e;
    }
    // 004f2e5d  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f2e61  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f2e65  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f2e68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2e6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2e6e:
    // 004f2e6e  be34cc5400             -mov esi, 0x54cc34
    cpu.esi = 5557300 /*0x54cc34*/;
    // 004f2e73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2e75  baaf000000             -mov edx, 0xaf
    cpu.edx = 175 /*0xaf*/;
    // 004f2e7a  e851e7feff             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 004f2e7f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f2e81  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f2e84  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f2e8a  80f310                 -xor bl, 0x10
    cpu.bl ^= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004f2e8d  b844cc5400             -mov eax, 0x54cc44
    cpu.eax = 5557316 /*0x54cc44*/;
    // 004f2e92  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f2e95  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f2e9a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2e9c  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f2ea2  e879e7feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f2ea7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2ea9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2eab  7455                   -je 0x4f2f02
    if (cpu.flags.zf)
    {
        goto L_0x004f2f02;
    }
    // 004f2ead  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f2eb0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2eb2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2eb4  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004f2eb8  e83376ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f2ebd  bb44cc5400             -mov ebx, 0x54cc44
    cpu.ebx = 5557316 /*0x54cc44*/;
    // 004f2ec2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2ec4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f2ec8  e8c3e9feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f2ecd  b934cc5400             -mov ecx, 0x54cc34
    cpu.ecx = 5557300 /*0x54cc34*/;
    // 004f2ed2  b8b6000000             -mov eax, 0xb6
    cpu.eax = 182 /*0xb6*/;
    // 004f2ed7  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f2edd  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f2ee2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f2ee4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2ee6  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f2eec  e82fe7feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f2ef1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f2ef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2ef7  7409                   -je 0x4f2f02
    if (cpu.flags.zf)
    {
        goto L_0x004f2f02;
    }
    // 004f2ef9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2efb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2efd  e81ef7ffff             -call 0x4f2620
    cpu.esp -= 4;
    sub_4f2620(app, cpu);
    if (cpu.terminate) return;
L_0x004f2f02:
    // 004f2f02  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f2f06  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f2f08  0f8435ffffff           -je 0x4f2e43
    if (cpu.flags.zf)
    {
        goto L_0x004f2e43;
    }
    // 004f2f0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f2f10  e87be9feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f2f15  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f2f19  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f2f1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f2f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2f32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2f34  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004f2f3a  891d0c445600           -mov dword ptr [0x56440c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ebx;
    // 004f2f40  e8dbfeffff             -call 0x4f2e20
    cpu.esp -= 4;
    sub_4f2e20(app, cpu);
    if (cpu.terminate) return;
    // 004f2f45  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004f2f4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2f52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2f53  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f2f56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2f58  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2f5a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004f2f60  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004f2f67  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f2f6e  8a25f49aa000           -mov ah, byte ptr [0xa09af4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
    // 004f2f74  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f2f7b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004f2f7d  7410                   -je 0x4f2f8f
    if (cpu.flags.zf)
    {
        goto L_0x004f2f8f;
    }
    // 004f2f7f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f2f81  7d13                   -jge 0x4f2f96
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2f96;
    }
L_0x004f2f83:
    // 004f2f83  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004f2f88:
    // 004f2f88  83c410                 +add esp, 0x10
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
    // 004f2f8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2f8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2f8f:
    // 004f2f8f  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f2f94  ebf2                   -jmp 0x4f2f88
    goto L_0x004f2f88;
L_0x004f2f96:
    // 004f2f96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2f98  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2f9d  e8020b0000             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f2fa2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2fa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2fa6  74db                   -je 0x4f2f83
    if (cpu.flags.zf)
    {
        goto L_0x004f2f83;
    }
    // 004f2fa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2fa9  e872de0000             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004f2fae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2fb0  e85bda0100             -call 0x510a10
    cpu.esp -= 4;
    sub_510a10(app, cpu);
    if (cpu.terminate) return;
    // 004f2fb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2fb9  0f84fb000000           -je 0x4f30ba
    if (cpu.flags.zf)
    {
        goto L_0x004f30ba;
    }
    // 004f2fbf  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004f2fc3  0f8ccb000000           -jl 0x4f3094
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3094;
    }
    // 004f2fc9  3b02                   +cmp eax, dword ptr [edx]
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
    // 004f2fcb  0f85d8000000           -jne 0x4f30a9
    if (!cpu.flags.zf)
    {
        goto L_0x004f30a9;
    }
    // 004f2fd1  c70102000000           -mov dword ptr [ecx], 2
    app->getMemory<x86::reg32>(cpu.ecx) = 2 /*0x2*/;
    // 004f2fd7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f2fd9  668b7a1c               -mov di, word ptr [edx + 0x1c]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */);
L_0x004f2fdd:
    // 004f2fdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2fde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2fdf  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004f2fe2  bae8030000             -mov edx, 0x3e8
    cpu.edx = 1000 /*0x3e8*/;
    // 004f2fe7  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f2feb  e880060100             -call 0x503670
    cpu.esp -= 4;
    sub_503670(app, cpu);
    if (cpu.terminate) return;
    // 004f2ff0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f2ff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2ff5  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f2ff9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f2ffa  e861070100             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 004f2fff  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f3002  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004f3005  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3006  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004f3009  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f300d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f300f  bae8030000             -mov edx, 0x3e8
    cpu.edx = 1000 /*0x3e8*/;
    // 004f3014  e857060100             -call 0x503670
    cpu.esp -= 4;
    sub_503670(app, cpu);
    if (cpu.terminate) return;
    // 004f3019  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f301d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f301e  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f3022  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3023  e838070100             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 004f3028  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f302b  817b1c00093d00         +cmp dword ptr [ebx + 0x1c], 0x3d0900
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000000 /*0x3d0900*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3032  762e                   -jbe 0x4f3062
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f3062;
    }
    // 004f3034  ba50cc5400             -mov edx, 0x54cc50
    cpu.edx = 5557328 /*0x54cc50*/;
    // 004f3039  be60cc5400             -mov esi, 0x54cc60
    cpu.esi = 5557344 /*0x54cc60*/;
    // 004f303e  bd9b000000             -mov ebp, 0x9b
    cpu.ebp = 155 /*0x9b*/;
    // 004f3043  6878cc5400             -push 0x54cc78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557368 /*0x54cc78*/;
    cpu.esp -= 4;
    // 004f3048  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f304e  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f3054  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f305a  e8b1dff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f305f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f3062:
    // 004f3062  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004f3065  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f306c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f306e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3071  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3073  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3076  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3078  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f307b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f307d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f307f  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004f3081  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f3084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3085  e8f2dd0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f308a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f308c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f308d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3090  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3091  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3092  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3093  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3094:
    // 004f3094  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004f309a  e8dddd0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f309f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f30a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30a2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f30a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f30a9:
    // 004f30a9  c70101000000           -mov dword ptr [ecx], 1
    app->getMemory<x86::reg32>(cpu.ecx) = 1 /*0x1*/;
    // 004f30af  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f30b1  668b7a20               -mov di, word ptr [edx + 0x20]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f30b5  e923ffffff             -jmp 0x4f2fdd
    goto L_0x004f2fdd;
L_0x004f30ba:
    // 004f30ba  c70103000000           -mov dword ptr [ecx], 3
    app->getMemory<x86::reg32>(cpu.ecx) = 3 /*0x3*/;
    // 004f30c0  e8b7dd0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f30c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f30c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30c8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f30cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f30ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f30d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f30d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f30d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f30d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f30d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f30d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f30d5  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
    // 004f30da  bbc0ffffff             -mov ebx, 0xffffffc0
    cpu.ebx = 4294967232 /*0xffffffc0*/;
    // 004f30df  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
L_0x004f30e4:
    // 004f30e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f30e6  83fac0                 +cmp edx, -0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-64 /*-0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f30e9  0f8dbd010000           -jge 0x4f32ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f32ac;
    }
    // 004f30ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004f30f1:
    // 004f30f1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f30f3  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f30f9  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004f30fb  42                     -inc edx
    (cpu.edx)++;
    // 004f30fc  8881380d9f00           -mov byte ptr [ecx + 0x9f0d38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */) = cpu.al;
    // 004f3102  83fa7f                 +cmp edx, 0x7f
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
    // 004f3105  7cdd                   -jl 0x4f30e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f30e4;
    }
    // 004f3107  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004f310c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004f3111  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 004f3116  891538199f00           -mov dword ptr [0x9f1938], edx
    app->getMemory<x86::reg32>(x86::reg32(10426680) /* 0x9f1938 */) = cpu.edx;
L_0x004f311c:
    // 004f311c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f311f  898834199f00           -mov dword ptr [eax + 0x9f1934], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10426676) /* 0x9f1934 */) = cpu.ecx;
    // 004f3125  83f820                 +cmp eax, 0x20
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
    // 004f3128  75f2                   -jne 0x4f311c
    if (!cpu.flags.zf)
    {
        goto L_0x004f311c;
    }
    // 004f312a  bb2f000000             -mov ebx, 0x2f
    cpu.ebx = 47 /*0x2f*/;
    // 004f312f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3131:
    // 004f3131  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3134  899854199f00           -mov dword ptr [eax + 0x9f1954], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10426708) /* 0x9f1954 */) = cpu.ebx;
    // 004f313a  83f820                 +cmp eax, 0x20
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
    // 004f313d  75f2                   -jne 0x4f3131
    if (!cpu.flags.zf)
    {
        goto L_0x004f3131;
    }
    // 004f313f  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
    // 004f3144  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3146:
    // 004f3146  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3149  89b0341d9f00           -mov dword ptr [eax + 0x9f1d34], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10427700) /* 0x9f1d34 */) = cpu.esi;
    // 004f314f  3d00020000             +cmp eax, 0x200
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3154  75f0                   -jne 0x4f3146
    if (!cpu.flags.zf)
    {
        goto L_0x004f3146;
    }
    // 004f3156  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004f315b:
    // 004f315b  8b83d8525600           -mov eax, dword ptr [ebx + 0x5652d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5657304) /* 0x5652d8 */);
    // 004f3161  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3163  8b8be0525600           -mov ecx, dword ptr [ebx + 0x5652e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5657312) /* 0x5652e0 */);
    // 004f3169  81e600fc0000           -and esi, 0xfc00
    cpu.esi &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004f316f  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004f3174  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 004f3177  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004f317a  8b93d4525600           -mov edx, dword ptr [ebx + 0x5652d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5657300) /* 0x5652d4 */);
    // 004f3180  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004f3182  f6c5fc                 +test ch, 0xfc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 252 /*0xfc*/));
    // 004f3185  0f8431010000           -je 0x4f32bc
    if (cpu.flags.zf)
    {
        goto L_0x004f32bc;
    }
    // 004f318b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f318d  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004f3192  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f3197  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3199  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f319b  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 004f319d  c1fe07                 -sar esi, 7
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (7 /*0x7*/ % 32));
    // 004f31a0  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f31a2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f31a4  7e1b                   -jle 0x4f31c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f31c1;
    }
    // 004f31a6  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f31a9  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f31b0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f31b2  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f31b4:
    // 004f31b4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f31b7  898234199f00           -mov dword ptr [edx + 0x9f1934], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10426676) /* 0x9f1934 */) = cpu.eax;
    // 004f31bd  39ca                   +cmp edx, ecx
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
    // 004f31bf  7cf3                   -jl 0x4f31b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f31b4;
    }
L_0x004f31c1:
    // 004f31c1  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f31c4  81fbf0050000           +cmp ebx, 0x5f0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1520 /*0x5f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f31ca  758f                   -jne 0x4f315b
    if (!cpu.flags.zf)
    {
        goto L_0x004f315b;
    }
    // 004f31cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f31ce:
    // 004f31ce  8b83c8585600           -mov eax, dword ptr [ebx + 0x5658c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5658824) /* 0x5658c8 */);
    // 004f31d4  8b93c4585600           -mov edx, dword ptr [ebx + 0x5658c4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5658820) /* 0x5658c4 */);
    // 004f31da  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f31dc  8b8bd0585600           -mov ecx, dword ptr [ebx + 0x5658d0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5658832) /* 0x5658d0 */);
    // 004f31e2  81e600fc0000           -and esi, 0xfc00
    cpu.esi &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004f31e8  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004f31ed  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 004f31f0  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004f31f3  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f31f6  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 004f31f8  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 004f31fb  0f85fe000000           -jne 0x4f32ff
    if (!cpu.flags.zf)
    {
        goto L_0x004f32ff;
    }
    // 004f3201  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f3203  83ea09                 -sub edx, 9
    (cpu.edx) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004f3206  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004f320b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f3210  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3212  c1fe07                 -sar esi, 7
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (7 /*0x7*/ % 32));
    // 004f3215  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 004f3217  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3219  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f321b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f321d  7e1b                   -jle 0x4f323a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f323a;
    }
    // 004f321f  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f3222  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f3229  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f322b  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f322d:
    // 004f322d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3230  898234119f00           -mov dword ptr [edx + 0x9f1134], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10424628) /* 0x9f1134 */) = cpu.eax;
    // 004f3236  39ca                   +cmp edx, ecx
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
    // 004f3238  7cf3                   -jl 0x4f322d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f322d;
    }
L_0x004f323a:
    // 004f323a  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f323d  81fb00080000           +cmp ebx, 0x800
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3243  7589                   -jne 0x4f31ce
    if (!cpu.flags.zf)
    {
        goto L_0x004f31ce;
    }
    // 004f3245  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f324a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f324c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f324d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f324e:
    // 004f324e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3251  89b834109f00           -mov dword ptr [eax + 0x9f1034], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10424372) /* 0x9f1034 */) = cpu.edi;
    // 004f3257  3d80000000             +cmp eax, 0x80
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f325c  75f0                   -jne 0x4f324e
    if (!cpu.flags.zf)
    {
        goto L_0x004f324e;
    }
    // 004f325e  ba00004000             -mov edx, 0x400000
    cpu.edx = 4194304 /*0x400000*/;
    // 004f3263  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3265:
    // 004f3265  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f3267  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f326a  80c906                 -or cl, 6
    cpu.cl |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 004f326d  81c200004000           -add edx, 0x400000
    (cpu.edx) += x86::reg32(x86::sreg32(4194304 /*0x400000*/));
    // 004f3273  8988b4109f00           -mov dword ptr [eax + 0x9f10b4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10424500) /* 0x9f10b4 */) = cpu.ecx;
    // 004f3279  83f840                 +cmp eax, 0x40
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
    // 004f327c  75e7                   -jne 0x4f3265
    if (!cpu.flags.zf)
    {
        goto L_0x004f3265;
    }
    // 004f327e  ba000000fc             -mov edx, 0xfc000000
    cpu.edx = 4227858432 /*0xfc000000*/;
    // 004f3283  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3285:
    // 004f3285  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f3287  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f328a  80c906                 -or cl, 6
    cpu.cl |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 004f328d  81c200004000           -add edx, 0x400000
    (cpu.edx) += x86::reg32(x86::sreg32(4194304 /*0x400000*/));
    // 004f3293  8988f4109f00           -mov dword ptr [eax + 0x9f10f4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10424564) /* 0x9f10f4 */) = cpu.ecx;
    // 004f3299  83f840                 +cmp eax, 0x40
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
    // 004f329c  75e7                   -jne 0x4f3285
    if (!cpu.flags.zf)
    {
        goto L_0x004f3285;
    }
    // 004f329e  c70538259f0001000000   -mov dword ptr [0x9f2538], 1
    app->getMemory<x86::reg32>(x86::reg32(10429752) /* 0x9f2538 */) = 1 /*0x1*/;
    // 004f32a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f32a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f32aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f32ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f32ac:
    // 004f32ac  83fa3f                 +cmp edx, 0x3f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f32af  0f8e3cfeffff           -jle 0x4f30f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f30f1;
    }
    // 004f32b5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f32b7  e935feffff             -jmp 0x4f30f1
    goto L_0x004f30f1;
L_0x004f32bc:
    // 004f32bc  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f32be  83ea06                 -sub edx, 6
    (cpu.edx) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004f32c1  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004f32c6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f32cb  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f32cd  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 004f32d0  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 004f32d2  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f32d4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f32d6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f32d8  0f8ee3feffff           -jle 0x4f31c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f31c1;
    }
    // 004f32de  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f32e1  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f32e8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f32ea  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f32ec:
    // 004f32ec  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f32ef  898234159f00           -mov dword ptr [edx + 0x9f1534], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10425652) /* 0x9f1534 */) = cpu.eax;
    // 004f32f5  39ca                   +cmp edx, ecx
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
    // 004f32f7  0f8dc4feffff           -jge 0x4f31c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f31c1;
    }
    // 004f32fd  ebed                   -jmp 0x4f32ec
    goto L_0x004f32ec;
L_0x004f32ff:
    // 004f32ff  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f3301  83ea06                 -sub edx, 6
    (cpu.edx) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004f3304  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004f3309  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f330e  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3310  c1fe0a                 -sar esi, 0xa
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (10 /*0xa*/ % 32));
    // 004f3313  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 004f3315  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3317  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f3319  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f331b  0f8e19ffffff           -jle 0x4f323a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f323a;
    }
    // 004f3321  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f3324  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f332b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f332d  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004f332f:
    // 004f332f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3332  898234159f00           -mov dword ptr [edx + 0x9f1534], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10425652) /* 0x9f1534 */) = cpu.eax;
    // 004f3338  39ca                   +cmp edx, ecx
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
    // 004f333a  0f8dfafeffff           -jge 0x4f323a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f323a;
    }
    // 004f3340  ebed                   -jmp 0x4f332f
    goto L_0x004f332f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f3350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3352  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3353  8b1544259f00           -mov edx, dword ptr [0x9f2544]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */);
    // 004f3359  8b353c259f00           -mov esi, dword ptr [0x9f253c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */);
    // 004f335f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f3361  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3363  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004f3365  83fa10                 +cmp edx, 0x10
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
    // 004f3368  7c10                   -jl 0x4f337a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f337a;
    }
    // 004f336a  89353c259f00           -mov dword ptr [0x9f253c], esi
    app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */) = cpu.esi;
    // 004f3370  891544259f00           -mov dword ptr [0x9f2544], edx
    app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */) = cpu.edx;
    // 004f3376  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3377  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3378  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3379  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f337a:
    // 004f337a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f337b  a148259f00             -mov eax, dword ptr [0x9f2548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429768) /* 0x9f2548 */);
    // 004f3380  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3382  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004f3387  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004f338a  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f338d  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f338f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3392  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004f3394  a348259f00             -mov dword ptr [0x9f2548], eax
    app->getMemory<x86::reg32>(x86::reg32(10429768) /* 0x9f2548 */) = cpu.eax;
    // 004f3399  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f339b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f339c  89353c259f00           -mov dword ptr [0x9f253c], esi
    app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */) = cpu.esi;
    // 004f33a2  891544259f00           -mov dword ptr [0x9f2544], edx
    app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */) = cpu.edx;
    // 004f33a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f33a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f33aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f33ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f33b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f33b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f33b1  a13c259f00             -mov eax, dword ptr [0x9f253c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */);
    // 004f33b6  c1e81a                 -shr eax, 0x1a
    cpu.eax >>= 26 /*0x1a*/ % 32;
    // 004f33b9  8b148538109f00         -mov edx, dword ptr [eax*4 + 0x9f1038]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10424376) /* 0x9f1038 */ + cpu.eax * 4);
    // 004f33c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f33c2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f33c7  e884ffffff             -call 0x4f3350
    cpu.esp -= 4;
    sub_4f3350(app, cpu);
    if (cpu.terminate) return;
    // 004f33cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f33ce  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 004f33d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f33d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f33e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f33e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f33e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f33e2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f33e4  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f33e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f33e9:
    // 004f33e9  8b0d2ccf5600           -mov ecx, dword ptr [0x56cf2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5689132) /* 0x56cf2c */);
    // 004f33ef  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004f33f1  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f33f4  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f33f7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f33fa  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004f33fd  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004f3400  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004f3403  42                     -inc edx
    (cpu.edx)++;
    // 004f3404  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f3407  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3409  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f340c  7cdb                   -jl 0x4f33e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f33e9;
    }
    // 004f340e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f340f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3410  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f3420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3420  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3421  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3422  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3423  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3425  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004f3427  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f3429  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f342b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f342f  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004f3436  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f3438  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f343a  7453                   -je 0x4f348f
    if (cpu.flags.zf)
    {
        goto L_0x004f348f;
    }
    // 004f343c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f343e:
    // 004f343e  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f3441  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3443  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004f3446  8a5a07                 -mov bl, byte ptr [edx + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004f3449  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f344b  885806                 -mov byte ptr [eax + 6], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.bl;
    // 004f344e  8a5a06                 -mov bl, byte ptr [edx + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004f3451  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3453  88580a                 -mov byte ptr [eax + 0xa], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.bl;
    // 004f3456  8a5a0b                 -mov bl, byte ptr [edx + 0xb]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 004f3459  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f345b  88580e                 -mov byte ptr [eax + 0xe], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.bl;
    // 004f345e  8a5a0a                 -mov bl, byte ptr [edx + 0xa]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004f3461  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3463  885812                 -mov byte ptr [eax + 0x12], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f3466  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004f3469  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f346b  885816                 -mov byte ptr [eax + 0x16], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = cpu.bl;
    // 004f346e  8a5a0e                 -mov bl, byte ptr [edx + 0xe]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 004f3471  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3473  88581a                 -mov byte ptr [eax + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 004f3476  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004f3479  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004f347c  46                     -inc esi
    (cpu.esi)++;
    // 004f347d  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f347f  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3481  8858de                 -mov byte ptr [eax - 0x22], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-34) /* -0x22 */) = cpu.bl;
    // 004f3484  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3487  7cb5                   -jl 0x4f343e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f343e;
    }
    // 004f3489  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f348a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f348b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f348c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f348f:
    // 004f348f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f3491:
    // 004f3491  8a5a03                 -mov bl, byte ptr [edx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004f3494  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3496  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004f3499  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f349c  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f349e  885806                 -mov byte ptr [eax + 6], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.bl;
    // 004f34a1  8a5a07                 -mov bl, byte ptr [edx + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004f34a4  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34a6  88580a                 -mov byte ptr [eax + 0xa], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.bl;
    // 004f34a9  8a5a06                 -mov bl, byte ptr [edx + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004f34ac  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34ae  88580e                 -mov byte ptr [eax + 0xe], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.bl;
    // 004f34b1  8a5a0b                 -mov bl, byte ptr [edx + 0xb]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 004f34b4  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34b6  885812                 -mov byte ptr [eax + 0x12], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f34b9  8a5a0a                 -mov bl, byte ptr [edx + 0xa]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004f34bc  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34be  885816                 -mov byte ptr [eax + 0x16], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = cpu.bl;
    // 004f34c1  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004f34c4  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34c6  88581a                 -mov byte ptr [eax + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 004f34c9  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004f34cc  8a5a0e                 -mov bl, byte ptr [edx + 0xe]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 004f34cf  46                     -inc esi
    (cpu.esi)++;
    // 004f34d0  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f34d2  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f34d4  8858de                 -mov byte ptr [eax - 0x22], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-34) /* -0x22 */) = cpu.bl;
    // 004f34d7  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f34da  7cb5                   -jl 0x4f3491
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3491;
    }
    // 004f34dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f34dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f34de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f34df  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f34f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f34f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f34f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f34f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f34f4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f34f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f34f8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f34fa  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f34fe  8d3cdd00000000         -lea edi, [ebx*8]
    cpu.edi = x86::reg32(cpu.ebx * 8);
    // 004f3505  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f3507  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f3509:
    // 004f3509  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f350b  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f350d  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004f3510  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3513  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3515  885a06                 -mov byte ptr [edx + 6], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.bl;
    // 004f3518  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f351b  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f351d  885a0a                 -mov byte ptr [edx + 0xa], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.bl;
    // 004f3520  8a580c                 -mov bl, byte ptr [eax + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f3523  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3525  885a0e                 -mov byte ptr [edx + 0xe], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */) = cpu.bl;
    // 004f3528  8a5810                 -mov bl, byte ptr [eax + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f352b  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f352d  885a12                 -mov byte ptr [edx + 0x12], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f3530  8a5814                 -mov bl, byte ptr [eax + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f3533  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3535  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
    // 004f3538  8a5818                 -mov bl, byte ptr [eax + 0x18]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f353b  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f353d  885a1a                 -mov byte ptr [edx + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 004f3540  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f3543  8a581c                 -mov bl, byte ptr [eax + 0x1c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f3546  46                     -inc esi
    (cpu.esi)++;
    // 004f3547  00cb                   -add bl, cl
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f3549  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f354b  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 004f354e  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3551  7cb6                   -jl 0x4f3509
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3509;
    }
    // 004f3553  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3555  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f3560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3560  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3561  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3563  833d38259f0000         +cmp dword ptr [0x9f2538], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10429752) /* 0x9f2538 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f356a  0f8486000000           -je 0x4f35f6
    if (cpu.flags.zf)
    {
        goto L_0x004f35f6;
    }
L_0x004f3570:
    // 004f3570  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3571  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3572  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 004f3577  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f357a  891540259f00           -mov dword ptr [0x9f2540], edx
    app->getMemory<x86::reg32>(x86::reg32(10429760) /* 0x9f2540 */) = cpu.edx;
    // 004f3580  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f3582  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3584  8b152cd05600           -mov edx, dword ptr [0x56d02c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5689388) /* 0x56d02c */);
    // 004f358a  893d44259f00           -mov dword ptr [0x9f2544], edi
    app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */) = cpu.edi;
    // 004f3590  668b71fc               -mov si, word ptr [ecx - 4]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004f3594  668b41fe               -mov ax, word ptr [ecx - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004f3598  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004f359b  890d48259f00           -mov dword ptr [0x9f2548], ecx
    app->getMemory<x86::reg32>(x86::reg32(10429768) /* 0x9f2548 */) = cpu.ecx;
    // 004f35a1  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004f35a3  a1c4605600             -mov eax, dword ptr [0x5660c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5660868) /* 0x5660c4 */);
    // 004f35a8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f35ad  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 004f35b0  89353c259f00           -mov dword ptr [0x9f253c], esi
    app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */) = cpu.esi;
    // 004f35b6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004f35b8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004f35bb  c1e810                 +shr eax, 0x10
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
    // 004f35be  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f35c0  a3380c9f00             -mov dword ptr [0x9f0c38], eax
    app->getMemory<x86::reg32>(x86::reg32(10423352) /* 0x9f0c38 */) = cpu.eax;
    // 004f35c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f35c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f35c7:
    // 004f35c7  8b81c4605600           -mov eax, dword ptr [ecx + 0x5660c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5660868) /* 0x5660c4 */);
    // 004f35cd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004f35d0  8b912cd05600           -mov edx, dword ptr [ecx + 0x56d02c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5689388) /* 0x56d02c */);
    // 004f35d6  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 004f35d9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f35dc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004f35de  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004f35e1  c1e810                 +shr eax, 0x10
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
    // 004f35e4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f35e6  8981340c9f00           -mov dword ptr [ecx + 0x9f0c34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10423348) /* 0x9f0c34 */) = cpu.eax;
    // 004f35ec  81f900010000           +cmp ecx, 0x100
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
    // 004f35f2  75d3                   -jne 0x4f35c7
    if (!cpu.flags.zf)
    {
        goto L_0x004f35c7;
    }
    // 004f35f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f35f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f35f6:
    // 004f35f6  e8d5faffff             -call 0x4f30d0
    cpu.esp -= 4;
    sub_4f30d0(app, cpu);
    if (cpu.terminate) return;
    // 004f35fb  e970ffffff             -jmp 0x4f3570
    goto L_0x004f3570;
}

/* align: skip  */
void Application::sub_4f3600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3602  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3603  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3606  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f3608  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f360a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f360c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f360d  8b1540259f00           -mov edx, dword ptr [0x9f2540]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10429760) /* 0x9f2540 */);
    // 004f3613  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004f3615  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f3617  0f843c020000           -je 0x4f3859
    if (cpu.flags.zf)
    {
        goto L_0x004f3859;
    }
    // 004f361d  8a253f259f00           -mov ah, byte ptr [0x9f253f]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10429759) /* 0x9f253f */);
    // 004f3623  f6c4c0                 +test ah, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 192 /*0xc0*/));
    // 004f3626  0f8536020000           -jne 0x4f3862
    if (!cpu.flags.zf)
    {
        goto L_0x004f3862;
    }
    // 004f362c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004f3631  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3633  e818fdffff             -call 0x4f3350
    cpu.esp -= 4;
    sub_4f3350(app, cpu);
    if (cpu.terminate) return;
    // 004f3638  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
L_0x004f363c:
    // 004f363c  e807d80100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f3641  83f801                 +cmp eax, 1
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
    // 004f3644  0f8598020000           -jne 0x4f38e2
    if (!cpu.flags.zf)
    {
        goto L_0x004f38e2;
    }
    // 004f364a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f364f  b838219f00             -mov eax, 0x9f2138
    cpu.eax = 10428728 /*0x9f2138*/;
    // 004f3654  e887fdffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f3659:
    // 004f3659  f644240802             +test byte ptr [esp + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004f365e  0f85a6020000           -jne 0x4f390a
    if (!cpu.flags.zf)
    {
        goto L_0x004f390a;
    }
    // 004f3664  e8dfd70100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f3669  83f801                 +cmp eax, 1
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
    // 004f366c  0f8584020000           -jne 0x4f38f6
    if (!cpu.flags.zf)
    {
        goto L_0x004f38f6;
    }
    // 004f3672  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f3677  b858219f00             -mov eax, 0x9f2158
    cpu.eax = 10428760 /*0x9f2158*/;
    // 004f367c  e85ffdffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f3681:
    // 004f3681  f644240804             +test byte ptr [esp + 8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 4 /*0x4*/));
    // 004f3686  0f85b3020000           -jne 0x4f393f
    if (!cpu.flags.zf)
    {
        goto L_0x004f393f;
    }
    // 004f368c  e8b7d70100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f3691  83f801                 +cmp eax, 1
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
    // 004f3694  0f8591020000           -jne 0x4f392b
    if (!cpu.flags.zf)
    {
        goto L_0x004f392b;
    }
    // 004f369a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f369f  b838239f00             -mov eax, 0x9f2338
    cpu.eax = 10429240 /*0x9f2338*/;
    // 004f36a4  e837fdffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f36a9:
    // 004f36a9  f644240808             +test byte ptr [esp + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 004f36ae  0f85c4020000           -jne 0x4f3978
    if (!cpu.flags.zf)
    {
        goto L_0x004f3978;
    }
    // 004f36b4  e88fd70100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f36b9  83f801                 +cmp eax, 1
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
    // 004f36bc  0f85a2020000           -jne 0x4f3964
    if (!cpu.flags.zf)
    {
        goto L_0x004f3964;
    }
    // 004f36c2  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f36c7  b858239f00             -mov eax, 0x9f2358
    cpu.eax = 10429272 /*0x9f2358*/;
    // 004f36cc  e80ffdffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f36d1:
    // 004f36d1  f644240810             +test byte ptr [esp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004f36d6  0f85d8020000           -jne 0x4f39b4
    if (!cpu.flags.zf)
    {
        goto L_0x004f39b4;
    }
    // 004f36dc  e867d70100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f36e1  83f801                 +cmp eax, 1
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
    // 004f36e4  0f85b6020000           -jne 0x4f39a0
    if (!cpu.flags.zf)
    {
        goto L_0x004f39a0;
    }
    // 004f36ea  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004f36ef  b8380e9f00             -mov eax, 0x9f0e38
    cpu.eax = 10423864 /*0x9f0e38*/;
    // 004f36f4  e8e7fcffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f36f9:
    // 004f36f9  f644240820             +test byte ptr [esp + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 004f36fe  0f85e5020000           -jne 0x4f39e9
    if (!cpu.flags.zf)
    {
        goto L_0x004f39e9;
    }
    // 004f3704  e83fd70100             -call 0x510e48
    cpu.esp -= 4;
    sub_510e48(app, cpu);
    if (cpu.terminate) return;
    // 004f3709  83f801                 +cmp eax, 1
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
    // 004f370c  0f85c3020000           -jne 0x4f39d5
    if (!cpu.flags.zf)
    {
        goto L_0x004f39d5;
    }
    // 004f3712  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004f3717  b8380f9f00             -mov eax, 0x9f0f38
    cpu.eax = 10424120 /*0x9f0f38*/;
    // 004f371c  e8bffcffff             -call 0x4f33e0
    cpu.esp -= 4;
    sub_4f33e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f3721:
    // 004f3721  ba380e9f00             -mov edx, 0x9f0e38
    cpu.edx = 10423864 /*0x9f0e38*/;
    // 004f3726  b838219f00             -mov eax, 0x9f2138
    cpu.eax = 10428728 /*0x9f2138*/;
    // 004f372b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f372d  e8c6d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3732  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004f3735  ba380e9f00             -mov edx, 0x9f0e38
    cpu.edx = 10423864 /*0x9f0e38*/;
    // 004f373a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f373c  b878219f00             -mov eax, 0x9f2178
    cpu.eax = 10428792 /*0x9f2178*/;
    // 004f3741  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3743  e8b0d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3748  ba580e9f00             -mov edx, 0x9f0e58
    cpu.edx = 10423896 /*0x9f0e58*/;
    // 004f374d  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f374f  b8b8219f00             -mov eax, 0x9f21b8
    cpu.eax = 10428856 /*0x9f21b8*/;
    // 004f3754  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3756  e89dd80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f375b  ba580e9f00             -mov edx, 0x9f0e58
    cpu.edx = 10423896 /*0x9f0e58*/;
    // 004f3760  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3762  b8f8219f00             -mov eax, 0x9f21f8
    cpu.eax = 10428920 /*0x9f21f8*/;
    // 004f3767  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3769  e88ad80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f376e  ba780e9f00             -mov edx, 0x9f0e78
    cpu.edx = 10423928 /*0x9f0e78*/;
    // 004f3773  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3775  b838229f00             -mov eax, 0x9f2238
    cpu.eax = 10428984 /*0x9f2238*/;
    // 004f377a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f377c  e877d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3781  ba780e9f00             -mov edx, 0x9f0e78
    cpu.edx = 10423928 /*0x9f0e78*/;
    // 004f3786  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3788  b878229f00             -mov eax, 0x9f2278
    cpu.eax = 10429048 /*0x9f2278*/;
    // 004f378d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f378f  e864d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3794  ba980e9f00             -mov edx, 0x9f0e98
    cpu.edx = 10423960 /*0x9f0e98*/;
    // 004f3799  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f379b  b8b8229f00             -mov eax, 0x9f22b8
    cpu.eax = 10429112 /*0x9f22b8*/;
    // 004f37a0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f37a2  e851d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f37a7  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f37a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f37aa  ba980e9f00             -mov edx, 0x9f0e98
    cpu.edx = 10423960 /*0x9f0e98*/;
    // 004f37af  b8f8229f00             -mov eax, 0x9f22f8
    cpu.eax = 10429176 /*0x9f22f8*/;
    // 004f37b4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f37b6  e83dd80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f37bb  bab80e9f00             -mov edx, 0x9f0eb8
    cpu.edx = 10423992 /*0x9f0eb8*/;
    // 004f37c0  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f37c2  b838239f00             -mov eax, 0x9f2338
    cpu.eax = 10429240 /*0x9f2338*/;
    // 004f37c7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f37c9  e82ad80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f37ce  bab80e9f00             -mov edx, 0x9f0eb8
    cpu.edx = 10423992 /*0x9f0eb8*/;
    // 004f37d3  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f37d5  b878239f00             -mov eax, 0x9f2378
    cpu.eax = 10429304 /*0x9f2378*/;
    // 004f37da  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f37dc  e817d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f37e1  bad80e9f00             -mov edx, 0x9f0ed8
    cpu.edx = 10424024 /*0x9f0ed8*/;
    // 004f37e6  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f37e8  b8b8239f00             -mov eax, 0x9f23b8
    cpu.eax = 10429368 /*0x9f23b8*/;
    // 004f37ed  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f37ef  e804d80100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f37f4  bad80e9f00             -mov edx, 0x9f0ed8
    cpu.edx = 10424024 /*0x9f0ed8*/;
    // 004f37f9  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f37fb  b8f8239f00             -mov eax, 0x9f23f8
    cpu.eax = 10429432 /*0x9f23f8*/;
    // 004f3800  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3802  e8f1d70100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3807  baf80e9f00             -mov edx, 0x9f0ef8
    cpu.edx = 10424056 /*0x9f0ef8*/;
    // 004f380c  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f380e  b838249f00             -mov eax, 0x9f2438
    cpu.eax = 10429496 /*0x9f2438*/;
    // 004f3813  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3815  e8ded70100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f381a  baf80e9f00             -mov edx, 0x9f0ef8
    cpu.edx = 10424056 /*0x9f0ef8*/;
    // 004f381f  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3821  b878249f00             -mov eax, 0x9f2478
    cpu.eax = 10429560 /*0x9f2478*/;
    // 004f3826  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f3828  e8cbd70100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f382d  ba180f9f00             -mov edx, 0x9f0f18
    cpu.edx = 10424088 /*0x9f0f18*/;
    // 004f3832  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f3834  b8b8249f00             -mov eax, 0x9f24b8
    cpu.eax = 10429624 /*0x9f24b8*/;
    // 004f3839  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f383b  e8b8d70100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3840  ba180f9f00             -mov edx, 0x9f0f18
    cpu.edx = 10424088 /*0x9f0f18*/;
    // 004f3845  b8f8249f00             -mov eax, 0x9f24f8
    cpu.eax = 10429688 /*0x9f24f8*/;
    // 004f384a  8d1c3e                 -lea ebx, [esi + edi]
    cpu.ebx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004f384d  e8a6d70100             -call 0x510ff8
    cpu.esp -= 4;
    sub_510ff8(app, cpu);
    if (cpu.terminate) return;
    // 004f3852  83c408                 +add esp, 8
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
    // 004f3855  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3856  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3857  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3858  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3859:
    // 004f3859  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f385d  e9dafdffff             -jmp 0x4f363c
    goto L_0x004f363c;
L_0x004f3862:
    // 004f3862  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 004f3865  7463                   -je 0x4f38ca
    if (cpu.flags.zf)
    {
        goto L_0x004f38ca;
    }
    // 004f3867  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f386c  b9ff030000             -mov ecx, 0x3ff
    cpu.ecx = 1023 /*0x3ff*/;
    // 004f3871  e8dafaffff             -call 0x4f3350
    cpu.esp -= 4;
    sub_4f3350(app, cpu);
    if (cpu.terminate) return;
    // 004f3876  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x004f387a:
    // 004f387a  e831fbffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f387f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3881  e82afbffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f3886  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3888  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004f388b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f388d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004f388f  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004f3892  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3894  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f3898  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f389b  8a742408               -mov dh, byte ptr [esp + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f389f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f38a1  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004f38a4  0f8492fdffff           -je 0x4f363c
    if (cpu.flags.zf)
    {
        goto L_0x004f363c;
    }
    // 004f38aa  e801fbffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f38af  b938219f00             -mov ecx, 0x9f2138
    cpu.ecx = 10428728 /*0x9f2138*/;
    // 004f38b4  83e840                 +sub eax, 0x40
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f38b7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f38bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f38bc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f38be  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f38c0  e85bfbffff             -call 0x4f3420
    cpu.esp -= 4;
    sub_4f3420(app, cpu);
    if (cpu.terminate) return;
    // 004f38c5  e98ffdffff             -jmp 0x4f3659
    goto L_0x004f3659;
L_0x004f38ca:
    // 004f38ca  a13c259f00             -mov eax, dword ptr [0x9f253c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */);
    // 004f38cf  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004f38d2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f38d6  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004f38db  e870faffff             -call 0x4f3350
    cpu.esp -= 4;
    sub_4f3350(app, cpu);
    if (cpu.terminate) return;
    // 004f38e0  eb98                   -jmp 0x4f387a
    goto L_0x004f387a;
L_0x004f38e2:
    // 004f38e2  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f38e7  b838219f00             -mov eax, 0x9f2138
    cpu.eax = 10428728 /*0x9f2138*/;
    // 004f38ec  e8ccd30100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f38f1  e963fdffff             -jmp 0x4f3659
    goto L_0x004f3659;
L_0x004f38f6:
    // 004f38f6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f38fb  b858219f00             -mov eax, 0x9f2158
    cpu.eax = 10428760 /*0x9f2158*/;
    // 004f3900  e8b8d30100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f3905  e977fdffff             -jmp 0x4f3681
    goto L_0x004f3681;
L_0x004f390a:
    // 004f390a  e8a1faffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f390f  b958219f00             -mov ecx, 0x9f2158
    cpu.ecx = 10428760 /*0x9f2158*/;
    // 004f3914  83e840                 +sub eax, 0x40
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3917  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f391b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f391c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f391e  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f3921  e8fafaffff             -call 0x4f3420
    cpu.esp -= 4;
    sub_4f3420(app, cpu);
    if (cpu.terminate) return;
    // 004f3926  e956fdffff             -jmp 0x4f3681
    goto L_0x004f3681;
L_0x004f392b:
    // 004f392b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f3930  b838239f00             -mov eax, 0x9f2338
    cpu.eax = 10429240 /*0x9f2338*/;
    // 004f3935  e883d30100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f393a  e96afdffff             -jmp 0x4f36a9
    goto L_0x004f36a9;
L_0x004f393f:
    // 004f393f  e86cfaffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f3944  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004f3947  b938239f00             -mov ecx, 0x9f2338
    cpu.ecx = 10429240 /*0x9f2338*/;
    // 004f394c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f394d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f394f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3953  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004f3956  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f3958  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f395a  e8c1faffff             -call 0x4f3420
    cpu.esp -= 4;
    sub_4f3420(app, cpu);
    if (cpu.terminate) return;
    // 004f395f  e945fdffff             -jmp 0x4f36a9
    goto L_0x004f36a9;
L_0x004f3964:
    // 004f3964  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f3969  b858239f00             -mov eax, 0x9f2358
    cpu.eax = 10429272 /*0x9f2358*/;
    // 004f396e  e84ad30100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f3973  e959fdffff             -jmp 0x4f36d1
    goto L_0x004f36d1;
L_0x004f3978:
    // 004f3978  e833faffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f397d  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004f3980  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f3981  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f3983  b958239f00             -mov ecx, 0x9f2358
    cpu.ecx = 10429272 /*0x9f2358*/;
    // 004f3988  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004f398b  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f398f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3991  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f3993  83c010                 +add eax, 0x10
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
    // 004f3996  e885faffff             -call 0x4f3420
    cpu.esp -= 4;
    sub_4f3420(app, cpu);
    if (cpu.terminate) return;
    // 004f399b  e931fdffff             -jmp 0x4f36d1
    goto L_0x004f36d1;
L_0x004f39a0:
    // 004f39a0  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004f39a5  b8380e9f00             -mov eax, 0x9f0e38
    cpu.eax = 10423864 /*0x9f0e38*/;
    // 004f39aa  e80ed30100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f39af  e945fdffff             -jmp 0x4f36f9
    goto L_0x004f36f9;
L_0x004f39b4:
    // 004f39b4  e8f7f9ffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f39b9  b9380e9f00             -mov ecx, 0x9f0e38
    cpu.ecx = 10423864 /*0x9f0e38*/;
    // 004f39be  83e840                 +sub eax, 0x40
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f39c1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f39c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f39c7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f39c9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f39cb  e820fbffff             -call 0x4f34f0
    cpu.esp -= 4;
    sub_4f34f0(app, cpu);
    if (cpu.terminate) return;
    // 004f39d0  e924fdffff             -jmp 0x4f36f9
    goto L_0x004f36f9;
L_0x004f39d5:
    // 004f39d5  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004f39da  b8380f9f00             -mov eax, 0x9f0f38
    cpu.eax = 10424120 /*0x9f0f38*/;
    // 004f39df  e8d9d20100             -call 0x510cbd
    cpu.esp -= 4;
    sub_510cbd(app, cpu);
    if (cpu.terminate) return;
    // 004f39e4  e938fdffff             -jmp 0x4f3721
    goto L_0x004f3721;
L_0x004f39e9:
    // 004f39e9  e8c2f9ffff             -call 0x4f33b0
    cpu.esp -= 4;
    sub_4f33b0(app, cpu);
    if (cpu.terminate) return;
    // 004f39ee  b9380f9f00             -mov ecx, 0x9f0f38
    cpu.ecx = 10424120 /*0x9f0f38*/;
    // 004f39f3  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004f39f6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f39f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f39f9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f39fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f39fd  e8eefaffff             -call 0x4f34f0
    cpu.esp -= 4;
    sub_4f34f0(app, cpu);
    if (cpu.terminate) return;
    // 004f3a02  e91afdffff             -jmp 0x4f3721
    goto L_0x004f3721;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f3a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3a11  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f3a13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3a15  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3a18  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3a1a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3a1d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3a1f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3a22  8d504c                 -lea edx, [eax + 0x4c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f3a25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f3a27  e8e4d70100             -call 0x511210
    cpu.esp -= 4;
    sub_511210(app, cpu);
    if (cpu.terminate) return;
    // 004f3a2c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3a2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3a32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a33  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3a35  e8d6ffffff             -call 0x4f3a10
    cpu.esp -= 4;
    sub_4f3a10(app, cpu);
    if (cpu.terminate) return;
    // 004f3a3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f3a3f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3a41  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004f3a44  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f3a46  e8f5bffdff             -call 0x4cfa40
    cpu.esp -= 4;
    sub_4cfa40(app, cpu);
    if (cpu.terminate) return;
    // 004f3a4b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f3a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f3a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a61  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3a63  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3a65  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f3a67  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f3a69  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3a6d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f3a6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a70  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f3a74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a75  e872050000             -call 0x4f3fec
    cpu.esp -= 4;
    sub_4f3fec(app, cpu);
    if (cpu.terminate) return;
    // 004f3a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a7b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f3a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3a81  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f3a83  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f3a85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3a87  e8cc070000             -call 0x4f4258
    cpu.esp -= 4;
    sub_4f4258(app, cpu);
    if (cpu.terminate) return;
    // 004f3a8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f3a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3a91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f3a93:
    // 004f3a93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3a95  42                     -inc edx
    (cpu.edx)++;
    // 004f3a96  e825090000             -call 0x4f43c0
    cpu.esp -= 4;
    sub_4f43c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3a9b  83fa10                 +cmp edx, 0x10
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
    // 004f3a9e  7cf3                   -jl 0x4f3a93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3a93;
    }
    // 004f3aa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3aa2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3aa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3aa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3aa4  83f810                 +cmp eax, 0x10
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
    // 004f3aa7  7d0c                   -jge 0x4f3ab5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3aab  7c08                   -jl 0x4f3ab5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aad  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3ab4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ab5:
    // 004f3ab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ab5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f3ab5;
    // 004f3aa4  83f810                 +cmp eax, 0x10
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
    // 004f3aa7  7d0c                   -jge 0x4f3ab5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3aab  7c08                   -jl 0x4f3ab5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aad  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3ab4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ab5:
L_entry_0x004f3ab5:
    // 004f3ab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ab8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ab9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3abb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3abc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3abd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3abe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3ac1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f3ac4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3ac9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3acb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3acd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3acf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f3ad3  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3ada:
    // 004f3ada  0fbe7016               -movsx esi, byte ptr [eax + 0x16]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
    // 004f3ade  39f2                   +cmp edx, esi
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
    // 004f3ae0  7d3a                   -jge 0x4f3b1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3b1c;
    }
    // 004f3ae2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3ae4  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3ae6  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3ae9  3b3c24                 +cmp edi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3aec  7506                   -jne 0x4f3af4
    if (!cpu.flags.zf)
    {
        goto L_0x004f3af4;
    }
L_0x004f3aee:
    // 004f3aee  83c52c                 +add ebp, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3af1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f3af2  ebe6                   -jmp 0x4f3ada
    goto L_0x004f3ada;
L_0x004f3af4:
    // 004f3af4  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3af8  39d7                   +cmp edi, edx
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
    // 004f3afa  7507                   -jne 0x4f3b03
    if (!cpu.flags.zf)
    {
        goto L_0x004f3b03;
    }
    // 004f3afc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b00  884817                 -mov byte ptr [eax + 0x17], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */) = cpu.cl;
L_0x004f3b03:
    // 004f3b03  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3b05  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004f3b0a  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3b0c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3b0e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b12  46                     -inc esi
    (cpu.esi)++;
    // 004f3b13  83c32c                 +add ebx, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3b16  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004f3b1a  ebd2                   -jmp 0x4f3aee
    goto L_0x004f3aee;
L_0x004f3b1c:
    // 004f3b1c  8a5016                 -mov dl, byte ptr [eax + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004f3b1f  fe4816                 -dec byte ptr [eax + 0x16]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */))--;
    // 004f3b22  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b25  3a5016                 +cmp dl, byte ptr [eax + 0x16]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3b28  7f0a                   -jg 0x4f3b34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3b34;
    }
    // 004f3b2a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3b34:
    // 004f3b34  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b37  fe4817                 -dec byte ptr [eax + 0x17]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */))--;
    // 004f3b3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f3b31;
    // 004f3ab8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ab9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3abb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3abc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3abd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3abe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3ac1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f3ac4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3ac9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3acb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3acd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3acf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f3ad3  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3ada:
    // 004f3ada  0fbe7016               -movsx esi, byte ptr [eax + 0x16]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
    // 004f3ade  39f2                   +cmp edx, esi
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
    // 004f3ae0  7d3a                   -jge 0x4f3b1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3b1c;
    }
    // 004f3ae2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3ae4  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3ae6  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3ae9  3b3c24                 +cmp edi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3aec  7506                   -jne 0x4f3af4
    if (!cpu.flags.zf)
    {
        goto L_0x004f3af4;
    }
L_0x004f3aee:
    // 004f3aee  83c52c                 +add ebp, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3af1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f3af2  ebe6                   -jmp 0x4f3ada
    goto L_0x004f3ada;
L_0x004f3af4:
    // 004f3af4  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3af8  39d7                   +cmp edi, edx
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
    // 004f3afa  7507                   -jne 0x4f3b03
    if (!cpu.flags.zf)
    {
        goto L_0x004f3b03;
    }
    // 004f3afc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b00  884817                 -mov byte ptr [eax + 0x17], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */) = cpu.cl;
L_0x004f3b03:
    // 004f3b03  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3b05  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004f3b0a  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3b0c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3b0e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b12  46                     -inc esi
    (cpu.esi)++;
    // 004f3b13  83c32c                 +add ebx, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3b16  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004f3b1a  ebd2                   -jmp 0x4f3aee
    goto L_0x004f3aee;
L_0x004f3b1c:
    // 004f3b1c  8a5016                 -mov dl, byte ptr [eax + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004f3b1f  fe4816                 -dec byte ptr [eax + 0x16]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */))--;
    // 004f3b22  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b25  3a5016                 +cmp dl, byte ptr [eax + 0x16]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3b28  7f0a                   -jg 0x4f3b34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3b34;
    }
    // 004f3b2a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004f3b31:
    // 004f3b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3b34:
    // 004f3b34  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b37  fe4817                 -dec byte ptr [eax + 0x17]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */))--;
    // 004f3b3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3b44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3b45  8d50f4                 -lea edx, [eax - 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-12) /* -0xc */);
    // 004f3b48  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f3b4a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3b4f  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3b56  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3b59  e862c8fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3b5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3b62  8b8089259f00           -mov eax, dword ptr [eax + 0x9f2589]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429833) /* 0x9f2589 */);
    // 004f3b68  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004f3b6b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3b6d  8b1c854c259f00         -mov ebx, dword ptr [eax*4 + 0x9f254c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3b74:
    // 004f3b74  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3b76  3b501c                 +cmp edx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3b79  7607                   -jbe 0x4f3b82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f3b82;
    }
    // 004f3b7b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f3b7d  2b481c                 -sub ecx, dword ptr [eax + 0x1c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004f3b80  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f3b82:
    // 004f3b82  015014                 -add dword ptr [eax + 0x14], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3b85  29501c                 -sub dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3b88  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f3b8b  3b5018                 +cmp edx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3b8e  7208                   -jb 0x4f3b98
    if (cpu.flags.cf)
    {
        goto L_0x004f3b98;
    }
    // 004f3b90  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3b93  e820ffffff             -call 0x4f3ab8
    cpu.esp -= 4;
    sub_4f3ab8(app, cpu);
    if (cpu.terminate) return;
L_0x004f3b98:
    // 004f3b98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f3b9a  7495                   -je 0x4f3b31
    if (cpu.flags.zf)
    {
        return sub_4f3b31(app, cpu);
    }
    // 004f3b9c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f3b9e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f3ba0  ebd2                   -jmp 0x4f3b74
    goto L_0x004f3b74;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f3ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ba5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3ba6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3ba7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3ba8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3ba9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3bac  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f3bae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f3bb0  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3bb4  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004f3bbb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004f3bbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3bc0  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004f3bc2  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004f3bc5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3bc8  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3bcc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3bce  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f3bd0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f3bd3  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f3bd6  8d7d20                 -lea edi, [ebp + 0x20]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f3bd9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3bdd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f3bdf  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3be3  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f3be6  e8eddd0100             -call 0x5119d8
    cpu.esp -= 4;
    sub_5119d8(app, cpu);
    if (cpu.terminate) return;
    // 004f3beb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f3bee  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3bf2  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f3bf5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f3bf7  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f3bfa  e8c1c7fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3bff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f3c01  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f3c04  e8e7df0100             -call 0x511bf0
    cpu.esp -= 4;
    sub_511bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f3c09  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f3c0c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f3c11  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f3c14  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f3c16  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004f3c18  7405                   -je 0x4f3c1f
    if (cpu.flags.zf)
    {
        goto L_0x004f3c1f;
    }
    // 004f3c1a  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3c1c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f3c1f:
    // 004f3c1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3c21  7445                   -je 0x4f3c68
    if (cpu.flags.zf)
    {
        goto L_0x004f3c68;
    }
L_0x004f3c23:
    // 004f3c23  66837d1c00             +cmp word ptr [ebp + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3c28  755b                   -jne 0x4f3c85
    if (!cpu.flags.zf)
    {
        goto L_0x004f3c85;
    }
    // 004f3c2a  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f3c2d  8d7d24                 -lea edi, [ebp + 0x24]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c30  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004f3c33  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f3c36  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3c37  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3c38  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004f3c39:
    // 004f3c39  807d1401               +cmp byte ptr [ebp + 0x14], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3c3d  741e                   -je 0x4f3c5d
    if (cpu.flags.zf)
    {
        goto L_0x004f3c5d;
    }
    // 004f3c3f  8d4d3c                 -lea ecx, [ebp + 0x3c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */);
    // 004f3c42  8d5d24                 -lea ebx, [ebp + 0x24]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c45  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f3c48  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f3c4b  e880d60100             -call 0x5112d0
    cpu.esp -= 4;
    sub_5112d0(app, cpu);
    if (cpu.terminate) return;
    // 004f3c50  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3c53  837d0800               +cmp dword ptr [ebp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3c57  7c32                   -jl 0x4f3c8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3c8b;
    }
    // 004f3c59  c6451401               -mov byte ptr [ebp + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x004f3c5d:
    // 004f3c5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3c5f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3c62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3c68:
    // 004f3c68  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f3c6d  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3c71  8d7524                 -lea esi, [ebp + 0x24]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c74  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f3c76  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004f3c78  7405                   -je 0x4f3c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f3c7f;
    }
    // 004f3c7a  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3c7c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f3c7f:
    // 004f3c7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3c81  75a0                   -jne 0x4f3c23
    if (!cpu.flags.zf)
    {
        goto L_0x004f3c23;
    }
    // 004f3c83  ebb4                   -jmp 0x4f3c39
    goto L_0x004f3c39;
L_0x004f3c85:
    // 004f3c85  c6451402               -mov byte ptr [ebp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
    // 004f3c89  ebd2                   -jmp 0x4f3c5d
    goto L_0x004f3c5d;
L_0x004f3c8b:
    // 004f3c8b  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f3c90  bbc0cc5400             -mov ebx, 0x54ccc0
    cpu.ebx = 5557440 /*0x54ccc0*/;
    // 004f3c95  be15010000             -mov esi, 0x115
    cpu.esi = 277 /*0x115*/;
    // 004f3c9a  68d8cc5400             -push 0x54ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557464 /*0x54ccd8*/;
    cpu.esp -= 4;
    // 004f3c9f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f3ca5  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f3cab  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f3cb1  e85ad3f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3cb6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3cb9  c6451401               -mov byte ptr [ebp + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004f3cbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3cbf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3cc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3cc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3cc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3cc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3cca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3ccc  8d5a08                 -lea ebx, [edx + 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f3ccf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3cd2  e8e9c6fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3cd7  0fbe5117               -movsx edx, byte ptr [ecx + 0x17]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */)));
    // 004f3cdb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3ce2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3ce4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3ce7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3ce9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3cec  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f3cee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3cf0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3cf2  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004f3cf5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3cfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f3d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3d01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3d02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3d03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3d06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f3d08  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f3d0b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f3d0f  8d420c                 -lea eax, [edx + 0xc]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f3d12  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f3d16  0fbe4b17               -movsx ecx, byte ptr [ebx + 0x17]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */)));
    // 004f3d1a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004f3d21  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3d23  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3d26  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3d28  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3d2b  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3d2d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3d2f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f3d32  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f3d34  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3d38  01411c                 -add dword ptr [ecx + 0x1c], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3d3b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f3d3e  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 004f3d41  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004f3d44  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004f3d46  e889d70100             -call 0x5114d4
    cpu.esp -= 4;
    sub_5114d4(app, cpu);
    if (cpu.terminate) return;
    // 004f3d4b  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f3d4e  83790c00               +cmp dword ptr [ecx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3d52  7c12                   -jl 0x4f3d66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3d66;
    }
L_0x004f3d54:
    // 004f3d54  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 004f3d58  7c3f                   -jl 0x4f3d99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3d99;
    }
    // 004f3d5a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3d5f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3d62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3d66:
    // 004f3d66  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f3d6b  b814cd5400             -mov eax, 0x54cd14
    cpu.eax = 5557524 /*0x54cd14*/;
    // 004f3d70  ba58010000             -mov edx, 0x158
    cpu.edx = 344 /*0x158*/;
    // 004f3d75  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f3d7b  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f3d80  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f3d86  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f3d89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f3d8a  6828cd5400             -push 0x54cd28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557544 /*0x54cd28*/;
    cpu.esp -= 4;
    // 004f3d8f  e87cd2f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3d94  83c408                 +add esp, 8
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
    // 004f3d97  ebbb                   -jmp 0x4f3d54
    goto L_0x004f3d54;
L_0x004f3d99:
    // 004f3d99  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f3d9c  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3d9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3da4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3da7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3da8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3da9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3daa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3dac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3dad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3daf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3db2  e809c6fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3db7  8a4117                 -mov al, byte ptr [ecx + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 004f3dba  fe4117                 -inc byte ptr [ecx + 0x17]
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */))++;
    // 004f3dbd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3dc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3dc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3dc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3dc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3dc6  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f3dc8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f3dcd  81fb5343446c           +cmp ebx, 0x6c444353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816413011 /*0x6c444353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3dd3  7424                   -je 0x4f3df9
    if (cpu.flags.zf)
    {
        goto L_0x004f3df9;
    }
    // 004f3dd5  81fb5343486c           +cmp ebx, 0x6c484353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816675155 /*0x6c484353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3ddb  7423                   -je 0x4f3e00
    if (cpu.flags.zf)
    {
        goto L_0x004f3e00;
    }
    // 004f3ddd  81fb5343456c           +cmp ebx, 0x6c454353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816478547 /*0x6c454353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3de3  7422                   -je 0x4f3e07
    if (cpu.flags.zf)
    {
        goto L_0x004f3e07;
    }
    // 004f3de5  81fb5343436c           +cmp ebx, 0x6c434353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816347475 /*0x6c434353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3deb  7521                   -jne 0x4f3e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e0e;
    }
    // 004f3ded  e8d6feffff             -call 0x4f3cc8
    cpu.esp -= 4;
    sub_4f3cc8(app, cpu);
    if (cpu.terminate) return;
L_0x004f3df2:
    // 004f3df2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3df4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f3df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3df8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3df9:
    // 004f3df9  e802ffffff             -call 0x4f3d00
    cpu.esp -= 4;
    sub_4f3d00(app, cpu);
    if (cpu.terminate) return;
    // 004f3dfe  ebf2                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e00:
    // 004f3e00  e89ffdffff             -call 0x4f3ba4
    cpu.esp -= 4;
    sub_4f3ba4(app, cpu);
    if (cpu.terminate) return;
    // 004f3e05  ebeb                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e07:
    // 004f3e07  e8a0ffffff             -call 0x4f3dac
    cpu.esp -= 4;
    sub_4f3dac(app, cpu);
    if (cpu.terminate) return;
    // 004f3e0c  ebe4                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e0e:
    // 004f3e0e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3e11  e8aac5fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3e16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f3e18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3e1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3e1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3e1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3e1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3e1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f3e21  0fbe5017               -movsx edx, byte ptr [eax + 0x17]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3e25  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3e2c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e2e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e31  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e33  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3e35  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e38  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3e3a  83791000               +cmp dword ptr [ecx + 0x10], 0
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
    // 004f3e3e  740e                   -je 0x4f3e4e
    if (cpu.flags.zf)
    {
        goto L_0x004f3e4e;
    }
    // 004f3e40  6683792800             +cmp word ptr [ecx + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3e45  7c0d                   -jl 0x4f3e54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3e54;
    }
    // 004f3e47  6683792800             +cmp word ptr [ecx + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3e4c  750f                   -jne 0x4f3e5d
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e5d;
    }
L_0x004f3e4e:
    // 004f3e4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3e50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3e54:
    // 004f3e54  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3e59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3e5d:
    // 004f3e5d  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f3e60  e8fbc5fdff             -call 0x4d0460
    cpu.esp -= 4;
    sub_4d0460(app, cpu);
    if (cpu.terminate) return;
    // 004f3e65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3e67  3d00093d00             +cmp eax, 0x3d0900
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000000 /*0x3d0900*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3e6c  7605                   -jbe 0x4f3e73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f3e73;
    }
    // 004f3e6e  ba00093d00             -mov edx, 0x3d0900
    cpu.edx = 4000000 /*0x3d0900*/;
L_0x004f3e73:
    // 004f3e73  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3e7a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e7c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3e7f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e81  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3e84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3e86  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e89  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e8d  f77110                 -div dword ptr [ecx + 0x10]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004f3e90  0fbf5128               -movsx edx, word ptr [ecx + 0x28]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
    // 004f3e94  39d0                   +cmp eax, edx
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
    // 004f3e96  720c                   -jb 0x4f3ea4
    if (cpu.flags.cf)
    {
        goto L_0x004f3ea4;
    }
    // 004f3e98  66c741280000           -mov word ptr [ecx + 0x28], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004f3e9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ea0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ea4:
    // 004f3ea4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f3ea7  e8e4c5fdff             -call 0x4d0490
    cpu.esp -= 4;
    sub_4d0490(app, cpu);
    if (cpu.terminate) return;
    // 004f3eac  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3eae  75a4                   -jne 0x4f3e54
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e54;
    }
    // 004f3eb0  66c741280000           -mov word ptr [ecx + 0x28], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004f3eb6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3eb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ebc  e8af510000             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004f3ec1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3ec3  0f85ecfbffff           -jne 0x4f3ab5
    if (!cpu.flags.zf)
    {
        return sub_4f3ab5(app, cpu);
    }
    // 004f3ec9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3eca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3ecb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3ecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ecd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004f3ecf:
    // 004f3ecf  8bb74c259f00           -mov esi, dword ptr [edi + 0x9f254c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429772) /* 0x9f254c */);
    // 004f3ed5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f3ed7  7406                   -je 0x4f3edf
    if (cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3ed9  807e1600               +cmp byte ptr [esi + 0x16], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3edd  750f                   -jne 0x4f3eee
    if (!cpu.flags.zf)
    {
        goto L_0x004f3eee;
    }
L_0x004f3edf:
    // 004f3edf  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3ee2  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3ee5  75e8                   -jne 0x4f3ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3ecf;
    }
    // 004f3ee7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ee9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3eee:
    // 004f3eee  807e1402               +cmp byte ptr [esi + 0x14], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3ef2  7538                   -jne 0x4f3f2c
    if (!cpu.flags.zf)
    {
        goto L_0x004f3f2c;
    }
    // 004f3ef4  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3ef7  e884d70100             -call 0x511680
    cpu.esp -= 4;
    sub_511680(app, cpu);
    if (cpu.terminate) return;
    // 004f3efc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3efe  7fdf                   -jg 0x4f3edf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3edf;
    }
    // 004f3f00  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f3f03  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f3f06  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3f09  8d4e3c                 -lea ecx, [esi + 0x3c]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004f3f0c  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f3f0f  8d561c                 -lea edx, [esi + 0x1c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f3f12  e805d90100             -call 0x51181c
    cpu.esp -= 4;
    sub_51181c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f17  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3f1a  e8b1d30100             -call 0x5112d0
    cpu.esp -= 4;
    sub_5112d0(app, cpu);
    if (cpu.terminate) return;
    // 004f3f1f  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3f22  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004f3f26  7c5d                   -jl 0x4f3f85
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3f85;
    }
L_0x004f3f28:
    // 004f3f28  c6461401               -mov byte ptr [esi + 0x14], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x004f3f2c:
    // 004f3f2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f3f2e  e8e9feffff             -call 0x4f3e1c
    cpu.esp -= 4;
    sub_4f3e1c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3f35  75a8                   -jne 0x4f3edf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3f37  807e1401               +cmp byte ptr [esi + 0x14], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3f3b  0f8476000000           -je 0x4f3fb7
    if (cpu.flags.zf)
    {
        goto L_0x004f3fb7;
    }
    // 004f3f41  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
L_0x004f3f46:
    // 004f3f46  e8d5ce0000             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004f3f4b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f3f4d:
    // 004f3f4d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3f50  49                     -dec ecx
    (cpu.ecx)--;
    // 004f3f51  e8aac3fdff             -call 0x4d0300
    cpu.esp -= 4;
    sub_4d0300(app, cpu);
    if (cpu.terminate) return;
    // 004f3f56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3f58  740b                   -je 0x4f3f65
    if (cpu.flags.zf)
    {
        goto L_0x004f3f65;
    }
    // 004f3f5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3f5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f3f5e  e861feffff             -call 0x4f3dc4
    cpu.esp -= 4;
    sub_4f3dc4(app, cpu);
    if (cpu.terminate) return;
    // 004f3f63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f3f65:
    // 004f3f65  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f3f67  7404                   -je 0x4f3f6d
    if (cpu.flags.zf)
    {
        goto L_0x004f3f6d;
    }
    // 004f3f69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f3f6b  7fe0                   -jg 0x4f3f4d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3f4d;
    }
L_0x004f3f6d:
    // 004f3f6d  e80acf0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f72  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3f75  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3f78  0f8551ffffff           -jne 0x4f3ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3ecf;
    }
    // 004f3f7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3f80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3f85:
    // 004f3f85  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f3f8a  bb5ccd5400             -mov ebx, 0x54cd5c
    cpu.ebx = 5557596 /*0x54cd5c*/;
    // 004f3f8f  b835020000             -mov eax, 0x235
    cpu.eax = 565 /*0x235*/;
    // 004f3f94  6874cd5400             -push 0x54cd74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557620 /*0x54cd74*/;
    cpu.esp -= 4;
    // 004f3f99  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f3f9f  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f3fa5  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f3faa  e861d0f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3faf  83c404                 +add esp, 4
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
    // 004f3fb2  e971ffffff             -jmp 0x4f3f28
    goto L_0x004f3f28;
L_0x004f3fb7:
    // 004f3fb7  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3fba  e8f9d50100             -call 0x5115b8
    cpu.esp -= 4;
    sub_5115b8(app, cpu);
    if (cpu.terminate) return;
    // 004f3fbf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3fc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3fc3  0f8416ffffff           -je 0x4f3edf
    if (cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3fc9  e978ffffff             -jmp 0x4f3f46
    goto L_0x004f3f46;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f3fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3fd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3fd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3fd5:
    // 004f3fd5  83b84c259f0000         +cmp dword ptr [eax + 0x9f254c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429772) /* 0x9f254c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3fdc  7401                   -je 0x4f3fdf
    if (cpu.flags.zf)
    {
        goto L_0x004f3fdf;
    }
    // 004f3fde  42                     -inc edx
    (cpu.edx)++;
L_0x004f3fdf:
    // 004f3fdf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3fe2  83f840                 +cmp eax, 0x40
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
    // 004f3fe5  75ee                   -jne 0x4f3fd5
    if (!cpu.flags.zf)
    {
        goto L_0x004f3fd5;
    }
    // 004f3fe7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3fe9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3fea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3fec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3fec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3fed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3fee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3fef  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3ff2  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f3ff6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f3ffa  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f3ffe  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f4000  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004f4007  0f847e010000           -je 0x4f418b
    if (cpu.flags.zf)
    {
        goto L_0x004f418b;
    }
    // 004f400d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f400f  7e08                   -jle 0x4f4019
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4019;
    }
    // 004f4011  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4017  7c32                   -jl 0x4f404b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f404b;
    }
L_0x004f4019:
    // 004f4019  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f401e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4022  b8accd5400             -mov eax, 0x54cdac
    cpu.eax = 5557676 /*0x54cdac*/;
    // 004f4027  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4028  ba80020000             -mov edx, 0x280
    cpu.edx = 640 /*0x280*/;
    // 004f402d  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f4033  68c0cd5400             -push 0x54cdc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557696 /*0x54cdc0*/;
    cpu.esp -= 4;
    // 004f4038  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f403d  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f4043  e8c8cff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4048  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004f404b:
    // 004f404b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f404d  752d                   -jne 0x4f407c
    if (!cpu.flags.zf)
    {
        goto L_0x004f407c;
    }
    // 004f404f  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f4054  b8accd5400             -mov eax, 0x54cdac
    cpu.eax = 5557676 /*0x54cdac*/;
    // 004f4059  ba85020000             -mov edx, 0x285
    cpu.edx = 645 /*0x285*/;
    // 004f405e  6810ce5400             -push 0x54ce10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557776 /*0x54ce10*/;
    cpu.esp -= 4;
    // 004f4063  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f4069  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f406e  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f4074  e897cff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4079  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f407c:
    // 004f407c  8b0d4c259f00           -mov ecx, dword ptr [0x9f254c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */);
    // 004f4082  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4084  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4086  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4088  7416                   -je 0x4f40a0
    if (cpu.flags.zf)
    {
        goto L_0x004f40a0;
    }
L_0x004f408a:
    // 004f408a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f408d  42                     -inc edx
    (cpu.edx)++;
    // 004f408e  83f840                 +cmp eax, 0x40
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
    // 004f4091  0f8d02010000           -jge 0x4f4199
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4199;
    }
    // 004f4097  83b84c259f0000         +cmp dword ptr [eax + 0x9f254c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429772) /* 0x9f254c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f409e  75ea                   -jne 0x4f408a
    if (!cpu.flags.zf)
    {
        goto L_0x004f408a;
    }
L_0x004f40a0:
    // 004f40a0  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f40a4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f40a8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f40af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f40b1  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004f40b3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f40b6  83ef4c                 -sub edi, 0x4c
    (cpu.edi) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f40b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f40bb  83c64c                 -add esi, 0x4c
    (cpu.esi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f40be  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f40c1  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 004f40c4  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f40c6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f40c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f40ca  e841d10100             -call 0x511210
    cpu.esp -= 4;
    sub_511210(app, cpu);
    if (cpu.terminate) return;
    // 004f40cf  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004f40d2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f40d4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f40d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f40d8  b9603b4f00             -mov ecx, 0x4f3b60
    cpu.ecx = 5192544 /*0x4f3b60*/;
    // 004f40dd  e82ed10100             -call 0x511210
    cpu.esp -= 4;
    sub_511210(app, cpu);
    if (cpu.terminate) return;
    // 004f40e2  bb443b4f00             -mov ebx, 0x4f3b44
    cpu.ebx = 5192516 /*0x4f3b44*/;
    // 004f40e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f40e9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f40ec  e837d10100             -call 0x511228
    cpu.esp -= 4;
    sub_511228(app, cpu);
    if (cpu.terminate) return;
    // 004f40f1  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f40f4  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f40f8  0f8ca9000000           -jl 0x4f41a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f41a7;
    }
    // 004f40fe  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f4101  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4105  88908c259f00           -mov byte ptr [eax + 0x9f258c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10429836) /* 0x9f258c */) = cpu.dl;
    // 004f410b  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 004f4110  0f84d0000000           -je 0x4f41e6
    if (cpu.flags.zf)
    {
        goto L_0x004f41e6;
    }
    // 004f4116  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f4118  0f8c95000000           -jl 0x4f41b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f41b3;
    }
L_0x004f411e:
    // 004f411e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f4122  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4125  c6451801               -mov byte ptr [ebp + 0x18], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
L_0x004f4129:
    // 004f4129  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f4130  c74508ffffffff         -mov dword ptr [ebp + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f4137  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f413b  884515                 -mov byte ptr [ebp + 0x15], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004f413e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4142  8d7d3c                 -lea edi, [ebp + 0x3c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */);
    // 004f4145  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4146  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4147  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4148  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4149  e882feffff             -call 0x4f3fd0
    cpu.esp -= 4;
    sub_4f3fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f414e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4150  751c                   -jne 0x4f416e
    if (!cpu.flags.zf)
    {
        goto L_0x004f416e;
    }
    // 004f4152  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f4157  b8bc3e4f00             -mov eax, 0x4f3ebc
    cpu.eax = 5193404 /*0x4f3ebc*/;
    // 004f415c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f415e  be903a4f00             -mov esi, 0x4f3a90
    cpu.esi = 5192336 /*0x4f3a90*/;
    // 004f4163  e8b833ffff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 004f4168  8935309ba000           -mov dword ptr [0xa09b30], esi
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.esi;
L_0x004f416e:
    // 004f416e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4172  892c854c259f00         -mov dword ptr [eax*4 + 0x9f254c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4) = cpu.ebp;
    // 004f4179  e8c2020000             -call 0x4f4440
    cpu.esp -= 4;
    sub_4f4440(app, cpu);
    if (cpu.terminate) return;
    // 004f417e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4182  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4185  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4186  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4187  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4188  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f418b:
    // 004f418b  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f4190  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4193  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4194  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4195  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4196  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f4199:
    // 004f4199  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 004f419e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f41a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f41a7:
    // 004f41a7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f41aa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f41ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41b0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f41b3:
    // 004f41b3  bab4cc5400             -mov edx, 0x54ccb4
    cpu.edx = 5557428 /*0x54ccb4*/;
    // 004f41b8  b9accd5400             -mov ecx, 0x54cdac
    cpu.ecx = 5557676 /*0x54cdac*/;
    // 004f41bd  bbb5020000             -mov ebx, 0x2b5
    cpu.ebx = 693 /*0x2b5*/;
    // 004f41c2  6834ce5400             -push 0x54ce34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557812 /*0x54ce34*/;
    cpu.esp -= 4;
    // 004f41c7  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f41cd  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f41d3  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f41d9  e832cef0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f41de  83c404                 +add esp, 4
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
    // 004f41e1  e938ffffff             -jmp 0x4f411e
    goto L_0x004f411e;
L_0x004f41e6:
    // 004f41e6  81ff00600000           +cmp edi, 0x6000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24576 /*0x6000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f41ec  7d2d                   -jge 0x4f421b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f421b;
    }
    // 004f41ee  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f41f3  bbaccd5400             -mov ebx, 0x54cdac
    cpu.ebx = 5557676 /*0x54cdac*/;
    // 004f41f8  b8c2020000             -mov eax, 0x2c2
    cpu.eax = 706 /*0x2c2*/;
    // 004f41fd  6834ce5400             -push 0x54ce34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557812 /*0x54ce34*/;
    cpu.esp -= 4;
    // 004f4202  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f4208  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f420e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f4213  e8f8cdf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4218  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f421b:
    // 004f421b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f421f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f4224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4225  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f4227  40                     -inc eax
    (cpu.eax)++;
    // 004f4228  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f422a  e851b8fdff             -call 0x4cfa80
    cpu.esp -= 4;
    sub_4cfa80(app, cpu);
    if (cpu.terminate) return;
    // 004f422f  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4232  c6451800               -mov byte ptr [ebp + 0x18], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f4236  e8c5c2fdff             -call 0x4d0500
    cpu.esp -= 4;
    sub_4d0500(app, cpu);
    if (cpu.terminate) return;
    // 004f423b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f423d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004f4242  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f4245  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f4247  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f424a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f424c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f424e  e84dda0100             -call 0x511ca0
    cpu.esp -= 4;
    sub_511ca0(app, cpu);
    if (cpu.terminate) return;
    // 004f4253  e9d1feffff             -jmp 0x4f4129
    goto L_0x004f4129;
}

/* align: skip  */
void Application::sub_4f4258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4258  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4259  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f425a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f425b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f425e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4262  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f4265  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f4267  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f4269  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f426d  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004f4274  750e                   -jne 0x4f4284
    if (!cpu.flags.zf)
    {
        goto L_0x004f4284;
    }
    // 004f4276  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f427b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f427e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f427f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4280  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4281  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4284:
    // 004f4284  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4288  e817f8ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f428d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f428f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f4291  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4293  750e                   -jne 0x4f42a3
    if (!cpu.flags.zf)
    {
        goto L_0x004f42a3;
    }
    // 004f4295  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f429a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f429d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f429e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f429f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f42a0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f42a3:
    // 004f42a3  e878cb0000             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004f42a8  8a4216                 -mov al, byte ptr [edx + 0x16]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 004f42ab  3a4215                 +cmp al, byte ptr [edx + 0x15]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f42ae  0f8dae000000           -jge 0x4f4362
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4362;
    }
    // 004f42b4  0fbe4216               -movsx eax, byte ptr [edx + 0x16]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */)));
    // 004f42b8  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004f42bf  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f42c1  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f42c4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f42c6  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004f42cd  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f42cf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f42d1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f42d3  0f859c000000           -jne 0x4f4375
    if (!cpu.flags.zf)
    {
        goto L_0x004f4375;
    }
    // 004f42d9  b95343456c             -mov ecx, 0x6c454353
    cpu.ecx = 1816478547 /*0x6c454353*/;
    // 004f42de  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f42e1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f42e3  e808bcfdff             -call 0x4cfef0
    cpu.esp -= 4;
    sub_4cfef0(app, cpu);
    if (cpu.terminate) return;
L_0x004f42e8:
    // 004f42e8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004f42ea:
    // 004f42ea  833e00                 +cmp dword ptr [esi], 0
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
    // 004f42ed  0f84a4000000           -je 0x4f4397
    if (cpu.flags.zf)
    {
        goto L_0x004f4397;
    }
    // 004f42f3  81471000010000         -add dword ptr [edi + 0x10], 0x100
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004f42fa  837f1000               +cmp dword ptr [edi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f42fe  7d07                   -jge 0x4f4307
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4307;
    }
    // 004f4300  c7471000000000         -mov dword ptr [edi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004f4307:
    // 004f4307  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004f430a  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f430e  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f4310  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4313  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f4316  66894628               -mov word ptr [esi + 0x28], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 004f431a  8a4716                 -mov al, byte ptr [edi + 0x16]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 004f431d  fe4716                 -inc byte ptr [edi + 0x16]
    (app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */))++;
    // 004f4320  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f4327  c74608ffffffff         -mov dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f432e  c7460cffffffff         -mov dword ptr [esi + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 004f4335  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f433c  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f4343  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f434a  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f4351  e826cb0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f4356  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4359  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f435c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4362:
    // 004f4362  e815cb0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f4367  b8f3ffffff             -mov eax, 0xfffffff3
    cpu.eax = 4294967283 /*0xfffffff3*/;
    // 004f436c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f436f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4370  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4371  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4372  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4375:
    // 004f4375  83f901                 +cmp ecx, 1
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
    // 004f4378  7407                   -je 0x4f4381
    if (cpu.flags.zf)
    {
        goto L_0x004f4381;
    }
    // 004f437a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004f437c  e969ffffff             -jmp 0x4f42ea
    goto L_0x004f42ea;
L_0x004f4381:
    // 004f4381  b95343456c             -mov ecx, 0x6c454353
    cpu.ecx = 1816478547 /*0x6c454353*/;
    // 004f4386  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f4389  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004f438b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f438d  e81ebcfdff             -call 0x4cffb0
    cpu.esp -= 4;
    sub_4cffb0(app, cpu);
    if (cpu.terminate) return;
    // 004f4392  e951ffffff             -jmp 0x4f42e8
    goto L_0x004f42e8;
L_0x004f4397:
    // 004f4397  e8e0ca0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f439c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f43a1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f43a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f43ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f43ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f43af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f43b1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f43b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43b6  e831fcffff             -call 0x4f3fec
    cpu.esp -= 4;
    sub_4f3fec(app, cpu);
    if (cpu.terminate) return;
    // 004f43bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43bc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f43c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f43c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f43c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f43c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f43c4  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004f43cb  7508                   -jne 0x4f43d5
    if (!cpu.flags.zf)
    {
        goto L_0x004f43d5;
    }
    // 004f43cd  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f43d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f43d5:
    // 004f43d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f43d7  e8c8f6ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f43dc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f43de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f43e0  744b                   -je 0x4f442d
    if (cpu.flags.zf)
    {
        goto L_0x004f442d;
    }
    // 004f43e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f43e5  e856000000             -call 0x4f4440
    cpu.esp -= 4;
    sub_4f4440(app, cpu);
    if (cpu.terminate) return;
    // 004f43ea  e8e1fbffff             -call 0x4f3fd0
    cpu.esp -= 4;
    sub_4f3fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f43ef  83f801                 +cmp eax, 1
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
    // 004f43f2  7514                   -jne 0x4f4408
    if (!cpu.flags.zf)
    {
        goto L_0x004f4408;
    }
    // 004f43f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f43f5  b8bc3e4f00             -mov eax, 0x4f3ebc
    cpu.eax = 5193404 /*0x4f3ebc*/;
    // 004f43fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f43fc  e8df31ffff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004f4401  891d309ba000           -mov dword ptr [0xa09b30], ebx
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.ebx;
    // 004f4407  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f4408:
    // 004f4408  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f440b  e8c0d40100             -call 0x5118d0
    cpu.esp -= 4;
    sub_5118d0(app, cpu);
    if (cpu.terminate) return;
    // 004f4410  80791800               +cmp byte ptr [ecx + 0x18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4414  7508                   -jne 0x4f441e
    if (!cpu.flags.zf)
    {
        goto L_0x004f441e;
    }
    // 004f4416  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4419  e812b9fdff             -call 0x4cfd30
    cpu.esp -= 4;
    sub_4cfd30(app, cpu);
    if (cpu.terminate) return;
L_0x004f441e:
    // 004f441e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f4420  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4422  8934954c259f00         -mov dword ptr [edx*4 + 0x9f254c], esi
    app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.edx * 4) = cpu.esi;
    // 004f4429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f442d:
    // 004f442d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f4432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f4438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4438  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f443a  e819feffff             -call 0x4f4258
    cpu.esp -= 4;
    sub_4f4258(app, cpu);
    if (cpu.terminate) return;
    // 004f443f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f4440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4441  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 004f4448  7507                   -jne 0x4f4451
    if (!cpu.flags.zf)
    {
        goto L_0x004f4451;
    }
    // 004f444a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f444f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4450  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4451:
    // 004f4451  e84ef6ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f4456  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f445a  7473                   -je 0x4f44cf
    if (cpu.flags.zf)
    {
        goto L_0x004f44cf;
    }
    // 004f445c  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004f4460  7c08                   -jl 0x4f446a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f446a;
    }
    // 004f4462  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f4465  e8b2d30100             -call 0x51181c
    cpu.esp -= 4;
    sub_51181c(app, cpu);
    if (cpu.terminate) return;
L_0x004f446a:
    // 004f446a  c74108ffffffff         -mov dword ptr [ecx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f4471  80791800               +cmp byte ptr [ecx + 0x18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4475  7508                   -jne 0x4f447f
    if (!cpu.flags.zf)
    {
        goto L_0x004f447f;
    }
    // 004f4477  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f447a  e8a1bdfdff             -call 0x4d0220
    cpu.esp -= 4;
    sub_4d0220(app, cpu);
    if (cpu.terminate) return;
L_0x004f447f:
    // 004f447f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4481  c6411600               -mov byte ptr [ecx + 0x16], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004f4485  c6411700               -mov byte ptr [ecx + 0x17], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */) = 0 /*0x0*/;
    // 004f4489  c6411400               -mov byte ptr [ecx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f448d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f4492  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004f4495  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4497  e8a4c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f449c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f44a1  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f44a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44a6  e895c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44ab  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004f44b0  8d4124                 -lea eax, [ecx + 0x24]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004f44b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44b5  e886c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44ba  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004f44bf  8d4130                 -lea eax, [ecx + 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004f44c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44c4  e877c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f44cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f44cf:
    // 004f44cf  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f44d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f44e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f44e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f44e1  39d0                   +cmp eax, edx
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
    // 004f44e3  7526                   -jne 0x4f450b
    if (!cpu.flags.zf)
    {
        goto L_0x004f450b;
    }
    // 004f44e5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f44e8  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f44eb  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f44ee  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f44f1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f44f4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f44f7  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004f44fa  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f44fd  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f4500  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f4503  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f4506  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004f4509  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f450a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f450b:
    // 004f450b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004f450d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004f450f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f4512  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f4515  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f4518  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f451b  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f451e  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f4521  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f4524  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004f4527  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f452a  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004f452d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4530  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004f4533  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f4536  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f4539  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f453c  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f453f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f4544(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4544  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4546  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4547  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4548  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f454a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f454c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f454e  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 004f4550  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4552  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4555  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f4557  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004f455a  01c5                   +add ebp, eax
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
    // 004f455c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f455f  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f4561  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 004f4564  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4566  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f4568  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f456c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f456e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f4570  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004f4573  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4575  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4578  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f457a  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 004f457d  01c5                   +add ebp, eax
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
    // 004f457f  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4582  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f4584  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 004f4587  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4589  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f458b  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f458f  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4592  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f4594  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004f4597  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4599  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f459c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f459e  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 004f45a1  01c5                   +add ebp, eax
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
    // 004f45a3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f45a6  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f45a8  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 004f45ab  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f45ad  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f45af  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f45b3  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f45b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f45c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f45c1  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f45c9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f45cb  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004f45cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f45d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f45d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45d1  87442404               -xchg dword ptr [esp + 4], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004f45d5  e807000000             -call 0x4f45e1
    cpu.esp -= 4;
    sub_4f45e1(app, cpu);
    if (cpu.terminate) return;
    // 004f45da  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f45de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f45e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45e2  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45e4  731a                   -jae 0x4f4600
    if (!cpu.flags.cf)
    {
        goto L_0x004f4600;
    }
    // 004f45e6  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004f45e8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f45ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f45eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45ec  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f45f4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f5  3b06                   +cmp eax, dword ptr [esi]
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
    // 004f45f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f8  7606                   -jbe 0x4f4600
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f4600;
    }
    // 004f45fa  e811000000             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f45ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4600:
    // 004f4600  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4601  b8cc625600             -mov eax, 0x5662cc
    cpu.eax = 5661388 /*0x5662cc*/;
    // 004f4606  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f460b  e8fcd60100             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 004f4610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4611  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4612  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4616  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004f461b:
    // 004f461b  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004f461e  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004f4624  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4629  7ff0                   -jg 0x4f461b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f461b;
    }
    // 004f462b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f4610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f4610;
    // 004f45e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45e2  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45e4  731a                   -jae 0x4f4600
    if (!cpu.flags.cf)
    {
        goto L_0x004f4600;
    }
    // 004f45e6  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004f45e8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f45ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f45eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45ec  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f45f4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f5  3b06                   +cmp eax, dword ptr [esi]
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
    // 004f45f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f8  7606                   -jbe 0x4f4600
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f4600;
    }
    // 004f45fa  e811000000             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f45ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4600:
    // 004f4600  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4601  b8cc625600             -mov eax, 0x5662cc
    cpu.eax = 5661388 /*0x5662cc*/;
    // 004f4606  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f460b  e8fcd60100             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004f4610:
    // 004f4610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4611  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4612  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4616  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004f461b:
    // 004f461b  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004f461e  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004f4624  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4629  7ff0                   -jg 0x4f461b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f461b;
    }
    // 004f462b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f4630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4630  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4631  e8daffffff             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f4636  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4637  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f463b  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f463e  94                     -xchg esp, eax
    {
        x86::reg32 tmp = cpu.esp;
        cpu.esp = cpu.eax;
        cpu.eax = tmp;
    }
    // 004f463f  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4642  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4653  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4655  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f4657  8b15e0625600           -mov edx, dword ptr [0x5662e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */);
    // 004f465d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f4664  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4666  bf24f57900             -mov edi, 0x79f524
    cpu.edi = 7992612 /*0x79f524*/;
    // 004f466b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f466e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f4670  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f4671:
    // 004f4671  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f4673  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f4675  3c00                   +cmp al, 0
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
    // 004f4677  7410                   -je 0x4f4689
    if (cpu.flags.zf)
    {
        goto L_0x004f4689;
    }
    // 004f4679  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f467c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f467f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f4682  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f4685  3c00                   +cmp al, 0
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
    // 004f4687  75e8                   -jne 0x4f4671
    if (!cpu.flags.zf)
    {
        goto L_0x004f4671;
    }
L_0x004f4689:
    // 004f4689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f468a  8b15e0625600           -mov edx, dword ptr [0x5662e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */);
    // 004f4690  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f4697  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4699  42                     -inc edx
    (cpu.edx)++;
    // 004f469a  890c852cf57900         -mov dword ptr [eax*4 + 0x79f52c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7992620) /* 0x79f52c */ + cpu.eax * 4) = cpu.ecx;
    // 004f46a1  8915e0625600           -mov dword ptr [0x5662e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */) = cpu.edx;
    // 004f46a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f46b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f46b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f46b1  a158e55500             -mov eax, dword ptr [0x55e558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629272) /* 0x55e558 */);
    // 004f46b6  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004f46bd  a1c4f57900             -mov eax, dword ptr [0x79f5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7992772) /* 0x79f5c4 */);
    // 004f46c2  8b0402                 -mov eax, dword ptr [edx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 004f46c5  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f46c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f46d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f46d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f46d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f46d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f46d3  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f46d8  bef44f5600             -mov esi, 0x564ff4
    cpu.esi = 5656564 /*0x564ff4*/;
    // 004f46dd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f46df  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f46e1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f46e6  be2c505600             -mov esi, 0x56502c
    cpu.esi = 5656620 /*0x56502c*/;
    // 004f46eb  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f46ee  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f46f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f4700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4701  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4702  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4703  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4704  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4706  8b150c445600           -mov edx, dword ptr [0x56440c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004f470c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f470e  bf2c505600             -mov edi, 0x56502c
    cpu.edi = 5656620 /*0x56502c*/;
    // 004f4713  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004f4719  e88266ffff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 004f471e  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f4723  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004f4726  89150c445600           -mov dword ptr [0x56440c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.edx;
    // 004f472c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f472e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f472f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4730  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4742  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4743  b92e000000             -mov ecx, 0x2e
    cpu.ecx = 46 /*0x2e*/;
    // 004f4748  bef4715600             -mov esi, 0x5671f4
    cpu.esi = 5665268 /*0x5671f4*/;
    // 004f474d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f474f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4751  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4752  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4754  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f4760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4763  b92e000000             -mov ecx, 0x2e
    cpu.ecx = 46 /*0x2e*/;
    // 004f4768  bff4715600             -mov edi, 0x5671f4
    cpu.edi = 5665268 /*0x5671f4*/;
    // 004f476d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f476f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4771  e80a7a0100             -call 0x50c180
    cpu.esp -= 4;
    sub_50c180(app, cpu);
    if (cpu.terminate) return;
    // 004f4776  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4778  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4779  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4782  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4784  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004f4787  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 004f478c  39f0                   +cmp eax, esi
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
    // 004f478e  7324                   -jae 0x4f47b4
    if (!cpu.flags.cf)
    {
        goto L_0x004f47b4;
    }
    // 004f4790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x004f4791:
    // 004f4791  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4793  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4795  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004f4797  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f4799  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f479b  668b0c4d546b5600       -mov cx, word ptr [ecx*2 + 0x566b54]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5663572) /* 0x566b54 */ + cpu.ecx * 2);
    // 004f47a3  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f47a9  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004f47ac  40                     -inc eax
    (cpu.eax)++;
    // 004f47ad  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f47af  39f0                   +cmp eax, esi
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
    // 004f47b1  72de                   -jb 0x4f4791
    if (cpu.flags.cf)
    {
        goto L_0x004f4791;
    }
    // 004f47b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f47b4:
    // 004f47b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f47b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f47c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f47c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f47c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f47c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f47c3  8a5803                 -mov bl, byte ptr [eax + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004f47c6  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f47cb  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004f47ce  7405                   -je 0x4f47d5
    if (cpu.flags.zf)
    {
        goto L_0x004f47d5;
    }
    // 004f47d0  f6c3c0                 +test bl, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 192 /*0xc0*/));
    // 004f47d3  7406                   -je 0x4f47db
    if (cpu.flags.zf)
    {
        goto L_0x004f47db;
    }
L_0x004f47d5:
    // 004f47d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f47d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f47db:
    // 004f47db  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f47de  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f47e1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f47e3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f47e8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f47ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f47ef  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f47f1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f47f3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f47fa  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f47fc  3d444e4542             +cmp eax, 0x42454e44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1111838276 /*0x42454e44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4801  74d2                   -je 0x4f47d5
    if (cpu.flags.zf)
    {
        goto L_0x004f47d5;
    }
    // 004f4803  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4805  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4807  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4808  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4809  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f480a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f4810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4812  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4813  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4815  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4816  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f4819  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f481c  8b3c85c0f59e00         -mov edi, dword ptr [eax*4 + 0x9ef5c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004f4823  8b5738                 -mov edx, dword ptr [edi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004f4826  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4828  7537                   -jne 0x4f4861
    if (!cpu.flags.zf)
    {
        goto L_0x004f4861;
    }
L_0x004f482a:
    // 004f482a  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x004f482d:
    // 004f482d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f482f  e88cffffff             -call 0x4f47c0
    cpu.esp -= 4;
    sub_4f47c0(app, cpu);
    if (cpu.terminate) return;
    // 004f4834  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4838  7530                   -jne 0x4f486a
    if (!cpu.flags.zf)
    {
        goto L_0x004f486a;
    }
L_0x004f483a:
    // 004f483a  8b6f38                 -mov ebp, dword ptr [edi + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004f483d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f483f  7407                   -je 0x4f4848
    if (cpu.flags.zf)
    {
        goto L_0x004f4848;
    }
    // 004f4841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4842  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f4848:
    // 004f4848  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f484a  7509                   -jne 0x4f4855
    if (!cpu.flags.zf)
    {
        goto L_0x004f4855;
    }
    // 004f484c  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004f4853  751e                   -jne 0x4f4873
    if (!cpu.flags.zf)
    {
        goto L_0x004f4873;
    }
L_0x004f4855:
    // 004f4855  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4857  83c408                 +add esp, 8
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
    // 004f485a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4860  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4861:
    // 004f4861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4862  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4868  ebc0                   -jmp 0x4f482a
    goto L_0x004f482a;
L_0x004f486a:
    // 004f486a  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f486d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f486f  75bc                   -jne 0x4f482d
    if (!cpu.flags.zf)
    {
        goto L_0x004f482d;
    }
    // 004f4871  ebc7                   -jmp 0x4f483a
    goto L_0x004f483a;
L_0x004f4873:
    // 004f4873  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f4875  88642404               -mov byte ptr [esp + 4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 004f4879  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004f487c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f487f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f4884  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f4886  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f4888  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f488a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f488c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f4893  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f4895  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f4897  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f489a  c7059821550051000000   -mov dword ptr [0x552198], 0x51
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 81 /*0x51*/;
    // 004f48a4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f48a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48a7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f48aa  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f48ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48ad  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f48b0  bd88ce5400             -mov ebp, 0x54ce88
    cpu.ebp = 5557896 /*0x54ce88*/;
    // 004f48b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f48b6  b978ce5400             -mov ecx, 0x54ce78
    cpu.ecx = 5557880 /*0x54ce78*/;
    // 004f48bb  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f48c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f48c2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f48c4  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f48ca  e811cdfeff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 004f48cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48d0  689cce5400             -push 0x54ce9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557916 /*0x54ce9c*/;
    cpu.esp -= 4;
    // 004f48d5  e836c7f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f48da  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f48dd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f48df  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f48e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f48f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f48f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f48f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f48f2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f48f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f48f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f48fb:
    // 004f48fb  83b9c0f59e0000         +cmp dword ptr [ecx + 0x9ef5c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10417600) /* 0x9ef5c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4902  7510                   -jne 0x4f4914
    if (!cpu.flags.zf)
    {
        goto L_0x004f4914;
    }
L_0x004f4904:
    // 004f4904  42                     -inc edx
    (cpu.edx)++;
    // 004f4905  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4908  83fa10                 +cmp edx, 0x10
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
    // 004f490b  7d04                   -jge 0x4f4911
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4911;
    }
    // 004f490d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f490f  75ea                   -jne 0x4f48fb
    if (!cpu.flags.zf)
    {
        goto L_0x004f48fb;
    }
L_0x004f4911:
    // 004f4911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4913  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4914:
    // 004f4914  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4916  e8f5feffff             -call 0x4f4810
    cpu.esp -= 4;
    sub_4f4810(app, cpu);
    if (cpu.terminate) return;
    // 004f491b  ebe7                   -jmp 0x4f4904
    goto L_0x004f4904;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f4920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4920  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4922  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4923  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f4927  39ca                   +cmp edx, ecx
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
    // 004f4929  0f8c6e000000           -jl 0x4f499d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f499d;
    }
    // 004f492f  39fa                   +cmp edx, edi
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
    // 004f4931  7f6a                   -jg 0x4f499d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f499d;
    }
    // 004f4933  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004f4938:
    // 004f4938  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004f493a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f493c  7557                   -jne 0x4f4995
    if (!cpu.flags.zf)
    {
        goto L_0x004f4995;
    }
    // 004f493e  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004f4945  744e                   -je 0x4f4995
    if (cpu.flags.zf)
    {
        goto L_0x004f4995;
    }
    // 004f4947  39f9                   +cmp ecx, edi
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
    // 004f4949  0f8598000000           -jne 0x4f49e7
    if (!cpu.flags.zf)
    {
        goto L_0x004f49e7;
    }
    // 004f494f  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f4954  744b                   -je 0x4f49a1
    if (cpu.flags.zf)
    {
        goto L_0x004f49a1;
    }
    // 004f4956  bf04cf5400             -mov edi, 0x54cf04
    cpu.edi = 5558020 /*0x54cf04*/;
    // 004f495b  be14cf5400             -mov esi, 0x54cf14
    cpu.esi = 5558036 /*0x54cf14*/;
    // 004f4960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4961  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f4967  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f496b  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f4971  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4972  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4975  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 004f497a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f497b  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f4981  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4984  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4985  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4987  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4988  6828cf5400             -push 0x54cf28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558056 /*0x54cf28*/;
    cpu.esp -= 4;
    // 004f498d  e87ec6f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4992  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004f4995:
    // 004f4995  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4997  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4998  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4999  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f499a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f499d:
    // 004f499d  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f499f  eb97                   -jmp 0x4f4938
    goto L_0x004f4938;
L_0x004f49a1:
    // 004f49a1  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f49ab  be16000000             -mov esi, 0x16
    cpu.esi = 22 /*0x16*/;
    // 004f49b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f49b1  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f49b7  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f49bb  bf14cf5400             -mov edi, 0x54cf14
    cpu.edi = 5558036 /*0x54cf14*/;
    // 004f49c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f49c1  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f49c7  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f49ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f49cb  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f49ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f49cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f49d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f49d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f49d2  687ccf5400             -push 0x54cf7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558140 /*0x54cf7c*/;
    cpu.esp -= 4;
    // 004f49d7  e834c6f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f49dc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f49df  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f49e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f49e7:
    // 004f49e7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f49ec  7446                   -je 0x4f4a34
    if (cpu.flags.zf)
    {
        goto L_0x004f4a34;
    }
    // 004f49ee  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f49f8  c7059421550014cf5400   -mov dword ptr [0x552194], 0x54cf14
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5558036 /*0x54cf14*/;
    // 004f4a02  be1b000000             -mov esi, 0x1b
    cpu.esi = 27 /*0x1b*/;
    // 004f4a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4a08  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f4a0e  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f4a12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a13  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4a16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a17  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4a1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a1f  68d0cf5400             -push 0x54cfd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558224 /*0x54cfd0*/;
    cpu.esp -= 4;
    // 004f4a24  e8e7c5f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4a29  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f4a2c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4a2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a31  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f4a34:
    // 004f4a34  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f4a3e  c7059421550014cf5400   -mov dword ptr [0x552194], 0x54cf14
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5558036 /*0x54cf14*/;
    // 004f4a48  be1d000000             -mov esi, 0x1d
    cpu.esi = 29 /*0x1d*/;
    // 004f4a4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4a4e  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f4a54  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f4a58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a59  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4a5c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a5d  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a65  6828d05400             -push 0x54d028
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558312 /*0x54d028*/;
    cpu.esp -= 4;
    // 004f4a6a  e8a1c5f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4a6f  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f4a72  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4a74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a77  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f4a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4a87  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f4a89  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 004f4a8e  68444e4957             -push 0x57494e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 1464421956 /*0x57494e44*/;
    cpu.esp -= 4;
    // 004f4a93  bb80d05400             -mov ebx, 0x54d080
    cpu.ebx = 5558400 /*0x54d080*/;
    // 004f4a98  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004f4a9a  e881feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4a9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4aa1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4aa6  bb84d05400             -mov ebx, 0x54d084
    cpu.ebx = 5558404 /*0x54d084*/;
    // 004f4aab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f4aad  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4ab2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4ab5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ab7  e864feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4abc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4abe  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4ac3  bb8cd05400             -mov ebx, 0x54d08c
    cpu.ebx = 5558412 /*0x54d08c*/;
    // 004f4ac8  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4acb  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4ad0  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4ad2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ad4  e847feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4ad9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4adb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4ae0  bb94d05400             -mov ebx, 0x54d094
    cpu.ebx = 5558420 /*0x54d094*/;
    // 004f4ae5  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4ae7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4ae9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f4aeb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4aed  8a561c                 -mov dl, byte ptr [esi + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f4af0  e82bfeffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4af5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f4af7  bb98d05400             -mov ebx, 0x54d098
    cpu.ebx = 5558424 /*0x54d098*/;
    // 004f4afc  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4afe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4b00  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b02  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004f4b04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b06  8a561d                 -mov dl, byte ptr [esi + 0x1d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */);
    // 004f4b09  e812feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b0e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b10  bba0d05400             -mov ebx, 0x54d0a0
    cpu.ebx = 5558432 /*0x54d0a0*/;
    // 004f4b15  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f4b18  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b1a  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b1f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b23  e8f8fdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b28  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b2c  bba8d05400             -mov ebx, 0x54d0a8
    cpu.ebx = 5558440 /*0x54d0a8*/;
    // 004f4b31  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b33  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b38  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004f4b3b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b3d  e8defdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b42  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b44  bbb0d05400             -mov ebx, 0x54d0b0
    cpu.ebx = 5558448 /*0x54d0b0*/;
    // 004f4b49  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f4b4c  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b4e  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b53  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b57  e8c4fdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b5c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b5e  bbb8d05400             -mov ebx, 0x54d0b8
    cpu.ebx = 5558456 /*0x54d0b8*/;
    // 004f4b63  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f4b66  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b68  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b6d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b6f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b71  e8aafdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b76  21f8                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004f4b78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f4b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4b81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4b82  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4b85  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f4b89  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f4b8b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f4b8f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f4b92  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f4b96  e879a40000             -call 0x4ff014
    cpu.esp -= 4;
    sub_4ff014(app, cpu);
    if (cpu.terminate) return;
    // 004f4b9b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4b9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ba0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4bb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4bb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4bb4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4bb6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f4bb8  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f4bba  3b10                   +cmp edx, dword ptr [eax]
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
    // 004f4bbc  7534                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bbe  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f4bc2  663b5604               +cmp dx, word ptr [esi + 4]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f4bc6  752a                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bc8  668b5f06               -mov bx, word ptr [edi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004f4bcc  663b5e06               +cmp bx, word ptr [esi + 6]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f4bd0  7520                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bd2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f4bd4  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4bd7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4bd9  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f4bdc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4bde  38fb                   +cmp bl, bh
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
    // 004f4be0  7510                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
L_0x004f4be2:
    // 004f4be2  40                     -inc eax
    (cpu.eax)++;
    // 004f4be3  42                     -inc edx
    (cpu.edx)++;
    // 004f4be4  41                     -inc ecx
    (cpu.ecx)++;
    // 004f4be5  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4be8  7d0f                   -jge 0x4f4bf9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4bf9;
    }
    // 004f4bea  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4bed  3a5908                 +cmp bl, byte ptr [ecx + 8]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4bf0  74f0                   -je 0x4f4be2
    if (cpu.flags.zf)
    {
        goto L_0x004f4be2;
    }
L_0x004f4bf2:
    // 004f4bf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4bf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4bf9:
    // 004f4bf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f4bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4c11  833de86d560000         +cmp dword ptr [0x566de8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4c18  742b                   -je 0x4f4c45
    if (cpu.flags.zf)
    {
        goto L_0x004f4c45;
    }
L_0x004f4c1a:
    // 004f4c1a  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4c1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4c21  e84a980100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f4c26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4c28  7407                   -je 0x4f4c31
    if (cpu.flags.zf)
    {
        goto L_0x004f4c31;
    }
    // 004f4c2a  e831020000             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
    // 004f4c2f  ebe9                   -jmp 0x4f4c1a
    goto L_0x004f4c1a;
L_0x004f4c31:
    // 004f4c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4c32  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4c37  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c39  e8a2910100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f4c3e  890de86d5600           -mov dword ptr [0x566de8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */) = cpu.ecx;
    // 004f4c44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f4c45:
    // 004f4c45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f4c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c50  833de06d560001         +cmp dword ptr [0x566de0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4c57  7d01                   -jge 0x4f4c5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4c5a;
    }
    // 004f4c59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4c5a:
    // 004f4c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4c5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4c5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4c5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4c5f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4c63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4c65  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4c67  e814d50100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f4c6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f4c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4c71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4c72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4c73  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4c76  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f4c7a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f4c7d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f4c81  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004f4c83  b8c0d05400             -mov eax, 0x54d0c0
    cpu.eax = 5558464 /*0x54d0c0*/;
    // 004f4c88  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f4c8d  e8beffffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4c92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c94  8b1de46d5600           -mov ebx, dword ptr [0x566de4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4c9a  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f4c9e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f4ca0  7e46                   -jle 0x4f4ce8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4ce8;
    }
    // 004f4ca2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f4ca4:
    // 004f4ca4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4ca6  7440                   -je 0x4f4ce8
    if (cpu.flags.zf)
    {
        goto L_0x004f4ce8;
    }
    // 004f4ca8  8b86b0259f00           -mov eax, dword ptr [esi + 0x9f25b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10429872) /* 0x9f25b0 */);
    // 004f4cae  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004f4cb2  753d                   -jne 0x4f4cf1
    if (!cpu.flags.zf)
    {
        goto L_0x004f4cf1;
    }
    // 004f4cb4  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4cb7  7719                   -ja 0x4f4cd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f4cd2;
    }
    // 004f4cb9  8b86d0259f00           -mov eax, dword ptr [esi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4cbf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4cc2  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 004f4cc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4cc9  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004f4ccc  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f4cd0:
    // 004f4cd0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f4cd2:
    // 004f4cd2  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4cd6  8b0de46d5600           -mov ecx, dword ptr [0x566de4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4cdc  45                     -inc ebp
    (cpu.ebp)++;
    // 004f4cdd  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4ce0  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004f4ce4  39cd                   +cmp ebp, ecx
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
    // 004f4ce6  7cbc                   -jl 0x4f4ca4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f4ca4;
    }
L_0x004f4ce8:
    // 004f4ce8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4cea  83c410                 +add esp, 0x10
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
    // 004f4ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4cf1:
    // 004f4cf1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4cf5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f4cf8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4cfa  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f4cfc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4d00  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4d03  ebcb                   -jmp 0x4f4cd0
    goto L_0x004f4cd0;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f4d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4d10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4d11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4d13  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4d16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4d18  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f4d1c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f4d1f  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f4d23  b8d0d05400             -mov eax, 0x54d0d0
    cpu.eax = 5558480 /*0x54d0d0*/;
    // 004f4d28  e823ffffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4d2d  8b15e86d5600           -mov edx, dword ptr [0x566de8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */);
    // 004f4d33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4d35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4d37  0f84a4000000           -je 0x4f4de1
    if (cpu.flags.zf)
    {
        goto L_0x004f4de1;
    }
L_0x004f4d3d:
    // 004f4d3d  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4d42  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f4d44  e8d7940100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4d49  83f8ff                 +cmp eax, -1
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
    // 004f4d4c  7407                   -je 0x4f4d55
    if (cpu.flags.zf)
    {
        goto L_0x004f4d55;
    }
    // 004f4d4e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4d50  e80b010000             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
L_0x004f4d55:
    // 004f4d55  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 004f4d5a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4d5c  e8abb9feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f4d61  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f4d63  a1e46d5600             -mov eax, dword ptr [0x566de4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4d68  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004f4d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4d6e  7e62                   -jle 0x4f4dd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4dd2;
    }
    // 004f4d70  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004f4d72:
    // 004f4d72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4d74  755c                   -jne 0x4f4dd2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4dd2;
    }
    // 004f4d76  8b87d0259f00           -mov eax, dword ptr [edi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4d7c  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f4d7f  8b87b0259f00           -mov eax, dword ptr [edi + 0x9f25b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429872) /* 0x9f25b0 */);
    // 004f4d85  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4d88  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4d8c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f4d8f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4d92  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004f4d96  0f848d000000           -je 0x4f4e29
    if (cpu.flags.zf)
    {
        goto L_0x004f4e29;
    }
L_0x004f4d9c:
    // 004f4d9c  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f4da0  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f4da4  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f4da8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4da9  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4dad  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4db1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4db3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4db7  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4dba  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004f4dbc:
    // 004f4dbc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4dc0  8b1de46d5600           -mov ebx, dword ptr [0x566de4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4dc6  42                     -inc edx
    (cpu.edx)++;
    // 004f4dc7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4dca  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f4dce  39da                   +cmp edx, ebx
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
    // 004f4dd0  7ca0                   -jl 0x4f4d72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f4d72;
    }
L_0x004f4dd2:
    // 004f4dd2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4dd4  7572                   -jne 0x4f4e48
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e48;
    }
    // 004f4dd6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4dd8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4ddb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ddc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4dde  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f4de1:
    // 004f4de1  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4de6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4de8  e8e38e0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f4ded  b8104c4f00             -mov eax, 0x4f4c10
    cpu.eax = 5196816 /*0x4f4c10*/;
    // 004f4df2  e881dcffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f4df7  833ddc6d560000         +cmp dword ptr [0x566ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664220) /* 0x566ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4dfe  751a                   -jne 0x4f4e1a
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e1a;
    }
    // 004f4e00  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f4e06  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004f4e09  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 004f4e0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4e10  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f4e13  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f4e15  a3dc6d5600             -mov dword ptr [0x566ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5664220) /* 0x566ddc */) = cpu.eax;
L_0x004f4e1a:
    // 004f4e1a  c705e86d560001000000   -mov dword ptr [0x566de8], 1
    app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */) = 1 /*0x1*/;
    // 004f4e24  e914ffffff             -jmp 0x4f4d3d
    goto L_0x004f4d3d;
L_0x004f4e29:
    // 004f4e29  8b87d0259f00           -mov eax, dword ptr [edi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4e2f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4e33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4e36  e875fdffff             -call 0x4f4bb0
    cpu.esp -= 4;
    sub_4f4bb0(app, cpu);
    if (cpu.terminate) return;
    // 004f4e3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4e3d  0f8559ffffff           -jne 0x4f4d9c
    if (!cpu.flags.zf)
    {
        goto L_0x004f4d9c;
    }
    // 004f4e43  e974ffffff             -jmp 0x4f4dbc
    goto L_0x004f4dbc;
L_0x004f4e48:
    // 004f4e48  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e4d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f4e4f  e8fc8f0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f4e54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4e56  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4e59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f4e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4e63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4e65  b8e0d05400             -mov eax, 0x54d0e0
    cpu.eax = 5558496 /*0x54d0e0*/;
    // 004f4e6a  e8e1fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4e6f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4e71  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e76  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4e78  e8a3930100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4e7d  83f8ff                 +cmp eax, -1
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
    // 004f4e80  7506                   -jne 0x4f4e88
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e88;
    }
    // 004f4e82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f4e84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4e88:
    // 004f4e88  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4e8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4e8d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4e8f  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4e92  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f4e94  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e99  e8b2920100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f4e9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f4ea0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f4eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4eb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4eb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4eb2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4eb4  b8f0d05400             -mov eax, 0x54d0f0
    cpu.eax = 5558512 /*0x54d0f0*/;
    // 004f4eb9  e892fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ebe  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4ec1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ec3  ff5710                 -call dword ptr [edi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4ec6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ec7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ec8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ed1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4ed2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ed4  b800d15400             -mov eax, 0x54d100
    cpu.eax = 5558528 /*0x54d100*/;
    // 004f4ed9  e872fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ede  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4ee1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4ee3  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4ee6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ee7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4ef2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ef4  b80cd15400             -mov eax, 0x54d10c
    cpu.eax = 5558540 /*0x54d10c*/;
    // 004f4ef9  e852fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4efe  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f01  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f03  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4f11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4f12  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4f14  b81cd15400             -mov eax, 0x54d11c
    cpu.eax = 5558556 /*0x54d11c*/;
    // 004f4f19  e832fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f1e  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4f21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4f23  ff571c                 -call dword ptr [edi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f28  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
