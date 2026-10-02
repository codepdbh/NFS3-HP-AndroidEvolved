#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

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

/* align: skip  */
void Application::sub_51f520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051f521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f522  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051f523  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f526  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051f528  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051f52a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0051f52c  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f530  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0051f532  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0051f535  83e13f                 -and ecx, 0x3f
    cpu.ecx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0051f538  e823b7fcff             -call 0x4eac60
    cpu.esp -= 4;
    sub_4eac60(app, cpu);
    if (cpu.terminate) return;
    // 0051f53d  69c17e480600           -imul eax, ecx, 0x6487e
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0051f543  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f547  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 0051f54a  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0051f54d  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0051f550  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051f553  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0051f556  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051f558  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0051f55a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051f55d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051f55f  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0051f562  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051f565  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051f569  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 0051f56c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051f56e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051f570  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f573  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f575  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f576  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51f580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f580  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f581  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f583  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f585  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f588  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f58b  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0051f58e  c700ddf55100           -mov dword ptr [eax], 0x51f5dd
    app->getMemory<x86::reg32>(cpu.eax) = 5371357 /*0x51f5dd*/;
    // 0051f594  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f597  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0051f59a  c700a4f55100           -mov dword ptr [eax], 0x51f5a4
    app->getMemory<x86::reg32>(cpu.eax) = 5371300 /*0x51f5a4*/;
    // 0051f5a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5a1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5a2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f5a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f5a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f5a5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f5a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f5a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f5a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f5aa  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f5ad  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f5b0  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f5b3  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f5b6  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f5b9  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f5bd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051f5bf  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051f5c2  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f5c5  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f5c8  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f5cb  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f5ce  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f5d2  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051f5d5  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051f5d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5da  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5db  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f5dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f5dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f5dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f5de  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f5e0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0051f5e1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f5e4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f5e7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f5ea  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 0051f5ed  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0051f5f1  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051f5f4  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051f5f6  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051f5f9  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f5fc  7405                   -je 0x51f603
    if (cpu.flags.zf)
    {
        goto L_0x0051f603;
    }
    // 0051f5fe  83e904                 +sub ecx, 4
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
    // 0051f601  7c3e                   -jl 0x51f641
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f641;
    }
L_0x0051f603:
    // 0051f603  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f606  0f7fcc                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 0051f609  0f6e2f                 -movd mm5, dword ptr [edi]
    cpu.mmx.mm5 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.edi)) };
    // 0051f60c  0f60f5                 -punpcklbw mm6, mm5
    cpu.mmx.mm6 = { _mm_unpacklo_epi8(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 0051f60f  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 0051f612  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 0051f615  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 0051f618  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 0051f61b  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 0051f61e  0fed5500               -paddsw mm2, qword ptr [ebp]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 0051f622  0fed5d08               -paddsw mm3, qword ptr [ebp + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 0051f626  0f7f5500               -movq qword ptr [ebp], mm2
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm2;
    // 0051f62a  0f7f5d08               -movq qword ptr [ebp + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 0051f62e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f631  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051f634  83e904                 +sub ecx, 4
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
    // 0051f637  7fca                   -jg 0x51f603
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051f603;
    }
    // 0051f639  83f900                 +cmp ecx, 0
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
    // 0051f63c  7503                   -jne 0x51f641
    if (!cpu.flags.zf)
    {
        goto L_0x0051f641;
    }
    // 0051f63e  61                     -popal 
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
    // 0051f63f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f640  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f641:
    // 0051f641  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f644  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051f646  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
L_0x0051f64b:
    // 0051f64b  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f64e  0f7fcc                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 0051f651  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 0051f653  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0051f656  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 0051f659  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 0051f65c  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 0051f65f  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 0051f662  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 0051f665  0f6e5d00               -movd mm3, dword ptr [ebp]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 0051f669  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 0051f66c  0f7e5d00               -movd dword ptr [ebp], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm3);
    // 0051f670  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0051f673  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f676  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f679  7cd0                   -jl 0x51f64b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f64b;
    }
    // 0051f67b  61                     -popal 
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
    // 0051f67c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f67d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_51f680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f680  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f681  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f683  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f684  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f685  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f688  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f68b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051f68e  c700c7f65100           -mov dword ptr [eax], 0x51f6c7
    app->getMemory<x86::reg32>(cpu.eax) = 5371591 /*0x51f6c7*/;
    // 0051f694  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f697  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051f69a  c700a4f65100           -mov dword ptr [eax], 0x51f6a4
    app->getMemory<x86::reg32>(cpu.eax) = 5371556 /*0x51f6a4*/;
    // 0051f6a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6a1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6a2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f6a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f6a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f6a5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f6a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f6a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f6a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f6aa  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f6ad  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f6b0  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f6b3  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f6b6  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f6b9  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f6bd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051f6bf  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051f6c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6c4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6c5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f6c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f6c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f6c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f6c8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f6ca  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0051f6cb  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f6ce  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f6d1  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f6d4  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 0051f6d7  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051f6da  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051f6dc  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051f6df  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f6e2  7405                   -je 0x51f6e9
    if (cpu.flags.zf)
    {
        goto L_0x0051f6e9;
    }
    // 0051f6e4  83e904                 +sub ecx, 4
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
    // 0051f6e7  7c38                   -jl 0x51f721
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f721;
    }
L_0x0051f6e9:
    // 0051f6e9  0f6f1f                 -movq mm3, qword ptr [edi]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 0051f6ec  0f7fc1                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 0051f6ef  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f6f2  0f60e3                 -punpcklbw mm4, mm3
    cpu.mmx.mm4 = { _mm_unpacklo_epi8(cpu.mmx.mm4, cpu.mmx.mm3) };
    // 0051f6f5  0f68eb                 -punpckhbw mm5, mm3
    cpu.mmx.mm5 = { _mm_unpacklo_epi8(_mm_srli_epi64(cpu.mmx.mm5, 32), _mm_srli_epi64(cpu.mmx.mm3, 32)) };
    // 0051f6f8  0fe5cc                 -pmulhw mm1, mm4
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 0051f6fb  0fe5d5                 -pmulhw mm2, mm5
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 0051f6fe  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 0051f702  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 0051f706  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 0051f70a  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 0051f70e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f711  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051f714  83e904                 +sub ecx, 4
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
    // 0051f717  7fd0                   -jg 0x51f6e9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051f6e9;
    }
    // 0051f719  83f900                 +cmp ecx, 0
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
    // 0051f71c  7503                   -jne 0x51f721
    if (!cpu.flags.zf)
    {
        goto L_0x0051f721;
    }
    // 0051f71e  61                     -popal 
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
    // 0051f71f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f720  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f721:
    // 0051f721  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f724  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0051f726:
    // 0051f726  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0051f729  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f72c  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 0051f72e  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0051f731  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0051f734  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 0051f738  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 0051f73b  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 0051f73f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051f742  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f745  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f748  7cdc                   -jl 0x51f726
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f726;
    }
    // 0051f74a  61                     -popal 
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
    // 0051f74b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f74c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_51f750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f750  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f751  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f753  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f754  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f755  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f758  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f75b  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0051f75e  c700adf75100           -mov dword ptr [eax], 0x51f7ad
    app->getMemory<x86::reg32>(cpu.eax) = 5371821 /*0x51f7ad*/;
    // 0051f764  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f767  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0051f76a  c70074f75100           -mov dword ptr [eax], 0x51f774
    app->getMemory<x86::reg32>(cpu.eax) = 5371764 /*0x51f774*/;
    // 0051f770  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f771  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f772  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f773  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f774(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f774  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f775  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f777  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f778  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f779  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f77a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f77d  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f780  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f783  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f786  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f789  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f78d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051f78f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051f792  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f795  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f798  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f79b  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f79e  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f7a2  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051f7a5  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051f7a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f7a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f7aa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f7ab  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f7ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f7ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f7ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f7ae  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f7b0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0051f7b1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f7b4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f7b7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f7ba  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 0051f7bd  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0051f7c1  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051f7c4  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051f7c6  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051f7c9  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f7cc  7405                   -je 0x51f7d3
    if (cpu.flags.zf)
    {
        goto L_0x0051f7d3;
    }
    // 0051f7ce  83e904                 +sub ecx, 4
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
    // 0051f7d1  7c39                   -jl 0x51f80c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f80c;
    }
L_0x0051f7d3:
    // 0051f7d3  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f7d6  0f7fcc                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 0051f7d9  0f6f37                 -movq mm6, qword ptr [edi]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 0051f7dc  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 0051f7df  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 0051f7e2  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 0051f7e5  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 0051f7e8  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 0051f7eb  0fed13                 -paddsw mm2, qword ptr [ebx]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx))) };
    // 0051f7ee  0fed5b08               -paddsw mm3, qword ptr [ebx + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */))) };
    // 0051f7f2  0f7f13                 -movq qword ptr [ebx], mm2
    app->getMemory<x86::reg64>(cpu.ebx) = cpu.mmx.mm2;
    // 0051f7f5  0f7f5b08               -movq qword ptr [ebx + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 0051f7f9  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f7fc  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051f7ff  83e904                 +sub ecx, 4
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
    // 0051f802  7fcf                   -jg 0x51f7d3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051f7d3;
    }
    // 0051f804  83f900                 +cmp ecx, 0
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
    // 0051f807  7503                   -jne 0x51f80c
    if (!cpu.flags.zf)
    {
        goto L_0x0051f80c;
    }
    // 0051f809  61                     -popal 
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
    // 0051f80a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f80b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f80c:
    // 0051f80c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f80f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0051f811:
    // 0051f811  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f814  0f7fcc                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 0051f817  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0051f81a  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0051f81d  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 0051f820  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 0051f823  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 0051f826  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 0051f829  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 0051f82c  0f6e1b                 -movd mm3, dword ptr [ebx]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebx)) };
    // 0051f82f  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 0051f832  0f7e1b                 -movd dword ptr [ebx], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx), cpu.mmx.mm3);
    // 0051f835  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0051f838  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f83b  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f83e  7cd1                   -jl 0x51f811
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f811;
    }
    // 0051f840  61                     -popal 
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
    // 0051f841  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51f850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f850  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f851  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f853  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f854  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f855  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f858  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f85b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051f85e  c70097f85100           -mov dword ptr [eax], 0x51f897
    app->getMemory<x86::reg32>(cpu.eax) = 5372055 /*0x51f897*/;
    // 0051f864  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f867  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0051f86a  c70074f85100           -mov dword ptr [eax], 0x51f874
    app->getMemory<x86::reg32>(cpu.eax) = 5372020 /*0x51f874*/;
    // 0051f870  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f871  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f872  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f873  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f874  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f875  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f877  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051f878  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f879  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f87a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f87d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f880  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0051f883  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f886  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 0051f889  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 0051f88d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0051f88f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051f892  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f894  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f895  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f897(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f897  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f898  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0051f89a  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0051f89b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051f89e  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051f8a1  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0051f8a4  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 0051f8a7  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0051f8aa  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051f8ac  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0051f8af  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051f8b2  7405                   -je 0x51f8b9
    if (cpu.flags.zf)
    {
        goto L_0x0051f8b9;
    }
    // 0051f8b4  83e908                 +sub ecx, 8
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
    // 0051f8b7  7c4e                   -jl 0x51f907
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f907;
    }
L_0x0051f8b9:
    // 0051f8b9  0f7fc1                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 0051f8bc  0f7fc2                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 0051f8bf  0f7fc3                 -movq mm3, mm0
    cpu.mmx.mm3 = cpu.mmx.mm0;
    // 0051f8c2  0f7fc4                 -movq mm4, mm0
    cpu.mmx.mm4 = cpu.mmx.mm0;
    // 0051f8c5  0fe50f                 -pmulhw mm1, qword ptr [edi]
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi))) };
    // 0051f8c8  0fe55708               -pmulhw mm2, qword ptr [edi + 8]
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */))) };
    // 0051f8cc  0fe55f10               -pmulhw mm3, qword ptr [edi + 0x10]
    cpu.mmx.mm3 = { _mm_mulhi_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */))) };
    // 0051f8d0  0fe56718               -pmulhw mm4, qword ptr [edi + 0x18]
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */))) };
    // 0051f8d4  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 0051f8d8  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 0051f8dc  0fed5d10               -paddsw mm3, qword ptr [ebp + 0x10]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */))) };
    // 0051f8e0  0fed6518               -paddsw mm4, qword ptr [ebp + 0x18]
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */))) };
    // 0051f8e4  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 0051f8e8  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 0051f8ec  0f7f5d10               -movq qword ptr [ebp + 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm3;
    // 0051f8f0  0f7f6518               -movq qword ptr [ebp + 0x18], mm4
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm4;
    // 0051f8f4  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051f8f7  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0051f8fa  83e908                 +sub ecx, 8
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
    // 0051f8fd  7fba                   -jg 0x51f8b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051f8b9;
    }
    // 0051f8ff  83f900                 +cmp ecx, 0
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
    // 0051f902  7503                   -jne 0x51f907
    if (!cpu.flags.zf)
    {
        goto L_0x0051f907;
    }
    // 0051f904  61                     -popal 
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
    // 0051f905  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f906  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051f907:
    // 0051f907  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051f90a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051f90c  0f7fc1                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
L_0x0051f90f:
    // 0051f90f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0051f911  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0051f914  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0051f917  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 0051f91b  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 0051f91e  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 0051f922  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f925  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f928  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0051f92b  7ce2                   -jl 0x51f90f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051f90f;
    }
    // 0051f92d  61                     -popal 
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
    // 0051f92e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f92f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_51f930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f931  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f932  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051f933  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051f937  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051f93b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051f93e  48                     -dec eax
    (cpu.eax)--;
    // 0051f93f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051f942  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0051f945  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051f948  8b5a0d                 -mov ebx, dword ptr [edx + 0xd]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0051f94b  40                     -inc eax
    (cpu.eax)++;
    // 0051f94c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0051f94f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051f951  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0051f953  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0051f956  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051f958  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051f95a  7501                   -jne 0x51f95d
    if (!cpu.flags.zf)
    {
        goto L_0x0051f95d;
    }
    // 0051f95c  40                     -inc eax
    (cpu.eax)++;
L_0x0051f95d:
    // 0051f95d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051f961  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0051f964  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0051f967  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0051f96a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051f96d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0051f96f  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0051f972  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f973  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f974  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f975  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51f978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f978  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f97c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51f980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f981  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051f985  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051f989  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051f98c  48                     -dec eax
    (cpu.eax)--;
    // 0051f98d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051f990  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0051f993  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051f995  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051f998  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0051f99b  40                     -inc eax
    (cpu.eax)++;
    // 0051f99c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051f99e  7501                   -jne 0x51f9a1
    if (!cpu.flags.zf)
    {
        goto L_0x0051f9a1;
    }
    // 0051f9a0  40                     -inc eax
    (cpu.eax)++;
L_0x0051f9a1:
    // 0051f9a1  8b510b                 -mov edx, dword ptr [ecx + 0xb]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(11) /* 0xb */);
    // 0051f9a4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0051f9a7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051f9a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051f9aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51f9ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051f9ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051f9ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051f9ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051f9af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051f9b0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051f9b3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051f9b7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051f9bb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051f9bf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051f9c1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0051f9c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051f9c6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051f9c8  7572                   -jne 0x51fa3c
    if (!cpu.flags.zf)
    {
        goto L_0x0051fa3c;
    }
L_0x0051f9ca:
    // 0051f9ca  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051f9ce  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0051f9d1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051f9d2  7572                   -jne 0x51fa46
    if (!cpu.flags.zf)
    {
        goto L_0x0051fa46;
    }
L_0x0051f9d4:
    // 0051f9d4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051f9d6  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 0051f9db  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051f9de  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 0051f9e2  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051f9e4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0051f9e7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051f9ea  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051f9ec  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 0051f9f1  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051f9f4  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0051f9f7  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051f9fa  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051f9fd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051f9ff  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051fa02  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 0051fa05  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fa07  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0051fa0b  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0051fa0e  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fa11  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 0051fa14  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fa16  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051fa18  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0051fa1b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fa1e  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0051fa24  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051fa26  8b430d                 -mov eax, dword ptr [ebx + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 0051fa29  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0051fa2b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0051fa2e  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 0051fa32  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0051fa34  83c404                 +add esp, 4
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
    // 0051fa37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fa38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fa39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fa3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fa3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051fa3c:
    // 0051fa3c  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051fa3f  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0051fa42  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0051fa44  eb84                   -jmp 0x51f9ca
    goto L_0x0051f9ca;
L_0x0051fa46:
    // 0051fa46  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fa49  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fa4c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fa4f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0051fa52  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0051fa55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051fa56  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051fa59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051fa5a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051fa5e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fa62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051fa63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fa64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fa65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fa66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fa67  e884760000             -call 0x5270f0
    cpu.esp -= 4;
    sub_5270f0(app, cpu);
    if (cpu.terminate) return;
    // 0051fa6c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051fa6f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051fa72  c1e810                 +shr eax, 0x10
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
    // 0051fa75  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051fa78  e957ffffff             -jmp 0x51f9d4
    goto L_0x0051f9d4;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51fa80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fa80  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051fa84  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051fa88  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051fa8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51fa8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fa8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fa8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fa8e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fa8f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fa90  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051fa93  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051fa97  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051fa9b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051fa9f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051faa1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0051faa4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051faa6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051faa8  0f85c7000000           -jne 0x51fb75
    if (!cpu.flags.zf)
    {
        goto L_0x0051fb75;
    }
L_0x0051faae:
    // 0051faae  807b0e00               +cmp byte ptr [ebx + 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051fab2  7406                   -je 0x51faba
    if (cpu.flags.zf)
    {
        goto L_0x0051faba;
    }
    // 0051fab4  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fab5  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0051fab8  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x0051faba:
    // 0051faba  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051fabe  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0051fac4  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0051fac7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fac8  7432                   -je 0x51fafc
    if (cpu.flags.zf)
    {
        goto L_0x0051fafc;
    }
    // 0051faca  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051facd  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fad0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fad3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0051fad6  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0051fad9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051fada  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051fadd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051fade  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051fae2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fae6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051fae7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fae8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fae9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051faea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051faeb  e800760000             -call 0x5270f0
    cpu.esp -= 4;
    sub_5270f0(app, cpu);
    if (cpu.terminate) return;
    // 0051faf0  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051faf3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051faf6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051faf9  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0051fafc:
    // 0051fafc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fafe  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 0051fb02  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fb05  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051fb07  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0051fb0c  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fb0f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051fb11  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051fb14  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fb16  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 0051fb1b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fb1e  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0051fb21  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fb24  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051fb27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051fb29  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051fb2c  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 0051fb2f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fb31  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 0051fb35  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0051fb38  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fb3b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fb3e  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fb40  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051fb42  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fb45  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0051fb47  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0051fb4a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fb4d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0051fb53  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051fb55  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fb58  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 0051fb5a  39d0                   +cmp eax, edx
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
    // 0051fb5c  7224                   -jb 0x51fb82
    if (cpu.flags.cf)
    {
        goto L_0x0051fb82;
    }
    // 0051fb5e  0333                   -add esi, dword ptr [ebx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
    // 0051fb60  c6430e01               -mov byte ptr [ebx + 0xe], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
    // 0051fb64  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0051fb66  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0051fb69  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 0051fb6d  83c404                 +add esp, 4
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
    // 0051fb70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051fb75:
    // 0051fb75  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051fb78  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0051fb7b  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0051fb7d  e92cffffff             -jmp 0x51faae
    goto L_0x0051faae;
L_0x0051fb82:
    // 0051fb82  c6430e00               -mov byte ptr [ebx + 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0051fb86  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 0051fb8a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051fb8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fb91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51fb94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fb94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fb95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fb96  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051fb9a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051fb9e  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0051fba1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051fba3  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051fba9  732c                   -jae 0x51fbd7
    if (!cpu.flags.cf)
    {
        goto L_0x0051fbd7;
    }
    // 0051fbab  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051fbb1  7324                   -jae 0x51fbd7
    if (!cpu.flags.cf)
    {
        goto L_0x0051fbd7;
    }
L_0x0051fbb3:
    // 0051fbb3  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051fbb6  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051fbbc  724b                   -jb 0x51fc09
    if (cpu.flags.cf)
    {
        goto L_0x0051fc09;
    }
    // 0051fbbe  7660                   -jbe 0x51fc20
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051fc20;
    }
    // 0051fbc0  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0051fbc3  c70230f95100           -mov dword ptr [edx], 0x51f930
    app->getMemory<x86::reg32>(cpu.edx) = 5372208 /*0x51f930*/;
    // 0051fbc9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0051fbcc  c700acf95100           -mov dword ptr [eax], 0x51f9ac
    app->getMemory<x86::reg32>(cpu.eax) = 5372332 /*0x51f9ac*/;
    // 0051fbd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051fbd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fbd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fbd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051fbd7:
    // 0051fbd7  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051fbda  39f2                   +cmp edx, esi
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
    // 0051fbdc  74d5                   -je 0x51fbb3
    if (cpu.flags.zf)
    {
        goto L_0x0051fbb3;
    }
    // 0051fbde  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051fbe4  7608                   -jbe 0x51fbee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051fbee;
    }
    // 0051fbe6  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051fbec  77c5                   -ja 0x51fbb3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051fbb3;
    }
L_0x0051fbee:
    // 0051fbee  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0051fbf2  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 0051fbf6  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0051fbfa  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051fc01  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0051fc07  ebaa                   -jmp 0x51fbb3
    goto L_0x0051fbb3;
L_0x0051fc09:
    // 0051fc09  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0051fc0c  c70280f95100           -mov dword ptr [edx], 0x51f980
    app->getMemory<x86::reg32>(cpu.edx) = 5372288 /*0x51f980*/;
    // 0051fc12  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0051fc15  c7008cfa5100           -mov dword ptr [eax], 0x51fa8c
    app->getMemory<x86::reg32>(cpu.eax) = 5372556 /*0x51fa8c*/;
    // 0051fc1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051fc1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fc1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fc1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051fc20:
    // 0051fc20  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0051fc23  c70278f95100           -mov dword ptr [edx], 0x51f978
    app->getMemory<x86::reg32>(cpu.edx) = 5372280 /*0x51f978*/;
    // 0051fc29  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0051fc2c  c70080fa5100           -mov dword ptr [eax], 0x51fa80
    app->getMemory<x86::reg32>(cpu.eax) = 5372544 /*0x51fa80*/;
    // 0051fc32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051fc34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fc35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fc36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51fc38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fc38  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051fc3c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0051fc42  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051fc49  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0051fc4d  c6400d00               -mov byte ptr [eax + 0xd], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 0051fc51  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 0051fc55  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fc59  c6401001               -mov byte ptr [eax + 0x10], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0051fc5d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0051fc60  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051fc64  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0051fc67  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051fc6b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0051fc6e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0051fc71  c70094fb5100           -mov dword ptr [eax], 0x51fb94
    app->getMemory<x86::reg32>(cpu.eax) = 5372820 /*0x51fb94*/;
    // 0051fc77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051fc79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_51fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fc80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fc82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fc83  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051fc87  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051fc8b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051fc8e  48                     -dec eax
    (cpu.eax)--;
    // 0051fc8f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051fc92  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0051fc95  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fc98  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0051fc9b  40                     -inc eax
    (cpu.eax)++;
    // 0051fc9c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0051fc9f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0051fca1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0051fca3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0051fca6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051fca8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051fcaa  7501                   -jne 0x51fcad
    if (!cpu.flags.zf)
    {
        goto L_0x0051fcad;
    }
    // 0051fcac  40                     -inc eax
    (cpu.eax)++;
L_0x0051fcad:
    // 0051fcad  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0051fcb1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0051fcb4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0051fcb7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0051fcba  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051fcbd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0051fcbf  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 0051fcc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fcc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fcc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fcc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51fcc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fcc8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fccc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51fcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fcd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fcd1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fcd5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051fcd9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0051fcdc  48                     -dec eax
    (cpu.eax)--;
    // 0051fcdd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0051fce0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0051fce3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051fce5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fce8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0051fceb  40                     -inc eax
    (cpu.eax)++;
    // 0051fcec  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051fcee  7501                   -jne 0x51fcf1
    if (!cpu.flags.zf)
    {
        goto L_0x0051fcf1;
    }
    // 0051fcf0  40                     -inc eax
    (cpu.eax)++;
L_0x0051fcf1:
    // 0051fcf1  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0051fcf4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0051fcf7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051fcf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fcfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51fcfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fcfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fcfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fcfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fcff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fd00  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051fd03  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051fd07  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051fd0b  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051fd0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051fd11  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 0051fd14  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051fd16  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051fd18  0f85b9000000           -jne 0x51fdd7
    if (!cpu.flags.zf)
    {
        goto L_0x0051fdd7;
    }
L_0x0051fd1e:
    // 0051fd1e  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0051fd22  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0051fd25  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fd26  0f85be000000           -jne 0x51fdea
    if (!cpu.flags.zf)
    {
        goto L_0x0051fdea;
    }
L_0x0051fd2c:
    // 0051fd2c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fd2e  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 0051fd32  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0051fd35  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fd38  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051fd3c  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0051fd41  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051fd43  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0051fd48  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 0051fd4d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fd50  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0051fd54  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fd57  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051fd5a  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051fd5c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051fd5e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051fd60  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051fd63  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 0051fd66  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fd68  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0051fd6d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fd70  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 0051fd75  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051fd77  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fd7a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051fd7d  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 0051fd80  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0051fd83  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fd86  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0051fd89  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fd8c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051fd8f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051fd91  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051fd94  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051fd97  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fd99  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 0051fd9d  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0051fda0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fda2  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 0051fda6  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0051fda9  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fdac  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 0051fdaf  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fdb1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051fdb3  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051fdb6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fdb9  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0051fdbf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051fdc1  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 0051fdc4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0051fdc6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0051fdc9  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 0051fdcd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0051fdcf  83c408                 +add esp, 8
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
    // 0051fdd2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fdd3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fdd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fdd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051fdd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051fdd7:
    // 0051fdd7  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051fdda  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0051fddd  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0051fddf  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fde0  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0051fde3  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0051fde5  e934ffffff             -jmp 0x51fd1e
    goto L_0x0051fd1e;
L_0x0051fdea:
    // 0051fdea  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fded  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fdf0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fdf3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0051fdf6  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0051fdf9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051fdfa  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051fdfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051fdfe  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051fe02  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fe06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051fe07  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fe08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fe09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fe0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fe0b  e860730000             -call 0x527170
    cpu.esp -= 4;
    sub_527170(app, cpu);
    if (cpu.terminate) return;
    // 0051fe10  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051fe13  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051fe16  c1e810                 +shr eax, 0x10
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
    // 0051fe19  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051fe1c  e90bffffff             -jmp 0x51fd2c
    goto L_0x0051fd2c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51fe24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fe24  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051fe28  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051fe2c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0051fe2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_51fe30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051fe30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fe31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fe32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fe33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fe34  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051fe37  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0051fe3b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051fe3f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0051fe43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0051fe45  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 0051fe48  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051fe4a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0051fe4c  0f8510010000           -jne 0x51ff62
    if (!cpu.flags.zf)
    {
        goto L_0x0051ff62;
    }
L_0x0051fe52:
    // 0051fe52  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051fe56  740c                   -je 0x51fe64
    if (cpu.flags.zf)
    {
        goto L_0x0051fe64;
    }
    // 0051fe58  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fe59  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 0051fe5c  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0051fe5e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fe5f  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0051fe62  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x0051fe64:
    // 0051fe64  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0051fe68  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0051fe6e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0051fe71  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051fe72  7432                   -je 0x51fea6
    if (cpu.flags.zf)
    {
        goto L_0x0051fea6;
    }
    // 0051fe74  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fe77  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051fe7a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fe7d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0051fe80  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0051fe83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051fe84  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051fe87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051fe88  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051fe8c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051fe90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051fe91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051fe92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051fe93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051fe94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051fe95  e8d6720000             -call 0x527170
    cpu.esp -= 4;
    sub_527170(app, cpu);
    if (cpu.terminate) return;
    // 0051fe9a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0051fe9d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0051fea0  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fea3  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0051fea6:
    // 0051fea6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051fea8  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 0051fead  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 0051feb1  2b4b04                 -sub ecx, dword ptr [ebx + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0051feb4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0051feb7  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0051feba  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 0051febf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fec2  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0051fec6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fec9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051fecc  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051fece  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051fed0  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0051fed2  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051fed5  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 0051fed8  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051feda  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0051fedf  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051fee2  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 0051fee7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051fee9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051feec  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0051feef  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 0051fef2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0051fef5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0051fef8  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0051fefb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051fefe  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0051ff01  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051ff03  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0051ff06  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0051ff09  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ff0b  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 0051ff0f  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0051ff12  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ff14  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 0051ff18  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0051ff1b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051ff1e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051ff21  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ff23  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051ff25  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0051ff28  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0051ff2a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0051ff2d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051ff30  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0051ff36  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051ff38  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0051ff3b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0051ff3d  39c8                   +cmp eax, ecx
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
    // 0051ff3f  7234                   -jb 0x51ff75
    if (cpu.flags.cf)
    {
        goto L_0x0051ff75;
    }
    // 0051ff41  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ff43  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0051ff47  8a0446                 -mov al, byte ptr [esi + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 2);
    // 0051ff4a  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0051ff4d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051ff4f  8a444601               -mov al, byte ptr [esi + eax*2 + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 2);
    // 0051ff53  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0051ff56  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 0051ff5a  83c404                 +add esp, 4
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
    // 0051ff5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ff62:
    // 0051ff62  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0051ff65  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0051ff68  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0051ff6a  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0051ff6b  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0051ff6e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0051ff70  e9ddfeffff             -jmp 0x51fe52
    goto L_0x0051fe52;
L_0x0051ff75:
    // 0051ff75  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0051ff79  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 0051ff7d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0051ff80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ff84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51ff88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051ff88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051ff89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051ff8a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051ff8e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051ff92  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0051ff95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051ff97  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ff9d  732c                   -jae 0x51ffcb
    if (!cpu.flags.cf)
    {
        goto L_0x0051ffcb;
    }
    // 0051ff9f  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ffa5  7324                   -jae 0x51ffcb
    if (!cpu.flags.cf)
    {
        goto L_0x0051ffcb;
    }
L_0x0051ffa7:
    // 0051ffa7  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051ffaa  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ffb0  724b                   -jb 0x51fffd
    if (cpu.flags.cf)
    {
        goto L_0x0051fffd;
    }
    // 0051ffb2  7660                   -jbe 0x520014
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00520014;
    }
    // 0051ffb4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0051ffb7  c70280fc5100           -mov dword ptr [edx], 0x51fc80
    app->getMemory<x86::reg32>(cpu.edx) = 5373056 /*0x51fc80*/;
    // 0051ffbd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0051ffc0  c700fcfc5100           -mov dword ptr [eax], 0x51fcfc
    app->getMemory<x86::reg32>(cpu.eax) = 5373180 /*0x51fcfc*/;
    // 0051ffc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051ffc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ffc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051ffca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051ffcb:
    // 0051ffcb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051ffce  39f2                   +cmp edx, esi
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
    // 0051ffd0  74d5                   -je 0x51ffa7
    if (cpu.flags.zf)
    {
        goto L_0x0051ffa7;
    }
    // 0051ffd2  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ffd8  7608                   -jbe 0x51ffe2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0051ffe2;
    }
    // 0051ffda  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051ffe0  77c5                   -ja 0x51ffa7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0051ffa7;
    }
L_0x0051ffe2:
    // 0051ffe2  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0051ffe6  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 0051ffea  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0051ffee  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051fff5  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0051fffb  ebaa                   -jmp 0x51ffa7
    goto L_0x0051ffa7;
L_0x0051fffd:
    // 0051fffd  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00520000  c702d0fc5100           -mov dword ptr [edx], 0x51fcd0
    app->getMemory<x86::reg32>(cpu.edx) = 5373136 /*0x51fcd0*/;
    // 00520006  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00520009  c70030fe5100           -mov dword ptr [eax], 0x51fe30
    app->getMemory<x86::reg32>(cpu.eax) = 5373488 /*0x51fe30*/;
    // 0052000f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520012  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520013  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00520014:
    // 00520014  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00520017  c702c8fc5100           -mov dword ptr [edx], 0x51fcc8
    app->getMemory<x86::reg32>(cpu.edx) = 5373128 /*0x51fcc8*/;
    // 0052001d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00520020  c70024fe5100           -mov dword ptr [eax], 0x51fe24
    app->getMemory<x86::reg32>(cpu.eax) = 5373476 /*0x51fe24*/;
    // 00520026  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520029  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052002a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52002c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052002c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00520030  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00520036  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052003d  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00520041  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 00520045  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520049  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0052004d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00520050  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00520054  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00520057  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052005b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0052005e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00520061  c70088ff5100           -mov dword ptr [eax], 0x51ff88
    app->getMemory<x86::reg32>(cpu.eax) = 5373832 /*0x51ff88*/;
    // 00520067  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520071  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520072  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00520073  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00520077  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052007b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0052007e  48                     -dec eax
    (cpu.eax)--;
    // 0052007f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00520082  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00520085  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520088  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0052008b  40                     -inc eax
    (cpu.eax)++;
    // 0052008c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0052008f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00520091  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00520093  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00520096  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00520098  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0052009a  7501                   -jne 0x52009d
    if (!cpu.flags.zf)
    {
        goto L_0x0052009d;
    }
    // 0052009c  40                     -inc eax
    (cpu.eax)++;
L_0x0052009d:
    // 0052009d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005200a1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 005200a4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005200a7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 005200aa  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 005200ad  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 005200af  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 005200b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005200b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005200b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005200b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5200b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005200b8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005200bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5200c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005200c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005200c1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005200c5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005200c9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005200cc  48                     -dec eax
    (cpu.eax)--;
    // 005200cd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 005200d0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005200d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005200d5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005200d8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005200db  40                     -inc eax
    (cpu.eax)++;
    // 005200dc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 005200de  7501                   -jne 0x5200e1
    if (!cpu.flags.zf)
    {
        goto L_0x005200e1;
    }
    // 005200e0  40                     -inc eax
    (cpu.eax)++;
L_0x005200e1:
    // 005200e1  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 005200e4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 005200e7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005200e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005200ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5200ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005200ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005200ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005200ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005200ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005200f0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005200f3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005200f7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005200fb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 005200ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00520101  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 00520104  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00520106  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00520108  0f8581000000           -jne 0x52018f
    if (!cpu.flags.zf)
    {
        goto L_0x0052018f;
    }
L_0x0052010e:
    // 0052010e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00520112  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00520115  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00520116  0f8582000000           -jne 0x52019e
    if (!cpu.flags.zf)
    {
        goto L_0x0052019e;
    }
L_0x0052011c:
    // 0052011c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052011e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 00520123  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520126  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 0052012a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052012c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052012f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520132  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00520134  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00520137  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 0052013b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052013d  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 00520140  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520143  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00520146  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00520149  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0052014c  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 00520150  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00520152  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 00520156  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520158  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 0052015d  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00520161  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520164  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 00520167  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520169  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052016b  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0052016e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520171  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00520177  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00520179  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 0052017c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0052017e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00520181  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 00520185  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00520187  83c404                 +add esp, 4
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
    // 0052018a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052018b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052018c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052018d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052018e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052018f:
    // 0052018f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00520192  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00520196  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 00520199  e970ffffff             -jmp 0x52010e
    goto L_0x0052010e;
L_0x0052019e:
    // 0052019e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005201a1  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005201a4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005201a7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005201aa  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 005201ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005201ae  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005201b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005201b2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005201b6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005201ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005201bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005201bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005201bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005201be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005201bf  e84c700000             -call 0x527210
    cpu.esp -= 4;
    sub_527210(app, cpu);
    if (cpu.terminate) return;
    // 005201c4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005201c7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005201ca  c1e810                 +shr eax, 0x10
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
    // 005201cd  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005201d0  e947ffffff             -jmp 0x52011c
    goto L_0x0052011c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5201d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005201d8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005201dc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005201e0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005201e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5201e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005201e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005201e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005201e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005201e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005201e8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005201eb  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005201ef  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005201f3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 005201f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005201f9  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 005201fc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005201fe  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00520200  0f85d5000000           -jne 0x5202db
    if (!cpu.flags.zf)
    {
        goto L_0x005202db;
    }
L_0x00520206:
    // 00520206  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052020a  740a                   -je 0x520216
    if (cpu.flags.zf)
    {
        goto L_0x00520216;
    }
    // 0052020c  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052020f  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00520213  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00520216:
    // 00520216  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0052021a  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00520220  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00520223  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00520224  7432                   -je 0x520258
    if (cpu.flags.zf)
    {
        goto L_0x00520258;
    }
    // 00520226  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00520229  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052022c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052022f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00520232  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00520235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00520236  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00520239  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052023a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052023e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520242  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520243  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520244  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520245  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520246  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00520247  e8c46f0000             -call 0x527210
    cpu.esp -= 4;
    sub_527210(app, cpu);
    if (cpu.terminate) return;
    // 0052024c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052024f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00520252  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520255  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00520258:
    // 00520258  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052025a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052025d  0fbf1446               -movsx edx, word ptr [esi + eax*2]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 00520261  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00520266  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00520268  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052026b  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0052026e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520271  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 00520275  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520277  8b0446                 -mov eax, dword ptr [esi + eax*2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 0052027a  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052027d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00520280  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00520283  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 00520286  0fbf042a               -movsx eax, word ptr [edx + ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1)));
    // 0052028a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052028c  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 00520290  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520292  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 00520297  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0052029b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052029e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005202a1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005202a3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 005202a5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005202a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005202aa  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 005202ad  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005202b0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 005202b6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005202b8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005202bb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 005202bd  39c8                   +cmp eax, ecx
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
    // 005202bf  7229                   -jb 0x5202ea
    if (cpu.flags.cf)
    {
        goto L_0x005202ea;
    }
    // 005202c1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005202c3  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 005202c7  668b0446               -mov ax, word ptr [esi + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2);
    // 005202cb  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 005202cf  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 005202d3  83c404                 +add esp, 4
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
    // 005202d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005202db:
    // 005202db  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 005202de  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 005202e2  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 005202e5  e91cffffff             -jmp 0x520206
    goto L_0x00520206;
L_0x005202ea:
    // 005202ea  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 005202ee  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 005202f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005202f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005202f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5202fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005202fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005202fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005202fe  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00520302  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00520306  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00520309  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052030b  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520311  732c                   -jae 0x52033f
    if (!cpu.flags.cf)
    {
        goto L_0x0052033f;
    }
    // 00520313  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520319  7324                   -jae 0x52033f
    if (!cpu.flags.cf)
    {
        goto L_0x0052033f;
    }
L_0x0052031b:
    // 0052031b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052031e  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520324  724b                   -jb 0x520371
    if (cpu.flags.cf)
    {
        goto L_0x00520371;
    }
    // 00520326  7660                   -jbe 0x520388
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00520388;
    }
    // 00520328  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052032b  c70270005200           -mov dword ptr [edx], 0x520070
    app->getMemory<x86::reg32>(cpu.edx) = 5374064 /*0x520070*/;
    // 00520331  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00520334  c700ec005200           -mov dword ptr [eax], 0x5200ec
    app->getMemory<x86::reg32>(cpu.eax) = 5374188 /*0x5200ec*/;
    // 0052033a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052033c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052033d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052033e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052033f:
    // 0052033f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00520342  39f2                   +cmp edx, esi
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
    // 00520344  74d5                   -je 0x52031b
    if (cpu.flags.zf)
    {
        goto L_0x0052031b;
    }
    // 00520346  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052034c  7608                   -jbe 0x520356
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00520356;
    }
    // 0052034e  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520354  77c5                   -ja 0x52031b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052031b;
    }
L_0x00520356:
    // 00520356  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0052035a  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 0052035e  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 00520362  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00520369  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052036f  ebaa                   -jmp 0x52031b
    goto L_0x0052031b;
L_0x00520371:
    // 00520371  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00520374  c702c0005200           -mov dword ptr [edx], 0x5200c0
    app->getMemory<x86::reg32>(cpu.edx) = 5374144 /*0x5200c0*/;
    // 0052037a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0052037d  c700e4015200           -mov dword ptr [eax], 0x5201e4
    app->getMemory<x86::reg32>(cpu.eax) = 5374436 /*0x5201e4*/;
    // 00520383  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520385  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520386  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520387  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00520388:
    // 00520388  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052038b  c702b8005200           -mov dword ptr [edx], 0x5200b8
    app->getMemory<x86::reg32>(cpu.edx) = 5374136 /*0x5200b8*/;
    // 00520391  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00520394  c700d8015200           -mov dword ptr [eax], 0x5201d8
    app->getMemory<x86::reg32>(cpu.eax) = 5374424 /*0x5201d8*/;
    // 0052039a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052039c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052039d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052039e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5203a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005203a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005203a4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005203aa  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005203b1  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 005203b5  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 005203bb  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 005203bf  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005203c3  c6401201               -mov byte ptr [eax + 0x12], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 1 /*0x1*/;
    // 005203c7  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005203ca  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005203ce  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005203d1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005203d5  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005203d8  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005203db  c700fc025200           -mov dword ptr [eax], 0x5202fc
    app->getMemory<x86::reg32>(cpu.eax) = 5374716 /*0x5202fc*/;
    // 005203e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005203e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5203f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005203f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005203f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005203f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005203f3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005203f7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005203fb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 005203fe  48                     -dec eax
    (cpu.eax)--;
    // 005203ff  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00520402  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00520405  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520408  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0052040b  40                     -inc eax
    (cpu.eax)++;
    // 0052040c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0052040f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00520411  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00520413  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 00520416  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00520418  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0052041a  7501                   -jne 0x52041d
    if (!cpu.flags.zf)
    {
        goto L_0x0052041d;
    }
    // 0052041c  40                     -inc eax
    (cpu.eax)++;
L_0x0052041d:
    // 0052041d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00520421  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00520424  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00520427  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0052042a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0052042d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052042f  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 00520432  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520433  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520434  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_520438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520438  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052043c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_520440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520441  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520445  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00520449  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0052044c  48                     -dec eax
    (cpu.eax)--;
    // 0052044d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00520450  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00520453  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00520455  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520458  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 0052045b  40                     -inc eax
    (cpu.eax)++;
    // 0052045c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0052045e  7501                   -jne 0x520461
    if (!cpu.flags.zf)
    {
        goto L_0x00520461;
    }
    // 00520460  40                     -inc eax
    (cpu.eax)++;
L_0x00520461:
    // 00520461  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 00520464  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00520467  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00520469  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052046a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52046c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052046c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052046d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052046e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052046f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520470  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520473  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00520477  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052047b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0052047f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00520481  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 00520484  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00520486  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00520488  0f85d1000000           -jne 0x52055f
    if (!cpu.flags.zf)
    {
        goto L_0x0052055f;
    }
L_0x0052048e:
    // 0052048e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00520492  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00520495  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00520496  0f85dc000000           -jne 0x520578
    if (!cpu.flags.zf)
    {
        goto L_0x00520578;
    }
L_0x0052049c:
    // 0052049c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052049e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 005204a3  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005204a6  0fbf0486               -movsx eax, word ptr [esi + eax*4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 005204aa  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005204ac  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005204af  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005204b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005204b4  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 005204bb  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 005204bf  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005204c1  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 005204c5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005204c7  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005204ca  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 005204cd  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005204d0  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 005204d4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 005204d7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005204d9  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 005204dd  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005204df  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 005204e4  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005204e7  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 005204ea  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005204ec  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005204ef  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005204f2  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 005204f5  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 005204fa  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005204fc  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 00520500  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00520502  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520505  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00520508  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052050b  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 0052050e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00520511  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 00520514  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00520516  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 0052051b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052051d  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 00520522  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00520526  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520528  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 0052052d  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 00520531  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520534  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 00520537  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520539  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052053b  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052053e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520541  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00520547  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00520549  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 0052054c  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0052054e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00520551  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 00520555  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00520557  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052055a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052055b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052055c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052055d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052055e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052055f:
    // 0052055f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00520562  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 00520566  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00520569  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052056c  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00520570  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 00520573  e916ffffff             -jmp 0x52048e
    goto L_0x0052048e;
L_0x00520578:
    // 00520578  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052057b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052057e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520581  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00520584  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00520587  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00520588  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0052058b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052058c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00520590  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520594  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520595  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520596  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520597  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520598  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00520599  e8f26c0000             -call 0x527290
    cpu.esp -= 4;
    sub_527290(app, cpu);
    if (cpu.terminate) return;
    // 0052059e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005205a1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005205a4  c1e810                 +shr eax, 0x10
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
    // 005205a7  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005205aa  e9edfeffff             -jmp 0x52049c
    goto L_0x0052049c;
}

/* align: skip 0x90 */
void Application::sub_5205b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005205b0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005205b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005205b8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005205ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5205bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005205bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005205bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005205be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005205bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005205c0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005205c3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005205c7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005205cb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 005205cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005205d1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 005205d4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005205d6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 005205d8  0f8538010000           -jne 0x520716
    if (!cpu.flags.zf)
    {
        goto L_0x00520716;
    }
L_0x005205de:
    // 005205de  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005205e2  7414                   -je 0x5205f8
    if (cpu.flags.zf)
    {
        goto L_0x005205f8;
    }
    // 005205e4  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005205e7  668b430e               -mov ax, word ptr [ebx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 005205eb  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 005205ee  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005205f1  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 005205f5  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x005205f8:
    // 005205f8  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005205fc  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00520602  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00520605  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00520606  7432                   -je 0x52063a
    if (cpu.flags.zf)
    {
        goto L_0x0052063a;
    }
    // 00520608  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052060b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052060e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520611  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00520614  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00520617  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00520618  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0052061b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052061c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00520620  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520624  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520625  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520626  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520627  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520628  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00520629  e8626c0000             -call 0x527290
    cpu.esp -= 4;
    sub_527290(app, cpu);
    if (cpu.terminate) return;
    // 0052062e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00520631  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00520634  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520637  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052063a:
    // 0052063a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052063c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052063f  0fbf1486               -movsx edx, word ptr [esi + eax*4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 00520643  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00520648  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052064a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052064d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00520650  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00520652  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00520659  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 0052065d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052065f  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 00520663  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00520666  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00520669  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0052066c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0052066f  0fbf3c28               -movsx edi, word ptr [eax + ebp]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 00520673  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00520675  66893c28               -mov word ptr [eax + ebp], di
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.di;
    // 00520679  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052067b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052067e  8b3c96                 -mov edi, dword ptr [esi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 00520681  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 00520686  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00520689  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052068b  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052068e  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 00520691  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 00520696  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520698  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 0052069c  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052069f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005206a2  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005206a5  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 005206a8  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 005206ab  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 005206ae  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 005206b0  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 005206b5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005206b7  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 005206bc  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 005206c0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005206c2  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 005206c7  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 005206cb  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005206ce  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005206d1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005206d3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 005206d5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 005206d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005206da  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 005206dd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005206e0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 005206e6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005206e8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005206eb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 005206ed  39c8                   +cmp eax, ecx
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
    // 005206ef  723e                   -jb 0x52072f
    if (cpu.flags.cf)
    {
        goto L_0x0052072f;
    }
    // 005206f1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005206f3  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 005206f7  668b0486               -mov ax, word ptr [esi + eax*4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4);
    // 005206fb  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 005206ff  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00520701  668b448602             -mov ax, word ptr [esi + eax*4 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 00520706  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0052070a  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 0052070e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520711  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520712  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520713  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520714  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520715  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00520716:
    // 00520716  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00520719  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0052071d  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00520720  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00520723  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00520727  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 0052072a  e9affeffff             -jmp 0x5205de
    goto L_0x005205de;
L_0x0052072f:
    // 0052072f  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00520733  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 00520737  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052073a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052073b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052073c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052073d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052073e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_520740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520742  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00520746  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052074a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0052074d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052074f  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520755  732c                   -jae 0x520783
    if (!cpu.flags.cf)
    {
        goto L_0x00520783;
    }
    // 00520757  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052075d  7324                   -jae 0x520783
    if (!cpu.flags.cf)
    {
        goto L_0x00520783;
    }
L_0x0052075f:
    // 0052075f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00520762  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520768  724b                   -jb 0x5207b5
    if (cpu.flags.cf)
    {
        goto L_0x005207b5;
    }
    // 0052076a  7660                   -jbe 0x5207cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005207cc;
    }
    // 0052076c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0052076f  c702f0035200           -mov dword ptr [edx], 0x5203f0
    app->getMemory<x86::reg32>(cpu.edx) = 5374960 /*0x5203f0*/;
    // 00520775  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00520778  c7006c045200           -mov dword ptr [eax], 0x52046c
    app->getMemory<x86::reg32>(cpu.eax) = 5375084 /*0x52046c*/;
    // 0052077e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520781  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00520783:
    // 00520783  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00520786  39f2                   +cmp edx, esi
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
    // 00520788  74d5                   -je 0x52075f
    if (cpu.flags.zf)
    {
        goto L_0x0052075f;
    }
    // 0052078a  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520790  7608                   -jbe 0x52079a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052079a;
    }
    // 00520792  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520798  77c5                   -ja 0x52075f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052075f;
    }
L_0x0052079a:
    // 0052079a  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0052079e  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 005207a2  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 005207a6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005207ad  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005207b3  ebaa                   -jmp 0x52075f
    goto L_0x0052075f;
L_0x005207b5:
    // 005207b5  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 005207b8  c70240045200           -mov dword ptr [edx], 0x520440
    app->getMemory<x86::reg32>(cpu.edx) = 5375040 /*0x520440*/;
    // 005207be  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005207c1  c700bc055200           -mov dword ptr [eax], 0x5205bc
    app->getMemory<x86::reg32>(cpu.eax) = 5375420 /*0x5205bc*/;
    // 005207c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005207c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005207ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005207cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005207cc:
    // 005207cc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 005207cf  c70238045200           -mov dword ptr [edx], 0x520438
    app->getMemory<x86::reg32>(cpu.edx) = 5375032 /*0x520438*/;
    // 005207d5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005207d8  c700b0055200           -mov dword ptr [eax], 0x5205b0
    app->getMemory<x86::reg32>(cpu.eax) = 5375408 /*0x5205b0*/;
    // 005207de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005207e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005207e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005207e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5207e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005207e4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005207e8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005207ee  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005207f5  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 005207f9  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 005207fd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00520801  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 00520805  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00520808  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052080c  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0052080f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00520813  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00520816  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00520819  c70040075200           -mov dword ptr [eax], 0x520740
    app->getMemory<x86::reg32>(cpu.eax) = 5375808 /*0x520740*/;
    // 0052081f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00520821  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520831  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520833  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520834  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520837  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052083a  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x0052083d:
    // 0052083d  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 00520842  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00520845  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 0052084a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0052084d  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 00520850  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 00520853  3500800000             -xor eax, 0x8000
    cpu.eax ^= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00520858  886439ff               -mov byte ptr [ecx + edi - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1) = cpu.ah;
    // 0052085c  83e901                 +sub ecx, 1
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
    // 0052085f  7fdc                   -jg 0x52083d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052083d;
    }
    // 00520861  61                     -popal 
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
    // 00520862  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520863  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520870  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520871  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520873  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520874  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520877  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052087a  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 0052087c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052087f  bb00ad5600             -mov ebx, 0x56ad00
    cpu.ebx = 5680384 /*0x56ad00*/;
L_0x00520884:
    // 00520884  0f6f444ef8             -movq mm0, qword ptr [esi + ecx*2 - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 2));
    // 00520889  0f6f4c4ef0             -movq mm1, qword ptr [esi + ecx*2 - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 2));
    // 0052088e  0f6f544ee8             -movq mm2, qword ptr [esi + ecx*2 - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 2));
    // 00520893  0f6f5c4ee0             -movq mm3, qword ptr [esi + ecx*2 - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-32) /* -0x20 */ + cpu.ecx * 2));
    // 00520898  0f6f644ed8             -movq mm4, qword ptr [esi + ecx*2 - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-40) /* -0x28 */ + cpu.ecx * 2));
    // 0052089d  0f6f6c4ed0             -movq mm5, qword ptr [esi + ecx*2 - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.ecx * 2));
    // 005208a2  0f6f744ec8             -movq mm6, qword ptr [esi + ecx*2 - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-56) /* -0x38 */ + cpu.ecx * 2));
    // 005208a7  0f6f7c4ec0             -movq mm7, qword ptr [esi + ecx*2 - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-64) /* -0x40 */ + cpu.ecx * 2));
    // 005208ac  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 005208af  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 005208b2  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 005208b5  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 005208b8  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 005208bb  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 005208be  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 005208c1  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 005208c4  0f71d008               -psrlw mm0, 8
    cpu.mmx.mm0 = { _mm_srli_epi16(cpu.mmx.mm0, 8 /*0x8*/) };
    // 005208c8  0f71d108               -psrlw mm1, 8
    cpu.mmx.mm1 = { _mm_srli_epi16(cpu.mmx.mm1, 8 /*0x8*/) };
    // 005208cc  0f71d208               -psrlw mm2, 8
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 8 /*0x8*/) };
    // 005208d0  0f71d308               -psrlw mm3, 8
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 8 /*0x8*/) };
    // 005208d4  0f71d408               -psrlw mm4, 8
    cpu.mmx.mm4 = { _mm_srli_epi16(cpu.mmx.mm4, 8 /*0x8*/) };
    // 005208d8  0f71d508               -psrlw mm5, 8
    cpu.mmx.mm5 = { _mm_srli_epi16(cpu.mmx.mm5, 8 /*0x8*/) };
    // 005208dc  0f71d608               -psrlw mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi16(cpu.mmx.mm6, 8 /*0x8*/) };
    // 005208e0  0f71d708               -psrlw mm7, 8
    cpu.mmx.mm7 = { _mm_srli_epi16(cpu.mmx.mm7, 8 /*0x8*/) };
    // 005208e4  0f67c8                 -packuswb mm1, mm0
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm1, cpu.mmx.mm0); cpu.mmx.mm1 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005208e7  0f67da                 -packuswb mm3, mm2
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm3, cpu.mmx.mm2); cpu.mmx.mm3 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005208ea  0f67ec                 -packuswb mm5, mm4
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm5, cpu.mmx.mm4); cpu.mmx.mm5 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005208ed  0f67fe                 -packuswb mm7, mm6
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm7, cpu.mmx.mm6); cpu.mmx.mm7 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005208f0  0f6f03                 -movq mm0, qword ptr [ebx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx));
    // 005208f3  0fefc8                 -pxor mm1, mm0
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 005208f6  0fefd8                 -pxor mm3, mm0
    cpu.mmx.mm3 = { _mm_xor_si128(cpu.mmx.mm3, cpu.mmx.mm0) };
    // 005208f9  0fefe8                 -pxor mm5, mm0
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm0) };
    // 005208fc  0feff8                 -pxor mm7, mm0
    cpu.mmx.mm7 = { _mm_xor_si128(cpu.mmx.mm7, cpu.mmx.mm0) };
    // 005208ff  0f7f4c39f8             -movq qword ptr [ecx + edi - 8], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 00520904  0f7f5c39f0             -movq qword ptr [ecx + edi - 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 00520909  0f7f6c39e8             -movq qword ptr [ecx + edi - 0x18], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 0052090e  0f7f7c39e0             -movq qword ptr [ecx + edi - 0x20], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 00520913  83e920                 +sub ecx, 0x20
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00520916  0f8f68ffffff           -jg 0x520884
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520884;
    }
    // 0052091c  61                     -popal 
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
    // 0052091d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052091e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_520920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520920  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520921  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520923  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520924  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520927  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052092a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052092d  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00520930:
    // 00520930  0f6f4431f8             -movq mm0, qword ptr [ecx + esi - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1));
    // 00520935  0f6f4c31f0             -movq mm1, qword ptr [ecx + esi - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.esi * 1));
    // 0052093a  0f6f5431e8             -movq mm2, qword ptr [ecx + esi - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.esi * 1));
    // 0052093f  0f6f5c31e0             -movq mm3, qword ptr [ecx + esi - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.esi * 1));
    // 00520944  0f6f6431d8             -movq mm4, qword ptr [ecx + esi - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.esi * 1));
    // 00520949  0f6f6c31d0             -movq mm5, qword ptr [ecx + esi - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.esi * 1));
    // 0052094e  0f6f7431c8             -movq mm6, qword ptr [ecx + esi - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.esi * 1));
    // 00520953  0f6f7c31c0             -movq mm7, qword ptr [ecx + esi - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.esi * 1));
    // 00520958  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 0052095b  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 0052095e  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 00520961  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 00520964  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 00520967  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 0052096a  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 0052096d  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 00520970  0f7f4439f8             -movq qword ptr [ecx + edi - 8], mm0
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm0;
    // 00520975  0f7f4c39f0             -movq qword ptr [ecx + edi - 0x10], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 0052097a  0f7f5439e8             -movq qword ptr [ecx + edi - 0x18], mm2
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm2;
    // 0052097f  0f7f5c39e0             -movq qword ptr [ecx + edi - 0x20], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 00520984  0f7f6439d8             -movq qword ptr [ecx + edi - 0x28], mm4
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.edi * 1) = cpu.mmx.mm4;
    // 00520989  0f7f6c39d0             -movq qword ptr [ecx + edi - 0x30], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 0052098e  0f7f7439c8             -movq qword ptr [ecx + edi - 0x38], mm6
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.edi * 1) = cpu.mmx.mm6;
    // 00520993  0f7f7c39c0             -movq qword ptr [ecx + edi - 0x40], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 00520998  83e940                 +sub ecx, 0x40
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052099b  7f93                   -jg 0x520930
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520930;
    }
    // 0052099d  61                     -popal 
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
    // 0052099e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052099f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5209a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005209a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005209a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005209a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005209a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005209a5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005209a8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005209ab  0fefc0                 -pxor mm0, mm0
    cpu.mmx.mm0 = { _mm_xor_si128(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 005209ae  83f90f                 +cmp ecx, 0xf
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
    // 005209b1  7e2d                   -jle 0x5209e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005209e0;
    }
    // 005209b3  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x005209b6:
    // 005209b6  0f7f07                 -movq qword ptr [edi], mm0
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm0;
    // 005209b9  0f7f4708               -movq qword ptr [edi + 8], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm0;
    // 005209bd  0f7f4710               -movq qword ptr [edi + 0x10], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm0;
    // 005209c1  0f7f4718               -movq qword ptr [edi + 0x18], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm0;
    // 005209c5  0f7f4720               -movq qword ptr [edi + 0x20], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm0;
    // 005209c9  0f7f4728               -movq qword ptr [edi + 0x28], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm0;
    // 005209cd  0f7f4730               -movq qword ptr [edi + 0x30], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm0;
    // 005209d1  0f7f4738               -movq qword ptr [edi + 0x38], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm0;
    // 005209d5  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 005209d8  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005209db  7fd9                   -jg 0x5209b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005209b6;
    }
    // 005209dd  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x005209e0:
    // 005209e0  83f900                 +cmp ecx, 0
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
    // 005209e3  7e0b                   -jle 0x5209f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005209f0;
    }
    // 005209e5  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 005209e8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005209eb  83e901                 +sub ecx, 1
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
    // 005209ee  7ff0                   -jg 0x5209e0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005209e0;
    }
L_0x005209f0:
    // 005209f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005209f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005209f2  0f77                   -emms 
    cpu.mmx.init();
    // 005209f4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005209f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520a00  0f77                   -emms 
    cpu.mmx.init();
    // 00520a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520a10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520a11  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520a13  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520a14  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520a17  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520a1a  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00520a1d:
    // 00520a1d  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 00520a22  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00520a25  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 00520a2a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00520a2d  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 00520a30  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 00520a33  6689444ffe             -mov word ptr [edi + ecx*2 - 2], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.ax;
    // 00520a38  83e901                 +sub ecx, 1
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
    // 00520a3b  7fe0                   -jg 0x520a1d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520a1d;
    }
    // 00520a3d  61                     -popal 
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
    // 00520a3e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520a3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520a40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520a41  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520a43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520a44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520a45  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520a48  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520a4b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00520a4e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520a51  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00520a54  c7005e0a5200           -mov dword ptr [eax], 0x520a5e
    app->getMemory<x86::reg32>(cpu.eax) = 5376606 /*0x520a5e*/;
    // 00520a5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520a5b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520a5c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520a5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520a5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520a5e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520a5f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520a61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520a62  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520a63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00520a64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520a65  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520a68  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00520a6b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520a6e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520a71  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 00520a74  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 00520a77  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520a79  d80d10ad5600           -fmul dword ptr [0x56ad10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680400) /* 0x56ad10 */));
    // 00520a7f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520a81  d80d10ad5600           -fmul dword ptr [0x56ad10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680400) /* 0x56ad10 */));
    // 00520a87  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520a89  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520a8b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520a8e  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520a91  7417                   -je 0x520aaa
    if (cpu.flags.zf)
    {
        goto L_0x00520aaa;
    }
    // 00520a93  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520a96  7448                   -je 0x520ae0
    if (cpu.flags.zf)
    {
        goto L_0x00520ae0;
    }
    // 00520a98  83f87f                 +cmp eax, 0x7f
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
    // 00520a9b  7414                   -je 0x520ab1
    if (cpu.flags.zf)
    {
        goto L_0x00520ab1;
    }
    // 00520a9d  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520aa0  742e                   -je 0x520ad0
    if (cpu.flags.zf)
    {
        goto L_0x00520ad0;
    }
    // 00520aa2  c701ee0a5200           -mov dword ptr [ecx], 0x520aee
    app->getMemory<x86::reg32>(cpu.ecx) = 5376750 /*0x520aee*/;
    // 00520aa8  eb3e                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520aaa:
    // 00520aaa  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520aad  7409                   -je 0x520ab8
    if (cpu.flags.zf)
    {
        goto L_0x00520ab8;
    }
    // 00520aaf  eb27                   -jmp 0x520ad8
    goto L_0x00520ad8;
L_0x00520ab1:
    // 00520ab1  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520ab4  740a                   -je 0x520ac0
    if (cpu.flags.zf)
    {
        goto L_0x00520ac0;
    }
    // 00520ab6  eb10                   -jmp 0x520ac8
    goto L_0x00520ac8;
L_0x00520ab8:
    // 00520ab8  c701f10d5200           -mov dword ptr [ecx], 0x520df1
    app->getMemory<x86::reg32>(cpu.ecx) = 5377521 /*0x520df1*/;
    // 00520abe  eb28                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ac0:
    // 00520ac0  c7017e0b5200           -mov dword ptr [ecx], 0x520b7e
    app->getMemory<x86::reg32>(cpu.ecx) = 5376894 /*0x520b7e*/;
    // 00520ac6  eb20                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ac8:
    // 00520ac8  c7016b0d5200           -mov dword ptr [ecx], 0x520d6b
    app->getMemory<x86::reg32>(cpu.ecx) = 5377387 /*0x520d6b*/;
    // 00520ace  eb18                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ad0:
    // 00520ad0  c701e60c5200           -mov dword ptr [ecx], 0x520ce6
    app->getMemory<x86::reg32>(cpu.ecx) = 5377254 /*0x520ce6*/;
    // 00520ad6  eb10                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ad8:
    // 00520ad8  c701690c5200           -mov dword ptr [ecx], 0x520c69
    app->getMemory<x86::reg32>(cpu.ecx) = 5377129 /*0x520c69*/;
    // 00520ade  eb08                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ae0:
    // 00520ae0  c701ed0b5200           -mov dword ptr [ecx], 0x520bed
    app->getMemory<x86::reg32>(cpu.ecx) = 5377005 /*0x520bed*/;
    // 00520ae6  eb00                   -jmp 0x520ae8
    goto L_0x00520ae8;
L_0x00520ae8:
    // 00520ae8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520aea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520aeb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520aec  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520aed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520aee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520aee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520aef  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520af1  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520af2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520af5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520af8  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520afb  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00520afe  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 00520b00  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520b03  83f901                 +cmp ecx, 1
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
    // 00520b06  7e45                   -jle 0x520b4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520b4d;
    }
    // 00520b08  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520b0b:
    // 00520b0b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520b0d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520b0f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520b11  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520b13  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520b16  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520b18  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520b1b  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 00520b1d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520b1f  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520b22  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520b24  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520b27  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520b29  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520b2c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520b2e  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00520b31  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520b33  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b36  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b39  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b3c  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b3f  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520b42  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520b45  83e902                 +sub ecx, 2
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
    // 00520b48  7fc1                   -jg 0x520b0b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520b0b;
    }
    // 00520b4a  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520b4d:
    // 00520b4d  83f900                 +cmp ecx, 0
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
    // 00520b50  7e25                   -jle 0x520b77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520b77;
    }
    // 00520b52  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520b54  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520b56  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520b58  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520b5a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520b5c  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520b5f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520b61  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520b64  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520b66  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b69  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b6c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520b6f  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520b72  83e901                 +sub ecx, 1
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
    // 00520b75  7fd6                   -jg 0x520b4d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520b4d;
    }
L_0x00520b77:
    // 00520b77  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b79  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520b7b  61                     -popal 
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
    // 00520b7c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520b7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520b7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520b7e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520b7f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520b81  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520b82  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520b85  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520b88  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520b8b  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520b8e  83f901                 +cmp ecx, 1
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
    // 00520b91  7e35                   -jle 0x520bc8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520bc8;
    }
    // 00520b93  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520b96:
    // 00520b96  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00520b99  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520b9b  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00520b9e  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520ba0  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00520ba3  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 00520ba6  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00520ba9  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 00520bac  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520bae  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bb1  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bb4  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bb7  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bba  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520bbd  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520bc0  83e902                 +sub ecx, 2
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
    // 00520bc3  7fd1                   -jg 0x520b96
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520b96;
    }
    // 00520bc5  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520bc8:
    // 00520bc8  83f900                 +cmp ecx, 0
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
    // 00520bcb  7e1d                   -jle 0x520bea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520bea;
    }
    // 00520bcd  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00520bd0  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520bd2  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00520bd5  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520bd7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520bd9  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bdc  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520bdf  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520be2  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520be5  83e901                 +sub ecx, 1
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
    // 00520be8  7fde                   -jg 0x520bc8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520bc8;
    }
L_0x00520bea:
    // 00520bea  61                     -popal 
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
    // 00520beb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520bec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520bed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520bed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520bee  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520bf0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520bf1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520bf4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520bf7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520bfa  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 00520bfc  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520bff  83f903                 +cmp ecx, 3
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
    // 00520c02  7e46                   -jle 0x520c4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520c4a;
    }
    // 00520c04  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00520c07:
    // 00520c07  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520c09  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520c0b  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520c0e  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00520c10  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00520c13  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520c15  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00520c18  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00520c1a  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520c1c  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520c1f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520c21  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520c24  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520c26  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 00520c29  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520c2b  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 00520c2e  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520c30  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c33  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c36  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c39  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c3c  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520c3f  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00520c42  83e904                 +sub ecx, 4
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
    // 00520c45  7fc0                   -jg 0x520c07
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520c07;
    }
    // 00520c47  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00520c4a:
    // 00520c4a  83f900                 +cmp ecx, 0
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
    // 00520c4d  7e15                   -jle 0x520c64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520c64;
    }
    // 00520c4f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520c51  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520c53  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520c56  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c59  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520c5c  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520c5f  83e901                 +sub ecx, 1
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
    // 00520c62  7fe6                   -jg 0x520c4a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520c4a;
    }
L_0x00520c64:
    // 00520c64  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520c66  61                     -popal 
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
    // 00520c67  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520c68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520c69(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520c69  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520c6a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520c6c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520c6d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520c70  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520c73  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520c76  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00520c79  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520c7c  83f903                 +cmp ecx, 3
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
    // 00520c7f  7e46                   -jle 0x520cc7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520cc7;
    }
    // 00520c81  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00520c84:
    // 00520c84  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520c86  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520c88  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520c8b  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00520c8d  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00520c90  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520c92  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00520c95  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00520c97  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520c99  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520c9c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520c9e  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00520ca1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520ca3  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 00520ca6  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520ca8  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 00520cab  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520cad  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520cb0  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520cb3  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520cb6  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520cb9  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520cbc  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00520cbf  83e904                 +sub ecx, 4
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
    // 00520cc2  7fc0                   -jg 0x520c84
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520c84;
    }
    // 00520cc4  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00520cc7:
    // 00520cc7  83f900                 +cmp ecx, 0
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
    // 00520cca  7e15                   -jle 0x520ce1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520ce1;
    }
    // 00520ccc  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520cce  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520cd0  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520cd3  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520cd6  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520cd9  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520cdc  83e901                 +sub ecx, 1
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
    // 00520cdf  7fe6                   -jg 0x520cc7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520cc7;
    }
L_0x00520ce1:
    // 00520ce1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520ce3  61                     -popal 
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
    // 00520ce4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520ce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520ce6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520ce6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520ce7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520ce9  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520cea  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520ced  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520cf0  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520cf3  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 00520cf5  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520cf8  83f901                 +cmp ecx, 1
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
    // 00520cfb  7e41                   -jle 0x520d3e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520d3e;
    }
    // 00520cfd  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520d00:
    // 00520d00  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d02  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520d04  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d06  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520d09  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520d0b  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520d0e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520d10  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520d13  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520d15  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520d18  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520d1a  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520d1d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520d1f  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00520d22  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520d24  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d27  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d2a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d2d  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d30  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520d33  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520d36  83e902                 +sub ecx, 2
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
    // 00520d39  7fc5                   -jg 0x520d00
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520d00;
    }
    // 00520d3b  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520d3e:
    // 00520d3e  83f900                 +cmp ecx, 0
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
    // 00520d41  7e23                   -jle 0x520d66
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520d66;
    }
    // 00520d43  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d45  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520d47  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d49  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520d4b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520d4e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520d50  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520d53  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520d55  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d58  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d5b  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520d5e  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520d61  83e901                 +sub ecx, 1
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
    // 00520d64  7fd8                   -jg 0x520d3e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520d3e;
    }
L_0x00520d66:
    // 00520d66  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520d68  61                     -popal 
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
    // 00520d69  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520d6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520d6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520d6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520d6c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520d6e  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520d6f  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520d72  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520d75  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520d78  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00520d7b  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520d7e  83f901                 +cmp ecx, 1
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
    // 00520d81  7e41                   -jle 0x520dc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520dc4;
    }
    // 00520d83  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520d86:
    // 00520d86  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d88  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520d8a  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00520d8c  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520d8f  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520d92  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00520d94  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520d96  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520d99  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520d9b  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520d9e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520da0  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520da3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520da5  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00520da8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520daa  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520dad  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520db0  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520db3  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520db6  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520db9  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520dbc  83e902                 +sub ecx, 2
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
    // 00520dbf  7fc5                   -jg 0x520d86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520d86;
    }
    // 00520dc1  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520dc4:
    // 00520dc4  83f900                 +cmp ecx, 0
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
    // 00520dc7  7e23                   -jle 0x520dec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520dec;
    }
    // 00520dc9  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520dcb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520dcd  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00520dcf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520dd1  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520dd4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520dd6  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520dd9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520ddb  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520dde  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520de1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520de4  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520de7  83e901                 +sub ecx, 1
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
    // 00520dea  7fd8                   -jg 0x520dc4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520dc4;
    }
L_0x00520dec:
    // 00520dec  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520dee  61                     -popal 
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
    // 00520def  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520df0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520df1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520df1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520df2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520df4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520df5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_520e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520e00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520e01  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520e03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520e04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520e05  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520e08  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520e0b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00520e0e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520e11  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00520e14  c7001e0e5200           -mov dword ptr [eax], 0x520e1e
    app->getMemory<x86::reg32>(cpu.eax) = 5377566 /*0x520e1e*/;
    // 00520e1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520e1b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520e1c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520e1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520e1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520e1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520e1f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520e21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00520e22  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00520e23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00520e24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00520e25  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520e28  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00520e2b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520e2e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520e31  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 00520e34  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 00520e37  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520e39  d80d20ad5600           -fmul dword ptr [0x56ad20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680416) /* 0x56ad20 */));
    // 00520e3f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520e41  d80d20ad5600           -fmul dword ptr [0x56ad20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5680416) /* 0x56ad20 */));
    // 00520e47  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520e49  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520e4b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520e4e  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520e51  7417                   -je 0x520e6a
    if (cpu.flags.zf)
    {
        goto L_0x00520e6a;
    }
    // 00520e53  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520e56  7448                   -je 0x520ea0
    if (cpu.flags.zf)
    {
        goto L_0x00520ea0;
    }
    // 00520e58  83f87f                 +cmp eax, 0x7f
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
    // 00520e5b  7414                   -je 0x520e71
    if (cpu.flags.zf)
    {
        goto L_0x00520e71;
    }
    // 00520e5d  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520e60  742e                   -je 0x520e90
    if (cpu.flags.zf)
    {
        goto L_0x00520e90;
    }
    // 00520e62  c701ae0e5200           -mov dword ptr [ecx], 0x520eae
    app->getMemory<x86::reg32>(cpu.ecx) = 5377710 /*0x520eae*/;
    // 00520e68  eb3e                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520e6a:
    // 00520e6a  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520e6d  7409                   -je 0x520e78
    if (cpu.flags.zf)
    {
        goto L_0x00520e78;
    }
    // 00520e6f  eb27                   -jmp 0x520e98
    goto L_0x00520e98;
L_0x00520e71:
    // 00520e71  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00520e74  740a                   -je 0x520e80
    if (cpu.flags.zf)
    {
        goto L_0x00520e80;
    }
    // 00520e76  eb10                   -jmp 0x520e88
    goto L_0x00520e88;
L_0x00520e78:
    // 00520e78  c701bb115200           -mov dword ptr [ecx], 0x5211bb
    app->getMemory<x86::reg32>(cpu.ecx) = 5378491 /*0x5211bb*/;
    // 00520e7e  eb28                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520e80:
    // 00520e80  c701400f5200           -mov dword ptr [ecx], 0x520f40
    app->getMemory<x86::reg32>(cpu.ecx) = 5377856 /*0x520f40*/;
    // 00520e86  eb20                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520e88:
    // 00520e88  c70133115200           -mov dword ptr [ecx], 0x521133
    app->getMemory<x86::reg32>(cpu.ecx) = 5378355 /*0x521133*/;
    // 00520e8e  eb18                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520e90:
    // 00520e90  c701ac105200           -mov dword ptr [ecx], 0x5210ac
    app->getMemory<x86::reg32>(cpu.ecx) = 5378220 /*0x5210ac*/;
    // 00520e96  eb10                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520e98:
    // 00520e98  c7012d105200           -mov dword ptr [ecx], 0x52102d
    app->getMemory<x86::reg32>(cpu.ecx) = 5378093 /*0x52102d*/;
    // 00520e9e  eb08                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520ea0:
    // 00520ea0  c701b10f5200           -mov dword ptr [ecx], 0x520fb1
    app->getMemory<x86::reg32>(cpu.ecx) = 5377969 /*0x520fb1*/;
    // 00520ea6  eb00                   -jmp 0x520ea8
    goto L_0x00520ea8;
L_0x00520ea8:
    // 00520ea8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520ea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520eaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520eab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520eac  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520ead  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520eae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520eae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520eaf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520eb1  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520eb2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520eb5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520eb8  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520ebb  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00520ebe  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 00520ec0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520ec3  83f901                 +cmp ecx, 1
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
    // 00520ec6  7e46                   -jle 0x520f0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520f0e;
    }
    // 00520ec8  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520ecb:
    // 00520ecb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520ecd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520ecf  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520ed2  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520ed4  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00520ed7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520ed9  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00520edc  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 00520ede  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520ee0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520ee3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520ee5  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520ee8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520eea  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520eed  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520eef  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00520ef2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520ef4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520ef7  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520efa  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520efd  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f00  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520f03  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520f06  83e902                 +sub ecx, 2
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
    // 00520f09  7fc0                   -jg 0x520ecb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520ecb;
    }
    // 00520f0b  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520f0e:
    // 00520f0e  83f900                 +cmp ecx, 0
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
    // 00520f11  7e26                   -jle 0x520f39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520f39;
    }
    // 00520f13  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520f15  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520f17  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00520f1a  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520f1c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520f1e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520f21  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520f23  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00520f26  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520f28  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f2b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f2e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00520f31  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520f34  83e901                 +sub ecx, 1
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
    // 00520f37  7fd5                   -jg 0x520f0e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520f0e;
    }
L_0x00520f39:
    // 00520f39  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f3b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f3d  61                     -popal 
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
    // 00520f3e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520f3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520f40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520f41  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520f43  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520f44  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520f47  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520f4a  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520f4d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520f50  83f901                 +cmp ecx, 1
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
    // 00520f53  7e36                   -jle 0x520f8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520f8b;
    }
    // 00520f55  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520f58:
    // 00520f58  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00520f5b  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520f5d  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00520f60  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 00520f63  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00520f66  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00520f69  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 00520f6c  d8470c                 -fadd dword ptr [edi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */));
    // 00520f6f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520f71  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f74  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f77  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f7a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520f7d  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520f80  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00520f83  83e902                 +sub ecx, 2
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
    // 00520f86  7fd0                   -jg 0x520f58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520f58;
    }
    // 00520f88  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00520f8b:
    // 00520f8b  83f900                 +cmp ecx, 0
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
    // 00520f8e  7e1e                   -jle 0x520fae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00520fae;
    }
    // 00520f90  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 00520f93  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 00520f95  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00520f98  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 00520f9b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520f9d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520fa0  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520fa3  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520fa6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00520fa9  83e901                 +sub ecx, 1
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
    // 00520fac  7fdd                   -jg 0x520f8b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520f8b;
    }
L_0x00520fae:
    // 00520fae  61                     -popal 
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
    // 00520faf  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00520fb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_520fb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00520fb1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00520fb2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00520fb4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00520fb5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00520fb8  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00520fbb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00520fbe  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 00520fc0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00520fc3  83f903                 +cmp ecx, 3
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
    // 00520fc6  7e46                   -jle 0x52100e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052100e;
    }
    // 00520fc8  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00520fcb:
    // 00520fcb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00520fcd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00520fcf  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00520fd2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00520fd4  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 00520fd7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00520fd9  d94718                 -fld dword ptr [edi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */)));
    // 00520fdc  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 00520fde  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520fe0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 00520fe3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520fe5  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00520fe8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00520fea  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 00520fed  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00520fef  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 00520ff2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00520ff4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520ff7  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520ffa  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00520ffd  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00521000  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00521003  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00521006  83e904                 +sub ecx, 4
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
    // 00521009  7fc0                   -jg 0x520fcb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00520fcb;
    }
    // 0052100b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0052100e:
    // 0052100e  83f900                 +cmp ecx, 0
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
    // 00521011  7e15                   -jle 0x521028
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00521028;
    }
    // 00521013  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 00521015  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00521017  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 0052101a  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052101d  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00521020  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00521023  83e901                 +sub ecx, 1
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
    // 00521026  7fe6                   -jg 0x52100e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052100e;
    }
L_0x00521028:
    // 00521028  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052102a  61                     -popal 
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
    // 0052102b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052102c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52102d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052102d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052102e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00521030  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00521031  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00521034  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00521037  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052103a  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0052103d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00521040  83f903                 +cmp ecx, 3
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
    // 00521043  7e47                   -jle 0x52108c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052108c;
    }
    // 00521045  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00521048:
    // 00521048  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0052104b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052104d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 00521050  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00521052  d94714                 -fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 00521055  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 00521057  d9471c                 -fld dword ptr [edi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */)));
    // 0052105a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0052105c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0052105e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00521061  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00521063  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 00521066  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00521068  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 0052106b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0052106d  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 00521070  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00521072  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00521075  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00521078  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052107b  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052107e  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00521081  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00521084  83e904                 +sub ecx, 4
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
    // 00521087  7fbf                   -jg 0x521048
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00521048;
    }
    // 00521089  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0052108c:
    // 0052108c  83f900                 +cmp ecx, 0
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
    // 0052108f  7e16                   -jle 0x5210a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005210a7;
    }
    // 00521091  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00521094  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00521096  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 00521099  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052109c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052109f  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005210a2  83e901                 +sub ecx, 1
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
    // 005210a5  7fe5                   -jg 0x52108c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052108c;
    }
L_0x005210a7:
    // 005210a7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005210a9  61                     -popal 
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
    // 005210aa  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005210ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
