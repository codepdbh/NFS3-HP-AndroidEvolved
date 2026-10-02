#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_505920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505920  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00505924  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505926  7505                   -jne 0x50592d
    if (!cpu.flags.zf)
    {
        goto L_0x0050592d;
    }
    // 00505928  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050592d:
    // 0050592d  48                     -dec eax
    (cpu.eax)--;
    // 0050592e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050592f  a3e87d5600             -mov dword ptr [0x567de8], eax
    app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */) = cpu.eax;
    // 00505934  ff159ca2a000           -call dword ptr [0xa0a29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527388) /* 0xa0a29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050593a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050593f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_505950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505950  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00505952  66a1e47d5600           -mov ax, word ptr [0x567de4]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5668324) /* 0x567de4 */);
    // 00505958  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505959  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050595b  8b15e07d5600           -mov edx, dword ptr [0x567de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668320) /* 0x567de0 */);
    // 00505961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505962  ff15a0a2a000           -call dword ptr [0xa0a2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527392) /* 0xa0a2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505968  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0050596e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
    // 00505970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_505980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505981  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00505986:
    // 00505986  ff1554a3a000           -call dword ptr [0xa0a354]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527572) /* 0xa0a354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050598c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050598e  7403                   -je 0x505993
    if (cpu.flags.zf)
    {
        goto L_0x00505993;
    }
    // 00505990  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00505991  75f3                   -jne 0x505986
    if (!cpu.flags.zf)
    {
        goto L_0x00505986;
    }
L_0x00505993:
    // 00505993  8b15f07d5600           -mov edx, dword ptr [0x567df0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668336) /* 0x567df0 */);
    // 00505999  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050599a  ff15a4a2a000           -call dword ptr [0xa0a2a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527396) /* 0xa0a2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005059a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005059a1  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005059a7  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 005059ad  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005059b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5059d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005059d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005059d1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005059d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005059d7  83f803                 +cmp eax, 3
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
    // 005059da  770d                   -ja 0x5059e9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005059e9;
    }
    // 005059dc  ff2485b4595000         -jmp dword ptr [eax*4 + 0x5059b4]
    cpu.ip = app->getMemory<x86::reg32>(5265844 + cpu.eax * 4); goto dynamic_jump;
  case 0x005059e3:
    // 005059e3  ff15b0a2a000           -call dword ptr [0xa0a2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527408) /* 0xa0a2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005059e9:
    // 005059e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005059eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005059ec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x005059ef:
    // 005059ef  ff15b4a2a000           -call dword ptr [0xa0a2b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527412) /* 0xa0a2b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005059f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005059f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005059f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005059fa  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x005059fd:
    // 005059fd  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00505a02:
    // 00505a02  ff15aca2a000           -call dword ptr [0xa0a2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527404) /* 0xa0a2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505a08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505a0a  7515                   -jne 0x505a21
    if (!cpu.flags.zf)
    {
        goto L_0x00505a21;
    }
L_0x00505a0c:
    // 00505a0c  ff15aca2a000           -call dword ptr [0xa0a2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527404) /* 0xa0a2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505a12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505a14  7503                   -jne 0x505a19
    if (!cpu.flags.zf)
    {
        goto L_0x00505a19;
    }
    // 00505a16  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00505a17  75f3                   -jne 0x505a0c
    if (!cpu.flags.zf)
    {
        goto L_0x00505a0c;
    }
L_0x00505a19:
    // 00505a19  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00505a1b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505a1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505a1e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00505a21:
    // 00505a21  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00505a22  75de                   -jne 0x505a02
    if (!cpu.flags.zf)
    {
        goto L_0x00505a02;
    }
    // 00505a24  ebe6                   -jmp 0x505a0c
    goto L_0x00505a0c;
  case 0x00505a26:
    // 00505a26  ff15a8a2a000           -call dword ptr [0xa0a2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527400) /* 0xa0a2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505a2c  c1e80c                 -shr eax, 0xc
    cpu.eax >>= 12 /*0xc*/ % 32;
    // 00505a2f  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 00505a34  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00505a39  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00505a3b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505a3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505a3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_505a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505a51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505a52  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00505a56  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505a57  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00505a5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00505a5c  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00505a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505a61  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00505a65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505a66  ff15b8a2a000           -call dword ptr [0xa0a2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527416) /* 0xa0a2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505a6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505a71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505a72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505a73  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_505a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00505a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505a83  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00505a85  744d                   -je 0x505ad4
    if (cpu.flags.zf)
    {
        goto L_0x00505ad4;
    }
    // 00505a87  b9204c5000             -mov ecx, 0x504c20
    cpu.ecx = 5262368 /*0x504c20*/;
    // 00505a8c  be004c5000             -mov esi, 0x504c00
    cpu.esi = 5262336 /*0x504c00*/;
    // 00505a91  8b1d40a3a000           -mov ebx, dword ptr [0xa0a340]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10527552) /* 0xa0a340 */);
L_0x00505a97:
    // 00505a97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505a99  7449                   -je 0x505ae4
    if (cpu.flags.zf)
    {
        goto L_0x00505ae4;
    }
    // 00505a9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505a9c  baf04a5000             -mov edx, 0x504af0
    cpu.edx = 5262064 /*0x504af0*/;
    // 00505aa1  bf704b5000             -mov edi, 0x504b70
    cpu.edi = 5262192 /*0x504b70*/;
    // 00505aa6  891570a7a000           -mov dword ptr [0xa0a770], edx
    app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */) = cpu.edx;
    // 00505aac  893d6ca7a000           -mov dword ptr [0xa0a76c], edi
    app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */) = cpu.edi;
    // 00505ab2  baf04b5000             -mov edx, 0x504bf0
    cpu.edx = 5262320 /*0x504bf0*/;
    // 00505ab7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00505ab8:
    // 00505ab8  891558a7a000           -mov dword ptr [0xa0a758], edx
    app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */) = cpu.edx;
    // 00505abe  893564a7a000           -mov dword ptr [0xa0a764], esi
    app->getMemory<x86::reg32>(x86::reg32(10528612) /* 0xa0a764 */) = cpu.esi;
    // 00505ac4  891d60a7a000           -mov dword ptr [0xa0a760], ebx
    app->getMemory<x86::reg32>(x86::reg32(10528608) /* 0xa0a760 */) = cpu.ebx;
    // 00505aca  890d5ca7a000           -mov dword ptr [0xa0a75c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10528604) /* 0xa0a75c */) = cpu.ecx;
    // 00505ad0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ad1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ad2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ad3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505ad4:
    // 00505ad4  8b3504a3a000           -mov esi, dword ptr [0xa0a304]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10527492) /* 0xa0a304 */);
    // 00505ada  8b1d08a3a000           -mov ebx, dword ptr [0xa0a308]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10527496) /* 0xa0a308 */);
    // 00505ae0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00505ae2  ebb3                   -jmp 0x505a97
    goto L_0x00505a97;
L_0x00505ae4:
    // 00505ae4  893570a7a000           -mov dword ptr [0xa0a770], esi
    app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */) = cpu.esi;
    // 00505aea  890d6ca7a000           -mov dword ptr [0xa0a76c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */) = cpu.ecx;
    // 00505af0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00505af2  ebc4                   -jmp 0x505ab8
    goto L_0x00505ab8;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_505b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00505b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505b31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505b32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505b33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505b34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00505b36  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00505b39  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00505b3c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00505b3e  83f80f                 +cmp eax, 0xf
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
    // 00505b41  7333                   -jae 0x505b76
    if (!cpu.flags.cf)
    {
        goto L_0x00505b76;
    }
    // 00505b43  83f807                 +cmp eax, 7
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
    // 00505b46  0f83d3010000           -jae 0x505d1f
    if (!cpu.flags.cf)
    {
        goto L_0x00505d1f;
    }
    // 00505b4c  83f803                 +cmp eax, 3
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
    // 00505b4f  0f83e4020000           -jae 0x505e39
    if (!cpu.flags.cf)
    {
        goto L_0x00505e39;
    }
    // 00505b55  83f801                 +cmp eax, 1
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
    // 00505b58  726a                   -jb 0x505bc4
    if (cpu.flags.cf)
    {
        goto L_0x00505bc4;
    }
    // 00505b5a  0f8729030000           -ja 0x505e89
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505e89;
    }
    // 00505b60  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505b63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505b64  e807fdffff             -call 0x505870
    cpu.esp -= 4;
    sub_505870(app, cpu);
    if (cpu.terminate) return;
    // 00505b69  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
  [[fallthrough]];
  case 0x00505b6b:
L_0x00505b6b:
    // 00505b6b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505b6d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505b6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505b70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505b71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505b72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505b73  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505b76:
    // 00505b76  0f86df040000           -jbe 0x50605b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050605b;
    }
    // 00505b7c  83f81c                 +cmp eax, 0x1c
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
    // 00505b7f  7326                   -jae 0x505ba7
    if (!cpu.flags.cf)
    {
        goto L_0x00505ba7;
    }
    // 00505b81  83f818                 +cmp eax, 0x18
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
    // 00505b84  0f83ed000000           -jae 0x505c77
    if (!cpu.flags.cf)
    {
        goto L_0x00505c77;
    }
    // 00505b8a  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505b8d  0f8311010000           -jae 0x505ca4
    if (!cpu.flags.cf)
    {
        goto L_0x00505ca4;
    }
    // 00505b93  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505b96  752c                   -jne 0x505bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00505bc4;
    }
    // 00505b98  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505b9b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505ba0  a3287e5600             -mov dword ptr [0x567e28], eax
    app->getMemory<x86::reg32>(x86::reg32(5668392) /* 0x567e28 */) = cpu.eax;
    // 00505ba5  ebc4                   -jmp 0x505b6b
    goto L_0x00505b6b;
L_0x00505ba7:
    // 00505ba7  0f8603060000           -jbe 0x5061b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005061b0;
    }
    // 00505bad  83f868                 +cmp eax, 0x68
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505bb0  731f                   -jae 0x505bd1
    if (!cpu.flags.cf)
    {
        goto L_0x00505bd1;
    }
    // 00505bb2  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505bb5  0f839e000000           -jae 0x505c59
    if (!cpu.flags.cf)
    {
        goto L_0x00505c59;
    }
    // 00505bbb  83f865                 +cmp eax, 0x65
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505bbe  0f8430050000           -je 0x5060f4
    if (cpu.flags.zf)
    {
        goto L_0x005060f4;
    }
L_0x00505bc4:
    // 00505bc4  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00505bc6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505bc8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505bca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505bcb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505bcc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505bcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505bce  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505bd1:
    // 00505bd1  7732                   -ja 0x505c05
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505c05;
    }
    // 00505bd3  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505bd6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505bdb  83fe03                 +cmp esi, 3
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
    // 00505bde  0f8774020000           -ja 0x505e58
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505e58;
    }
    // 00505be4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00505be6  ff2485185b5000         -jmp dword ptr [eax*4 + 0x505b18]
    cpu.ip = app->getMemory<x86::reg32>(5266200 + cpu.eax * 4); goto dynamic_jump;
  case 0x00505bed:
    // 00505bed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505bef  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00505bf1  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00505bf3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505bf4  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505bfa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505bfc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505bfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505bff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c02  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505c05:
    // 00505c05  83f86a                 +cmp eax, 0x6a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(106 /*0x6a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505c08  732c                   -jae 0x505c36
    if (!cpu.flags.cf)
    {
        goto L_0x00505c36;
    }
    // 00505c0a  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505c0e  0f84bb040000           -je 0x5060cf
    if (cpu.flags.zf)
    {
        goto L_0x005060cf;
    }
    // 00505c14  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00505c16  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505c19  ff15eca2a000           -call dword ptr [0xa0a2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505c1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505c20  ff15f0a2a000           -call dword ptr [0xa0a2f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527472) /* 0xa0a2f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505c26  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505c2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505c2d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505c2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c33  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505c36:
    // 00505c36  0f86d3030000           -jbe 0x50600f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050600f;
    }
    // 00505c3c  83f86b                 +cmp eax, 0x6b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(107 /*0x6b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505c3f  7583                   -jne 0x505bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00505bc4;
    }
    // 00505c41  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505c44  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505c49  a3f47d5600             -mov dword ptr [0x567df4], eax
    app->getMemory<x86::reg32>(x86::reg32(5668340) /* 0x567df4 */) = cpu.eax;
    // 00505c4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505c50  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505c52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c56  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505c59:
    // 00505c59  0f86ae040000           -jbe 0x50610d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050610d;
    }
    // 00505c5f  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505c62  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505c67  a3f07d5600             -mov dword ptr [0x567df0], eax
    app->getMemory<x86::reg32>(x86::reg32(5668336) /* 0x567df0 */) = cpu.eax;
    // 00505c6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505c6e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505c70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c74  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505c77:
    // 00505c77  0f8690040000           -jbe 0x50610d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050610d;
    }
    // 00505c7d  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505c80  0f82ee040000           -jb 0x506174
    if (cpu.flags.cf)
    {
        goto L_0x00506174;
    }
    // 00505c86  0f873c050000           -ja 0x5061c8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005061c8;
    }
    // 00505c8c  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505c8f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505c94  a3187e5600             -mov dword ptr [0x567e18], eax
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = cpu.eax;
    // 00505c99  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505c9b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505c9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505c9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ca0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ca1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505ca4:
    // 00505ca4  7744                   -ja 0x505cea
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505cea;
    }
    // 00505ca6  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505ca9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505cab  0f842f050000           -je 0x5061e0
    if (cpu.flags.zf)
    {
        goto L_0x005061e0;
    }
    // 00505cb1  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00505cb4  a3147e5600             -mov dword ptr [0x567e14], eax
    app->getMemory<x86::reg32>(x86::reg32(5668372) /* 0x567e14 */) = cpu.eax;
    // 00505cb9  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505cbc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00505cbf  a3207e5600             -mov dword ptr [0x567e20], eax
    app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */) = cpu.eax;
    // 00505cc4  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505cc7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00505cca  a3187e5600             -mov dword ptr [0x567e18], eax
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = cpu.eax;
    // 00505ccf  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505cd2  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00505cd5  a31c7e5600             -mov dword ptr [0x567e1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */) = cpu.eax;
    // 00505cda  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505cdf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505ce1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505ce3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ce4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ce5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ce6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ce7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505cea:
    // 00505cea  83f815                 +cmp eax, 0x15
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505ced  0f85d1feffff           -jne 0x505bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00505bc4;
    }
    // 00505cf3  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505cf6  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505cf9  0f876cfeffff           -ja 0x505b6b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505b6b;
    }
    // 00505cff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00505d01  ff2485f45a5000         -jmp dword ptr [eax*4 + 0x505af4]
    cpu.ip = app->getMemory<x86::reg32>(5266164 + cpu.eax * 4); goto dynamic_jump;
  case 0x00505d08:
L_0x00505d08:
    // 00505d08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505d09  ff15eca2a000           -call dword ptr [0xa0a2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505d0f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505d14  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505d16  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505d18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d1c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505d1f:
    // 00505d1f  0f867e010000           -jbe 0x505ea3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00505ea3;
    }
    // 00505d25  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505d28  734b                   -jae 0x505d75
    if (!cpu.flags.cf)
    {
        goto L_0x00505d75;
    }
    // 00505d2a  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505d2d  0f82d5040000           -jb 0x506208
    if (cpu.flags.cf)
    {
        goto L_0x00506208;
    }
    // 00505d33  0f8653040000           -jbe 0x50618c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050618c;
    }
    // 00505d39  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505d3c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00505d3e  0f8401020000           -je 0x505f45
    if (cpu.flags.zf)
    {
        goto L_0x00505f45;
    }
    // 00505d44  83fe01                 +cmp esi, 1
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
    // 00505d47  0f8417020000           -je 0x505f64
    if (cpu.flags.zf)
    {
        goto L_0x00505f64;
    }
    // 00505d4d  83fe02                 +cmp esi, 2
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
    // 00505d50  0f8515feffff           -jne 0x505b6b
    if (!cpu.flags.zf)
    {
        goto L_0x00505b6b;
    }
    // 00505d56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505d57  ff15d4a2a000           -call dword ptr [0xa0a2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527444) /* 0xa0a2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505d5d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00505d5f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505d64  ff15d8a2a000           -call dword ptr [0xa0a2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527448) /* 0xa0a2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505d6a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505d6c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505d6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505d72  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505d75:
    // 00505d75  0f8776000000           -ja 0x505df1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505df1;
    }
    // 00505d7b  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505d7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00505d80  83fe03                 +cmp esi, 3
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
    // 00505d83  750a                   -jne 0x505d8f
    if (!cpu.flags.zf)
    {
        goto L_0x00505d8f;
    }
    // 00505d85  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00505d8a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00505d8c  897d18                 -mov dword ptr [ebp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edi;
L_0x00505d8f:
    // 00505d8f  3b05087e5600           +cmp eax, dword ptr [0x567e08]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5668360) /* 0x567e08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505d95  7427                   -je 0x505dbe
    if (cpu.flags.zf)
    {
        goto L_0x00505dbe;
    }
    // 00505d97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505d99  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00505d9b  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00505d9d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505d9f  a3087e5600             -mov dword ptr [0x567e08], eax
    app->getMemory<x86::reg32>(x86::reg32(5668360) /* 0x567e08 */) = cpu.eax;
    // 00505da4  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505daa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505dac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505dae  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505db0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505db2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505db4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505db6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505db8  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00505dbe:
    // 00505dbe  8b15047e5600           -mov edx, dword ptr [0x567e04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668356) /* 0x567e04 */);
    // 00505dc4  a1087e5600             -mov eax, dword ptr [0x567e08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668360) /* 0x567e08 */);
    // 00505dc9  e8b2fcffff             -call 0x505a80
    cpu.esp -= 4;
    sub_505a80(app, cpu);
    if (cpu.terminate) return;
    // 00505dce  8b0d087e5600           -mov ecx, dword ptr [0x567e08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668360) /* 0x567e08 */);
    // 00505dd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00505dd5  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505dd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505dd9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505ddb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505de0  ff1518a3a000           -call dword ptr [0xa0a318]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527512) /* 0xa0a318 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505de6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505de8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505dea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505deb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505dec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ded  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505dee  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505df1:
    // 00505df1  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505df4  0f822f020000           -jb 0x506029
    if (cpu.flags.cf)
    {
        goto L_0x00506029;
    }
    // 00505dfa  0f878d020000           -ja 0x50608d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050608d;
    }
    // 00505e00  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505e04  0f85dc020000           -jne 0x5060e6
    if (!cpu.flags.zf)
    {
        goto L_0x005060e6;
    }
    // 00505e0a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00505e0f:
    // 00505e0f  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505e12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505e13  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00505e15  0f85d2020000           -jne 0x5060ed
    if (!cpu.flags.zf)
    {
        goto L_0x005060ed;
    }
    // 00505e1b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00505e20:
    // 00505e20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505e21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505e23  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505e28  ff1534a3a000           -call dword ptr [0xa0a334]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527540) /* 0xa0a334 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505e2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505e30  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505e32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e36  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505e39:
    // 00505e39  0f8604020000           -jbe 0x506043
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00506043;
    }
    // 00505e3f  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505e42  7321                   -jae 0x505e65
    if (!cpu.flags.cf)
    {
        goto L_0x00505e65;
    }
    // 00505e44  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505e47  83f801                 +cmp eax, 1
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
    // 00505e4a  0f8330010000           -jae 0x505f80
    if (!cpu.flags.cf)
    {
        goto L_0x00505f80;
    }
    // 00505e50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505e52  0f8465010000           -je 0x505fbd
    if (cpu.flags.zf)
    {
        goto L_0x00505fbd;
    }
L_0x00505e58:
    // 00505e58  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00505e5a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505e5c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505e5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e62  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505e65:
    // 00505e65  775c                   -ja 0x505ec3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00505ec3;
    }
    // 00505e67  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505e6b  7452                   -je 0x505ebf
    if (cpu.flags.zf)
    {
        goto L_0x00505ebf;
    }
    // 00505e6d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00505e72:
    // 00505e72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505e73  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505e78  ff15d0a2a000           -call dword ptr [0xa0a2d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527440) /* 0xa0a2d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505e7e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505e80  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505e82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e86  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505e89:
    // 00505e89  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505e8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505e8d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505e92  ff15c8a2a000           -call dword ptr [0xa0a2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527432) /* 0xa0a2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505e98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505e9a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505e9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505e9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ea0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505ea3:
    // 00505ea3  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00505ea6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505ea7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505ea9  ff15cca2a000           -call dword ptr [0xa0a2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527436) /* 0xa0a2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505eaf  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505eb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505eb6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505eb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505eb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505eba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ebb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505ebc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505ebf:
    // 00505ebf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00505ec1  ebaf                   -jmp 0x505e72
    goto L_0x00505e72;
L_0x00505ec3:
    // 00505ec3  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505ec7  754c                   -jne 0x505f15
    if (!cpu.flags.zf)
    {
        goto L_0x00505f15;
    }
    // 00505ec9  c705107e560001000000   -mov dword ptr [0x567e10], 1
    app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */) = 1 /*0x1*/;
L_0x00505ed3:
    // 00505ed3  a138825600             -mov eax, dword ptr [0x568238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669432) /* 0x568238 */);
    // 00505ed8  83f801                 +cmp eax, 1
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
    // 00505edb  7542                   -jne 0x505f1f
    if (!cpu.flags.zf)
    {
        goto L_0x00505f1f;
    }
    // 00505edd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505edf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505ee0  8b1d107e5600           -mov ebx, dword ptr [0x567e10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 00505ee6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505ee7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505ee8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00505eea  ff15bca2a000           -call dword ptr [0xa0a2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527420) /* 0xa0a2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505ef0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505ef2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505ef4  8b35107e5600           -mov esi, dword ptr [0x567e10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 00505efa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505efb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505efd  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
L_0x00505eff:
    // 00505eff  ff15c0a2a000           -call dword ptr [0xa0a2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527424) /* 0xa0a2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f05  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505f0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505f0c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505f0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f12  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505f15:
    // 00505f15  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00505f17  8935107e5600           -mov dword ptr [0x567e10], esi
    app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */) = cpu.esi;
    // 00505f1d  ebb4                   -jmp 0x505ed3
    goto L_0x00505ed3;
L_0x00505f1f:
    // 00505f1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505f21  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00505f23  8b15107e5600           -mov edx, dword ptr [0x567e10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 00505f29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505f2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505f2c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505f2e  ff15bca2a000           -call dword ptr [0xa0a2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527420) /* 0xa0a2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f34  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505f36  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00505f38  8b0d107e5600           -mov ecx, dword ptr [0x567e10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 00505f3e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00505f3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505f41  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505f43  ebba                   -jmp 0x505eff
    goto L_0x00505eff;
L_0x00505f45:
    // 00505f45  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505f46  ff15d4a2a000           -call dword ptr [0xa0a2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527444) /* 0xa0a2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f4c  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00505f4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505f53  ff15d8a2a000           -call dword ptr [0xa0a2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527448) /* 0xa0a2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f59  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505f5b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505f5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f61  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505f64:
    // 00505f64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505f65  ff15d4a2a000           -call dword ptr [0xa0a2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527444) /* 0xa0a2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f6b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00505f6d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00505f6f  ff15d8a2a000           -call dword ptr [0xa0a2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527448) /* 0xa0a2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f75  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505f77  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505f79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505f7d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505f80:
    // 00505f80  765a                   -jbe 0x505fdc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00505fdc;
    }
    // 00505f82  83f802                 +cmp eax, 2
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
    // 00505f85  0f85cdfeffff           -jne 0x505e58
    if (!cpu.flags.zf)
    {
        goto L_0x00505e58;
    }
    // 00505f8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505f8c  ff15dca2a000           -call dword ptr [0xa0a2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527452) /* 0xa0a2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f92  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00505f94  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 00505f99  ff15e0a2a000           -call dword ptr [0xa0a2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527456) /* 0xa0a2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505f9f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505fa1  891de47d5600           -mov dword ptr [0x567de4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668324) /* 0x567de4 */) = cpu.ebx;
    // 00505fa7  ff15e4a2a000           -call dword ptr [0xa0a2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527460) /* 0xa0a2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505fad  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505fb2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505fb4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505fb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fba  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505fbd:
    // 00505fbd  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00505fbf  ff15e0a2a000           -call dword ptr [0xa0a2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527456) /* 0xa0a2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505fc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505fc6  ff15e4a2a000           -call dword ptr [0xa0a2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527460) /* 0xa0a2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505fcc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505fd1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505fd3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00505fd5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505fd9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00505fdc:
    // 00505fdc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505fde  ff15dca2a000           -call dword ptr [0xa0a2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527452) /* 0xa0a2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505fe4  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00505fe6  beffff0000             -mov esi, 0xffff
    cpu.esi = 65535 /*0xffff*/;
    // 00505feb  ff15e0a2a000           -call dword ptr [0xa0a2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527456) /* 0xa0a2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505ff1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505ff3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00505ff8  8935e47d5600           -mov dword ptr [0x567de4], esi
    app->getMemory<x86::reg32>(x86::reg32(5668324) /* 0x567de4 */) = cpu.esi;
    // 00505ffe  ff15e4a2a000           -call dword ptr [0xa0a2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527460) /* 0xa0a2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506004  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506006  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050600a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050600b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050600c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0050600f:
    // 0050600f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00506012  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00506013  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506018  ff15e4a2a000           -call dword ptr [0xa0a2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527460) /* 0xa0a2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050601e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506020  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506022  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506023  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506025  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506026  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00506029:
    // 00506029  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050602c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050602d  ff1590a2a000           -call dword ptr [0xa0a290]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527376) /* 0xa0a290 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506033  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506038  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050603a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050603c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050603d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050603e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050603f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506040  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00506043:
    // 00506043  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00506046  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050604b  a3e07d5600             -mov dword ptr [0x567de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5668320) /* 0x567de0 */) = cpu.eax;
    // 00506050  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506052  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506054  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506055  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506056  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506057  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506058  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0050605b:
    // 0050605b  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050605e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050605f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506064  ff15e8a2a000           -call dword ptr [0xa0a2e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527464) /* 0xa0a2e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050606a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050606c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050606e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050606f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506070  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506071  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506072  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00506075:
    // 00506075  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00506077  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050607c  ff15eca2a000           -call dword ptr [0xa0a2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506082  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506084  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506086  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506087  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506088  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506089  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050608a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0050608d:
    // 0050608d  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00506091  0f8471fcffff           -je 0x505d08
    if (cpu.flags.zf)
    {
        goto L_0x00505d08;
    }
    // 00506097  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00506099  ff15eca2a000           -call dword ptr [0xa0a2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050609f  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005060a2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 005060a5  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 005060a8  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 005060aa  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 005060ac  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005060af  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 005060b2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005060b5  e876e9ffff             -call 0x504a30
    cpu.esp -= 4;
    sub_504a30(app, cpu);
    if (cpu.terminate) return;
    // 005060ba  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 005060bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005060be  ff15f0a2a000           -call dword ptr [0xa0a2f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527472) /* 0xa0a2f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005060c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005060c6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005060c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060cc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005060cf:
    // 005060cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005060d0  ff15eca2a000           -call dword ptr [0xa0a2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005060d6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005060db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005060dd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005060df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005060e3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005060e6:
    // 005060e6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005060e8  e922fdffff             -jmp 0x505e0f
    goto L_0x00505e0f;
L_0x005060ed:
    // 005060ed  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005060ef  e92cfdffff             -jmp 0x505e20
    goto L_0x00505e20;
L_0x005060f4:
    // 005060f4  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005060f7  ff1510a3a000           -call dword ptr [0xa0a310]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527504) /* 0xa0a310 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005060fd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506102  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506104  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506106  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506107  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506108  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506109  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050610a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0050610d:
    // 0050610d  8b4516                 -mov eax, dword ptr [ebp + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */);
    // 00506110  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00506113  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506114  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506119  ff1514a3a000           -call dword ptr [0xa0a314]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527508) /* 0xa0a314 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050611f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506121  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506123  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506125  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506126  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506127  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0050612a:
    // 0050612a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050612c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0050612e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00506130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506131  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506137  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506139  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050613b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050613c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050613d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050613e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050613f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x00506142:
    // 00506142  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00506144  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00506146  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00506148  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050614a  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506150  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506152  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506154  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506155  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506156  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506157  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506158  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x0050615b:
    // 0050615b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050615d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0050615f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00506161  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00506163  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506169  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050616b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050616d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050616e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050616f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506170  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506171  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00506174:
    // 00506174  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00506177  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050617c  a3ec7d5600             -mov dword ptr [0x567dec], eax
    app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */) = cpu.eax;
    // 00506181  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506183  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506185  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506186  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506187  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506189  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0050618c:
    // 0050618c  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050618f  a3047e5600             -mov dword ptr [0x567e04], eax
    app->getMemory<x86::reg32>(x86::reg32(5668356) /* 0x567e04 */) = cpu.eax;
    // 00506194  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00506196  a1087e5600             -mov eax, dword ptr [0x567e08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668360) /* 0x567e08 */);
    // 0050619b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005061a0  e8dbf8ffff             -call 0x505a80
    cpu.esp -= 4;
    sub_505a80(app, cpu);
    if (cpu.terminate) return;
    // 005061a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005061a7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005061a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061ad  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005061b0:
    // 005061b0  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005061b3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005061b8  a31c7e5600             -mov dword ptr [0x567e1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */) = cpu.eax;
    // 005061bd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005061bf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005061c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061c5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005061c8:
    // 005061c8  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005061cb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005061d0  a3207e5600             -mov dword ptr [0x567e20], eax
    app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */) = cpu.eax;
    // 005061d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005061d7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005061d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005061dd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005061e0:
    // 005061e0  891d207e5600           -mov dword ptr [0x567e20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */) = cpu.ebx;
    // 005061e6  891d187e5600           -mov dword ptr [0x567e18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = cpu.ebx;
    // 005061ec  891d1c7e5600           -mov dword ptr [0x567e1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */) = cpu.ebx;
    // 005061f2  891d147e5600           -mov dword ptr [0x567e14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668372) /* 0x567e14 */) = cpu.ebx;
    // 005061f8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005061fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005061ff  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00506201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506204  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506205  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00506208:
    // 00506208  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0050620b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050620c  ff1548a3a000           -call dword ptr [0xa0a348]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527560) /* 0xa0a348 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506212  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00506217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506219  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050621b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050621c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050621d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050621e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050621f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_506230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506231  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506232  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506233  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506234  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00506237  8b151c7e5600           -mov edx, dword ptr [0x567e1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    // 0050623d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050623f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00506241  0f85a1000000           -jne 0x5062e8
    if (!cpu.flags.zf)
    {
        goto L_0x005062e8;
    }
L_0x00506247:
    // 00506247  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506249  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050624a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050624c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050624e  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00506253  8b35e87d5600           -mov esi, dword ptr [0x567de8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */);
    // 00506259  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050625a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0050625f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00506261  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00506265  ff15f4a2a000           -call dword ptr [0xa0a2f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527476) /* 0xa0a2f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050626b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050626d  743e                   -je 0x5062ad
    if (cpu.flags.zf)
    {
        goto L_0x005062ad;
    }
    // 0050626f  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 00506274  e88716ffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00506279  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050627b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050627d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050627f  742c                   -je 0x5062ad
    if (cpu.flags.zf)
    {
        goto L_0x005062ad;
    }
    // 00506281  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00506285  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00506287  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050628b  c7420804000000         -mov dword ptr [edx + 8], 4
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
    // 00506292  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00506295  a1fc7d5600             -mov eax, dword ptr [0x567dfc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668348) /* 0x567dfc */);
    // 0050629a  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050629d  a1007e5600             -mov eax, dword ptr [0x567e00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668352) /* 0x567e00 */);
    // 005062a2  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005062a5  a1e87d5600             -mov eax, dword ptr [0x567de8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */);
    // 005062aa  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x005062ad:
    // 005062ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005062af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005062b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005062b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005062b4  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 005062b9  8b2de87d5600           -mov ebp, dword ptr [0x567de8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */);
    // 005062bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005062c0  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 005062c5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005062c7  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 005062cb  ff15f4a2a000           -call dword ptr [0xa0a2f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527476) /* 0xa0a2f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005062d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005062d3  7509                   -jne 0x5062de
    if (!cpu.flags.zf)
    {
        goto L_0x005062de;
    }
    // 005062d5  833d1c7e560000         +cmp dword ptr [0x567e1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005062dc  7517                   -jne 0x5062f5
    if (!cpu.flags.zf)
    {
        goto L_0x005062f5;
    }
L_0x005062de:
    // 005062de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005062e0  83c414                 +add esp, 0x14
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
    // 005062e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005062e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005062e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005062e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005062e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005062e8:
    // 005062e8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005062ea  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005062f0  e952ffffff             -jmp 0x506247
    goto L_0x00506247;
L_0x005062f5:
    // 005062f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005062f6  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005062fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005062fe  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00506301  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506302  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506303  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_506310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506311  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506312  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506313  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00506317  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0050631c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050631e  7508                   -jne 0x506328
    if (!cpu.flags.zf)
    {
        goto L_0x00506328;
    }
L_0x00506320:
    // 00506320  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00506322  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506323  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506324  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506325  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00506328:
    // 00506328  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050632b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050632c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050632d  ff15f8a2a000           -call dword ptr [0xa0a2f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527480) /* 0xa0a2f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506333  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506334  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00506336  ff15f8a2a000           -call dword ptr [0xa0a2f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527480) /* 0xa0a2f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050633c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050633e  e8ad16ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00506343  833d1c7e560000         +cmp dword ptr [0x567e1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050634a  74d4                   -je 0x506320
    if (cpu.flags.zf)
    {
        goto L_0x00506320;
    }
    // 0050634c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050634e  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506354  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00506356  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506357  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506358  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506359  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_506360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506361  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506362  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506363  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506364  833d1c7e560000         +cmp dword ptr [0x567e1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050636b  7408                   -je 0x506375
    if (cpu.flags.zf)
    {
        goto L_0x00506375;
    }
    // 0050636d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050636f  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00506375:
    // 00506375  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00506379  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050637d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050637e  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00506380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506381  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00506385  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506386  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050638a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050638b  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050638f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506390  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00506394  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506395  a1e87d5600             -mov eax, dword ptr [0x567de8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */);
    // 0050639a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050639b  ff1500a3a000           -call dword ptr [0xa0a300]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527488) /* 0xa0a300 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005063a1  8b151c7e5600           -mov edx, dword ptr [0x567e1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    // 005063a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005063a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005063ab  7509                   -jne 0x5063b6
    if (!cpu.flags.zf)
    {
        goto L_0x005063b6;
    }
    // 005063ad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005063af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063b3  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x005063b6:
    // 005063b6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005063b8  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005063be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005063c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005063c4  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_5063d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005063d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005063d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005063d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005063d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005063d4  833d1c7e560000         +cmp dword ptr [0x567e1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005063db  7408                   -je 0x5063e5
    if (cpu.flags.zf)
    {
        goto L_0x005063e5;
    }
    // 005063dd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005063df  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005063e5:
    // 005063e5  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005063e9  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005063ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005063ee  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005063f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005063f1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005063f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005063f6  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005063fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005063fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005063fd  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00506401  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506402  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00506406  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506407  a1e87d5600             -mov eax, dword ptr [0x567de8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */);
    // 0050640c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050640d  ff15fca2a000           -call dword ptr [0xa0a2fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527484) /* 0xa0a2fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506413  8b151c7e5600           -mov edx, dword ptr [0x567e1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    // 00506419  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050641b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050641d  7509                   -jne 0x506428
    if (!cpu.flags.zf)
    {
        goto L_0x00506428;
    }
    // 0050641f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506421  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506422  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506423  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506424  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506425  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00506428:
    // 00506428  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050642a  ff151c7e5600           -call dword ptr [0x567e1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668380) /* 0x567e1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506430  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00506432  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506433  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506434  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506435  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506436  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_506440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506441  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00506447  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 0050644e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506450  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506453  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506459  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050645c  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506462  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506464  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050646a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050646d  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506473  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506475  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506477  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050647a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050647d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506480  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506483  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506485  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506487  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050648a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506491  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506494  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506497  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050649e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005064a1  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005064a4  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005064a7  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005064aa  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005064b1  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005064b4  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005064b7  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005064be  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005064c1  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005064c4  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005064c7  8b9424fc000000         -mov edx, dword ptr [esp + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 005064ce  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005064d2  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005064d5  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005064db  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005064de  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005064e4  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005064e6  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005064ec  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005064ef  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005064f5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005064f7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005064f9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005064fc  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005064ff  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506502  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506505  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506507  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506509  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050650c  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506513  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506516  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506519  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506520  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506523  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506526  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506529  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0050652c  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506533  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506536  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506539  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506540  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506543  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506546  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506549  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00506550  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506554  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506557  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 0050655d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506560  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506566  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506568  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050656e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506571  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506577  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506579  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050657b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050657e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506581  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506584  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506587  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506589  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050658b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050658e  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506595  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506598  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0050659b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005065a2  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005065a5  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005065a8  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005065ab  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005065ae  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005065b5  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005065b8  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005065bb  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005065c2  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005065c5  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005065c8  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005065cb  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 005065d2  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 005065d9  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005065dc  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005065e2  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005065e5  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005065eb  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005065ed  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005065f3  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005065f6  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005065fc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005065fe  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506600  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506603  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506606  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506609  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050660c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050660e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506610  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506613  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050661a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050661d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506620  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506627  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050662a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050662d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506630  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506633  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050663a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050663d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506640  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506647  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0050664a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050664d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506650  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506654  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506655  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00506659  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050665a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050665e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050665f  ff156ca7a000           -call dword ptr [0xa0a76c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506665  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506667  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506668  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0050666f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506670  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00506677  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506678  ff156ca7a000           -call dword ptr [0xa0a76c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050667e  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00506684  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506685  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_506690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506693  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00506699  8bac2400010000         -mov ebp, dword ptr [esp + 0x100]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 005066a0  8bbc2404010000         -mov edi, dword ptr [esp + 0x104]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 005066a7  8bb42408010000         -mov esi, dword ptr [esp + 0x108]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 005066ae  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005066b0  0f8e4a020000           -jle 0x506900
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00506900;
    }
    // 005066b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x005066b7:
    // 005066b7  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005066ba  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 005066bd  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005066c1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005066c3  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005066c6  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005066cc  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005066cf  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005066d5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005066d7  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005066dd  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005066e0  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005066e6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005066e8  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005066ea  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005066ed  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005066f0  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005066f3  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005066f6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005066f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005066fa  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005066fd  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506704  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506707  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0050670a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506711  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506714  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506717  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0050671a  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0050671d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506724  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506727  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050672a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506731  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506734  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506737  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050673a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0050673d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00506740  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00506744  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00506746  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506749  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 0050674f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506752  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506758  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0050675a  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506760  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506763  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506769  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050676b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050676d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506770  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506773  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506776  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506779  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050677b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050677d  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506780  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506787  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050678a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0050678d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506794  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506797  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050679a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0050679d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005067a0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005067a7  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005067aa  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005067ad  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005067b4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005067b7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005067ba  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005067bd  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005067c0  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 005067c3  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005067ca  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005067cc  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005067cf  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005067d5  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005067d8  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005067de  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005067e0  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005067e6  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005067e9  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005067ef  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005067f1  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005067f3  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005067f6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005067f9  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005067fc  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005067ff  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506801  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506803  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506806  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050680d  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506810  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506813  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050681a  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050681d  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506820  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506823  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506826  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050682d  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506830  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506833  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050683a  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0050683d  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506840  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506843  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00506845  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00506848  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050684c  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050684e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506851  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506857  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050685a  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506860  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506862  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506868  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050686b  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506871  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506873  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506875  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506878  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050687b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050687e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506881  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506883  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506885  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506888  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050688f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506892  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506895  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050689c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050689f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005068a2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005068a5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005068a8  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005068af  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005068b2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005068b5  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005068bc  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005068bf  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005068c2  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005068c5  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 005068c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068ca  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 005068ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068cf  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005068d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068d4  ff156ca7a000           -call dword ptr [0xa0a76c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005068da  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005068de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068df  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 005068e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068e7  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 005068ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005068ef  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005068f2  ff156ca7a000           -call dword ptr [0xa0a76c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005068f8  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005068f9  0f85b8fdffff           -jne 0x5066b7
    if (!cpu.flags.zf)
    {
        goto L_0x005066b7;
    }
    // 005068ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00506900:
    // 00506900  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00506906  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506907  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506908  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506909  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_506910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506911  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00506917  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0050691e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506920  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506923  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506929  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050692c  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506932  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506934  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050693a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050693d  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506943  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506945  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506947  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050694a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050694d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506950  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506953  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506955  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506957  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050695a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506961  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506964  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506967  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050696e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506971  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506974  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506977  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0050697a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506981  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506984  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506987  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050698e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506991  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506994  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506997  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0050699e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005069a2  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005069a5  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005069ab  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005069ae  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005069b4  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005069b6  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005069bc  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005069bf  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005069c5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005069c7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005069c9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005069cc  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005069cf  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005069d2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005069d5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005069d7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005069d9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005069dc  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005069e3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005069e6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005069e9  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005069f0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005069f3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005069f6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005069f9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005069fc  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a03  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506a06  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506a09  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a10  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506a13  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a16  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a19  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00506a20  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506a24  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506a27  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506a2d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506a30  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506a36  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506a38  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506a3e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506a41  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506a47  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506a49  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a4b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a4e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506a51  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506a54  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506a57  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506a59  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506a5b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506a5e  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a65  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506a68  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506a6b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a72  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506a75  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a78  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506a7b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506a7e  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a85  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506a88  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506a8b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506a92  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506a95  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a98  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506a9b  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506a9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506aa0  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00506aa4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506aa5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00506aa9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506aaa  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506ab0  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00506ab6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506ab7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_506ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506ac0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506ac1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506ac2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506ac3  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00506ac9  8bbc24c4000000         -mov edi, dword ptr [esp + 0xc4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 00506ad0  8bac24c8000000         -mov ebp, dword ptr [esp + 0xc8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00506ad7  8bb424cc000000         -mov esi, dword ptr [esp + 0xcc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00506ade  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00506ae0  0f8ea9010000           -jle 0x506c8f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00506c8f;
    }
    // 00506ae6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00506ae7:
    // 00506ae7  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00506aea  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00506aed  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00506af1  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00506af3  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506af6  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506afc  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506aff  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506b05  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506b07  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506b0d  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506b10  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506b16  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506b18  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b1a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b1d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506b20  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506b23  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506b26  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506b28  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506b2a  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506b2d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506b34  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506b37  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506b3a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506b41  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506b44  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b47  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506b4a  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506b4d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506b54  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506b57  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506b5a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506b61  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506b64  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b67  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b6a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00506b6d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00506b70  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00506b74  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00506b76  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506b79  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506b7f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506b82  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506b88  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506b8a  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506b90  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506b93  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506b99  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506b9b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506b9d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506ba0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506ba3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506ba6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506ba9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506bab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506bad  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506bb0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506bb7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506bba  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506bbd  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506bc4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506bc7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506bca  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506bcd  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506bd0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506bd7  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506bda  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506bdd  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506be4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506be7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506bea  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506bed  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00506bef  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00506bf2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00506bf6  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00506bf8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506bfb  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506c01  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506c04  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506c0a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506c0c  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506c12  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506c15  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506c1b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506c1d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506c1f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506c22  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506c25  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506c28  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506c2b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506c2d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506c2f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506c32  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506c39  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506c3c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506c3f  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506c46  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506c49  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506c4c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506c4f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506c52  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506c59  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506c5c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506c5f  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506c66  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506c69  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506c6c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506c6f  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00506c73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506c74  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00506c78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506c79  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00506c7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506c7e  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00506c81  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506c87  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00506c88  0f8559feffff           -jne 0x506ae7
    if (!cpu.flags.zf)
    {
        goto L_0x00506ae7;
    }
    // 00506c8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00506c8f:
    // 00506c8f  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00506c95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506c96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506c97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506c98  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_506ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00506ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00506ca1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00506ca2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00506ca3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00506ca4  81ecc4000000           -sub esp, 0xc4
    (cpu.esp) -= x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00506caa  8bb424d8000000         -mov esi, dword ptr [esp + 0xd8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 00506cb1  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506cb8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506cba  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506cbd  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506cc3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506cc6  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506ccc  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506cce  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506cd4  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506cd7  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506cdd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506cdf  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506ce1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506ce4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506ce7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506cea  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506ced  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506cef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506cf1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506cf4  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506cfb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506cfe  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506d01  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506d08  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506d0b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d0e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506d11  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506d14  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506d1b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506d1e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506d21  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506d28  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506d2b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d2e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d31  8b9424dc000000         -mov edx, dword ptr [esp + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506d38  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00506d3c  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00506d3f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506d42  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506d48  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506d4b  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506d51  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506d53  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506d59  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506d5c  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506d62  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506d64  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d66  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d69  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506d6c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506d6f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506d72  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506d74  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506d76  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506d79  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506d80  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506d83  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506d86  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506d8d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506d90  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506d93  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506d96  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506d99  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506da0  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506da3  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506da6  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506dad  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506db0  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506db3  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506db6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00506db8  0f8ee5000000           -jle 0x506ea3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00506ea3;
    }
    // 00506dbe  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506dc5  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00506dc8  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00506dcf  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506dd6  8bbc24dc000000         -mov edi, dword ptr [esp + 0xdc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506ddd  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00506de2  8bac24dc000000         -mov ebp, dword ptr [esp + 0xdc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506de9  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 00506df0  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00506df7  81c7a0000000           -add edi, 0xa0
    (cpu.edi) += x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 00506dfd  05e0000000             -add eax, 0xe0
    (cpu.eax) += x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 00506e02  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00506e05  898424bc000000         -mov dword ptr [esp + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.eax;
L_0x00506e0c:
    // 00506e0c  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506e10  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00506e12  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506e15  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506e1b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506e1e  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506e24  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506e26  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506e2c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506e2f  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506e35  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506e37  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506e39  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506e3c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506e3f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506e42  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506e45  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506e47  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506e49  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506e4c  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506e53  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506e56  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506e59  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506e60  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506e63  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506e66  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506e69  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506e6c  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506e73  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506e76  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506e79  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506e80  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506e83  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506e86  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506e89  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506e8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506e8e  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00506e92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506e93  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00506e97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506e98  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506e9e  83fe02                 +cmp esi, 2
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
    // 00506ea1  7d0d                   -jge 0x506eb0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00506eb0;
    }
L_0x00506ea3:
    // 00506ea3  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00506ea9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506eaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506eab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506eac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00506ead  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00506eb0:
    // 00506eb0  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00506eb7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00506eb9  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506ebc  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506ec2  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506ec5  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506ecb  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506ecd  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506ed3  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506ed6  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506edc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506ede  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506ee0  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506ee3  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506ee6  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506ee9  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506eec  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506eee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506ef0  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506ef3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506efa  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506efd  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506f00  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506f07  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506f0a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506f0d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506f10  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506f13  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506f1a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506f1d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506f20  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506f27  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506f2a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506f2d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506f30  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506f34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506f35  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00506f39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506f3a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00506f3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506f3f  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506f45  83fe03                 +cmp esi, 3
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
    // 00506f48  0f8c55ffffff           -jl 0x506ea3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00506ea3;
    }
    // 00506f4e  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00506f55  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00506f59  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506f5c  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00506f62  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00506f65  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00506f6b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00506f6d  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506f73  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00506f76  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00506f7c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00506f7e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506f80  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506f83  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00506f86  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00506f89  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00506f8c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00506f8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00506f90  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00506f93  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506f9a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00506f9d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00506fa0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506fa7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00506faa  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506fad  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00506fb0  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00506fb3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506fba  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00506fbd  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00506fc0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00506fc7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00506fca  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506fcd  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00506fd0  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00506fd4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506fd5  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00506fd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506fda  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00506fe1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00506fe2  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00506fe8  83fe04                 +cmp esi, 4
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
    // 00506feb  0f8cb2feffff           -jl 0x506ea3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00506ea3;
    }
    // 00506ff1  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00506ff5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00506ff7  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00506ffa  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507000  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507003  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507009  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0050700b  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507011  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507014  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050701a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050701c  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050701e  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507021  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507024  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507027  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050702a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050702c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050702e  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507031  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507038  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050703b  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0050703e  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507045  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507048  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050704b  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0050704e  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507051  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507058  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050705b  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050705e  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507065  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507068  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050706b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050706e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00507072  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507073  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00507077  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507078  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050707c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050707d  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507083  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00507086  0f8c17feffff           -jl 0x506ea3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00506ea3;
    }
    // 0050708c  8b8424dc000000         -mov eax, dword ptr [esp + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 00507093  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00507098  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0050709f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005070a1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005070a3  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005070a6  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005070ac  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005070af  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005070b5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005070b7  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005070bd  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005070c0  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005070c6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005070c8  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005070ca  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005070cd  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005070d0  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005070d3  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005070d6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005070d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005070da  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005070dd  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005070e4  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005070e7  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005070ea  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005070f1  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005070f4  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005070f7  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005070fa  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005070fd  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507104  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507107  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0050710a  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507111  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507114  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507117  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050711a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050711c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050711d  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00507121  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507122  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00507126  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507127  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050712d  83fe06                 +cmp esi, 6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00507130  0f8c6dfdffff           -jl 0x506ea3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00506ea3;
    }
    // 00507136  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0050713d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00507141  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507144  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 0050714a  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050714d  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507153  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507155  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050715b  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050715e  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507164  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507166  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507168  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050716b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050716e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507171  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507174  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507176  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507178  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050717b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507182  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507185  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507188  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050718f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507192  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507195  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507198  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0050719b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005071a2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005071a5  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005071a8  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005071af  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005071b2  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005071b5  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005071b8  81c5c0000000           -add ebp, 0xc0
    (cpu.ebp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 005071be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005071c0  81c7c0000000           -add edi, 0xc0
    (cpu.edi) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 005071c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005071c7  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005071cb  8b9c24c0000000         -mov ebx, dword ptr [esp + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 005071d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005071d3  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005071da  81c3c0000000           -add ebx, 0xc0
    (cpu.ebx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 005071e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005071e1  83ee06                 -sub esi, 6
    (cpu.esi) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 005071e4  899c24c8000000         -mov dword ptr [esp + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 005071eb  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005071f1  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 005071f8  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005071ff  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00507206  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0050720c  81c1c0000000           -add ecx, 0xc0
    (cpu.ecx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00507212  898424dc000000         -mov dword ptr [esp + 0xdc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */) = cpu.eax;
    // 00507219  899424c0000000         -mov dword ptr [esp + 0xc0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 00507220  898c24b8000000         -mov dword ptr [esp + 0xb8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ecx;
    // 00507227  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00507229  0f8fddfbffff           -jg 0x506e0c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00506e0c;
    }
    // 0050722f  81c4c4000000           -add esp, 0xc4
    (cpu.esp) += x86::reg32(x86::sreg32(196 /*0xc4*/));
    // 00507235  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507236  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507237  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507238  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507239  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_507240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507241  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507243  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00507244  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0050724a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00507251  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00507258  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050725a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050725c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050725f  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507265  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507268  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 0050726e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507270  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507276  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507279  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050727f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507281  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507283  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507286  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507289  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050728c  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050728f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507291  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507293  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507296  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050729d  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005072a0  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005072a3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005072aa  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005072ad  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005072b0  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005072b3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005072b6  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005072bd  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005072c0  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005072c3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005072ca  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005072cd  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005072d0  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005072d3  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005072d7  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005072da  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005072dd  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005072e3  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005072e6  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005072ec  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005072ee  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005072f4  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005072f7  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005072fd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005072ff  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507301  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507304  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507307  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050730a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050730d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050730f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507311  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507314  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050731b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050731e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507321  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507328  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050732b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050732e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507331  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507334  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050733b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050733e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507341  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507348  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0050734b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050734e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507351  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00507353  0f8e9d000000           -jle 0x5073f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005073f6;
    }
    // 00507359  8d7560                 -lea esi, [ebp + 0x60]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
L_0x0050735c:
    // 0050735c  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050735f  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00507363  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00507365  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507368  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 0050736e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507371  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507377  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507379  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050737f  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507382  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507388  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050738a  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050738c  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050738f  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507392  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507395  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507398  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050739a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050739c  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0050739f  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005073a6  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005073a9  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005073ac  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005073b3  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005073b6  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005073b9  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005073bc  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005073bf  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005073c6  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005073c9  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005073cc  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005073d3  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005073d6  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005073d9  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005073dc  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 005073e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005073e1  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005073e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005073e6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005073ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005073eb  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005073f1  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005073f4  7d0d                   -jge 0x507403
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00507403;
    }
L_0x005073f6:
    // 005073f6  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 005073fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005073fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005073fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005073ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507400  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00507403:
    // 00507403  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00507407  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00507409  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050740c  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507412  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507415  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 0050741b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0050741d  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507423  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507426  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050742c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050742e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507430  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507433  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507436  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507439  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050743c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050743e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507440  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507443  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050744a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050744d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507450  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507457  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050745a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050745d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507460  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507463  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050746a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050746d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507470  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507477  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0050747a  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050747d  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507480  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00507484  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507485  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00507489  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050748a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050748e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050748f  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00507492  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00507495  ff1570a7a000           -call dword ptr [0xa0a770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050749b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050749d  0f8fb9feffff           -jg 0x50735c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050735c;
    }
    // 005074a3  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 005074a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005074aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005074ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005074ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005074ad  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5074b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005074b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005074b1  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 005074b4  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 005074bb  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005074bf  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005074c2  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005074c8  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005074cb  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005074d1  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005074d3  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005074d9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005074dc  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005074e2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005074e4  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005074e6  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005074e9  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005074ec  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005074ef  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005074f2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005074f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005074f6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005074f9  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507500  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507503  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507506  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050750d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507510  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507513  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507516  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507519  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507520  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507523  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507526  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050752d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507530  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507533  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507536  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0050753d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050753f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507542  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507548  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050754b  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507551  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507553  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507559  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050755c  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507562  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507564  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507566  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507569  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050756c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050756f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507572  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507574  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507576  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507579  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507580  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507583  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507586  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050758d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507590  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507593  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507596  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507599  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005075a0  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005075a3  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005075a6  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005075ad  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005075b0  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005075b3  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005075b6  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005075ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005075bb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005075bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005075c0  ff1558a7a000           -call dword ptr [0xa0a758]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005075c6  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 005075c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005075ca  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5075d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005075d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005075d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005075d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005075d3  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 005075d6  8bbc2488000000         -mov edi, dword ptr [esp + 0x88]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 005075dd  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005075e4  8bb42490000000         -mov esi, dword ptr [esp + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 005075eb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005075ed  0f8e21010000           -jle 0x507714
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00507714;
    }
    // 005075f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x005075f4:
    // 005075f4  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 005075f6  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 005075f9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005075fd  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005075ff  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507602  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507608  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050760b  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507611  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507613  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507619  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050761c  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507622  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507624  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507626  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507629  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050762c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050762f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507632  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507634  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507636  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507639  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507640  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507643  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507646  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050764d  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507650  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507653  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507656  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507659  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507660  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507663  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507666  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050766d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507670  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507673  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507676  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00507679  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0050767c  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00507680  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00507682  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507685  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 0050768b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050768e  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507694  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507696  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050769c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050769f  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005076a5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005076a7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005076a9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005076ac  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005076af  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005076b2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005076b5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005076b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005076b9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005076bc  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005076c3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005076c6  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005076c9  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005076d0  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005076d3  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005076d6  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005076d9  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005076dc  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005076e3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005076e6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005076e9  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005076f0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005076f3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005076f6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005076f9  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005076fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005076fe  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00507702  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507703  83c608                 +add esi, 8
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
    // 00507706  ff1558a7a000           -call dword ptr [0xa0a758]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050770c  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050770d  0f85e1feffff           -jne 0x5075f4
    if (!cpu.flags.zf)
    {
        goto L_0x005075f4;
    }
    // 00507713  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00507714:
    // 00507714  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00507717  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507718  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507719  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050771a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_507720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507722  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507723  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00507724  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00507727  8bac248c000000         -mov ebp, dword ptr [esp + 0x8c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0050772e  8bbc2490000000         -mov edi, dword ptr [esp + 0x90]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00507735  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00507737  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00507739  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050773c  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507742  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507745  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 0050774b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0050774d  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507753  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507756  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050775c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050775e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507760  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507763  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507766  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507769  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050776c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050776e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507770  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507773  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050777a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050777d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507780  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507787  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050778a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050778d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507790  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507793  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050779a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050779d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005077a0  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005077a7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005077aa  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005077ad  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005077b0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005077b2  0f8e95000000           -jle 0x50784d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050784d;
    }
    // 005077b8  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x005077bb:
    // 005077bb  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 005077bf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005077c1  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005077c4  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005077ca  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005077cd  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005077d3  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005077d5  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005077db  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005077de  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005077e4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005077e6  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005077e8  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005077eb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005077ee  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005077f1  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005077f4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005077f6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005077f8  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 005077fb  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507802  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507805  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507808  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050780f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507812  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507815  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507818  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0050781b  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507822  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507825  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507828  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050782f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507832  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507835  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507838  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050783c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050783d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00507841  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507842  ff1558a7a000           -call dword ptr [0xa0a758]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507848  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050784b  7d0a                   -jge 0x507857
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00507857;
    }
L_0x0050784d:
    // 0050784d  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00507850  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507851  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507852  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507853  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507854  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00507857:
    // 00507857  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0050785a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050785c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050785e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507861  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507867  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0050786a  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507870  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507872  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507878  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0050787b  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507881  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507883  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507885  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507888  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0050788b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050788e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507891  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507893  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507895  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507898  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050789f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005078a2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 005078a5  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005078ac  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005078af  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005078b2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 005078b5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 005078b8  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005078bf  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005078c2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005078c5  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 005078cc  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005078cf  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005078d2  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005078d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005078d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005078d8  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005078dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005078dd  83c640                 -add esi, 0x40
    (cpu.esi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 005078e0  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005078e3  ff1558a7a000           -call dword ptr [0xa0a758]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005078e9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005078eb  0f8fcafeffff           -jg 0x5077bb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005077bb;
    }
    // 005078f1  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 005078f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005078f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005078f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005078f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005078f8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_507900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507901  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00507904  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00507908  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050790a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050790d  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507913  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507916  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 0050791c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0050791e  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507924  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507927  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 0050792d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050792f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507931  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507934  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507937  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0050793a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050793d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0050793f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507941  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507944  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050794b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0050794e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507951  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507958  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050795b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050795e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507961  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507964  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 0050796b  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050796e  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507971  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507978  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0050797b  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050797e  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507981  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00507983  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507984  ff150ca3a000           -call dword ptr [0xa0a30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527500) /* 0xa0a30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050798a  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0050798d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050798e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_5079a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005079a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005079a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005079a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005079a3  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 005079a6  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 005079aa  8b6c2450               -mov ebp, dword ptr [esp + 0x50]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 005079ae  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 005079b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005079b4  0f8e95000000           -jle 0x507a4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00507a4f;
    }
    // 005079ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x005079bb:
    // 005079bb  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 005079bd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 005079c0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005079c4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005079c6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005079c9  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 005079cf  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 005079d2  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 005079d8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 005079da  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005079e0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 005079e3  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 005079e9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005079eb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005079ed  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005079f0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 005079f3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005079f6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 005079f9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 005079fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005079fd  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507a00  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507a07  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507a0a  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507a0d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507a14  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507a17  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507a1a  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507a1d  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507a20  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507a27  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507a2a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507a2d  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507a34  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507a37  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507a3a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507a3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507a3e  83c704                 +add edi, 4
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
    // 00507a41  ff150ca3a000           -call dword ptr [0xa0a30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527500) /* 0xa0a30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507a47  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00507a48  0f856dffffff           -jne 0x5079bb
    if (!cpu.flags.zf)
    {
        goto L_0x005079bb;
    }
    // 00507a4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00507a4f:
    // 00507a4f  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00507a52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507a53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507a54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507a55  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_507a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507a61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507a62  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00507a65  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00507a69  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00507a6d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00507a6f  0f8e90000000           -jle 0x507b05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00507b05;
    }
    // 00507a75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00507a76:
    // 00507a76  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00507a7a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00507a7c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00507a7f  d80d40825600           -fmul dword ptr [0x568240]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669440) /* 0x568240 */));
    // 00507a85  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00507a88  d80d3c825600           -fmul dword ptr [0x56823c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5669436) /* 0x56823c */));
    // 00507a8e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00507a90  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507a96  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00507a99  d80544825600           -fadd dword ptr [0x568244]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5669444) /* 0x568244 */));
    // 00507a9f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00507aa1  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507aa3  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507aa6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00507aa9  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00507aac  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00507aaf  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00507ab1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507ab3  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00507ab6  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507abd  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00507ac0  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507ac3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507aca  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00507acd  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507ad0  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00507ad3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00507ad6  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507add  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00507ae0  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00507ae3  8b0c9d58a3a000         -mov ecx, dword ptr [ebx*4 + 0xa0a358]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527576) /* 0xa0a358 */ + cpu.ebx * 4);
    // 00507aea  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00507aed  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507af0  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00507af3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507af4  83c620                 +add esi, 0x20
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00507af7  ff150ca3a000           -call dword ptr [0xa0a30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527500) /* 0xa0a30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507afd  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00507afe  0f8572ffffff           -jne 0x507a76
    if (!cpu.flags.zf)
    {
        goto L_0x00507a76;
    }
    // 00507b04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00507b05:
    // 00507b05  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00507b08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507b09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507b0a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_507b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507b11  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00507b15  6884f15400             -push 0x54f184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566852 /*0x54f184*/;
    cpu.esp -= 4;
    // 00507b1a  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507b1c  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507b21  e82a95ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507b26  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00507b29  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00507b2d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00507b33  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00507b35  7505                   -jne 0x507b3c
    if (!cpu.flags.zf)
    {
        goto L_0x00507b3c;
    }
    // 00507b37  bbd0389f00             -mov ebx, 0x9f38d0
    cpu.ebx = 10434768 /*0x9f38d0*/;
L_0x00507b3c:
    // 00507b3c  e8df15ffff             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 00507b41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507b43  743a                   -je 0x507b7f
    if (cpu.flags.zf)
    {
        goto L_0x00507b7f;
    }
    // 00507b45  833b00                 +cmp dword ptr [ebx], 0
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
    // 00507b48  7407                   -je 0x507b51
    if (cpu.flags.zf)
    {
        goto L_0x00507b51;
    }
    // 00507b4a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00507b4c  e8ff51feff             -call 0x4ecd50
    cpu.esp -= 4;
    sub_4ecd50(app, cpu);
    if (cpu.terminate) return;
L_0x00507b51:
    // 00507b51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00507b53  e8983ffeff             -call 0x4ebaf0
    cpu.esp -= 4;
    sub_4ebaf0(app, cpu);
    if (cpu.terminate) return;
    // 00507b58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507b5a  7412                   -je 0x507b6e
    if (cpu.flags.zf)
    {
        goto L_0x00507b6e;
    }
    // 00507b5c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00507b5e  e8ed42feff             -call 0x4ebe50
    cpu.esp -= 4;
    sub_4ebe50(app, cpu);
    if (cpu.terminate) return;
    // 00507b63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507b65  7407                   -je 0x507b6e
    if (cpu.flags.zf)
    {
        goto L_0x00507b6e;
    }
    // 00507b67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507b69  a35c825600             -mov dword ptr [0x56825c], eax
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.eax;
L_0x00507b6e:
    // 00507b6e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00507b70  891558825600           -mov dword ptr [0x568258], edx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.edx;
    // 00507b76  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507b7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507b7c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507b7f:
    // 00507b7f  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00507b85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00507b87  741a                   -je 0x507ba3
    if (cpu.flags.zf)
    {
        goto L_0x00507ba3;
    }
    // 00507b89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507b8a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00507b8c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00507b8d  2eff1598475300         -call dword ptr cs:[0x534798]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457816) /* 0x534798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507b94  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00507b9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507b9b  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507ba2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00507ba3:
    // 00507ba3  c70558825600ffffffff   -mov dword ptr [0x568258], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = 4294967295 /*0xffffffff*/;
    // 00507bad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507bb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507bb3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_507bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507bc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507bc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00507bc2  8b1d58825600           -mov ebx, dword ptr [0x568258]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
    // 00507bc8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00507bcc  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00507bd0  68a0f15400             -push 0x54f1a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566880 /*0x54f1a0*/;
    cpu.esp -= 4;
    // 00507bd5  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507bd7  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507bdc  e86f94ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507be1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00507be4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00507be8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00507bee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00507bf0  7505                   -jne 0x507bf7
    if (!cpu.flags.zf)
    {
        goto L_0x00507bf7;
    }
    // 00507bf2  b9d0389f00             -mov ecx, 0x9f38d0
    cpu.ecx = 10434768 /*0x9f38d0*/;
L_0x00507bf7:
    // 00507bf7  e82415ffff             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 00507bfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507bfe  7515                   -jne 0x507c15
    if (!cpu.flags.zf)
    {
        goto L_0x00507c15;
    }
    // 00507c00  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00507c05  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507c0a  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507c10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c12  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507c15:
    // 00507c15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00507c17  e8b444feff             -call 0x4ec0d0
    cpu.esp -= 4;
    sub_4ec0d0(app, cpu);
    if (cpu.terminate) return;
    // 00507c1c  83fafe                 +cmp edx, -2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00507c1f  751a                   -jne 0x507c3b
    if (!cpu.flags.zf)
    {
        goto L_0x00507c3b;
    }
    // 00507c21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00507c23  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507c25  89155c825600           -mov dword ptr [0x56825c], edx
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.edx;
    // 00507c2b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507c30  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507c36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c38  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507c3b:
    // 00507c3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00507c3d  e82e4cfeff             -call 0x4ec870
    cpu.esp -= 4;
    sub_4ec870(app, cpu);
    if (cpu.terminate) return;
    // 00507c42  83f8ff                 +cmp eax, -1
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
    // 00507c45  7c0c                   -jl 0x507c53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00507c53;
    }
    // 00507c47  8b1d58825600           -mov ebx, dword ptr [0x568258]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
    // 00507c4d  7e38                   -jle 0x507c87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00507c87;
    }
    // 00507c4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507c51  7456                   -je 0x507ca9
    if (cpu.flags.zf)
    {
        goto L_0x00507ca9;
    }
L_0x00507c53:
    // 00507c53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00507c55  e84645feff             -call 0x4ec1a0
    cpu.esp -= 4;
    sub_4ec1a0(app, cpu);
    if (cpu.terminate) return;
    // 00507c5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507c5c  7568                   -jne 0x507cc6
    if (!cpu.flags.zf)
    {
        goto L_0x00507cc6;
    }
    // 00507c5e  833d5c82560000         +cmp dword ptr [0x56825c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00507c65  7578                   -jne 0x507cdf
    if (!cpu.flags.zf)
    {
        goto L_0x00507cdf;
    }
    // 00507c67  bdbcf15400             -mov ebp, 0x54f1bc
    cpu.ebp = 5566908 /*0x54f1bc*/;
    // 00507c6c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00507c71  892d5c825600           -mov dword ptr [0x56825c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.ebp;
    // 00507c77  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507c7c  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507c82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c84  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507c87:
    // 00507c87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507c88  bebcf15400             -mov esi, 0x54f1bc
    cpu.esi = 5566908 /*0x54f1bc*/;
    // 00507c8d  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00507c92  89355c825600           -mov dword ptr [0x56825c], esi
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.esi;
    // 00507c98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507c99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507c9e  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507ca4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ca6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507ca9:
    // 00507ca9  b9c4f15400             -mov ecx, 0x54f1c4
    cpu.ecx = 5566916 /*0x54f1c4*/;
    // 00507cae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507cb0  890d5c825600           -mov dword ptr [0x56825c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.ecx;
    // 00507cb6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507cbb  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507cc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507cc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507cc3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507cc6:
    // 00507cc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507cc8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507cca  a35c825600             -mov dword ptr [0x56825c], eax
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.eax;
    // 00507ccf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507cd4  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507cda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507cdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507cdc  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00507cdf:
    // 00507cdf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507ce1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507ce6  891d58825600           -mov dword ptr [0x568258], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebx;
    // 00507cec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ced  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507cee  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_507d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507d01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00507d02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507d03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507d04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00507d05  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00507d07  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00507d09  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00507d0e  b9ccf15400             -mov ecx, 0x54f1cc
    cpu.ecx = 5566924 /*0x54f1cc*/;
    // 00507d13  891558825600           -mov dword ptr [0x568258], edx
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.edx;
    // 00507d19  890d5c825600           -mov dword ptr [0x56825c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */) = cpu.ecx;
    // 00507d1f  e86c30feff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00507d24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507d25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507d26  68d4f15400             -push 0x54f1d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566932 /*0x54f1d4*/;
    cpu.esp -= 4;
    // 00507d2b  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00507d2d  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507d32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507d34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00507d36  e81593ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507d3b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00507d3e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00507d40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00507d42  e8794afcff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
    // 00507d47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507d49  0f8441010000           -je 0x507e90
    if (cpu.flags.zf)
    {
        goto L_0x00507e90;
    }
    // 00507d4f  68f8f15400             -push 0x54f1f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566968 /*0x54f1f8*/;
    cpu.esp -= 4;
    // 00507d54  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507d56  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507d5b  e8f092ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507d60  8b2d58825600           -mov ebp, dword ptr [0x568258]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
    // 00507d66  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00507d69  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00507d6b  744e                   -je 0x507dbb
    if (cpu.flags.zf)
    {
        goto L_0x00507dbb;
    }
    // 00507d6d  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00507d72:
    // 00507d72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00507d77  e8647bfdff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 00507d7c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507d7e  e8ad7bfdff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00507d83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507d85  7407                   -je 0x507d8e
    if (cpu.flags.zf)
    {
        goto L_0x00507d8e;
    }
    // 00507d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507d89  e8a2f8fdff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x00507d8e:
    // 00507d8e  833d5882560000         +cmp dword ptr [0x568258], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00507d95  7c54                   -jl 0x507deb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00507deb;
    }
L_0x00507d97:
    // 00507d97  a158825600             -mov eax, dword ptr [0x568258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
    // 00507d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507d9d  68a8f25400             -push 0x54f2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567144 /*0x54f2a8*/;
    cpu.esp -= 4;
    // 00507da2  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00507da4  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507da9  e8a292ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507dae  8b1558825600           -mov edx, dword ptr [0x568258]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */);
    // 00507db4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00507db7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00507db9  75b7                   -jne 0x507d72
    if (!cpu.flags.zf)
    {
        goto L_0x00507d72;
    }
L_0x00507dbb:
    // 00507dbb  8b0d5c825600           -mov ecx, dword ptr [0x56825c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */);
    // 00507dc1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00507dc3  0f84bd000000           -je 0x507e86
    if (cpu.flags.zf)
    {
        goto L_0x00507e86;
    }
    // 00507dc9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00507dcb:
    // 00507dcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507dcc  68ccf25400             -push 0x54f2cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567180 /*0x54f2cc*/;
    cpu.esp -= 4;
    // 00507dd1  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00507dd3  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507dd8  e87392ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507ddd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00507de0  a15c825600             -mov eax, dword ptr [0x56825c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */);
    // 00507de5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507de6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507de7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507de8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507de9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507dea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00507deb:
    // 00507deb  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00507df0  e8eb7afdff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 00507df5  e82613ffff             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 00507dfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507dfc  746f                   -je 0x507e6d
    if (cpu.flags.zf)
    {
        goto L_0x00507e6d;
    }
    // 00507dfe  6810f25400             -push 0x54f210
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566992 /*0x54f210*/;
    cpu.esp -= 4;
    // 00507e03  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507e05  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507e0a  e84192ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507e0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00507e12  a1243d9f00             -mov eax, dword ptr [0x9f3d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 00507e17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507e18  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507e1a  892d58825600           -mov dword ptr [0x568258], ebp
    app->getMemory<x86::reg32>(x86::reg32(5669464) /* 0x568258 */) = cpu.ebp;
    // 00507e20  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507e27  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00507e29  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00507e2b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00507e2d  e88e49fcff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
    // 00507e32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507e34  0f855dffffff           -jne 0x507d97
    if (!cpu.flags.zf)
    {
        goto L_0x00507d97;
    }
    // 00507e3a  ba2cf25400             -mov edx, 0x54f22c
    cpu.edx = 5567020 /*0x54f22c*/;
    // 00507e3f  b93cf25400             -mov ecx, 0x54f23c
    cpu.ecx = 5567036 /*0x54f23c*/;
    // 00507e44  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
    // 00507e49  6850f25400             -push 0x54f250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567056 /*0x54f250*/;
    cpu.esp -= 4;
    // 00507e4e  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00507e54  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00507e5a  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00507e60  e8ab91efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00507e65  83c404                 +add esp, 4
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
    // 00507e68  e92affffff             -jmp 0x507d97
    goto L_0x00507d97;
L_0x00507e6d:
    // 00507e6d  688cf25400             -push 0x54f28c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567116 /*0x54f28c*/;
    cpu.esp -= 4;
    // 00507e72  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507e74  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507e79  e8d291ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507e7e  83c40c                 +add esp, 0xc
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
    // 00507e81  e911ffffff             -jmp 0x507d97
    goto L_0x00507d97;
L_0x00507e86:
    // 00507e86  b8c4f25400             -mov eax, 0x54f2c4
    cpu.eax = 5567172 /*0x54f2c4*/;
    // 00507e8b  e93bffffff             -jmp 0x507dcb
    goto L_0x00507dcb;
L_0x00507e90:
    // 00507e90  bb2cf25400             -mov ebx, 0x54f22c
    cpu.ebx = 5567020 /*0x54f22c*/;
    // 00507e95  be3cf25400             -mov esi, 0x54f23c
    cpu.esi = 5567036 /*0x54f23c*/;
    // 00507e9a  bf99000000             -mov edi, 0x99
    cpu.edi = 153 /*0x99*/;
    // 00507e9f  6850f25400             -push 0x54f250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567056 /*0x54f250*/;
    cpu.esp -= 4;
    // 00507ea4  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00507eaa  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00507eb0  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00507eb6  e85591efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00507ebb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00507ebe  a15c825600             -mov eax, dword ptr [0x56825c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669468) /* 0x56825c */);
    // 00507ec3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ec4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ec5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ec6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ec7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ec8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_507ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00507ed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00507ed3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507ed4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507ed6  e8557afdff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00507edb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00507edd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507edf  7511                   -jne 0x507ef2
    if (!cpu.flags.zf)
    {
        goto L_0x00507ef2;
    }
    // 00507ee1  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00507ee7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00507ee9  750e                   -jne 0x507ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00507ef9;
    }
L_0x00507eeb:
    // 00507eeb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00507eed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507eee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507eef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ef0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507ef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00507ef2:
    // 00507ef2  e819060000             -call 0x508510
    cpu.esp -= 4;
    sub_508510(app, cpu);
    if (cpu.terminate) return;
    // 00507ef7  ebf2                   -jmp 0x507eeb
    goto L_0x00507eeb;
L_0x00507ef9:
    // 00507ef9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00507efa  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507f00  8b35243d9f00           -mov esi, dword ptr [0x9f3d24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 00507f06  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00507f0c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00507f0e  74db                   -je 0x507eeb
    if (cpu.flags.zf)
    {
        goto L_0x00507eeb;
    }
    // 00507f10  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00507f12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507f13  2eff1598475300         -call dword ptr cs:[0x534798]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457816) /* 0x534798 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00507f1a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00507f1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_507f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00507f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00507f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00507f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00507f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507f34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507f35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00507f36  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00507f39  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00507f3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00507f3d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00507f41:
    // 00507f41  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00507f48  7551                   -jne 0x507f9b
    if (!cpu.flags.zf)
    {
        goto L_0x00507f9b;
    }
    // 00507f4a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00507f4f  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 00507f54  e8a7fdffff             -call 0x507d00
    cpu.esp -= 4;
    sub_507d00(app, cpu);
    if (cpu.terminate) return;
    // 00507f59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507f5b  0f85ac010000           -jne 0x50810d
    if (!cpu.flags.zf)
    {
        goto L_0x0050810d;
    }
L_0x00507f61:
    // 00507f61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00507f66:
    // 00507f66  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00507f6a:
    // 00507f6a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00507f6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00507f6f  68acf35400             -push 0x54f3ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567404 /*0x54f3ac*/;
    cpu.esp -= 4;
    // 00507f74  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00507f76  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507f7b  e8d090ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507f80  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00507f83  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00507f85  0f84c0010000           -je 0x50814b
    if (cpu.flags.zf)
    {
        goto L_0x0050814b;
    }
    // 00507f8b  74b4                   -je 0x507f41
    if (cpu.flags.zf)
    {
        goto L_0x00507f41;
    }
    // 00507f8d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00507f91  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00507f94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00507f9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00507f9b:
    // 00507f9b  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00507f9e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00507fa2  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00507fa5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507fa6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00507faa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00507fab  8b7b14                 -mov edi, dword ptr [ebx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00507fae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00507faf  68ecf25400             -push 0x54f2ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567212 /*0x54f2ec*/;
    cpu.esp -= 4;
    // 00507fb4  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00507fb6  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00507fbb  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00507fbf  e88c90ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00507fc4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00507fc7  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00507fcc  759c                   -jne 0x507f6a
    if (!cpu.flags.zf)
    {
        goto L_0x00507f6a;
    }
L_0x00507fce:
    // 00507fce  bda0860100             -mov ebp, 0x186a0
    cpu.ebp = 100000 /*0x186a0*/;
    // 00507fd3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00507fd6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00507fd8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00507fdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00507fde  0f8e6a000000           -jle 0x50804e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050804e;
    }
    // 00507fe4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00507fe6:
    // 00507fe6  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00507fe9  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00507feb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00507fed  8a4212                 -mov al, byte ptr [edx + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00507ff0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507ff1  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00507ff4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507ff5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00507ff7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507ff8  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00507ffb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00507ffc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00507ffd  681cf35400             -push 0x54f31c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567260 /*0x54f31c*/;
    cpu.esp -= 4;
    // 00508002  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508004  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508009  e84290ffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0050800e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508010  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00508013  8a4212                 -mov al, byte ptr [edx + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00508016  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00508019  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050801d  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00508020  7521                   -jne 0x508043
    if (!cpu.flags.zf)
    {
        goto L_0x00508043;
    }
    // 00508022  f6420f80               +test byte ptr [edx + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */) & 128 /*0x80*/));
    // 00508026  751b                   -jne 0x508043
    if (!cpu.flags.zf)
    {
        goto L_0x00508043;
    }
    // 00508028  3b3a                   +cmp edi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050802a  7717                   -ja 0x508043
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00508043;
    }
    // 0050802c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00508030  3b4204                 +cmp eax, dword ptr [edx + 4]
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
    // 00508033  770e                   -ja 0x508043
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00508043;
    }
    // 00508035  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00508037  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00508039  39ea                   +cmp edx, ebp
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
    // 0050803b  7306                   -jae 0x508043
    if (!cpu.flags.cf)
    {
        goto L_0x00508043;
    }
    // 0050803d  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00508041  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x00508043:
    // 00508043  41                     -inc ecx
    (cpu.ecx)++;
    // 00508044  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00508047  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050804a  39c1                   +cmp ecx, eax
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
    // 0050804c  7c98                   -jl 0x507fe6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00507fe6;
    }
L_0x0050804e:
    // 0050804e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00508052  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508053  6840f35400             -push 0x54f340
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567296 /*0x54f340*/;
    cpu.esp -= 4;
    // 00508058  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0050805a  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 0050805f  e8ec8fffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508064  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00508067  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050806a  39ca                   +cmp edx, ecx
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
    // 0050806c  7c3f                   -jl 0x5080ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005080ad;
    }
    // 0050806e  81ff40010000           +cmp edi, 0x140
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508074  7665                   -jbe 0x5080db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005080db;
    }
    // 00508076  685cf35400             -push 0x54f35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567324 /*0x54f35c*/;
    cpu.esp -= 4;
    // 0050807b  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0050807d  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508082  e8c98fffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508087  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050808a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050808e  2dc8000000             -sub eax, 0xc8
    (cpu.eax) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 00508093  81efc8000000           -sub edi, 0xc8
    (cpu.edi) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 00508099  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050809d:
    // 0050809d  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 005080a2  0f8426ffffff           -je 0x507fce
    if (cpu.flags.zf)
    {
        goto L_0x00507fce;
    }
    // 005080a8  e9bdfeffff             -jmp 0x507f6a
    goto L_0x00507f6a;
L_0x005080ad:
    // 005080ad  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 005080b2  e849fcffff             -call 0x507d00
    cpu.esp -= 4;
    sub_507d00(app, cpu);
    if (cpu.terminate) return;
    // 005080b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005080b9  751c                   -jne 0x5080d7
    if (!cpu.flags.zf)
    {
        goto L_0x005080d7;
    }
    // 005080bb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005080c0:
    // 005080c0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005080c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005080c6  75d5                   -jne 0x50809d
    if (!cpu.flags.zf)
    {
        goto L_0x0050809d;
    }
    // 005080c8  6b44241014             -imul eax, dword ptr [esp + 0x10], 0x14
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 005080cd  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 005080d0  804c020f80             +or byte ptr [edx + eax + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 005080d5  ebc6                   -jmp 0x50809d
    goto L_0x0050809d;
L_0x005080d7:
    // 005080d7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005080d9  ebe5                   -jmp 0x5080c0
    goto L_0x005080c0;
L_0x005080db:
    // 005080db  837c240808             +cmp dword ptr [esp + 8], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005080e0  7532                   -jne 0x508114
    if (!cpu.flags.zf)
    {
        goto L_0x00508114;
    }
    // 005080e2  6884f35400             -push 0x54f384
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567364 /*0x54f384*/;
    cpu.esp -= 4;
    // 005080e7  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 005080e9  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 005080ee  e85d8fffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 005080f3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005080f6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 005080fb  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 00508100  e8fbfbffff             -call 0x507d00
    cpu.esp -= 4;
    sub_507d00(app, cpu);
    if (cpu.terminate) return;
    // 00508105  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508107  0f8454feffff           -je 0x507f61
    if (cpu.flags.zf)
    {
        goto L_0x00507f61;
    }
L_0x0050810d:
    // 0050810d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050810f  e952feffff             -jmp 0x507f66
    goto L_0x00507f66;
L_0x00508114:
    // 00508114  6870f35400             -push 0x54f370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567344 /*0x54f370*/;
    cpu.esp -= 4;
    // 00508119  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0050811b  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508120  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 00508125  e8268fffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0050812a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050812d  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00508130  8b7b14                 -mov edi, dword ptr [ebx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00508133  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00508137  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0050813b  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00508140  0f8488feffff           -je 0x507fce
    if (cpu.flags.zf)
    {
        goto L_0x00507fce;
    }
    // 00508146  e91ffeffff             -jmp 0x507f6a
    goto L_0x00507f6a;
L_0x0050814b:
    // 0050814b  68c0f35400             -push 0x54f3c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567424 /*0x54f3c0*/;
    cpu.esp -= 4;
    // 00508150  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00508152  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508157  e8f48effff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0050815c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050815f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00508163  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00508166  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508167  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508168  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508169  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050816a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050816b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050816c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_508170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508173  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508174  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00508176  8b0dfc445600           -mov ecx, dword ptr [0x5644fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653756) /* 0x5644fc */);
    // 0050817c  8a152d3d9f00           -mov dl, byte ptr [0x9f3d2d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 00508182  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508184  0f84a4000000           -je 0x50822e
    if (cpu.flags.zf)
    {
        goto L_0x0050822e;
    }
L_0x0050818a:
    // 0050818a  f6059043560001         +test byte ptr [0x564390], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */) & 1 /*0x1*/));
    // 00508191  0f84ce000000           -je 0x508265
    if (cpu.flags.zf)
    {
        goto L_0x00508265;
    }
    // 00508197  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00508199:
    // 00508199  8a1d90435600           -mov bl, byte ptr [0x564390]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 0050819f  a22d3d9f00             -mov byte ptr [0x9f3d2d], al
    app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */) = cpu.al;
    // 005081a4  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 005081a7  0f84bf000000           -je 0x50826c
    if (cpu.flags.zf)
    {
        goto L_0x0050826c;
    }
    // 005081ad  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 005081af  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 005081b1  b302                   -mov bl, 2
    cpu.bl = 2 /*0x2*/;
    // 005081b3  880d053d9f00           -mov byte ptr [0x9f3d05], cl
    app->getMemory<x86::reg8>(x86::reg32(10435845) /* 0x9f3d05 */) = cpu.cl;
    // 005081b9  880d043d9f00           -mov byte ptr [0x9f3d04], cl
    app->getMemory<x86::reg8>(x86::reg32(10435844) /* 0x9f3d04 */) = cpu.cl;
    // 005081bf  88252e3d9f00           -mov byte ptr [0x9f3d2e], ah
    app->getMemory<x86::reg8>(x86::reg32(10435886) /* 0x9f3d2e */) = cpu.ah;
    // 005081c5  881d073d9f00           -mov byte ptr [0x9f3d07], bl
    app->getMemory<x86::reg8>(x86::reg32(10435847) /* 0x9f3d07 */) = cpu.bl;
    // 005081cb  881d333d9f00           -mov byte ptr [0x9f3d33], bl
    app->getMemory<x86::reg8>(x86::reg32(10435891) /* 0x9f3d33 */) = cpu.bl;
    // 005081d1  880d063d9f00           -mov byte ptr [0x9f3d06], cl
    app->getMemory<x86::reg8>(x86::reg32(10435846) /* 0x9f3d06 */) = cpu.cl;
L_0x005081d7:
    // 005081d7  a1f4435600             -mov eax, dword ptr [0x5643f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 005081dc  8b2d64435600           -mov ebp, dword ptr [0x564364]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
    // 005081e2  a3f0389f00             -mov dword ptr [0x9f38f0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434800) /* 0x9f38f0 */) = cpu.eax;
    // 005081e7  83fd07                 +cmp ebp, 7
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
    // 005081ea  7424                   -je 0x508210
    if (cpu.flags.zf)
    {
        goto L_0x00508210;
    }
    // 005081ec  e84f170000             -call 0x509940
    cpu.esp -= 4;
    sub_509940(app, cpu);
    if (cpu.terminate) return;
    // 005081f1  b810855000             -mov eax, 0x508510
    cpu.eax = 5276944 /*0x508510*/;
    // 005081f6  b9d07e5000             -mov ecx, 0x507ed0
    cpu.ecx = 5275344 /*0x507ed0*/;
    // 005081fb  e878a8feff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 00508200  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00508205  890d18445600           -mov dword ptr [0x564418], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */) = cpu.ecx;
    // 0050820b  a364435600             -mov dword ptr [0x564364], eax
    app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */) = cpu.eax;
L_0x00508210:
    // 00508210  e87b2bfeff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00508215  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508217  a02d3d9f00             -mov al, byte ptr [0x9f3d2d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 0050821c  39c2                   +cmp edx, eax
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
    // 0050821e  0f84bd000000           -je 0x5082e1
    if (cpu.flags.zf)
    {
        goto L_0x005082e1;
    }
    // 00508224  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00508229  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050822a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050822b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050822c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050822d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050822e:
    // 0050822e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050822f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508230  bb2cf25400             -mov ebx, 0x54f22c
    cpu.ebx = 5567020 /*0x54f22c*/;
    // 00508235  bee0f35400             -mov esi, 0x54f3e0
    cpu.esi = 5567456 /*0x54f3e0*/;
    // 0050823a  bf0c010000             -mov edi, 0x10c
    cpu.edi = 268 /*0x10c*/;
    // 0050823f  68f0f35400             -push 0x54f3f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567472 /*0x54f3f0*/;
    cpu.esp -= 4;
    // 00508244  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050824a  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00508250  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00508256  e8b58defff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050825b  83c404                 +add esp, 4
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
    // 0050825e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050825f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508260  e925ffffff             -jmp 0x50818a
    goto L_0x0050818a;
L_0x00508265:
    // 00508265  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00508267  e92dffffff             -jmp 0x508199
    goto L_0x00508199;
L_0x0050826c:
    // 0050826c  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0050826f  7451                   -je 0x5082c2
    if (cpu.flags.zf)
    {
        goto L_0x005082c2;
    }
    // 00508271  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00508273:
    // 00508273  8a0d90435600           -mov cl, byte ptr [0x564390]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 00508279  a2063d9f00             -mov byte ptr [0x9f3d06], al
    app->getMemory<x86::reg8>(x86::reg32(10435846) /* 0x9f3d06 */) = cpu.al;
    // 0050827e  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00508281  7443                   -je 0x5082c6
    if (cpu.flags.zf)
    {
        goto L_0x005082c6;
    }
    // 00508283  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00508285:
    // 00508285  8a2d90435600           -mov ch, byte ptr [0x564390]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 0050828b  a2053d9f00             -mov byte ptr [0x9f3d05], al
    app->getMemory<x86::reg8>(x86::reg32(10435845) /* 0x9f3d05 */) = cpu.al;
    // 00508290  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00508293  7435                   -je 0x5082ca
    if (cpu.flags.zf)
    {
        goto L_0x005082ca;
    }
    // 00508295  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00508297:
    // 00508297  a2043d9f00             -mov byte ptr [0x9f3d04], al
    app->getMemory<x86::reg8>(x86::reg32(10435844) /* 0x9f3d04 */) = cpu.al;
    // 0050829c  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0050829e  a22e3d9f00             -mov byte ptr [0x9f3d2e], al
    app->getMemory<x86::reg8>(x86::reg32(10435886) /* 0x9f3d2e */) = cpu.al;
    // 005082a3  a094435600             -mov al, byte ptr [0x564394]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5653396) /* 0x564394 */);
    // 005082a8  a2073d9f00             -mov byte ptr [0x9f3d07], al
    app->getMemory<x86::reg8>(x86::reg32(10435847) /* 0x9f3d07 */) = cpu.al;
    // 005082ad  f6059043560040         +test byte ptr [0x564390], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */) & 64 /*0x40*/));
    // 005082b4  7418                   -je 0x5082ce
    if (cpu.flags.zf)
    {
        goto L_0x005082ce;
    }
L_0x005082b6:
    // 005082b6  c605333d9f0001         -mov byte ptr [0x9f3d33], 1
    app->getMemory<x86::reg8>(x86::reg32(10435891) /* 0x9f3d33 */) = 1 /*0x1*/;
    // 005082bd  e915ffffff             -jmp 0x5081d7
    goto L_0x005081d7;
L_0x005082c2:
    // 005082c2  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 005082c4  ebad                   -jmp 0x508273
    goto L_0x00508273;
L_0x005082c6:
    // 005082c6  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 005082c8  ebbb                   -jmp 0x508285
    goto L_0x00508285;
L_0x005082ca:
    // 005082ca  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 005082cc  ebc9                   -jmp 0x508297
    goto L_0x00508297;
L_0x005082ce:
    // 005082ce  803d063d9f0000         +cmp byte ptr [0x9f3d06], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435846) /* 0x9f3d06 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005082d5  75df                   -jne 0x5082b6
    if (!cpu.flags.zf)
    {
        goto L_0x005082b6;
    }
    // 005082d7  a2333d9f00             -mov byte ptr [0x9f3d33], al
    app->getMemory<x86::reg8>(x86::reg32(10435891) /* 0x9f3d33 */) = cpu.al;
    // 005082dc  e9f6feffff             -jmp 0x5081d7
    goto L_0x005081d7;
L_0x005082e1:
    // 005082e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005082e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005082e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005082e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005082e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005082e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_5082f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005082f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005082f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005082f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005082f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005082f5  a02c3d9f00             -mov al, byte ptr [0x9f3d2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435884) /* 0x9f3d2c */);
    // 005082fa  8b151c3d9f00           -mov edx, dword ptr [0x9f3d1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435868) /* 0x9f3d1c */);
    // 00508300  a38c435600             -mov dword ptr [0x56438c], eax
    app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */) = cpu.eax;
    // 00508305  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508307  7405                   -je 0x50830e
    if (cpu.flags.zf)
    {
        goto L_0x0050830e;
    }
    // 00508309  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0050830e:
    // 0050830e  833d203d9f0000         +cmp dword ptr [0x9f3d20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435872) /* 0x9f3d20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508315  7470                   -je 0x508387
    if (cpu.flags.zf)
    {
        goto L_0x00508387;
    }
    // 00508317  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050831c:
    // 0050831c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050831e  a1e4389f00             -mov eax, dword ptr [0x9f38e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */);
    // 00508323  a384435600             -mov dword ptr [0x564384], eax
    app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */) = cpu.eax;
    // 00508328  a1e8389f00             -mov eax, dword ptr [0x9f38e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */);
    // 0050832d  a388435600             -mov dword ptr [0x564388], eax
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.eax;
    // 00508332  a1dc389f00             -mov eax, dword ptr [0x9f38dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434780) /* 0x9f38dc */);
    // 00508337  8b1d9c435600           -mov ebx, dword ptr [0x56439c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653404) /* 0x56439c */);
    // 0050833d  a398435600             -mov dword ptr [0x564398], eax
    app->getMemory<x86::reg32>(x86::reg32(5653400) /* 0x564398 */) = cpu.eax;
    // 00508342  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00508347  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508349  8b35a0435600           -mov esi, dword ptr [0x5643a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653408) /* 0x5643a0 */);
    // 0050834f  a3a4435600             -mov dword ptr [0x5643a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653412) /* 0x5643a4 */) = cpu.eax;
    // 00508354  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00508359  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0050835b  a3a8435600             -mov dword ptr [0x5643a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653416) /* 0x5643a8 */) = cpu.eax;
    // 00508360  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508362  a0333d9f00             -mov al, byte ptr [0x9f3d33]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435891) /* 0x9f3d33 */);
    // 00508367  a350825600             -mov dword ptr [0x568250], eax
    app->getMemory<x86::reg32>(x86::reg32(5669456) /* 0x568250 */) = cpu.eax;
    // 0050836c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050836e  a0323d9f00             -mov al, byte ptr [0x9f3d32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435890) /* 0x9f3d32 */);
    // 00508373  891594435600           -mov dword ptr [0x564394], edx
    app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */) = cpu.edx;
    // 00508379  a354825600             -mov dword ptr [0x568254], eax
    app->getMemory<x86::reg32>(x86::reg32(5669460) /* 0x568254 */) = cpu.eax;
    // 0050837e  e80d2afeff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00508383  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508384  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508386  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508387:
    // 00508387  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00508389  eb91                   -jmp 0x50831c
    goto L_0x0050831c;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_508390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00508391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508394  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00508395  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00508397  8b15d0389f00           -mov edx, dword ptr [0x9f38d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 0050839d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050839f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005083a1  0f8509010000           -jne 0x5084b0
    if (!cpu.flags.zf)
    {
        goto L_0x005084b0;
    }
    // 005083a7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x005083ac:
    // 005083ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005083ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005083b0  0f8401010000           -je 0x5084b7
    if (cpu.flags.zf)
    {
        goto L_0x005084b7;
    }
L_0x005083b6:
    // 005083b6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x005083bb:
    // 005083bb  68107b5000             -push 0x507b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5274384 /*0x507b10*/;
    cpu.esp -= 4;
    // 005083c0  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 005083c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005083c7  e80443fcff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 005083cc  68c07b5000             -push 0x507bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5274560 /*0x507bc0*/;
    cpu.esp -= 4;
    // 005083d1  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 005083d6  e8f542fcff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 005083db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005083dd  7444                   -je 0x508423
    if (cpu.flags.zf)
    {
        goto L_0x00508423;
    }
    // 005083df  803d2d3d9f0000         +cmp byte ptr [0x9f3d2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005083e6  743b                   -je 0x508423
    if (cpu.flags.zf)
    {
        goto L_0x00508423;
    }
    // 005083e8  6828f45400             -push 0x54f428
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567528 /*0x54f428*/;
    cpu.esp -= 4;
    // 005083ed  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 005083ef  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 005083f4  e8578cffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 005083f9  8b0de4389f00           -mov ecx, dword ptr [0x9f38e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */);
    // 005083ff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00508402  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508404  750a                   -jne 0x508410
    if (!cpu.flags.zf)
    {
        goto L_0x00508410;
    }
    // 00508406  c705e4389f0080020000   -mov dword ptr [0x9f38e4], 0x280
    app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */) = 640 /*0x280*/;
L_0x00508410:
    // 00508410  833de8389f0000         +cmp dword ptr [0x9f38e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00508417  750a                   -jne 0x508423
    if (!cpu.flags.zf)
    {
        goto L_0x00508423;
    }
    // 00508419  c705e8389f00e0010000   -mov dword ptr [0x9f38e8], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */) = 480 /*0x1e0*/;
L_0x00508423:
    // 00508423  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00508425  744c                   -je 0x508473
    if (cpu.flags.zf)
    {
        goto L_0x00508473;
    }
    // 00508427  6848f45400             -push 0x54f448
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567560 /*0x54f448*/;
    cpu.esp -= 4;
    // 0050842c  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0050842e  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508433  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00508435  e8168cffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0050843a  8a1d2d3d9f00           -mov bl, byte ptr [0x9f3d2d]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 00508440  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00508443  8b15e8389f00           -mov edx, dword ptr [0x9f38e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */);
    // 00508449  a1e4389f00             -mov eax, dword ptr [0x9f38e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */);
    // 0050844e  e86d52fcff             -call 0x4cd6c0
    cpu.esp -= 4;
    sub_4cd6c0(app, cpu);
    if (cpu.terminate) return;
    // 00508453  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00508455  746d                   -je 0x5084c4
    if (cpu.flags.zf)
    {
        goto L_0x005084c4;
    }
    // 00508457  b864040000             -mov eax, 0x464
    cpu.eax = 1124 /*0x464*/;
    // 0050845c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050845e  e89df8ffff             -call 0x507d00
    cpu.esp -= 4;
    sub_507d00(app, cpu);
    if (cpu.terminate) return;
    // 00508463  8b0d243d9f00           -mov ecx, dword ptr [0x9f3d24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 00508469  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050846a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050846c  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00508473:
    // 00508473  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00508475  7411                   -je 0x508488
    if (cpu.flags.zf)
    {
        goto L_0x00508488;
    }
    // 00508477  bb308c5600             -mov ebx, 0x568c30
    cpu.ebx = 5671984 /*0x568c30*/;
    // 0050847c  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00508481  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508483  e8c8b9ffff             -call 0x503e50
    cpu.esp -= 4;
    sub_503e50(app, cpu);
    if (cpu.terminate) return;
L_0x00508488:
    // 00508488  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050848a  7415                   -je 0x5084a1
    if (cpu.flags.zf)
    {
        goto L_0x005084a1;
    }
    // 0050848c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050848d  6868f45400             -push 0x54f468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567592 /*0x54f468*/;
    cpu.esp -= 4;
    // 00508492  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00508494  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508499  e8b28bffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 0050849e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x005084a1:
    // 005084a1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005084a3  7526                   -jne 0x5084cb
    if (!cpu.flags.zf)
    {
        goto L_0x005084cb;
    }
    // 005084a5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005084aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005084b0:
    // 005084b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005084b2  e9f5feffff             -jmp 0x5083ac
    goto L_0x005083ac;
L_0x005084b7:
    // 005084b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005084b9  0f85f7feffff           -jne 0x5083b6
    if (!cpu.flags.zf)
    {
        goto L_0x005083b6;
    }
    // 005084bf  e9f7feffff             -jmp 0x5083bb
    goto L_0x005083bb;
L_0x005084c4:
    // 005084c4  be60f45400             -mov esi, 0x54f460
    cpu.esi = 5567584 /*0x54f460*/;
    // 005084c9  eba8                   -jmp 0x508473
    goto L_0x00508473;
L_0x005084cb:
    // 005084cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005084cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5084e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005084e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005084e1  8b15dc389f00           -mov edx, dword ptr [0x9f38dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434780) /* 0x9f38dc */);
    // 005084e7  e8b455fcff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
    // 005084ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005084ee  e87d040000             -call 0x508970
    cpu.esp -= 4;
    sub_508970(app, cpu);
    if (cpu.terminate) return;
    // 005084f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005084f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_508500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508500  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00508505  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_508510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00508511  e87a28feff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00508516  833dc47d560000         +cmp dword ptr [0x567dc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668292) /* 0x567dc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050851d  0f8574000000           -jne 0x508597
    if (!cpu.flags.zf)
    {
        goto L_0x00508597;
    }
    // 00508523  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00508524  6890f45400             -push 0x54f490
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567632 /*0x54f490*/;
    cpu.esp -= 4;
    // 00508529  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0050852b  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 00508530  e81b8bffff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508535  8b0d243d9f00           -mov ecx, dword ptr [0x9f3d24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 0050853b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050853e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00508540  7405                   -je 0x508547
    if (cpu.flags.zf)
    {
        goto L_0x00508547;
    }
    // 00508542  e85955fcff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00508547:
    // 00508547  833d6443560007         +cmp dword ptr [0x564364], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050854e  7530                   -jne 0x508580
    if (!cpu.flags.zf)
    {
        goto L_0x00508580;
    }
    // 00508550  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00508551  8b35f0435600           -mov esi, dword ptr [0x5643f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
    // 00508557  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00508559  7411                   -je 0x50856c
    if (cpu.flags.zf)
    {
        goto L_0x0050856c;
    }
    // 0050855b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050855c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050855e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00508560  e89b79feff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 00508565  893df0435600           -mov dword ptr [0x5643f0], edi
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.edi;
    // 0050856b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050856c:
    // 0050856c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050856e  e88d140000             -call 0x509a00
    cpu.esp -= 4;
    sub_509a00(app, cpu);
    if (cpu.terminate) return;
    // 00508573  892d64435600           -mov dword ptr [0x564364], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */) = cpu.ebp;
    // 00508579  892d18445600           -mov dword ptr [0x564418], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */) = cpu.ebp;
    // 0050857f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00508580:
    // 00508580  68acf45400             -push 0x54f4ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5567660 /*0x54f4ac*/;
    cpu.esp -= 4;
    // 00508585  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00508587  68d44e5600             -push 0x564ed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 0050858c  e8bf8affff             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 00508591  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00508594  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508595  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508596  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508597:
    // 00508597  ff15c47d5600           -call dword ptr [0x567dc4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668292) /* 0x567dc4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050859d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050859e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5085a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005085a0  833dd0389f0000         +cmp dword ptr [0x9f38d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005085a7  7406                   -je 0x5085af
    if (cpu.flags.zf)
    {
        goto L_0x005085af;
    }
    // 005085a9  a1d8389f00             -mov eax, dword ptr [0x9f38d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434776) /* 0x9f38d8 */);
    // 005085ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005085af:
    // 005085af  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005085b4  e8b7030000             -call 0x508970
    cpu.esp -= 4;
    sub_508970(app, cpu);
    if (cpu.terminate) return;
    // 005085b9  a1d8389f00             -mov eax, dword ptr [0x9f38d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434776) /* 0x9f38d8 */);
    // 005085be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5085c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005085c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005085c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005085c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005085c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005085c4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005085c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005085c8  833dd0389f0000         +cmp dword ptr [0x9f38d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005085cf  750a                   -jne 0x5085db
    if (!cpu.flags.zf)
    {
        goto L_0x005085db;
    }
    // 005085d1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005085d6  e895030000             -call 0x508970
    cpu.esp -= 4;
    sub_508970(app, cpu);
    if (cpu.terminate) return;
L_0x005085db:
    // 005085db  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 005085e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005085e2  e82581fdff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 005085e7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005085e9  0f8cbe020000           -jl 0x5088ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005088ad;
    }
    // 005085ef  3b1dd8389f00           +cmp ebx, dword ptr [0x9f38d8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10434776) /* 0x9f38d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005085f5  0f8db2020000           -jge 0x5088ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005088ad;
    }
    // 005085fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005085fc  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508603  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00508606  a1e0389f00             -mov eax, dword ptr [0x9f38e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 0050860b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0050860e  8b3402                 -mov esi, dword ptr [edx + eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 00508611  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00508613  8b740204               -mov esi, dword ptr [edx + eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00508617  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0050861a  0fb6740213             -movzx esi, byte ptr [edx + eax + 0x13]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 1));
    // 0050861f  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00508622  8a440212               -mov al, byte ptr [edx + eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 1);
    // 00508626  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050862b  e8a0120000             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 00508630  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00508633  a1e0389f00             -mov eax, dword ptr [0x9f38e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 00508638  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050863a  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050863d  f6420c08               +test byte ptr [edx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00508641  0f841c020000           -je 0x508863
    if (cpu.flags.zf)
    {
        goto L_0x00508863;
    }
    // 00508647  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0050864c:
    // 0050864c  8020fd                 -and byte ptr [eax], 0xfd
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0050864f  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508652  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00508654  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00508656  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00508658  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050865a  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508661  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00508663  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 00508669  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050866c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050866e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508671  f6420c04               +test byte ptr [edx + 0xc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 4 /*0x4*/));
    // 00508675  0f84ef010000           -je 0x50886a
    if (cpu.flags.zf)
    {
        goto L_0x0050886a;
    }
    // 0050867b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00508680:
    // 00508680  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508683  8020fb                 -and byte ptr [eax], 0xfb
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00508686  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00508689  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050868b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508692  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00508695  a1e0389f00             -mov eax, dword ptr [0x9f38e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 0050869a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0050869d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050869f  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005086a2  f6420c10               +test byte ptr [edx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 005086a6  0f84c5010000           -je 0x508871
    if (cpu.flags.zf)
    {
        goto L_0x00508871;
    }
    // 005086ac  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005086b1:
    // 005086b1  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005086b4  8020f7                 -and byte ptr [eax], 0xf7
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 005086b7  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 005086ba  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 005086bc  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 005086c3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005086c5  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 005086cb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005086ce  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005086d0  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005086d3  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 005086d7  0f849b010000           -je 0x508878
    if (cpu.flags.zf)
    {
        goto L_0x00508878;
    }
    // 005086dd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005086e2:
    // 005086e2  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005086e5  8020ef                 -and byte ptr [eax], 0xef
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 005086e8  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 005086eb  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 005086ed  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 005086f4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005086f6  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 005086fc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005086ff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00508701  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508704  f6420d08               +test byte ptr [edx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00508708  0f8471010000           -je 0x50887f
    if (cpu.flags.zf)
    {
        goto L_0x0050887f;
    }
    // 0050870e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00508713:
    // 00508713  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508716  806001f7               -and byte ptr [eax + 1], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0050871a  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0050871d  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050871f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508722  c1e01d                 -shl eax, 0x1d
    cpu.eax <<= 29 /*0x1d*/ % 32;
    // 00508725  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 00508728  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050872a  0f8528010000           -jne 0x508858
    if (!cpu.flags.zf)
    {
        goto L_0x00508858;
    }
    // 00508730  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508737  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00508739  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 0050873f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00508742  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00508744  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508747  f6420d04               +test byte ptr [edx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0050874b  0f8435010000           -je 0x508886
    if (cpu.flags.zf)
    {
        goto L_0x00508886;
    }
    // 00508751  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00508756:
    // 00508756  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508759  8020df                 -and byte ptr [eax], 0xdf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0050875c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0050875f  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 00508761  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508768  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050876a  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 00508770  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00508773  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00508775  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508778  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0050877c  0f840b010000           -je 0x50888d
    if (cpu.flags.zf)
    {
        goto L_0x0050888d;
    }
    // 00508782  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00508787:
    // 00508787  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050878a  8020bf                 -and byte ptr [eax], 0xbf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 0050878d  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00508790  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 00508792  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00508799  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0050879c  a1e0389f00             -mov eax, dword ptr [0x9f38e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 005087a1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005087a4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005087a6  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005087a9  f6420c80               +test byte ptr [edx + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 005087ad  0f84e1000000           -je 0x508894
    if (cpu.flags.zf)
    {
        goto L_0x00508894;
    }
    // 005087b3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005087b8:
    // 005087b8  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005087bb  80207f                 -and byte ptr [eax], 0x7f
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 005087be  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 005087c1  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 005087c3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 005087ca  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 005087cd  a1e0389f00             -mov eax, dword ptr [0x9f38e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 005087d2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005087d5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005087d7  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005087da  f6420d01               +test byte ptr [edx + 0xd], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 1 /*0x1*/));
    // 005087de  0f84b7000000           -je 0x50889b
    if (cpu.flags.zf)
    {
        goto L_0x0050889b;
    }
    // 005087e4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005087e9:
    // 005087e9  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005087ec  806001fe               -and byte ptr [eax + 1], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 005087f0  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005087f3  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 005087f5  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 005087fc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005087fe  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 00508804  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00508807  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00508809  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050880c  f6420d02               +test byte ptr [edx + 0xd], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 2 /*0x2*/));
    // 00508810  0f848c000000           -je 0x5088a2
    if (cpu.flags.zf)
    {
        goto L_0x005088a2;
    }
    // 00508816  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0050881b:
    // 0050881b  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050881e  806001fd               -and byte ptr [eax + 1], 0xfd
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00508822  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00508825  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 00508827  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0050882e  8b15e0389f00           -mov edx, dword ptr [0x9f38e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
    // 00508834  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00508836  8a5c820c               -mov bl, byte ptr [edx + eax*4 + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 0050883a  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050883d  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00508840  7467                   -je 0x5088a9
    if (cpu.flags.zf)
    {
        goto L_0x005088a9;
    }
    // 00508842  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00508847:
    // 00508847  8a7901                 -mov bh, byte ptr [ecx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050884a  80e7fb                 -and bh, 0xfb
    cpu.bh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0050884d  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508850  887901                 -mov byte ptr [ecx + 1], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bh;
    // 00508853  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00508856  0901                   -or dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00508858:
    // 00508858  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050885d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050885e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050885f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508863:
    // 00508863  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00508865  e9e2fdffff             -jmp 0x50864c
    goto L_0x0050864c;
L_0x0050886a:
    // 0050886a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050886c  e90ffeffff             -jmp 0x508680
    goto L_0x00508680;
L_0x00508871:
    // 00508871  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00508873  e939feffff             -jmp 0x5086b1
    goto L_0x005086b1;
L_0x00508878:
    // 00508878  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050887a  e963feffff             -jmp 0x5086e2
    goto L_0x005086e2;
L_0x0050887f:
    // 0050887f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00508881  e98dfeffff             -jmp 0x508713
    goto L_0x00508713;
L_0x00508886:
    // 00508886  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00508888  e9c9feffff             -jmp 0x508756
    goto L_0x00508756;
L_0x0050888d:
    // 0050888d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050888f  e9f3feffff             -jmp 0x508787
    goto L_0x00508787;
L_0x00508894:
    // 00508894  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00508896  e91dffffff             -jmp 0x5087b8
    goto L_0x005087b8;
L_0x0050889b:
    // 0050889b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050889d  e947ffffff             -jmp 0x5087e9
    goto L_0x005087e9;
L_0x005088a2:
    // 005088a2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005088a4  e972ffffff             -jmp 0x50881b
    goto L_0x0050881b;
L_0x005088a9:
    // 005088a9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005088ab  eb9a                   -jmp 0x508847
    goto L_0x00508847;
L_0x005088ad:
    // 005088ad  83fbff                 +cmp ebx, -1
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
    // 005088b0  0f85a7000000           -jne 0x50895d
    if (!cpu.flags.zf)
    {
        goto L_0x0050895d;
    }
    // 005088b6  803d2d3d9f0000         +cmp byte ptr [0x9f3d2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005088bd  0f859a000000           -jne 0x50895d
    if (!cpu.flags.zf)
    {
        goto L_0x0050895d;
    }
    // 005088c3  a1e4389f00             -mov eax, dword ptr [0x9f38e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */);
    // 005088c8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 005088ca  a1e8389f00             -mov eax, dword ptr [0x9f38e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */);
    // 005088cf  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005088d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005088d4  a02c3d9f00             -mov al, byte ptr [0x9f3d2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435884) /* 0x9f3d2c */);
    // 005088d9  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005088dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005088de  a049505600             -mov al, byte ptr [0x565049]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656649) /* 0x565049 */);
    // 005088e3  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005088e6  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005088e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005088eb  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 005088ee  a0323d9f00             -mov al, byte ptr [0x9f3d32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435890) /* 0x9f3d32 */);
    // 005088f3  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 005088f6  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005088f9  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005088fc  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005088fe  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00508900  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00508903  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00508905  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00508908  a02f3d9f00             -mov al, byte ptr [0x9f3d2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435887) /* 0x9f3d2f */);
    // 0050890d  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00508910  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508913  887110                 -mov byte ptr [ecx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 00508916  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00508919  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050891c  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050891f  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 00508921  8a1d333d9f00           -mov bl, byte ptr [0x9f3d33]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(10435891) /* 0x9f3d33 */);
    // 00508927  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 00508929  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050892c  762b                   -jbe 0x508959
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00508959;
    }
    // 0050892e  803d303d9f0000         +cmp byte ptr [0x9f3d30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435888) /* 0x9f3d30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00508935  7422                   -je 0x508959
    if (cpu.flags.zf)
    {
        goto L_0x00508959;
    }
    // 00508937  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050893c:
    // 0050893c  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050893e  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00508941  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00508944  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00508946  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00508949  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0050894b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050894d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00508952  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00508954  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508955  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00508959:
    // 00508959  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050895b  ebdf                   -jmp 0x50893c
    goto L_0x0050893c;
L_0x0050895d:
    // 0050895d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050895f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508960  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508961  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508962  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00508963  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_508970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00508970  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00508971  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00508973  e8f8f7ffff             -call 0x508170
    cpu.esp -= 4;
    sub_508170(app, cpu);
    if (cpu.terminate) return;
    // 00508978  e813faffff             -call 0x508390
    cpu.esp -= 4;
    sub_508390(app, cpu);
    if (cpu.terminate) return;
    // 0050897d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050897f  7441                   -je 0x5089c2
    if (cpu.flags.zf)
    {
        goto L_0x005089c2;
    }
    // 00508981  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00508983  7c08                   -jl 0x50898d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050898d;
    }
    // 00508985  3b15d8389f00           +cmp edx, dword ptr [0x9f38d8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10434776) /* 0x9f38d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050898b  7c05                   -jl 0x508992
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00508992;
    }
L_0x0050898d:
    // 0050898d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00508992:
    // 00508992  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 00508997  e864f3ffff             -call 0x507d00
    cpu.esp -= 4;
    sub_507d00(app, cpu);
    if (cpu.terminate) return;
    // 0050899c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050899e  751e                   -jne 0x5089be
    if (!cpu.flags.zf)
    {
        goto L_0x005089be;
    }
    // 005089a0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x005089a5:
    // 005089a5  e846f9ffff             -call 0x5082f0
    cpu.esp -= 4;
    sub_5082f0(app, cpu);
    if (cpu.terminate) return;
    // 005089aa  833d6443560007         +cmp dword ptr [0x564364], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005089b1  7514                   -jne 0x5089c7
    if (!cpu.flags.zf)
    {
        goto L_0x005089c7;
    }
    // 005089b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005089b5  7410                   -je 0x5089c7
    if (cpu.flags.zf)
    {
        goto L_0x005089c7;
    }
    // 005089b7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005089bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005089bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005089be:
    // 005089be  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005089c0  ebe3                   -jmp 0x5089a5
    goto L_0x005089a5;
L_0x005089c2:
    // 005089c2  a364435600             -mov dword ptr [0x564364], eax
    app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */) = cpu.eax;
L_0x005089c7:
    // 005089c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005089c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005089ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

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

}
