#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip 0x90 */
void sub_aab5a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab5a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab5a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab5a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab5a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab5a8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab5aa  2eff156813ab00         -call dword ptr cs:[0xab1368]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211624) /* 0xab1368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab5b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab5b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab5b5  750d                   -jne 0xaab5c4
    if (!cpu.flags.zf)
    {
        goto L_0x00aab5c4;
    }
    // 00aab5b7  8b151038ab00           -mov edx, dword ptr [0xab3810]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221008) /* 0xab3810 */);
    // 00aab5bd  42                     -inc edx
    (cpu.edx)++;
    // 00aab5be  89151038ab00           -mov dword ptr [0xab3810], edx
    app->getMemory<x86::reg32>(x86::reg32(11221008) /* 0xab3810 */) = cpu.edx;
L_0x00aab5c4:
    // 00aab5c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aab5c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab5c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab5c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aab5cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab5cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab5cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab5ce  8b150838ab00           -mov edx, dword ptr [0xab3808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab5d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aab5d6  740f                   -je 0xaab5e7
    if (cpu.flags.zf)
    {
        goto L_0x00aab5e7;
    }
    // 00aab5d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aab5da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aab5dc  e8bfc7ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aab5e1  891d0838ab00           -mov dword ptr [0xab3808], ebx
    app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */) = cpu.ebx;
L_0x00aab5e7:
    // 00aab5e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab5e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab5e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab5f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab5f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab5f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab5f4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aab5f6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aab5f8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aab5fa  2eff15e013ab00         -call dword ptr cs:[0xab13e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211744) /* 0xab13e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab601  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00aab604  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aab609  663d0080               +cmp ax, 0x8000
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
    // 00aab60d  730f                   -jae 0xaab61e
    if (!cpu.flags.cf)
    {
        goto L_0x00aab61e;
    }
    // 00aab60f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab610  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab611  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab612  2eff15cc13ab00         -call dword ptr cs:[0xab13cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211724) /* 0xab13cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab619  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab61a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab61b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab61c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab61d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab61e:
    // 00aab61e  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00aab623  e888c6ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab628  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aab62a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab62c  7452                   -je 0xaab680
    if (cpu.flags.zf)
    {
        goto L_0x00aab680;
    }
    // 00aab62e  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00aab633  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab635  2eff15c813ab00         -call dword ptr cs:[0xab13c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211720) /* 0xab13c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab63c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab63e  750e                   -jne 0xaab64e
    if (!cpu.flags.zf)
    {
        goto L_0x00aab64e;
    }
    // 00aab640  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab642  e859c7ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aab647  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aab649  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab64a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab64b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab64c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab64d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab64e:
    // 00aab64e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab64f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab650  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00aab652  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab653  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aab655  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aab657  2eff15f413ab00         -call dword ptr cs:[0xab13f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211764) /* 0xab13f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab65e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aab660  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab662  e839c7ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aab667  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aab669  7507                   -jne 0xaab672
    if (!cpu.flags.zf)
    {
        goto L_0x00aab672;
    }
    // 00aab66b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aab66d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab66e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab66f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab670  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab672:
    // 00aab672  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab674  66c7447efe0000         -mov word ptr [esi + edi*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.edi * 2) = 0 /*0x0*/;
    // 00aab67b  e8401a0000             -call 0xaad0c0
    cpu.esp -= 4;
    sub_aad0c0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab680:
    // 00aab680  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab681  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab682  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab683  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab691  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab692  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab694  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aab696  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aab698  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aab699  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aab69b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aab69d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aab69f  49                     -dec ecx
    (cpu.ecx)--;
    // 00aab6a0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aab6a2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aab6a4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aab6a6  49                     -dec ecx
    (cpu.ecx)--;
    // 00aab6a7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aab6a8  41                     -inc ecx
    (cpu.ecx)++;
    // 00aab6a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab6ab  e800c6ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab6b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab6b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab6b4  7418                   -je 0xaab6ce
    if (cpu.flags.zf)
    {
        goto L_0x00aab6ce;
    }
    // 00aab6b6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aab6b8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aab6b9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aab6bb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aab6bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab6be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab6c0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00aab6c3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aab6c5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00aab6c7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00aab6ca  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00aab6cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab6cd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00aab6ce:
    // 00aab6ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aab6d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab6d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab6d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab6d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab6d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab6e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab6e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab6e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab6e5  e8d6190000             -call 0xaad0c0
    cpu.esp -= 4;
    sub_aad0c0(app, cpu);
    if (cpu.terminate) return;
    // 00aab6ea  40                     -inc eax
    (cpu.eax)++;
    // 00aab6eb  8d1c4500000000         -lea ebx, [eax*2]
    cpu.ebx = x86::reg32(cpu.eax * 2);
    // 00aab6f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab6f4  e8b7c5ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab6f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aab6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab6fd  7405                   -je 0xaab704
    if (cpu.flags.zf)
    {
        goto L_0x00aab704;
    }
    // 00aab6ff  e8dc190000             -call 0xaad0e0
    cpu.esp -= 4;
    sub_aad0e0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab704:
    // 00aab704  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab706  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab710(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab713  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00aab716  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aab718  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aab71a  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00aab71c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aab720  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab721  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aab725  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab726  2eff153414ab00         -call dword ptr cs:[0xab1434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211828) /* 0xab1434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab72d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab730  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00aab734  668b0d8537ab00         -mov cx, word ptr [0xab3785]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(11220869) /* 0xab3785 */);
    // 00aab73b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aab73f  6681f90080             +cmp cx, 0x8000
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
    // 00aab744  7307                   -jae 0xaab74d
    if (!cpu.flags.cf)
    {
        goto L_0x00aab74d;
    }
    // 00aab746  0500300000             +add eax, 0x3000
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
    // 00aab74b  eb17                   -jmp 0xaab764
    goto L_0x00aab764;
L_0x00aab74d:
    // 00aab74d  7210                   -jb 0xaab75f
    if (cpu.flags.cf)
    {
        goto L_0x00aab75f;
    }
    // 00aab74f  803d8337ab0004         +cmp byte ptr [0xab3783], 4
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
    // 00aab756  7307                   -jae 0xaab75f
    if (!cpu.flags.cf)
    {
        goto L_0x00aab75f;
    }
    // 00aab758  0500200100             +add eax, 0x12000
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
    // 00aab75d  eb05                   -jmp 0xaab764
    goto L_0x00aab764;
L_0x00aab75f:
    // 00aab75f  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00aab764:
    // 00aab764  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aab766  7402                   -je 0xaab76a
    if (cpu.flags.zf)
    {
        goto L_0x00aab76a;
    }
    // 00aab768  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00aab76a:
    // 00aab76a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aab76c  7402                   -je 0xaab770
    if (cpu.flags.zf)
    {
        goto L_0x00aab770;
    }
    // 00aab76e  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00aab770:
    // 00aab770  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00aab773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab783  68c828ab00             -push 0xab28c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11217096 /*0xab28c8*/;
    cpu.esp -= 4;
    // 00aab788  2eff15ec13ab00         -call dword ptr cs:[0xab13ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211756) /* 0xab13ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab78f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aab791  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab793  7417                   -je 0xaab7ac
    if (cpu.flags.zf)
    {
        goto L_0x00aab7ac;
    }
    // 00aab795  68d428ab00             -push 0xab28d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11217108 /*0xab28d4*/;
    cpu.esp -= 4;
    // 00aab79a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab79b  2eff15d813ab00         -call dword ptr cs:[0xab13d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211736) /* 0xab13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab7a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab7a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab7a6  7404                   -je 0xaab7ac
    if (cpu.flags.zf)
    {
        goto L_0x00aab7ac;
    }
    // 00aab7a8  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab7aa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00aab7ac:
    // 00aab7ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aab7ae  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00aab7b1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aab7b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab7b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab7b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab7b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aab7bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab7bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab7bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab7be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab7bf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aab7c1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aab7c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aab7c5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00aab7c7  7408                   -je 0xaab7d1
    if (cpu.flags.zf)
    {
        goto L_0x00aab7d1;
    }
L_0x00aab7c9:
    // 00aab7c9  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aab7cc  40                     -inc eax
    (cpu.eax)++;
    // 00aab7cd  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00aab7cf  75f8                   -jne 0xaab7c9
    if (!cpu.flags.zf)
    {
        goto L_0x00aab7c9;
    }
L_0x00aab7d1:
    // 00aab7d1  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00aab7d4:
    // 00aab7d4  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00aab7d6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00aab7d8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00aab7da  7412                   -je 0xaab7ee
    if (cpu.flags.zf)
    {
        goto L_0x00aab7ee;
    }
    // 00aab7dc  80f930                 +cmp cl, 0x30
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
    // 00aab7df  7508                   -jne 0xaab7e9
    if (!cpu.flags.zf)
    {
        goto L_0x00aab7e9;
    }
    // 00aab7e1  807a0178               +cmp byte ptr [edx + 1], 0x78
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
    // 00aab7e5  7502                   -jne 0xaab7e9
    if (!cpu.flags.zf)
    {
        goto L_0x00aab7e9;
    }
    // 00aab7e7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00aab7e9:
    // 00aab7e9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aab7ea  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aab7eb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aab7ec  ebe6                   -jmp 0xaab7d4
    goto L_0x00aab7d4;
L_0x00aab7ee:
    // 00aab7ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aab7f0  741c                   -je 0xaab80e
    if (cpu.flags.zf)
    {
        goto L_0x00aab80e;
    }
    // 00aab7f2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aab7f4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aab7f6  7416                   -je 0xaab80e
    if (cpu.flags.zf)
    {
        goto L_0x00aab80e;
    }
L_0x00aab7f8:
    // 00aab7f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab7fa  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aab7fd  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aab7fe  8a921c38ab00           -mov dl, byte ptr [edx + 0xab381c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11221020) /* 0xab381c */);
    // 00aab804  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00aab807  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00aab80a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab80c  75ea                   -jne 0xaab7f8
    if (!cpu.flags.zf)
    {
        goto L_0x00aab7f8;
    }
L_0x00aab80e:
    // 00aab80e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab80f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab810  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aab814(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab814  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab815  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab816  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00aab81c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00aab823  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aab825  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aab828  e853ffffff             -call 0xaab780
    cpu.esp -= 4;
    sub_aab780(app, cpu);
    if (cpu.terminate) return;
    // 00aab82d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab82f  750a                   -jne 0xaab83b
    if (!cpu.flags.zf)
    {
        goto L_0x00aab83b;
    }
    // 00aab831  e87e190000             -call 0xaad1b4
    cpu.esp -= 4;
    sub_aad1b4(app, cpu);
    if (cpu.terminate) return;
    // 00aab836  83f8ff                 +cmp eax, -1
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
    // 00aab839  7507                   -jne 0xaab842
    if (!cpu.flags.zf)
    {
        goto L_0x00aab842;
    }
L_0x00aab83b:
    // 00aab83b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aab83d  e98c010000             -jmp 0xaab9ce
    goto L_0x00aab9ce;
L_0x00aab842:
    // 00aab842  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00aab844  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00aab847  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aab849  3d900000c0             +cmp eax, 0xc0000090
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
    // 00aab84e  724d                   -jb 0xaab89d
    if (cpu.flags.cf)
    {
        goto L_0x00aab89d;
    }
    // 00aab850  0f86c2000000           -jbe 0xaab918
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab918;
    }
    // 00aab856  3d930000c0             +cmp eax, 0xc0000093
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
    // 00aab85b  7233                   -jb 0xaab890
    if (cpu.flags.cf)
    {
        goto L_0x00aab890;
    }
    // 00aab85d  0f86ab000000           -jbe 0xaab90e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab90e;
    }
    // 00aab863  3d960000c0             +cmp eax, 0xc0000096
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
    // 00aab868  7216                   -jb 0xaab880
    if (cpu.flags.cf)
    {
        goto L_0x00aab880;
    }
    // 00aab86a  0f86ec000000           -jbe 0xaab95c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab95c;
    }
    // 00aab870  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 00aab875  0f84f6000000           -je 0xaab971
    if (cpu.flags.zf)
    {
        goto L_0x00aab971;
    }
    // 00aab87b  e9f8000000             -jmp 0xaab978
    goto L_0x00aab978;
L_0x00aab880:
    // 00aab880  3d940000c0             +cmp eax, 0xc0000094
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
    // 00aab885  0f84df000000           -je 0xaab96a
    if (cpu.flags.zf)
    {
        goto L_0x00aab96a;
    }
    // 00aab88b  e9e8000000             -jmp 0xaab978
    goto L_0x00aab978;
L_0x00aab890:
    // 00aab890  3d910000c0             +cmp eax, 0xc0000091
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
    // 00aab895  0f8669000000           -jbe 0xaab904
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab904;
    }
    // 00aab89b  eb2f                   -jmp 0xaab8cc
    goto L_0x00aab8cc;
L_0x00aab89d:
    // 00aab89d  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 00aab8a2  720b                   -jb 0xaab8af
    if (cpu.flags.cf)
    {
        goto L_0x00aab8af;
    }
    // 00aab8a4  7640                   -jbe 0xaab8e6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab8e6;
    }
    // 00aab8a6  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 00aab8ab  7643                   -jbe 0xaab8f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab8f0;
    }
    // 00aab8ad  eb4b                   -jmp 0xaab8fa
    goto L_0x00aab8fa;
L_0x00aab8af:
    // 00aab8af  3d050000c0             +cmp eax, 0xc0000005
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
    // 00aab8b4  0f82be000000           -jb 0xaab978
    if (cpu.flags.cf)
    {
        goto L_0x00aab978;
    }
    // 00aab8ba  7666                   -jbe 0xaab922
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab922;
    }
    // 00aab8bc  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 00aab8c1  0f849c000000           -je 0xaab963
    if (cpu.flags.zf)
    {
        goto L_0x00aab963;
    }
    // 00aab8c7  e9ac000000             -jmp 0xaab978
    goto L_0x00aab978;
L_0x00aab8cc:
    // 00aab8cc  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00aab8d0  740a                   -je 0xaab8dc
    if (cpu.flags.zf)
    {
        goto L_0x00aab8dc;
    }
    // 00aab8d2  bae428ab00             -mov edx, 0xab28e4
    cpu.edx = 11217124 /*0xab28e4*/;
    // 00aab8d7  e9af000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab8dc:
    // 00aab8dc  ba3829ab00             -mov edx, 0xab2938
    cpu.edx = 11217208 /*0xab2938*/;
    // 00aab8e1  e9a5000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab8e6:
    // 00aab8e6  ba8c29ab00             -mov edx, 0xab298c
    cpu.edx = 11217292 /*0xab298c*/;
    // 00aab8eb  e99b000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab8f0:
    // 00aab8f0  bae029ab00             -mov edx, 0xab29e0
    cpu.edx = 11217376 /*0xab29e0*/;
    // 00aab8f5  e991000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab8fa:
    // 00aab8fa  ba342aab00             -mov edx, 0xab2a34
    cpu.edx = 11217460 /*0xab2a34*/;
    // 00aab8ff  e987000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab904:
    // 00aab904  ba882aab00             -mov edx, 0xab2a88
    cpu.edx = 11217544 /*0xab2a88*/;
    // 00aab909  e97d000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab90e:
    // 00aab90e  bad42aab00             -mov edx, 0xab2ad4
    cpu.edx = 11217620 /*0xab2ad4*/;
    // 00aab913  e973000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab918:
    // 00aab918  ba242bab00             -mov edx, 0xab2b24
    cpu.edx = 11217700 /*0xab2b24*/;
    // 00aab91d  e969000000             -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab922:
    // 00aab922  ba7c2bab00             -mov edx, 0xab2b7c
    cpu.edx = 11217788 /*0xab2b7c*/;
    // 00aab927  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab929  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aab92c  e88bfeffff             -call 0xaab7bc
    cpu.esp -= 4;
    sub_aab7bc(app, cpu);
    if (cpu.terminate) return;
    // 00aab931  bab02bab00             -mov edx, 0xab2bb0
    cpu.edx = 11217840 /*0xab2bb0*/;
    // 00aab936  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab938  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00aab93b  e87cfeffff             -call 0xaab7bc
    cpu.esp -= 4;
    sub_aab7bc(app, cpu);
    if (cpu.terminate) return;
    // 00aab940  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 00aab944  750b                   -jne 0xaab951
    if (!cpu.flags.zf)
    {
        goto L_0x00aab951;
    }
    // 00aab946  bad82bab00             -mov edx, 0xab2bd8
    cpu.edx = 11217880 /*0xab2bd8*/;
    // 00aab94b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab94d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aab94f  eb3f                   -jmp 0xaab990
    goto L_0x00aab990;
L_0x00aab951:
    // 00aab951  bae02bab00             -mov edx, 0xab2be0
    cpu.edx = 11217888 /*0xab2be0*/;
    // 00aab956  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab958  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aab95a  eb34                   -jmp 0xaab990
    goto L_0x00aab990;
L_0x00aab95c:
    // 00aab95c  baec2bab00             -mov edx, 0xab2bec
    cpu.edx = 11217900 /*0xab2bec*/;
    // 00aab961  eb28                   -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab963:
    // 00aab963  ba2c2cab00             -mov edx, 0xab2c2c
    cpu.edx = 11217964 /*0xab2c2c*/;
    // 00aab968  eb21                   -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab96a:
    // 00aab96a  ba682cab00             -mov edx, 0xab2c68
    cpu.edx = 11218024 /*0xab2c68*/;
    // 00aab96f  eb1a                   -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab971:
    // 00aab971  baac2cab00             -mov edx, 0xab2cac
    cpu.edx = 11218092 /*0xab2cac*/;
    // 00aab976  eb13                   -jmp 0xaab98b
    goto L_0x00aab98b;
L_0x00aab978:
    // 00aab978  bae82cab00             -mov edx, 0xab2ce8
    cpu.edx = 11218152 /*0xab2ce8*/;
    // 00aab97d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab97f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aab981  e836feffff             -call 0xaab7bc
    cpu.esp -= 4;
    sub_aab7bc(app, cpu);
    if (cpu.terminate) return;
    // 00aab986  ba1c2dab00             -mov edx, 0xab2d1c
    cpu.edx = 11218204 /*0xab2d1c*/;
L_0x00aab98b:
    // 00aab98b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab98d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00aab990:
    // 00aab990  e827feffff             -call 0xaab7bc
    cpu.esp -= 4;
    sub_aab7bc(app, cpu);
    if (cpu.terminate) return;
    // 00aab995  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab997  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00aab99e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab99f  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aab9a3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aab9a4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aab9a6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aab9a8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aab9aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00aab9ab  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aab9ad  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aab9af  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aab9b1  49                     -dec ecx
    (cpu.ecx)--;
    // 00aab9b2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aab9b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab9b4  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aab9b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab9b9  a10838ab00             -mov eax, dword ptr [0xab3808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab9be  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aab9c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab9c2  2eff154014ab00         -call dword ptr cs:[0xab1440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211840) /* 0xab1440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab9c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aab9ce:
    // 00aab9ce  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00aab9d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab9d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab9d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aab9f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aab9f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab9f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab9fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab9fb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aab9fe  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00aaba02  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aaba06  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00aaba0a  0f85a1010000           -jne 0xaabbb1
    if (!cpu.flags.zf)
    {
        goto L_0x00aabbb1;
    }
    // 00aaba10  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaba12  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00aaba17  83f806                 +cmp eax, 6
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
    // 00aaba1a  0f871f010000           -ja 0xaabb3f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aabb3f;
    }
    // 00aaba20  2eff2485dcb9aa00       -jmp dword ptr cs:[eax*4 + 0xaab9dc]
    cpu.ip = app->getMemory<x86::reg32>(11188700 + cpu.eax * 4); goto dynamic_jump;
  case 0x00aaba28:
    // 00aaba28  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00aaba2c  740a                   -je 0xaaba38
    if (cpu.flags.zf)
    {
        goto L_0x00aaba38;
    }
    // 00aaba2e  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00aaba33  e9ca000000             -jmp 0xaabb02
    goto L_0x00aabb02;
L_0x00aaba38:
    // 00aaba38  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00aaba3d  e9c0000000             -jmp 0xaabb02
    goto L_0x00aabb02;
  case 0x00aaba42:
    // 00aaba42  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00aaba47  e9b6000000             -jmp 0xaabb02
    goto L_0x00aabb02;
  case 0x00aaba4c:
    // 00aaba4c  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00aaba51  e9ac000000             -jmp 0xaabb02
    goto L_0x00aabb02;
  case 0x00aaba56:
    // 00aaba56  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00aaba5b  e9a2000000             -jmp 0xaabb02
    goto L_0x00aabb02;
  case 0x00aaba60:
    // 00aaba60  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00aaba65  e998000000             -jmp 0xaabb02
    goto L_0x00aabb02;
  case 0x00aaba6a:
    // 00aaba6a  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00aaba6d  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00aaba70  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00aaba75  6681fad9fa             +cmp dx, 0xfad9
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
    // 00aaba7a  750a                   -jne 0xaaba86
    if (!cpu.flags.zf)
    {
        goto L_0x00aaba86;
    }
    // 00aaba7c  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00aaba81  e97c000000             -jmp 0xaabb02
    goto L_0x00aabb02;
L_0x00aaba86:
    // 00aaba86  6681fad9f1             +cmp dx, 0xf1d9
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
    // 00aaba8b  750a                   -jne 0xaaba97
    if (!cpu.flags.zf)
    {
        goto L_0x00aaba97;
    }
    // 00aaba8d  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00aaba92  e96b000000             -jmp 0xaabb02
    goto L_0x00aabb02;
L_0x00aaba97:
    // 00aaba97  750a                   -jne 0xaabaa3
    if (!cpu.flags.zf)
    {
        goto L_0x00aabaa3;
    }
    // 00aaba99  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00aaba9e  e95f000000             -jmp 0xaabb02
    goto L_0x00aabb02;
L_0x00aabaa3:
    // 00aabaa3  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabaa5  80fedb                 +cmp dh, 0xdb
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
    // 00aabaa8  7405                   -je 0xaabaaf
    if (cpu.flags.zf)
    {
        goto L_0x00aabaaf;
    }
    // 00aabaaa  80fedf                 +cmp dh, 0xdf
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
    // 00aabaad  7510                   -jne 0xaababf
    if (!cpu.flags.zf)
    {
        goto L_0x00aababf;
    }
L_0x00aabaaf:
    // 00aabaaf  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aabab2  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00aabab5  80fa10                 +cmp dl, 0x10
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
    // 00aabab8  7505                   -jne 0xaababf
    if (!cpu.flags.zf)
    {
        goto L_0x00aababf;
    }
    // 00aababa  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00aababf:
    // 00aababf  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00aabac2  7539                   -jne 0xaabafd
    if (!cpu.flags.zf)
    {
        goto L_0x00aabafd;
    }
    // 00aabac4  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aabac7  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00aabac9  3c30                   +cmp al, 0x30
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
    // 00aabacb  7530                   -jne 0xaabafd
    if (!cpu.flags.zf)
    {
        goto L_0x00aabafd;
    }
    // 00aabacd  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00aabad0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aabad5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aabad8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aabada  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00aabade  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00aabae1  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00aabae4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aabaea  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aabaec  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00aabaee  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00aabaf1  83fa01                 +cmp edx, 1
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
    // 00aabaf4  7507                   -jne 0xaabafd
    if (!cpu.flags.zf)
    {
        goto L_0x00aabafd;
    }
  [[fallthrough]];
  case 0x00aabaf6:
    // 00aabaf6  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00aabafb  eb05                   -jmp 0xaabb02
    goto L_0x00aabb02;
L_0x00aabafd:
    // 00aabafd  83fbff                 +cmp ebx, -1
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
    // 00aabb00  743d                   -je 0xaabb3f
    if (cpu.flags.zf)
    {
        goto L_0x00aabb3f;
    }
L_0x00aabb02:
    // 00aabb02  c605245aab0001         -mov byte ptr [0xab5a24], 1
    app->getMemory<x86::reg8>(x86::reg32(11229732) /* 0xab5a24 */) = 1 /*0x1*/;
    // 00aabb09  e8b2160000             -call 0xaad1c0
    cpu.esp -= 4;
    sub_aad1c0(app, cpu);
    if (cpu.terminate) return;
    // 00aabb0e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabb10  e87f180000             -call 0xaad394
    cpu.esp -= 4;
    sub_aad394(app, cpu);
    if (cpu.terminate) return;
    // 00aabb15  83f8ff                 +cmp eax, -1
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
    // 00aabb18  0f8474000000           -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb1e  803d245aab0000         +cmp byte ptr [0xab5a24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11229732) /* 0xab5a24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aabb25  0f8467000000           -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb2b  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00aabb2f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00aabb31  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00aabb34  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aabb36  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00aabb3a  e977000000             -jmp 0xaabbb6
    goto L_0x00aabbb6;
L_0x00aabb3f:
    // 00aabb3f  833d1838ab0000         +cmp dword ptr [0xab3818], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11221016) /* 0xab3818 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aabb46  744a                   -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb48  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aabb4d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00aabb4f:
    // 00aabb4f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabb51  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aabb53  ff151438ab00           -call dword ptr [0xab3814]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11221012) /* 0xab3814 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabb59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabb5b  742f                   -je 0xaabb8c
    if (cpu.flags.zf)
    {
        goto L_0x00aabb8c;
    }
    // 00aabb5d  83f801                 +cmp eax, 1
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
    // 00aabb60  7430                   -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb62  83f802                 +cmp eax, 2
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
    // 00aabb65  742b                   -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb67  83f803                 +cmp eax, 3
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
    // 00aabb6a  7426                   -je 0xaabb92
    if (cpu.flags.zf)
    {
        goto L_0x00aabb92;
    }
    // 00aabb6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabb6e  880d245aab00           -mov byte ptr [0xab5a24], cl
    app->getMemory<x86::reg8>(x86::reg32(11229732) /* 0xab5a24 */) = cpu.cl;
    // 00aabb74  ff151838ab00           -call dword ptr [0xab3818]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11221016) /* 0xab3818 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabb7a  803d245aab0000         +cmp byte ptr [0xab5a24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11229732) /* 0xab5a24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aabb81  7409                   -je 0xaabb8c
    if (cpu.flags.zf)
    {
        goto L_0x00aabb8c;
    }
    // 00aabb83  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabb85  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aabb88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabb89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabb8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabb8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aabb8c:
    // 00aabb8c  43                     -inc ebx
    (cpu.ebx)++;
    // 00aabb8d  83fb0c                 +cmp ebx, 0xc
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
    // 00aabb90  7ebd                   -jle 0xaabb4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aabb4f;
    }
L_0x00aabb92:
    // 00aabb92  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aabb94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aabb95  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00aabb99  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00aabb9d  2eff152814ab00         -call dword ptr cs:[0xab1428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211816) /* 0xab1428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabba4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabba6  7409                   -je 0xaabbb1
    if (cpu.flags.zf)
    {
        goto L_0x00aabbb1;
    }
    // 00aabba8  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00aabbaa  2eff158013ab00         -call dword ptr cs:[0xab1380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211648) /* 0xab1380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aabbb1:
    // 00aabbb1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aabbb6:
    // 00aabbb6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aabbb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabbba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabbbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabbbc  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aabbc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabbc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabbc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabbc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aabbc4  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabbca  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00aabbcd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabbcf  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00aabbd2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aabbd4  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabbda  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00aabbdd  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aabbdf  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabbe5  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00aabbe8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aabbea  c74004f8b9aa00         -mov dword ptr [eax + 4], 0xaab9f8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 11188728 /*0xaab9f8*/;
    // 00aabbf1  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabbf7  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00aabbfa  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00aabbfd  6814b8aa00             -push 0xaab814
    app->getMemory<x86::reg32>(cpu.esp-4) = 11188244 /*0xaab814*/;
    cpu.esp -= 4;
    // 00aabc02  2eff151414ab00         -call dword ptr cs:[0xab1414]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211796) /* 0xab1414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabc09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabc0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabc0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aabc0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabc0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabc0d  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabc13  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00aabc16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabc18  7407                   -je 0xaabc21
    if (cpu.flags.zf)
    {
        goto L_0x00aabc21;
    }
    // 00aabc1a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aabc1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aabc1e  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00aabc21:
    // 00aabc21  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabc27  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00aabc2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabc2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aabc30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabc30  e97bc0ffff             -jmp 0xaa7cb0
    return sub_aa7cb0(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aabc38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabc38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabc39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabc3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabc3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aabc3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aabc3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aabc3e  8b3da44eab00           -mov edi, dword ptr [0xab4ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aabc44  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aabc46  0f85c1000000           -jne 0xaabd0d
    if (!cpu.flags.zf)
    {
        goto L_0x00aabd0d;
    }
    // 00aabc4c  8b2d7d37ab00           -mov ebp, dword ptr [0xab377d]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11220861) /* 0xab377d */);
    // 00aabc52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aabc54  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00aabc57  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aabc59  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aabc5b  7416                   -je 0xaabc73
    if (cpu.flags.zf)
    {
        goto L_0x00aabc73;
    }
L_0x00aabc5d:
    // 00aabc5d  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabc5f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aabc62  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00aabc64  7404                   -je 0xaabc6a
    if (cpu.flags.zf)
    {
        goto L_0x00aabc6a;
    }
    // 00aabc66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabc68  ebf3                   -jmp 0xaabc5d
    goto L_0x00aabc5d;
L_0x00aabc6a:
    // 00aabc6a  41                     -inc ecx
    (cpu.ecx)++;
    // 00aabc6b  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 00aabc6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabc6f  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00aabc71  75ea                   -jne 0xaabc5d
    if (!cpu.flags.zf)
    {
        goto L_0x00aabc5d;
    }
L_0x00aabc73:
    // 00aabc73  893da44eab00           -mov dword ptr [0xab4ea4], edi
    app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */) = cpu.edi;
    // 00aabc79  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aabc7b  7505                   -jne 0xaabc82
    if (!cpu.flags.zf)
    {
        goto L_0x00aabc82;
    }
    // 00aabc7d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aabc82:
    // 00aabc82  e829c0ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aabc87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aabc89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aabc8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabc8d  0f8475000000           -je 0xaabd08
    if (cpu.flags.zf)
    {
        goto L_0x00aabd08;
    }
    // 00aabc93  a3305aab00             -mov dword ptr [0xab5a30], eax
    app->getMemory<x86::reg32>(x86::reg32(11229744) /* 0xab5a30 */) = cpu.eax;
    // 00aabc98  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00aabc9f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aabca2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aabca4  e807c0ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aabca9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabcab  7454                   -je 0xaabd01
    if (cpu.flags.zf)
    {
        goto L_0x00aabd01;
    }
    // 00aabcad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aabcaf  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00aabcb2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aabcb4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aabcb6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aabcb8  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aabcba  741a                   -je 0xaabcd6
    if (cpu.flags.zf)
    {
        goto L_0x00aabcd6;
    }
L_0x00aabcbc:
    // 00aabcbc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aabcbe  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00aabcc1:
    // 00aabcc1  43                     -inc ebx
    (cpu.ebx)++;
    // 00aabcc2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabcc4  40                     -inc eax
    (cpu.eax)++;
    // 00aabcc5  8853ff                 -mov byte ptr [ebx - 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00aabcc8  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aabcca  75f5                   -jne 0xaabcc1
    if (!cpu.flags.zf)
    {
        goto L_0x00aabcc1;
    }
    // 00aabccc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aabccf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabcd1  46                     -inc esi
    (cpu.esi)++;
    // 00aabcd2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aabcd4  75e6                   -jne 0xaabcbc
    if (!cpu.flags.zf)
    {
        goto L_0x00aabcbc;
    }
L_0x00aabcd6:
    // 00aabcd6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aabcd8  c7040100000000         -mov dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 00aabcdf  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aabce2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aabce4  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00aabce7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aabce9  a3a04eab00             -mov dword ptr [0xab4ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11226784) /* 0xab4ea0 */) = cpu.eax;
    // 00aabcee  893da44eab00           -mov dword ptr [0xab4ea4], edi
    app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */) = cpu.edi;
    // 00aabcf4  e8b7bdffff             -call 0xaa7ab0
    cpu.esp -= 4;
    sub_aa7ab0(app, cpu);
    if (cpu.terminate) return;
    // 00aabcf9  8b3da44eab00           -mov edi, dword ptr [0xab4ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aabcff  eb07                   -jmp 0xaabd08
    goto L_0x00aabd08;
L_0x00aabd01:
    // 00aabd01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aabd03  e898c0ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
L_0x00aabd08:
    // 00aabd08  e883180000             -call 0xaad590
    cpu.esp -= 4;
    sub_aad590(app, cpu);
    if (cpu.terminate) return;
L_0x00aabd0d:
    // 00aabd0d  8b3da44eab00           -mov edi, dword ptr [0xab4ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aabd13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aabd1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabd1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabd1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabd1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabd1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aabd20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aabd21  e88a190000             -call 0xaad6b0
    cpu.esp -= 4;
    sub_aad6b0(app, cpu);
    if (cpu.terminate) return;
    // 00aabd26  8b15a44eab00           -mov edx, dword ptr [0xab4ea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aabd2c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aabd2e  740f                   -je 0xaabd3f
    if (cpu.flags.zf)
    {
        goto L_0x00aabd3f;
    }
    // 00aabd30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aabd32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aabd34  e867c0ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aabd39  891da44eab00           -mov dword ptr [0xab4ea4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */) = cpu.ebx;
L_0x00aabd3f:
    // 00aabd3f  8b0d305aab00           -mov ecx, dword ptr [0xab5a30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11229744) /* 0xab5a30 */);
    // 00aabd45  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aabd47  740f                   -je 0xaabd58
    if (cpu.flags.zf)
    {
        goto L_0x00aabd58;
    }
    // 00aabd49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aabd4b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aabd4d  e84ec0ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aabd52  8935305aab00           -mov dword ptr [0xab5a30], esi
    app->getMemory<x86::reg32>(x86::reg32(11229744) /* 0xab5a30 */) = cpu.esi;
L_0x00aabd58:
    // 00aabd58  8b3d7d37ab00           -mov edi, dword ptr [0xab377d]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11220861) /* 0xab377d */);
    // 00aabd5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aabd60  7408                   -je 0xaabd6a
    if (cpu.flags.zf)
    {
        goto L_0x00aabd6a;
    }
    // 00aabd62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aabd63  2eff158c13ab00         -call dword ptr cs:[0xab138c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211660) /* 0xab138c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aabd6a:
    // 00aabd6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aabd70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabd70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabd71  803800                 +cmp byte ptr [eax], 0
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
    // 00aabd74  7507                   -jne 0xaabd7d
    if (!cpu.flags.zf)
    {
        goto L_0x00aabd7d;
    }
    // 00aabd76  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aabd7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabd7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aabd7d:
    // 00aabd7d  833d505aab0000         +cmp dword ptr [0xab5a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aabd84  7422                   -je 0xaabda8
    if (cpu.flags.zf)
    {
        goto L_0x00aabda8;
    }
    // 00aabd86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aabd88  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabd8a  8a92615aab00           -mov dl, byte ptr [edx + 0xab5a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aabd90  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aabd93  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aabd99  740d                   -je 0xaabda8
    if (cpu.flags.zf)
    {
        goto L_0x00aabda8;
    }
    // 00aabd9b  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aabd9f  7507                   -jne 0xaabda8
    if (!cpu.flags.zf)
    {
        goto L_0x00aabda8;
    }
    // 00aabda1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00aabda6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabda7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aabda8:
    // 00aabda8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabdaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabdab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_aabdb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabdb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabdb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabdb2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aabdb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aabdb7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aabdb9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aabdbb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aabdbd  e88e190000             -call 0xaad750
    cpu.esp -= 4;
    sub_aad750(app, cpu);
    if (cpu.terminate) return;
    // 00aabdc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aabdc4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aabdc6  e8c5190000             -call 0xaad790
    cpu.esp -= 4;
    sub_aad790(app, cpu);
    if (cpu.terminate) return;
    // 00aabdcb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00aabdce  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aabdd2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aabdd4  e877190000             -call 0xaad750
    cpu.esp -= 4;
    sub_aad750(app, cpu);
    if (cpu.terminate) return;
    // 00aabdd9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aabddb  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00aabddd  e8ae190000             -call 0xaad790
    cpu.esp -= 4;
    sub_aad790(app, cpu);
    if (cpu.terminate) return;
    // 00aabde2  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00aabde6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aabde8  e8d3190000             -call 0xaad7c0
    cpu.esp -= 4;
    sub_aad7c0(app, cpu);
    if (cpu.terminate) return;
    // 00aabded  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aabdf1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aabdf5  e8c6190000             -call 0xaad7c0
    cpu.esp -= 4;
    sub_aad7c0(app, cpu);
    if (cpu.terminate) return;
    // 00aabdfa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aabdfc  e80f1a0000             -call 0xaad810
    cpu.esp -= 4;
    sub_aad810(app, cpu);
    if (cpu.terminate) return;
    // 00aabe01  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aabe04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aabe10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabe10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabe11  833d505aab0000         +cmp dword ptr [0xab5a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aabe18  7420                   -je 0xaabe3a
    if (cpu.flags.zf)
    {
        goto L_0x00aabe3a;
    }
    // 00aabe1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aabe1c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aabe1e  8a92615aab00           -mov dl, byte ptr [edx + 0xab5a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aabe24  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aabe27  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aabe2d  740b                   -je 0xaabe3a
    if (cpu.flags.zf)
    {
        goto L_0x00aabe3a;
    }
    // 00aabe2f  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aabe33  7405                   -je 0xaabe3a
    if (cpu.flags.zf)
    {
        goto L_0x00aabe3a;
    }
    // 00aabe35  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aabe38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aabe3a:
    // 00aabe3a  40                     -inc eax
    (cpu.eax)++;
    // 00aabe3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_aabe40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabe40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabe41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabe42  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aabe44  ff15c436ab00           -call dword ptr [0xab36c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220676) /* 0xab36c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabe4a  8b153038ab00           -mov edx, dword ptr [0xab3830]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221040) /* 0xab3830 */);
    // 00aabe50  891d3038ab00           -mov dword ptr [0xab3830], ebx
    app->getMemory<x86::reg32>(x86::reg32(11221040) /* 0xab3830 */) = cpu.ebx;
    // 00aabe56  ff15cc36ab00           -call dword ptr [0xab36cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220684) /* 0xab36cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabe5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aabe5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabe60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aabe70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabe70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabe71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabe72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabe73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aabe74  ff15c436ab00           -call dword ptr [0xab36c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220676) /* 0xab36c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabe7a  a17c36ab00             -mov eax, dword ptr [0xab367c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */);
    // 00aabe7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabe81  741c                   -je 0xaabe9f
    if (cpu.flags.zf)
    {
        goto L_0x00aabe9f;
    }
L_0x00aabe83:
    // 00aabe83  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aabe85  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00aabe88  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aabe8b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aabe8d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aabe90  39f3                   +cmp ebx, esi
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
    // 00aabe92  7505                   -jne 0xaabe99
    if (!cpu.flags.zf)
    {
        goto L_0x00aabe99;
    }
    // 00aabe94  e873000000             -call 0xaabf0c
    cpu.esp -= 4;
    sub_aabf0c(app, cpu);
    if (cpu.terminate) return;
L_0x00aabe99:
    // 00aabe99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aabe9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aabe9d  75e4                   -jne 0xaabe83
    if (!cpu.flags.zf)
    {
        goto L_0x00aabe83;
    }
L_0x00aabe9f:
    // 00aabe9f  ff15cc36ab00           -call dword ptr [0xab36cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220684) /* 0xab36cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabea5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabea7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabea8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabeaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabeab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aabeac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabeac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabead  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabeae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabeaf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aabeb0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aabeb1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aabeb3  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00aabeb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aabeba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aabebb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aabebe  2eff153014ab00         -call dword ptr cs:[0xab1430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211824) /* 0xab1430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aabec5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabec7  7507                   -jne 0xaabed0
    if (!cpu.flags.zf)
    {
        goto L_0x00aabed0;
    }
    // 00aabec9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aabece  eb36                   -jmp 0xaabf06
    goto L_0x00aabf06;
L_0x00aabed0:
    // 00aabed0  3b1d8036ab00           +cmp ebx, dword ptr [0xab3680]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aabed6  751c                   -jne 0xaabef4
    if (!cpu.flags.zf)
    {
        goto L_0x00aabef4;
    }
    // 00aabed8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aabeda  7408                   -je 0xaabee4
    if (cpu.flags.zf)
    {
        goto L_0x00aabee4;
    }
    // 00aabedc  89358036ab00           -mov dword ptr [0xab3680], esi
    app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */) = cpu.esi;
    // 00aabee2  eb10                   -jmp 0xaabef4
    goto L_0x00aabef4;
L_0x00aabee4:
    // 00aabee4  a17c36ab00             -mov eax, dword ptr [0xab367c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */);
    // 00aabee9  89358436ab00           -mov dword ptr [0xab3684], esi
    app->getMemory<x86::reg32>(x86::reg32(11220612) /* 0xab3684 */) = cpu.esi;
    // 00aabeef  a38036ab00             -mov dword ptr [0xab3680], eax
    app->getMemory<x86::reg32>(x86::reg32(11220608) /* 0xab3680 */) = cpu.eax;
L_0x00aabef4:
    // 00aabef4  3b1d5048ab00           +cmp ebx, dword ptr [0xab4850]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11225168) /* 0xab4850 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aabefa  7508                   -jne 0xaabf04
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf04;
    }
    // 00aabefc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00aabefe  893d5048ab00           -mov dword ptr [0xab4850], edi
    app->getMemory<x86::reg32>(x86::reg32(11225168) /* 0xab4850 */) = cpu.edi;
L_0x00aabf04:
    // 00aabf04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aabf06:
    // 00aabf06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aabf0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabf0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aabf0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aabf0e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aabf11  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aabf14  e893ffffff             -call 0xaabeac
    cpu.esp -= 4;
    sub_aabeac(app, cpu);
    if (cpu.terminate) return;
    // 00aabf19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aabf1b  7516                   -jne 0xaabf33
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf33;
    }
    // 00aabf1d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aabf1f  7508                   -jne 0xaabf29
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf29;
    }
    // 00aabf21  89157c36ab00           -mov dword ptr [0xab367c], edx
    app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */) = cpu.edx;
    // 00aabf27  eb03                   -jmp 0xaabf2c
    goto L_0x00aabf2c;
L_0x00aabf29:
    // 00aabf29  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00aabf2c:
    // 00aabf2c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aabf2e  7403                   -je 0xaabf33
    if (cpu.flags.zf)
    {
        goto L_0x00aabf33;
    }
    // 00aabf30  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00aabf33:
    // 00aabf33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aabf35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aabf40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aabf40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aabf41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aabf43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aabf44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aabf45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aabf46  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00aabf49  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aabf4b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aabf4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabf4f  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00aabf52  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00aabf55  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00aabf58  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aabf5b  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 00aabf5d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aabf62  83f847                 +cmp eax, 0x47
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
    // 00aabf65  7523                   -jne 0xaabf8a
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf8a;
    }
    // 00aabf67  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aabf69  7505                   -jne 0xaabf70
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf70;
    }
    // 00aabf6b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00aabf70:
    // 00aabf70  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 00aabf77  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00aabf7a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aabf7f  83ef02                 +sub edi, 2
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
    // 00aabf82  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00aabf85  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 00aabf88  eb1f                   -jmp 0xaabfa9
    goto L_0x00aabfa9;
L_0x00aabf8a:
    // 00aabf8a  83f845                 +cmp eax, 0x45
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
    // 00aabf8d  750d                   -jne 0xaabf9c
    if (!cpu.flags.zf)
    {
        goto L_0x00aabf9c;
    }
    // 00aabf8f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00aabf94  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00aabf97  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 00aabf9a  eb0d                   -jmp 0xaabfa9
    goto L_0x00aabfa9;
L_0x00aabf9c:
    // 00aabf9c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00aabfa1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aabfa3  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00aabfa6  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x00aabfa9:
    // 00aabfa9  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00aabfad  7404                   -je 0xaabfb3
    if (cpu.flags.zf)
    {
        goto L_0x00aabfb3;
    }
    // 00aabfaf  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00aabfb3:
    // 00aabfb3  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aabfb5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aabfb8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aabfba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aabfbc  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00aabfbf  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00aabfc2  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00aabfc5  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00aabfc8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00aabfcb  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00aabfce  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 00aabfd0  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aabfd2  83fbff                 +cmp ebx, -1
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
    // 00aabfd5  7505                   -jne 0xaabfdc
    if (!cpu.flags.zf)
    {
        goto L_0x00aabfdc;
    }
    // 00aabfd7  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x00aabfdc:
    // 00aabfdc  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00aabfdf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aabfe1  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 00aabfe4  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 00aabfe7  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aabfea  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00aabfed  e8ae190000             -call 0xaad9a0
    cpu.esp -= 4;
    sub_aad9a0(app, cpu);
    if (cpu.terminate) return;
    // 00aabff2  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00aabff5  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00aabff8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00aabffb  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00aabffe  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00aac001  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00aac004  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00aac007  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00aac00a  837dc800               +cmp dword ptr [ebp - 0x38], 0
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
    // 00aac00e  7d0f                   -jge 0xaac01f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aac01f;
    }
    // 00aac010  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aac013  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aac016  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aac019  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00aac01d  eb29                   -jmp 0xaac048
    goto L_0x00aac048;
L_0x00aac01f:
    // 00aac01f  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aac022  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00aac025  740f                   -je 0xaac036
    if (cpu.flags.zf)
    {
        goto L_0x00aac036;
    }
    // 00aac027  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aac02a  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aac02d  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aac030  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00aac034  eb12                   -jmp 0xaac048
    goto L_0x00aac048;
L_0x00aac036:
    // 00aac036  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00aac039  740d                   -je 0xaac048
    if (cpu.flags.zf)
    {
        goto L_0x00aac048;
    }
    // 00aac03b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aac03e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aac041  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aac044  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00aac048:
    // 00aac048  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aac04a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aac04c  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00aac04f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac050  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac052  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac054(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac054  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac055  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00aac057  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac059  e88c240000             -call 0xaae4ea
    cpu.esp -= 4;
    sub_aae4ea(app, cpu);
    if (cpu.terminate) return;
    // 00aac05e  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aac060  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac061  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac070(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac071  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aac076  b8482dab00             -mov eax, 0xab2d48
    cpu.eax = 11218248 /*0xab2d48*/;
    // 00aac07b  e87cedffff             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
    // 00aac080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac081  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac090(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac090  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac0a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac0a0  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 00aac0a2  9b                     -wait 
    /*nothing*/;
    // 00aac0a3  dbe3                   +fninit 
    cpu.fpu.init();
    // 00aac0a5  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00aac0a7  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aac0a9  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aac0ab  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00aac0ad  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00aac0af  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00aac0b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aac0b3  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00aac0b5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aac0b6  7402                   -je 0xaac0ba
    if (cpu.flags.zf)
    {
        goto L_0x00aac0ba;
    }
    // 00aac0b8  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x00aac0ba:
    // 00aac0ba  9b                     -wait 
    /*nothing*/;
    // 00aac0bb  dbe3                   -fninit 
    cpu.fpu.init();
    // 00aac0bd  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00aac0c0  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 00aac0c4  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aac0c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac0d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac0d1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00aac0d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac0d6  e8d5bbffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aac0db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac0dd  7407                   -je 0xaac0e6
    if (cpu.flags.zf)
    {
        goto L_0x00aac0e6;
    }
    // 00aac0df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac0e1  e8cab9ffff             -call 0xaa7ab0
    cpu.esp -= 4;
    sub_aa7ab0(app, cpu);
    if (cpu.terminate) return;
L_0x00aac0e6:
    // 00aac0e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac0e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac0f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac0f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac0f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac0f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac0f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac0f7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aac0f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac0fb  7509                   -jne 0xaac106
    if (!cpu.flags.zf)
    {
        goto L_0x00aac106;
    }
    // 00aac0fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac0ff  e8acbbffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aac104  eb62                   -jmp 0xaac168
    goto L_0x00aac168;
L_0x00aac106:
    // 00aac106  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aac108  750d                   -jne 0xaac117
    if (!cpu.flags.zf)
    {
        goto L_0x00aac117;
    }
    // 00aac10a  e891bcffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aac10f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac111  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac115  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac117:
    // 00aac117  e8b4240000             -call 0xaae5d0
    cpu.esp -= 4;
    sub_aae5d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac11c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aac11e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac120  e8bb240000             -call 0xaae5e0
    cpu.esp -= 4;
    sub_aae5e0(app, cpu);
    if (cpu.terminate) return;
    // 00aac125  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aac127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac129  753b                   -jne 0xaac166
    if (!cpu.flags.zf)
    {
        goto L_0x00aac166;
    }
    // 00aac12b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac12d  e87ebbffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aac132  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aac134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac136  7425                   -je 0xaac15d
    if (cpu.flags.zf)
    {
        goto L_0x00aac15d;
    }
    // 00aac138  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00aac13a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aac13c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00aac13e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aac13f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aac141  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aac143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac144  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac146  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00aac149  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aac14b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00aac14d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00aac150  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00aac152  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac153  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aac154  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac156  e845bcffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aac15b  eb09                   -jmp 0xaac166
    goto L_0x00aac166;
L_0x00aac15d:
    // 00aac15d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aac15f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac161  e87a240000             -call 0xaae5e0
    cpu.esp -= 4;
    sub_aae5e0(app, cpu);
    if (cpu.terminate) return;
L_0x00aac166:
    // 00aac166  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00aac168:
    // 00aac168  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac169  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac16a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac16b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac16c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac16d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aac170(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac173  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac175  e81ed7ffff             -call 0xaa9898
    cpu.esp -= 4;
    sub_aa9898(app, cpu);
    if (cpu.terminate) return;
    // 00aac17a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac17c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac17e  7410                   -je 0xaac190
    if (cpu.flags.zf)
    {
        goto L_0x00aac190;
    }
    // 00aac180  8b15a436ab00           -mov edx, dword ptr [0xab36a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aac186  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac187  2eff152014ab00         -call dword ptr cs:[0xab1420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211808) /* 0xab1420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac18e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00aac190:
    // 00aac190  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aac192  750f                   -jne 0xaac1a3
    if (!cpu.flags.zf)
    {
        goto L_0x00aac1a3;
    }
    // 00aac194  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aac199  b86c2dab00             -mov eax, 0xab2d6c
    cpu.eax = 11218284 /*0xab2d6c*/;
    // 00aac19e  e859ecffff             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
L_0x00aac1a3:
    // 00aac1a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac1a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac1a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac1a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aac1ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac1ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac1ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac1ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac1af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac1b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac1b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac1b2  ff15d436ab00           -call dword ptr [0xab36d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac1b8  2eff15ac13ab00         -call dword ptr cs:[0xab13ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211692) /* 0xab13ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac1bf  8b1d405aab00           -mov ebx, dword ptr [0xab5a40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */);
    // 00aac1c5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aac1c7  740b                   -je 0xaac1d4
    if (cpu.flags.zf)
    {
        goto L_0x00aac1d4;
    }
L_0x00aac1c9:
    // 00aac1c9  3b4304                 +cmp eax, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac1cc  7406                   -je 0xaac1d4
    if (cpu.flags.zf)
    {
        goto L_0x00aac1d4;
    }
    // 00aac1ce  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aac1d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aac1d2  75f5                   -jne 0xaac1c9
    if (!cpu.flags.zf)
    {
        goto L_0x00aac1c9;
    }
L_0x00aac1d4:
    // 00aac1d4  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 00aac1d8  7425                   -je 0xaac1ff
    if (cpu.flags.zf)
    {
        goto L_0x00aac1ff;
    }
    // 00aac1da  8b154c38ab00           -mov edx, dword ptr [0xab384c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aac1e0  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aac1e3  e808ffffff             -call 0xaac0f0
    cpu.esp -= 4;
    sub_aac0f0(app, cpu);
    if (cpu.terminate) return;
    // 00aac1e8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aac1ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac1ec  755e                   -jne 0xaac24c
    if (!cpu.flags.zf)
    {
        goto L_0x00aac24c;
    }
    // 00aac1ee  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aac1f3  b8942dab00             -mov eax, 0xab2d94
    cpu.eax = 11218324 /*0xab2d94*/;
    // 00aac1f8  e8ffebffff             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
    // 00aac1fd  eb4d                   -jmp 0xaac24c
    goto L_0x00aac24c;
L_0x00aac1ff:
    // 00aac1ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aac204  8b154c38ab00           -mov edx, dword ptr [0xab384c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aac20a  e8c1feffff             -call 0xaac0d0
    cpu.esp -= 4;
    sub_aac0d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac20f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aac211  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac213  750f                   -jne 0xaac224
    if (!cpu.flags.zf)
    {
        goto L_0x00aac224;
    }
    // 00aac215  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aac21a  b8bc2dab00             -mov eax, 0xab2dbc
    cpu.eax = 11218364 /*0xab2dbc*/;
    // 00aac21f  e8d8ebffff             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
L_0x00aac224:
    // 00aac224  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aac227  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00aac229  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00aac22f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aac230  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aac232  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aac234  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac235  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac237  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00aac23a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aac23c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00aac23e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00aac241  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00aac243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac244  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aac245  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00aac24c:
    // 00aac24c  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00aac24f  a14c38ab00             -mov eax, dword ptr [0xab384c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aac254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac255  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00aac259  8b35a436ab00           -mov esi, dword ptr [0xab36a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aac25f  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00aac263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac264  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00aac26a  2eff152414ab00         -call dword ptr cs:[0xab1424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211812) /* 0xab1424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac271  ff15d836ab00           -call dword ptr [0xab36d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac277  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aac279  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac27f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac280(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac283  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aac285  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00aac287  ff15d436ab00           -call dword ptr [0xab36d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac28d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00aac292  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00aac297  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac299  e832feffff             -call 0xaac0d0
    cpu.esp -= 4;
    sub_aac0d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac29e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aac2a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac2a2  742f                   -je 0xaac2d3
    if (cpu.flags.zf)
    {
        goto L_0x00aac2d3;
    }
    // 00aac2a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac2a6  e849250000             -call 0xaae7f4
    cpu.esp -= 4;
    sub_aae7f4(app, cpu);
    if (cpu.terminate) return;
    // 00aac2ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac2ad  7409                   -je 0xaac2b8
    if (cpu.flags.zf)
    {
        goto L_0x00aac2b8;
    }
    // 00aac2af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac2b1  e8eabaffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aac2b6  eb1b                   -jmp 0xaac2d3
    goto L_0x00aac2d3;
L_0x00aac2b8:
    // 00aac2b8  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aac2bb  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00aac2be  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00aac2c1  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00aac2c4  a1405aab00             -mov eax, dword ptr [0xab5a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */);
    // 00aac2c9  8915405aab00           -mov dword ptr [0xab5a40], edx
    app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */) = cpu.edx;
    // 00aac2cf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aac2d1  eb02                   -jmp 0xaac2d5
    goto L_0x00aac2d5;
L_0x00aac2d3:
    // 00aac2d3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00aac2d5:
    // 00aac2d5  ff15d836ab00           -call dword ptr [0xab36d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac2db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac2dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac2de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac2df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac2e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aac2e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac2e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac2e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac2e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac2e7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac2e9  ff15d436ab00           -call dword ptr [0xab36d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac2ef  8b15405aab00           -mov edx, dword ptr [0xab5a40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */);
    // 00aac2f5  b9405aab00             -mov ecx, 0xab5a40
    cpu.ecx = 11229760 /*0xab5a40*/;
    // 00aac2fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aac2fc  7428                   -je 0xaac326
    if (cpu.flags.zf)
    {
        goto L_0x00aac326;
    }
L_0x00aac2fe:
    // 00aac2fe  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac301  751b                   -jne 0xaac31e
    if (!cpu.flags.zf)
    {
        goto L_0x00aac31e;
    }
    // 00aac303  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00aac307  7408                   -je 0xaac311
    if (cpu.flags.zf)
    {
        goto L_0x00aac311;
    }
    // 00aac309  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aac30c  e88fbaffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
L_0x00aac311:
    // 00aac311  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aac313  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00aac315  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac317  e884baffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aac31c  eb08                   -jmp 0xaac326
    goto L_0x00aac326;
L_0x00aac31e:
    // 00aac31e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aac320  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aac322  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aac324  75d8                   -jne 0xaac2fe
    if (!cpu.flags.zf)
    {
        goto L_0x00aac2fe;
    }
L_0x00aac326:
    // 00aac326  ff15d836ab00           -call dword ptr [0xab36d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac32c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac32d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac32e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac32f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac330(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac330  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac331  ff15d436ab00           -call dword ptr [0xab36d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac337  a1405aab00             -mov eax, dword ptr [0xab5a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */);
    // 00aac33c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac33e  740d                   -je 0xaac34d
    if (cpu.flags.zf)
    {
        goto L_0x00aac34d;
    }
L_0x00aac340:
    // 00aac340  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aac343  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00aac347  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aac349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac34b  75f3                   -jne 0xaac340
    if (!cpu.flags.zf)
    {
        goto L_0x00aac340;
    }
L_0x00aac34d:
    // 00aac34d  ff15d836ab00           -call dword ptr [0xab36d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac353  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aac358(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac358  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac35a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac35b  8b15405aab00           -mov edx, dword ptr [0xab5a40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11229760) /* 0xab5a40 */);
    // 00aac361  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aac363  741e                   -je 0xaac383
    if (cpu.flags.zf)
    {
        goto L_0x00aac383;
    }
L_0x00aac365:
    // 00aac365  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aac368  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aac36a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aac36c  7408                   -je 0xaac376
    if (cpu.flags.zf)
    {
        goto L_0x00aac376;
    }
    // 00aac36e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aac371  e82abaffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
L_0x00aac376:
    // 00aac376  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac378  e823baffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aac37d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aac37f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aac381  75e2                   -jne 0xaac365
    if (!cpu.flags.zf)
    {
        goto L_0x00aac365;
    }
L_0x00aac383:
    // 00aac383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac391  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac392  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac394  ff15d436ab00           -call dword ptr [0xab36d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac39a  8b154c38ab00           -mov edx, dword ptr [0xab384c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aac3a0  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00aac3a3  a34c38ab00             -mov dword ptr [0xab384c], eax
    app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */) = cpu.eax;
    // 00aac3a8  e883ffffff             -call 0xaac330
    cpu.esp -= 4;
    sub_aac330(app, cpu);
    if (cpu.terminate) return;
    // 00aac3ad  ff15d836ab00           -call dword ptr [0xab36d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac3b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac3b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac3b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac3c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac3c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac3c3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac3c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac3c7  741b                   -je 0xaac3e4
    if (cpu.flags.zf)
    {
        goto L_0x00aac3e4;
    }
    // 00aac3c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac3cb  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00aac3d2  e839f3ffff             -call 0xaab710
    cpu.esp -= 4;
    sub_aab710(app, cpu);
    if (cpu.terminate) return;
    // 00aac3d7  2eff15ac13ab00         -call dword ptr cs:[0xab13ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211692) /* 0xab13ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac3de  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00aac3e4:
    // 00aac3e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac3e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac3e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac3e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aac3f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac3f0  e963ffffff             -jmp 0xaac358
    return sub_aac358(app, cpu);
}

/* align: skip 0x00 */
void sub_aac3f6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac3f6  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aac3f8  750b                   -jne 0xaac405
    if (!cpu.flags.zf)
    {
        goto L_0x00aac405;
    }
    // 00aac3fa  01c9                   +add ecx, ecx
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
    // 00aac3fc  7505                   -jne 0xaac403
    if (!cpu.flags.zf)
    {
        goto L_0x00aac403;
    }
    // 00aac3fe  e94a240000             -jmp 0xaae84d
    return sub_aae84d(app, cpu);
L_0x00aac403:
    // 00aac403  d1d9                   -rcr ecx, 1
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
L_0x00aac405:
    // 00aac405  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac407  7507                   -jne 0xaac410
    if (!cpu.flags.zf)
    {
        goto L_0x00aac410;
    }
    // 00aac409  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac40b  7501                   -jne 0xaac40e
    if (!cpu.flags.zf)
    {
        goto L_0x00aac40e;
    }
    // 00aac40d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac40e:
    // 00aac40e  d1da                   -rcr edx, 1
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
L_0x00aac410:
    // 00aac410  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
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
    // 00aac417  7430                   -je 0xaac449
    if (cpu.flags.zf)
    {
        goto L_0x00aac449;
    }
    // 00aac419  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac41a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac41b  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00aac41e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac41f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac420  f6059036ab0001         +test byte ptr [0xab3690], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(11220624) /* 0xab3690 */) & 1 /*0x1*/));
    // 00aac427  7407                   -je 0xaac430
    if (cpu.flags.zf)
    {
        goto L_0x00aac430;
    }
    // 00aac429  e872c3ffff             -call 0xaa87a0
    cpu.esp -= 4;
    sub_aa87a0(app, cpu);
    if (cpu.terminate) return;
    // 00aac42e  eb06                   -jmp 0xaac436
    goto L_0x00aac436;
L_0x00aac430:
    // 00aac430  dc3424                 -fdiv qword ptr [esp]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.esp));
    // 00aac433  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00aac436:
    // 00aac436  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aac439  9b                     -wait 
    /*nothing*/;
    // 00aac43a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac43b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac43c  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac442  7504                   -jne 0xaac448
    if (!cpu.flags.zf)
    {
        goto L_0x00aac448;
    }
    // 00aac444  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac446  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aac448:
    // 00aac448  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac449:
    // 00aac449  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac44a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aac44c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac44d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac44e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac450  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac452  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00aac455  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00aac458  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac45e  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac464  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac467  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac46a  6601cf                 -add di, cx
    (cpu.di) += x86::reg16(x86::sreg16(cpu.cx));
    // 00aac46d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac470  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac473  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac479  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac47f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00aac482  7408                   -je 0xaac48c
    if (cpu.flags.zf)
    {
        goto L_0x00aac48c;
    }
    // 00aac484  81ca00001000           +or edx, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 00aac48a  eb0e                   -jmp 0xaac49a
    goto L_0x00aac49a;
L_0x00aac48c:
    // 00aac48c  01c0                   +add eax, eax
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
    // 00aac48e  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00aac490  664f                   -dec di
    (cpu.di)--;
    // 00aac492  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 00aac498  74f2                   -je 0xaac48c
    if (cpu.flags.zf)
    {
        goto L_0x00aac48c;
    }
L_0x00aac49a:
    // 00aac49a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00aac49d  7408                   -je 0xaac4a7
    if (cpu.flags.zf)
    {
        goto L_0x00aac4a7;
    }
    // 00aac49f  81ce00001000           +or esi, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 00aac4a5  eb0e                   -jmp 0xaac4b5
    goto L_0x00aac4b5;
L_0x00aac4a7:
    // 00aac4a7  01db                   +add ebx, ebx
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
    // 00aac4a9  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00aac4ab  6649                   -dec cx
    (cpu.cx)--;
    // 00aac4ad  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 00aac4b3  74f2                   -je 0xaac4a7
    if (cpu.flags.zf)
    {
        goto L_0x00aac4a7;
    }
L_0x00aac4b5:
    // 00aac4b5  6629cf                 -sub di, cx
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.cx));
    // 00aac4b8  6681c7ff03             +add di, 0x3ff
    {
        x86::reg16& tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac4bd  7811                   -js 0xaac4d0
    if (cpu.flags.sf)
    {
        goto L_0x00aac4d0;
    }
    // 00aac4bf  6681ffff07             +cmp di, 0x7ff
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac4c4  720a                   -jb 0xaac4d0
    if (cpu.flags.cf)
    {
        goto L_0x00aac4d0;
    }
    // 00aac4c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac4c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4cb  e989230000             -jmp 0xaae859
    return sub_aae859(app, cpu);
L_0x00aac4d0:
    // 00aac4d0  6683ffcc               +cmp di, -0x34
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-52 /*-0x34*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac4d4  7d08                   -jge 0xaac4de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aac4de;
    }
    // 00aac4d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac4d9  e95e230000             -jmp 0xaae83c
    return sub_aae83c(app, cpu);
L_0x00aac4de:
    // 00aac4de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac4df  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00aac4e1  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 00aac4e4  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00aac4e7  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00aac4ec  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 00aac4ef  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00aac4f2  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00aac4f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac4f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac4fa  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00aac4fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac4fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aac500  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac502  39d1                   +cmp ecx, edx
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
    // 00aac504  7703                   -ja 0xaac509
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aac509;
    }
    // 00aac506  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aac508  40                     -inc eax
    (cpu.eax)++;
L_0x00aac509:
    // 00aac509  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac50a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aac50c  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00aac50e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac50f  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac510  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00aac512  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac513  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 00aac515  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00aac517  01d8                   +add eax, ebx
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
    // 00aac519  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac51c  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00aac51f  f645e801               +test byte ptr [ebp - 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) & 1 /*0x1*/));
    // 00aac523  7405                   -je 0xaac52a
    if (cpu.flags.zf)
    {
        goto L_0x00aac52a;
    }
    // 00aac525  01d8                   +add eax, ebx
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
    // 00aac527  1355f0                 -adc edx, dword ptr [ebp - 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
L_0x00aac52a:
    // 00aac52a  f7d9                   +neg ecx
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
    // 00aac52c  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac52e  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac530  7412                   -je 0xaac544
    if (cpu.flags.zf)
    {
        goto L_0x00aac544;
    }
L_0x00aac532:
    // 00aac532  836de401               +sub dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac536  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac53a  01d9                   +add ecx, ebx
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
    // 00aac53c  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac53f  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac542  75ee                   -jne 0xaac532
    if (!cpu.flags.zf)
    {
        goto L_0x00aac532;
    }
L_0x00aac544:
    // 00aac544  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00aac546  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac548  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00aac54b  39f9                   +cmp ecx, edi
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
    // 00aac54d  770a                   -ja 0xaac559
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aac559;
    }
    // 00aac54f  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aac551  8345e401               +add dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac555  8355e800               -adc dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00aac559:
    // 00aac559  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aac55b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aac55d  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00aac55f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac560  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac562  742c                   -je 0xaac590
    if (cpu.flags.zf)
    {
        goto L_0x00aac590;
    }
    // 00aac564  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac565  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00aac567  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac568  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 00aac56a  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00aac56c  01d8                   +add eax, ebx
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
    // 00aac56e  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac571  f7d9                   +neg ecx
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
    // 00aac573  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac575  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac577  7417                   -je 0xaac590
    if (cpu.flags.zf)
    {
        goto L_0x00aac590;
    }
L_0x00aac579:
    // 00aac579  836de001               +sub dword ptr [ebp - 0x20], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac57d  835de400               +sbb dword ptr [ebp - 0x1c], 0
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac581  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac585  034dec                 +add ecx, dword ptr [ebp - 0x14]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac588  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac58b  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac58e  75e9                   -jne 0xaac579
    if (!cpu.flags.zf)
    {
        goto L_0x00aac579;
    }
L_0x00aac590:
    // 00aac590  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac591  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac592  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac593  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aac596  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac597  664f                   -dec di
    (cpu.di)--;
    // 00aac599  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac59b  7305                   -jae 0xaac5a2
    if (!cpu.flags.cf)
    {
        goto L_0x00aac5a2;
    }
    // 00aac59d  d1da                   +rcr edx, 1
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
    // 00aac59f  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac5a1  47                     -inc edi
    (cpu.edi)++;
L_0x00aac5a2:
    // 00aac5a2  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00aac5a4  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00aac5a6  0fadd0                 +shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        cpu.flags.cf = 1 & (destination >> (cpu.cl - 1));
        cpu.flags.of = 1 & (destination >> (32 - 1));
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
        cpu.flags.of ^= 1 & (destination >> (32 - 1));
        cpu.set_szp(destination);
    }
    // 00aac5a9  d1de                   -rcr esi, 1
    {
        x86::reg32& op = cpu.esi;
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
    // 00aac5ab  0fadf2                 -shrd edx, esi, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.esi  << (32 - (cpu.cl % 32));
    }
    // 00aac5ae  81ca0000f0ff           -or edx, 0xfff00000
    cpu.edx |= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00aac5b4  01f6                   +add esi, esi
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
    // 00aac5b6  83d000                 +adc eax, 0
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
    // 00aac5b9  83d200                 +adc edx, 0
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
    // 00aac5bc  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac5bf  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00aac5c2  7f1d                   -jg 0xaac5e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aac5e1;
    }
    // 00aac5c4  7504                   -jne 0xaac5ca
    if (!cpu.flags.zf)
    {
        goto L_0x00aac5ca;
    }
    // 00aac5c6  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00aac5c8  eb06                   -jmp 0xaac5d0
    goto L_0x00aac5d0;
L_0x00aac5ca:
    // 00aac5ca  66f7df                 -neg di
    cpu.di = ~cpu.di + 1;
    // 00aac5cd  6689f9                 -mov cx, di
    cpu.cx = cpu.di;
L_0x00aac5d0:
    // 00aac5d0  81e2ffff1f00           -and edx, 0x1fffff
    cpu.edx &= x86::reg32(x86::sreg32(2097151 /*0x1fffff*/));
    // 00aac5d6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac5d8  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00aac5db  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00aac5de  6629ff                 -sub di, di
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.di));
L_0x00aac5e1:
    // 00aac5e1  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac5e7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00aac5e9  c1cf0b                 -ror edi, 0xb
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00aac5ec  01f6                   +add esi, esi
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
    // 00aac5ee  d1df                   -rcr edi, 1
    {
        x86::reg32& op = cpu.edi;
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
    // 00aac5f0  81e70000f0ff           -and edi, 0xfff00000
    cpu.edi &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00aac5f6  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00aac5f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac5f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac5fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac5fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac5fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac5fc  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00aac602  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aac604  7506                   -jne 0xaac60c
    if (!cpu.flags.zf)
    {
        goto L_0x00aac60c;
    }
    // 00aac606  01c9                   +add ecx, ecx
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
    // 00aac608  740e                   -je 0xaac618
    if (cpu.flags.zf)
    {
        goto L_0x00aac618;
    }
    // 00aac60a  d1d9                   -rcr ecx, 1
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
L_0x00aac60c:
    // 00aac60c  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac60e  750b                   -jne 0xaac61b
    if (!cpu.flags.zf)
    {
        goto L_0x00aac61b;
    }
    // 00aac610  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac612  7505                   -jne 0xaac619
    if (!cpu.flags.zf)
    {
        goto L_0x00aac619;
    }
    // 00aac614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aac616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00aac618:
    // 00aac618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac619:
    // 00aac619  d1da                   -rcr edx, 1
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
L_0x00aac61b:
    // 00aac61b  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
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
    // 00aac622  7421                   -je 0xaac645
    if (cpu.flags.zf)
    {
        goto L_0x00aac645;
    }
    // 00aac624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac626  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00aac629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac62a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac62b  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
    // 00aac62e  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aac632  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aac635  9b                     -wait 
    /*nothing*/;
    // 00aac636  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac637  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac638  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac63e  7504                   -jne 0xaac644
    if (!cpu.flags.zf)
    {
        goto L_0x00aac644;
    }
    // 00aac640  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac642  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aac644:
    // 00aac644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac645:
    // 00aac645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac647  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac648  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac64a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac64c  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00aac64f  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00aac652  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac658  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac65e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00aac660  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac663  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac666  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00aac669  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac66c  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac66f  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac675  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac67b  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00aac67e  7406                   -je 0xaac686
    if (cpu.flags.zf)
    {
        goto L_0x00aac686;
    }
    // 00aac680  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00aac686:
    // 00aac686  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00aac689  7406                   -je 0xaac691
    if (cpu.flags.zf)
    {
        goto L_0x00aac691;
    }
    // 00aac68b  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00aac691:
    // 00aac691  01c0                   +add eax, eax
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
    // 00aac693  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00aac695  01db                   +add ebx, ebx
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
    // 00aac697  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00aac699  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac69c  742f                   -je 0xaac6cd
    if (cpu.flags.zf)
    {
        goto L_0x00aac6cd;
    }
    // 00aac69e  7308                   -jae 0xaac6a8
    if (!cpu.flags.cf)
    {
        goto L_0x00aac6a8;
    }
    // 00aac6a0  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00aac6a2  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00aac6a5  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac6a6  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x00aac6a8:
    // 00aac6a8  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac6ac  761f                   -jbe 0xaac6cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aac6cd;
    }
    // 00aac6ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aac6b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac6b2  01ed                   +add ebp, ebp
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
    // 00aac6b4  d1da                   +rcr edx, 1
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
    // 00aac6b6  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac6b8  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00aac6be  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00aac6c1  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00aac6c7  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aac6c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac6cd:
    // 00aac6cd  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aac6cf  790d                   -jns 0xaac6de
    if (!cpu.flags.sf)
    {
        goto L_0x00aac6de;
    }
    // 00aac6d1  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00aac6d3  f7db                   +neg ebx
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
    // 00aac6d5  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac6d8  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00aac6de:
    // 00aac6de  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00aac6e0  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aac6e3  7423                   -je 0xaac708
    if (cpu.flags.zf)
    {
        goto L_0x00aac708;
    }
    // 00aac6e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac6e6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6e8  80f920                 +cmp cl, 0x20
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
    // 00aac6eb  720d                   -jb 0xaac6fa
    if (cpu.flags.cf)
    {
        goto L_0x00aac6fa;
    }
    // 00aac6ed  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac6ef  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac6f2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aac6f4  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac6f8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aac6fa:
    // 00aac6fa  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00aac6fd  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6ff  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac701  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00aac704  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00aac707  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aac708:
    // 00aac708  01d8                   +add eax, ebx
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
    // 00aac70a  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac70c  7923                   -jns 0xaac731
    if (!cpu.flags.sf)
    {
        goto L_0x00aac731;
    }
    // 00aac70e  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aac711  7211                   -jb 0xaac724
    if (cpu.flags.cf)
    {
        goto L_0x00aac724;
    }
    // 00aac713  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 00aac719  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac71c  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac71e  83d000                 +adc eax, 0
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
    // 00aac721  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00aac724:
    // 00aac724  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00aac726  f7d8                   +neg eax
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
    // 00aac728  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac72b  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00aac731:
    // 00aac731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac733  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aac735  746a                   -je 0xaac7a1
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a1;
    }
    // 00aac737  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00aac73a  7469                   -je 0xaac7a5
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a5;
    }
L_0x00aac73c:
    // 00aac73c  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00aac742  750a                   -jne 0xaac74e
    if (!cpu.flags.zf)
    {
        goto L_0x00aac74e;
    }
    // 00aac744  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 00aac746  745d                   -je 0xaac7a5
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a5;
    }
    // 00aac748  01c0                   +add eax, eax
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
    // 00aac74a  11d2                   +adc edx, edx
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
    // 00aac74c  ebee                   -jmp 0xaac73c
    goto L_0x00aac73c;
L_0x00aac74e:
    // 00aac74e  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 00aac754  7410                   -je 0xaac766
    if (cpu.flags.zf)
    {
        goto L_0x00aac766;
    }
    // 00aac756  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac758  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac75a  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac75d  6645                   -inc bp
    (cpu.bp)++;
    // 00aac75f  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac764  7449                   -je 0xaac7af
    if (cpu.flags.zf)
    {
        goto L_0x00aac7af;
    }
L_0x00aac766:
    // 00aac766  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac768  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac76a  7324                   -jae 0xaac790
    if (!cpu.flags.cf)
    {
        goto L_0x00aac790;
    }
    // 00aac76c  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00aac76e  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac771  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac773  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac775  83d000                 +adc eax, 0
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
    // 00aac778  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac77b  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00aac781  740d                   -je 0xaac790
    if (cpu.flags.zf)
    {
        goto L_0x00aac790;
    }
    // 00aac783  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac785  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac787  6645                   -inc bp
    (cpu.bp)++;
    // 00aac789  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac78e  741f                   -je 0xaac7af
    if (cpu.flags.zf)
    {
        goto L_0x00aac7af;
    }
L_0x00aac790:
    // 00aac790  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac796  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00aac798  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 00aac79b  01c9                   +add ecx, ecx
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
    // 00aac79d  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 00aac79f  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00aac7a1:
    // 00aac7a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7a5:
    // 00aac7a5  01ed                   +add ebp, ebp
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
    // 00aac7a7  d1da                   +rcr edx, 1
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
    // 00aac7a9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7af:
    // 00aac7af  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aac7b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b4  e9a0200000             -jmp 0xaae859
    return sub_aae859(app, cpu);
}

/* align: skip  */
void sub_aac62e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aac62e;
    // 00aac5fc  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00aac602  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aac604  7506                   -jne 0xaac60c
    if (!cpu.flags.zf)
    {
        goto L_0x00aac60c;
    }
    // 00aac606  01c9                   +add ecx, ecx
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
    // 00aac608  740e                   -je 0xaac618
    if (cpu.flags.zf)
    {
        goto L_0x00aac618;
    }
    // 00aac60a  d1d9                   -rcr ecx, 1
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
L_0x00aac60c:
    // 00aac60c  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac60e  750b                   -jne 0xaac61b
    if (!cpu.flags.zf)
    {
        goto L_0x00aac61b;
    }
    // 00aac610  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac612  7505                   -jne 0xaac619
    if (!cpu.flags.zf)
    {
        goto L_0x00aac619;
    }
    // 00aac614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aac616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00aac618:
    // 00aac618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac619:
    // 00aac619  d1da                   -rcr edx, 1
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
L_0x00aac61b:
    // 00aac61b  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
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
    // 00aac622  7421                   -je 0xaac645
    if (cpu.flags.zf)
    {
        goto L_0x00aac645;
    }
    // 00aac624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac626  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00aac629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac62a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac62b  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
L_entry_0x00aac62e:
    // 00aac62e  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aac632  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aac635  9b                     -wait 
    /*nothing*/;
    // 00aac636  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac637  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac638  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac63e  7504                   -jne 0xaac644
    if (!cpu.flags.zf)
    {
        goto L_0x00aac644;
    }
    // 00aac640  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aac642  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aac644:
    // 00aac644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac645:
    // 00aac645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac647  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac648  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac64a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac64c  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00aac64f  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00aac652  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac658  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac65e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00aac660  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac663  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac666  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00aac669  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac66c  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac66f  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac675  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac67b  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00aac67e  7406                   -je 0xaac686
    if (cpu.flags.zf)
    {
        goto L_0x00aac686;
    }
    // 00aac680  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00aac686:
    // 00aac686  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00aac689  7406                   -je 0xaac691
    if (cpu.flags.zf)
    {
        goto L_0x00aac691;
    }
    // 00aac68b  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00aac691:
    // 00aac691  01c0                   +add eax, eax
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
    // 00aac693  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00aac695  01db                   +add ebx, ebx
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
    // 00aac697  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00aac699  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac69c  742f                   -je 0xaac6cd
    if (cpu.flags.zf)
    {
        goto L_0x00aac6cd;
    }
    // 00aac69e  7308                   -jae 0xaac6a8
    if (!cpu.flags.cf)
    {
        goto L_0x00aac6a8;
    }
    // 00aac6a0  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00aac6a2  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00aac6a5  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac6a6  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x00aac6a8:
    // 00aac6a8  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac6ac  761f                   -jbe 0xaac6cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aac6cd;
    }
    // 00aac6ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aac6b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac6b2  01ed                   +add ebp, ebp
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
    // 00aac6b4  d1da                   +rcr edx, 1
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
    // 00aac6b6  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac6b8  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00aac6be  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00aac6c1  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00aac6c7  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aac6c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac6cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac6cd:
    // 00aac6cd  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aac6cf  790d                   -jns 0xaac6de
    if (!cpu.flags.sf)
    {
        goto L_0x00aac6de;
    }
    // 00aac6d1  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00aac6d3  f7db                   +neg ebx
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
    // 00aac6d5  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac6d8  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00aac6de:
    // 00aac6de  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00aac6e0  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aac6e3  7423                   -je 0xaac708
    if (cpu.flags.zf)
    {
        goto L_0x00aac708;
    }
    // 00aac6e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac6e6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6e8  80f920                 +cmp cl, 0x20
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
    // 00aac6eb  720d                   -jb 0xaac6fa
    if (cpu.flags.cf)
    {
        goto L_0x00aac6fa;
    }
    // 00aac6ed  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac6ef  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac6f2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aac6f4  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aac6f8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aac6fa:
    // 00aac6fa  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00aac6fd  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac6ff  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac701  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00aac704  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00aac707  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aac708:
    // 00aac708  01d8                   +add eax, ebx
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
    // 00aac70a  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac70c  7923                   -jns 0xaac731
    if (!cpu.flags.sf)
    {
        goto L_0x00aac731;
    }
    // 00aac70e  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aac711  7211                   -jb 0xaac724
    if (cpu.flags.cf)
    {
        goto L_0x00aac724;
    }
    // 00aac713  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 00aac719  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac71c  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac71e  83d000                 +adc eax, 0
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
    // 00aac721  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00aac724:
    // 00aac724  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00aac726  f7d8                   +neg eax
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
    // 00aac728  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac72b  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00aac731:
    // 00aac731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac733  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aac735  746a                   -je 0xaac7a1
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a1;
    }
    // 00aac737  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00aac73a  7469                   -je 0xaac7a5
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a5;
    }
L_0x00aac73c:
    // 00aac73c  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00aac742  750a                   -jne 0xaac74e
    if (!cpu.flags.zf)
    {
        goto L_0x00aac74e;
    }
    // 00aac744  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 00aac746  745d                   -je 0xaac7a5
    if (cpu.flags.zf)
    {
        goto L_0x00aac7a5;
    }
    // 00aac748  01c0                   +add eax, eax
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
    // 00aac74a  11d2                   +adc edx, edx
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
    // 00aac74c  ebee                   -jmp 0xaac73c
    goto L_0x00aac73c;
L_0x00aac74e:
    // 00aac74e  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 00aac754  7410                   -je 0xaac766
    if (cpu.flags.zf)
    {
        goto L_0x00aac766;
    }
    // 00aac756  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac758  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac75a  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac75d  6645                   -inc bp
    (cpu.bp)++;
    // 00aac75f  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac764  7449                   -je 0xaac7af
    if (cpu.flags.zf)
    {
        goto L_0x00aac7af;
    }
L_0x00aac766:
    // 00aac766  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac768  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac76a  7324                   -jae 0xaac790
    if (!cpu.flags.cf)
    {
        goto L_0x00aac790;
    }
    // 00aac76c  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00aac76e  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac771  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac773  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac775  83d000                 +adc eax, 0
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
    // 00aac778  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac77b  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00aac781  740d                   -je 0xaac790
    if (cpu.flags.zf)
    {
        goto L_0x00aac790;
    }
    // 00aac783  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac785  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac787  6645                   -inc bp
    (cpu.bp)++;
    // 00aac789  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac78e  741f                   -je 0xaac7af
    if (cpu.flags.zf)
    {
        goto L_0x00aac7af;
    }
L_0x00aac790:
    // 00aac790  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac796  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00aac798  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 00aac79b  01c9                   +add ecx, ecx
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
    // 00aac79d  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 00aac79f  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00aac7a1:
    // 00aac7a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7a5:
    // 00aac7a5  01ed                   +add ebp, ebp
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
    // 00aac7a7  d1da                   +rcr edx, 1
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
    // 00aac7a9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7af:
    // 00aac7af  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aac7b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac7b4  e9a0200000             -jmp 0xaae859
    return sub_aae859(app, cpu);
}

/* align: skip  */
void sub_aac7b9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac7b9  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aac7bb  7507                   -jne 0xaac7c4
    if (!cpu.flags.zf)
    {
        goto L_0x00aac7c4;
    }
    // 00aac7bd  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac7bf  7501                   -jne 0xaac7c2
    if (!cpu.flags.zf)
    {
        goto L_0x00aac7c2;
    }
    // 00aac7c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7c2:
    // 00aac7c2  d1da                   -rcr edx, 1
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
L_0x00aac7c4:
    // 00aac7c4  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00aac7c6  750b                   -jne 0xaac7d3
    if (!cpu.flags.zf)
    {
        goto L_0x00aac7d3;
    }
    // 00aac7c8  01c9                   +add ecx, ecx
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
    // 00aac7ca  7505                   -jne 0xaac7d1
    if (!cpu.flags.zf)
    {
        goto L_0x00aac7d1;
    }
    // 00aac7cc  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aac7ce  29d2                   +sub edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac7d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac7d1:
    // 00aac7d1  d1d9                   -rcr ecx, 1
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
L_0x00aac7d3:
    // 00aac7d3  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
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
    // 00aac7da  740f                   -je 0xaac7eb
    if (cpu.flags.zf)
    {
        goto L_0x00aac7eb;
    }
    // 00aac7dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac7dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac7de  dd0424                 +fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00aac7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac7e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac7e3  dc0c24                 +fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp));
    // 00aac7e6  e943feffff             -jmp 0xaac62e
    return sub_aac62e(app, cpu);
L_0x00aac7eb:
    // 00aac7eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac7ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aac7ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac7ee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac7f0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac7f2  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00aac7f5  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00aac7f8  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac7fe  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00aac804  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac807  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac80a  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00aac80d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac810  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00aac813  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac819  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac81f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00aac822  7510                   -jne 0xaac834
    if (!cpu.flags.zf)
    {
        goto L_0x00aac834;
    }
    // 00aac824  6647                   -inc di
    (cpu.di)++;
L_0x00aac826:
    // 00aac826  664f                   -dec di
    (cpu.di)--;
    // 00aac828  01c0                   +add eax, eax
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
    // 00aac82a  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00aac82c  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 00aac832  74f2                   -je 0xaac826
    if (cpu.flags.zf)
    {
        goto L_0x00aac826;
    }
L_0x00aac834:
    // 00aac834  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 00aac83a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00aac83d  7510                   -jne 0xaac84f
    if (!cpu.flags.zf)
    {
        goto L_0x00aac84f;
    }
    // 00aac83f  6641                   -inc cx
    (cpu.cx)++;
L_0x00aac841:
    // 00aac841  6649                   -dec cx
    (cpu.cx)--;
    // 00aac843  01db                   +add ebx, ebx
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
    // 00aac845  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00aac847  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 00aac84d  74f2                   -je 0xaac841
    if (cpu.flags.zf)
    {
        goto L_0x00aac841;
    }
L_0x00aac84f:
    // 00aac84f  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 00aac855  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00aac858  6681e9ff03             +sub cx, 0x3ff
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac85d  7811                   -js 0xaac870
    if (cpu.flags.sf)
    {
        goto L_0x00aac870;
    }
    // 00aac85f  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac864  720a                   -jb 0xaac870
    if (cpu.flags.cf)
    {
        goto L_0x00aac870;
    }
    // 00aac866  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac869  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac86a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac86b  e9e91f0000             -jmp 0xaae859
    return sub_aae859(app, cpu);
L_0x00aac870:
    // 00aac870  6683f9cb               +cmp cx, -0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-53 /*-0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac874  7d08                   -jge 0xaac87e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aac87e;
    }
    // 00aac876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac877  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac878  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac879  e9be1f0000             -jmp 0xaae83c
    return sub_aae83c(app, cpu);
L_0x00aac87e:
    // 00aac87e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac87f  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00aac881  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 00aac884  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00aac887  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00aac88c  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 00aac88f  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00aac892  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00aac898  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aac89a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac89b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac89c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aac89d  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00aac89f  96                     -xchg esi, eax
    {
        x86::reg32 tmp = cpu.esi;
        cpu.esi = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac8a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aac8a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac8a3  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00aac8a5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aac8a7  01c1                   +add ecx, eax
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
    // 00aac8a9  11ef                   +adc edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac8ab  11ed                   -adc ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 00aac8ad  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac8ae  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00aac8af  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00aac8b1  01c1                   +add ecx, eax
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
    // 00aac8b3  11d7                   +adc edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac8b5  83d500                 -adc ebp, 0
    (cpu.ebp) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac8b8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aac8ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac8bb  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00aac8bd  01f8                   +add eax, edi
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
    // 00aac8bf  11ea                   -adc edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 00aac8c1  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac8c3  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00aac8c5  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00aac8c8  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00aac8cb  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00aac8ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aac8cf:
    // 00aac8cf  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00aac8d5  7411                   -je 0xaac8e8
    if (cpu.flags.zf)
    {
        goto L_0x00aac8e8;
    }
    // 00aac8d7  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac8d9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac8db  d1db                   -rcr ebx, 1
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
    // 00aac8dd  6641                   -inc cx
    (cpu.cx)++;
    // 00aac8df  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac8e4  7466                   -je 0xaac94c
    if (cpu.flags.zf)
    {
        goto L_0x00aac94c;
    }
    // 00aac8e6  ebe7                   -jmp 0xaac8cf
    goto L_0x00aac8cf;
L_0x00aac8e8:
    // 00aac8e8  01db                   +add ebx, ebx
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
    // 00aac8ea  732a                   -jae 0xaac916
    if (!cpu.flags.cf)
    {
        goto L_0x00aac916;
    }
    // 00aac8ec  750d                   -jne 0xaac8fb
    if (!cpu.flags.zf)
    {
        goto L_0x00aac8fb;
    }
    // 00aac8ee  09f6                   +or esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00aac8f0  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00aac8f3  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac8f5  7204                   -jb 0xaac8fb
    if (cpu.flags.cf)
    {
        goto L_0x00aac8fb;
    }
    // 00aac8f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aac8f9  d1ee                   +shr esi, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
L_0x00aac8fb:
    // 00aac8fb  83d000                 +adc eax, 0
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
    // 00aac8fe  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac901  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00aac907  740d                   -je 0xaac916
    if (cpu.flags.zf)
    {
        goto L_0x00aac916;
    }
    // 00aac909  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00aac90b  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00aac90d  6641                   -inc cx
    (cpu.cx)++;
    // 00aac90f  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00aac914  7436                   -je 0xaac94c
    if (cpu.flags.zf)
    {
        goto L_0x00aac94c;
    }
L_0x00aac916:
    // 00aac916  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00aac919  7f16                   -jg 0xaac931
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aac931;
    }
    // 00aac91b  7504                   -jne 0xaac921
    if (!cpu.flags.zf)
    {
        goto L_0x00aac921;
    }
    // 00aac91d  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00aac91f  eb05                   -jmp 0xaac926
    goto L_0x00aac926;
L_0x00aac921:
    // 00aac921  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00aac924  6649                   -dec cx
    (cpu.cx)--;
L_0x00aac926:
    // 00aac926  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aac928  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00aac92b  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00aac92e  6629c9                 -sub cx, cx
    (cpu.cx) -= x86::reg16(x86::sreg16(cpu.cx));
L_0x00aac931:
    // 00aac931  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00aac937  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aac939  c1c90b                 -ror ecx, 0xb
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00aac93c  01f6                   +add esi, esi
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
    // 00aac93e  d1d9                   -rcr ecx, 1
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
    // 00aac940  81e10000f0ff           -and ecx, 0xfff00000
    cpu.ecx &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00aac946  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aac948  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac94a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac94b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aac94c:
    // 00aac94c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac94e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac94f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac950  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac951  e9031f0000             -jmp 0xaae859
    return sub_aae859(app, cpu);
}

/* align: skip  */
void sub_aac956(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac956  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aac957  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 00aac95d  7502                   -jne 0xaac961
    if (!cpu.flags.zf)
    {
        goto L_0x00aac961;
    }
    // 00aac95f  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00aac961:
    // 00aac961  f7c10000f07f           +test ecx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 2146435072 /*0x7ff00000*/));
    // 00aac967  7502                   -jne 0xaac96b
    if (!cpu.flags.zf)
    {
        goto L_0x00aac96b;
    }
    // 00aac969  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00aac96b:
    // 00aac96b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00aac96d  31d5                   +xor ebp, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aac96f  bd00000000             -mov ebp, 0
    cpu.ebp = 0 /*0x0*/;
    // 00aac974  780c                   -js 0xaac982
    if (cpu.flags.sf)
    {
        goto L_0x00aac982;
    }
    // 00aac976  39ca                   +cmp edx, ecx
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
    // 00aac978  7502                   -jne 0xaac97c
    if (!cpu.flags.zf)
    {
        goto L_0x00aac97c;
    }
    // 00aac97a  39d8                   +cmp eax, ebx
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
L_0x00aac97c:
    // 00aac97c  740c                   -je 0xaac98a
    if (cpu.flags.zf)
    {
        goto L_0x00aac98a;
    }
    // 00aac97e  d1d9                   -rcr ecx, 1
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
    // 00aac980  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00aac982:
    // 00aac982  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aac984  83dd00                 -sbb ebp, 0
    (cpu.ebp) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00aac987  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aac989  45                     -inc ebp
    (cpu.ebp)++;
L_0x00aac98a:
    // 00aac98a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aac98c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac98d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aac990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac990  a36c38ab00             -mov dword ptr [0xab386c], eax
    app->getMemory<x86::reg32>(x86::reg32(11221100) /* 0xab386c */) = cpu.eax;
    // 00aac995  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac996(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac996  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac997  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aac998  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aac999  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aac99b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aac99d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00aac9a2  e8091f0000             -call 0xaae8b0
    cpu.esp -= 4;
    sub_aae8b0(app, cpu);
    if (cpu.terminate) return;
    // 00aac9a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac9a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aac9ab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aac9ad  8b04855038ab00         -mov eax, dword ptr [eax*4 + 0xab3850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221072) /* 0xab3850 */ + cpu.eax * 4);
    // 00aac9b4  e8171f0000             -call 0xaae8d0
    cpu.esp -= 4;
    sub_aae8d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac9b9  b8692eab00             -mov eax, 0xab2e69
    cpu.eax = 11218537 /*0xab2e69*/;
    // 00aac9be  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aac9c0  e80b1f0000             -call 0xaae8d0
    cpu.esp -= 4;
    sub_aae8d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac9c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aac9c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aac9c9  e8021f0000             -call 0xaae8d0
    cpu.esp -= 4;
    sub_aae8d0(app, cpu);
    if (cpu.terminate) return;
    // 00aac9ce  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00aac9d3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aac9d5  e806d4ffff             -call 0xaa9de0
    cpu.esp -= 4;
    sub_aa9de0(app, cpu);
    if (cpu.terminate) return;
    // 00aac9da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aac9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aac9de(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aac9de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aac9df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aac9e0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aac9e2  ff156c38ab00           -call dword ptr [0xab386c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11221100) /* 0xab386c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aac9e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aac9ea  751b                   -jne 0xaaca07
    if (!cpu.flags.zf)
    {
        goto L_0x00aaca07;
    }
    // 00aac9ec  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aac9ef  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aac9f1  e8a0ffffff             -call 0xaac996
    cpu.esp -= 4;
    sub_aac996(app, cpu);
    if (cpu.terminate) return;
    // 00aac9f6  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aac9f9  7507                   -jne 0xaaca02
    if (!cpu.flags.zf)
    {
        goto L_0x00aaca02;
    }
    // 00aac9fb  e830e8ffff             -call 0xaab230
    cpu.esp -= 4;
    sub_aab230(app, cpu);
    if (cpu.terminate) return;
    // 00aaca00  eb05                   -jmp 0xaaca07
    goto L_0x00aaca07;
L_0x00aaca02:
    // 00aaca02  e83de8ffff             -call 0xaab244
    cpu.esp -= 4;
    sub_aab244(app, cpu);
    if (cpu.terminate) return;
L_0x00aaca07:
    // 00aaca07  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 00aaca0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_aaca10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaca10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaca11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaca12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaca13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaca15  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00aaca19  7522                   -jne 0xaaca3d
    if (!cpu.flags.zf)
    {
        goto L_0x00aaca3d;
    }
    // 00aaca1b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aaca1e  e84d1f0000             -call 0xaae970
    cpu.esp -= 4;
    sub_aae970(app, cpu);
    if (cpu.terminate) return;
    // 00aaca23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaca25  7416                   -je 0xaaca3d
    if (cpu.flags.zf)
    {
        goto L_0x00aaca3d;
    }
    // 00aaca27  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00aaca2a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00aaca2d  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00aaca30  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 00aaca33  7508                   -jne 0xaaca3d
    if (!cpu.flags.zf)
    {
        goto L_0x00aaca3d;
    }
    // 00aaca35  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00aaca37  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00aaca3a  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x00aaca3d:
    // 00aaca3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaca50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaca50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaca51  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaca54  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aaca57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaca59  742a                   -je 0xaaca85
    if (cpu.flags.zf)
    {
        goto L_0x00aaca85;
    }
    // 00aaca5b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aaca5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aaca5f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aaca61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aaca62  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aaca64  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00aaca68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aaca69  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00aaca6e  8b157c3bab00           -mov edx, dword ptr [0xab3b7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221884) /* 0xab3b7c */);
    // 00aaca74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaca75  2eff153c14ab00         -call dword ptr cs:[0xab143c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211836) /* 0xab143c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaca7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaca7e  7505                   -jne 0xaaca85
    if (!cpu.flags.zf)
    {
        goto L_0x00aaca85;
    }
    // 00aaca80  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00aaca85:
    // 00aaca85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaca88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaca89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaca90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaca90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaca91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaca92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaca93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaca94  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00aaca97  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00aaca99  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aaca9b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aaca9d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aaca9f  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00aacaa3  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00aacaa6:
    // 00aacaa6  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aacaaa  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00aacaae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aacab0  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00aacab2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00aacab4  8a827038ab00           -mov al, byte ptr [edx + 0xab3870]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11221104) /* 0xab3870 */);
    // 00aacaba  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00aacabc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aacac0  41                     -inc ecx
    (cpu.ecx)++;
    // 00aacac1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacac3  75e1                   -jne 0xaacaa6
    if (!cpu.flags.zf)
    {
        goto L_0x00aacaa6;
    }
L_0x00aacac5:
    // 00aacac5  46                     -inc esi
    (cpu.esi)++;
    // 00aacac6  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00aacac9  49                     -dec ecx
    (cpu.ecx)--;
    // 00aacaca  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00aacacd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00aacacf  75f4                   -jne 0xaacac5
    if (!cpu.flags.zf)
    {
        goto L_0x00aacac5;
    }
    // 00aacad1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aacad3  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00aacad6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacad7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacad8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aacadc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacadc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacadd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aacadf  83fb0a                 +cmp ebx, 0xa
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
    // 00aacae2  750a                   -jne 0xaacaee
    if (!cpu.flags.zf)
    {
        goto L_0x00aacaee;
    }
    // 00aacae4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacae6  7d06                   -jge 0xaacaee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aacaee;
    }
    // 00aacae8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00aacaea  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00aacaed  42                     -inc edx
    (cpu.edx)++;
L_0x00aacaee:
    // 00aacaee  e89dffffff             -call 0xaaca90
    cpu.esp -= 4;
    sub_aaca90(app, cpu);
    if (cpu.terminate) return;
    // 00aacaf3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aacaf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacaf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aacb00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacb01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacb02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacb03  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aacb04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aacb05  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00aacb08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aacb0a  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00aacb0e  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aacb12  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00aacb16  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aacb18  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00aacb1c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aacb1e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aacb20  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00aacb22  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aacb23  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aacb24  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00aacb28  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00aacb2c  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00aacb2f:
    // 00aacb2f  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00aacb33  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aacb37  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aacb3b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aacb3f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aacb42  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aacb44  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aacb47  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aacb49  e84b200000             -call 0xaaeb99
    cpu.esp -= 4;
    sub_aaeb99(app, cpu);
    if (cpu.terminate) return;
    // 00aacb4e  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aacb51  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aacb53  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00aacb56  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00aacb58  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00aacb5c  8a809838ab00           -mov al, byte ptr [eax + 0xab3898]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11221144) /* 0xab3898 */);
    // 00aacb62  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00aacb65  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aacb69  45                     -inc ebp
    (cpu.ebp)++;
    // 00aacb6a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aacb6c  75c1                   -jne 0xaacb2f
    if (!cpu.flags.zf)
    {
        goto L_0x00aacb2f;
    }
    // 00aacb6e  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 00aacb73  75ba                   -jne 0xaacb2f
    if (!cpu.flags.zf)
    {
        goto L_0x00aacb2f;
    }
L_0x00aacb75:
    // 00aacb75  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00aacb79  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00aacb7c  4d                     -dec ebp
    (cpu.ebp)--;
    // 00aacb7d  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00aacb80  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00aacb82  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00aacb86  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00aacb88  75eb                   -jne 0xaacb75
    if (!cpu.flags.zf)
    {
        goto L_0x00aacb75;
    }
    // 00aacb8a  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00aacb8e  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00aacb91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacb92  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aacb93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacb94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacb95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacb96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aacb98(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacb98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacb99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacb9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacb9b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aacb9c  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aacb9f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aacba1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aacba3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aacba5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00aacba7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aacba9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aacbaa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aacbab  83fb0a                 +cmp ebx, 0xa
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
    // 00aacbae  752d                   -jne 0xaacbdd
    if (!cpu.flags.zf)
    {
        goto L_0x00aacbdd;
    }
    // 00aacbb0  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00aacbb5  7426                   -je 0xaacbdd
    if (cpu.flags.zf)
    {
        goto L_0x00aacbdd;
    }
    // 00aacbb7  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00aacbba  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aacbbd  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aacbc1  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00aacbc3  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 00aacbc5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aacbc8  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00aacbcc  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00aacbcf  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00aacbd2  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aacbd3  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00aacbd6  7501                   -jne 0xaacbd9
    if (!cpu.flags.zf)
    {
        goto L_0x00aacbd9;
    }
    // 00aacbd8  46                     -inc esi
    (cpu.esi)++;
L_0x00aacbd9:
    // 00aacbd9  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00aacbdd:
    // 00aacbdd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aacbdf  e81cffffff             -call 0xaacb00
    cpu.esp -= 4;
    sub_aacb00(app, cpu);
    if (cpu.terminate) return;
    // 00aacbe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aacbe6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aacbe9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aacbea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacbeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacbec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacbed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aacbf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacbf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacbf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacbf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacbf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aacbf4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00aacbf7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00aacbf9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aacbfb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aacbfd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aacbff  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00aacc03  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00aacc06:
    // 00aacc06  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aacc0a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00aacc0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aacc10  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00aacc12  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00aacc14  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aacc18  41                     -inc ecx
    (cpu.ecx)++;
    // 00aacc19  8a9bc038ab00           -mov bl, byte ptr [ebx + 0xab38c0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11221184) /* 0xab38c0 */);
    // 00aacc1f  8859ff                 -mov byte ptr [ecx - 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00aacc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacc24  75e0                   -jne 0xaacc06
    if (!cpu.flags.zf)
    {
        goto L_0x00aacc06;
    }
L_0x00aacc26:
    // 00aacc26  46                     -inc esi
    (cpu.esi)++;
    // 00aacc27  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00aacc2a  49                     -dec ecx
    (cpu.ecx)--;
    // 00aacc2b  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00aacc2e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00aacc30  75f4                   -jne 0xaacc26
    if (!cpu.flags.zf)
    {
        goto L_0x00aacc26;
    }
    // 00aacc32  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aacc34  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00aacc37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacc38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacc39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacc3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacc3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aacc3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacc3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacc3d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aacc3f  83fb0a                 +cmp ebx, 0xa
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
    // 00aacc42  750a                   -jne 0xaacc4e
    if (!cpu.flags.zf)
    {
        goto L_0x00aacc4e;
    }
    // 00aacc44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacc46  7d06                   -jge 0xaacc4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aacc4e;
    }
    // 00aacc48  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00aacc4a  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00aacc4d  42                     -inc edx
    (cpu.edx)++;
L_0x00aacc4e:
    // 00aacc4e  e89dffffff             -call 0xaacbf0
    cpu.esp -= 4;
    sub_aacbf0(app, cpu);
    if (cpu.terminate) return;
    // 00aacc53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aacc55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacc56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aacc60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacc60  8a80615aab00           -mov al, byte ptr [eax + 0xab5a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aacc66  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aacc68  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aacc6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aacc70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacc70  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aacc72  e9691d0000             -jmp 0xaae9e0
    return sub_aae9e0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aacc80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacc80  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aacc83  7c08                   -jl 0xaacc8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aacc8d;
    }
    // 00aacc85  83f87a                 +cmp eax, 0x7a
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
    // 00aacc88  7f03                   -jg 0xaacc8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aacc8d;
    }
    // 00aacc8a  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00aacc8d:
    // 00aacc8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aacc90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacc90  803de838ab0000         +cmp byte ptr [0xab38e8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11221224) /* 0xab38e8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aacc97  741a                   -je 0xaaccb3
    if (cpu.flags.zf)
    {
        goto L_0x00aaccb3;
    }
    // 00aacc99  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00aacc9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aacca0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aacca1  cc                     -int3 
    NFS2_ASSERT(false);
    // 00aacca2  eb06                   -jmp 0xaaccaa
    goto L_0x00aaccaa;
    // 00aacca4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacca5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacca6  49                     -dec ecx
    (cpu.ecx)--;
    // 00aacca7  44                     -inc esp
    (cpu.esp)++;
    // 00aacca8  45                     -inc ebp
    (cpu.ebp)++;
    // 00aacca9  4f                     -dec edi
    (cpu.edi)--;
L_0x00aaccaa:
    // 00aaccaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aaccaf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aaccb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaccb3:
    // 00aaccb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaccb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaccc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaccc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaccc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaccc2  2eff15a813ab00         -call dword ptr cs:[0xab13a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211688) /* 0xab13a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaccc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaccca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacccb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_aaccd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaccd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaccd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaccd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaccd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaccd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaccd5  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00aaccdb  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacce1  bd902eab00             -mov ebp, 0xab2e90
    cpu.ebp = 11218576 /*0xab2e90*/;
    // 00aacce6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aacce9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00aacceb:
    // 00aacceb  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00aaccf2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aaccf4  e8bfe2ffff             -call 0xaaafb8
    cpu.esp -= 4;
    sub_aaafb8(app, cpu);
    if (cpu.terminate) return;
    // 00aaccf9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aaccfe  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00aacd05  41                     -inc ecx
    (cpu.ecx)++;
    // 00aacd06  e8251f0000             -call 0xaaec30
    cpu.esp -= 4;
    sub_aaec30(app, cpu);
    if (cpu.terminate) return;
    // 00aacd0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacd0d  74dc                   -je 0xaacceb
    if (cpu.flags.zf)
    {
        goto L_0x00aacceb;
    }
    // 00aacd0f  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00aacd16  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aacd18  e8bb210000             -call 0xaaeed8
    cpu.esp -= 4;
    sub_aaeed8(app, cpu);
    if (cpu.terminate) return;
    // 00aacd1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacd1f  751b                   -jne 0xaacd3c
    if (!cpu.flags.zf)
    {
        goto L_0x00aacd3c;
    }
    // 00aacd21  e8ca220000             -call 0xaaeff0
    cpu.esp -= 4;
    sub_aaeff0(app, cpu);
    if (cpu.terminate) return;
    // 00aacd26  83380b                 +cmp dword ptr [eax], 0xb
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
    // 00aacd29  740a                   -je 0xaacd35
    if (cpu.flags.zf)
    {
        goto L_0x00aacd35;
    }
    // 00aacd2b  e8c0220000             -call 0xaaeff0
    cpu.esp -= 4;
    sub_aaeff0(app, cpu);
    if (cpu.terminate) return;
    // 00aacd30  833806                 +cmp dword ptr [eax], 6
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
    // 00aacd33  75b6                   -jne 0xaacceb
    if (!cpu.flags.zf)
    {
        goto L_0x00aacceb;
    }
L_0x00aacd35:
    // 00aacd35  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aacd37  e998000000             -jmp 0xaacdd4
    goto L_0x00aacdd4;
L_0x00aacd3c:
    // 00aacd3c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aacd3e  e80de2ffff             -call 0xaaaf50
    cpu.esp -= 4;
    sub_aaaf50(app, cpu);
    if (cpu.terminate) return;
    // 00aacd43  8a1d6835ab00           -mov bl, byte ptr [0xab3568]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(11220328) /* 0xab3568 */);
L_0x00aacd49:
    // 00aacd49  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aacd4b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aacd4d  e866e2ffff             -call 0xaaafb8
    cpu.esp -= 4;
    sub_aaafb8(app, cpu);
    if (cpu.terminate) return;
    // 00aacd52  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00aacd54  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00aacd5b  e8b0220000             -call 0xaaf010
    cpu.esp -= 4;
    sub_aaf010(app, cpu);
    if (cpu.terminate) return;
    // 00aacd60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacd62  7551                   -jne 0xaacdb5
    if (!cpu.flags.zf)
    {
        goto L_0x00aacdb5;
    }
    // 00aacd64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aacd66  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00aacd68  e86b210000             -call 0xaaeed8
    cpu.esp -= 4;
    sub_aaeed8(app, cpu);
    if (cpu.terminate) return;
    // 00aacd6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aacd6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacd71  742a                   -je 0xaacd9d
    if (cpu.flags.zf)
    {
        goto L_0x00aacd9d;
    }
    // 00aacd73  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00aacd76  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00aacd79  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00aacd7c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aacd7f  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 00aacd82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aacd84  881d6835ab00           -mov byte ptr [0xab3568], bl
    app->getMemory<x86::reg8>(x86::reg32(11220328) /* 0xab3568 */) = cpu.bl;
    // 00aacd8a  e891e4ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aacd8f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aacd91  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00aacd97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacd98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacd99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacd9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacd9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacd9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aacd9d:
    // 00aacd9d  e84e220000             -call 0xaaeff0
    cpu.esp -= 4;
    sub_aaeff0(app, cpu);
    if (cpu.terminate) return;
    // 00aacda2  83380b                 +cmp dword ptr [eax], 0xb
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
    // 00aacda5  750e                   -jne 0xaacdb5
    if (!cpu.flags.zf)
    {
        goto L_0x00aacdb5;
    }
    // 00aacda7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aacda9  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00aacdaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aacdb5:
    // 00aacdb5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aacdba  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00aacdc1  43                     -inc ebx
    (cpu.ebx)++;
    // 00aacdc2  e8691e0000             -call 0xaaec30
    cpu.esp -= 4;
    sub_aaec30(app, cpu);
    if (cpu.terminate) return;
    // 00aacdc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacdc9  0f851cffffff           -jne 0xaacceb
    if (!cpu.flags.zf)
    {
        goto L_0x00aacceb;
    }
    // 00aacdcf  e975ffffff             -jmp 0xaacd49
    goto L_0x00aacd49;
L_0x00aacdd4:
    // 00aacdd4  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00aacdda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacddb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacddc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacddd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacdde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aacde0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aacde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacde2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aacde3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacde4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacde5  803d0039ab0000         +cmp byte ptr [0xab3900], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11221248) /* 0xab3900 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aacdec  0f85ab000000           -jne 0xaace9d
    if (!cpu.flags.zf)
    {
        goto L_0x00aace9d;
    }
    // 00aacdf2  bbec38ab00             -mov ebx, 0xab38ec
    cpu.ebx = 11221228 /*0xab38ec*/;
    // 00aacdf7  eb39                   -jmp 0xaace32
    goto L_0x00aace32;
L_0x00aacdf9:
    // 00aacdf9  e8d2acffff             -call 0xaa7ad0
    cpu.esp -= 4;
    sub_aa7ad0(app, cpu);
    if (cpu.terminate) return;
    // 00aacdfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aace00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aace02  742b                   -je 0xaace2f
    if (cpu.flags.zf)
    {
        goto L_0x00aace2f;
    }
    // 00aace04  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aace06  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aace07  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aace09  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aace0b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aace0d  49                     -dec ecx
    (cpu.ecx)--;
    // 00aace0e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aace10  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aace12  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aace14  49                     -dec ecx
    (cpu.ecx)--;
    // 00aace15  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aace16  81f903010000           +cmp ecx, 0x103
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
    // 00aace1c  7711                   -ja 0xaace2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aace2f;
    }
    // 00aace1e  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 00aace23  b80039ab00             -mov eax, 0xab3900
    cpu.eax = 11221248 /*0xab3900*/;
    // 00aace28  e803220000             -call 0xaaf030
    cpu.esp -= 4;
    sub_aaf030(app, cpu);
    if (cpu.terminate) return;
    // 00aace2d  eb0a                   -jmp 0xaace39
    goto L_0x00aace39;
L_0x00aace2f:
    // 00aace2f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00aace32:
    // 00aace32  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aace34  803800                 +cmp byte ptr [eax], 0
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
    // 00aace37  75c0                   -jne 0xaacdf9
    if (!cpu.flags.zf)
    {
        goto L_0x00aacdf9;
    }
L_0x00aace39:
    // 00aace39  803d0039ab0000         +cmp byte ptr [0xab3900], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11221248) /* 0xab3900 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aace40  752a                   -jne 0xaace6c
    if (!cpu.flags.zf)
    {
        goto L_0x00aace6c;
    }
    // 00aace42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aace44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aace46  bf0039ab00             -mov edi, 0xab3900
    cpu.edi = 11221248 /*0xab3900*/;
    // 00aace4b  e890220000             -call 0xaaf0e0
    cpu.esp -= 4;
    sub_aaf0e0(app, cpu);
    if (cpu.terminate) return;
    // 00aace50  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aace52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00aace53:
    // 00aace53  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aace55  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aace57  3c00                   +cmp al, 0
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
    // 00aace59  7410                   -je 0xaace6b
    if (cpu.flags.zf)
    {
        goto L_0x00aace6b;
    }
    // 00aace5b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aace5e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aace61  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aace64  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aace67  3c00                   +cmp al, 0
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
    // 00aace69  75e8                   -jne 0xaace53
    if (!cpu.flags.zf)
    {
        goto L_0x00aace53;
    }
L_0x00aace6b:
    // 00aace6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00aace6c:
    // 00aace6c  bf0039ab00             -mov edi, 0xab3900
    cpu.edi = 11221248 /*0xab3900*/;
    // 00aace71  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aace72  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aace74  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aace76  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aace78  49                     -dec ecx
    (cpu.ecx)--;
    // 00aace79  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aace7b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aace7d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aace7f  49                     -dec ecx
    (cpu.ecx)--;
    // 00aace80  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aace81  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00aace84  050039ab00             -add eax, 0xab3900
    (cpu.eax) += x86::reg32(x86::sreg32(11221248 /*0xab3900*/));
    // 00aace89  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aace8b  80fb5c                 +cmp bl, 0x5c
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
    // 00aace8e  740d                   -je 0xaace9d
    if (cpu.flags.zf)
    {
        goto L_0x00aace9d;
    }
    // 00aace90  80fb2f                 +cmp bl, 0x2f
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
    // 00aace93  7408                   -je 0xaace9d
    if (cpu.flags.zf)
    {
        goto L_0x00aace9d;
    }
    // 00aace95  40                     -inc eax
    (cpu.eax)++;
    // 00aace96  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 00aace99  40                     -inc eax
    (cpu.eax)++;
    // 00aace9a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00aace9d:
    // 00aace9d  b80039ab00             -mov eax, 0xab3900
    cpu.eax = 11221248 /*0xab3900*/;
    // 00aacea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacea4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacea5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacea6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacea7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaceb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaceb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaceb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaceb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaceb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaceb4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaceb6  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 00aaceba  740d                   -je 0xaacec9
    if (cpu.flags.zf)
    {
        goto L_0x00aacec9;
    }
    // 00aacebc  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00aacec0  7407                   -je 0xaacec9
    if (cpu.flags.zf)
    {
        goto L_0x00aacec9;
    }
    // 00aacec2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aacec4  e877abffff             -call 0xaa7a40
    cpu.esp -= 4;
    sub_aa7a40(app, cpu);
    if (cpu.terminate) return;
L_0x00aacec9:
    // 00aacec9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aacecc  e8af220000             -call 0xaaf180
    cpu.esp -= 4;
    sub_aaf180(app, cpu);
    if (cpu.terminate) return;
    // 00aaced1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaced3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aaced5  83f8ff                 +cmp eax, -1
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
    // 00aaced8  742a                   -je 0xaacf04
    if (cpu.flags.zf)
    {
        goto L_0x00aacf04;
    }
    // 00aaceda  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aacedd  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacee3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aacee6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aacee8  740f                   -je 0xaacef9
    if (cpu.flags.zf)
    {
        goto L_0x00aacef9;
    }
    // 00aaceea  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00aaceee  7405                   -je 0xaacef5
    if (cpu.flags.zf)
    {
        goto L_0x00aacef5;
    }
    // 00aacef0  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 00aacef3  eb04                   -jmp 0xaacef9
    goto L_0x00aacef9;
L_0x00aacef5:
    // 00aacef5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aacef7  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00aacef9:
    // 00aacef9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aacefc  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacf02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00aacf04:
    // 00aacf04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aacf10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacf10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aacf11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacf12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aacf13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aacf14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacf15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aacf16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aacf18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacf1a  7c08                   -jl 0xaacf24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aacf24;
    }
    // 00aacf1c  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
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
    // 00aacf22  7611                   -jbe 0xaacf35
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aacf35;
    }
L_0x00aacf24:
    // 00aacf24  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aacf29  e8f2e2ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aacf2e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aacf33  eb61                   -jmp 0xaacf96
    goto L_0x00aacf96;
L_0x00aacf35:
    // 00aacf35  8b150838ab00           -mov edx, dword ptr [0xab3808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aacf3b  8b2d0037ab00           -mov ebp, dword ptr [0xab3700]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11220736) /* 0xab3700 */);
    // 00aacf41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aacf43  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aacf45  8b3c9a                 -mov edi, dword ptr [edx + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00aacf48  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aacf4a  741e                   -je 0xaacf6a
    if (cpu.flags.zf)
    {
        goto L_0x00aacf6a;
    }
    // 00aacf4c  ff15f436ab00           -call dword ptr [0xab36f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220724) /* 0xab36f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacf52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aacf54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacf56  7412                   -je 0xaacf6a
    if (cpu.flags.zf)
    {
        goto L_0x00aacf6a;
    }
    // 00aacf58  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aacf5a  ff15f836ab00           -call dword ptr [0xab36f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220728) /* 0xab36f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacf60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aacf62  ff150037ab00           -call dword ptr [0xab3700]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220736) /* 0xab3700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacf68  eb21                   -jmp 0xaacf8b
    goto L_0x00aacf8b;
L_0x00aacf6a:
    // 00aacf6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aacf6c  751d                   -jne 0xaacf8b
    if (!cpu.flags.zf)
    {
        goto L_0x00aacf8b;
    }
    // 00aacf6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aacf6f  2eff156413ab00         -call dword ptr cs:[0xab1364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211620) /* 0xab1364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aacf76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacf78  7511                   -jne 0xaacf8b
    if (!cpu.flags.zf)
    {
        goto L_0x00aacf8b;
    }
    // 00aacf7a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aacf7f  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00aacf84  e897e2ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aacf89  eb09                   -jmp 0xaacf94
    goto L_0x00aacf94;
L_0x00aacf8b:
    // 00aacf8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aacf8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aacf8f  e874000000             -call 0xaad008
    cpu.esp -= 4;
    sub_aad008(app, cpu);
    if (cpu.terminate) return;
L_0x00aacf94:
    // 00aacf94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00aacf96:
    // 00aacf96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacf9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_aacfa0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacfa0  e93b220000             -jmp 0xaaf1e0
    return sub_aaf1e0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aacfb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aacfb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aacfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aacfb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aacfb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aacfb5  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
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
    // 00aacfbb  7206                   -jb 0xaacfc3
    if (cpu.flags.cf)
    {
        goto L_0x00aacfc3;
    }
    // 00aacfbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aacfbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacfc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacfc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aacfc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aacfc3:
    // 00aacfc3  83f803                 +cmp eax, 3
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
    // 00aacfc6  7d33                   -jge 0xaacffb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aacffb;
    }
    // 00aacfc8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00aacfcf  a1583aab00             -mov eax, dword ptr [0xab3a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221592) /* 0xab3a58 */);
    // 00aacfd4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aacfd6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aacfd9  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00aacfdc  751d                   -jne 0xaacffb
    if (!cpu.flags.zf)
    {
        goto L_0x00aacffb;
    }
    // 00aacfde  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00aacfe0  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00aacfe3  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00aacfe6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aacfe8  e883190000             -call 0xaae970
    cpu.esp -= 4;
    sub_aae970(app, cpu);
    if (cpu.terminate) return;
    // 00aacfed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aacfef  740a                   -je 0xaacffb
    if (cpu.flags.zf)
    {
        goto L_0x00aacffb;
    }
    // 00aacff1  a1583aab00             -mov eax, dword ptr [0xab3a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221592) /* 0xab3a58 */);
    // 00aacff6  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00aacffb:
    // 00aacffb  a1583aab00             -mov eax, dword ptr [0xab3a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221592) /* 0xab3a58 */);
    // 00aad000  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00aad003  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad005  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad006  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aad008(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad008  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad009  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00aad00c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad00e  740e                   -je 0xaad01e
    if (cpu.flags.zf)
    {
        goto L_0x00aad01e;
    }
    // 00aad010  8b1d583aab00           -mov ebx, dword ptr [0xab3a58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221592) /* 0xab3a58 */);
    // 00aad016  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00aad019  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00aad01c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad01d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad01e:
    // 00aad01e  8b1d583aab00           -mov ebx, dword ptr [0xab3a58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221592) /* 0xab3a58 */);
    // 00aad024  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00aad027  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad030(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad030  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad032  7504                   -jne 0xaad038
    if (!cpu.flags.zf)
    {
        goto L_0x00aad038;
    }
    // 00aad034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aad036:
    // 00aad036  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00aad037  90                     -nop 
    ;
L_0x00aad038:
    // 00aad038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad03a  74fa                   -je 0xaad036
    if (cpu.flags.zf)
    {
        goto L_0x00aad036;
    }
    // 00aad03c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad03d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad03f  e824e2ffff             -call 0xaab268
    cpu.esp -= 4;
    sub_aab268(app, cpu);
    if (cpu.terminate) return;
    // 00aad044  83fa7b                 +cmp edx, 0x7b
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
    // 00aad047  7507                   -jne 0xaad050
    if (!cpu.flags.zf)
    {
        goto L_0x00aad050;
    }
    // 00aad049  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad04e  eb45                   -jmp 0xaad095
    goto L_0x00aad095;
L_0x00aad050:
    // 00aad050  81face000000           +cmp edx, 0xce
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
    // 00aad056  7511                   -jne 0xaad069
    if (!cpu.flags.zf)
    {
        goto L_0x00aad069;
    }
    // 00aad058  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00aad05d  e8bee1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad062  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad067  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad068  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad069:
    // 00aad069  81fab7000000           +cmp edx, 0xb7
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
    // 00aad06f  7511                   -jne 0xaad082
    if (!cpu.flags.zf)
    {
        goto L_0x00aad082;
    }
    // 00aad071  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad076  e8a5e1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad07b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad082:
    // 00aad082  83fa13                 +cmp edx, 0x13
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
    // 00aad085  7605                   -jbe 0xaad08c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aad08c;
    }
    // 00aad087  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00aad08c:
    // 00aad08c  8b82593aab00           -mov eax, dword ptr [edx + 0xab3a59]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11221593) /* 0xab3a59 */);
    // 00aad092  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00aad095:
    // 00aad095  e886e1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad09a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad09f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad03c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aad03c;
    // 00aad030  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad032  7504                   -jne 0xaad038
    if (!cpu.flags.zf)
    {
        goto L_0x00aad038;
    }
    // 00aad034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aad036:
    // 00aad036  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00aad037  90                     -nop 
    ;
L_0x00aad038:
    // 00aad038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad03a  74fa                   -je 0xaad036
    if (cpu.flags.zf)
    {
        goto L_0x00aad036;
    }
L_entry_0x00aad03c:
    // 00aad03c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad03d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad03f  e824e2ffff             -call 0xaab268
    cpu.esp -= 4;
    sub_aab268(app, cpu);
    if (cpu.terminate) return;
    // 00aad044  83fa7b                 +cmp edx, 0x7b
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
    // 00aad047  7507                   -jne 0xaad050
    if (!cpu.flags.zf)
    {
        goto L_0x00aad050;
    }
    // 00aad049  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad04e  eb45                   -jmp 0xaad095
    goto L_0x00aad095;
L_0x00aad050:
    // 00aad050  81face000000           +cmp edx, 0xce
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
    // 00aad056  7511                   -jne 0xaad069
    if (!cpu.flags.zf)
    {
        goto L_0x00aad069;
    }
    // 00aad058  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00aad05d  e8bee1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad062  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad067  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad068  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad069:
    // 00aad069  81fab7000000           +cmp edx, 0xb7
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
    // 00aad06f  7511                   -jne 0xaad082
    if (!cpu.flags.zf)
    {
        goto L_0x00aad082;
    }
    // 00aad071  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad076  e8a5e1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad07b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad082:
    // 00aad082  83fa13                 +cmp edx, 0x13
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
    // 00aad085  7605                   -jbe 0xaad08c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aad08c;
    }
    // 00aad087  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00aad08c:
    // 00aad08c  8b82593aab00           -mov eax, dword ptr [edx + 0xab3a59]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11221593) /* 0xab3a59 */);
    // 00aad092  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00aad095:
    // 00aad095  e886e1ffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad09a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad09f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad0a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad0a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad0a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad0a6  2eff15c413ab00         -call dword ptr cs:[0xab13c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211716) /* 0xab13c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad0ad  e88affffff             -call 0xaad03c
    cpu.esp -= 4;
    sub_aad03c(app, cpu);
    if (cpu.terminate) return;
    // 00aad0b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad0c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad0c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad0c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad0c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad0c4  66833800               +cmp word ptr [eax], 0
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
    // 00aad0c8  740c                   -je 0xaad0d6
    if (cpu.flags.zf)
    {
        goto L_0x00aad0d6;
    }
L_0x00aad0ca:
    // 00aad0ca  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00aad0ce  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aad0d1  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00aad0d4  75f4                   -jne 0xaad0ca
    if (!cpu.flags.zf)
    {
        goto L_0x00aad0ca;
    }
L_0x00aad0d6:
    // 00aad0d6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aad0d8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00aad0da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_aad0e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad0e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad0e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad0e3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aad0e5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aad0e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aad0e9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aad0ea  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aad0ec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aad0ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad0ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aad0f1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00aad0f4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aad0f6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00aad0f8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00aad0fb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00aad0fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad0fe  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aad0ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aad101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad104  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad110(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad110  66833801               +cmp word ptr [eax], 1
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
    // 00aad114  751c                   -jne 0xaad132
    if (!cpu.flags.zf)
    {
        goto L_0x00aad132;
    }
    // 00aad116  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00aad11a  7416                   -je 0xaad132
    if (cpu.flags.zf)
    {
        goto L_0x00aad132;
    }
    // 00aad11c  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00aad120  663d1000               +cmp ax, 0x10
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
    // 00aad124  7206                   -jb 0xaad12c
    if (cpu.flags.cf)
    {
        goto L_0x00aad12c;
    }
    // 00aad126  663d1200               +cmp ax, 0x12
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
    // 00aad12a  7606                   -jbe 0xaad132
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aad132;
    }
L_0x00aad12c:
    // 00aad12c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad131  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad132:
    // 00aad132  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad134  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad138(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad138  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad139  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad13a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad13c  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad142  833d703aab00ff         +cmp dword ptr [0xab3a70], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11221616) /* 0xab3a70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad149  7523                   -jne 0xaad16e
    if (!cpu.flags.zf)
    {
        goto L_0x00aad16e;
    }
    // 00aad14b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad14d  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00aad152  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aad154  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad156  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aad158  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00aad15d  68942eab00             -push 0xab2e94
    app->getMemory<x86::reg32>(cpu.esp-4) = 11218580 /*0xab2e94*/;
    cpu.esp -= 4;
    // 00aad162  2eff156c13ab00         -call dword ptr cs:[0xab136c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211628) /* 0xab136c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad169  a3703aab00             -mov dword ptr [0xab3a70], eax
    app->getMemory<x86::reg32>(x86::reg32(11221616) /* 0xab3a70 */) = cpu.eax;
L_0x00aad16e:
    // 00aad16e  833d743aab00ff         +cmp dword ptr [0xab3a74], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11221620) /* 0xab3a74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad175  7523                   -jne 0xaad19a
    if (!cpu.flags.zf)
    {
        goto L_0x00aad19a;
    }
    // 00aad177  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad179  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00aad17e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00aad180  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad182  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aad184  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00aad189  689c2eab00             -push 0xab2e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11218588 /*0xab2e9c*/;
    cpu.esp -= 4;
    // 00aad18e  2eff156c13ab00         -call dword ptr cs:[0xab136c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211628) /* 0xab136c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad195  a3743aab00             -mov dword ptr [0xab3a74], eax
    app->getMemory<x86::reg32>(x86::reg32(11221620) /* 0xab3a74 */) = cpu.eax;
L_0x00aad19a:
    // 00aad19a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad19c  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad1a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad1a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad1a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad1a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad1a8  e88bffffff             -call 0xaad138
    cpu.esp -= 4;
    sub_aad138(app, cpu);
    if (cpu.terminate) return;
    // 00aad1ad  a1703aab00             -mov eax, dword ptr [0xab3a70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221616) /* 0xab3a70 */);
    // 00aad1b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aad1b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad1b4  e87fffffff             -call 0xaad138
    cpu.esp -= 4;
    sub_aad138(app, cpu);
    if (cpu.terminate) return;
    // 00aad1b9  a1743aab00             -mov eax, dword ptr [0xab3a74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221620) /* 0xab3a74 */);
    // 00aad1be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_aad1c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad1c0  dbe2                   -fnclex 
    /*nothing*/;
    // 00aad1c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad1d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad1d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad1d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad1d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad1d4  83f807                 +cmp eax, 7
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
    // 00aad1d7  7405                   -je 0xaad1de
    if (cpu.flags.zf)
    {
        goto L_0x00aad1de;
    }
    // 00aad1d9  83f804                 +cmp eax, 4
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
    // 00aad1dc  7518                   -jne 0xaad1f6
    if (!cpu.flags.zf)
    {
        goto L_0x00aad1f6;
    }
L_0x00aad1de:
    // 00aad1de  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00aad1e5  8b98783aab00           -mov ebx, dword ptr [eax + 0xab3a78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11221624) /* 0xab3a78 */);
    // 00aad1eb  8990783aab00           -mov dword ptr [eax + 0xab3a78], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11221624) /* 0xab3a78 */) = cpu.edx;
    // 00aad1f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad1f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad1f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad1f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad1f6:
    // 00aad1f6  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00aad1fd  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad203  8b5c0158               -mov ebx, dword ptr [ecx + eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1);
    // 00aad207  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad20d  89540158               -mov dword ptr [ecx + eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1) = cpu.edx;
    // 00aad211  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad215  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad218(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad218  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad219  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad21b  83f807                 +cmp eax, 7
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
    // 00aad21e  7405                   -je 0xaad225
    if (cpu.flags.zf)
    {
        goto L_0x00aad225;
    }
    // 00aad220  83f804                 +cmp eax, 4
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
    // 00aad223  7509                   -jne 0xaad22e
    if (!cpu.flags.zf)
    {
        goto L_0x00aad22e;
    }
L_0x00aad225:
    // 00aad225  8b04d5783aab00         -mov eax, dword ptr [edx*8 + 0xab3a78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221624) /* 0xab3a78 */ + cpu.edx * 8);
    // 00aad22c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad22d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad22e:
    // 00aad22e  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad234  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00aad238  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad239  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad23c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad23c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad23d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad23f  83f807                 +cmp eax, 7
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
    // 00aad242  7405                   -je 0xaad249
    if (cpu.flags.zf)
    {
        goto L_0x00aad249;
    }
    // 00aad244  83f804                 +cmp eax, 4
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
    // 00aad247  7509                   -jne 0xaad252
    if (!cpu.flags.zf)
    {
        goto L_0x00aad252;
    }
L_0x00aad249:
    // 00aad249  8b04d57c3aab00         -mov eax, dword ptr [edx*8 + 0xab3a7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221628) /* 0xab3a7c */ + cpu.edx * 8);
    // 00aad250  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad251  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad252:
    // 00aad252  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad258  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00aad25c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad25d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad260(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad261  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad263  e8d4ffffff             -call 0xaad23c
    cpu.esp -= 4;
    sub_aad23c(app, cpu);
    if (cpu.terminate) return;
    // 00aad268  39c2                   +cmp edx, eax
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
    // 00aad26a  7509                   -jne 0xaad275
    if (!cpu.flags.zf)
    {
        goto L_0x00aad275;
    }
    // 00aad26c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad26e  e8a5ffffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad273  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad274  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad275:
    // 00aad275  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad278  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad27c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad27c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aad280  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad282  760a                   -jbe 0xaad28e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aad28e;
    }
    // 00aad284  83f801                 +cmp eax, 1
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
    // 00aad287  7424                   -je 0xaad2ad
    if (cpu.flags.zf)
    {
        goto L_0x00aad2ad;
    }
    // 00aad289  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad28b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aad28e:
    // 00aad28e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aad293  e880ffffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad298  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad29a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad29c  7503                   -jne 0xaad2a1
    if (!cpu.flags.zf)
    {
        goto L_0x00aad2a1;
    }
    // 00aad29e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aad2a1:
    // 00aad2a1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aad2a6  e8dd010000             -call 0xaad488
    cpu.esp -= 4;
    sub_aad488(app, cpu);
    if (cpu.terminate) return;
    // 00aad2ab  eb1d                   -jmp 0xaad2ca
    goto L_0x00aad2ca;
L_0x00aad2ad:
    // 00aad2ad  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad2b2  e861ffffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad2b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad2b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad2bb  7503                   -jne 0xaad2c0
    if (!cpu.flags.zf)
    {
        goto L_0x00aad2c0;
    }
    // 00aad2bd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aad2c0:
    // 00aad2c0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad2c5  e8be010000             -call 0xaad488
    cpu.esp -= 4;
    sub_aad488(app, cpu);
    if (cpu.terminate) return;
L_0x00aad2ca:
    // 00aad2ca  83fa02                 +cmp edx, 2
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
    // 00aad2cd  7405                   -je 0xaad2d4
    if (cpu.flags.zf)
    {
        goto L_0x00aad2d4;
    }
    // 00aad2cf  83fa03                 +cmp edx, 3
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
    // 00aad2d2  7505                   -jne 0xaad2d9
    if (!cpu.flags.zf)
    {
        goto L_0x00aad2d9;
    }
L_0x00aad2d4:
    // 00aad2d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad2d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00aad2d9:
    // 00aad2d9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad2de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad2e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad2e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad2e5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aad2ea  e829ffffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad2ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aad2f1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad2f6  e81dffffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad2fb  83fa02                 +cmp edx, 2
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
    // 00aad2fe  7405                   -je 0xaad305
    if (cpu.flags.zf)
    {
        goto L_0x00aad305;
    }
    // 00aad300  83fa03                 +cmp edx, 3
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
    // 00aad303  750a                   -jne 0xaad30f
    if (!cpu.flags.zf)
    {
        goto L_0x00aad30f;
    }
L_0x00aad305:
    // 00aad305  83f802                 +cmp eax, 2
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
    // 00aad308  740c                   -je 0xaad316
    if (cpu.flags.zf)
    {
        goto L_0x00aad316;
    }
    // 00aad30a  83f803                 +cmp eax, 3
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
    // 00aad30d  7407                   -je 0xaad316
    if (cpu.flags.zf)
    {
        goto L_0x00aad316;
    }
L_0x00aad30f:
    // 00aad30f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad314  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad316:
    // 00aad316  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad318  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad31c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad31c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad31d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad31e  803de03aab0000         +cmp byte ptr [0xab3ae0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aad325  7519                   -jne 0xaad340
    if (!cpu.flags.zf)
    {
        goto L_0x00aad340;
    }
    // 00aad327  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aad329  687cd2aa00             -push 0xaad27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11195004 /*0xaad27c*/;
    cpu.esp -= 4;
    // 00aad32e  2eff15f813ab00         -call dword ptr cs:[0xab13f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211768) /* 0xab13f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad335  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad337  7407                   -je 0xaad340
    if (cpu.flags.zf)
    {
        goto L_0x00aad340;
    }
    // 00aad339  c605e03aab0001         -mov byte ptr [0xab3ae0], 1
    app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */) = 1 /*0x1*/;
L_0x00aad340:
    // 00aad340  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad342  a0e03aab00             -mov al, byte ptr [0xab3ae0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */);
    // 00aad347  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad348  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad34c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad34c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad34d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad34e  803de03aab0000         +cmp byte ptr [0xab3ae0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aad355  741a                   -je 0xaad371
    if (cpu.flags.zf)
    {
        goto L_0x00aad371;
    }
    // 00aad357  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad359  687cd2aa00             -push 0xaad27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11195004 /*0xaad27c*/;
    cpu.esp -= 4;
    // 00aad35e  2eff15f813ab00         -call dword ptr cs:[0xab13f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211768) /* 0xab13f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad365  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad367  7408                   -je 0xaad371
    if (cpu.flags.zf)
    {
        goto L_0x00aad371;
    }
    // 00aad369  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aad36b  8815e03aab00           -mov byte ptr [0xab3ae0], dl
    app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */) = cpu.dl;
L_0x00aad371:
    // 00aad371  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad373  a0e03aab00             -mov al, byte ptr [0xab3ae0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11221728) /* 0xab3ae0 */);
    // 00aad378  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad37a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00aad37d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aad382  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aad388(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad388  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad38d  e9f6000000             -jmp 0xaad488
    return sub_aad488(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_aad394(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad395  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad396  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad397  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad399  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00aad39e  e875feffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad3a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aad3a5  83f801                 +cmp eax, 1
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
    // 00aad3a8  7425                   -je 0xaad3cf
    if (cpu.flags.zf)
    {
        goto L_0x00aad3cf;
    }
    // 00aad3aa  83f802                 +cmp eax, 2
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
    // 00aad3ad  7420                   -je 0xaad3cf
    if (cpu.flags.zf)
    {
        goto L_0x00aad3cf;
    }
    // 00aad3af  83f803                 +cmp eax, 3
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
    // 00aad3b2  741b                   -je 0xaad3cf
    if (cpu.flags.zf)
    {
        goto L_0x00aad3cf;
    }
    // 00aad3b4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aad3b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aad3bb  e810feffff             -call 0xaad1d0
    cpu.esp -= 4;
    sub_aad1d0(app, cpu);
    if (cpu.terminate) return;
    // 00aad3c0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00aad3c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aad3c7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad3c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad3cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad3cf:
    // 00aad3cf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad3d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad3d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad3d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad3d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad3da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad3db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad3dd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aad3df  83f801                 +cmp eax, 1
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
    // 00aad3e2  7c05                   -jl 0xaad3e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aad3e9;
    }
    // 00aad3e4  83f80c                 +cmp eax, 0xc
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
    // 00aad3e7  7e13                   -jle 0xaad3fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aad3fc;
    }
L_0x00aad3e9:
    // 00aad3e9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00aad3ee  e82ddeffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aad3f3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00aad3f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad3fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad3fc:
    // 00aad3fc  c705803bab0088d3aa00   -mov dword ptr [0xab3b80], 0xaad388
    app->getMemory<x86::reg32>(x86::reg32(11221888) /* 0xab3b80 */) = 11195272 /*0xaad388*/;
    // 00aad406  83f902                 +cmp ecx, 2
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
    // 00aad409  741f                   -je 0xaad42a
    if (cpu.flags.zf)
    {
        goto L_0x00aad42a;
    }
    // 00aad40b  83f903                 +cmp ecx, 3
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
    // 00aad40e  741a                   -je 0xaad42a
    if (cpu.flags.zf)
    {
        goto L_0x00aad42a;
    }
    // 00aad410  e827feffff             -call 0xaad23c
    cpu.esp -= 4;
    sub_aad23c(app, cpu);
    if (cpu.terminate) return;
    // 00aad415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad417  7411                   -je 0xaad42a
    if (cpu.flags.zf)
    {
        goto L_0x00aad42a;
    }
    // 00aad419  83fb02                 +cmp ebx, 2
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
    // 00aad41c  750c                   -jne 0xaad42a
    if (!cpu.flags.zf)
    {
        goto L_0x00aad42a;
    }
    // 00aad41e  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00aad423  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad425  e8f61d0000             -call 0xaaf220
    cpu.esp -= 4;
    sub_aaf220(app, cpu);
    if (cpu.terminate) return;
L_0x00aad42a:
    // 00aad42a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad42c  e8e7fdffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad431  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aad433  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aad435  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad437  e894fdffff             -call 0xaad1d0
    cpu.esp -= 4;
    sub_aad1d0(app, cpu);
    if (cpu.terminate) return;
    // 00aad43c  e8a3feffff             -call 0xaad2e4
    cpu.esp -= 4;
    sub_aad2e4(app, cpu);
    if (cpu.terminate) return;
    // 00aad441  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad443  7407                   -je 0xaad44c
    if (cpu.flags.zf)
    {
        goto L_0x00aad44c;
    }
    // 00aad445  e8d2feffff             -call 0xaad31c
    cpu.esp -= 4;
    sub_aad31c(app, cpu);
    if (cpu.terminate) return;
    // 00aad44a  eb05                   -jmp 0xaad451
    goto L_0x00aad451;
L_0x00aad44c:
    // 00aad44c  e8fbfeffff             -call 0xaad34c
    cpu.esp -= 4;
    sub_aad34c(app, cpu);
    if (cpu.terminate) return;
L_0x00aad451:
    // 00aad451  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aad453  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad454  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad455  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad456  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aad488(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00aad488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad489  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad48a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad48b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad48d  e886fdffff             -call 0xaad218
    cpu.esp -= 4;
    sub_aad218(app, cpu);
    if (cpu.terminate) return;
    // 00aad492  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00aad495  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aad497  83fa0b                 +cmp edx, 0xb
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
    // 00aad49a  774d                   -ja 0xaad4e9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aad4e9;
    }
    // 00aad49c  2eff249558d4aa00       -jmp dword ptr cs:[edx*4 + 0xaad458]
    cpu.ip = app->getMemory<x86::reg32>(11195480 + cpu.edx * 4); goto dynamic_jump;
  case 0x00aad4a4:
    // 00aad4a4  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00aad4a9  e8e6feffff             -call 0xaad394
    cpu.esp -= 4;
    sub_aad394(app, cpu);
    if (cpu.terminate) return;
    // 00aad4ae  eb42                   -jmp 0xaad4f2
    goto L_0x00aad4f2;
  case 0x00aad4b0:
    // 00aad4b0  83f802                 +cmp eax, 2
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
    // 00aad4b3  7505                   -jne 0xaad4ba
    if (!cpu.flags.zf)
    {
        goto L_0x00aad4ba;
    }
    // 00aad4b5  e84e1d0000             -call 0xaaf208
    cpu.esp -= 4;
    sub_aaf208(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00aad4ba:
L_0x00aad4ba:
    // 00aad4ba  83f901                 +cmp ecx, 1
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
    // 00aad4bd  741a                   -je 0xaad4d9
    if (cpu.flags.zf)
    {
        goto L_0x00aad4d9;
    }
    // 00aad4bf  83f902                 +cmp ecx, 2
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
    // 00aad4c2  7415                   -je 0xaad4d9
    if (cpu.flags.zf)
    {
        goto L_0x00aad4d9;
    }
    // 00aad4c4  83f903                 +cmp ecx, 3
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
    // 00aad4c7  7410                   -je 0xaad4d9
    if (cpu.flags.zf)
    {
        goto L_0x00aad4d9;
    }
    // 00aad4c9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aad4ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad4d0  e8fbfcffff             -call 0xaad1d0
    cpu.esp -= 4;
    sub_aad1d0(app, cpu);
    if (cpu.terminate) return;
    // 00aad4d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad4d7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aad4d9:
    // 00aad4d9  e806feffff             -call 0xaad2e4
    cpu.esp -= 4;
    sub_aad2e4(app, cpu);
    if (cpu.terminate) return;
    // 00aad4de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad4e0  7510                   -jne 0xaad4f2
    if (!cpu.flags.zf)
    {
        goto L_0x00aad4f2;
    }
    // 00aad4e2  e865feffff             -call 0xaad34c
    cpu.esp -= 4;
    sub_aad34c(app, cpu);
    if (cpu.terminate) return;
    // 00aad4e7  eb09                   -jmp 0xaad4f2
    goto L_0x00aad4f2;
L_0x00aad4e9:
    // 00aad4e9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad4ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad4f2:
    // 00aad4f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad4f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad4f7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_aad4f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad4f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad4f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad4fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad4fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad4fc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aad4fd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00aad502:
    // 00aad502  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aad508  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00aad50b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aad50d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aad50f  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00aad512  8db2783aab00           -lea esi, [edx + 0xab3a78]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(11221624) /* 0xab3a78 */);
    // 00aad518  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aad51b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aad51c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00aad51d  83fa68                 +cmp edx, 0x68
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
    // 00aad520  75e0                   -jne 0xaad502
    if (!cpu.flags.zf)
    {
        goto L_0x00aad502;
    }
    // 00aad522  ba60d2aa00             -mov edx, 0xaad260
    cpu.edx = 11194976 /*0xaad260*/;
    // 00aad527  bb88d4aa00             -mov ebx, 0xaad488
    cpu.ebx = 11195528 /*0xaad488*/;
    // 00aad52c  89151438ab00           -mov dword ptr [0xab3814], edx
    app->getMemory<x86::reg32>(x86::reg32(11221012) /* 0xab3814 */) = cpu.edx;
    // 00aad532  891d1838ab00           -mov dword ptr [0xab3818], ebx
    app->getMemory<x86::reg32>(x86::reg32(11221016) /* 0xab3818 */) = cpu.ebx;
    // 00aad538  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aad539  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad53a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad53b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad53c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad53d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aad540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad540  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad541  e89efdffff             -call 0xaad2e4
    cpu.esp -= 4;
    sub_aad2e4(app, cpu);
    if (cpu.terminate) return;
    // 00aad546  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad548  7423                   -je 0xaad56d
    if (cpu.flags.zf)
    {
        goto L_0x00aad56d;
    }
    // 00aad54a  e8fdfdffff             -call 0xaad34c
    cpu.esp -= 4;
    sub_aad34c(app, cpu);
    if (cpu.terminate) return;
    // 00aad54f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aad554  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aad559  e872fcffff             -call 0xaad1d0
    cpu.esp -= 4;
    sub_aad1d0(app, cpu);
    if (cpu.terminate) return;
    // 00aad55e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00aad563  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00aad568  e863fcffff             -call 0xaad1d0
    cpu.esp -= 4;
    sub_aad1d0(app, cpu);
    if (cpu.terminate) return;
L_0x00aad56d:
    // 00aad56d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad56e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aad570(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad572  baf8d4aa00             -mov edx, 0xaad4f8
    cpu.edx = 11195640 /*0xaad4f8*/;
    // 00aad577  bb40d5aa00             -mov ebx, 0xaad540
    cpu.ebx = 11195712 /*0xaad540*/;
    // 00aad57c  8915e836ab00           -mov dword ptr [0xab36e8], edx
    app->getMemory<x86::reg32>(x86::reg32(11220712) /* 0xab36e8 */) = cpu.edx;
    // 00aad582  891dec36ab00           -mov dword ptr [0xab36ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220716) /* 0xab36ec */) = cpu.ebx;
    // 00aad588  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad589  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aad590(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad594  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad595  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aad596  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aad599  b8a42eab00             -mov eax, 0xab2ea4
    cpu.eax = 11218596 /*0xab2ea4*/;
    // 00aad59e  e82da5ffff             -call 0xaa7ad0
    cpu.esp -= 4;
    sub_aa7ad0(app, cpu);
    if (cpu.terminate) return;
    // 00aad5a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aad5a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad5a7  0f84f9000000           -je 0xaad6a6
    if (cpu.flags.zf)
    {
        goto L_0x00aad6a6;
    }
L_0x00aad5ad:
    // 00aad5ad  803900                 +cmp byte ptr [ecx], 0
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
    // 00aad5b0  0f84e6000000           -je 0xaad69c
    if (cpu.flags.zf)
    {
        goto L_0x00aad69c;
    }
    // 00aad5b6  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00aad5b8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00aad5ba:
    // 00aad5ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad5bc  3ac2                   +cmp al, dl
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
    // 00aad5be  7412                   -je 0xaad5d2
    if (cpu.flags.zf)
    {
        goto L_0x00aad5d2;
    }
    // 00aad5c0  3c00                   +cmp al, 0
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
    // 00aad5c2  740c                   -je 0xaad5d0
    if (cpu.flags.zf)
    {
        goto L_0x00aad5d0;
    }
    // 00aad5c4  46                     -inc esi
    (cpu.esi)++;
    // 00aad5c5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad5c7  3ac2                   +cmp al, dl
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
    // 00aad5c9  7407                   -je 0xaad5d2
    if (cpu.flags.zf)
    {
        goto L_0x00aad5d2;
    }
    // 00aad5cb  46                     -inc esi
    (cpu.esi)++;
    // 00aad5cc  3c00                   +cmp al, 0
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
    // 00aad5ce  75ea                   -jne 0xaad5ba
    if (!cpu.flags.zf)
    {
        goto L_0x00aad5ba;
    }
L_0x00aad5d0:
    // 00aad5d0  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00aad5d2:
    // 00aad5d2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad5d4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00aad5d6  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aad5d8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aad5da  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aad5dc  e88f1c0000             -call 0xaaf270
    cpu.esp -= 4;
    sub_aaf270(app, cpu);
    if (cpu.terminate) return;
    // 00aad5e1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00aad5e6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aad5e8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad5ea  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00aad5ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aad5ef  e80c1e0000             -call 0xaaf400
    cpu.esp -= 4;
    sub_aaf400(app, cpu);
    if (cpu.terminate) return;
    // 00aad5f4  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00aad5f7  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00aad5f9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aad5fb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00aad5fd:
    // 00aad5fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad5ff  3ac2                   +cmp al, dl
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
    // 00aad601  7412                   -je 0xaad615
    if (cpu.flags.zf)
    {
        goto L_0x00aad615;
    }
    // 00aad603  3c00                   +cmp al, 0
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
    // 00aad605  740c                   -je 0xaad613
    if (cpu.flags.zf)
    {
        goto L_0x00aad613;
    }
    // 00aad607  46                     -inc esi
    (cpu.esi)++;
    // 00aad608  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad60a  3ac2                   +cmp al, dl
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
    // 00aad60c  7407                   -je 0xaad615
    if (cpu.flags.zf)
    {
        goto L_0x00aad615;
    }
    // 00aad60e  46                     -inc esi
    (cpu.esi)++;
    // 00aad60f  3c00                   +cmp al, 0
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
    // 00aad611  75ea                   -jne 0xaad5fd
    if (!cpu.flags.zf)
    {
        goto L_0x00aad5fd;
    }
L_0x00aad613:
    // 00aad613  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00aad615:
    // 00aad615  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad617  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00aad619  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aad61b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aad61d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aad61f  e84c1c0000             -call 0xaaf270
    cpu.esp -= 4;
    sub_aaf270(app, cpu);
    if (cpu.terminate) return;
    // 00aad624  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00aad629  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00aad62b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad62d  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00aad630  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aad632  e8c91d0000             -call 0xaaf400
    cpu.esp -= 4;
    sub_aaf400(app, cpu);
    if (cpu.terminate) return;
    // 00aad637  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00aad63a  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00aad63c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00aad640  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00aad642:
    // 00aad642  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad644  3ac2                   +cmp al, dl
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
    // 00aad646  7412                   -je 0xaad65a
    if (cpu.flags.zf)
    {
        goto L_0x00aad65a;
    }
    // 00aad648  3c00                   +cmp al, 0
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
    // 00aad64a  740c                   -je 0xaad658
    if (cpu.flags.zf)
    {
        goto L_0x00aad658;
    }
    // 00aad64c  46                     -inc esi
    (cpu.esi)++;
    // 00aad64d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aad64f  3ac2                   +cmp al, dl
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
    // 00aad651  7407                   -je 0xaad65a
    if (cpu.flags.zf)
    {
        goto L_0x00aad65a;
    }
    // 00aad653  46                     -inc esi
    (cpu.esi)++;
    // 00aad654  3c00                   +cmp al, 0
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
    // 00aad656  75ea                   -jne 0xaad642
    if (!cpu.flags.zf)
    {
        goto L_0x00aad642;
    }
L_0x00aad658:
    // 00aad658  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00aad65a:
    // 00aad65a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad65c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00aad65e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aad660  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aad662  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aad664  e8071c0000             -call 0xaaf270
    cpu.esp -= 4;
    sub_aaf270(app, cpu);
    if (cpu.terminate) return;
    // 00aad669  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad66b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00aad66d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aad66f  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00aad672  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00aad677  e8841d0000             -call 0xaaf400
    cpu.esp -= 4;
    sub_aaf400(app, cpu);
    if (cpu.terminate) return;
    // 00aad67c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aad67e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aad680  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aad684  e8afddffff             -call 0xaab438
    cpu.esp -= 4;
    sub_aab438(app, cpu);
    if (cpu.terminate) return;
    // 00aad689  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aad68b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aad68d  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00aad690  e873f9ffff             -call 0xaad008
    cpu.esp -= 4;
    sub_aad008(app, cpu);
    if (cpu.terminate) return;
    // 00aad695  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00aad697  e911ffffff             -jmp 0xaad5ad
    goto L_0x00aad5ad;
L_0x00aad69c:
    // 00aad69c  b8b02eab00             -mov eax, 0xab2eb0
    cpu.eax = 11218608 /*0xab2eb0*/;
    // 00aad6a1  e8ca1d0000             -call 0xaaf470
    cpu.esp -= 4;
    sub_aaf470(app, cpu);
    if (cpu.terminate) return;
L_0x00aad6a6:
    // 00aad6a6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aad6a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad6af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad6b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad6b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad6b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad6b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad6b4  8b15a44eab00           -mov edx, dword ptr [0xab4ea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aad6ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad6bc  0f8480000000           -je 0xaad742
    if (cpu.flags.zf)
    {
        goto L_0x00aad742;
    }
    // 00aad6c2  eb30                   -jmp 0xaad6f4
    goto L_0x00aad6f4;
L_0x00aad6c4:
    // 00aad6c4  833da04eab0000         +cmp dword ptr [0xab4ea0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11226784) /* 0xab4ea0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad6cb  7424                   -je 0xaad6f1
    if (cpu.flags.zf)
    {
        goto L_0x00aad6f1;
    }
    // 00aad6cd  8b35a44eab00           -mov esi, dword ptr [0xab4ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aad6d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aad6d5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00aad6d7  8b1da04eab00           -mov ebx, dword ptr [0xab4ea0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11226784) /* 0xab4ea0 */);
    // 00aad6dd  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00aad6e0  803c1900               +cmp byte ptr [ecx + ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aad6e4  7405                   -je 0xaad6eb
    if (cpu.flags.zf)
    {
        goto L_0x00aad6eb;
    }
    // 00aad6e6  e8b5a6ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
L_0x00aad6eb:
    // 00aad6eb  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x00aad6f1:
    // 00aad6f1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00aad6f4:
    // 00aad6f4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aad6f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad6f8  75ca                   -jne 0xaad6c4
    if (!cpu.flags.zf)
    {
        goto L_0x00aad6c4;
    }
    // 00aad6fa  833da04eab0000         +cmp dword ptr [0xab4ea0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11226784) /* 0xab4ea0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad701  750c                   -jne 0xaad70f
    if (!cpu.flags.zf)
    {
        goto L_0x00aad70f;
    }
    // 00aad703  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00aad708  e8a3a5ffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aad70d  eb0f                   -jmp 0xaad71e
    goto L_0x00aad71e;
L_0x00aad70f:
    // 00aad70f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00aad714  a1a44eab00             -mov eax, dword ptr [0xab4ea4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */);
    // 00aad719  e8d2e9ffff             -call 0xaac0f0
    cpu.esp -= 4;
    sub_aac0f0(app, cpu);
    if (cpu.terminate) return;
L_0x00aad71e:
    // 00aad71e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad720  750a                   -jne 0xaad72c
    if (!cpu.flags.zf)
    {
        goto L_0x00aad72c;
    }
    // 00aad722  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aad727  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad728  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad729  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad72a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad72b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad72c:
    // 00aad72c  a3a44eab00             -mov dword ptr [0xab4ea4], eax
    app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */) = cpu.eax;
    // 00aad731  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00aad737  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aad73a  a3a04eab00             -mov dword ptr [0xab4ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11226784) /* 0xab4ea0 */) = cpu.eax;
    // 00aad73f  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00aad742:
    // 00aad742  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad744  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad745  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad746  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad747  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad748  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad750(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad751  833d505aab0000         +cmp dword ptr [0xab5a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad758  7421                   -je 0xaad77b
    if (cpu.flags.zf)
    {
        goto L_0x00aad77b;
    }
    // 00aad75a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aad75c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00aad75e  8a9b615aab00           -mov bl, byte ptr [ebx + 0xab5a61]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aad764  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aad767  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aad76d  740c                   -je 0xaad77b
    if (cpu.flags.zf)
    {
        goto L_0x00aad77b;
    }
    // 00aad76f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00aad771  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00aad773  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00aad776  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00aad779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad77a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad77b:
    // 00aad77b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00aad77d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00aad77f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad780  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aad790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad790  833d505aab0000         +cmp dword ptr [0xab5a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad797  741c                   -je 0xaad7b5
    if (cpu.flags.zf)
    {
        goto L_0x00aad7b5;
    }
    // 00aad799  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00aad79b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aad7a0  8a80615aab00           -mov al, byte ptr [eax + 0xab5a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aad7a6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aad7a8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aad7ad  7406                   -je 0xaad7b5
    if (cpu.flags.zf)
    {
        goto L_0x00aad7b5;
    }
    // 00aad7af  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00aad7b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad7b5:
    // 00aad7b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aad7ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aad7c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad7c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad7c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad7c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aad7c3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aad7c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00aad7c8:
    // 00aad7c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aad7ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad7cc  e89fe5ffff             -call 0xaabd70
    cpu.esp -= 4;
    sub_aabd70(app, cpu);
    if (cpu.terminate) return;
    // 00aad7d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aad7d3  7531                   -jne 0xaad806
    if (!cpu.flags.zf)
    {
        goto L_0x00aad806;
    }
    // 00aad7d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad7d7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00aad7d9  e802210000             -call 0xaaf8e0
    cpu.esp -= 4;
    sub_aaf8e0(app, cpu);
    if (cpu.terminate) return;
    // 00aad7de  e83d210000             -call 0xaaf920
    cpu.esp -= 4;
    sub_aaf920(app, cpu);
    if (cpu.terminate) return;
    // 00aad7e3  e8a8210000             -call 0xaaf990
    cpu.esp -= 4;
    sub_aaf990(app, cpu);
    if (cpu.terminate) return;
    // 00aad7e8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aad7ea  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00aad7ec  e89fffffff             -call 0xaad790
    cpu.esp -= 4;
    sub_aad790(app, cpu);
    if (cpu.terminate) return;
    // 00aad7f1  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00aad7f4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00aad7f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad7f8  e853ffffff             -call 0xaad750
    cpu.esp -= 4;
    sub_aad750(app, cpu);
    if (cpu.terminate) return;
    // 00aad7fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad7ff  e80ce6ffff             -call 0xaabe10
    cpu.esp -= 4;
    sub_aabe10(app, cpu);
    if (cpu.terminate) return;
    // 00aad804  ebc2                   -jmp 0xaad7c8
    goto L_0x00aad7c8;
L_0x00aad806:
    // 00aad806  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aad808  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aad80b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad80c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad80d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad80e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_aad810(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad812  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aad814  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aad816  7541                   -jne 0xaad859
    if (!cpu.flags.zf)
    {
        goto L_0x00aad859;
    }
    // 00aad818  833d505aab0000         +cmp dword ptr [0xab5a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aad81f  741f                   -je 0xaad840
    if (cpu.flags.zf)
    {
        goto L_0x00aad840;
    }
    // 00aad821  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aad823  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aad825  8a9b615aab00           -mov bl, byte ptr [ebx + 0xab5a61]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aad82b  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aad82e  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aad834  740a                   -je 0xaad840
    if (cpu.flags.zf)
    {
        goto L_0x00aad840;
    }
    // 00aad836  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aad839  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00aad83c  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aad83e  7505                   -jne 0xaad845
    if (!cpu.flags.zf)
    {
        goto L_0x00aad845;
    }
L_0x00aad840:
    // 00aad840  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad842  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad843  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad844  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad845:
    // 00aad845  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00aad847  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aad84c  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00aad84e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aad854  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aad856  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad857  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad858  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aad859:
    // 00aad859  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aad85b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aad85d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad85f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00aad861  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aad863  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aad865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad866  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad868(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad868  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aad869  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aad86b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad86d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad86e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad86f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aad872  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aad874  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aad876  81fa00200000           +cmp edx, 0x2000
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
    // 00aad87c  7c05                   -jl 0xaad883
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aad883;
    }
    // 00aad87e  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00aad883:
    // 00aad883  b9e43aab00             -mov ecx, 0xab3ae4
    cpu.ecx = 11221732 /*0xab3ae4*/;
    // 00aad888  eb2e                   -jmp 0xaad8b8
    goto L_0x00aad8b8;
L_0x00aad88a:
    // 00aad88a  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00aad88f  7422                   -je 0xaad8b3
    if (cpu.flags.zf)
    {
        goto L_0x00aad8b3;
    }
    // 00aad891  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aad895  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00aad899  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aad89c  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00aad89f  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad8a2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aad8a4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00aad8a6  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00aad8a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aad8ab  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00aad8ad  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00aad8af  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aad8b1  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aad8b3:
    // 00aad8b3  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00aad8b5  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00aad8b8:
    // 00aad8b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aad8ba  7fce                   -jg 0xaad88a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aad88a;
    }
    // 00aad8bc  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00aad8bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad8bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aad8bc;
    // 00aad868  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aad869  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aad86b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad86d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad86e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad86f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aad872  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aad874  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aad876  81fa00200000           +cmp edx, 0x2000
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
    // 00aad87c  7c05                   -jl 0xaad883
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aad883;
    }
    // 00aad87e  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00aad883:
    // 00aad883  b9e43aab00             -mov ecx, 0xab3ae4
    cpu.ecx = 11221732 /*0xab3ae4*/;
    // 00aad888  eb2e                   -jmp 0xaad8b8
    goto L_0x00aad8b8;
L_0x00aad88a:
    // 00aad88a  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00aad88f  7422                   -je 0xaad8b3
    if (cpu.flags.zf)
    {
        goto L_0x00aad8b3;
    }
    // 00aad891  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aad895  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00aad899  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aad89c  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00aad89f  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad8a2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00aad8a4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00aad8a6  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00aad8a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aad8ab  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00aad8ad  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00aad8af  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aad8b1  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aad8b3:
    // 00aad8b3  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00aad8b5  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00aad8b8:
    // 00aad8b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aad8ba  7fce                   -jg 0xaad88a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aad88a;
    }
L_entry_0x00aad8bc:
    // 00aad8bc  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00aad8bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aad8c5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aad8c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aad8c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aad8c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aad8c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aad8ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aad8cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aad8cc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00aad8cf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aad8d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad8d3  74e7                   -je 0xaad8bc
    if (cpu.flags.zf)
    {
        return sub_aad8bc(app, cpu);
    }
    // 00aad8d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aad8d7  9b                     -wait 
    /*nothing*/;
    // 00aad8d8  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00aad8db  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8dc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aad8de  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00aad8e1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aad8e6  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 00aad8eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aad8ec  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00aad8ef  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad8f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00aad8f2  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 00aad8f6  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00aad8fb  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00aad8fe  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00aad901  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aad903  7d1b                   -jge 0xaad920
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aad920;
    }
    // 00aad905  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad908  f7da                   +neg edx
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
    // 00aad90a  e859ffffff             -call 0xaad868
    cpu.esp -= 4;
    sub_aad868(app, cpu);
    if (cpu.terminate) return;
    // 00aad90f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aad911  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad914  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aad916  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00aad918  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00aad91a  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aad91c  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aad91e  eb17                   -jmp 0xaad937
    goto L_0x00aad937;
L_0x00aad920:
    // 00aad920  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad923  e840ffffff             -call 0xaad868
    cpu.esp -= 4;
    sub_aad868(app, cpu);
    if (cpu.terminate) return;
    // 00aad928  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aad92a  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00aad92d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aad92f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00aad931  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00aad933  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00aad935  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aad937:
    // 00aad937  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aad939  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 00aad93c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aad93d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00aad940  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aad941  e976ffffff             -jmp 0xaad8bc
    return sub_aad8bc(app, cpu);
}

}
