#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f34  b828d15400             -mov eax, 0x54d128
    cpu.eax = 5558568 /*0x54d128*/;
    // 004f4f39  e812fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f3e  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f43  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f54  b838d15400             -mov eax, 0x54d138
    cpu.eax = 5558584 /*0x54d138*/;
    // 004f4f59  e8f2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f5e  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f63  ff5324                 -call dword ptr [ebx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4f72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f4f74  b848d15400             -mov eax, 0x54d148
    cpu.eax = 5558600 /*0x54d148*/;
    // 004f4f79  e8d2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f7e  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f4f81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4f83  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4f92  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f94  b858d15400             -mov eax, 0x54d158
    cpu.eax = 5558616 /*0x54d158*/;
    // 004f4f99  e8b2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f9e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4fa0  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4fa5  e876920100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4faa  83f8ff                 +cmp eax, -1
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
    // 004f4fad  7508                   -jne 0x4f4fb7
    if (!cpu.flags.zf)
    {
        goto L_0x004f4fb7;
    }
    // 004f4faf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f4fb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4fb7:
    // 004f4fb7  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4fba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4fbc  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4fbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f4fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4fd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4fd2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4fd4  b864d15400             -mov eax, 0x54d164
    cpu.eax = 5558628 /*0x54d164*/;
    // 004f4fd9  e872fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4fde  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4fe1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4fe3  ff5630                 -call dword ptr [esi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4fe6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fe8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ff2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ff4  b874d15400             -mov eax, 0x54d174
    cpu.eax = 5558644 /*0x54d174*/;
    // 004f4ff9  e852fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ffe  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f5001  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5003  ff5334                 -call dword ptr [ebx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5006  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5007  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5008  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5011  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5013  b884d15400             -mov eax, 0x54d184
    cpu.eax = 5558660 /*0x54d184*/;
    // 004f5018  e833fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f501d  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f5020  83783c00               +cmp dword ptr [eax + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5024  7504                   -jne 0x4f502a
    if (!cpu.flags.zf)
    {
        goto L_0x004f502a;
    }
    // 004f5026  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5029  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f502a:
    // 004f502a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f502b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f502d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f502f  ff533c                 -call dword ptr [ebx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5033  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5034  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5041  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5044  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5047  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f504a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f504b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5050  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5051  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5054  837e3800               +cmp dword ptr [esi + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5058  7504                   -jne 0x4f505e
    if (!cpu.flags.zf)
    {
        goto L_0x004f505e;
    }
    // 004f505a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f505c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f505d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f505e:
    // 004f505e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5061  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5064  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5070  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5071  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5074  837e3c00               +cmp dword ptr [esi + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5078  7504                   -jne 0x4f507e
    if (!cpu.flags.zf)
    {
        goto L_0x004f507e;
    }
    // 004f507a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f507c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f507d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f507e:
    // 004f507e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5081  ff563c                 -call dword ptr [esi + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5090  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5091  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5094  837a2400               +cmp dword ptr [edx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5098  7504                   -jne 0x4f509e
    if (!cpu.flags.zf)
    {
        goto L_0x004f509e;
    }
    // 004f509a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f509c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f509d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f509e:
    // 004f509e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f50a1  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f50a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f50a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f50b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f50b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f50c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50c0  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f50c7  7501                   -jne 0x4f50ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f50ca;
    }
    // 004f50c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f50ca:
    // 004f50ca  e8b1010000             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 004f50cf  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f50d4  e8078d0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f50d9  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f50de  e9fd8c0100             -jmp 0x50dde0
    return sub_50dde0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f50f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50f0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f50f3  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004f50f7  7506                   -jne 0x4f50ff
    if (!cpu.flags.zf)
    {
        goto L_0x004f50ff;
    }
    // 004f50f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f50fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f50ff:
    // 004f50ff  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5102  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5107  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5111  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5112  baf0504f00             -mov edx, 0x4f50f0
    cpu.edx = 5198064 /*0x4f50f0*/;
    // 004f5117  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f511c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f511e  e8bd970100             -call 0x50e8e0
    cpu.esp -= 4;
    sub_50e8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5123  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5124  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5130  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5133  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5135  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f5137  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f5139  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f513b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f513f  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5146  0f84b5000000           -je 0x4f5201
    if (cpu.flags.zf)
    {
        goto L_0x004f5201;
    }
L_0x004f514c:
    // 004f514c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f514e  745e                   -je 0x4f51ae
    if (cpu.flags.zf)
    {
        goto L_0x004f51ae;
    }
    // 004f5150  66837e2a00             +cmp word ptr [esi + 0x2a], 0
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
    // 004f5155  7506                   -jne 0x4f515d
    if (!cpu.flags.zf)
    {
        goto L_0x004f515d;
    }
    // 004f5157  66c7462a0200           -mov word ptr [esi + 0x2a], 2
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = 2 /*0x2*/;
L_0x004f515d:
    // 004f515d  66837e2c00             +cmp word ptr [esi + 0x2c], 0
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
    // 004f5162  7506                   -jne 0x4f516a
    if (!cpu.flags.zf)
    {
        goto L_0x004f516a;
    }
    // 004f5164  66c7462c0400           -mov word ptr [esi + 0x2c], 4
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = 4 /*0x4*/;
L_0x004f516a:
    // 004f516a  66837e2e00             +cmp word ptr [esi + 0x2e], 0
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
    // 004f516f  7506                   -jne 0x4f5177
    if (!cpu.flags.zf)
    {
        goto L_0x004f5177;
    }
    // 004f5171  66c7462e0600           -mov word ptr [esi + 0x2e], 6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = 6 /*0x6*/;
L_0x004f5177:
    // 004f5177  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 004f517b  7507                   -jne 0x4f5184
    if (!cpu.flags.zf)
    {
        goto L_0x004f5184;
    }
    // 004f517d  c74614b0504f00         -mov dword ptr [esi + 0x14], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 5198000 /*0x4f50b0*/;
L_0x004f5184:
    // 004f5184  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5188  7507                   -jne 0x4f5191
    if (!cpu.flags.zf)
    {
        goto L_0x004f5191;
    }
    // 004f518a  c7461cb0504f00         -mov dword ptr [esi + 0x1c], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 5198000 /*0x4f50b0*/;
L_0x004f5191:
    // 004f5191  837e1800               +cmp dword ptr [esi + 0x18], 0
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
    // 004f5195  7507                   -jne 0x4f519e
    if (!cpu.flags.zf)
    {
        goto L_0x004f519e;
    }
    // 004f5197  c74618b0504f00         -mov dword ptr [esi + 0x18], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 5198000 /*0x4f50b0*/;
L_0x004f519e:
    // 004f519e  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51a2  7507                   -jne 0x4f51ab
    if (!cpu.flags.zf)
    {
        goto L_0x004f51ab;
    }
    // 004f51a4  c74620b0504f00         -mov dword ptr [esi + 0x20], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 5198000 /*0x4f50b0*/;
L_0x004f51ab:
    // 004f51ab  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x004f51ae:
    // 004f51ae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51b0  741f                   -je 0x4f51d1
    if (cpu.flags.zf)
    {
        goto L_0x004f51d1;
    }
    // 004f51b2  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51b6  7419                   -je 0x4f51d1
    if (cpu.flags.zf)
    {
        goto L_0x004f51d1;
    }
    // 004f51b8  833df86d560000         +cmp dword ptr [0x566df8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51bf  750a                   -jne 0x4f51cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f51cb;
    }
    // 004f51c1  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f51c6  e865d7ffff             -call 0x4f2930
    cpu.esp -= 4;
    sub_4f2930(app, cpu);
    if (cpu.terminate) return;
L_0x004f51cb:
    // 004f51cb  ff05f86d5600           -inc dword ptr [0x566df8]
    (app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */))++;
L_0x004f51d1:
    // 004f51d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51d3  7536                   -jne 0x4f520b
    if (!cpu.flags.zf)
    {
        goto L_0x004f520b;
    }
L_0x004f51d5:
    // 004f51d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f51d7  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f51da  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004f51dc:
    // 004f51dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51de  7419                   -je 0x4f51f9
    if (cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51e0  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51e4  7413                   -je 0x4f51f9
    if (cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f51e8  750f                   -jne 0x4f51f9
    if (!cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51ea  8b0df86d5600           -mov ecx, dword ptr [0x566df8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
    // 004f51f0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f51f1  890df86d5600           -mov dword ptr [0x566df8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */) = cpu.ecx;
    // 004f51f7  741f                   -je 0x4f5218
    if (cpu.flags.zf)
    {
        goto L_0x004f5218;
    }
L_0x004f51f9:
    // 004f51f9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f51fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f5201:
    // 004f5201  e82a000000             -call 0x4f5230
    cpu.esp -= 4;
    sub_4f5230(app, cpu);
    if (cpu.terminate) return;
    // 004f5206  e941ffffff             -jmp 0x4f514c
    goto L_0x004f514c;
L_0x004f520b:
    // 004f520b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f520d  e84ed40100             -call 0x512660
    cpu.esp -= 4;
    sub_512660(app, cpu);
    if (cpu.terminate) return;
    // 004f5212  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5214  75bf                   -jne 0x4f51d5
    if (!cpu.flags.zf)
    {
        goto L_0x004f51d5;
    }
    // 004f5216  ebc4                   -jmp 0x4f51dc
    goto L_0x004f51dc;
L_0x004f5218:
    // 004f5218  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f521d  e88ed7ffff             -call 0x4f29b0
    cpu.esp -= 4;
    sub_4f29b0(app, cpu);
    if (cpu.terminate) return;
    // 004f5222  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5224  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5225  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5226  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5227  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5231  8b15f46d5600           -mov edx, dword ptr [0x566df4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
    // 004f5237  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5239  7402                   -je 0x4f523d
    if (cpu.flags.zf)
    {
        goto L_0x004f523d;
    }
    // 004f523b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f523c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f523d:
    // 004f523d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f523e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f523f  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f5244  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5246  e8858a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f524b  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f5250  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5252  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5254  e8778a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5259  b8c0504f00             -mov eax, 0x4f50c0
    cpu.eax = 5198016 /*0x4f50c0*/;
    // 004f525e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5263  e810d8ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f5268  890df46d5600           -mov dword ptr [0x566df4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */) = cpu.ecx;
    // 004f526e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f526f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5270  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f5280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5284  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5285  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5286  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f528d  7434                   -je 0x4f52c3
    if (cpu.flags.zf)
    {
        goto L_0x004f52c3;
    }
    // 004f528f  bb28269f00             -mov ebx, 0x9f2628
    cpu.ebx = 10429992 /*0x9f2628*/;
    // 004f5294  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f5296:
    // 004f5296  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5298  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f529a  e8d1910100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f529f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52a1  7527                   -jne 0x4f52ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f52ca;
    }
    // 004f52a3  be0c269f00             -mov esi, 0x9f260c
    cpu.esi = 10429964 /*0x9f260c*/;
    // 004f52a8  bf94d15400             -mov edi, 0x54d194
    cpu.edi = 5558676 /*0x54d194*/;
    // 004f52ad  bda4d15400             -mov ebp, 0x54d1a4
    cpu.ebp = 5558692 /*0x54d1a4*/;
    // 004f52b2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f52b4:
    // 004f52b4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f52b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f52b8  e8b3910100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f52bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f52bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52c1  750e                   -jne 0x4f52d1
    if (!cpu.flags.zf)
    {
        goto L_0x004f52d1;
    }
L_0x004f52c3:
    // 004f52c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f52ca:
    // 004f52ca  e861000000             -call 0x4f5330
    cpu.esp -= 4;
    sub_4f5330(app, cpu);
    if (cpu.terminate) return;
    // 004f52cf  ebc5                   -jmp 0x4f5296
    goto L_0x004f5296;
L_0x004f52d1:
    // 004f52d1  e85a000000             -call 0x4f5330
    cpu.esp -= 4;
    sub_4f5330(app, cpu);
    if (cpu.terminate) return;
    // 004f52d6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f52d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f52da  e8718e0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f52df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52e1  74d1                   -je 0x4f52b4
    if (cpu.flags.zf)
    {
        goto L_0x004f52b4;
    }
    // 004f52e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f52e4  b8db000000             -mov eax, 0xdb
    cpu.eax = 219 /*0xdb*/;
    // 004f52e9  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f52ef  68b4d15400             -push 0x54d1b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558708 /*0x54d1b4*/;
    cpu.esp -= 4;
    // 004f52f4  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f52fa  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f52ff  e80cbdf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f5304  83c408                 +add esp, 8
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
    // 004f5307  ebab                   -jmp 0x4f52b4
    goto L_0x004f52b4;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5310  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f5313  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f5317  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f531a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f531c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f5321  e84ad40100             -call 0x512770
    cpu.esp -= 4;
    sub_512770(app, cpu);
    if (cpu.terminate) return;
    // 004f5326  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f5329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5330  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5331  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5333  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5335  7406                   -je 0x4f533d
    if (cpu.flags.zf)
    {
        goto L_0x004f533d;
    }
    // 004f5337  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f533b  7504                   -jne 0x4f5341
    if (!cpu.flags.zf)
    {
        goto L_0x004f5341;
    }
L_0x004f533d:
    // 004f533d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f533f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5340  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5341:
    // 004f5341  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5342  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5343  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5344  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f5347  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f534a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f534c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f534e  742a                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5350  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5353  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 004f5357  7421                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5359  8b35f86d5600           -mov esi, dword ptr [0x566df8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
    // 004f535f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f5361  7417                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5363  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004f5366  893df86d5600           -mov dword ptr [0x566df8], edi
    app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */) = cpu.edi;
    // 004f536c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f536e  750a                   -jne 0x4f537a
    if (!cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5370  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f5375  e836d6ffff             -call 0x4f29b0
    cpu.esp -= 4;
    sub_4f29b0(app, cpu);
    if (cpu.terminate) return;
L_0x004f537a:
    // 004f537a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f537c  e83fd30100             -call 0x5126c0
    cpu.esp -= 4;
    sub_5126c0(app, cpu);
    if (cpu.terminate) return;
    // 004f5381  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5384  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5385  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5386  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5387  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f5390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5392  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5394  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5395  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5397  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004f5399  8b15006e5600           -mov edx, dword ptr [0x566e00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f539f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f53a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f53a3  7e1a                   -jle 0x4f53bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f53bf;
    }
    // 004f53a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f53a7:
    // 004f53a7  8b8148269f00           -mov eax, dword ptr [ecx + 0x9f2648]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10430024) /* 0x9f2648 */);
    // 004f53ad  39c7                   +cmp edi, eax
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
    // 004f53af  7419                   -je 0x4f53ca
    if (cpu.flags.zf)
    {
        goto L_0x004f53ca;
    }
L_0x004f53b1:
    // 004f53b1  8b1d006e5600           -mov ebx, dword ptr [0x566e00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f53b7  46                     -inc esi
    (cpu.esi)++;
    // 004f53b8  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f53bb  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f53bd  7ce8                   -jl 0x4f53a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f53a7;
    }
L_0x004f53bf:
    // 004f53bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f53c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f53ca:
    // 004f53ca  8b9944269f00           -mov ebx, dword ptr [ecx + 0x9f2644]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10430020) /* 0x9f2644 */);
    // 004f53d0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f53d2  83c334                 -add ebx, 0x34
    (cpu.ebx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f53d5  e866fcffff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 004f53da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f53dc  74d3                   -je 0x4f53b1
    if (cpu.flags.zf)
    {
        goto L_0x004f53b1;
    }
    // 004f53de  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f53e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f53f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f53f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f53f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f53f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f53f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f53f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f53f5  81eccc000000           -sub esp, 0xcc
    (cpu.esp) -= x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f53fb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f53fd  899424c8000000         -mov dword ptr [esp + 0xc8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.edx;
    // 004f5404  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f540a  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f540f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5411  7510                   -jne 0x4f5423
    if (!cpu.flags.zf)
    {
        goto L_0x004f5423;
    }
    // 004f5413  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f5415  7c56                   -jl 0x4f546d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f546d;
    }
    // 004f5417  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f541d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f541e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f541f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5420  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5421  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5422  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5423:
    // 004f5423  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5424  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f542a  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004f5431  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5433  e858ffffff             -call 0x4f5390
    cpu.esp -= 4;
    sub_4f5390(app, cpu);
    if (cpu.terminate) return;
    // 004f5438  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f543a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f543c  7c12                   -jl 0x4f5450
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5450;
    }
    // 004f543e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004f5441  8b8044269f00           -mov eax, dword ptr [eax + 0x9f2644]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10430020) /* 0x9f2644 */);
    // 004f5447  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f544a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f544c  7402                   -je 0x4f5450
    if (cpu.flags.zf)
    {
        goto L_0x004f5450;
    }
    // 004f544e  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f5450:
    // 004f5450  8b35fc6d5600           -mov esi, dword ptr [0x566dfc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5456  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5457  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f545d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f545f  7c0c                   -jl 0x4f546d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f546d;
    }
    // 004f5461  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f5467  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5468  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5469  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f546d:
    // 004f546d  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004f5474  8bb424c8000000         -mov esi, dword ptr [esp + 0xc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004f547b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5480  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004f5485  bf746164ea             -mov edi, 0xea646174
    cpu.edi = 3932447092 /*0xea646174*/;
    // 004f548a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f548e  89bc24c4000000         -mov dword ptr [esp + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.edi;
    // 004f5495  8d9c24c4000000         -lea ebx, [esp + 0xc4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f549c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f549f  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004f54a6  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f54a9  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f54ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f54ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f54b0  742b                   -je 0x4f54dd
    if (cpu.flags.zf)
    {
        goto L_0x004f54dd;
    }
    // 004f54b2  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f54ba  7421                   -je 0x4f54dd
    if (cpu.flags.zf)
    {
        goto L_0x004f54dd;
    }
    // 004f54bc  8d9424c4000000         -lea edx, [esp + 0xc4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f54c3  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004f54c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f54c6  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f54cd  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f54d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f54d1  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004f54d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f54da  ff5640                 -call dword ptr [esi + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f54dd:
    // 004f54dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f54df  758c                   -jne 0x4f546d
    if (!cpu.flags.zf)
    {
        goto L_0x004f546d;
    }
    // 004f54e1  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f54e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f54f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f54f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f54f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f54f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f54f5  8b684c                 -mov ebp, dword ptr [eax + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f54f8  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f54fb  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f54fe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f5501  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5503  0f84c1000000           -je 0x4f55ca
    if (cpu.flags.zf)
    {
        goto L_0x004f55ca;
    }
    // 004f5509  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f550c  837a4800               +cmp dword ptr [edx + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5510  0f85a4000000           -jne 0x4f55ba
    if (!cpu.flags.zf)
    {
        goto L_0x004f55ba;
    }
L_0x004f5516:
    // 004f5516  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5517  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5518  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5519  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f551d  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004f5522  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f5525  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f5528  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f552a  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f552d  ff565c                 -call dword ptr [esi + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5530  833dfc6d560000         +cmp dword ptr [0x566dfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5537  750a                   -jne 0x4f5543
    if (!cpu.flags.zf)
    {
        goto L_0x004f5543;
    }
    // 004f5539  e8a25dffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f553e  a3fc6d5600             -mov dword ptr [0x566dfc], eax
    app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */) = cpu.eax;
L_0x004f5543:
    // 004f5543  8b35fc6d5600           -mov esi, dword ptr [0x566dfc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5549  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f554a  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5550  8b35006e5600           -mov esi, dword ptr [0x566e00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5556  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004f5559  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f555d  898644269f00           -mov dword ptr [esi + 0x9f2644], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10430020) /* 0x9f2644 */) = cpu.eax;
    // 004f5563  8dbe4c269f00           -lea edi, [esi + 0x9f264c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(10430028) /* 0x9f264c */);
    // 004f5569  89ae48269f00           -mov dword ptr [esi + 0x9f2648], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10430024) /* 0x9f2648 */) = cpu.ebp;
    // 004f556f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5571  8d7634                 -lea esi, [esi + 0x34]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f5574  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5575  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5576  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5577  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5578  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5579  8b85a8000000           -mov eax, dword ptr [ebp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */);
    // 004f557f  8b3d006e5600           -mov edi, dword ptr [0x566e00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5585  40                     -inc eax
    (cpu.eax)++;
    // 004f5586  47                     -inc edi
    (cpu.edi)++;
    // 004f5587  8985a8000000           -mov dword ptr [ebp + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004f558d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5591  893d006e5600           -mov dword ptr [0x566e00], edi
    app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */) = cpu.edi;
    // 004f5597  c74048ffffffff         -mov dword ptr [eax + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f559e  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f55a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f55a5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f55ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ae  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f55b1  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f55b4  83c404                 +add esp, 4
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
    // 004f55b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f55ba:
    // 004f55ba  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f55bc  8d5034                 -lea edx, [eax + 0x34]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004f55bf  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f55c2  ff5648                 -call dword ptr [esi + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f55c5  e94cffffff             -jmp 0x4f5516
    goto L_0x004f5516;
L_0x004f55ca:
    // 004f55ca  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 004f55cd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f55d0  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f55d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f55d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f55e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f55e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f55e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f55e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f55e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f55e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f55e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f55e7  8b784c                 -mov edi, dword ptr [eax + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f55ea  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004f55ed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f55ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f55f1  7409                   -je 0x4f55fc
    if (cpu.flags.zf)
    {
        goto L_0x004f55fc;
    }
    // 004f55f3  83bfa800000000         +cmp dword ptr [edi + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f55fa  7512                   -jne 0x4f560e
    if (!cpu.flags.zf)
    {
        goto L_0x004f560e;
    }
L_0x004f55fc:
    // 004f55fc  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f5603  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5608  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5609  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f560e:
    // 004f560e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f560f  8b2dfc6d5600           -mov ebp, dword ptr [0x566dfc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5615  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5616  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f561c  8b0d006e5600           -mov ecx, dword ptr [0x566e00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5622  8b2d44269f00           -mov ebp, dword ptr [0x9f2644]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10430020) /* 0x9f2644 */);
    // 004f5628  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f562a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f562c  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004f562f  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5631  7412                   -je 0x4f5645
    if (cpu.flags.zf)
    {
        goto L_0x004f5645;
    }
L_0x004f5633:
    // 004f5633  39c8                   +cmp eax, ecx
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
    // 004f5635  7d0e                   -jge 0x4f5645
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5645;
    }
    // 004f5637  8b9864269f00           -mov ebx, dword ptr [eax + 0x9f2664]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10430052) /* 0x9f2664 */);
    // 004f563d  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f5640  42                     -inc edx
    (cpu.edx)++;
    // 004f5641  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5643  75ee                   -jne 0x4f5633
    if (!cpu.flags.zf)
    {
        goto L_0x004f5633;
    }
L_0x004f5645:
    // 004f5645  8b2d006e5600           -mov ebp, dword ptr [0x566e00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f564b  b944269f00             -mov ecx, 0x9f2644
    cpu.ecx = 10430020 /*0x9f2644*/;
    // 004f5650  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f5651  8b87a8000000           -mov eax, dword ptr [edi + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */);
    // 004f5657  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f5659  48                     -dec eax
    (cpu.eax)--;
    // 004f565a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f565c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004f565f  8987a8000000           -mov dword ptr [edi + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004f5665  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f5667  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f566a  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004f566d  0544269f00             -add eax, 0x9f2644
    (cpu.eax) += x86::reg32(x86::sreg32(10430020 /*0x9f2644*/));
    // 004f5672  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5674  892d006e5600           -mov dword ptr [0x566e00], ebp
    app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */) = cpu.ebp;
    // 004f567a  e8714effff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f567f  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5685  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5686  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004f568b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5691  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5696  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f5699  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f569c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004f569f  ff555c                 -call dword ptr [ebp + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f56a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56a3  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f56aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f56af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f56c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f56c0  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f56c4  7412                   -je 0x4f56d8
    if (cpu.flags.zf)
    {
        goto L_0x004f56d8;
    }
    // 004f56c6  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f56c9  83b89c00000000         +cmp dword ptr [eax + 0x9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f56d0  7406                   -je 0x4f56d8
    if (cpu.flags.zf)
    {
        goto L_0x004f56d8;
    }
    // 004f56d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f56d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f56d8:
    // 004f56d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f56da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f56e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f56e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f56e1  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f56e4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f56e7  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f56ea  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f56ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f56ef  7408                   -je 0x4f56f9
    if (cpu.flags.zf)
    {
        goto L_0x004f56f9;
    }
    // 004f56f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f56f3  66a1206e5600           -mov ax, word ptr [0x566e20]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5664288) /* 0x566e20 */);
L_0x004f56f9:
    // 004f56f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5700  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5701  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f5704  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5707  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f570a  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f570d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f570e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f5710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5711  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5712  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5713  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5714  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5717  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f571b  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f571f  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004f5723  8b684c                 -mov ebp, dword ptr [eax + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
L_0x004f5726:
    // 004f5726  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004f572b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f572d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f5731  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004f5735  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f5739  8d7634                 -lea esi, [esi + 0x34]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f573c  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5741  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5742  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5743  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5744  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5745  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5746  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f574a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f574d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5751  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f5754  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5757  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5759  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f575b  750a                   -jne 0x4f5767
    if (!cpu.flags.zf)
    {
        goto L_0x004f5767;
    }
L_0x004f575d:
    // 004f575d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f575f  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5762  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5763  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5764  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5765  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5766  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5767:
    // 004f5767  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f576b  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f576f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5770  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f5774  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f5777  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5778  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f577c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f577e  ff5640                 -call dword ptr [esi + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5781  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5785  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5787  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f5789  7509                   -jne 0x4f5794
    if (!cpu.flags.zf)
    {
        goto L_0x004f5794;
    }
    // 004f578b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f578f  895824                 -mov dword ptr [eax + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f5792  eb15                   -jmp 0x4f57a9
    goto L_0x004f57a9;
L_0x004f5794:
    // 004f5794  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5796  7411                   -je 0x4f57a9
    if (cpu.flags.zf)
    {
        goto L_0x004f57a9;
    }
    // 004f5798  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f579c  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f57a0  7407                   -je 0x4f57a9
    if (cpu.flags.zf)
    {
        goto L_0x004f57a9;
    }
    // 004f57a2  c7404801000000         -mov dword ptr [eax + 0x48], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
L_0x004f57a9:
    // 004f57a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f57ab  0f8475ffffff           -je 0x4f5726
    if (cpu.flags.zf)
    {
        goto L_0x004f5726;
    }
    // 004f57b1  ebaa                   -jmp 0x4f575d
    goto L_0x004f575d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f57c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f57c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f57c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f57c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f57c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f57c4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f57c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f57c9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f57cc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f57ce  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004f57d3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f57d7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f57db  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f57df  7d32                   -jge 0x4f5813
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5813;
    }
    // 004f57e1  837848fc               +cmp dword ptr [eax + 0x48], -4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f57e5  7d59                   -jge 0x4f5840
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5840;
    }
    // 004f57e7  b86e706fea             -mov eax, 0xea6f706e
    cpu.eax = 3933171822 /*0xea6f706e*/;
    // 004f57ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f57ee  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f57f2  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004f57f5  bb6e706fea             -mov ebx, 0xea6f706e
    cpu.ebx = 3933171822 /*0xea6f706e*/;
    // 004f57fa  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f57fd  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5800  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5802  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5805  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5808  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f580a  7407                   -je 0x4f5813
    if (cpu.flags.zf)
    {
        goto L_0x004f5813;
    }
    // 004f580c  c74648ffffffff         -mov dword ptr [esi + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
L_0x004f5813:
    // 004f5813  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f5817  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f581b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f581e  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f5821  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5825  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5826  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5829  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f582c  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f582f  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5832  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5834  7402                   -je 0x4f5838
    if (cpu.flags.zf)
    {
        goto L_0x004f5838;
    }
    // 004f5836  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004f5838:
    // 004f5838  83c40c                 +add esp, 0xc
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
    // 004f583b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5840:
    // 004f5840  ff4848                 +dec dword ptr [eax + 0x48]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f5843  ebce                   -jmp 0x4f5813
    goto L_0x004f5813;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5850  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5851  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5852  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f5854  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5856  740a                   -je 0x4f5862
    if (cpu.flags.zf)
    {
        goto L_0x004f5862;
    }
    // 004f5858  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f585f  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
L_0x004f5862:
    // 004f5862  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f5864  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f5867  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f5869  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f586b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f586d  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5870  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5871  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f5880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5882  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5883  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5885  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f5887  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f588c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f588f  e85c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f5894  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 004f5899  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f589c  8d4606                 -lea eax, [esi + 6]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004f589f  e84c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58a4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f58a9  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 004f58ac  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f58af  e83c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f58c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f58c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f58c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f58c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f58c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f58c5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f58c7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f58cc  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f58cf  e81c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58d4  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 004f58d9  8d5106                 -lea edx, [ecx + 6]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004f58dc  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f58df  e80c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58e4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f58e9  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f58ec  8d460a                 -lea eax, [esi + 0xa]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004f58ef  e8fc4bffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58f4  66c7010600             -mov word ptr [ecx], 6
    app->getMemory<x86::reg16>(cpu.ecx) = 6 /*0x6*/;
    // 004f58f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f5900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5902  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5905  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f5908  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f590a  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f590d  66c7020600             -mov word ptr [edx], 6
    app->getMemory<x86::reg16>(cpu.edx) = 6 /*0x6*/;
    // 004f5912  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5914  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004f5919  e8f8adfeff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 004f591e  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004f5923  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004f5928  8d4106                 -lea eax, [ecx + 6]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004f592b  e8e6adfeff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 004f5930  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f5935  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5937  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f593a  e8b14bffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f593f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5944  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5952  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5953  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5954  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5957  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5959  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f595b  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f595f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5960  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5964  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5965  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5967  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004f596c  681c010000             -push 0x11c
    app->getMemory<x86::reg32>(cpu.esp-4) = 284 /*0x11c*/;
    cpu.esp -= 4;
    // 004f5971  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f5974  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f5978  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5979  8b4f58                 -mov ecx, dword ptr [edi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(88) /* 0x58 */);
    // 004f597c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f597d  e8dae40300             -call 0x533e5c
    cpu.esp -= 4;
    sub_533e5c(app, cpu);
    if (cpu.terminate) return;
    // 004f5982  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f5985  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5987  7e16                   -jle 0x4f599f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f599f;
    }
    // 004f5989  807f2600               +cmp byte ptr [edi + 0x26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(38) /* 0x26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f598d  741a                   -je 0x4f59a9
    if (cpu.flags.zf)
    {
        goto L_0x004f59a9;
    }
    // 004f598f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004f5991  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5993  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f5996  e8f5ce0100             -call 0x512890
    cpu.esp -= 4;
    sub_512890(app, cpu);
    if (cpu.terminate) return;
    // 004f599b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f599d  740a                   -je 0x4f59a9
    if (cpu.flags.zf)
    {
        goto L_0x004f59a9;
    }
L_0x004f599f:
    // 004f599f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f59a1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f59a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f59a9:
    // 004f59a9  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f59ae  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f59b3  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f59b6  8d4624                 -lea eax, [esi + 0x24]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f59b9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f59bb  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f59bd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f59bf  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f59c6  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f59c8  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f59cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f59cd  7445                   -je 0x4f5a14
    if (cpu.flags.zf)
    {
        goto L_0x004f5a14;
    }
    // 004f59cf  837e0804               +cmp dword ptr [esi + 8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f59d3  7c3f                   -jl 0x4f5a14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a14;
    }
    // 004f59d5  837c24100e             +cmp dword ptr [esp + 0x10], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f59da  7538                   -jne 0x4f5a14
    if (!cpu.flags.zf)
    {
        goto L_0x004f5a14;
    }
    // 004f59dc  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f59df  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f59e1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f59e3  e898feffff             -call 0x4f5880
    cpu.esp -= 4;
    sub_4f5880(app, cpu);
    if (cpu.terminate) return;
    // 004f59e8  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f59ef  7c16                   -jl 0x4f5a07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a07;
    }
    // 004f59f1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f59f3  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f59f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f59fa  b810d25400             -mov eax, 0x54d210
    cpu.eax = 5558800 /*0x54d210*/;
    // 004f59ff  8d5620                 -lea edx, [esi + 0x20]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f5a02  e879c70100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5a07:
    // 004f5a07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5a0c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5a0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5a14:
    // 004f5a14  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f5a1b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f5a22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5a24  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5a27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5a31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5a32  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a35  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f5a37  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f5a3a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004f5a3c  8d5026                 -lea edx, [eax + 0x26]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004f5a3f  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 004f5a44  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5a46  e84559ffff             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 004f5a4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5a4d  7406                   -je 0x4f5a55
    if (cpu.flags.zf)
    {
        goto L_0x004f5a55;
    }
    // 004f5a4f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5a55:
    // 004f5a55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5a56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a57  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004f5a59  bb767273ea             -mov ebx, 0xea737276
    cpu.ebx = 3933434486 /*0xea737276*/;
    // 004f5a5e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5a60  49                     -dec ecx
    (cpu.ecx)--;
    // 004f5a61  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f5a63  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f5a65  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f5a67  49                     -dec ecx
    (cpu.ecx)--;
    // 004f5a68  41                     -inc ecx
    (cpu.ecx)++;
    // 004f5a69  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f5a6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a6e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5a70  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f5a72  e839060000             -call 0x4f60b0
    cpu.esp -= 4;
    sub_4f60b0(app, cpu);
    if (cpu.terminate) return;
    // 004f5a77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f5a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5a83  8b0da0c17900           -mov ecx, dword ptr [0x79c1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f5a89  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f5a8c  3b4804                 +cmp ecx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5a8f  7c07                   -jl 0x4f5a98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a98;
    }
    // 004f5a91  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f5a94  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5a96  7409                   -je 0x4f5aa1
    if (cpu.flags.zf)
    {
        goto L_0x004f5aa1;
    }
L_0x004f5a98:
    // 004f5a98  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5a9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aa0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5aa1:
    // 004f5aa1  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5aa4  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5aa7  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f5aaa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5aac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5aae  e82d050000             -call 0x4f5fe0
    cpu.esp -= 4;
    sub_4f5fe0(app, cpu);
    if (cpu.terminate) return;
    // 004f5ab3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5ab5  75e1                   -jne 0x4f5a98
    if (!cpu.flags.zf)
    {
        goto L_0x004f5a98;
    }
    // 004f5ab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ab9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5ac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5ac4  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f5ac7  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f5ac9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5acb  39d9                   +cmp ecx, ebx
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
    // 004f5acd  750e                   -jne 0x4f5add
    if (!cpu.flags.zf)
    {
        goto L_0x004f5add;
    }
    // 004f5acf  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f5ad2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5ad4  7511                   -jne 0x4f5ae7
    if (!cpu.flags.zf)
    {
        goto L_0x004f5ae7;
    }
L_0x004f5ad6:
    // 004f5ad6  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x004f5add:
    // 004f5add  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5ae2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5ae7:
    // 004f5ae7  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5aea  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5aed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5aef  e8ec040000             -call 0x4f5fe0
    cpu.esp -= 4;
    sub_4f5fe0(app, cpu);
    if (cpu.terminate) return;
    // 004f5af4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5af6  75de                   -jne 0x4f5ad6
    if (!cpu.flags.zf)
    {
        goto L_0x004f5ad6;
    }
    // 004f5af8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5afd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5afe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f5b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5b15  8b1d50369f00           -mov ebx, dword ptr [0x9f3650]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */);
    // 004f5b1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5b1d  e8de9ffeff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f5b22  891550369f00           -mov dword ptr [0x9f3650], edx
    app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */) = cpu.edx;
    // 004f5b28  8b4b20                 -mov ecx, dword ptr [ebx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004f5b2b  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f5b2e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f5b30  743f                   -je 0x4f5b71
    if (cpu.flags.zf)
    {
        goto L_0x004f5b71;
    }
    // 004f5b32  8dbb8c000000           -lea edi, [ebx + 0x8c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(140) /* 0x8c */);
    // 004f5b38  8d7370                 -lea esi, [ebx + 0x70]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
L_0x004f5b3b:
    // 004f5b3b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5b3d  e81e840100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f5b42  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5b44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5b46  7449                   -je 0x4f5b91
    if (cpu.flags.zf)
    {
        goto L_0x004f5b91;
    }
    // 004f5b48  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5b4a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f5b4c  e8fffdffff             -call 0x4f5950
    cpu.esp -= 4;
    sub_4f5950(app, cpu);
    if (cpu.terminate) return;
    // 004f5b51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5b53  7431                   -je 0x4f5b86
    if (cpu.flags.zf)
    {
        goto L_0x004f5b86;
    }
    // 004f5b55  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5b57  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5b59  e872830100             -call 0x50ded0
    cpu.esp -= 4;
    sub_50ded0(app, cpu);
    if (cpu.terminate) return;
    // 004f5b5e  833b00                 +cmp dword ptr [ebx], 0
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
    // 004f5b61  7408                   -je 0x4f5b6b
    if (cpu.flags.zf)
    {
        goto L_0x004f5b6b;
    }
    // 004f5b63  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f5b66  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f5b69  ff13                   -call dword ptr [ebx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f5b6b:
    // 004f5b6b  837b2000               +cmp dword ptr [ebx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5b6f  75ca                   -jne 0x4f5b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004f5b3b;
    }
L_0x004f5b71:
    // 004f5b71  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004f5b74  e887a0feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f5b79  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f5b80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5b86:
    // 004f5b86  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5b88  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5b8a  e8c1820100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f5b8f  ebda                   -jmp 0x4f5b6b
    goto L_0x004f5b6b;
L_0x004f5b91:
    // 004f5b91  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004f5b94  e8d79ffeff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f5b99  ebd0                   -jmp 0x4f5b6b
    goto L_0x004f5b6b;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ba1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5ba2  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f5ba8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5baa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5bab  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f5bb0  e8fbe20300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f5bb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5bb7  751f                   -jne 0x4f5bd8
    if (!cpu.flags.zf)
    {
        goto L_0x004f5bd8;
    }
    // 004f5bb9  8b942488010000         -mov edx, dword ptr [esp + 0x188]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004f5bc0  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f5bc3  740c                   -je 0x4f5bd1
    if (cpu.flags.zf)
    {
        goto L_0x004f5bd1;
    }
    // 004f5bc5  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
L_0x004f5bc8:
    // 004f5bc8  81c490010000           +add esp, 0x190
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f5bce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5bcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5bd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5bd1:
    // 004f5bd1  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004f5bd6  ebf0                   -jmp 0x4f5bc8
    goto L_0x004f5bc8;
L_0x004f5bd8:
    // 004f5bd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5bda  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f5be0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5be2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5bf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5bf2  e8a7e20300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f5bf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5bf9  7508                   -jne 0x4f5c03
    if (!cpu.flags.zf)
    {
        goto L_0x004f5c03;
    }
    // 004f5bfb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5c00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5c03:
    // 004f5c03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5c11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5c12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5c13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5c14  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5c17  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f5c1b  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004f5c1f  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004f5c23  ba1cd25400             -mov edx, 0x54d21c
    cpu.edx = 5558812 /*0x54d21c*/;
    // 004f5c28  b928d25400             -mov ecx, 0x54d228
    cpu.ecx = 5558824 /*0x54d228*/;
    // 004f5c2d  bb0a010000             -mov ebx, 0x10a
    cpu.ebx = 266 /*0x10a*/;
    // 004f5c32  b838d25400             -mov eax, 0x54d238
    cpu.eax = 5558840 /*0x54d238*/;
    // 004f5c37  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f5c3d  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f5c43  baa8400100             -mov edx, 0x140a8
    cpu.edx = 82088 /*0x140a8*/;
    // 004f5c48  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f5c4e  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f5c54  e8c7b9feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f5c59  baa8400100             -mov edx, 0x140a8
    cpu.edx = 82088 /*0x140a8*/;
    // 004f5c5e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5c60  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5c62  e8a5aafeff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f5c67  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5c69  8d6970                 -lea ebp, [ecx + 0x70]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 004f5c6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5c6e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5c70  e85b800100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5c75  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 004f5c7b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5c7d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5c7f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f5c81  e84a800100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5c86  8d81a8000000           -lea eax, [ecx + 0xa8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 004f5c8c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f5c8e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5c90  8da800400100           -lea ebp, [eax + 0x14000]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(81920) /* 0x14000 */);
L_0x004f5c96:
    // 004f5c96  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5c98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f5c9a  81c140010000           -add ecx, 0x140
    (cpu.ecx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f5ca0  e8ab810100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f5ca5  39e9                   +cmp ecx, ebp
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
    // 004f5ca7  75ed                   -jne 0x4f5c96
    if (!cpu.flags.zf)
    {
        goto L_0x004f5c96;
    }
    // 004f5ca9  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 004f5cae  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f5cb0  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004f5cb2  e8f3e10300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f5cb7  c7462001000000         -mov dword ptr [esi + 0x20], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004f5cbe  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004f5cc1  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f5cc5  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f5cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5cca  0f85ad010000           -jne 0x4f5e7d
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e7d;
    }
L_0x004f5cd0:
    // 004f5cd0  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f5cd7  7c1a                   -jl 0x4f5cf3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5cf3;
    }
    // 004f5cd9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5cdb  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f5ce0  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5ce4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5ce6  b828d25400             -mov eax, 0x54d228
    cpu.eax = 5558824 /*0x54d228*/;
    // 004f5ceb  8d5e58                 -lea ebx, [esi + 0x58]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5cee  e88dc40100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5cf3:
    // 004f5cf3  837e58ff               +cmp dword ptr [esi + 0x58], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5cf7  0f8423010000           -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5cfd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5cff  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d04  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5d09  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f5d0b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004f5d0f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f5d14  8b5e58                 -mov ebx, dword ptr [esi + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5d18  e839e10300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d1d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5d1f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d24  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f5d26  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 004f5d2b  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004f5d2f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f5d34  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d38  e819e10300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d3d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5d3f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d44  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 004f5d49  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 004f5d4e  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5d52  e8ffe00300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d57  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5d5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d5c  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004f5d60  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 004f5d65  8b5e58                 -mov ebx, dword ptr [esi + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5d69  e8e2e00300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f5d6e  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004f5d73  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5d75  e892a9feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f5d7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5d7c  668b442410             -mov ax, word ptr [esp + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f5d81  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004f5d86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d87  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004f5d8c  e8b9e00300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f5d91  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004f5d93  6689442410             -mov word ptr [esp + 0x10], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004f5d98  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d9d  8b6e58                 -mov ebp, dword ptr [esi + 0x58]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5da0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5da1  e89ee00300             -call 0x533e44
    cpu.esp -= 4;
    sub_533e44(app, cpu);
    if (cpu.terminate) return;
    // 004f5da6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5da8  0f8572000000           -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dae  c74424180e000000       -mov dword ptr [esp + 0x18], 0xe
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 14 /*0xe*/;
    // 004f5db6  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5dba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dbb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5dbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dc0  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5dc3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5dc4  e875e00300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f5dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5dcb  7553                   -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dcd  837c24180e             +cmp dword ptr [esp + 0x18], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5dd2  754c                   -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dd4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5dd6  8d565c                 -lea edx, [esi + 0x5c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004f5dd9  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f5dde  e89dfaffff             -call 0x4f5880
    cpu.esp -= 4;
    sub_4f5880(app, cpu);
    if (cpu.terminate) return;
    // 004f5de3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5de7  893550369f00           -mov dword ptr [0x9f3650], esi
    app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */) = cpu.esi;
    // 004f5ded  66894624               -mov word ptr [esi + 0x24], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ax;
    // 004f5df1  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f5df4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f5df9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dfa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5dfc  b8105b4f00             -mov eax, 0x4f5b10
    cpu.eax = 5200656 /*0x4f5b10*/;
    // 004f5e01  e89a99feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f5e06  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5e08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5e0a  7414                   -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
L_0x004f5e0c:
    // 004f5e0c  833d50369f0000         +cmp dword ptr [0x9f3650], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5e13  740b                   -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5e15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5e17  e8c49afeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5e1c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5e1e  75ec                   -jne 0x4f5e0c
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e0c;
    }
L_0x004f5e20:
    // 004f5e20  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5e22  754f                   -jne 0x4f5e73
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e73;
    }
    // 004f5e24  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f5e2b  7d5b                   -jge 0x4f5e88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5e88;
    }
L_0x004f5e2d:
    // 004f5e2d  8b6e58                 -mov ebp, dword ptr [esi + 0x58]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5e30  83fdff                 +cmp ebp, -1
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
    // 004f5e33  7435                   -je 0x4f5e6a
    if (cpu.flags.zf)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5e36  e869e00300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f5e3b  83f8ff                 +cmp eax, -1
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
    // 004f5e3e  752a                   -jne 0x4f5e6a
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e40  e8f3df0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f5e45  8b15e06d5600           -mov edx, dword ptr [0x566de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f5e4b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f5e4f  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5e52  7c16                   -jl 0x4f5e6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5e56  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f5e5a  b84cd25400             -mov eax, 0x54d24c
    cpu.eax = 5558860 /*0x54d24c*/;
    // 004f5e5f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5e61  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5e63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5e65  e816c30100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5e6a:
    // 004f5e6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5e6c  e81fbafeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f5e71  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f5e73:
    // 004f5e73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5e75  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f5e78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5e7d:
    // 004f5e7d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f5e81  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004f5e83  e948feffff             -jmp 0x4f5cd0
    goto L_0x004f5cd0;
L_0x004f5e88:
    // 004f5e88  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5e8a  b840d25400             -mov eax, 0x54d240
    cpu.eax = 5558848 /*0x54d240*/;
    // 004f5e8f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5e91  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5e93  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5e95  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f5e97  e8e4c20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5e9c  eb8f                   -jmp 0x4f5e2d
    goto L_0x004f5e2d;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f5ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5ea1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5ea2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5ea5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5ea7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5ea9  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f5eb0  7d4b                   -jge 0x4f5efd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5efd;
    }
L_0x004f5eb2:
    // 004f5eb2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f5eb5  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f5ebc  e86f9cfeff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f5ec1  8b4e58                 -mov ecx, dword ptr [esi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5ec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ec5  e8dadf0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f5eca  83f8ff                 +cmp eax, -1
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
    // 004f5ecd  7444                   -je 0x4f5f13
    if (cpu.flags.zf)
    {
        goto L_0x004f5f13;
    }
L_0x004f5ecf:
    // 004f5ecf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5ed1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ed2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f5ed3:
    // 004f5ed3  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5ed6  7567                   -jne 0x4f5f3f
    if (!cpu.flags.zf)
    {
        goto L_0x004f5f3f;
    }
    // 004f5ed8  8d4670                 -lea eax, [esi + 0x70]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 004f5edb  e8007f0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f5ee0  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004f5ee6  e8f57e0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f5eeb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5eed  e89eb9feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f5ef2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5ef7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5efa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5efb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5efc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5efd:
    // 004f5efd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5eff  b858d25400             -mov eax, 0x54d258
    cpu.eax = 5558872 /*0x54d258*/;
    // 004f5f04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5f06  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5f08  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5f0a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f5f0c  e86fc20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5f11  eb9f                   -jmp 0x4f5eb2
    goto L_0x004f5eb2;
L_0x004f5f13:
    // 004f5f13  e820df0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f5f18  8b1de06d5600           -mov ebx, dword ptr [0x566de0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f5f1e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f5f22  83fb04                 +cmp ebx, 4
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
    // 004f5f25  7ca8                   -jl 0x4f5ecf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5ecf;
    }
    // 004f5f27  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5f29  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5f2d  b868d25400             -mov eax, 0x54d268
    cpu.eax = 5558888 /*0x54d268*/;
    // 004f5f32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5f34  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5f36  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004f5f38  e843c20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5f3d  eb90                   -jmp 0x4f5ecf
    goto L_0x004f5ecf;
L_0x004f5f3f:
    // 004f5f3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f5f41  e89a99feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5f46  eb8b                   -jmp 0x4f5ed3
    goto L_0x004f5ed3;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5f51  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f5f56  83c024                 -add eax, 0x24
    (cpu.eax) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f5f59  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f5f5b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f5f5d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f5f5f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f5f66  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f5f68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5f71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5f72  8d485c                 -lea ecx, [eax + 0x5c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004f5f75  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f5f77  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5f79  e802cd0100             -call 0x512c80
    cpu.esp -= 4;
    sub_512c80(app, cpu);
    if (cpu.terminate) return;
    // 004f5f7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f5f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f90  e9dbcd0100             -jmp 0x512d70
    return sub_512d70(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5fa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5fa4  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 004f5fa9  83c026                 -add eax, 0x26
    (cpu.eax) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 004f5fac  e87faefeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f5fb1  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004f5fb4  e817c80100             -call 0x5127d0
    cpu.esp -= 4;
    sub_5127d0(app, cpu);
    if (cpu.terminate) return;
    // 004f5fb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5fba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5fbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fc0  c6402600               -mov byte ptr [eax + 0x26], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(38) /* 0x26 */) = 0 /*0x0*/;
    // 004f5fc4  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f5fca  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f5fd0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5fe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5fe1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5fe2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5fe3  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004f5fe8  8d7b04                 -lea edi, [ebx + 4]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f5feb  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5fee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f5ff0  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f5ff2  7405                   -je 0x4f5ff9
    if (cpu.flags.zf)
    {
        goto L_0x004f5ff9;
    }
    // 004f5ff4  19c0                   +sbb eax, eax
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
    // 004f5ff6  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f5ff9:
    // 004f5ff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5ffb  7509                   -jne 0x4f6006
    if (!cpu.flags.zf)
    {
        goto L_0x004f6006;
    }
    // 004f5ffd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6002  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6003  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6005  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6006:
    // 004f6006  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6008  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6009  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f600a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f600b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f6010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6012  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f6014  8d705c                 -lea esi, [eax + 0x5c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004f6017  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f601c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f601f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6020  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6021  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f6030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6033  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f6036  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6038  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004f603d  e88e810100             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 004f6042  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6044  760c                   -jbe 0x4f6052
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6052;
    }
L_0x004f6046:
    // 004f6046  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f604b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f604e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f604f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6050  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6051  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6052:
    // 004f6052  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6056  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6057  687f660440             -push 0x4004667f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1074030207 /*0x4004667f*/;
    cpu.esp -= 4;
    // 004f605c  8b5358                 -mov edx, dword ptr [ebx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004f605f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6060  e8ebdd0300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f6065  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f6068  83f8ff                 +cmp eax, -1
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
    // 004f606b  7410                   -je 0x4f607d
    if (cpu.flags.zf)
    {
        goto L_0x004f607d;
    }
    // 004f606d  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004f6072  77d2                   -ja 0x4f6046
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f6046;
    }
    // 004f6074  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6076  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f6079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f607c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f607d:
    // 004f607d  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f6084  7c1a                   -jl 0x4f60a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f60a0;
    }
    // 004f6086  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6088  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f608d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6091  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f6093  b874d25400             -mov eax, 0x54d274
    cpu.eax = 5558900 /*0x54d274*/;
    // 004f6098  83c358                 -add ebx, 0x58
    (cpu.ebx) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004f609b  e8e0c00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f60a0:
    // 004f60a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f60a2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f60a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f60a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f60b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f60b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f60b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f60b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f60b3  81ec38010000           -sub esp, 0x138
    (cpu.esp) -= x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f60b9  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004f60c0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f60c2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f60c4  899c242c010000         -mov dword ptr [esp + 0x12c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.ebx;
    // 004f60cb  81ff18010000           +cmp edi, 0x118
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(280 /*0x118*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f60d1  7e05                   -jle 0x4f60d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f60d8;
    }
    // 004f60d3  bf18010000             -mov edi, 0x118
    cpu.edi = 280 /*0x118*/;
L_0x004f60d8:
    // 004f60d8  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004f60df  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f60e3  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f60e5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f60e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f60ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f60ec  e8ff43ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f60f1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f60f3  0f84a6000000           -je 0x4f619f
    if (cpu.flags.zf)
    {
        goto L_0x004f619f;
    }
    // 004f60f9  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004f6100  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6102  e8b9f7ffff             -call 0x4f58c0
    cpu.esp -= 4;
    sub_4f58c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f6107:
    // 004f6107  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f610d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f610e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6114  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004f6116  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004f611d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f611e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6120  8d4704                 -lea eax, [edi + 4]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f6123  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6124  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6128  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6129  8b4d58                 -mov ecx, dword ptr [ebp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    // 004f612c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f612d  e800dd0300             -call 0x533e32
    cpu.esp -= 4;
    sub_533e32(app, cpu);
    if (cpu.terminate) return;
    // 004f6132  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6134  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 004f613b  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6140  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6141  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6147  83fbff                 +cmp ebx, -1
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
    // 004f614a  756a                   -jne 0x4f61b6
    if (!cpu.flags.zf)
    {
        goto L_0x004f61b6;
    }
    // 004f614c  e8e7dc0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f6151  8b0de06d5600           -mov ecx, dword ptr [0x566de0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f6157  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004f615e  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6161  7c1d                   -jl 0x4f6180
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6180;
    }
    // 004f6163  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6165  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f616a  8d942434010000         -lea edx, [esp + 0x134]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004f6171  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f6173  b884d25400             -mov eax, 0x54d284
    cpu.eax = 5558916 /*0x54d284*/;
    // 004f6178  8d5d58                 -lea ebx, [ebp + 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(88) /* 0x58 */);
L_0x004f617b:
    // 004f617b  e800c00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f6180:
    // 004f6180  8b9c2434010000         -mov ebx, dword ptr [esp + 0x134]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004f6187  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f618a  39df                   +cmp edi, ebx
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
    // 004f618c  754a                   -jne 0x4f61d8
    if (!cpu.flags.zf)
    {
        goto L_0x004f61d8;
    }
    // 004f618e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6193  81c438010000           -add esp, 0x138
    (cpu.esp) += x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f6199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f619c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f619f:
    // 004f619f  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 004f61a2  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004f61a9  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004f61ac  e84ff7ffff             -call 0x4f5900
    cpu.esp -= 4;
    sub_4f5900(app, cpu);
    if (cpu.terminate) return;
    // 004f61b1  e951ffffff             -jmp 0x4f6107
    goto L_0x004f6107;
L_0x004f61b6:
    // 004f61b6  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f61bd  7cc1                   -jl 0x4f6180
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6180;
    }
    // 004f61bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f61c1  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f61c6  8d942430010000         -lea edx, [esp + 0x130]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004f61cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f61cf  b890d25400             -mov eax, 0x54d290
    cpu.eax = 5558928 /*0x54d290*/;
    // 004f61d4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f61d6  eba3                   -jmp 0x4f617b
    goto L_0x004f617b;
L_0x004f61d8:
    // 004f61d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f61da  81c438010000           -add esp, 0x138
    (cpu.esp) += x86::reg32(x86::sreg32(312 /*0x138*/));
    // 004f61e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f61e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f61f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f61f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f61f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f61f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f61f3  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f61f6  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004f61fa  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f61fe  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f6202  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f6206  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f620a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f620c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f620e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f6211  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6215  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6216  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6217  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6218  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6219  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f621a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f621c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f6220  8db08c000000           -lea esi, [eax + 0x8c]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004f6226  ba805a4f00             -mov edx, 0x4f5a80
    cpu.edx = 5200512 /*0x4f5a80*/;
    // 004f622b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f622d  e86e830100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f6232  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6234  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6236  745f                   -je 0x4f6297
    if (cpu.flags.zf)
    {
        goto L_0x004f6297;
    }
    // 004f6238  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f623c  83c770                 -add edi, 0x70
    (cpu.edi) += x86::reg32(x86::sreg32(112 /*0x70*/));
L_0x004f623f:
    // 004f623f  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f6244  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6247  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f624a  7d60                   -jge 0x4f62ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f62ac;
    }
    // 004f624c  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f6253  7c19                   -jl 0x4f626e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f626e;
    }
    // 004f6255  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6257  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f625c  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f625f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6261  b89cd25400             -mov eax, 0x54d29c
    cpu.eax = 5558940 /*0x54d29c*/;
    // 004f6266  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f6269  e812bf0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f626e:
    // 004f626e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f6270  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6272  e8d97b0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f6277  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f627b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f627d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6280  ba805a4f00             -mov edx, 0x4f5a80
    cpu.edx = 5200512 /*0x4f5a80*/;
    // 004f6285  e8a698feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f628a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f628c  e80f830100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f6291  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6293  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6295  75a8                   -jne 0x4f623f
    if (!cpu.flags.zf)
    {
        goto L_0x004f623f;
    }
L_0x004f6297:
    // 004f6297  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f629b  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004f62a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f62a3  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f62a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f62a9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f62ac:
    // 004f62ac  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f62af  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f62b2  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004f62b6  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004f62ba  39c8                   +cmp eax, ecx
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
    // 004f62bc  0f8e78000000           -jle 0x4f633a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f633a;
    }
    // 004f62c2  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
L_0x004f62c6:
    // 004f62c6  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f62ca  8d750c                 -lea esi, [ebp + 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f62cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f62d2  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f62d6  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f62d9  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f62dd  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f62df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f62e1  740e                   -je 0x4f62f1
    if (cpu.flags.zf)
    {
        goto L_0x004f62f1;
    }
    // 004f62e3  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f62e7  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004f62ea  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f62ec  e8ff41ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f62f1:
    // 004f62f1  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f62f8  7c19                   -jl 0x4f6313
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6313;
    }
    // 004f62fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f62fc  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f6301  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f6304  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6306  b8a8d25400             -mov eax, 0x54d2a8
    cpu.eax = 5558952 /*0x54d2a8*/;
    // 004f630b  8d5520                 -lea edx, [ebp + 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f630e  e86dbe0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f6313:
    // 004f6313  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6317  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f6319  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f631c  e82f7b0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f6321  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f6325  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6328  e80398feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f632d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f6331  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f6334  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6335  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6336  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6337  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f633a:
    // 004f633a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f633c  7d88                   -jge 0x4f62c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f62c6;
    }
    // 004f633e  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f6340  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 004f6344  eb80                   -jmp 0x4f62c6
    goto L_0x004f62c6;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6350  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6351  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f6354  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6356  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f635a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f635d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f635f  7531                   -jne 0x4f6392
    if (!cpu.flags.zf)
    {
        goto L_0x004f6392;
    }
    // 004f6361  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004f6365:
    // 004f6365  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f636c  7d39                   -jge 0x4f63a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f63a7;
    }
L_0x004f636e:
    // 004f636e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f6370  bac05a4f00             -mov edx, 0x4f5ac0
    cpu.edx = 5200576 /*0x4f5ac0*/;
    // 004f6375  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004f637b  e830860100             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 004f6380  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f6383  e8a897feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f6388  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f638d  83c420                 +add esp, 0x20
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
    // 004f6390  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6391  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6392:
    // 004f6392  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6394  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6398  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f639a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f639f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f63a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f63a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f63a5  ebbe                   -jmp 0x4f6365
    goto L_0x004f6365;
L_0x004f63a7:
    // 004f63a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f63a9  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f63ae  b8b4d25400             -mov eax, 0x54d2b4
    cpu.eax = 5558964 /*0x54d2b4*/;
    // 004f63b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f63b5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f63b7  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f63bb  e8c0bd0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f63c0  ebac                   -jmp 0x4f636e
    goto L_0x004f636e;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f63d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f63d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f63d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f63d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f63d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f63d4  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f63da  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f63dc  833d8044560000         +cmp dword ptr [0x564480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f63e3  0f8487000000           -je 0x4f6470
    if (cpu.flags.zf)
    {
        goto L_0x004f6470;
    }
L_0x004f63e9:
    // 004f63e9  833d846e560000         +cmp dword ptr [0x566e84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f63f0  7565                   -jne 0x4f6457
    if (!cpu.flags.zf)
    {
        goto L_0x004f6457;
    }
    // 004f63f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f63f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f63f5  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f63fa  e8b1da0300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f63ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6401  7554                   -jne 0x4f6457
    if (!cpu.flags.zf)
    {
        goto L_0x004f6457;
    }
    // 004f6403  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6405  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f6407  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6409  e802f8ffff             -call 0x4f5c10
    cpu.esp -= 4;
    sub_4f5c10(app, cpu);
    if (cpu.terminate) return;
    // 004f640e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6410  743e                   -je 0x4f6450
    if (cpu.flags.zf)
    {
        goto L_0x004f6450;
    }
    // 004f6412  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f6417  891d846e5600           -mov dword ptr [0x566e84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */) = cpu.ebx;
    // 004f641d  e87efaffff             -call 0x4f5ea0
    cpu.esp -= 4;
    sub_4f5ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f6422  a1e46d5600             -mov eax, dword ptr [0x566de4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f6427  bf246e5600             -mov edi, 0x566e24
    cpu.edi = 5664292 /*0x566e24*/;
    // 004f642c  bde8895600             -mov ebp, 0x5689e8
    cpu.ebp = 5671400 /*0x5689e8*/;
    // 004f6431  893c85d0259f00         -mov dword ptr [eax*4 + 0x9f25d0], edi
    app->getMemory<x86::reg32>(x86::reg32(10429904) /* 0x9f25d0 */ + cpu.eax * 4) = cpu.edi;
    // 004f6438  892c85b0259f00         -mov dword ptr [eax*4 + 0x9f25b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(10429872) /* 0x9f25b0 */ + cpu.eax * 4) = cpu.ebp;
    // 004f643f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f6441  a3e46d5600             -mov dword ptr [0x566de4], eax
    app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */) = cpu.eax;
    // 004f6446  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6448  7406                   -je 0x4f6450
    if (cpu.flags.zf)
    {
        goto L_0x004f6450;
    }
    // 004f644a  8935246e5600           -mov dword ptr [0x566e24], esi
    app->getMemory<x86::reg32>(x86::reg32(5664292) /* 0x566e24 */) = cpu.esi;
L_0x004f6450:
    // 004f6450  e849da0300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f6455  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6456  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f6457:
    // 004f6457  833d846e560000         +cmp dword ptr [0x566e84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664388) /* 0x566e84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f645e  741f                   -je 0x4f647f
    if (cpu.flags.zf)
    {
        goto L_0x004f647f;
    }
    // 004f6460  b8286e5600             -mov eax, 0x566e28
    cpu.eax = 5664296 /*0x566e28*/;
    // 004f6465  81c490010000           +add esp, 0x190
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f646b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f646f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6470:
    // 004f6470  e86b4effff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6475  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004f647a  e96affffff             -jmp 0x4f63e9
    goto L_0x004f63e9;
L_0x004f647f:
    // 004f647f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6481  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f6487  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6488  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6489  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f648a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f648b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f6490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6491  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6492  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6493  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6494  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6497  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6499  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f649b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f649d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f649f  e806da0300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f64a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f64a6  83f8ff                 +cmp eax, -1
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
    // 004f64a9  750f                   -jne 0x4f64ba
    if (!cpu.flags.zf)
    {
        goto L_0x004f64ba;
    }
    // 004f64ab  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x004f64b0:
    // 004f64b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f64b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f64b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f64b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f64ba:
    // 004f64ba  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004f64bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f64c1  e846a2feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f64c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f64c8  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 004f64cb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f64d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f64d1  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004f64d6  e86fd90300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f64db  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f64dd  6689442406             -mov word ptr [esp + 6], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004f64e2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f64e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f64e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f64e8  e857d90300             -call 0x533e44
    cpu.esp -= 4;
    sub_533e44(app, cpu);
    if (cpu.terminate) return;
    // 004f64ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f64ef  74bf                   -je 0x4f64b0
    if (cpu.flags.zf)
    {
        goto L_0x004f64b0;
    }
    // 004f64f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f64f2  e8add90300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f64f7  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f64fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f64fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6502  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6504  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6505  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6514  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6517  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6519  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f651b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f651c  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 004f6521  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f6526  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6527  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f652b  e820d90300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f6530  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f6532  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6536  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6537  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f6539  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f653e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f6543  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6544  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004f6548  e809d90300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f654d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f654f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6553  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6554  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6559  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f655a  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004f655c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f655d  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004f6561  e8f0d80300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f6566  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6569  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f656d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f6570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6572  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6574  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6575  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f6577  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f657a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f657c  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f657e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f6580  83ff01                 +cmp edi, 1
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
    // 004f6583  0f856a000000           -jne 0x4f65f3
    if (!cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f6589  837948ff               +cmp dword ptr [ecx + 0x48], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f658d  7464                   -je 0x4f65f3
    if (cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f658f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f6591  3b4b38                 +cmp ecx, dword ptr [ebx + 0x38]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6594  745d                   -je 0x4f65f3
    if (cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f6596  8b9a10030000           -mov ebx, dword ptr [edx + 0x310]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */);
    // 004f659c  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004f65a3  43                     -inc ebx
    (cpu.ebx)++;
    // 004f65a4  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004f65a7  899a10030000           -mov dword ptr [edx + 0x310], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(784) /* 0x310 */) = cpu.ebx;
    // 004f65ad  898c3a14030000         -mov dword ptr [edx + edi + 0x314], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(788) /* 0x314 */ + cpu.edi * 1) = cpu.ecx;
    // 004f65b4  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f65b7  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f65ba  7242                   -jb 0x4f65fe
    if (cpu.flags.cf)
    {
        goto L_0x004f65fe;
    }
L_0x004f65bc:
    // 004f65bc  8bb80c020000           -mov edi, dword ptr [eax + 0x20c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(524) /* 0x20c */);
    // 004f65c2  83ff40                 +cmp edi, 0x40
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
    // 004f65c5  731a                   -jae 0x4f65e1
    if (!cpu.flags.cf)
    {
        goto L_0x004f65e1;
    }
    // 004f65c7  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004f65ce  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004f65d1  89900c020000           -mov dword ptr [eax + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 004f65d7  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f65da  89940110020000         -mov dword ptr [ecx + eax + 0x210], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(528) /* 0x210 */ + cpu.eax * 1) = cpu.edx;
L_0x004f65e1:
    // 004f65e1  66837d0600             +cmp word ptr [ebp + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f65e6  760b                   -jbe 0x4f65f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f65f3;
    }
    // 004f65e8  8ba808010000           -mov ebp, dword ptr [eax + 0x108]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */);
    // 004f65ee  83fd40                 +cmp ebp, 0x40
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f65f1  721f                   -jb 0x4f6612
    if (cpu.flags.cf)
    {
        goto L_0x004f6612;
    }
L_0x004f65f3:
    // 004f65f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f65f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f65fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f65fe:
    // 004f65fe  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004f6605  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f6606  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f6609  8b4948                 -mov ecx, dword ptr [ecx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004f660c  894c3a08               -mov dword ptr [edx + edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.edi * 1) = cpu.ecx;
    // 004f6610  ebaa                   -jmp 0x4f65bc
    goto L_0x004f65bc;
L_0x004f6612:
    // 004f6612  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 004f6619  8d5501                 -lea edx, [ebp + 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004f661c  899008010000           -mov dword ptr [eax + 0x108], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(264) /* 0x108 */) = cpu.edx;
    // 004f6622  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6625  8994010c010000         -mov dword ptr [ecx + eax + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */ + cpu.eax * 1) = cpu.edx;
    // 004f662c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6631  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6632  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6633  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6634  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6635  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6636  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f6640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6642  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6643  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6644  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6645  81ec10040000           -sub esp, 0x410
    (cpu.esp) -= x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 004f664b  8984240c040000         -mov dword ptr [esp + 0x40c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */) = cpu.eax;
    // 004f6652  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f6654  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f6657  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f665d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f665e  8984240c040000         -mov dword ptr [esp + 0x40c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */) = cpu.eax;
    // 004f6665  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f666b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f666d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f666f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6673  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6675  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6676  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6679  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f667a  e8add70300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f667f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6681  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6683  7430                   -je 0x4f66b5
    if (cpu.flags.zf)
    {
        goto L_0x004f66b5;
    }
    // 004f6685  83f8ff                 +cmp eax, -1
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
    // 004f6688  741f                   -je 0x4f66a9
    if (cpu.flags.zf)
    {
        goto L_0x004f66a9;
    }
L_0x004f668a:
    // 004f668a  83fb02                 +cmp ebx, 2
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
    // 004f668d  7d2d                   -jge 0x4f66bc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f66bc;
    }
L_0x004f668f:
    // 004f668f  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6694  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6695  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f669b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f669d  81c410040000           -add esp, 0x410
    (cpu.esp) += x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 004f66a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f66a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f66a9:
    // 004f66a9  e88ad70300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f66ae  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f66b3  74d5                   -je 0x4f668a
    if (cpu.flags.zf)
    {
        goto L_0x004f668a;
    }
L_0x004f66b5:
    // 004f66b5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f66ba  ebd3                   -jmp 0x4f668f
    goto L_0x004f668f;
L_0x004f66bc:
    // 004f66bc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f66c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f66c3  8b9c2408040000         -mov ebx, dword ptr [esp + 0x408]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004f66ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f66cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f66ce  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f66d0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f66d2  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f66d9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f66db  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f66df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f66e1  39d0                   +cmp eax, edx
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
    // 004f66e3  7e07                   -jle 0x4f66ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f66ec;
    }
    // 004f66e5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f66ea  eba3                   -jmp 0x4f668f
    goto L_0x004f668f;
L_0x004f66ec:
    // 004f66ec  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f66ee  8d5802                 -lea ebx, [eax + 2]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004f66f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f66f2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f66f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f66f7  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f66fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f66fb  e82cd70300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f6700  89842404040000         -mov dword ptr [esp + 0x404], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.eax;
    // 004f6707  39d8                   +cmp eax, ebx
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
    // 004f6709  756a                   -jne 0x4f6775
    if (!cpu.flags.zf)
    {
        goto L_0x004f6775;
    }
    // 004f670b  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f6712  7c18                   -jl 0x4f672c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f672c;
    }
    // 004f6714  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6716  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f671b  b8c8d25400             -mov eax, 0x54d2c8
    cpu.eax = 5558984 /*0x54d2c8*/;
    // 004f6720  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f6722  8d5e34                 -lea ebx, [esi + 0x34]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f6725  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6727  e854ba0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f672c:
    // 004f672c  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004f6733  83784000               +cmp dword ptr [eax + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6737  7410                   -je 0x4f6749
    if (cpu.flags.zf)
    {
        goto L_0x004f6749;
    }
    // 004f6739  8b9c240c040000         -mov ebx, dword ptr [esp + 0x40c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004f6740  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f6743  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004f6746  ff5340                 -call dword ptr [ebx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f6749:
    // 004f6749  8d542402               -lea edx, [esp + 2]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004f674d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f674f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6751  e89abf0100             -call 0x5126f0
    cpu.esp -= 4;
    sub_5126f0(app, cpu);
    if (cpu.terminate) return;
    // 004f6756  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6758  741b                   -je 0x4f6775
    if (cpu.flags.zf)
    {
        goto L_0x004f6775;
    }
    // 004f675a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f675c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f675f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6760  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6764  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6765  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f6768  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6769  e8bed60300             -call 0x533e2c
    cpu.esp -= 4;
    sub_533e2c(app, cpu);
    if (cpu.terminate) return;
    // 004f676e  89842404040000         -mov dword ptr [esp + 0x404], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.eax;
L_0x004f6775:
    // 004f6775  8bb42404040000         -mov esi, dword ptr [esp + 0x404]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 004f677c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f677e  7419                   -je 0x4f6799
    if (cpu.flags.zf)
    {
        goto L_0x004f6799;
    }
    // 004f6780  83feff                 +cmp esi, -1
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
    // 004f6783  0f8506ffffff           -jne 0x4f668f
    if (!cpu.flags.zf)
    {
        goto L_0x004f668f;
    }
    // 004f6789  e8aad60300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f678e  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6793  0f84f6feffff           -je 0x4f668f
    if (cpu.flags.zf)
    {
        goto L_0x004f668f;
    }
L_0x004f6799:
    // 004f6799  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f679e  e9ecfeffff             -jmp 0x4f668f
    goto L_0x004f668f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f67b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f67b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f67b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f67b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f67b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f67b4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f67b6  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f67b9  668b5306               -mov dx, word ptr [ebx + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f67bd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f67bf  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f67c2  7707                   -ja 0x4f67cb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f67cb;
    }
    // 004f67c4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f67c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f67ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f67cb:
    // 004f67cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f67cc  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f67d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f67d3  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f67d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f67db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f67dc  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f67e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f67e1  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f67e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f67e5  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f67e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f67e9  e838d60300             -call 0x533e26
    cpu.esp -= 4;
    sub_533e26(app, cpu);
    if (cpu.terminate) return;
    // 004f67ee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f67f0  83f8ff                 +cmp eax, -1
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
    // 004f67f3  7532                   -jne 0x4f6827
    if (!cpu.flags.zf)
    {
        goto L_0x004f6827;
    }
    // 004f67f5  e83ed60300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f67fa  3d47270000             +cmp eax, 0x2747
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10055 /*0x2747*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f67ff  7412                   -je 0x4f6813
    if (cpu.flags.zf)
    {
        goto L_0x004f6813;
    }
    // 004f6801  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6806  740b                   -je 0x4f6813
    if (cpu.flags.zf)
    {
        goto L_0x004f6813;
    }
    // 004f6808  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f680d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
L_0x004f6813:
    // 004f6813  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6818  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6819  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f681f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6820  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6822  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6823  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6824  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6825  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6826  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6827:
    // 004f6827  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6829  7ee8                   -jle 0x4f6813
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f6813;
    }
    // 004f682b  668b4b06               -mov cx, word ptr [ebx + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004f682f  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f6832  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6834  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f6836  66894b06               -mov word ptr [ebx + 6], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 004f683a  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004f683d  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6842  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6843  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6849  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f684c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f684f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6850  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f6860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6860  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6865  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f6870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f6872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6873  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6875  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6878  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6879  e826d60300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f687e  c74348ffffffff         -mov dword ptr [ebx + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f6885  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f688a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f688c  e8bf780100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f6891  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6893  7504                   -jne 0x4f6899
    if (!cpu.flags.zf)
    {
        goto L_0x004f6899;
    }
    // 004f6895  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6896  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6897  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6899:
    // 004f6899  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f68a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f68a2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f68a4  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f68a7  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f68ac  e89f750100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f68b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f68b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f68c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f68c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f68c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f68c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f68c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f68c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f68c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f68c6  81ec30040000           -sub esp, 0x430
    (cpu.esp) -= x86::reg32(x86::sreg32(1072 /*0x430*/));
    // 004f68cc  a1f0379f00             -mov eax, dword ptr [0x9f37f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434544) /* 0x9f37f0 */);
    // 004f68d1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f68d4  c6404701               -mov byte ptr [eax + 0x47], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(71) /* 0x47 */) = 1 /*0x1*/;
    // 004f68d8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68db  80784600               +cmp byte ptr [eax + 0x46], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f68df  0f85b2020000           -jne 0x4f6b97
    if (!cpu.flags.zf)
    {
        goto L_0x004f6b97;
    }
L_0x004f68e5:
    // 004f68e5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68e8  8b503c                 -mov edx, dword ptr [eax + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f68eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f68ed  0f84b8020000           -je 0x4f6bab
    if (cpu.flags.zf)
    {
        goto L_0x004f6bab;
    }
    // 004f68f3  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
L_0x004f68f6:
    // 004f68f6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f68f9  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f68fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f68fe  83f9ff                 +cmp ecx, -1
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
    // 004f6901  7431                   -je 0x4f6934
    if (cpu.flags.zf)
    {
        goto L_0x004f6934;
    }
    // 004f6903  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6905  0f84a7020000           -je 0x4f6bb2
    if (cpu.flags.zf)
    {
        goto L_0x004f6bb2;
    }
    // 004f690b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f690e  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f6911  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004f6914  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6916  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6918  0f8594020000           -jne 0x4f6bb2
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bb2;
    }
L_0x004f691e:
    // 004f691e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6921  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6924  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6925  e87ad50300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f692a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f692d  c7401cffffffff         -mov dword ptr [eax + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
L_0x004f6934:
    // 004f6934  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6936  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6939  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004f693d  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 004f6944  89bc240c020000         -mov dword ptr [esp + 0x20c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edi;
    // 004f694b  89bc2410030000         -mov dword ptr [esp + 0x310], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.edi;
    // 004f6952  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6956  0f856c020000           -jne 0x4f6bc8
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bc8;
    }
    // 004f695c  c744240401000000       -mov dword ptr [esp + 4], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004f6964  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6967  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004f696b:
    // 004f696b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f696e  8b7038                 -mov esi, dword ptr [eax + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f6971  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6973  744b                   -je 0x4f69c0
    if (cpu.flags.zf)
    {
        goto L_0x004f69c0;
    }
    // 004f6975  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f697c  83ff40                 +cmp edi, 0x40
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
    // 004f697f  7314                   -jae 0x4f6995
    if (!cpu.flags.cf)
    {
        goto L_0x004f6995;
    }
    // 004f6981  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004f6984  89ac2408010000         -mov dword ptr [esp + 0x108], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebp;
    // 004f698b  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004f698e  8984bc0c010000         -mov dword ptr [esp + edi*4 + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */ + cpu.edi * 4) = cpu.eax;
L_0x004f6995:
    // 004f6995  83bc240c02000040       +cmp dword ptr [esp + 0x20c], 0x40
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f699d  7321                   -jae 0x4f69c0
    if (!cpu.flags.cf)
    {
        goto L_0x004f69c0;
    }
    // 004f699f  8b94240c020000         -mov edx, dword ptr [esp + 0x20c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f69a6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f69a9  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004f69ac  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f69af  898c240c020000         -mov dword ptr [esp + 0x20c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.ecx;
    // 004f69b6  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f69b9  89849410020000         -mov dword ptr [esp + edx*4 + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.edx * 4) = cpu.eax;
L_0x004f69c0:
    // 004f69c0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f69c2  ba70654f00             -mov edx, 0x4f6570
    cpu.edx = 5203312 /*0x4f6570*/;
    // 004f69c7  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f69cc  e8df7f0100             -call 0x50e9b0
    cpu.esp -= 4;
    sub_50e9b0(app, cpu);
    if (cpu.terminate) return;
    // 004f69d1  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f69d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f69d8  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f69de  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f69e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f69e5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f69eb  8d842424040000         -lea eax, [esp + 0x424]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1060) /* 0x424 */);
    // 004f69f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f69f3  8d842410020000         -lea eax, [esp + 0x210]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 004f69fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f69fb  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004f6a02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a03  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a08  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6a0a  bda8610000             -mov ebp, 0x61a8
    cpu.ebp = 25000 /*0x61a8*/;
    // 004f6a0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6a10  89bc2438040000         -mov dword ptr [esp + 0x438], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1080) /* 0x438 */) = cpu.edi;
    // 004f6a17  89ac243c040000         -mov dword ptr [esp + 0x43c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1084) /* 0x43c */) = cpu.ebp;
    // 004f6a1e  e8fdd30300             -call 0x533e20
    cpu.esp -= 4;
    sub_533e20(app, cpu);
    if (cpu.terminate) return;
    // 004f6a23  83f8ff                 +cmp eax, -1
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
    // 004f6a26  0f845e010000           -je 0x4f6b8a
    if (cpu.flags.zf)
    {
        goto L_0x004f6b8a;
    }
    // 004f6a2c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6a30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a31  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6a35  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6a38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6a39  e8dcd30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6a3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6a40  7440                   -je 0x4f6a82
    if (cpu.flags.zf)
    {
        goto L_0x004f6a82;
    }
    // 004f6a42  8d84242c040000         -lea eax, [esp + 0x42c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1068) /* 0x42c */);
    // 004f6a49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a4a  8d842418040000         -lea eax, [esp + 0x418]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 004f6a51  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004f6a56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a57  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f6a5b  898c2434040000         -mov dword ptr [esp + 0x434], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1076) /* 0x434 */) = cpu.ecx;
    // 004f6a62  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f6a65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6a66  e8a9d30300             -call 0x533e14
    cpu.esp -= 4;
    sub_533e14(app, cpu);
    if (cpu.terminate) return;
    // 004f6a6b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a6e  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f6a71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a74  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6a78  0f8559010000           -jne 0x4f6bd7
    if (!cpu.flags.zf)
    {
        goto L_0x004f6bd7;
    }
    // 004f6a7e  c6404601               -mov byte ptr [eax + 0x46], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */) = 1 /*0x1*/;
L_0x004f6a82:
    // 004f6a82  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6a85  8b6d38                 -mov ebp, dword ptr [ebp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 004f6a88  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f6a8a  742a                   -je 0x4f6ab6
    if (cpu.flags.zf)
    {
        goto L_0x004f6ab6;
    }
    // 004f6a8c  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f6a93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a94  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f6a97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6a98  e87dd30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6a9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6a9f  0f8478010000           -je 0x4f6c1d
    if (cpu.flags.zf)
    {
        goto L_0x004f6c1d;
    }
    // 004f6aa5  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6aac:
    // 004f6aac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6aaf  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
L_0x004f6ab6:
    // 004f6ab6  8b842410030000         -mov eax, dword ptr [esp + 0x310]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004f6abd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f6abf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ac1  0f8ec3000000           -jle 0x4f6b8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f6b8a;
    }
    // 004f6ac7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f6ac9:
    // 004f6ac9  8b841c14030000         -mov eax, dword ptr [esp + ebx + 0x314]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6ad0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f6ad2  837848ff               +cmp dword ptr [eax + 0x48], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ad6  0f8485000000           -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6adc  39e8                   +cmp eax, ebp
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
    // 004f6ade  0f847d000000           -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6ae4  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6ae8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6ae9  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6aec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6aed  e828d30300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6af4  7411                   -je 0x4f6b07
    if (cpu.flags.zf)
    {
        goto L_0x004f6b07;
    }
    // 004f6af6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6af9  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b00  e83bfbffff             -call 0x4f6640
    cpu.esp -= 4;
    sub_4f6640(app, cpu);
    if (cpu.terminate) return;
    // 004f6b05  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f6b07:
    // 004f6b07  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f6b0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b0f  8b841c18030000         -mov eax, dword ptr [esp + ebx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */ + cpu.ebx * 1);
    // 004f6b16  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6b19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b1a  e8fbd20300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6b1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6b21  7411                   -je 0x4f6b34
    if (cpu.flags.zf)
    {
        goto L_0x004f6b34;
    }
    // 004f6b23  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b26  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b2d  e87efcffff             -call 0x4f67b0
    cpu.esp -= 4;
    sub_4f67b0(app, cpu);
    if (cpu.terminate) return;
    // 004f6b32  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f6b34:
    // 004f6b34  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 004f6b3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b3c  8b841c18030000         -mov eax, dword ptr [esp + ebx + 0x318]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */ + cpu.ebx * 1);
    // 004f6b43  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f6b46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6b47  e8ced20300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6b4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6b4e  7411                   -je 0x4f6b61
    if (cpu.flags.zf)
    {
        goto L_0x004f6b61;
    }
    // 004f6b50  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b53  8b941c14030000         -mov edx, dword ptr [esp + ebx + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b5a  e801fdffff             -call 0x4f6860
    cpu.esp -= 4;
    sub_4f6860(app, cpu);
    if (cpu.terminate) return;
    // 004f6b5f  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f6b61:
    // 004f6b61  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6b63  7412                   -je 0x4f6b77
    if (cpu.flags.zf)
    {
        goto L_0x004f6b77;
    }
    // 004f6b65  8bb41c14030000         -mov esi, dword ptr [esp + ebx + 0x314]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */ + cpu.ebx * 1);
    // 004f6b6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6b6e  7407                   -je 0x4f6b77
    if (cpu.flags.zf)
    {
        goto L_0x004f6b77;
    }
    // 004f6b70  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f6b72  e8f9fcffff             -call 0x4f6870
    cpu.esp -= 4;
    sub_4f6870(app, cpu);
    if (cpu.terminate) return;
L_0x004f6b77:
    // 004f6b77  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004f6b7e  47                     -inc edi
    (cpu.edi)++;
    // 004f6b7f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f6b82  39d7                   +cmp edi, edx
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
    // 004f6b84  0f8c3fffffff           -jl 0x4f6ac9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6ac9;
    }
L_0x004f6b8a:
    // 004f6b8a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b8d  80784600               +cmp byte ptr [eax + 0x46], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(70) /* 0x46 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f6b91  0f844efdffff           -je 0x4f68e5
    if (cpu.flags.zf)
    {
        goto L_0x004f68e5;
    }
L_0x004f6b97:
    // 004f6b97  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6b9a  c6404700               -mov byte ptr [eax + 0x47], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(71) /* 0x47 */) = 0 /*0x0*/;
    // 004f6b9e  81c430040000           -add esp, 0x430
    (cpu.esp) += x86::reg32(x86::sreg32(1072 /*0x430*/));
    // 004f6ba4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6ba9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6baa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6bab:
    // 004f6bab  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6bad  e944fdffff             -jmp 0x4f68f6
    goto L_0x004f68f6;
L_0x004f6bb2:
    // 004f6bb2  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f6bb7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6bba  3b4234                 +cmp eax, dword ptr [edx + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6bbd  0f8f5bfdffff           -jg 0x4f691e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f691e;
    }
    // 004f6bc3  e96cfdffff             -jmp 0x4f6934
    goto L_0x004f6934;
L_0x004f6bc8:
    // 004f6bc8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f6bcd  e80e8dfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6bd2  e994fdffff             -jmp 0x4f696b
    goto L_0x004f696b;
L_0x004f6bd7:
    // 004f6bd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f6bd9  6689942414040000       -mov word ptr [esp + 0x414], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(1044) /* 0x414 */) = cpu.dx;
    // 004f6be1  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f6be4  8b9c242c040000         -mov ebx, dword ptr [esp + 0x42c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1068) /* 0x42c */);
    // 004f6beb  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004f6bf2  e8f938ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f6bf7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6bfa  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6bfd  e80ef9ffff             -call 0x4f6510
    cpu.esp -= 4;
    sub_4f6510(app, cpu);
    if (cpu.terminate) return;
    // 004f6c02  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f6c07  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6c0d  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f6c10  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f6c13  01d8                   +add eax, ebx
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
    // 004f6c15  894234                 -mov dword ptr [edx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004f6c18  e965feffff             -jmp 0x4f6a82
    goto L_0x004f6a82;
L_0x004f6c1d:
    // 004f6c1d  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f6c24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6c25  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f6c28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6c29  e8ecd10300             -call 0x533e1a
    cpu.esp -= 4;
    sub_533e1a(app, cpu);
    if (cpu.terminate) return;
    // 004f6c2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6c30  0f8480feffff           -je 0x4f6ab6
    if (cpu.flags.zf)
    {
        goto L_0x004f6ab6;
    }
    // 004f6c36  c7452401000000         -mov dword ptr [ebp + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004f6c3d  e96afeffff             -jmp 0x4f6aac
    goto L_0x004f6aac;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f6c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f6c50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f6c51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f6c52  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6c55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6c57  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f6c59  8d430e                 -lea eax, [ebx + 0xe]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004f6c5c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6c5e  0f84af010000           -je 0x4f6e13
    if (cpu.flags.zf)
    {
        goto L_0x004f6e13;
    }
    // 004f6c64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f6c65  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f6c68  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f6c6a  0f84cc000000           -je 0x4f6d3c
    if (cpu.flags.zf)
    {
        goto L_0x004f6d3c;
    }
    // 004f6c70  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004f6c74:
    // 004f6c74  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6c78  0f85fa000000           -jne 0x4f6d78
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d78;
    }
    // 004f6c7e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f6c83:
    // 004f6c83  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6c87  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f6c89  668b15e8379f00         -mov dx, word ptr [0x9f37e8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10434536) /* 0x9f37e8 */);
    // 004f6c90  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f6c93  0f84e6000000           -je 0x4f6d7f
    if (cpu.flags.zf)
    {
        goto L_0x004f6d7f;
    }
    // 004f6c99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6c9b  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004f6c9e  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004f6ca1:
    // 004f6ca1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6ca5  66c742060000           -mov word ptr [edx + 6], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004f6cab  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f6cb2  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004f6cb6  8b454c                 -mov eax, dword ptr [ebp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 004f6cb9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f6cbc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f6cc0  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f6cc7  668b5d34               -mov bx, word ptr [ebp + 0x34]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6ccb  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004f6cce  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004f6cd1  0f85b2000000           -jne 0x4f6d89
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d89;
    }
    // 004f6cd7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f6cdc:
    // 004f6cdc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f6cde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ce0  0f84b3000000           -je 0x4f6d99
    if (cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6ce6  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 004f6ceb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f6ced:
    // 004f6ced  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6cf1  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6cf5  0f859e000000           -jne 0x4f6d99
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6cfb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6cfd  e82e8cfeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6d02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d04  0f8486000000           -je 0x4f6d90
    if (cpu.flags.zf)
    {
        goto L_0x004f6d90;
    }
    // 004f6d0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6d0c  e81f09ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6d11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d13  0f8c80000000           -jl 0x4f6d99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6d99;
    }
L_0x004f6d19:
    // 004f6d19  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6d1b  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6d1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6d20  0f8573000000           -jne 0x4f6d99
    if (!cpu.flags.zf)
    {
        goto L_0x004f6d99;
    }
    // 004f6d26  8b0dd8435600           -mov ecx, dword ptr [0x5643d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6d2c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f6d2e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f6d30  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f6d33  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f6d35  e8a68bfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6d3a  ebb1                   -jmp 0x4f6ced
    goto L_0x004f6ced;
L_0x004f6d3c:
    // 004f6d3c  b9d0d25400             -mov ecx, 0x54d2d0
    cpu.ecx = 5558992 /*0x54d2d0*/;
    // 004f6d41  bbdcd25400             -mov ebx, 0x54d2dc
    cpu.ebx = 5559004 /*0x54d2dc*/;
    // 004f6d46  bfac010000             -mov edi, 0x1ac
    cpu.edi = 428 /*0x1ac*/;
    // 004f6d4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f6d4d  b8f0d25400             -mov eax, 0x54d2f0
    cpu.eax = 5559024 /*0x54d2f0*/;
    // 004f6d52  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f6d58  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f6d5e  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f6d64  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f6d6a  e8b1a8feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f6d6f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f6d73  e9fcfeffff             -jmp 0x4f6c74
    goto L_0x004f6c74;
L_0x004f6d78:
    // 004f6d78  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6d7a  e904ffffff             -jmp 0x4f6c83
    goto L_0x004f6c83;
L_0x004f6d7f:
    // 004f6d7f  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
    // 004f6d84  e918ffffff             -jmp 0x4f6ca1
    goto L_0x004f6ca1;
L_0x004f6d89:
    // 004f6d89  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f6d8b  e94cffffff             -jmp 0x4f6cdc
    goto L_0x004f6cdc;
L_0x004f6d90:
    // 004f6d90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6d92  e8498bfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6d97  eb80                   -jmp 0x4f6d19
    goto L_0x004f6d19;
L_0x004f6d99:
    // 004f6d99  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6d9d  83781cff               +cmp dword ptr [eax + 0x1c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6da1  0f8484000000           -je 0x4f6e2b
    if (cpu.flags.zf)
    {
        goto L_0x004f6e2b;
    }
    // 004f6da7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6da9  746e                   -je 0x4f6e19
    if (cpu.flags.zf)
    {
        goto L_0x004f6e19;
    }
L_0x004f6dab:
    // 004f6dab  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6db0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6db1  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6db7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6dbb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f6dbe  894548                 -mov dword ptr [ebp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004f6dc1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6dc5  8d7d34                 -lea edi, [ebp + 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6dc8  8d7620                 -lea esi, [esi + 0x20]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f6dcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dcf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f6dd0  c7452401000000         -mov dword ptr [ebp + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004f6dd7  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f6ddd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6de1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f6de2  c7401cffffffff         -mov dword ptr [eax + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 004f6de9  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f6def:
    // 004f6def  8b5524                 -mov edx, dword ptr [ebp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f6df2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f6df4  0f850a020000           -jne 0x4f7004
    if (!cpu.flags.zf)
    {
        goto L_0x004f7004;
    }
    // 004f6dfa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f6dfe  833800                 +cmp dword ptr [eax], 0
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
    // 004f6e01  0f84fd010000           -je 0x4f7004
    if (cpu.flags.zf)
    {
        goto L_0x004f7004;
    }
    // 004f6e07  895510                 -mov dword ptr [ebp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004f6e0a  e881aafeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f6e0f:
    // 004f6e0f  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f6e12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f6e13:
    // 004f6e13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f6e16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f6e18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f6e19:
    // 004f6e19  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f6e1c  8d5534                 -lea edx, [ebp + 0x34]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6e1f  8b454c                 -mov eax, dword ptr [ebp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 004f6e22  e819e2ffff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 004f6e27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e29  7580                   -jne 0x4f6dab
    if (!cpu.flags.zf)
    {
        goto L_0x004f6dab;
    }
L_0x004f6e2b:
    // 004f6e2b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6e2d  75c0                   -jne 0x4f6def
    if (!cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e2f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e33  896838                 -mov dword ptr [eax + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 004f6e36  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f6e38  74b5                   -je 0x4f6def
    if (cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e3a  8d4534                 -lea eax, [ebp + 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f6e3d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004f6e41:
    // 004f6e41  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f6e43  75aa                   -jne 0x4f6def
    if (!cpu.flags.zf)
    {
        goto L_0x004f6def;
    }
    // 004f6e45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6e47  e8e48afeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6e4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e4e  7534                   -jne 0x4f6e84
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e84;
    }
    // 004f6e50  e88b8afeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004f6e55:
    // 004f6e55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6e57  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6e5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e5c  7433                   -je 0x4f6e91
    if (cpu.flags.zf)
    {
        goto L_0x004f6e91;
    }
L_0x004f6e5e:
    // 004f6e5e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e62  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6e67  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6e6e  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6e75:
    // 004f6e75  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6e79  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6e7d  75c2                   -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6e7f  e96bffffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f6e84:
    // 004f6e84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6e86  e8a507ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6e8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6e8d  7ccf                   -jl 0x4f6e5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6e5e;
    }
    // 004f6e8f  ebc4                   -jmp 0x4f6e55
    goto L_0x004f6e55;
L_0x004f6e91:
    // 004f6e91  e8faf5ffff             -call 0x4f6490
    cpu.esp -= 4;
    sub_4f6490(app, cpu);
    if (cpu.terminate) return;
    // 004f6e96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f6e98  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f6e9c  2eff1564465300         -call dword ptr cs:[0x534664]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457508) /* 0x534664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6ea3  8db8e8030000           -lea edi, [eax + 0x3e8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1000) /* 0x3e8 */);
    // 004f6ea9  83fbff                 +cmp ebx, -1
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
    // 004f6eac  0f843a010000           -je 0x4f6fec
    if (cpu.flags.zf)
    {
        goto L_0x004f6fec;
    }
    // 004f6eb2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f6eb4  e857f6ffff             -call 0x4f6510
    cpu.esp -= 4;
    sub_4f6510(app, cpu);
    if (cpu.terminate) return;
    // 004f6eb9  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004f6ebb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6ebf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f6ec1  e848cf0300             -call 0x533e0e
    cpu.esp -= 4;
    sub_533e0e(app, cpu);
    if (cpu.terminate) return;
    // 004f6ec6  e86dcf0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f6ecb  3d33270000             +cmp eax, 0x2733
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ed0  0f859f000000           -jne 0x4f6f75
    if (!cpu.flags.zf)
    {
        goto L_0x004f6f75;
    }
    // 004f6ed6  895d48                 -mov dword ptr [ebp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 004f6ed9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6edd  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ee1  744b                   -je 0x4f6f2e
    if (cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
L_0x004f6ee3:
    // 004f6ee3  2eff1564465300         -call dword ptr cs:[0x534664]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457508) /* 0x534664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6eea  39c7                   +cmp edi, eax
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
    // 004f6eec  7640                   -jbe 0x4f6f2e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6eee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6ef0  e83b8afeff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f6ef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6ef7  745c                   -je 0x4f6f55
    if (cpu.flags.zf)
    {
        goto L_0x004f6f55;
    }
    // 004f6ef9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f6efb  e83007ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f6f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f02  7c09                   -jl 0x4f6f0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f6f0d;
    }
L_0x004f6f04:
    // 004f6f04  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f6f06  ff5514                 -call dword ptr [ebp + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f6f09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f0b  744f                   -je 0x4f6f5c
    if (cpu.flags.zf)
    {
        goto L_0x004f6f5c;
    }
L_0x004f6f0d:
    // 004f6f0d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f11  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6f16  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6f1d  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
L_0x004f6f24:
    // 004f6f24  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f28  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f2c  75b5                   -jne 0x4f6ee3
    if (!cpu.flags.zf)
    {
        goto L_0x004f6ee3;
    }
L_0x004f6f2e:
    // 004f6f2e  837d2400               +cmp dword ptr [ebp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f32  0f853dffffff           -jne 0x4f6e75
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e75;
    }
    // 004f6f38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f6f3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f6f3d  e862cf0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f6f42  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f46  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f4a  0f85f1feffff           -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6f50  e99afeffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f6f55:
    // 004f6f55  e88689feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6f5a  eba8                   -jmp 0x4f6f04
    goto L_0x004f6f04;
L_0x004f6f5c:
    // 004f6f5c  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004f6f61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f6f63  8b1dd8435600           -mov ebx, dword ptr [0x5643d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f6f69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f6f6c  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f6f6e  e86d89feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f6f73  ebaf                   -jmp 0x4f6f24
    goto L_0x004f6f24;
L_0x004f6f75:
    // 004f6f75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f6f77  74b5                   -je 0x4f6f2e
    if (cpu.flags.zf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6f79  3d42270000             +cmp eax, 0x2742
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10050 /*0x2742*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f7e  7329                   -jae 0x4f6fa9
    if (!cpu.flags.cf)
    {
        goto L_0x004f6fa9;
    }
    // 004f6f80  3d3f270000             +cmp eax, 0x273f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10047 /*0x273f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f85  7309                   -jae 0x4f6f90
    if (!cpu.flags.cf)
    {
        goto L_0x004f6f90;
    }
    // 004f6f87  3d1e270000             +cmp eax, 0x271e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10014 /*0x271e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6f8c  72a0                   -jb 0x4f6f2e
    if (cpu.flags.cf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6f8e  7750                   -ja 0x4f6fe0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f6fe0;
    }
L_0x004f6f90:
    // 004f6f90  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6f94  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6f99  c7403800000000         -mov dword ptr [eax + 0x38], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004f6fa0  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f6fa7  eb85                   -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fa9:
    // 004f6fa9  76e5                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fab  3d4d270000             +cmp eax, 0x274d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10061 /*0x274d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fb0  7313                   -jae 0x4f6fc5
    if (!cpu.flags.cf)
    {
        goto L_0x004f6fc5;
    }
    // 004f6fb2  3d43270000             +cmp eax, 0x2743
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10051 /*0x2743*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fb7  76d7                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fb9  3d48270000             +cmp eax, 0x2748
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10056 /*0x2748*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fbe  74d0                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fc0  e969ffffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fc5:
    // 004f6fc5  76c9                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fc7  3d50270000             +cmp eax, 0x2750
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10064 /*0x2750*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fcc  0f825cffffff           -jb 0x4f6f2e
    if (cpu.flags.cf)
    {
        goto L_0x004f6f2e;
    }
    // 004f6fd2  76bc                   -jbe 0x4f6f90
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fd4  3d51270000             +cmp eax, 0x2751
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10065 /*0x2751*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fd9  74b5                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fdb  e94effffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fe0:
    // 004f6fe0  3d26270000             +cmp eax, 0x2726
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10022 /*0x2726*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6fe5  74a9                   -je 0x4f6f90
    if (cpu.flags.zf)
    {
        goto L_0x004f6f90;
    }
    // 004f6fe7  e942ffffff             -jmp 0x4f6f2e
    goto L_0x004f6f2e;
L_0x004f6fec:
    // 004f6fec  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004f6ff1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f6ff5  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f6ff9  0f8542feffff           -jne 0x4f6e41
    if (!cpu.flags.zf)
    {
        goto L_0x004f6e41;
    }
    // 004f6fff  e9ebfdffff             -jmp 0x4f6def
    goto L_0x004f6def;
L_0x004f7004:
    // 004f7004  837d2400               +cmp dword ptr [ebp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7008  0f8401feffff           -je 0x4f6e0f
    if (cpu.flags.zf)
    {
        goto L_0x004f6e0f;
    }
    // 004f700e  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f7013  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f7015  e8366e0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f701a  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f701d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f701e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f7021  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f7030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7034  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f7037  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f703b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f703d  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f7040  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f7042  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7044  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7048  39c3                   +cmp ebx, eax
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
    // 004f704a  7711                   -ja 0x4f705d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f705d;
    }
L_0x004f704c:
    // 004f704c  66837e0600             +cmp word ptr [esi + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f7051  7641                   -jbe 0x4f7094
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7094;
    }
    // 004f7053  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7055  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f7058  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7059  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f705c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f705d:
    // 004f705d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f705f  bad0d25400             -mov edx, 0x54d2d0
    cpu.edx = 5558992 /*0x54d2d0*/;
    // 004f7064  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7068  b9f8d25400             -mov ecx, 0x54d2f8
    cpu.ecx = 5559032 /*0x54d2f8*/;
    // 004f706d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f706e  bb2e020000             -mov ebx, 0x22e
    cpu.ebx = 558 /*0x22e*/;
    // 004f7073  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f7079  680cd35400             -push 0x54d30c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559052 /*0x54d30c*/;
    cpu.esp -= 4;
    // 004f707e  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f7084  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f708a  e8819ff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f708f  83c408                 +add esp, 8
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
    // 004f7092  ebb8                   -jmp 0x4f704c
    goto L_0x004f704c;
L_0x004f7094:
    // 004f7094  a180445600             -mov eax, dword ptr [0x564480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f7099  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f709a  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f70a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f70a2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004f70a4  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f70a6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004f70a9  8d560e                 -lea edx, [esi + 0xe]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004f70ac  6689460c               -mov word ptr [esi + 0xc], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004f70b0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f70b4  e83734ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f70b9  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f70bc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f70bf  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f70c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f70c4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f70c6  6689f8                 -mov ax, di
    cpu.ax = cpu.di;
    // 004f70c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f70ca  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f70cd  66897e06               -mov word ptr [esi + 6], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 004f70d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f70d2  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f70d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f70d6  e84bcd0300             -call 0x533e26
    cpu.esp -= 4;
    sub_533e26(app, cpu);
    if (cpu.terminate) return;
    // 004f70db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f70dd  83f8ff                 +cmp eax, -1
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
    // 004f70e0  755d                   -jne 0x4f713f
    if (!cpu.flags.zf)
    {
        goto L_0x004f713f;
    }
    // 004f70e2  e851cd0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f70e7  8b3de06d5600           -mov edi, dword ptr [0x566de0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f70ed  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f70f0  83ff04                 +cmp edi, 4
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
    // 004f70f3  7c1a                   -jl 0x4f710f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f710f;
    }
    // 004f70f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f70f7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f70fc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f7100  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7102  b844d35400             -mov eax, 0x54d344
    cpu.eax = 5559108 /*0x54d344*/;
    // 004f7107  8d5d48                 -lea ebx, [ebp + 0x48]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004f710a  e871b00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f710f:
    // 004f710f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7112  81fd47270000           +cmp ebp, 0x2747
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10055 /*0x2747*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7118  7408                   -je 0x4f7122
    if (cpu.flags.zf)
    {
        goto L_0x004f7122;
    }
    // 004f711a  81fd33270000           +cmp ebp, 0x2733
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10035 /*0x2733*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7120  7556                   -jne 0x4f7178
    if (!cpu.flags.zf)
    {
        goto L_0x004f7178;
    }
L_0x004f7122:
    // 004f7122  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f7128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7129  66c746060000           -mov word ptr [esi + 6], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004f712f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7135  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7137  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f713a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f713e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f713f:
    // 004f713f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7141  7e35                   -jle 0x4f7178
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f7178;
    }
    // 004f7143  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004f7147  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f714a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f714c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f714e  66895e06               -mov word ptr [esi + 6], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.bx;
    // 004f7152  8b1de06d5600           -mov ebx, dword ptr [0x566de0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f7158  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f715b  83fb04                 +cmp ebx, 4
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
    // 004f715e  7c18                   -jl 0x4f7178
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f7178;
    }
    // 004f7160  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7162  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f7167  8d5d34                 -lea ebx, [ebp + 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004f716a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f716c  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f716e  b850d35400             -mov eax, 0x54d350
    cpu.eax = 5559120 /*0x54d350*/;
    // 004f7173  e808b00100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f7178:
    // 004f7178  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004f717e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f717f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7185  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f718a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f718d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f718e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f718f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7190  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7191  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f71a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f71a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f71a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f71a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f71a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f71a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f71a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f71a9  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f71ae  e89d6f0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f71b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f71b5  743a                   -je 0x4f71f1
    if (cpu.flags.zf)
    {
        goto L_0x004f71f1;
    }
    // 004f71b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f71b8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f71ba  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004f71bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f71be  e845cc0300             -call 0x533e08
    cpu.esp -= 4;
    sub_533e08(app, cpu);
    if (cpu.terminate) return;
    // 004f71c3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f71c8  e81387feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f71cd  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004f71d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f71d1  e8cecc0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f71d6  c74348ffffffff         -mov dword ptr [ebx + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f71dd  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f71e4  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f71e9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f71eb  e8606c0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f71f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f71f1:
    // 004f71f1  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f71f6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f71f8  e8536f0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f71fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f71ff  7419                   -je 0x4f721a
    if (cpu.flags.zf)
    {
        goto L_0x004f721a;
    }
    // 004f7201  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f7204  833800                 +cmp dword ptr [eax], 0
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
    // 004f7207  740c                   -je 0x4f7215
    if (cpu.flags.zf)
    {
        goto L_0x004f7215;
    }
    // 004f7209  e882a6feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f720e  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004f7215:
    // 004f7215  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f721a:
    // 004f721a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f721d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7224  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7226  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7228  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f722a  3b10                   +cmp edx, dword ptr [eax]
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
    // 004f722c  7534                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f722e  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f7232  663b5604               +cmp dx, word ptr [esi + 4]
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
    // 004f7236  752a                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f7238  668b5f06               -mov bx, word ptr [edi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004f723c  663b5e06               +cmp bx, word ptr [esi + 6]
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
    // 004f7240  7520                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
    // 004f7242  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f7244  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f7247  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7249  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f724c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f724e  38fb                   +cmp bl, bh
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
    // 004f7250  7510                   -jne 0x4f7262
    if (!cpu.flags.zf)
    {
        goto L_0x004f7262;
    }
L_0x004f7252:
    // 004f7252  40                     -inc eax
    (cpu.eax)++;
    // 004f7253  42                     -inc edx
    (cpu.edx)++;
    // 004f7254  41                     -inc ecx
    (cpu.ecx)++;
    // 004f7255  83fa08                 +cmp edx, 8
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
    // 004f7258  7d0f                   -jge 0x4f7269
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7269;
    }
    // 004f725a  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f725d  3a5908                 +cmp bl, byte ptr [ecx + 8]
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
    // 004f7260  74f0                   -je 0x4f7252
    if (cpu.flags.zf)
    {
        goto L_0x004f7252;
    }
L_0x004f7262:
    // 004f7262  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7264  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7265  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7266  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7267  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7268  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7269:
    // 004f7269  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f726e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f726f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7270  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7271  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7272  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7282  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7283  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7285  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7287  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f7289  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f728c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f728f  e88cffffff             -call 0x4f7220
    cpu.esp -= 4;
    sub_4f7220(app, cpu);
    if (cpu.terminate) return;
    // 004f7294  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7296  7506                   -jne 0x4f729e
    if (!cpu.flags.zf)
    {
        goto L_0x004f729e;
    }
L_0x004f7298:
    // 004f7298  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7299  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f729a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f729b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f729e:
    // 004f729e  e88ddfffff             -call 0x4f5230
    cpu.esp -= 4;
    sub_4f5230(app, cpu);
    if (cpu.terminate) return;
    // 004f72a3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72a6  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72a9  a3446f5600             -mov dword ptr [0x566f44], eax
    app->getMemory<x86::reg32>(x86::reg32(5664580) /* 0x566f44 */) = cpu.eax;
    // 004f72ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f72b0  74e6                   -je 0x4f7298
    if (cpu.flags.zf)
    {
        goto L_0x004f7298;
    }
    // 004f72b2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f72b4  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f72b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f72bb  ff551c                 -call dword ptr [ebp + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72be  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f72c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f72c3  74d3                   -je 0x4f7298
    if (cpu.flags.zf)
    {
        goto L_0x004f7298;
    }
    // 004f72c5  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f72c8  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004f72cb  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004f72d0  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f72d3  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004f72d9  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 004f72e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f72e5  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f72ec  e8ff31ffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f72f1  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 004f72f6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f72fa  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004f72fd  e82e9bfeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f7302  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004f7307  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f730b  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004f730e  e81d9bfeff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f7313  a1446f5600             -mov eax, dword ptr [0x566f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664580) /* 0x566f44 */);
    // 004f7318  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7319  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f731a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f731b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7322  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f7324  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f7327  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f732c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f732e  7431                   -je 0x4f7361
    if (cpu.flags.zf)
    {
        goto L_0x004f7361;
    }
    // 004f7330  83baa000000000         +cmp dword ptr [edx + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7337  7407                   -je 0x4f7340
    if (cpu.flags.zf)
    {
        goto L_0x004f7340;
    }
    // 004f7339  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f733b  e850dcffff             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
L_0x004f7340:
    // 004f7340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7341  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7344  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7346  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7349  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004f7353  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7356  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f735d  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7360  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f7361:
    // 004f7361  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7363  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f7370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7370  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7372  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7380  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7382  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7384  7406                   -je 0x4f738c
    if (cpu.flags.zf)
    {
        goto L_0x004f738c;
    }
    // 004f7386  66c742280100           -mov word ptr [edx + 0x28], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
L_0x004f738c:
    // 004f738c  ba8c6e5600             -mov edx, 0x566e8c
    cpu.edx = 5664396 /*0x566e8c*/;
    // 004f7391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7392  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f7394  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7396  e895ddffff             -call 0x4f5130
    cpu.esp -= 4;
    sub_4f5130(app, cpu);
    if (cpu.terminate) return;
    // 004f739b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f73a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f73a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f73a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f73a2  833d886e560000         +cmp dword ptr [0x566e88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f73a9  7452                   -je 0x4f73fd
    if (cpu.flags.zf)
    {
        goto L_0x004f73fd;
    }
L_0x004f73ab:
    // 004f73ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f73ad  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f73af  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f73b1  e8f4ca0300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f73b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f73b8  83f8ff                 +cmp eax, -1
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
    // 004f73bb  7410                   -je 0x4f73cd
    if (cpu.flags.zf)
    {
        goto L_0x004f73cd;
    }
    // 004f73bd  b820b1a000             -mov eax, 0xa0b120
    cpu.eax = 10531104 /*0xa0b120*/;
    // 004f73c2  e829dd0100             -call 0x5150f0
    cpu.esp -= 4;
    sub_5150f0(app, cpu);
    if (cpu.terminate) return;
    // 004f73c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f73c8  e8d7ca0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
L_0x004f73cd:
    // 004f73cd  8b0d886e5600           -mov ecx, dword ptr [0x566e88]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
    // 004f73d3  41                     -inc ecx
    (cpu.ecx)++;
    // 004f73d4  668b15e8379f00         -mov dx, word ptr [0x9f37e8]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10434536) /* 0x9f37e8 */);
    // 004f73db  890d886e5600           -mov dword ptr [0x566e88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */) = cpu.ecx;
    // 004f73e1  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f73e4  740f                   -je 0x4f73f5
    if (cpu.flags.zf)
    {
        goto L_0x004f73f5;
    }
    // 004f73e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f73e8  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004f73eb  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f73ee  3d00040000             +cmp eax, 0x400
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
    // 004f73f3  7e05                   -jle 0x4f73fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f73fa;
    }
L_0x004f73f5:
    // 004f73f5  b800040000             -mov eax, 0x400
    cpu.eax = 1024 /*0x400*/;
L_0x004f73fa:
    // 004f73fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f73fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f73fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f73fd:
    // 004f73fd  6860369f00             -push 0x9f3660
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434144 /*0x9f3660*/;
    cpu.esp -= 4;
    // 004f7402  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f7407  e8a4ca0300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f740c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f740e  749b                   -je 0x4f73ab
    if (cpu.flags.zf)
    {
        goto L_0x004f73ab;
    }
    // 004f7410  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7412  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f7420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7421  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7422  8b15886e5600           -mov edx, dword ptr [0x566e88]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */);
    // 004f7428  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f742a  741e                   -je 0x4f744a
    if (cpu.flags.zf)
    {
        goto L_0x004f744a;
    }
    // 004f742c  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004f742f  890d886e5600           -mov dword ptr [0x566e88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664392) /* 0x566e88 */) = cpu.ecx;
    // 004f7435  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7437  7408                   -je 0x4f7441
    if (cpu.flags.zf)
    {
        goto L_0x004f7441;
    }
L_0x004f7439:
    // 004f7439  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f743e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f743f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7440  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7441:
    // 004f7441  e858ca0300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f7446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7448  74ef                   -je 0x4f7439
    if (cpu.flags.zf)
    {
        goto L_0x004f7439;
    }
L_0x004f744a:
    // 004f744a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f744c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f744d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f744e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f7450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7451  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7452  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7453  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7454  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7457  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f745b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f745d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f745f  bad0d25400             -mov edx, 0x54d2d0
    cpu.edx = 5558992 /*0x54d2d0*/;
    // 004f7464  bb58d35400             -mov ebx, 0x54d358
    cpu.ebx = 5559128 /*0x54d358*/;
    // 004f7469  be1a030000             -mov esi, 0x31a
    cpu.esi = 794 /*0x31a*/;
    // 004f746e  b868d35400             -mov eax, 0x54d368
    cpu.eax = 5559144 /*0x54d368*/;
    // 004f7473  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f7479  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f747f  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 004f7484  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f748a  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f7490  e88ba1feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f7495  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 004f749a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f749c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f749e  e86992feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f74a3  c7431cffffffff         -mov dword ptr [ebx + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 004f74aa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f74ae  e8ddefffff             -call 0x4f6490
    cpu.esp -= 4;
    sub_4f6490(app, cpu);
    if (cpu.terminate) return;
    // 004f74b3  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f74b6  897b3c                 -mov dword ptr [ebx + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 004f74b9  894b40                 -mov dword ptr [ebx + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 004f74bc  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f74c0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f74c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f74c4  0f8493000000           -je 0x4f755d
    if (cpu.flags.zf)
    {
        goto L_0x004f755d;
    }
    // 004f74ca  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
L_0x004f74cc:
    // 004f74cc  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f74d3  7c1a                   -jl 0x4f74ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f74ef;
    }
    // 004f74d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f74d7  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f74dc  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f74e0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f74e2  b870d35400             -mov eax, 0x54d370
    cpu.eax = 5559152 /*0x54d370*/;
    // 004f74e7  8d5e18                 -lea ebx, [esi + 0x18]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f74ea  e891ac0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f74ef:
    // 004f74ef  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f74f2  83fbff                 +cmp ebx, -1
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
    // 004f74f5  0f849e000000           -je 0x4f7599
    if (cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f74fb  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004f74fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f74fe  e8ffc80300             -call 0x533e02
    cpu.esp -= 4;
    sub_533e02(app, cpu);
    if (cpu.terminate) return;
    // 004f7503  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7505  0f858e000000           -jne 0x4f7599
    if (!cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f750b  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f7510  8935f0379f00           -mov dword ptr [0x9f37f0], esi
    app->getMemory<x86::reg32>(x86::reg32(10434544) /* 0x9f37f0 */) = cpu.esi;
    // 004f7516  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f7519  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f751e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f751f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f7521  b8c0684f00             -mov eax, 0x4f68c0
    cpu.eax = 5204160 /*0x4f68c0*/;
    // 004f7526  e87582feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f752b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f752d  746a                   -je 0x4f7599
    if (cpu.flags.zf)
    {
        goto L_0x004f7599;
    }
    // 004f752f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004f7534  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f7536:
    // 004f7536  8a6647                 -mov ah, byte ptr [esi + 0x47]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
    // 004f7539  38e2                   +cmp dl, ah
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f753b  7558                   -jne 0x4f7595
    if (!cpu.flags.zf)
    {
        goto L_0x004f7595;
    }
    // 004f753d  3a6646                 +cmp ah, byte ptr [esi + 0x46]
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(70) /* 0x46 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7540  7553                   -jne 0x4f7595
    if (!cpu.flags.zf)
    {
        goto L_0x004f7595;
    }
    // 004f7542  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7544  e8e783feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f7549  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f754b  743f                   -je 0x4f758c
    if (cpu.flags.zf)
    {
        goto L_0x004f758c;
    }
    // 004f754d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f754f  e8dc00ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x004f7554:
    // 004f7554  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f7556  e88583feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f755b  ebd9                   -jmp 0x4f7536
    goto L_0x004f7536;
L_0x004f755d:
    // 004f755d  c744241410000000       -mov dword ptr [esp + 0x14], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 16 /*0x10*/;
    // 004f7565  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7569  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f756a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f756e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f756f  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004f7572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7573  e8c6c80300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f7578  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f757a  0f854cffffff           -jne 0x4f74cc
    if (!cpu.flags.zf)
    {
        goto L_0x004f74cc;
    }
    // 004f7580  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004f7585  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f7587  e940ffffff             -jmp 0x4f74cc
    goto L_0x004f74cc;
L_0x004f758c:
    // 004f758c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f758e  e84d83feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f7593  ebbf                   -jmp 0x4f7554
    goto L_0x004f7554;
L_0x004f7595:
    // 004f7595  0fb66e47               -movzx ebp, byte ptr [esi + 0x47]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */));
L_0x004f7599:
    // 004f7599  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f759b  7526                   -jne 0x4f75c3
    if (!cpu.flags.zf)
    {
        goto L_0x004f75c3;
    }
    // 004f759d  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f75a4  7c14                   -jl 0x4f75ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f75ba;
    }
    // 004f75a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f75a8  b880d35400             -mov eax, 0x54d380
    cpu.eax = 5559168 /*0x54d380*/;
    // 004f75ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f75af  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f75b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f75b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f75b5  e8c6ab0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f75ba:
    // 004f75ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f75bc  e80f000000             -call 0x4f75d0
    cpu.esp -= 4;
    sub_4f75d0(app, cpu);
    if (cpu.terminate) return;
    // 004f75c1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f75c3:
    // 004f75c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f75c5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f75c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f75cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f75d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f75d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f75d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f75d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f75d3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f75d5  833de06d560004         +cmp dword ptr [0x566de0], 4
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
    // 004f75dc  7d4b                   -jge 0x4f7629
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7629;
    }
L_0x004f75de:
    // 004f75de  807e4700               +cmp byte ptr [esi + 0x47], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f75e2  742d                   -je 0x4f7611
    if (cpu.flags.zf)
    {
        goto L_0x004f7611;
    }
    // 004f75e4  8a5647                 -mov dl, byte ptr [esi + 0x47]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
    // 004f75e7  c6464601               -mov byte ptr [esi + 0x46], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(70) /* 0x46 */) = 1 /*0x1*/;
    // 004f75eb  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004f75ed  7422                   -je 0x4f7611
    if (cpu.flags.zf)
    {
        goto L_0x004f7611;
    }
L_0x004f75ef:
    // 004f75ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f75f1  e83a83feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f75f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f75f8  7447                   -je 0x4f7641
    if (cpu.flags.zf)
    {
        goto L_0x004f7641;
    }
    // 004f75fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f75fc  e82f00ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x004f7601:
    // 004f7601  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7606  e8d582feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f760b  807e4700               +cmp byte ptr [esi + 0x47], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(71) /* 0x47 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f760f  75de                   -jne 0x4f75ef
    if (!cpu.flags.zf)
    {
        goto L_0x004f75ef;
    }
L_0x004f7611:
    // 004f7611  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f7614  83f9ff                 +cmp ecx, -1
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
    // 004f7617  752f                   -jne 0x4f7648
    if (!cpu.flags.zf)
    {
        goto L_0x004f7648;
    }
    // 004f7619  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f761b  e870a2feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f7620  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7625  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7626  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7627  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7628  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7629:
    // 004f7629  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f762a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f762c  b890d35400             -mov eax, 0x54d390
    cpu.eax = 5559184 /*0x54d390*/;
    // 004f7631  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7633  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7635  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7637  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f7639  e842ab0100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f763e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f763f  eb9d                   -jmp 0x4f75de
    goto L_0x004f75de;
L_0x004f7641:
    // 004f7641  e89a82feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f7646  ebb9                   -jmp 0x4f7601
    goto L_0x004f7601;
L_0x004f7648:
    // 004f7648  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7649  e856c80300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f764e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7650  e83ba2feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f7655  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f765a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f765d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f7660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7660  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f7662  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7673  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f7676  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f7679  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f767b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004f767f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f7681  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004f7686  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f768a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f768c  7509                   -jne 0x4f7697
    if (!cpu.flags.zf)
    {
        goto L_0x004f7697;
    }
L_0x004f768e:
    // 004f768e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7690  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f7693  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7694  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7695  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7696  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7697:
    // 004f7697  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f7699  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f769b  49                     -dec ecx
    (cpu.ecx)--;
    // 004f769c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f769e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f76a0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f76a2  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f76a5  74e7                   -je 0x4f768e
    if (cpu.flags.zf)
    {
        goto L_0x004f768e;
    }
    // 004f76a7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f76a9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f76ab  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f76ae  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f76b0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f76b2  49                     -dec ecx
    (cpu.ecx)--;
    // 004f76b3  807c31ff2e             +cmp byte ptr [ecx + esi - 1], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.esi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f76b8  74d4                   -je 0x4f768e
    if (cpu.flags.zf)
    {
        goto L_0x004f768e;
    }
    // 004f76ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f76bb  e83cc70300             -call 0x533dfc
    cpu.esp -= 4;
    sub_533dfc(app, cpu);
    if (cpu.terminate) return;
    // 004f76c0  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004f76c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f76c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f76c9  e83e90feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f76ce  66c7030200             -mov word ptr [ebx], 2
    app->getMemory<x86::reg16>(cpu.ebx) = 2 /*0x2*/;
    // 004f76d3  83f9ff                 +cmp ecx, -1
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
    // 004f76d6  755c                   -jne 0x4f7734
    if (!cpu.flags.zf)
    {
        goto L_0x004f7734;
    }
    // 004f76d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f76d9  e818c70300             -call 0x533df6
    cpu.esp -= 4;
    sub_533df6(app, cpu);
    if (cpu.terminate) return;
    // 004f76de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f76e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f76e2  744c                   -je 0x4f7730
    if (cpu.flags.zf)
    {
        goto L_0x004f7730;
    }
    // 004f76e4  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f76e7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004f76ea  83fb04                 +cmp ebx, 4
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
    // 004f76ed  733a                   -jae 0x4f7729
    if (!cpu.flags.cf)
    {
        goto L_0x004f7729;
    }
L_0x004f76ef:
    // 004f76ef  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f76f3  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f76f6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f76f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f76fb  e8f02dffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x004f7700:
    // 004f7700  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f7702  741c                   -je 0x4f7720
    if (cpu.flags.zf)
    {
        goto L_0x004f7720;
    }
    // 004f7704  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004f7709  742e                   -je 0x4f7739
    if (cpu.flags.zf)
    {
        goto L_0x004f7739;
    }
    // 004f770b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f770d  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004f7712:
    // 004f7712  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7713  e832c70300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f7718  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f771c  66894202               -mov word ptr [edx + 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.ax;
L_0x004f7720:
    // 004f7720  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f7722  83c40c                 +add esp, 0xc
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
    // 004f7725  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7726  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7727  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7728  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7729:
    // 004f7729  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f772e  ebbf                   -jmp 0x4f76ef
    goto L_0x004f76ef;
L_0x004f7730:
    // 004f7730  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004f7732  ebec                   -jmp 0x4f7720
    goto L_0x004f7720;
L_0x004f7734:
    // 004f7734  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f7737  ebc7                   -jmp 0x4f7700
    goto L_0x004f7700;
L_0x004f7739:
    // 004f7739  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f773c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f773e  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004f7741  ebcf                   -jmp 0x4f7712
    goto L_0x004f7712;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f7750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7753  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7756  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f7759  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004f775b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f775e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f775f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f7761  e88ac60300             -call 0x533df0
    cpu.esp -= 4;
    sub_533df0(app, cpu);
    if (cpu.terminate) return;
    // 004f7766  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7768  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f7769:
    // 004f7769  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f776b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f776d  3c00                   +cmp al, 0
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
    // 004f776f  7410                   -je 0x4f7781
    if (cpu.flags.zf)
    {
        goto L_0x004f7781;
    }
    // 004f7771  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f7774  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f7777  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f777a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f777d  3c00                   +cmp al, 0
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
    // 004f777f  75e8                   -jne 0x4f7769
    if (!cpu.flags.zf)
    {
        goto L_0x004f7769;
    }
L_0x004f7781:
    // 004f7781  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7782  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f7784  750c                   -jne 0x4f7792
    if (!cpu.flags.zf)
    {
        goto L_0x004f7792;
    }
    // 004f7786  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f778b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f778e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f778f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7791  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7792:
    // 004f7792  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7795  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7797  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004f779b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f779c  e849c60300             -call 0x533dea
    cpu.esp -= 4;
    sub_533dea(app, cpu);
    if (cpu.terminate) return;
    // 004f77a1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f77a6  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004f77a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f77ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f77b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f77c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f77c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f77c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f77c3  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004f77c8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f77ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f77cc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f77ce  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f77d0  7405                   -je 0x4f77d7
    if (cpu.flags.zf)
    {
        goto L_0x004f77d7;
    }
    // 004f77d2  19c0                   +sbb eax, eax
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
    // 004f77d4  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f77d7:
    // 004f77d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f77d9  7509                   -jne 0x4f77e4
    if (!cpu.flags.zf)
    {
        goto L_0x004f77e4;
    }
    // 004f77db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f77e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f77e4:
    // 004f77e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f77e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f77e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f77f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f77f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f77f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f77f5  c7042414000000         -mov dword ptr [esp], 0x14
    app->getMemory<x86::reg32>(cpu.esp) = 20 /*0x14*/;
    // 004f77fc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004f77fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f77ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7800  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f7803  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7804  e835c60300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f7809  83f8ff                 +cmp eax, -1
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
    // 004f780c  740b                   -je 0x4f7819
    if (cpu.flags.zf)
    {
        goto L_0x004f7819;
    }
    // 004f780e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f7813  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7816  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7817  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7818  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7819:
    // 004f7819  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f781b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f781e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f781f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f7830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7833  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7834  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7836  833d8044560000         +cmp dword ptr [0x564480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f783d  0f8499000000           -je 0x4f78dc
    if (cpu.flags.zf)
    {
        goto L_0x004f78dc;
    }
L_0x004f7843:
    // 004f7843  833d486f560000         +cmp dword ptr [0x566f48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f784a  0f8579000000           -jne 0x4f78c9
    if (!cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f7850  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004f7852  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7859  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004f785b  746c                   -je 0x4f78c9
    if (cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f785d  6860369f00             -push 0x9f3660
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434144 /*0x9f3660*/;
    cpu.esp -= 4;
    // 004f7862  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f7867  e844c60300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f786c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f786e  7559                   -jne 0x4f78c9
    if (!cpu.flags.zf)
    {
        goto L_0x004f78c9;
    }
    // 004f7870  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7871  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7872  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7873  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7875  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f7877  e82ec60300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f787c  83f8ff                 +cmp eax, -1
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
    // 004f787f  7441                   -je 0x4f78c2
    if (cpu.flags.zf)
    {
        goto L_0x004f78c2;
    }
    // 004f7881  bee46e5600             -mov esi, 0x566ee4
    cpu.esi = 5664484 /*0x566ee4*/;
    // 004f7886  bfa06e5600             -mov edi, 0x566ea0
    cpu.edi = 5664416 /*0x566ea0*/;
    // 004f788b  8b15e46d5600           -mov edx, dword ptr [0x566de4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f7891  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7892  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004f7895  893495d0259f00         -mov dword ptr [edx*4 + 0x9f25d0], esi
    app->getMemory<x86::reg32>(x86::reg32(10429904) /* 0x9f25d0 */ + cpu.edx * 4) = cpu.esi;
    // 004f789c  893c95b0259f00         -mov dword ptr [edx*4 + 0x9f25b0], edi
    app->getMemory<x86::reg32>(x86::reg32(10429872) /* 0x9f25b0 */ + cpu.edx * 4) = cpu.edi;
    // 004f78a3  892de46d5600           -mov dword ptr [0x566de4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */) = cpu.ebp;
    // 004f78a9  e8f6c50300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f78ae  c705486f560001000000   -mov dword ptr [0x566f48], 1
    app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */) = 1 /*0x1*/;
    // 004f78b8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f78ba  7406                   -je 0x4f78c2
    if (cpu.flags.zf)
    {
        goto L_0x004f78c2;
    }
    // 004f78bc  891de46e5600           -mov dword ptr [0x566ee4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5664484) /* 0x566ee4 */) = cpu.ebx;
L_0x004f78c2:
    // 004f78c2  e8d7c50300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f78c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f78c9:
    // 004f78c9  833d486f560000         +cmp dword ptr [0x566f48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664584) /* 0x566f48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f78d0  7419                   -je 0x4f78eb
    if (cpu.flags.zf)
    {
        goto L_0x004f78eb;
    }
    // 004f78d2  b8e86e5600             -mov eax, 0x566ee8
    cpu.eax = 5664488 /*0x566ee8*/;
    // 004f78d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f78dc:
    // 004f78dc  e8ff39ffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f78e1  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 004f78e6  e958ffffff             -jmp 0x4f7843
    goto L_0x004f7843;
L_0x004f78eb:
    // 004f78eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f78ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f78f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7905  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f7906  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004f7908  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004f790a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f790b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f790e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f7910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7912  7405                   -je 0x4f7919
    if (cpu.flags.zf)
    {
        goto L_0x004f7919;
    }
    // 004f7914  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7917  7607                   -jbe 0x4f7920
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7920;
    }
L_0x004f7919:
    // 004f7919  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f791b  e9be000000             -jmp 0x4f79de
    goto L_0x004f79de;
L_0x004f7920:
    // 004f7920  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004f7923  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004f7926  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7929  7305                   -jae 0x4f7930
    if (!cpu.flags.cf)
    {
        goto L_0x004f7930;
    }
    // 004f792b  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x004f7930:
    // 004f7930  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7936  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f7938  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f793a  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004f793d:
    // 004f793d  3b2d546f5600           +cmp ebp, dword ptr [0x566f54]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7943  760c                   -jbe 0x4f7951
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7951;
    }
    // 004f7945  8b0d506f5600           -mov ecx, dword ptr [0x566f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f794b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f794d  7510                   -jne 0x4f795f
    if (!cpu.flags.zf)
    {
        goto L_0x004f795f;
    }
    // 004f794f  eb02                   -jmp 0x4f7953
    goto L_0x004f7953;
L_0x004f7951:
    // 004f7951  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f7953:
    // 004f7953  890d546f5600           -mov dword ptr [0x566f54], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.ecx;
    // 004f7959  8b0d4c6f5600           -mov ecx, dword ptr [0x566f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
L_0x004f795f:
    // 004f795f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7961  743c                   -je 0x4f799f
    if (cpu.flags.zf)
    {
        goto L_0x004f799f;
    }
    // 004f7963  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004f7966  890d506f5600           -mov dword ptr [0x566f50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.ecx;
    // 004f796c  39fe                   +cmp esi, edi
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
    // 004f796e  721c                   -jb 0x4f798c
    if (cpu.flags.cf)
    {
        goto L_0x004f798c;
    }
    // 004f7970  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 004f7975  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004f7977  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f797d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f797f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7981  e87ad90100             -call 0x515300
    cpu.esp -= 4;
    sub_515300(app, cpu);
    if (cpu.terminate) return;
    // 004f7986  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f7988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f798a  7542                   -jne 0x4f79ce
    if (!cpu.flags.zf)
    {
        goto L_0x004f79ce;
    }
L_0x004f798c:
    // 004f798c  3b35546f5600           +cmp esi, dword ptr [0x566f54]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7992  7606                   -jbe 0x4f799a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f799a;
    }
    // 004f7994  8935546f5600           -mov dword ptr [0x566f54], esi
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.esi;
L_0x004f799a:
    // 004f799a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f799d  ebc0                   -jmp 0x4f795f
    goto L_0x004f795f;
L_0x004f799f:
    // 004f799f  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f79a3  750b                   -jne 0x4f79b0
    if (!cpu.flags.zf)
    {
        goto L_0x004f79b0;
    }
    // 004f79a5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f79a7  e868dc0100             -call 0x515614
    cpu.esp -= 4;
    sub_515614(app, cpu);
    if (cpu.terminate) return;
    // 004f79ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79ae  7515                   -jne 0x4f79c5
    if (!cpu.flags.zf)
    {
        goto L_0x004f79c5;
    }
L_0x004f79b0:
    // 004f79b0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f79b2  e8c9dc0100             -call 0x515680
    cpu.esp -= 4;
    sub_515680(app, cpu);
    if (cpu.terminate) return;
    // 004f79b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79b9  7413                   -je 0x4f79ce
    if (cpu.flags.zf)
    {
        goto L_0x004f79ce;
    }
    // 004f79bb  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004f79bd  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 004f79c0  e978ffffff             -jmp 0x4f793d
    goto L_0x004f793d;
L_0x004f79c5:
    // 004f79c5  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 004f79c9  e96fffffff             -jmp 0x4f793d
    goto L_0x004f793d;
L_0x004f79ce:
    // 004f79ce  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004f79d0  882d40b1a000           -mov byte ptr [0xa0b140], ch
    app->getMemory<x86::reg8>(x86::reg32(10531136) /* 0xa0b140 */) = cpu.ch;
    // 004f79d6  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f79dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004f79de:
    // 004f79de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f79e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e2  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e4  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f79e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f79ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f79f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f79f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f79f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f79f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f79f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f79f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f79f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f79f8  0f84f3000000           -je 0x4f7af1
    if (cpu.flags.zf)
    {
        goto L_0x004f7af1;
    }
    // 004f79fe  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7a04  8b0d00389f00           -mov ecx, dword ptr [0x9f3800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */);
    // 004f7a0a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a0c  7440                   -je 0x4f7a4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a0e  39f1                   +cmp ecx, esi
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
    // 004f7a10  770c                   -ja 0x4f7a1e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a1e;
    }
    // 004f7a12  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a14  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a16  39f0                   +cmp eax, esi
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
    // 004f7a18  0f878d000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a1e:
    // 004f7a1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7a20  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f7a23  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a25  7410                   -je 0x4f7a37
    if (cpu.flags.zf)
    {
        goto L_0x004f7a37;
    }
    // 004f7a27  39f1                   +cmp ecx, esi
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
    // 004f7a29  770c                   -ja 0x4f7a37
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a37;
    }
    // 004f7a2b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a2d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a2f  39f0                   +cmp eax, esi
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
    // 004f7a31  0f8774000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a37:
    // 004f7a37  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7a3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a3c  7410                   -je 0x4f7a4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a3e  39f1                   +cmp ecx, esi
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
    // 004f7a40  770c                   -ja 0x4f7a4e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a4e;
    }
    // 004f7a42  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a44  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a46  39f0                   +cmp eax, esi
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
    // 004f7a48  0f875d000000           -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a4e:
    // 004f7a4e  8b0d506f5600           -mov ecx, dword ptr [0x566f50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f7a54  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a56  7434                   -je 0x4f7a8c
    if (cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a58  39f1                   +cmp ecx, esi
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
    // 004f7a5a  7708                   -ja 0x4f7a64
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a64;
    }
    // 004f7a5c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a5e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a60  39f0                   +cmp eax, esi
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
    // 004f7a62  7747                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a64:
    // 004f7a64  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7a66  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f7a69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a6b  740c                   -je 0x4f7a79
    if (cpu.flags.zf)
    {
        goto L_0x004f7a79;
    }
    // 004f7a6d  39f1                   +cmp ecx, esi
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
    // 004f7a6f  7708                   -ja 0x4f7a79
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a79;
    }
    // 004f7a71  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a73  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a75  39f0                   +cmp eax, esi
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
    // 004f7a77  7732                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a79:
    // 004f7a79  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7a7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a7e  740c                   -je 0x4f7a8c
    if (cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a80  39f1                   +cmp ecx, esi
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
    // 004f7a82  7708                   -ja 0x4f7a8c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7a8c;
    }
    // 004f7a84  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a86  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a88  39f0                   +cmp eax, esi
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
    // 004f7a8a  771f                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7a8c:
    // 004f7a8c  8b0d4c6f5600           -mov ecx, dword ptr [0x566f4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 004f7a92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7a94  7455                   -je 0x4f7aeb
    if (cpu.flags.zf)
    {
        goto L_0x004f7aeb;
    }
L_0x004f7a96:
    // 004f7a96  39f1                   +cmp ecx, esi
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
    // 004f7a98  7708                   -ja 0x4f7aa2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aa2;
    }
    // 004f7a9a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f7a9c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7a9e  39f0                   +cmp eax, esi
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
    // 004f7aa0  7709                   -ja 0x4f7aab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f7aab;
    }
L_0x004f7aa2:
    // 004f7aa2  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f7aa5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f7aa7  75ed                   -jne 0x4f7a96
    if (!cpu.flags.zf)
    {
        goto L_0x004f7a96;
    }
    // 004f7aa9  eb40                   -jmp 0x4f7aeb
    goto L_0x004f7aeb;
L_0x004f7aab:
    // 004f7aab  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 004f7ab0  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004f7ab2  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f7ab8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f7aba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7abc  e8efd80100             -call 0x5153b0
    cpu.esp -= 4;
    sub_5153b0(app, cpu);
    if (cpu.terminate) return;
    // 004f7ac1  8b15506f5600           -mov edx, dword ptr [0x566f50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */);
    // 004f7ac7  890d00389f00           -mov dword ptr [0x9f3800], ecx
    app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */) = cpu.ecx;
    // 004f7acd  39d1                   +cmp ecx, edx
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
    // 004f7acf  7312                   -jae 0x4f7ae3
    if (!cpu.flags.cf)
    {
        goto L_0x004f7ae3;
    }
    // 004f7ad1  8b1d546f5600           -mov ebx, dword ptr [0x566f54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */);
    // 004f7ad7  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004f7ada  39d8                   +cmp eax, ebx
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
    // 004f7adc  7605                   -jbe 0x4f7ae3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7ae3;
    }
    // 004f7ade  a3546f5600             -mov dword ptr [0x566f54], eax
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.eax;
L_0x004f7ae3:
    // 004f7ae3  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f7ae5  882540b1a000           -mov byte ptr [0xa0b140], ah
    app->getMemory<x86::reg8>(x86::reg32(10531136) /* 0xa0b140 */) = cpu.ah;
L_0x004f7aeb:
    // 004f7aeb  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f7af1:
    // 004f7af1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7af5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f7af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7af8  64ff3500000000         -push dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.efs);
    cpu.esp -= 4;
    // 004f7aff  8f00                   -pop dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.eax) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b01  c740042a7b4f00         -mov dword ptr [eax + 4], 0x4f7b2a
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 5208874 /*0x4f7b2a*/;
    // 004f7b08  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004f7b0b  c64010ff               -mov byte ptr [eax + 0x10], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 255 /*0xff*/;
    // 004f7b0f  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004f7b13  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 004f7b19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b1a  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004f7b1c  648f0500000000         -pop dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.efs) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b23  64a300000000           -mov dword ptr fs:[0], eax
    app->getMemory<x86::reg32>(cpu.efs) = cpu.eax;
    // 004f7b29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b2b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f7b2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7b2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7b31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b32  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b35  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b38  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004f7b3f  740d                   -je 0x4f7b4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7b4e;
    }
    // 004f7b41  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b43  c64512ff               -mov byte ptr [ebp + 0x12], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = 255 /*0xff*/;
    // 004f7b47  e877000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7b4c  eb3e                   -jmp 0x4f7b8c
    return sub_4f7b8c(app, cpu);
L_0x004f7b4e:
    // 004f7b4e  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f7b51  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b54  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f7b57  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b59  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b5c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7b5e  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b61  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b64  7426                   -je 0x4f7b8c
    if (cpu.flags.zf)
    {
        return sub_4f7b8c(app, cpu);
    }
    // 004f7b66  885d12                 -mov byte ptr [ebp + 0x12], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f7b69  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7b6c  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b71  7514                   -jne 0x4f7b87
    if (!cpu.flags.zf)
    {
        return sub_4f7b87(app, cpu);
    }
    // 004f7b73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b76  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b79  ff645f02               -jmp dword ptr [edi + ebx*2 + 2]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.edi + 2 + cpu.ebx * 2), cpu);
}

/* align: skip  */
void Application::sub_4f7b61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b61;
    // 004f7b2a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b2b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f7b2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7b2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7b31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b32  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b35  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b38  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004f7b3f  740d                   -je 0x4f7b4e
    if (cpu.flags.zf)
    {
        goto L_0x004f7b4e;
    }
    // 004f7b41  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b43  c64512ff               -mov byte ptr [ebp + 0x12], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = 255 /*0xff*/;
    // 004f7b47  e877000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7b4c  eb3e                   -jmp 0x4f7b8c
    return sub_4f7b8c(app, cpu);
L_0x004f7b4e:
    // 004f7b4e  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f7b51  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7b54  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f7b57  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004f7b59  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7b5c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7b5e  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_entry_0x004f7b61:
    // 004f7b61  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b64  7426                   -je 0x4f7b8c
    if (cpu.flags.zf)
    {
        return sub_4f7b8c(app, cpu);
    }
    // 004f7b66  885d12                 -mov byte ptr [ebp + 0x12], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bl;
    // 004f7b69  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7b6c  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7b71  7514                   -jne 0x4f7b87
    if (!cpu.flags.zf)
    {
        return sub_4f7b87(app, cpu);
    }
    // 004f7b73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7b74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7b75  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7b76  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7b79  ff645f02               -jmp dword ptr [edi + ebx*2 + 2]
    return app->dynamic_call(app->getMemory<x86::reg32>(cpu.edi + 2 + cpu.ebx * 2), cpu);
}

/* align: skip  */
void Application::sub_4f7b7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b8c;
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
L_entry_0x004f7b8c:
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7b87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f7b87;
    // 004f7b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b81  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f7b82  740d                   -je 0x4f7b91
    if (cpu.flags.zf)
    {
        goto L_0x004f7b91;
    }
    // 004f7b84  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f7b85  7511                   -jne 0x4f7b98
    if (!cpu.flags.zf)
    {
        goto L_0x004f7b98;
    }
L_entry_0x004f7b87:
    // 004f7b87  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7b8a  ebd5                   -jmp 0x4f7b61
    return sub_4f7b61(app, cpu);
    // 004f7b8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f7b91:
    // 004f7b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7b98:
    // 004f7b98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7b99  e809000000             -call 0x4f7ba7
    cpu.esp -= 4;
    sub_4f7ba7(app, cpu);
    if (cpu.terminate) return;
    // 004f7b9e  e820000000             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7ba3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7ba7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7ba7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7ba8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7ba9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7baa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7bab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7bac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7baf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7bb1  68bc7b4f00             -push 0x4f7bbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5209020 /*0x4f7bbc*/;
    cpu.esp -= 4;
    // 004f7bb6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bb7  e828c20300             -call 0x533de4
    cpu.esp -= 4;
    sub_533de4(app, cpu);
    if (cpu.terminate) return;
    // 004f7bbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7bc3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7bc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7bc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7bc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7bc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7bc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bc9  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f7bcc  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7bce  8a5d10                 -mov bl, byte ptr [ebp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f7bd1  c6451101               -mov byte ptr [ebp + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
L_0x004f7bd5:
    // 004f7bd5  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7bd8  7424                   -je 0x4f7bfe
    if (cpu.flags.zf)
    {
        goto L_0x004f7bfe;
    }
    // 004f7bda  3a5d12                 +cmp bl, byte ptr [ebp + 0x12]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7bdd  741f                   -je 0x4f7bfe
    if (cpu.flags.zf)
    {
        goto L_0x004f7bfe;
    }
    // 004f7bdf  8d1c5b                 -lea ebx, [ebx + ebx*2]
    cpu.ebx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 004f7be2  807c5f0100             +cmp byte ptr [edi + ebx*2 + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.ebx * 2);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f7be7  740d                   -je 0x4f7bf6
    if (cpu.flags.zf)
    {
        goto L_0x004f7bf6;
    }
    // 004f7be9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7bea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7beb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7bec  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f7bef  ff545f02               -call dword ptr [edi + ebx*2 + 2]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */ + cpu.ebx * 2);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7bf3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7bf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f7bf6:
    // 004f7bf6  8a1c5f                 -mov bl, byte ptr [edi + ebx*2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + cpu.ebx * 2);
    // 004f7bf9  885d10                 -mov byte ptr [ebp + 0x10], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.bl;
    // 004f7bfc  ebd7                   -jmp 0x4f7bd5
    goto L_0x004f7bd5;
L_0x004f7bfe:
    // 004f7bfe  c6451100               -mov byte ptr [ebp + 0x11], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004f7c02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7c09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c09  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7c0a  648b2d00000000         -mov ebp, dword ptr fs:[0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.efs);
    // 004f7c11  884512                 -mov byte ptr [ebp + 0x12], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 004f7c14  e8aaffffff             -call 0x4f7bc3
    cpu.esp -= 4;
    sub_4f7bc3(app, cpu);
    if (cpu.terminate) return;
    // 004f7c19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7c21  8b1590389f00           -mov edx, dword ptr [0x9f3890]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */);
    // 004f7c27  83fa20                 +cmp edx, 0x20
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
    // 004f7c2a  7d12                   -jge 0x4f7c3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f7c3e;
    }
    // 004f7c2c  42                     -inc edx
    (cpu.edx)++;
    // 004f7c2d  8904950c389f00         -mov dword ptr [edx*4 + 0x9f380c], eax
    app->getMemory<x86::reg32>(x86::reg32(10434572) /* 0x9f380c */ + cpu.edx * 4) = cpu.eax;
    // 004f7c34  891590389f00           -mov dword ptr [0x9f3890], edx
    app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */) = cpu.edx;
    // 004f7c3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7c3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f7c3e:
    // 004f7c3e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f7c43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f7c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7c49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7c4a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f7c4b  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004f7c4d  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004f7c4f  8b1d90389f00           -mov ebx, dword ptr [0x9f3890]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */);
    // 004f7c55  83fb21                 +cmp ebx, 0x21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7c58  7425                   -je 0x4f7c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f7c7f;
    }
    // 004f7c5a  c70590389f0021000000   -mov dword ptr [0x9f3890], 0x21
    app->getMemory<x86::reg32>(x86::reg32(10434704) /* 0x9f3890 */) = 33 /*0x21*/;
    // 004f7c64  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f7c66  7417                   -je 0x4f7c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f7c7f;
    }
    // 004f7c68  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
L_0x004f7c6f:
    // 004f7c6f  8b820c389f00           -mov eax, dword ptr [edx + 0x9f380c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10434572) /* 0x9f380c */);
    // 004f7c75  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7c78  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f7c79  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7c7b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7c7d  75f0                   -jne 0x4f7c6f
    if (!cpu.flags.zf)
    {
        goto L_0x004f7c6f;
    }
L_0x004f7c7f:
    // 004f7c7f  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c81  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c83  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f7c84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7c86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7c91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7c92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7c93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7c94  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7c97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7c99  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f7c9b  8a25c0445600           -mov ah, byte ptr [0x5644c0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5653696) /* 0x5644c0 */);
    // 004f7ca1  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004f7ca4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004f7ca6  7426                   -je 0x4f7cce
    if (cpu.flags.zf)
    {
        goto L_0x004f7cce;
    }
    // 004f7ca8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7caa  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004f7cad  9b                     -wait 
    /*nothing*/;
    // 004f7cae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f7cb0  741c                   -je 0x4f7cce
    if (cpu.flags.zf)
    {
        goto L_0x004f7cce;
    }
    // 004f7cb2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f7cb4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7cb7  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004f7cb9  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f7cbb  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004f7cbd  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004f7cbf  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7cc1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f7cc4  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004f7cc7  9b                     -wait 
    /*nothing*/;
    // 004f7cc8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f7cca  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004f7ccd  9b                     -wait 
    /*nothing*/;
L_0x004f7cce:
    // 004f7cce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7cd0  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004f7cd4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7cd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7cdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f7ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7ce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7ce3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7ce6  833de077560000         +cmp dword ptr [0x5677e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7ced  7410                   -je 0x4f7cff
    if (cpu.flags.zf)
    {
        goto L_0x004f7cff;
    }
    // 004f7cef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f7cf1  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cf7  ff15e0775600           -call dword ptr [0x5677e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666784) /* 0x5677e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7cfd  eb60                   -jmp 0x4f7d5f
    goto L_0x004f7d5f;
L_0x004f7cff:
    // 004f7cff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d01  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d07  e81cda0100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7d0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004f7d0e:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004f7d0e  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d13  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d15  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d1b  2eff15a0455300         -call dword ptr cs:[0x5345a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457312) /* 0x5345a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d22  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f7d27  7421                   -je 0x4f7d4a
    if (cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7d2b  e860d90100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d32  7516                   -jne 0x4f7d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004f7d4a;
    }
    // 004f7d34  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7d38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d39  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7d3b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7d3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d41  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d48  ebc4                   -jmp 0x4f7d0e
    goto L_0x004f7d0e;
L_0x004f7d4a:
    // 004f7d4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d4c  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d52  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f7d57  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7d5a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004f7d5f:
    // 004f7d5f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7d62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7d65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7d72  0f85e8a90000           -jne 0x502760
    if (!cpu.flags.zf)
    {
        return sub_502760(app, cpu);
    }
    // 004f7d78  e8d3da0100             -call 0x515850
    cpu.esp -= 4;
    sub_515850(app, cpu);
    if (cpu.terminate) return;
    // 004f7d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7d7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7d82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7d83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7d84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7d85  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7d87  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f7d89  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004f7d8c  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7d92  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f7d95  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004f7d99  7507                   -jne 0x4f7da2
    if (!cpu.flags.zf)
    {
        goto L_0x004f7da2;
    }
    // 004f7d9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7d9d  e81eac0000             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004f7da2:
    // 004f7da2  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7da5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f7da7  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004f7daa  7415                   -je 0x4f7dc1
    if (cpu.flags.zf)
    {
        goto L_0x004f7dc1;
    }
    // 004f7dac  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004f7dae  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7db1  88510d                 -mov byte ptr [ecx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 004f7db4  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004f7db6  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004f7db9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004f7dbe  88710d                 -mov byte ptr [ecx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x004f7dc1:
    // 004f7dc1  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f7dc3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f7dc5:
    // 004f7dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7dc7  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004f7dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7dcb  740f                   -je 0x4f7ddc
    if (cpu.flags.zf)
    {
        goto L_0x004f7ddc;
    }
    // 004f7dcd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f7dcf  43                     -inc ebx
    (cpu.ebx)++;
    // 004f7dd0  e8db190100             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 004f7dd5  83f8ff                 +cmp eax, -1
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
    // 004f7dd8  75eb                   -jne 0x4f7dc5
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dc5;
    }
    // 004f7dda  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7ddc:
    // 004f7ddc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7dde  741d                   -je 0x4f7dfd
    if (cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7de0  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004f7de3  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004f7de5  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004f7de8  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004f7dea  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004f7ded  88610d                 -mov byte ptr [ecx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004f7df0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7df2  7509                   -jne 0x4f7dfd
    if (!cpu.flags.zf)
    {
        goto L_0x004f7dfd;
    }
    // 004f7df4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f7df6  e865a90000             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 004f7dfb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004f7dfd:
    // 004f7dfd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7dff  7504                   -jne 0x4f7e05
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e05;
    }
    // 004f7e01  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004f7e03  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004f7e05:
    // 004f7e05  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004f7e08  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7e0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f7e10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f7e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7e22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7e23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f7e25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f7e26  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7e29  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
    // 004f7e2f  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7e35  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7e37  a168715600             -mov eax, dword ptr [0x567168]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */);
    // 004f7e3c  83f801                 +cmp eax, 1
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
    // 004f7e3f  7244                   -jb 0x4f7e85
    if (cpu.flags.cf)
    {
        goto L_0x004f7e85;
    }
    // 004f7e41  7607                   -jbe 0x4f7e4a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f7e4a;
    }
    // 004f7e43  83f802                 +cmp eax, 2
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
    // 004f7e46  7424                   -je 0x4f7e6c
    if (cpu.flags.zf)
    {
        goto L_0x004f7e6c;
    }
    // 004f7e48  eb3b                   -jmp 0x4f7e85
    goto L_0x004f7e85;
L_0x004f7e4a:
    // 004f7e4a  4e                     -dec esi
    (cpu.esi)--;
    // 004f7e4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7e4d  740c                   -je 0x4f7e5b
    if (cpu.flags.zf)
    {
        goto L_0x004f7e5b;
    }
    // 004f7e4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e51  7512                   -jne 0x4f7e65
    if (!cpu.flags.zf)
    {
        goto L_0x004f7e65;
    }
    // 004f7e53  893568715600           -mov dword ptr [0x567168], esi
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.esi;
    // 004f7e59  eb0a                   -jmp 0x4f7e65
    goto L_0x004f7e65;
L_0x004f7e5b:
    // 004f7e5b  c7056871560002000000   -mov dword ptr [0x567168], 2
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 2 /*0x2*/;
L_0x004f7e65:
    // 004f7e65  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7e67  e9a2000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e6c:
    // 004f7e6c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7e6e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f7e71  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004f7e76  a368715600             -mov dword ptr [0x567168], eax
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.eax;
    // 004f7e7b  a1b0389f00             -mov eax, dword ptr [0x9f38b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */);
    // 004f7e80  e989000000             -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7e85:
    // 004f7e85  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7e8b  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
L_0x004f7e91:
    // 004f7e91  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f7e95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f7e98  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7e9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7e9d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7e9e  2eff15ac455300         -call dword ptr cs:[0x5345ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457324) /* 0x5345ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7ea5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7ea7  7454                   -je 0x4f7efd
    if (cpu.flags.zf)
    {
        goto L_0x004f7efd;
    }
    // 004f7ea9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7eab  e8e0d70100             -call 0x515690
    cpu.esp -= 4;
    sub_515690(app, cpu);
    if (cpu.terminate) return;
    // 004f7eb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7eb2  74dd                   -je 0x4f7e91
    if (cpu.flags.zf)
    {
        goto L_0x004f7e91;
    }
    // 004f7eb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7eb6  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f7ebb  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f7ebe  8a642411               -mov ah, byte ptr [esp + 0x11]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 004f7ec2  0fb67c240e             -movzx edi, byte ptr [esp + 0xe]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */));
    // 004f7ec7  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004f7eca  7504                   -jne 0x4f7ed0
    if (!cpu.flags.zf)
    {
        goto L_0x004f7ed0;
    }
    // 004f7ecc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f7ece  751b                   -jne 0x4f7eeb
    if (!cpu.flags.zf)
    {
        goto L_0x004f7eeb;
    }
L_0x004f7ed0:
    // 004f7ed0  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004f7ed5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7ed7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004f7ed9  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f7ede  892d68715600           -mov dword ptr [0x567168], ebp
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = cpu.ebp;
    // 004f7ee4  a3b0389f00             -mov dword ptr [0x9f38b0], eax
    app->getMemory<x86::reg32>(x86::reg32(10434736) /* 0x9f38b0 */) = cpu.eax;
    // 004f7ee9  eb0e                   -jmp 0x4f7ef9
    goto L_0x004f7ef9;
L_0x004f7eeb:
    // 004f7eeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f7eed  740a                   -je 0x4f7ef9
    if (cpu.flags.zf)
    {
        goto L_0x004f7ef9;
    }
    // 004f7eef  c7056871560001000000   -mov dword ptr [0x567168], 1
    app->getMemory<x86::reg32>(x86::reg32(5665128) /* 0x567168 */) = 1 /*0x1*/;
L_0x004f7ef9:
    // 004f7ef9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f7efb  eb11                   -jmp 0x4f7f0e
    goto L_0x004f7f0e;
L_0x004f7efd:
    // 004f7efd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f7f02  8b3db4389f00           -mov edi, dword ptr [0x9f38b4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */);
    // 004f7f08  8b35b8389f00           -mov esi, dword ptr [0x9f38b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */);
L_0x004f7f0e:
    // 004f7f0e  893db4389f00           -mov dword ptr [0x9f38b4], edi
    app->getMemory<x86::reg32>(x86::reg32(10434740) /* 0x9f38b4 */) = cpu.edi;
    // 004f7f14  8935b8389f00           -mov dword ptr [0x9f38b8], esi
    app->getMemory<x86::reg32>(x86::reg32(10434744) /* 0x9f38b8 */) = cpu.esi;
    // 004f7f1a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f7f1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f7f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f7f24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f7f27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f7f28  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f2b  a128785600             -mov eax, dword ptr [0x567828]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */);
    // 004f7f30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f7f32  740a                   -je 0x4f7f3e
    if (cpu.flags.zf)
    {
        goto L_0x004f7f3e;
    }
    // 004f7f34  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f7f36  893528785600           -mov dword ptr [0x567828], esi
    app->getMemory<x86::reg32>(x86::reg32(5666856) /* 0x567828 */) = cpu.esi;
    // 004f7f3c  eb5a                   -jmp 0x4f7f98
    goto L_0x004f7f98;
L_0x004f7f3e:
    // 004f7f3e  833de477560000         +cmp dword ptr [0x5677e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f7f45  7410                   -je 0x4f7f57
    if (cpu.flags.zf)
    {
        goto L_0x004f7f57;
    }
    // 004f7f47  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f4d  ff15e4775600           -call dword ptr [0x5677e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666788) /* 0x5677e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f55  eb3f                   -jmp 0x4f7f96
    goto L_0x004f7f96;
L_0x004f7f57:
    // 004f7f57  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f5d  e8c6d70100             -call 0x515728
    cpu.esp -= 4;
    sub_515728(app, cpu);
    if (cpu.terminate) return;
    // 004f7f62  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f7f64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f7f66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f7f67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f68  2eff15fc445300         -call dword ptr cs:[0x5344fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457148) /* 0x5344fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f6f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f7f71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f72  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f79  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f7f7b  e8a0feffff             -call 0x4f7e20
    cpu.esp -= 4;
    sub_4f7e20(app, cpu);
    if (cpu.terminate) return;
    // 004f7f80  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f7f83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f7f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f7f85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f7f87  2eff15d0455300         -call dword ptr cs:[0x5345d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457360) /* 0x5345d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f7f8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f7f90  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f7f96:
    // 004f7f96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004f7f98:
    // 004f7f98  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f7f9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f7f9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
